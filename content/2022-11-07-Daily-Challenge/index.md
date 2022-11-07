+++
updated = 2022-11-07T12:08:33+08:00
title = "2022-11-07 Daily Challenge"
path = "2022-11-07-Daily-Challenge"
date = 2022-11-07T12:08:33+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/maximum-69-number/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 7

## Description

**Maximum 69 Number**

<p>You are given a positive integer <code>num</code> consisting only of digits <code>6</code> and <code>9</code>.</p>

<p>Return <em>the maximum number you can get by changing <strong>at most</strong> one digit (</em><code>6</code><em> becomes </em><code>9</code><em>, and </em><code>9</code><em> becomes </em><code>6</code><em>)</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> num = 9669
<strong>Output:</strong> 9969
<strong>Explanation:</strong> 
Changing the first digit results in 6669.
Changing the second digit results in 9969.
Changing the third digit results in 9699.
Changing the fourth digit results in 9666.
The maximum number is 9969.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> num = 9996
<strong>Output:</strong> 9999
<strong>Explanation:</strong> Changing the last digit 6 to 9 results in the maximum number.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> num = 9999
<strong>Output:</strong> 9999
<strong>Explanation:</strong> It is better not to apply any change.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= num &lt;= 10<sup>4</sup></code></li>
	<li><code>num</code>&nbsp;consists of only <code>6</code> and <code>9</code> digits.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int maximum69Number (int num) {
    auto s = to_string(num);
    for(auto &c : s) {
      if(c == '6') {
        c = '9';
        break;
      }
    }
    return stoi(s);
  }
};

// Accepted
// 153/153 cases passed (7 ms)
// Your runtime beats 9.01 % of cpp submissions
// Your memory usage beats 45.85 % of cpp submissions (6 MB)
```
