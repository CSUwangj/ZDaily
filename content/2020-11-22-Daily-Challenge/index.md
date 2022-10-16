+++
title = "2020-11-22 Daily-Challenge"
path = "2020-11-22-Daily-Challenge"
date = 2020-11-22 00:14:29+08:00
updated = 2020-11-22 17:38:58+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Sunday, I gonna review the tasks I've done this week, and finish today's leetcode's [November LeetCoding Challenge](https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/566/week-3-november-15th-november-21st/3540/) with `cpp`.

<!-- more -->

# LeetCode Review

## Count Complete Tree Nodes

if we let height be the deepest path of tree, then we could calculate it by recursively check left child.

if height of left subtree is height of tree minus one, then left side of tree is full, otherwise right side of tree is full.

``` cpp
class Solution {
    int height(TreeNode *root) {
        if(!root) return -1;
        int h = 0;
        while(root) {
            h += 1;
            root = root->left;
        }
        return h-1;
        
    }
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int h = height(root);
        return h < 0 ? 0 :
                       height(root->right) == h - 1 ? (1 << h) + countNodes(root->right) :
                                                      (1 << (h - 1)) + countNodes(root->left);
    }
};
```

## Course Schedule IV

floyd

``` cpp
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> isPrerequisite(n, vector<bool>(n));
        for(auto &pre : prerequisites) {
            isPrerequisite[pre[0]][pre[1]] = true;
        }
        
        for(int k = 0; k < n; ++k) {
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    if(isPrerequisite[i][k] && isPrerequisite[k][j]) {
                        isPrerequisite[i][j] = true;
                    }
                }
            }
        }
        
        vector<bool> answer;
        for(auto &query : queries) {
            answer.push_back(isPrerequisite[query[0]][query[1]]);
        }
        return answer;
    }
};
```

## Greatest Sum Divisible by Three

more elegant way

``` cpp
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int minOne = 0;
        int minTwo = 0;
        int sum = 0;
        for(auto num : nums) {
            if(num % 3 == 1) {
                if(minOne) {
                    if(minTwo) minTwo = min(minTwo, minOne + num);
                    else minTwo = minOne + num;
                    minOne = min(minOne, num);
                } else {
                    minOne = num;
                }
            } else if(num % 3 == 2) {
                if(minTwo) {
                    if(minOne) minOne = min(minOne, minTwo + num);
                    else minOne = minTwo + num;
                    minTwo = min(minTwo, num);
                } else {
                    minTwo = num;
                }
            }
            sum += num;
        }
        if(sum % 3 == 1) return sum - minOne;
        if(sum % 3 == 2) return sum - minTwo;
        return sum;
    }
};
```

## Decode String

nothing to say

``` cpp
class Solution {
public:
    string decodeString(string s) {
        stack<pair<string, int>> st;
        string current = "";
        int curCnt = 0;
        for(auto c : s) {
            if(islower(c)) {
                current += c;
            } else if (isdigit(c)) {
                curCnt *= 10;
                curCnt += c - '0';
            } else if(c == '[') {
                st.push(make_pair(current, curCnt));
                current = "";
                curCnt = 0;
            } else {
                auto [str, cnt] = st.top();
                st.pop();
                while(cnt--) {
                    str += current;
                }
                current = str;
            }
        }
        return current;
    }
};
```

## Merge Intervals

``` cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return vector<vector<int>>();
        sort(intervals.begin(), intervals.end());
        int len = intervals.size();
        
        vector<vector<int>> answer;
        vector<int> current = intervals[0];
        for(int i = 1; i < len; ++i) {
            if(intervals[i][0] > current[1]) {
                answer.push_back(current);
                current = intervals[i];
            } else {
                current[1] = max(current[1], intervals[i][1]);
            }
        }
        answer.push_back(current);
        return answer;
    }
};
```

## Search in Rotated Sorted Array II

nothing to say

``` cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty()) return false;
        int offset = 0;
        int len = nums.size();
        for(int i = 1; i < len; ++i) {
            if(nums[i] < nums[i-1]) {
                offset = i;
                break;
            }
        }
        int start = 0, end = nums.size() - 1;
        while(start < end) {
            int mid = (start + end) / 2;
            int pos = (mid + offset) % len;
            if(nums[pos] < target) start = mid + 1;
            else end = mid;
        }
        return nums[(start+offset)%len] == target;
    }
};
```

# November LeetCoding Challenge 22

## Description

**Unique Morse Code Words**

International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows: `"a"` maps to `".-"`, `"b"` maps to `"-..."`, `"c"` maps to `"-.-."`, and so on.

For convenience, the full table for the 26 letters of the English alphabet is given below:

```
[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
```

Now, given a list of words, each word can be written as a concatenation of the Morse code of each letter. For example, "cab" can be written as "-.-..--...", (which is the concatenation "-.-." + ".-" + "`-...`"). We'll call such a concatenation, the transformation of a word.

Return the number of different transformations among all words we have.

```
Example:
Input: words = ["gin", "zen", "gig", "msg"]
Output: 2
Explanation: 
The transformation of each word is:
"gin" -> "--...-."
"zen" -> "--...-."
"gig" -> "--...--."
"msg" -> "--...--."

There are 2 different transformations, "--...-." and "--...--.".
```

**Note:**

- The length of `words` will be at most `100`.
- Each `words[i]` will have length in range `[1, 12]`.
- `words[i]` will only consist of lowercase letters.

## Solution

nothing to say

``` cpp
class Solution {
    vector<string> m{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> answer;
        for(auto &word : words) {
            string code = "";
            for(auto c : word) {
                code += m[c-'a'];
            }
            answer.insert(code);
        }
        return answer.size();
    }
};
```
