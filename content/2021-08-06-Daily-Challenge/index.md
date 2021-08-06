+++
title = "2021-08-06 Daily-Challenge"
path = "2021-08-06-Daily-Challenge"
date = 2021-08-06 19:10:19+08:00
updated = 2021-08-06 19:39:04+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Largest Substring Between Two Equal Characters](https://leetcode.com/problems/largest-substring-between-two-equal-characters/description/) and leetcode's [August LeetCoding Challenge](https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/613/week-1-august-1st-august-7th/3840/) with `cpp`.

<!-- more -->

# Largest Substring Between Two Equal Characters

## Description

Given a string `s`, return *the length of the longest substring between two equal characters, excluding the two characters.* If there is no such substring return `-1`.

A **substring** is a contiguous sequence of characters within a string.

 

**Example 1:**

```
Input: s = "aa"
Output: 0
Explanation: The optimal substring here is an empty substring between the two 'a's.
```

**Example 2:**

```
Input: s = "abca"
Output: 2
Explanation: The optimal substring here is "bc".
```

**Example 3:**

```
Input: s = "cbzxy"
Output: -1
Explanation: There are no characters that appear twice in s.
```

**Example 4:**

```
Input: s = "cabbac"
Output: 4
Explanation: The optimal substring here is "abba". Other non-optimal substrings include "bb" and "".
```

 

**Constraints:**

- `1 <= s.length <= 300`
- `s` contains only lowercase English letters.

## Solution

``` cpp
int front[26];
int back[26];
class Solution {
public:
  int maxLengthBetweenEqualCharacters(string s) {
    for(int i = 0; i < 26; ++i) {
      front[i] = 1000;
      back[i] = -1000;
    }
    for(int i = 0; i < s.length(); ++i) {
      int c = s[i] - 'a';
      front[c] = min(front[c], i);
      back[c] = max(back[c], i);
    }
    int answer = -1;
    for(int i = 0; i < 26; ++i) {
      answer = max(answer, back[i] - 1 - front[i]);
    }
    return answer;
  }
};

// Accepted
// 54/54 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 86.26 % of cpp submissions (6.2 MB)
```

# August LeetCoding Challenge 6

## Description

**N-ary Tree Level Order Traversal**

Given an n-ary tree, return the *level order* traversal of its nodes' values.

*Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).*

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png)

```
Input: root = [1,null,3,2,4,null,5,6]
Output: [[1],[3,2,4],[5,6]]
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2019/11/08/sample_4_964.png)

```
Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
```

 

**Constraints:**

- The height of the n-ary tree is less than or equal to `1000`
- The total number of nodes is between `[0, 10^4]`

## Solution

it's easy to come up with a interval DP solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  vector<vector<int>> levelOrder(Node* root) {
    if(!root) return {};
    vector<vector<int>> answer;
    queue<Node*> q;
    q.push(root);
    while(q.size()) {
      int sz = q.size();
      vector<int> level;
      for(int _ = 0; _ < sz; ++_) {
        auto cur = q.front();
        q.pop();
        level.push_back(cur->val);
        for(auto child : cur->children) {
          q.push(child);
        }
      }
      answer.push_back(level);
    }
    return answer;
  }
};

// Accepted
// 38/38 cases passed (20 ms)
// Your runtime beats 86.78 % of cpp submissions
// Your memory usage beats 34.23 % of cpp submissions (11.9 MB)
```
