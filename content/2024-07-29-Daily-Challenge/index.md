+++
updated = 2024-07-29T14:00:01+08:00
title = "2024-07-29 Daily Challenge"
path = "2024-07-29-Daily-Challenge"
date = 2024-07-29T14:00:01+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/count-number-of-teams/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 29

## Description

**Count Number of Teams**

<p>There are <code>n</code> soldiers standing in a line. Each soldier is assigned a <strong>unique</strong> <code>rating</code> value.</p>

<p>You have to form a team of 3 soldiers amongst them under the following rules:</p>

<ul>
	<li>Choose 3 soldiers with index (<code>i</code>, <code>j</code>, <code>k</code>) with rating (<code>rating[i]</code>, <code>rating[j]</code>, <code>rating[k]</code>).</li>
	<li>A team is valid if: (<code>rating[i] &lt; rating[j] &lt; rating[k]</code>) or (<code>rating[i] &gt; rating[j] &gt; rating[k]</code>) where (<code>0 &lt;= i &lt; j &lt; k &lt; n</code>).</li>
</ul>

<p>Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> rating = [2,5,3,4,1]
<strong>Output:</strong> 3
<strong>Explanation:</strong> We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1). 
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> rating = [2,1,3]
<strong>Output:</strong> 0
<strong>Explanation:</strong> We can&#39;t form any team given the conditions.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> rating = [1,2,3,4]
<strong>Output:</strong> 4
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == rating.length</code></li>
	<li><code>3 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= rating[i] &lt;= 10<sup>5</sup></code></li>
	<li>All the integers in <code>rating</code> are <strong>unique</strong>.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int numTeams(vector<int>& rating) {
    int answer = 0;
    for(int j = 1; j < rating.size() - 1; ++j) {
      int lessLeft = 0;
      int lessRight = 0;
      int greaterLeft = 0;
      int greaterRight = 0;
      for(int i = 0; i < j; ++i) {
        if(rating[i] < rating[j]) lessLeft += 1;
        else if(rating[i] > rating[j]) greaterLeft += 1;
      }
      for(int k = j + 1; k < rating.size(); ++k) {
        if(rating[k] < rating[j]) lessRight += 1;
        else if(rating[k] > rating[j]) greaterRight += 1;
      }
      answer += lessLeft * greaterRight + lessRight * greaterLeft;
    }
    return answer;
  }
};
```
