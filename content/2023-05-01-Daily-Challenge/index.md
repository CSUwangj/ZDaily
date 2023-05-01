+++
updated = 2023-05-01T11:55:18+08:00
title = "2023-05-01 Daily Challenge"
path = "2023-05-01-Daily-Challenge"
date = 2023-05-01T11:55:18+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 1

## Description

**Average Salary Excluding the Minimum and Maximum Salary**

<p>You are given an array of <strong>unique</strong> integers <code>salary</code> where <code>salary[i]</code> is the salary of the <code>i<sup>th</sup></code> employee.</p>

<p>Return <em>the average salary of employees excluding the minimum and maximum salary</em>. Answers within <code>10<sup>-5</sup></code> of the actual answer will be accepted.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> salary = [4000,3000,1000,2000]
<strong>Output:</strong> 2500.00000
<strong>Explanation:</strong> Minimum salary and maximum salary are 1000 and 4000 respectively.
Average salary excluding minimum and maximum salary is (2000+3000) / 2 = 2500
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> salary = [1000,2000,3000]
<strong>Output:</strong> 2000.00000
<strong>Explanation:</strong> Minimum salary and maximum salary are 1000 and 3000 respectively.
Average salary excluding minimum and maximum salary is (2000) / 1 = 2000
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= salary.length &lt;= 100</code></li>
	<li><code>1000 &lt;= salary[i] &lt;= 10<sup>6</sup></code></li>
	<li>All the integers of <code>salary</code> are <strong>unique</strong>.</li>
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
public:
  double average(vector<int>& salary) {
    int sum = accumulate(salary.begin(), salary.end(), 0);
    int mmin = *min_element(salary.begin(), salary.end());
    int mmax = *max_element(salary.begin(), salary.end());

    return (sum - mmin - mmax) * 1.0 / (salary.size() - 2);
  }
};

// Accepted
// 43/43 cases passed (5 ms)
// Your runtime beats 23.02 % of cpp submissions
// Your memory usage beats 84.06 % of cpp submissions (7.1 MB)
```
