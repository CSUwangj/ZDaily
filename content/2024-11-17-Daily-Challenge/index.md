+++
updated = 2024-11-17T08:26:27+08:00
title = "2024-11-17 Daily Challenge"
path = "2024-11-17-Daily-Challenge"
date = 2024-11-17T08:26:27+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 17

## Description

**Shortest Subarray with Sum at Least K**

<p>Given an integer array <code>nums</code> and an integer <code>k</code>, return <em>the length of the shortest non-empty <strong>subarray</strong> of </em><code>nums</code><em> with a sum of at least </em><code>k</code>. If there is no such <strong>subarray</strong>, return <code>-1</code>.</p>

<p>A <strong>subarray</strong> is a <strong>contiguous</strong> part of an array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1], k = 1
<strong>Output:</strong> 1
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [1,2], k = 4
<strong>Output:</strong> -1
</pre><p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> nums = [2,-1,2], k = 3
<strong>Output:</strong> 3
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int shortestSubarray(vector<int>& nums, int k) {
    int answer = INT_MAX;
    deque<pair<long long, int>> dq;
    long long total = 0;
    int current = 0;

    for(auto n : nums) {
      if(n >= 0) {
        dq.push_back({n, 1});
        total += n;
        current += 1;
      } else {
        if(total + n <= 0) {
          dq.clear();
          total = 0;
          current = 0;
          continue;
        } else {
          auto [sum, len] = dq.back();
          dq.pop_back();
          long long currentSum = n + sum;
          int segLen = 1 + len;
          while(dq.size() && currentSum < 0) {
            auto [s, l] = dq.back();
            dq.pop_back();
            currentSum += s;
            segLen += l;
          }

          total += n;
          dq.push_back({currentSum, segLen});
          current += 1;
        }
      }

      while(dq.size() && total >= k) {
        answer = min(answer, current);
        auto [s, l] = dq.front();
        dq.pop_front();
        total -= s;
        current -= l;
      }
    }

    return answer == INT_MAX ? -1 : answer;
  }
};
```
