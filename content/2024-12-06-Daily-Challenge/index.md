+++
updated = 2024-12-06T18:06:45+08:00
title = "2024-12-06 Daily Challenge"
path = "2024-12-06-Daily-Challenge"
date = 2024-12-06T18:06:45+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 6

## Description

**Maximum Number of Integers to Choose From a Range I**

<p>You are given an integer array <code>banned</code> and two integers <code>n</code> and <code>maxSum</code>. You are choosing some number of integers following the below rules:</p>

<ul>
	<li>The chosen integers have to be in the range <code>[1, n]</code>.</li>
	<li>Each integer can be chosen <strong>at most once</strong>.</li>
	<li>The chosen integers should not be in the array <code>banned</code>.</li>
	<li>The sum of the chosen integers should not exceed <code>maxSum</code>.</li>
</ul>

<p>Return <em>the <strong>maximum</strong> number of integers you can choose following the mentioned rules</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> banned = [1,6,5], n = 5, maxSum = 6
<strong>Output:</strong> 2
<strong>Explanation:</strong> You can choose the integers 2 and 4.
2 and 4 are from the range [1, 5], both did not appear in banned, and their sum is 6, which did not exceed maxSum.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> banned = [1,2,3,4,5,6,7], n = 8, maxSum = 1
<strong>Output:</strong> 0
<strong>Explanation:</strong> You cannot choose any integer while following the mentioned conditions.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> banned = [11], n = 7, maxSum = 50
<strong>Output:</strong> 7
<strong>Explanation:</strong> You can choose the integers 1, 2, 3, 4, 5, 6, and 7.
They are from the range [1, 7], all did not appear in banned, and their sum is 28, which did not exceed maxSum.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= banned.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= banned[i], n &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= maxSum &lt;= 10<sup>9</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int maxCount(vector<int>& banned, int n, int maxSum) {
    set<int> blacklist(banned.begin(), banned.end());

    int sum = 0;
    int answer = 0;
    for(int i = 1; i <= n; ++i) {
      if(blacklist.count(i)) continue;
      if(sum + i > maxSum) break;
      sum += i;
      answer += 1;
    }
    return answer;
  }
};

// Accepted
// 208/208 cases passed (287 ms)
// Your runtime beats 22.14 % of cpp submissions
// Your memory usage beats 19.94 % of cpp submissions (185.6 MB)
```
