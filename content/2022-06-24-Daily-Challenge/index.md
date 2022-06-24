+++
updated = 2022-06-24 18:14:00+08:00
title = "2022-06-24 Daily-Challenge"
path = "2022-06-24-Daily-Challenge"
date = 2022-06-24 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/construct-target-array-with-multiple-sums/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 24

## Description

**Construct Target Array With Multiple Sums**

You are given an array `target` of n integers. From a starting array `arr` consisting of `n` 1's, you may perform the following procedure :

- let `x` be the sum of all elements currently in your array.
- choose index `i`, such that `0 <= i < n` and set the value of `arr` at index `i` to `x`.
- You may repeat this procedure as many times as needed.

Return `true` *if it is possible to construct the* `target` *array from* `arr`*, otherwise, return* `false`.

 

**Example 1:**

```
Input: target = [9,3,5]
Output: true
Explanation: Start with arr = [1, 1, 1] 
[1, 1, 1], sum = 3 choose index 1
[1, 3, 1], sum = 5 choose index 2
[1, 3, 5], sum = 9 choose index 0
[9, 3, 5] Done
```

**Example 2:**

```
Input: target = [1,1,1,2]
Output: false
Explanation: Impossible to create target array from [1,1,1,1].
```

**Example 3:**

```
Input: target = [8,5]
Output: true
```

 

**Constraints:**

- `n == target.length`
- `1 <= n <= 5 * 10^4`
- `1 <= target[i] <= 10^9`

## Solution

``` cpp
class Solution {
public:
  bool isPossible(vector<int>& target) {
    if(target.size() == 1 && target[0] != 1) return false;
    priority_queue<int> q;
    long long sum = 0;
    for(auto i : target) {
      q.push(i);
      sum += i;
    }
    // cout << "###########" << endl;
    while(q.size() && q.top() != 1) {
      long long cur = q.top();
      q.pop();
      long long nxt = q.top();
      long long diff = ceil(1.0 * (cur - nxt) / (sum - cur)) * (sum - cur);
      if(cur - diff == nxt && nxt != 1) diff += (sum - cur); 
      // cout << cur << ' ' << diff << endl;
      cur -= diff;
      sum -= diff;
      if(cur < 1) return false;
      q.push(cur);
    }
    return true;
  }
};

// cur - x * diff < nxt
// (cur - nxt) / diff
// Accepted
// 71/71 cases passed (64 ms)
// Your runtime beats 52.45 % of cpp submissions
// Your memory usage beats 51.05 % of cpp submissions (30.1 MB)
```
