+++
updated = 2025-10-11T23:48:57+02:00
title = "2025-10-11 Daily Challenge"
path = "2025-10-11-Daily-Challenge"
date = 2025-10-11T23:48:57+02:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/maximum-total-damage-with-spell-casting/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 11

## Description

**Maximum Total Damage With Spell Casting**

<p>A magician has various spells.</p>

<p>You are given an array <code>power</code>, where each element represents the damage of a spell. Multiple spells can have the same damage value.</p>

<p>It is a known fact that if a magician decides to cast a spell with a damage of <code>power[i]</code>, they <strong>cannot</strong> cast any spell with a damage of <code>power[i] - 2</code>, <code>power[i] - 1</code>, <code>power[i] + 1</code>, or <code>power[i] + 2</code>.</p>

<p>Each spell can be cast <strong>only once</strong>.</p>

<p>Return the <strong>maximum</strong> possible <em>total damage</em> that a magician can cast.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">power = [1,1,3,4]</span></p>

<p><strong>Output:</strong> <span class="example-io">6</span></p>

<p><strong>Explanation:</strong></p>

<p>The maximum possible damage of 6 is produced by casting spells 0, 1, 3 with damage 1, 1, 4.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">power = [7,1,6,6]</span></p>

<p><strong>Output:</strong> <span class="example-io">13</span></p>

<p><strong>Explanation:</strong></p>

<p>The maximum possible damage of 13 is produced by casting spells 1, 2, 3 with damage 1, 6, 6.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= power.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= power[i] &lt;= 10<sup>9</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
  void rotate(vector<pair<int, long long>> &arr) {
    arr[0] = arr[1];
    arr[1] = arr[2];
  }
public:
  long long maximumTotalDamage(vector<int>& power) {
    map<int, long long> dp;
    vector<pair<int, long long>> prevs(4);
    for(auto s : power) {
      dp[s] += s;
    }

    for(auto [p, s] : dp) {
      pair<int, long long> newP = {p, prevs[0].second + s};
      if(p > prevs[1].first + 2) {
        newP.second = max(prevs[1].second + s, newP.second);
      } else {
        newP.second = max(prevs[1].second, newP.second);
      }
      if(p > prevs[2].first + 2) {
        newP.second = max(prevs[2].second + s, newP.second);
      } else {
        newP.second = max(prevs[2].second, newP.second);
      }
      rotate(prevs);
      prevs[2] = newP;
    }
    return max({prevs[0].second, prevs[1].second, prevs[2].second});
  }
};

// Accepted
// 554/554 cases passed (396 ms)
// Your runtime beats 37.39 % of cpp submissions
// Your memory usage beats 77.04 % of cpp submissions (189.5 MB)
```
