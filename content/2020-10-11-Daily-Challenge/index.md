+++
title = "2020-10-11 Daily-Challenge"
path = "2020-10-11-Daily-Challenge"
date = 2020-10-11 02:17:34+08:00
updated = 2020-10-11 19:37:17+08:00
in_search_index = true

[taxonomies]
tags = ["Design", "Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Sunday, I gonna review the tasks I've done this week, and finish today's leetcode's [October LeetCoding Challenge](https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/559/week-1-october-1st-october-7th/3491/) with `cpp`.

<!-- more -->

# The non-Designer's Design Book review

my second answer on Page 56:

- [F] color of dark purple
- [F] shape of circle
- [HT] color of grey green circle

reference answer:

- dark maroon color
- color of green bubble
- explicit alignment of border and text

my second answer on Page 72-73:

- [T] use lowercase and uppercase
- [T] curly banner of quotes
- [T] remove unnecessary `TELEPHONE`, etc
- [D] use uppercase in website
- [HT] increase size of image
- [F] purple banner background of title
- [T] neat left align and right align

reference answer has 4 more differences:

- border is more slim than before
- enlarge pie and let it float
- quote repeat font of the title
- move ` a pie gallery` to title(where it is?)

my second answer on Page 74:

- [T] use white background instead of light purple
- [T] purple banner for the title
- [T] reduce size of heart shape
- [F] email and phone repeat same font and color
- [T] move heart shape to top
- [HT] use interesting font in the title

reference answer:

- remove `Times New Roman`, use handwritting font for the title and sans serif font for the rest
- in order to match the serif bold, a dark purple is added

my second answer on Page 134:

- top one
  - [T] remove useless shape
  - [F] use `|` instead of `·` to separate contact information
  - [T] use lowercase
  - [T] not use italic on the title
  - [T] not use uppercase on `smile`
- bottom one
  - [T] repeat black banner
  - [T] no unused space between image and banners
  - [F] lowercase so can be enlarged

reference answer:

- first one
  - remove casual image
  - remove one `Emergenicies Welcome`
- second one
  - gather text block closer so it looks more organized

my second answer on Page 82:

- [T] use interesting font for bullets
- [T] separate `resume` and follow text
- [T] remove border
- [T] titles and details are more closer
- [T] use another bold font for titles
- [T] left align
- [F] same spacing between blocks

seems all write if I write in more detailed manner?

# LeetCode Review

## Queries on a Permutation With Key

Get index of number can be transformed into a prefix sum problems, then we only need to know the position of the number and should be able to do a quick add to range of prefix sum. So, we can use a map and a BIT(binary indexed tree) to solve this problem.

Here comes the trick: imaging that we have a array to compute the prefix sum, which is index of the key, instead of initialize array with size of `m` and set all values to `1`, we initialize a array with size of `m+queries.size()` and, first `queries.size()` elements set values to `0` and set reset to `1`. And we have a hashmap to record the position of number. Then we can transform each query to follow:

```
0. get position of query number from map
1. compute the prefix sum of position of query number
2. put the query number to first position, which is equal to
  - let prifix sum of position minus one
  - let prefix sum of last add one
```

check my code for more information

``` cpp
class Solution {
  void add(vector<int>& nums, int pos, int val) {
    while(pos < nums.size()) {
      nums[pos] += val;
      pos += pos&(-pos);
    }
  }

  int sum(vector<int>& nums, int pos) {
    int ret = 0;
    while(pos) {
      ret += nums[pos];
      pos -= pos&(-pos);
    }
    return ret;
  }
public:
  vector<int> processQueries(vector<int>& queries, int m) {
    vector<int> answer, bit(m*2+1, 0);
    unordered_map<int, int> h;
    int cnt = queries.size();
    for (int i = 1; i <= m; ++i) {
      h[i] = i+cnt;
      add(bit, i+cnt, 1);
    }
    for(int q: queries) {
      answer.push_back(sum(bit, h[q])-1);
      add(bit, h[q], -1);
      add(bit, cnt, 1);
      h[q] = cnt;
      --cnt;
    }
    return answer;
  }
};
```

BTW because `queries.size() <= m` so we can use `2*m+1` as size.

## Binary Search

homemade-binary-search :)

``` cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int begin = 0, end = nums.size()-1;
        while(begin < end) {
            int mid = (begin + end) >> 1;
            if(nums[mid] >= target) {
                end = mid;
            } else {
                begin = mid+1;
            }
        }
        return nums[begin]==target?begin:-1;
    }
};
```

## Serialize and Deserialize BST

pre-order traversal with human-readable encoding

``` cpp
class Codec {
  int stoi(string &num, int &end) {
    int ret = 0;
    while (num.length() > end  && isdigit(num[end])) {
      ret *= 10;
      ret += num[end] - '0';
      end += 1;
    }
    return ret;
  }
  TreeNode* deserialize(string &data, int &pos) {
    if(data[pos] == 'n') {
      pos += 2;
      return NULL;
    }
    TreeNode* root = new TreeNode(stoi(data, pos));
    pos += 1;
    root->left = deserialize(data, pos);
    root->right = deserialize(data, pos);
    return root;
  }
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if(!root) return "n,";
    string tmp = to_string(root->val);
    tmp += ",";
    tmp += serialize(root->left);
    tmp += serialize(root->right);
    return tmp;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    if(data.length() == 2) return NULL;
    int len = data.length();
    int pos = 0;
    TreeNode* root = new TreeNode(stoi(data, pos));
    pos += 1;
    root->left = deserialize(data, pos);
    root->right = deserialize(data, pos);
    return root;
  }
};
```

## Remove Outermost Parentheses

raw concatenation

``` cpp
class Solution {
public:
    string removeOuterParentheses(string S) {
        string answer = "";
        int cnt = 0;
        for(char c: S) {
            if(c == '(' && cnt++) {
                answer += '(';
            } else if(c == ')' && --cnt) {
                answer += ')';
            }
        }
        return answer;
    }
};
```

# October LeetCoding Challenge11

**Remove Duplicate Letters**

Given a string `s`, remove duplicate letters so that every letter appears once and only once. You must make sure your result is **the smallest in lexicographical order** among all possible results.

**Note:** This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

**Example 1:**

```
Input: s = "bcabc"
Output: "abc"
```

**Example 2:**

```
Input: s = "cbacdcbc"
Output: "acdb"
```

**Constraints:**

- `1 <= s.length <= 104`
- `s` consists of lowercase English letters.
- 
## Solution

another greedy

``` cpp
class Solution {
public:
  string removeDuplicateLetters(string s) {
    map<char, int> cnt;
    vector<bool> used = vector<bool>(128, false);
    string answer = "";
    for(auto c: s) {
      cnt[c] += 1;
    }
    for(auto c: s) {
      if(used[c]) {
        cnt[c] -= 1;
        continue;
      }
      while(answer.length() && answer.back() > c && cnt[answer.back()]) {
        used[answer.back()] = false;
        answer.pop_back();
      }
      answer.push_back(c);
      cnt[c] -= 1;
      used[c] = true;
    }
    return answer;
  }
};
```
