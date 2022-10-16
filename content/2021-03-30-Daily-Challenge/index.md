+++
title = "2021-03-30 Daily-Challenge"
path = "2021-03-30-Daily-Challenge"
date = 2021-03-30 16:17:14+08:00
updated = 2021-03-30 19:52:31+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Unique Paths](https://leetcode.com/problems/unique-paths/), [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/), [Search Suggestions System](https://leetcode.com/problems/search-suggestions-system/) and leetcode's [March LeetCoding Challenge](https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/592/week-5-march-29th-march-31st/3690/) with `cpp`.

<!-- more -->

# Unique Paths

## Description

A robot is located at the top-left corner of a `m x n` grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png)

```
Input: m = 3, n = 7
Output: 28
```

**Example 2:**

```
Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
```

**Example 3:**

```
Input: m = 7, n = 3
Output: 28
```

**Example 4:**

```
Input: m = 3, n = 3
Output: 6
```

 

**Constraints:**

- `1 <= m, n <= 100`
- It's guaranteed that the answer will be less than or equal to `2 * 109`.

## Solution

using constexpr to get a precomputed table

``` cpp
template<int N>
struct Table {
  constexpr Table() : values() {
    for(int i = 0; i < N; ++i) {
      for(int j = 0; j < N; ++j) {
        if(!i || !j) values[i][j] = 1;
        else {
          if(INT_MAX - values[i - 1][j] > values[i][j - 1]) {
            values[i][j] = values[i - 1][j] + values[i][j - 1];         
          } else {
            values[i][j] = 1;  
          }
        }
      }
    }
  }
  int values[N][N];
};

constexpr auto table = Table<100>();

class Solution {
public:
  int uniquePaths(int m, int n) {
    return table.values[m - 1][n - 1];
  }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Paths.
// Memory Usage: 6 MB, less than 66.04% of C++ online submissions for Unique Paths.
```

or just dp

``` cpp
class Solution {
public:
  int uniquePaths(int m, int n) {
    int dp[2][m];
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < m; ++j) {
        if(!i || !j) {
          dp[i & 1][j] = 1;
        } else {
          dp[i & 1][j] = dp[(i & 1) ^ 1][j] + dp[i & 1][j - 1];
        }
      }
    }
    return dp[(n & 1) ^ 1][m - 1];
  }
};
```

# Longest Increasing Subsequence

## Description

Given an integer array `nums`, return the length of the longest strictly increasing subsequence.

A **subsequence** is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, `[3,6,2,7]` is a subsequence of the array `[0,3,1,6,2,2,7]`.

 

**Example 1:**

```
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
```

**Example 2:**

```
Input: nums = [0,1,0,3,2,3]
Output: 4
```

**Example 3:**

```
Input: nums = [7,7,7,7,7,7,7]
Output: 1
```

 

**Constraints:**

- `1 <= nums.length <= 2500`
- $-10^4 \le nums[i] \le 10^4$

 

**Follow up:**

- Could you come up with the $O(n^2)$ solution?
- Could you improve it to $O(n \log (n))$ time complexity?

## Solution

``` cpp
class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> dp;
    for(auto i : nums) {
      auto it = lower_bound(dp.begin(), dp.end(), i);
      if(it == dp.end()) {
        dp.push_back(i);
      } else {
        *it = i;
      }
    }
    return dp.size();
  }
};
```

# Search Suggestions System

yesterday's problems

## Solution

I knew it! hahahahaha gotcha!

``` cpp
struct TrieNode {
  bool isEnd;
  TrieNode *next[26];
  TrieNode() : isEnd(false) {
    for(int i = 0; i < 26; ++i) next[i] = nullptr;
  }
};

void insertTrie(string &s, TrieNode *root) {
  TrieNode *cur = root;
  for(auto c : s) {
    if(!cur->next[c - 'a']) {
      cur->next[c - 'a'] = new TrieNode();
    }
    cur = cur->next[c - 'a'];
  }
  cur->isEnd = true;
}

void getWords(vector<string> &words, TrieNode *root, int count, string &cur) {
  if(root == nullptr) return;
  if(root->isEnd) words.push_back(cur);
  for(int i = 0; i < 26 && words.size() < count; ++i) {
    if(root->next[i]) {
      cur.push_back(i + 'a');
      getWords(words, root->next[i], count, cur);
      cur.pop_back();
    }
  }
}

class Solution {
public:
  vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    auto root = new TrieNode();
    for(auto &product : products) {
      insertTrie(product, root);
    }
    
    auto cur = root;
    vector<vector<string>> answer;
      string word;
    for(auto c : searchWord) {
      vector<string> words;
      word.push_back(c);
      cur = cur ? cur->next[c - 'a'] : cur;
      getWords(words, cur, 3, word);
      answer.push_back(words);
    }
    
    return answer;
  }
};
```

# March LeetCoding challenge 30

## Description

**Russian Doll Envelopes**

You are given a 2D array of integers `envelopes` where `envelopes[i] = [wi, hi]` represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

Return *the maximum number of envelopes can you Russian doll (i.e., put one inside the other)*.

**Note:** You cannot rotate an envelope.

 

**Example 1:**

```
Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
```

**Example 2:**

```
Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1
```

 

**Constraints:**

- `1 <= envelopes.length <= 5000`
- `envelopes[i].length == 2`
- `1 <= wi, hi <= 10^4`

## Solution

$O(n^2)$ solution

``` cpp
class Solution {
public:
  int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end());
    int len = envelopes.size();
    int dp[len];
    dp[0] = 1;
    for(int i = 1; i < len; ++i) {
      dp[i] = 1;
      for(int j = 0; j < i; ++j) {
        if(envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1] && dp[i] <= dp[j]) {
          dp[i] = dp[j] + 1;
        }
      }
    }
    return *max_element(dp, dp + len);
  }
};
```

$O(n\log n)$ solution

``` cpp
class Solution {
public:
  int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b) {
      return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
    });
    vector<int> dp;
    for(auto &e : envelopes) {
      auto it = lower_bound(dp.begin(), dp.end(), e[1]);
      if(it == dp.end()) {
        dp.push_back(e[1]);
      } else {
        *it = e[1];
      }
    }
    return dp.size();
  }
};
```
