+++
updated = 2022-12-27T12:05:00+08:00
title = "2022-12-27 Daily Challenge"
path = "2022-12-27-Daily-Challenge"
date = 2022-12-27T12:05:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 27

## Description

**Maximum Bags With Full Capacity of Rocks**

<p>You have <code>n</code> bags numbered from <code>0</code> to <code>n - 1</code>. You are given two <strong>0-indexed</strong> integer arrays <code>capacity</code> and <code>rocks</code>. The <code>i<sup>th</sup></code> bag can hold a maximum of <code>capacity[i]</code> rocks and currently contains <code>rocks[i]</code> rocks. You are also given an integer <code>additionalRocks</code>, the number of additional rocks you can place in <strong>any</strong> of the bags.</p>

<p>Return<em> the <strong>maximum</strong> number of bags that could have full capacity after placing the additional rocks in some bags.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> capacity = [2,3,4,5], rocks = [1,2,4,4], additionalRocks = 2
<strong>Output:</strong> 3
<strong>Explanation:</strong>
Place 1 rock in bag 0 and 1 rock in bag 1.
The number of rocks in each bag are now [2,3,4,4].
Bags 0, 1, and 2 have full capacity.
There are 3 bags at full capacity, so we return 3.
It can be shown that it is not possible to have more than 3 bags at full capacity.
Note that there may be other ways of placing the rocks that result in an answer of 3.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> capacity = [10,2,2], rocks = [2,2,0], additionalRocks = 100
<strong>Output:</strong> 3
<strong>Explanation:</strong>
Place 8 rocks in bag 0 and 2 rocks in bag 2.
The number of rocks in each bag are now [10,2,2].
Bags 0, 1, and 2 have full capacity.
There are 3 bags at full capacity, so we return 3.
It can be shown that it is not possible to have more than 3 bags at full capacity.
Note that we did not use all of the additional rocks.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == capacity.length == rocks.length</code></li>
	<li><code>1 &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= capacity[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= rocks[i] &lt;= capacity[i]</code></li>
	<li><code>1 &lt;= additionalRocks &lt;= 10<sup>9</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
    int len = capacity.size();
    for(int i = 0; i < len; ++i) {
      capacity[i] -= rocks[i];
    }
    sort(capacity.begin(), capacity.end());
    for(int i = 0; i < len && additionalRocks; ++i) {
      if(capacity[i]) {
        if(capacity[i] <= additionalRocks) {
          additionalRocks -= capacity[i];
          capacity[i] = 0;
        } else {
          additionalRocks = 0;
        }
      }
    }
    sort(capacity.begin(), capacity.end());
    return upper_bound(capacity.begin(), capacity.end(), 0) - capacity.begin();
  }
};

// Accepted
// 170/170 cases passed (223 ms)
// Your runtime beats 76.70 % of cpp submissions
// Your memory usage beats 79.56 % of cpp submissions (84.8 MB)
```
