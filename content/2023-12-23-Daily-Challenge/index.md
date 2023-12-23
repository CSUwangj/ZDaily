+++
updated = 2023-12-23T15:24:57+08:00
title = "2023-12-23 Daily Challenge"
path = "2023-12-23-Daily-Challenge"
date = 2023-12-23T15:24:57+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/path-crossing/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 23

## Description

**Path Crossing**

<p>Given a string <code>path</code>, where <code>path[i] = &#39;N&#39;</code>, <code>&#39;S&#39;</code>, <code>&#39;E&#39;</code> or <code>&#39;W&#39;</code>, each representing moving one unit north, south, east, or west, respectively. You start at the origin <code>(0, 0)</code> on a 2D plane and walk on the path specified by <code>path</code>.</p>

<p>Return <code>true</code> <em>if the path crosses itself at any point, that is, if at any time you are on a location you have previously visited</em>. Return <code>false</code> otherwise.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/06/10/screen-shot-2020-06-10-at-123929-pm.png" style="width: 400px; height: 358px;" />
<pre>
<strong>Input:</strong> path = &quot;NES&quot;
<strong>Output:</strong> false 
<strong>Explanation:</strong> Notice that the path doesn&#39;t cross any point more than once.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/06/10/screen-shot-2020-06-10-at-123843-pm.png" style="width: 400px; height: 339px;" />
<pre>
<strong>Input:</strong> path = &quot;NESWW&quot;
<strong>Output:</strong> true
<strong>Explanation:</strong> Notice that the path visits the origin twice.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= path.length &lt;= 10<sup>4</sup></code></li>
	<li><code>path[i]</code> is either <code>&#39;N&#39;</code>, <code>&#39;S&#39;</code>, <code>&#39;E&#39;</code>, or <code>&#39;W&#39;</code>.</li>
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
  map<char, int> mp= {
    { 'N', 10000 },
    { 'S', -10000 },
    { 'W', 1 },
    { 'E', -1 }
  };
public:
  bool isPathCrossing(string path) {
    set<int> position{ 0 };
    int current = 0;
    for(auto d : path) {
      current += mp[d];
      if(position.count(current)) {
        return true;
      }
      position.insert(current);
    }
    return false;
  }
};

// Accepted
// 81/81 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 64.64 % of cpp submissions (7.2 MB)
```
