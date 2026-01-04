+++
updated = 2026-01-04T17:33:38+01:00
title = "2026-01-04 Daily Challenge"
path = "2026-01-04-Daily-Challenge"
date = 2026-01-04T17:33:38+01:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/four-divisors/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 4

## Description

**Four Divisors**

<p>Given an integer array <code>nums</code>, return <em>the sum of divisors of the integers in that array that have exactly four divisors</em>. If there is no such integer in the array, return <code>0</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [21,4,7]
<strong>Output:</strong> 32
<strong>Explanation:</strong> 
21 has 4 divisors: 1, 3, 7, 21
4 has 3 divisors: 1, 2, 4
7 has 2 divisors: 1, 7
The answer is the sum of divisors of 21 only.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [21,21]
<strong>Output:</strong> 64
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3,4,5]
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int sumFourDivisors(vector<int>& nums) {
    int answer = 0;
    map<int, int> sums;
    for(auto n : nums) {
      if(sums.count(n)) {
        if(sums[n] != -1) answer += sums[n];
        continue;
      }
      int c = 0;
      int s = 0;
      for(int i = 1; i * i <= n; ++i) {
        if(!(n % i)) {
          if(i * i == n) {
            s = -1;
            c = -1;
            break;
          }
          c += 2;
          s += i + (n / i);
        }
      }
      if(c == 4) {
        answer += s;
        sums[n] = s;
      } else {
        sums[n] = -1;
      }
    }
    return answer;
  }
};

// Accepted
// 18/18 cases passed (30 ms)
// Your runtime beats 49.51 % of cpp submissions
// Your memory usage beats 24.63 % of cpp submissions (19.1 MB)
```
