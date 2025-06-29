+++
updated = 2025-06-30T02:01:59+08:00
title = "2025-06-29 Daily Challenge"
path = "2025-06-29-Daily-Challenge"
date = 2025-06-30T02:01:59+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 29

## Description

**Number of Subsequences That Satisfy the Given Sum Condition**

<p>You are given an array of integers <code>nums</code> and an integer <code>target</code>.</p>

<p>Return <em>the number of <strong>non-empty</strong> subsequences of </em><code>nums</code><em> such that the sum of the minimum and maximum element on it is less or equal to </em><code>target</code>. Since the answer may be too large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,5,6,7], target = 9
<strong>Output:</strong> 4
<strong>Explanation:</strong> There are 4 subsequences that satisfy the condition.
[3] -&gt; Min value + max value &lt;= target (3 + 3 &lt;= 9)
[3,5] -&gt; (3 + 5 &lt;= 9)
[3,5,6] -&gt; (3 + 6 &lt;= 9)
[3,6] -&gt; (3 + 6 &lt;= 9)
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,3,6,8], target = 10
<strong>Output:</strong> 6
<strong>Explanation:</strong> There are 6 subsequences that satisfy the condition. (nums can have repeated numbers).
[3] , [3] , [3,3], [3,6] , [3,6] , [3,3,6]
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,3,3,4,6,7], target = 12
<strong>Output:</strong> 61
<strong>Explanation:</strong> There are 63 non-empty subsequences, two of them do not satisfy the condition ([6,7], [7]).
Number of valid subsequences (63 - 2 = 61).
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= target &lt;= 10<sup>6</sup></code></li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
const int MOD = 1e9 + 7;
int qpow(int b, int e) {
  int result = 1;
  while(e) {
    if(e & 1) {
      result = 1LL * result * b % MOD;
    }
    b = 1LL * b * b % MOD;
    e >>= 1;
  }
  return result;
}
class Solution {
public:
  int numSubseq(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int left = 0;
    int right = nums.size() - 1;
    int answer = 0;
    while(left <= right && left < nums.size()) {
      while(right >= 0 && left <= right && nums[left] + nums[right] > target) {
        right -= 1;
      }
      if(right < 0) break;
      if(left < right) {
        answer += qpow(2, right - left);
      } else if (nums[left] * 2 <= target) {
        answer += 1;
      }
      answer %= MOD;
      left += 1;
    }

    return answer;
  }
};

// Accepted
// 63/63 cases passed (26 ms)
// Your runtime beats 88.41 % of cpp submissions
// Your memory usage beats 95.04 % of cpp submissions (51.4 MB)
```
