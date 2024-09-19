+++
updated = 2024-09-19T19:48:52+08:00
title = "2024-09-19 Daily Challenge"
path = "2024-09-19-Daily-Challenge"
date = 2024-09-19T19:48:52+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/different-ways-to-add-parentheses/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 19

## Description

**Different Ways to Add Parentheses**

<p>Given a string <code>expression</code> of numbers and operators, return <em>all possible results from computing all the different possible ways to group numbers and operators</em>. You may return the answer in <strong>any order</strong>.</p>

<p>The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed <code>10<sup>4</sup></code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> expression = &quot;2-1-1&quot;
<strong>Output:</strong> [0,2]
<strong>Explanation:</strong>
((2-1)-1) = 0 
(2-(1-1)) = 2
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> expression = &quot;2*3-4*5&quot;
<strong>Output:</strong> [-34,-14,-10,-10,10]
<strong>Explanation:</strong>
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= expression.length &lt;= 20</code></li>
	<li><code>expression</code> consists of digits and the operator <code>&#39;+&#39;</code>, <code>&#39;-&#39;</code>, and <code>&#39;*&#39;</code>.</li>
	<li>All the integer values in the input expression are in the range <code>[0, 99]</code>.</li>
	<li>The integer values in the input expression do not have a leading <code>&#39;-&#39;</code> or <code>&#39;+&#39;</code> denoting the sign.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  vector<int> diffWaysToCompute(string expression) {
    vector<int> answer;
    for(int i = 0; i < expression.size(); ++i) {
      char op = expression[i];
      if(isdigit(op)) continue;
      vector<int> r1 = diffWaysToCompute(expression.substr(0, i));
      vector<int> r2 = diffWaysToCompute(expression.substr(i + 1));
      for(int a : r1) {
        for(int b : r2) {
          if(op == '+') answer.push_back(a + b);
          else if(op == '-') answer.push_back(a - b);
          else answer.push_back(a * b);
        }
      }
    }
    if(answer.empty()) return {stoi(expression)};
    return answer;
  }
};
```
