+++
updated = 2025-08-18T23:29:42+02:00
title = "2025-08-18 Daily Challenge"
path = "2025-08-18-Daily-Challenge"
date = 2025-08-18T23:29:42+02:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/24-game/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 18

## Description

**24 Game**

<p>You are given an integer array <code>cards</code> of length <code>4</code>. You have four cards, each containing a number in the range <code>[1, 9]</code>. You should arrange the numbers on these cards in a mathematical expression using the operators <code>[&#39;+&#39;, &#39;-&#39;, &#39;*&#39;, &#39;/&#39;]</code> and the parentheses <code>&#39;(&#39;</code> and <code>&#39;)&#39;</code> to get the value 24.</p>

<p>You are restricted with the following rules:</p>

<ul>
	<li>The division operator <code>&#39;/&#39;</code> represents real division, not integer division.

	<ul>
		<li>For example, <code>4 / (1 - 2 / 3) = 4 / (1 / 3) = 12</code>.</li>
	</ul>
	</li>
	<li>Every operation done is between two numbers. In particular, we cannot use <code>&#39;-&#39;</code> as a unary operator.
	<ul>
		<li>For example, if <code>cards = [1, 1, 1, 1]</code>, the expression <code>&quot;-1 - 1 - 1 - 1&quot;</code> is <strong>not allowed</strong>.</li>
	</ul>
	</li>
	<li>You cannot concatenate numbers together
	<ul>
		<li>For example, if <code>cards = [1, 2, 1, 2]</code>, the expression <code>&quot;12 + 12&quot;</code> is not valid.</li>
	</ul>
	</li>
</ul>

<p>Return <code>true</code> if you can get such expression that evaluates to <code>24</code>, and <code>false</code> otherwise.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> cards = [4,1,8,7]
<strong>Output:</strong> true
<strong>Explanation:</strong> (8-4) * (7-1) = 24
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> cards = [1,2,1,2]
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>cards.length == 4</code></li>
	<li><code>1 &lt;= cards[i] &lt;= 9</code></li>
</ul>


## Solution

``` cpp
class Solution {
  const double EPS = 1e-7;
  bool solve(vector<double> &cards) {
    if(cards.size() == 1) return abs(cards[0] - 24) < EPS;

    int sz = cards.size();
    for(int i = 0; i < sz; ++i) {
      for(int j = 0; j < sz; ++j) {
        if(i == j) continue;

        vector<double> next;
        for(int k = 0; k < sz; ++k) {
          if(k == i || k == j) continue;
          next.push_back(cards[k]);
        }

        double a = cards[i];
        double b = cards[j];
        vector<double> candidates{a - b, a + b, b - a, a * b};
        if(abs(a) > EPS) candidates.push_back(b / a);
        if(abs(b) > EPS) candidates.push_back(a / b);
        for(auto val : candidates) {
          next.push_back(val);
          if(solve(next)) return true;
          next.pop_back();
        }
      }
    }
    return false;
  }
public:
  bool judgePoint24(vector<int>& cards) {
    vector<double> dcards(cards.begin(), cards.end());
    return solve(dcards);
  }
};

// Accepted
// 71/71 cases passed (63 ms)
// Your runtime beats 20.85 % of cpp submissions
// Your memory usage beats 17.49 % of cpp submissions (30.7 MB)
```
