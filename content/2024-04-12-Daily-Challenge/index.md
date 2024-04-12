+++
updated = 2024-04-12T11:47:41+08:00
title = "2024-04-12 Daily Challenge"
path = "2024-04-12-Daily-Challenge"
date = 2024-04-12T11:47:41+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/trapping-rain-water/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 12

## Description

**Trapping Rain Water**

<p>Given <code>n</code> non-negative integers representing an elevation map where the width of each bar is <code>1</code>, compute how much water it can trap after raining.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img src="https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png" style="width: 412px; height: 161px;" />
<pre>
<strong>Input:</strong> height = [0,1,0,2,1,0,1,3,2,1,2,1]
<strong>Output:</strong> 6
<strong>Explanation:</strong> The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> height = [4,2,0,3,2,5]
<strong>Output:</strong> 9
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == height.length</code></li>
	<li><code>1 &lt;= n &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= height[i] &lt;= 10<sup>5</sup></code></li>
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
  int trap(vector<int>& height) {
    vector<int> maxRights{0};
    int len = height.size();
    for(int i = len - 1; i >= 0; --i) {
      if(height[i] >= maxRights.back()) {
        maxRights.push_back(height[i]);
      }
    }
    int maxLeft = 0;
    int answer = 0;
    for(auto h : height) {
      maxLeft = max(maxLeft, h);
      int maxRight = maxRights.back();
      int waterHeight = maxLeft > maxRight ? maxRight : maxLeft;
      answer += waterHeight > h ? (waterHeight - h) : 0;
      if(h == maxRight) {
        maxRights.pop_back();
      }
    }
    return answer;
  }
};

// Accepted
// 322/322 cases passed (21 ms)
// Your runtime beats 72.47 % of cpp submissions
// Your memory usage beats 43.13 % of cpp submissions (20.2 MB)
```
