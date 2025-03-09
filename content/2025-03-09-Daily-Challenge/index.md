+++
updated = 2025-03-09T11:26:49+08:00
title = "2025-03-09 Daily Challenge"
path = "2025-03-09-Daily-Challenge"
date = 2025-03-09T11:26:49+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 9

## Description

**Alternating Groups II**

<p>You are given a <strong>0-indexed</strong> string <code>blocks</code> of length <code>n</code>, where <code>blocks[i]</code> is either <div class="elfjS" data-track-load="description_content"><p>There is a circle of red and blue tiles. You are given an array of integers <code>colors</code> and an integer <code>k</code>. The color of tile <code>i</code> is represented by <code>colors[i]</code>:</p>

<ul>
	<li><code>colors[i] == 0</code> means that tile <code>i</code> is <strong>red</strong>.</li>
	<li><code>colors[i] == 1</code> means that tile <code>i</code> is <strong>blue</strong>.</li>
</ul>

<p>An <strong>alternating</strong> group is every <code>k</code> contiguous tiles in the circle with <strong>alternating</strong> colors (each tile in the group except the first and last one has a different color from its <strong>left</strong> and <strong>right</strong> tiles).</p>

<p>Return the number of <strong>alternating</strong> groups.</p>

<p><strong>Note</strong> that since <code>colors</code> represents a <strong>circle</strong>, the <strong>first</strong> and the <strong>last</strong> tiles are considered to be next to each other.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">colors = [0,1,0,1,0], k = 3</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<p><strong><img alt="" data-darkreader-inline-bgcolor="" data-darkreader-inline-bgimage="" style="width: 150px; height: 150px; padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem;" src="https://assets.leetcode.com/uploads/2024/06/19/screenshot-2024-05-28-183519.png"></strong></p>

<p>Alternating groups:</p>

<p><img alt="" data-darkreader-inline-bgcolor="" data-darkreader-inline-bgimage="" style="width: 150px; height: 150px; padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem;" src="https://assets.leetcode.com/uploads/2024/05/28/screenshot-2024-05-28-182448.png"><img alt="" data-darkreader-inline-bgcolor="" data-darkreader-inline-bgimage="" style="width: 150px; height: 150px; padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem;" src="https://assets.leetcode.com/uploads/2024/05/28/screenshot-2024-05-28-182844.png"><img alt="" data-darkreader-inline-bgcolor="" data-darkreader-inline-bgimage="" style="width: 150px; height: 150px; padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem;" src="https://assets.leetcode.com/uploads/2024/05/28/screenshot-2024-05-28-183057.png"></p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">colors = [0,1,0,0,1,0,1], k = 6</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<p><strong><img alt="" data-darkreader-inline-bgcolor="" data-darkreader-inline-bgimage="" style="width: 150px; height: 150px; padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem;" src="https://assets.leetcode.com/uploads/2024/06/19/screenshot-2024-05-28-183907.png"></strong></p>

<p>Alternating groups:</p>

<p><img alt="" data-darkreader-inline-bgcolor="" data-darkreader-inline-bgimage="" style="width: 150px; height: 150px; padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem;" src="https://assets.leetcode.com/uploads/2024/06/19/screenshot-2024-05-28-184128.png"><img alt="" data-darkreader-inline-bgcolor="" data-darkreader-inline-bgimage="" style="width: 150px; height: 150px; padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem;" src="https://assets.leetcode.com/uploads/2024/06/19/screenshot-2024-05-28-184240.png"></p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">colors = [1,1,0,1], k = 4</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<p><img alt="" data-darkreader-inline-bgcolor="" data-darkreader-inline-bgimage="" style="width: 150px; height: 150px; padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem;" src="https://assets.leetcode.com/uploads/2024/06/19/screenshot-2024-05-28-184516.png"></p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= colors.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= colors[i] &lt;= 1</code></li>
	<li><code>3 &lt;= k &lt;= colors.length</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int numberOfAlternatingGroups(vector<int>& colors, int k) {
    int len = colors.size();
    int answer = 0;
    int count = 1;
    int last = colors[0];

    for(int i = 1; i < len + k - 1; ++i) {
      int index = i % len;
      if(colors[index] == last) {
        count = 0;
      }

      count += 1;
      if(count >= k) answer += 1;
      last = colors[index];
    }

    return answer;
  }
};

// Accepted
// 625/625 cases passed (80 ms)
// Your runtime beats 17.56 % of cpp submissions
// Your memory usage beats 61.38 % of cpp submissions (102.7 MB)
```
