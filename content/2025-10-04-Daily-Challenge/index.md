+++
updated = 2025-10-04T22:36:34+02:00
title = "2025-10-04 Daily Challenge"
path = "2025-10-04-Daily-Challenge"
date = 2025-10-04T22:36:34+02:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/container-with-most-water/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 4

## Description

**Container With Most Water**

<p>You are given an integer array <code>height</code> of length <code>n</code>. There are <code>n</code> vertical lines drawn such that the two endpoints of the <code>i<sup>th</sup></code> line are <code>(i, 0)</code> and <code>(i, height[i])</code>.</p>

<p>Find two lines that together with the x-axis form a container, such that the container contains the most water.</p>

<p>Return <em>the maximum amount of water a container can store</em>.</p>

<p><strong>Notice</strong> that you may not slant the container.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/17/question_11.jpg" style="width: 600px; height: 287px;" />
<pre>
<strong>Input:</strong> height = [1,8,6,2,5,4,8,3,7]
<strong>Output:</strong> 49
<strong>Explanation:</strong> The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> height = [1,1]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == height.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= height[i] &lt;= 10<sup>4</sup></code></li>
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
  int maxArea(vector<int>& height) {
    int len = height.size();
    int left = 0, right = len - 1;
    int answer = (right - left) * min(height[left], height[right]);
    while(left < right) {
      if(height[left] < height[right]) {
        int tmp = height[left];
        while(left < right && height[left] <= tmp) ++left;
        answer = max(answer, (right - left) * min(height[left], height[right]));
      } else {
        int tmp = height[right];
        while(left < right && height[right] <= tmp) --right;
        answer = max(answer, (right - left) * min(height[left], height[right]));
      }
    }
    return answer;
  }
};

// Accepted
// 65/65 cases passed (4 ms)
// Your runtime beats 21.89 % of cpp submissions
// Your memory usage beats 12.58 % of cpp submissions (63.5 MB)
```
