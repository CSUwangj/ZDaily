+++
updated = 2023-12-15T08:30:59+08:00
title = "2023-12-15 Daily Challenge"
path = "2023-12-15-Daily-Challenge"
date = 2023-12-15T08:30:59+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/destination-city/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 15

## Description

**Destination City**

<p>You are given the array <code>paths</code>, where <code>paths[i] = [cityA<sub>i</sub>, cityB<sub>i</sub>]</code> means there exists a direct path going from <code>cityA<sub>i</sub></code> to <code>cityB<sub>i</sub></code>. <em>Return the destination city, that is, the city without any path outgoing to another city.</em></p>

<p>It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one destination city.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> paths = [[&quot;London&quot;,&quot;New York&quot;],[&quot;New York&quot;,&quot;Lima&quot;],[&quot;Lima&quot;,&quot;Sao Paulo&quot;]]
<strong>Output:</strong> &quot;Sao Paulo&quot; 
<strong>Explanation:</strong> Starting at &quot;London&quot; city you will reach &quot;Sao Paulo&quot; city which is the destination city. Your trip consist of: &quot;London&quot; -&gt; &quot;New York&quot; -&gt; &quot;Lima&quot; -&gt; &quot;Sao Paulo&quot;.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> paths = [[&quot;B&quot;,&quot;C&quot;],[&quot;D&quot;,&quot;B&quot;],[&quot;C&quot;,&quot;A&quot;]]
<strong>Output:</strong> &quot;A&quot;
<strong>Explanation:</strong> All possible trips are:&nbsp;
&quot;D&quot; -&gt; &quot;B&quot; -&gt; &quot;C&quot; -&gt; &quot;A&quot;.&nbsp;
&quot;B&quot; -&gt; &quot;C&quot; -&gt; &quot;A&quot;.&nbsp;
&quot;C&quot; -&gt; &quot;A&quot;.&nbsp;
&quot;A&quot;.&nbsp;
Clearly the destination city is &quot;A&quot;.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> paths = [[&quot;A&quot;,&quot;Z&quot;]]
<strong>Output:</strong> &quot;Z&quot;
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= paths.length &lt;= 100</code></li>
	<li><code>paths[i].length == 2</code></li>
	<li><code>1 &lt;= cityA<sub>i</sub>.length, cityB<sub>i</sub>.length &lt;= 10</code></li>
	<li><code>cityA<sub>i</sub> != cityB<sub>i</sub></code></li>
	<li>All strings consist of lowercase and uppercase English letters and the space character.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  string destCity(vector<vector<string>>& paths) {
    map<string, int> degree;
    for(const auto &path : paths) {
      degree[path[0]] += 1;
      degree[path[1]] -= 1;
    }

    for(const auto &[city, d] : degree) {
      if(d == -1) return city;
    }
    return "";
  }
};

// Accepted
// 103/103 cases passed (7 ms)
// Your runtime beats 85.29 % of cpp submissions
// Your memory usage beats 59.81 % of cpp submissions (11 MB)
```
