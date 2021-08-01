+++
title = "2021-05-25 Daily-Challenge"
path = "2021-05-25-Daily-Challenge"
date = 2021-05-25 18:40:59+08:00
updated = 2021-05-25 18:55:12+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Length of Longest Fibonacci Subsequence](https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/) and leetcode's [May LeetCoding Challenge](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/601/week-4-may-22nd-may-28th/3755/) with `cpp`.

<!-- more -->

# Length of Longest Fibonacci Subsequence

## Description

<p>A sequence <code>X<sub>1</sub>, X<sub>2</sub>, ..., X<sub>n</sub></code> is <em>Fibonacci-like</em> if:</p>

<ul>
	<li><code>n &gt;= 3</code></li>
	<li><code>X<sub>i</sub> + X<sub>i+1</sub> = X<sub>i+2</sub></code> for all <code>i + 2 &lt;= n</code></li>
</ul>

<p>Given a <b>strictly increasing</b> array <code>arr</code> of positive integers forming a sequence, return the <strong>length</strong> of the longest Fibonacci-like subsequence of <code>arr</code>. If one does not exist, return <code>0</code>.</p>

<p><em>A subsequence is derived from another sequence <code>arr</code> by deleting any number of elements (including none) from <code>arr</code>, without changing the order of the remaining elements. For example, <code>[3, 5, 8]</code> is a subsequence of <code>[3, 4, 5, 6, 7, 8]</code>.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><code><strong>Input:</strong> arr = [1,2,3,4,5,6,7,8]
<strong>Output:</strong> 5
<strong>Explanation:</strong> The longest subsequence that is fibonacci-like: [1,2,3,5,8].</code></pre>

<p><strong>Example 2:</strong></p>

<pre><code><strong>Input:</strong> arr = [1,3,7,11,12,14,18]
<strong>Output:</strong> 3
<strong>Explanation</strong>:<strong> </strong>The longest subsequence that is fibonacci-like: [1,11,12], [3,11,14] or [7,11,18].</code></pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= arr.length &lt;= 1000</code></li>
	<li><code>1 &lt;= arr[i] &lt; arr[i + 1] &lt;= 10<sup>9</sup></code></li>
</ul>

## Solution

I thought there was a non-square-time-complexity solution... but no

``` cpp
class Solution {
public:
  int lenLongestFibSubseq(vector<int>& arr) {
    unordered_map<int, unordered_map<int, int>> mp;
    unordered_set<int> has;
    int len = arr.size();
    int answer = 0;
    for(auto i : arr) has.insert(i);
    for(int i = 2; i < len; ++i) {
      for(int j = i - 1; j >= 0 && arr[j] * 2 > arr[i]; --j) {
        int gt = arr[i];
        int lt = arr[j];
        int diff = gt - lt;
        if(has.count(diff)) {
          mp[gt][lt] = mp[lt][diff] + 1;
          answer = max(mp[gt][lt], answer);
        }
      }
    }
    return answer ? answer + 2 : 0;
  }
};
```

# May LeetCoding Challenge 25

## Description

**Evaluate Reverse Polish Notation**

<p>Evaluate the value of an arithmetic expression in <a href="http://en.wikipedia.org/wiki/Reverse_Polish_notation" target="_blank">Reverse Polish Notation</a>.</p>

<p>Valid operators are <code>+</code>, <code>-</code>, <code>*</code>, and <code>/</code>. Each operand may be an integer or another expression.</p>

<p><strong>Note</strong> that division between two integers should truncate toward zero.</p>

<p>It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, and there will not be any division by zero operation.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><code><strong>Input:</strong> tokens = [&quot;2&quot;,&quot;1&quot;,&quot;+&quot;,&quot;3&quot;,&quot;*&quot;]
<strong>Output:</strong> 9
<strong>Explanation:</strong> ((2 + 1) * 3) = 9</code></pre>

<p><strong>Example 2:</strong></p>

<pre><code><strong>Input:</strong> tokens = [&quot;4&quot;,&quot;13&quot;,&quot;5&quot;,&quot;/&quot;,&quot;+&quot;]
<strong>Output:</strong> 6
<strong>Explanation:</strong> (4 + (13 / 5)) = 6</code></pre>

<p><strong>Example 3:</strong></p>

<pre><code><strong>Input:</strong> tokens = [&quot;10&quot;,&quot;6&quot;,&quot;9&quot;,&quot;3&quot;,&quot;+&quot;,&quot;-11&quot;,&quot;*&quot;,&quot;/&quot;,&quot;*&quot;,&quot;17&quot;,&quot;+&quot;,&quot;5&quot;,&quot;+&quot;]
<strong>Output:</strong> 22
<strong>Explanation:</strong> ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22</code></pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= tokens.length &lt;= 10<sup>4</sup></code></li>
	<li><code>tokens[i]</code> is either an operator: <code>&quot;+&quot;</code>, <code>&quot;-&quot;</code>, <code>&quot;*&quot;</code>, or <code>&quot;/&quot;</code>, or an integer in the range <code>[-200, 200]</code>.</li>
</ul>

## Solution

``` cpp
class Solution {
public:
  string toLowerCase(string s) {
    for(auto &c : s) c = tolower(c);
    return s;
  }
};
```
