+++
updated = 2022-10-20T12:39:43+08:00
title = "2022-10-20 Daily Challenge"
path = "2022-10-20-Daily-Challenge"
date = 2022-10-20T12:39:43+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/integer-to-roman/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 20

## Description

**Integer to Roman**

<p>Roman numerals are represented by seven different symbols:&nbsp;<code>I</code>, <code>V</code>, <code>X</code>, <code>L</code>, <code>C</code>, <code>D</code> and <code>M</code>.</p>

<pre>
<strong>Symbol</strong>       <strong>Value</strong>
I             1
V             5
X             10
L             50
C             100
D             500
M             1000</pre>

<p>For example,&nbsp;<code>2</code> is written as <code>II</code>&nbsp;in Roman numeral, just two one&#39;s added together. <code>12</code> is written as&nbsp;<code>XII</code>, which is simply <code>X + II</code>. The number <code>27</code> is written as <code>XXVII</code>, which is <code>XX + V + II</code>.</p>

<p>Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not <code>IIII</code>. Instead, the number four is written as <code>IV</code>. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as <code>IX</code>. There are six instances where subtraction is used:</p>

<ul>
	<li><code>I</code> can be placed before <code>V</code> (5) and <code>X</code> (10) to make 4 and 9.&nbsp;</li>
	<li><code>X</code> can be placed before <code>L</code> (50) and <code>C</code> (100) to make 40 and 90.&nbsp;</li>
	<li><code>C</code> can be placed before <code>D</code> (500) and <code>M</code> (1000) to make 400 and 900.</li>
</ul>

<p>Given an integer, convert it to a roman numeral.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> num = 3
<strong>Output:</strong> &quot;III&quot;
<strong>Explanation:</strong> 3 is represented as 3 ones.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> num = 58
<strong>Output:</strong> &quot;LVIII&quot;
<strong>Explanation:</strong> L = 50, V = 5, III = 3.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> num = 1994
<strong>Output:</strong> &quot;MCMXCIV&quot;
<strong>Explanation:</strong> M = 1000, CM = 900, XC = 90 and IV = 4.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= num &lt;= 3999</code></li>
</ul>


## Solution

``` cpp
class Solution {
  vector<pair<int, int>> p = {
    {1000, 100},
    {500, 100},
    {100, 10},
    {50, 10},
    {10, 1},
    {5, 1},
    {1, 0}
  };
  unordered_map<int, char> mp = {
    {1000, 'M'},
    {500, 'D'},
    {100, 'C'},
    {50, 'L'},
    {10, 'X'},
    {5, 'V'},
    {1, 'I'}
  };
public:
  string intToRoman(int num) {
    string answer;
    for(auto [larger, less] : p) {
      while(num >= larger) {
        num -= larger;
        answer.push_back(mp[larger]);
      }
      if(num >= larger - less) {
        num -= larger - less;
        answer.push_back(mp[less]);
        answer.push_back(mp[larger]);
      }
    }
    return answer;
  }
};

// Accepted
// 3999/3999 cases passed (11 ms)
// Your runtime beats 72.59 % of cpp submissions
// Your memory usage beats 31.42 % of cpp submissions (8.2 MB)
```
