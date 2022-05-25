+++
updated = 2022-05-25 18:14:00+08:00
title = "2022-05-25 Daily-Challenge"
path = "2022-05-25-Daily-Challenge"
date = 2022-05-25 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [May LeetCoding Challenge](hhttps://leetcode.com/problems/russian-doll-envelopes/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 25

## Description

**Russian Doll Envelopes**

<p>You are given a 2D array of integers <code>envelopes</code> where <code>envelopes[i] = [w<sub>i</sub>, h<sub>i</sub>]</code> represents the width and the height of an envelope.</p>

<p>One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope&#39;s width and height.</p>

<p>Return <em>the maximum number of envelopes you can Russian doll (i.e., put one inside the other)</em>.</p>

<p><strong>Note:</strong> You cannot rotate an envelope.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong> envelopes = [[5,4],[6,4],[6,7],[2,3]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The maximum number of envelopes you can Russian doll is <code>3</code> ([2,3] =&gt; [5,4] =&gt; [6,7]).
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong> envelopes = [[1,1],[1,1],[1,1]]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= envelopes.length &lt;= 10<sup>5</sup></code></li>
	<li><code>envelopes[i].length == 2</code></li>
	<li><code>1 &lt;= w<sub>i</sub>, h<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
</ul>

## Solution

``` cpp
class Solution {
public:
  int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b){
      return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
    });
    vector<int> dp;
    for(auto &e : envelopes) {
      auto it = lower_bound(dp.begin(), dp.end(), e[1]);
      if(it == dp.end()) {
        dp.push_back(e[1]);
      } else {
        *it = e[1];
      }
    }
    return dp.size();
  }
};

// Accepted
// 231/231 cases passed (4 ms)
// Your runtime beats 73.76 % of cpp submissions
// Your memory usage beats 96.04 % of cpp submissions (6.7 MB)
```
