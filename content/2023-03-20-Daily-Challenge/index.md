+++
updated = 2023-03-20T15:01:45+08:00
title = "2023-03-20 Daily Challenge"
path = "2023-03-20-Daily-Challenge"
date = 2023-03-20T15:01:45+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/can-place-flowers/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 20

## Description

**Can Place Flowers**

<p>You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in <strong>adjacent</strong> plots.</p>

<p>Given an integer array <code>flowerbed</code> containing <code>0</code>&#39;s and <code>1</code>&#39;s, where <code>0</code> means empty and <code>1</code> means not empty, and an integer <code>n</code>, return <em>if</em> <code>n</code> new flowers can be planted in the <code>flowerbed</code> without violating the no-adjacent-flowers rule.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> flowerbed = [1,0,0,0,1], n = 1
<strong>Output:</strong> true
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> flowerbed = [1,0,0,0,1], n = 2
<strong>Output:</strong> false
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= flowerbed.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>flowerbed[i]</code> is <code>0</code> or <code>1</code>.</li>
	<li>There are no two adjacent flowers in <code>flowerbed</code>.</li>
	<li><code>0 &lt;= n &lt;= flowerbed.length</code></li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int count = 0;
    int flowers = 0;
    for(auto flowered : flowerbed) {
      if(flowered) {
        flowers += count / 2;
        count = -1;
      } else {
        count += 1;
      }
    }
    flowers += (count + 1) / 2;
    return flowers >= n;
  }
};

// Accepted
// 124/124 cases passed (10 ms)
// Your runtime beats 97.73 % of cpp submissions
// Your memory usage beats 34.3 % of cpp submissions (20.3 MB)
```
