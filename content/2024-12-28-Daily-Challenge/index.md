+++
updated = 2024-12-28T23:25:07+08:00
title = "2024-12-28 Daily Challenge"
path = "2024-12-28-Daily-Challenge"
date = 2024-12-28T23:25:07+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 28

## Description

**Maximum Sum of 3 Non-Overlapping Subarrays**

<p>Given an integer array <code>nums</code> and an integer <code>k</code>, find three non-overlapping subarrays of length <code>k</code> with maximum sum and return them.</p>

<p>Return the result as a list of indices representing the starting position of each interval (<strong>0-indexed</strong>). If there are multiple answers, return the lexicographically smallest one.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,1,2,6,7,5,1], k = 2
<strong>Output:</strong> [0,3,5]
<strong>Explanation:</strong> Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,1,2,1,2,1,2,1], k = 2
<strong>Output:</strong> [0,2,4]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;&nbsp;2<sup>16</sup></code></li>
	<li><code>1 &lt;= k &lt;= floor(nums.length / 3)</code></li>
</ul>


## Solution

``` cpp
class Solution {
  using ll = long long;
public:
  vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    int len = nums.size();
    vector<ll> sumK(len);
    for(int i = 0; i < k; ++i) {
      sumK[0] += nums[i];
    }
    for(int i = 1; i + k - 1 < len; ++i) {
      sumK[i] = sumK[i - 1] - nums[i - 1] + nums[i + k - 1];
    }
    vector<pair<ll, pair<int, int>>> dp(len);
    priority_queue<pair<ll, int>> pq1;
    priority_queue<pair<ll, pair<int, int>>> pq2;
    int answerSum = 0;
    vector<int> answerPos = {0, 0, 0};
    for(int i = k; i + k - 1 < len; ++i) {
      pq1.push({sumK[i - k], len - (i - k)});
      dp[i] = dp[i - 1];
      if(sumK[i] + pq1.top().first > dp[i - 1].first) {
        dp[i].first = sumK[i] + pq1.top().first;
        dp[i].second = make_pair(pq1.top().second, len - i);
      }
      if(i >= k * 2) {
        pq2.push(dp[i - k]);
        if(sumK[i] + pq2.top().first > answerSum) {
          answerSum = sumK[i] + pq2.top().first;
          answerPos[0] = len - pq2.top().second.first;
          answerPos[1] = len - pq2.top().second.second;
          answerPos[2] = i;
        }
      }
    }
    return answerPos;
  }
};

// Accepted
// 43/43 cases passed (11 ms)
// Your runtime beats 33.6 % of cpp submissions
// Your memory usage beats 21.41 % of cpp submissions (34.9 MB)
```
