+++
updated = 2023-08-27T00:10:07+08:00
title = "2023-08-27 Daily Challenge"
path = "2023-08-27-Daily-Challenge"
date = 2023-08-27T00:10:07+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/frog-jump/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 27

## Description

**Frog Jump**

<p>A frog is crossing a river. The river is divided into some number of units, and at each unit, there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.</p>

<p>Given a list of <code>stones</code>&#39; positions (in units) in sorted <strong>ascending order</strong>, determine if the frog can cross the river by landing on the last stone. Initially, the frog is on the first stone and assumes the first jump must be <code>1</code> unit.</p>

<p>If the frog&#39;s last jump was <code>k</code> units, its next jump must be either <code>k - 1</code>, <code>k</code>, or <code>k + 1</code> units. The frog can only jump in the forward direction.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> stones = [0,1,3,5,6,8,12,17]
<strong>Output:</strong> true
<strong>Explanation:</strong> The frog can jump to the last stone by jumping 1 unit to the 2nd stone, then 2 units to the 3rd stone, then 2 units to the 4th stone, then 3 units to the 6th stone, 4 units to the 7th stone, and 5 units to the 8th stone.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> stones = [0,1,2,3,4,8,9,11]
<strong>Output:</strong> false
<strong>Explanation:</strong> There is no way to jump to the last stone as the gap between the 5th and 6th stone is too large.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= stones.length &lt;= 2000</code></li>
	<li><code>0 &lt;= stones[i] &lt;= 2<sup>31</sup> - 1</code></li>
	<li><code>stones[0] == 0</code></li>
	<li><code>stones</code>&nbsp;is sorted in a strictly increasing order.</li>
</ul>


## Solution

``` cpp
class Solution {
  using pi = pair<int, int>;
public:
  bool canCross(vector<int>& stones) {
    if(stones[1] != 1) return false;
    int target = stones.back();
    set<int> s(stones.begin(), stones.end());
    set<pi> ways;
    queue<pi> q;
    q.push({1, 1});
    while(q.size()) {
      auto [jump, pos] = q.front();
      q.pop();
      if(pos == target) return true;
      for(int i = jump - 1; i < jump + 2; ++i) {
        if(!i) continue;
        if(!s.count(pos + i)) continue;
        if(ways.count({i, pos + i})) continue;
        ways.insert({i, pos + i});
        q.push({i, pos + i});
      }
    }

    return false;
  }
};

// Accepted
// 52/52 cases passed (192 ms)
// Your runtime beats 47.07 % of cpp submissions
// Your memory usage beats 62.79 % of cpp submissions (36.6 MB)
```
