+++
updated = 2023-11-21T08:24:09+08:00
title = "2023-11-21 Daily Challenge"
path = "2023-11-21-Daily-Challenge"
date = 2023-11-21T08:24:09+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/count-nice-pairs-in-an-array/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 21

## Description

**Count Nice Pairs in an Array**

<p>You are given an array <code>nums</code> that consists of non-negative integers. Let us define <code>rev(x)</code> as the reverse of the non-negative integer <code>x</code>. For example, <code>rev(123) = 321</code>, and <code>rev(120) = 21</code>. A pair of indices <code>(i, j)</code> is <strong>nice</strong> if it satisfies all of the following conditions:</p>

<ul>
	<li><code>0 &lt;= i &lt; j &lt; nums.length</code></li>
	<li><code>nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])</code></li>
</ul>

<p>Return <em>the number of nice pairs of indices</em>. Since that number can be too large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [42,11,1,97]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The two pairs are:
 - (0,3) : 42 + rev(97) = 42 + 79 = 121, 97 + rev(42) = 97 + 24 = 121.
 - (1,2) : 11 + rev(1) = 11 + 1 = 12, 1 + rev(11) = 1 + 11 = 12.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [13,10,35,24,76]
<strong>Output:</strong> 4
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  const int MOD = 1e9 + 7;
  int rev(int num) {
    int result = 0;
    while(num) {
      result *= 10;
      result += num % 10;
      num /= 10;
    }
    return result;
  }
public:
  int countNicePairs(vector<int>& nums) {
    map<int, int> revDiff;
    for(auto n : nums) {
      revDiff[n - rev(n)] += 1;
    }
    int answer = 0;
    for(const auto &[_diff, count] : revDiff) {
      answer += 1LL * count * (count - 1) / 2 % MOD;
      answer %= MOD;
    }
    return answer;
  }
};

// Accepted
// 84/84 cases passed (71 ms)
// Your runtime beats 99.16 % of cpp submissions
// Your memory usage beats 98.74 % of cpp submissions (56.2 MB)
```
