+++
title = "2021-05-09 Daily-Challenge"
path = "2021-05-09-Daily-Challenge"
date = 2021-05-09 22:09:47+08:00
updated = 2021-05-09 23:04:53+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [May LeetCoding Challenge](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3728/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 9

## Description

**Construct Target Array With Multiple Sums**

Given an array of integers `target`. From a starting array, `A` consisting of all 1's, you may perform the following procedure :

- let `x` be the sum of all elements currently in your array.
- choose index `i`, such that `0 <= i < target.size` and set the value of `A` at index `i` to `x`.
- You may repeat this procedure as many times as needed.

Return True if it is possible to construct the `target` array from `A` otherwise return False.

 

**Example 1:**

```
Input: target = [9,3,5]
Output: true
Explanation: Start with [1, 1, 1] 
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

- `N == target.length`
- `1 <= target.length <= 5 * 10^4`
- `1 <= target[i] <= 10^9`

## Solution

I try to solve forward, but failed. it needs to be solved think reversely.

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
```
