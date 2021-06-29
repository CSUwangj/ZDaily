+++
title = "2021-06-29 Daily-Challenge"
path = "2021-06-29-Daily-Challenge"
date = 2021-06-29 19:03:44+08:00
updated = 2021-06-29 20:00:03+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Construct the Lexicographically Largest Valid Sequence](https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/description/) and leetcode's [June LeetCoding Challenge](https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/607/week-5-june-29th-june-30th/3796/) with `cpp`.

<!-- more -->

# Construct the Lexicographically Largest Valid Sequence

## Description

Given an integer `n`, find a sequence that satisfies all of the following:

- The integer `1` occurs once in the sequence.
- Each integer between `2` and `n` occurs twice in the sequence.
- For every integer `i` between `2` and `n`, the **distance** between the two occurrences of `i` is exactly `i`.

The **distance** between two numbers on the sequence, `a[i]` and `a[j]`, is the absolute difference of their indices, `|j - i|`.

Return *the **lexicographically largest** sequence**. It is guaranteed that under the given constraints, there is always a solution.*

A sequence `a` is lexicographically larger than a sequence `b` (of the same length) if in the first position where `a` and `b` differ, sequence `a` has a number greater than the corresponding number in `b`. For example, `[0,1,9,0]` is lexicographically larger than `[0,1,5,6]` because the first position they differ is at the third number, and `9` is greater than `5`.

 

**Example 1:**

```
Input: n = 3
Output: [3,1,2,3,2]
Explanation: [2,3,2,1,3] is also a valid sequence, but [3,1,2,3,2] is the lexicographically largest valid sequence.
```

**Example 2:**

```
Input: n = 5
Output: [5,3,1,4,3,5,2,4,2]
```

 

**Constraints:**

- `1 <= n <= 20`

## Solution

``` cpp
class Solution {
  vector<bool> vis;
  vector<int> answer;
  int n;
  bool solve(int index) {
    if(index == 2 * n - 1) return true;
    // cout << "#" << answer << endl;
    if(answer[index]) return solve(index + 1);
    for(int i = min(n, 2 * n - 2 - index); i > 1 ; --i) {
      // cout << index << ' ' << i << endl;
      if(vis[i]) continue;
      // cout << "???" << endl;
      if(i != 1 && answer[i + index]) continue;
      // cout << "????" << endl;
      answer[index] = i;
      answer[index + i] = i;
      vis[i] = true;
      if(solve(index + 1)) return true;
      answer[index] = 0;
      answer[index + i] = 0;
      vis[i] = false;
    }
    if(!vis[1]) {
      answer[index] = 1;
      vis[1] = true;
      if(solve(index + 1)) return true;
      vis[1] = false;
      answer[index] = 0;
    }
    return false;
  }
public:
  vector<int> constructDistancedSequence(int n) {
    this->n = n;
    vis.resize(n + 1);
    answer.resize(n * 2 - 1);
    solve(0);
    return answer;
  }
};
```

# June LeetCoding Challenge29

## Description

**Max Consecutive Ones III**

Given a binary array `nums` and an integer `k`, return *the maximum number of consecutive* `1`*'s in the array if you can flip at most* `k` `0`'s.

 

**Example 1:**

```
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
```

**Example 2:**

```
Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
```

 

**Constraints:**

- `1 <= nums.length <= 10^5`
- `nums[i]` is either `0` or `1`.
- `0 <= k <= nums.length`

## Solution

``` cpp
[1,1,1,0,0,0,1,1,1,1,0]auto speedup = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
int ones[100000];
class Solution {
public:
  int longestOnes(vector<int>& nums, int k) {
    int len = nums.size();
    int answer = 0;
    int last = -1;
    int ed = 0;
    int start = 0;
    for(int i = 0; i < len; ++i) {
      if(!nums[i]) {
        if(!k) {
          last = i;
        } else {
          if(ed - start == k) last = ones[start++];
          ones[ed++] = i;
        }
      }
      // cout << i << ' ' << last << ' ' << ed << ' ' << start << endl;
      answer = max(answer, i - last);
    }
    return answer;
  }
};

// Accepted
// 48/48 cases passed (36 ms)
// Your runtime beats 99.56 % of cpp submissions
// Your memory usage beats 8.97 % of cpp submissions (55.6 MB)
```

``` cpp
auto speedup = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
class Solution {
public:
  int longestOnes(vector<int>& nums, int k) {
    int len = nums.size();
    int answer = 0;
    int last = -1;
    queue<int> q;
    for(int i = 0; i < len; ++i) {
      if(!nums[i]) {
        if(!k) {
          last = i;
        } else {
          if(q.size() == k) {
            last = q.front();
            q.pop();
          }
          q.push(i);
        }
      }
      // cout << i << ' ' << last << ' ' << ed << ' ' << start << endl;
      answer = max(answer, i - last);
    }
    return answer;
  }
};

// Accepted
// 48/48 cases passed (56 ms)
// Your runtime beats 59.23 % of cpp submissions
// Your memory usage beats 6.29 % of cpp submissions (57 MB)
```

``` cpp
auto speedup = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
class Solution {
public:
  int longestOnes(vector<int>& nums, int k) {
    int len = nums.size();
    int answer = 0;
    int last = -1;
    list<int> q;
    for(int i = 0; i < len; ++i) {
      if(!nums[i]) {
        if(!k) {
          last = i;
        } else {
          if(q.size() == k) {
            last = q.front();
            q.pop_front();
          }
          q.push_back(i);
        }
      }
      // cout << i << ' ' << last << ' ' << ed << ' ' << start << endl;
      answer = max(answer, i - last);
    }
    return answer;
  }
};

// Accepted
// 48/48 cases passed (68 ms)
// Your runtime beats 23.17 % of cpp submissions
// Your memory usage beats 5.15 % of cpp submissions (69.9 MB)
```

``` cpp
auto speedup = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
int ones[50000];
class Solution {
public:
  int longestOnes(vector<int>& nums, int k) {
    int s = accumulate(nums.begin(), nums.end(), 0);
    int len = nums.size();
    if(s + k >= len) return len;
    int answer = 0;
    int last = -1;
    int ed = 0;
    int start = 0;
    for(int i = 0; i < len; ++i) {
      if(!nums[i]) {
        if(!k) {
          last = i;
        } else {
          if(ed - start == k) last = ones[start++];
          ones[ed++] = i;
          start %= 50000;
          ed %= 50000;
        }
      }
      // cout << i << ' ' << last << ' ' << ed << ' ' << start << endl;
      answer = max(answer, i - last);
    }
    return answer;
  }
};

// Accepted
// 48/48 cases passed (28 ms)
// Your runtime beats 99.97 % of cpp submissions
// Your memory usage beats 8.97 % of cpp submissions (55.6 MB)
```
