+++
updated = 2025-04-06T14:08:25+08:00
title = "2025-04-06 Daily Challenge"
path = "2025-04-06-Daily-Challenge"
date = 2025-04-06T14:08:25+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/largest-divisible-subset/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 6

## Description

**Largest Divisible Subset**

<p>Given a set of <strong>distinct</strong> positive integers <code>nums</code>, return the largest subset <code>answer</code> such that every pair <code>(answer[i], answer[j])</code> of elements in this subset satisfies:</p>

<ul>
	<li><code>answer[i] % answer[j] == 0</code>, or</li>
	<li><code>answer[j] % answer[i] == 0</code></li>
</ul>

<p>If there are multiple solutions, return any of them.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> [1,2]
<strong>Explanation:</strong> [1,3] is also accepted.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,4,8]
<strong>Output:</strong> [1,2,4,8]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 2 * 10<sup>9</sup></code></li>
	<li>All the integers in <code>nums</code> are <strong>unique</strong>.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int len = nums.size();
    vector<int> dp(len, 1);
    vector<int> child(len, -1);
    
    for(int i = 1; i < len; ++i) {
      for(int j = 0; j < i; ++j) {
        if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
          dp[i] = dp[j] + 1;
          child[i] = j;
        }
      }
    }
    
    int answerLen = 0;
    int answerEnd = -1;
    for(int i = 0; i < len; ++i) {
      if(dp[i] > answerLen) {
        answerLen = dp[i];
        answerEnd = i;
      }
    }
    
    vector<int> answer;
    while(answerEnd != -1) {
      answer.push_back(nums[answerEnd]);
      answerEnd = child[answerEnd];
    }
    
    return answer;
  }
};

// Accepted
// 49/49 cases passed (12 ms)
// Your runtime beats 92.77 % of cpp submissions
// Your memory usage beats 11.66 % of cpp submissions (11.5 MB)
```
