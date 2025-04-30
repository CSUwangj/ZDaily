+++
updated = 2025-04-30T11:54:21+08:00
title = "2025-04-30 Daily Challenge"
path = "2025-04-30-Daily-Challenge"
date = 2025-04-30T11:54:21+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/find-numbers-with-even-number-of-digits/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 30

## Description

**Find Numbers with Even Number of Digits**

<p>Given an array <code>nums</code> of integers, return how many of them contain an <strong>even number</strong> of digits.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [12,345,2,6,7896]
<strong>Output:</strong> 2
<strong>Explanation: 
</strong>12 contains 2 digits (even number of digits).&nbsp;
345 contains 3 digits (odd number of digits).&nbsp;
2 contains 1 digit (odd number of digits).&nbsp;
6 contains 1 digit (odd number of digits).&nbsp;
7896 contains 4 digits (even number of digits).&nbsp;
Therefore only 12 and 7896 contain an even number of digits.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [555,901,482,1771]
<strong>Output:</strong> 1 
<strong>Explanation: </strong>
Only 1771 contains an even number of digits.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 500</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int findNumbers(vector<int>& nums) {
    int answer = 0;
    for(auto n : nums) {
      answer += to_string(n).length() % 2 == 0;
    }
    return answer;
  }
};

// Accepted
// 105/105 cases passed (3 ms)
// Your runtime beats 10.29 % of cpp submissions
// Your memory usage beats 11.46 % of cpp submissions (14.6 MB)
```
