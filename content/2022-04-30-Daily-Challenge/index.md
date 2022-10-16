+++
updated = 2022-04-30 18:58:00+08:00
title = "2022-04-30 Daily-Challenge"
path = "2022-04-30-Daily-Challenge"
date = 2022-04-30 18:57:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/evaluate-division/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 30

## Description

**Evaluate Division**

<p>You are given an array of variable pairs <code>equations</code> and an array of real numbers <code>values</code>, where <code>equations[i] = [A<sub>i</sub>, B<sub>i</sub>]</code> and <code>values[i]</code> represent the equation <code>A<sub>i</sub> / B<sub>i</sub> = values[i]</code>. Each <code>A<sub>i</sub></code> or <code>B<sub>i</sub></code> is a string that represents a single variable.</p>

<p>You are also given some <code>queries</code>, where <code>queries[j] = [C<sub>j</sub>, D<sub>j</sub>]</code> represents the <code>j<sup>th</sup></code> query where you must find the answer for <code>C<sub>j</sub> / D<sub>j</sub> = ?</code>.</p>

<p>Return <em>the answers to all queries</em>. If a single answer cannot be determined, return <code>-1.0</code>.</p>

<p><strong>Note:</strong> The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong> equations = [[&quot;a&quot;,&quot;b&quot;],[&quot;b&quot;,&quot;c&quot;]], values = [2.0,3.0], queries = [[&quot;a&quot;,&quot;c&quot;],[&quot;b&quot;,&quot;a&quot;],[&quot;a&quot;,&quot;e&quot;],[&quot;a&quot;,&quot;a&quot;],[&quot;x&quot;,&quot;x&quot;]]
<strong>Output:</strong> [6.00000,0.50000,-1.00000,1.00000,-1.00000]
<strong>Explanation:</strong> 
Given: <em>a / b = 2.0</em>, <em>b / c = 3.0</em>
queries are: <em>a / c = ?</em>, <em>b / a = ?</em>, <em>a / e = ?</em>, <em>a / a = ?</em>, <em>x / x = ?</em>
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong> equations = [[&quot;a&quot;,&quot;b&quot;],[&quot;b&quot;,&quot;c&quot;],[&quot;bc&quot;,&quot;cd&quot;]], values = [1.5,2.5,5.0], queries = [[&quot;a&quot;,&quot;c&quot;],[&quot;c&quot;,&quot;b&quot;],[&quot;bc&quot;,&quot;cd&quot;],[&quot;cd&quot;,&quot;bc&quot;]]
<strong>Output:</strong> [3.75000,0.40000,5.00000,0.20000]
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong> equations = [[&quot;a&quot;,&quot;b&quot;]], values = [0.5], queries = [[&quot;a&quot;,&quot;b&quot;],[&quot;b&quot;,&quot;a&quot;],[&quot;a&quot;,&quot;c&quot;],[&quot;x&quot;,&quot;y&quot;]]
<strong>Output:</strong> [0.50000,2.00000,-1.00000,-1.00000]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= equations.length &lt;= 20</code></li>
	<li><code>equations[i].length == 2</code></li>
	<li><code>1 &lt;= A<sub>i</sub>.length, B<sub>i</sub>.length &lt;= 5</code></li>
	<li><code>values.length == equations.length</code></li>
	<li><code>0.0 &lt; values[i] &lt;= 20.0</code></li>
	<li><code>1 &lt;= queries.length &lt;= 20</code></li>
	<li><code>queries[i].length == 2</code></li>
	<li><code>1 &lt;= C<sub>j</sub>.length, D<sub>j</sub>.length &lt;= 5</code></li>
	<li><code>A<sub>i</sub>, B<sub>i</sub>, C<sub>j</sub>, D<sub>j</sub></code> consist of lower case English letters and digits.</li>
</ul>

## Solution

``` cpp
class Solution {
public:
  vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    unordered_map<string, unordered_map<string, double>> fractions;
    queue<pair<string, string>> q;
    int len = equations.size();
    for(int i = 0; i < len; ++i) {
      if(equations[i][0] == equations[i][1]) continue;
      fractions[equations[i][0]][equations[i][1]] = values[i];
      fractions[equations[i][1]][equations[i][0]] = 1.0 / values[i];
      fractions[equations[i][0]][equations[i][0]] = 1.0;
      fractions[equations[i][1]][equations[i][1]] = 1.0;
      // (a / b) * (b / c) = a / c
      // (a / b) / (c / b) = a / c
      // add both fraction itself and its reciprocal so
      // we don't need to concern about so much case
      q.push({equations[i][0], equations[i][1]});
      q.push({equations[i][1], equations[i][0]});
    }
    while(q.size()) {
      const auto [numerator1, denominator1] = q.front();
      q.pop();
      // numerator2 == denominator1
      for(const auto &[denominator2, value] : fractions[denominator1]) {
        if(fractions[numerator1].count(denominator2)) continue;
        fractions[numerator1][denominator2] = value * fractions[numerator1][denominator1];
        q.push({numerator1, denominator2});
      }
    }
    vector<double> answer;
    answer.reserve(queries.size());
    for(const auto &query : queries) {
      if(fractions.count(query[0]) && fractions[query[0]].count(query[1])) {
        answer.push_back(fractions[query[0]][query[1]]);
      } else {
        answer.push_back(-1);
      }
    }
    return answer;
  }
};

// Accepted
// 24/24 cases passed (4 ms)
// Your runtime beats 51.34 % of cpp submissions
// Your memory usage beats 18.38 % of cpp submissions (8.6 MB)
```
