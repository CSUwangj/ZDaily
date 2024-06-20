+++
updated = 2024-06-20T13:07:29+08:00
title = "2024-06-20 Daily Challenge"
path = "2024-06-20-Daily-Challenge"
date = 2024-06-20T13:07:29+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/magnetic-force-between-two-balls/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 20

## Description

**Magnetic Force Between Two Balls**

<p>In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has <code>n</code> empty baskets, the <code>i<sup>th</sup></code> basket is at <code>position[i]</code>, Morty has <code>m</code> balls and needs to distribute the balls into the baskets such that the <strong>minimum magnetic force</strong> between any two balls is <strong>maximum</strong>.</p>

<p>Rick stated that magnetic force between two different balls at positions <code>x</code> and <code>y</code> is <code>|x - y|</code>.</p>

<p>Given the integer array <code>position</code> and the integer <code>m</code>. Return <em>the required force</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/11/q3v1.jpg" style="width: 562px; height: 195px;" />
<pre>
<strong>Input:</strong> position = [1,2,3,4,7], m = 3
<strong>Output:</strong> 3
<strong>Explanation:</strong> Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6]. The minimum magnetic force is 3. We cannot achieve a larger minimum magnetic force than 3.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> position = [5,4,3,2,1,1000000000], m = 2
<strong>Output:</strong> 999999999
<strong>Explanation:</strong> We can use baskets 1 and 1000000000.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == position.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= position[i] &lt;= 10<sup>9</sup></code></li>
	<li>All integers in <code>position</code> are <strong>distinct</strong>.</li>
	<li><code>2 &lt;= m &lt;= position.length</code></li>
</ul>


## Solution

``` cpp
class Solution {
  bool verify(const vector<int> &position, int m, int d) {
    m -= 1;
    int current = position.front();
    for(auto pos : position) {
      if(pos - current >= d) {
        m -= 1;
        current = pos;
      }
    }
    return m < 1;
  }
public:
  int maxDistance(vector<int>& position, int m) {
    sort(position.begin(), position.end());
    int low = 1;
    int high = (position.front() + position.back()) / (m - 1);
    while(low < high) {
      int mid = (low + high + 1) / 2;
      if(verify(position, m, mid)) {
        low = mid;
      } else {
        high = mid - 1;
      }
    }
    return high;
  }
};
```
