+++
updated = 2024-05-08T08:23:19+08:00
title = "2024-05-08 Daily Challenge"
path = "2024-05-08-Daily-Challenge"
date = 2024-05-08T08:23:19+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/relative-ranks/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 8

## Description

**Relative Ranks**

<p>You are given an integer array <code>score</code> of size <code>n</code>, where <code>score[i]</code> is the score of the <code>i<sup>th</sup></code> athlete in a competition. All the scores are guaranteed to be <strong>unique</strong>.</p>

<p>The athletes are <strong>placed</strong> based on their scores, where the <code>1<sup>st</sup></code> place athlete has the highest score, the <code>2<sup>nd</sup></code> place athlete has the <code>2<sup>nd</sup></code> highest score, and so on. The placement of each athlete determines their rank:</p>

<ul>
	<li>The <code>1<sup>st</sup></code> place athlete&#39;s rank is <code>&quot;Gold Medal&quot;</code>.</li>
	<li>The <code>2<sup>nd</sup></code> place athlete&#39;s rank is <code>&quot;Silver Medal&quot;</code>.</li>
	<li>The <code>3<sup>rd</sup></code> place athlete&#39;s rank is <code>&quot;Bronze Medal&quot;</code>.</li>
	<li>For the <code>4<sup>th</sup></code> place to the <code>n<sup>th</sup></code> place athlete, their rank is their placement number (i.e., the <code>x<sup>th</sup></code> place athlete&#39;s rank is <code>&quot;x&quot;</code>).</li>
</ul>

<p>Return an array <code>answer</code> of size <code>n</code> where <code>answer[i]</code> is the <strong>rank</strong> of the <code>i<sup>th</sup></code> athlete.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> score = [5,4,3,2,1]
<strong>Output:</strong> [&quot;Gold Medal&quot;,&quot;Silver Medal&quot;,&quot;Bronze Medal&quot;,&quot;4&quot;,&quot;5&quot;]
<strong>Explanation:</strong> The placements are [1<sup>st</sup>, 2<sup>nd</sup>, 3<sup>rd</sup>, 4<sup>th</sup>, 5<sup>th</sup>].</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> score = [10,3,8,9,4]
<strong>Output:</strong> [&quot;Gold Medal&quot;,&quot;5&quot;,&quot;Bronze Medal&quot;,&quot;Silver Medal&quot;,&quot;4&quot;]
<strong>Explanation:</strong> The placements are [1<sup>st</sup>, 5<sup>th</sup>, 3<sup>rd</sup>, 2<sup>nd</sup>, 4<sup>th</sup>].

</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == score.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= score[i] &lt;= 10<sup>6</sup></code></li>
	<li>All the values in <code>score</code> are <strong>unique</strong>.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  vector<string> findRelativeRanks(vector<int>& score) {
    int len = score.size();
    vector<int> indice(len);
    iota(indice.begin(), indice.end(), 0);
    sort(indice.begin(), indice.end(), [&](int a, int b) { return score[a] > score[b];});
    vector<string> answer(len);
    answer[indice[0]] = "Gold Medal";
    if(len > 1) {
      answer[indice[1]] = "Silver Medal";
    }
    if(len > 2) {
      answer[indice[2]] = "Bronze Medal";
    }
    for(int i = 3; i < len; ++i) {
      answer[indice[i]] = to_string(i + 1);
    }
    return answer;
  }
};
```
