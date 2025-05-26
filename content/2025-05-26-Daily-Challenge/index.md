+++
updated = 2025-05-26T10:52:57+08:00
title = "2025-05-26 Daily Challenge"
path = "2025-05-26-Daily-Challenge"
date = 2025-05-26T10:52:57+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 26

## Description

**Largest Color Value in a Directed Graph**

<p>There is a <strong>directed graph</strong> of <code>n</code> colored nodes and <code>m</code> edges. The nodes are numbered from <code>0</code> to <code>n - 1</code>.</p>

<p>You are given a string <code>colors</code> where <code>colors[i]</code> is a lowercase English letter representing the <strong>color</strong> of the <code>i<sup>th</sup></code> node in this graph (<strong>0-indexed</strong>). You are also given a 2D array <code>edges</code> where <code>edges[j] = [a<sub>j</sub>, b<sub>j</sub>]</code> indicates that there is a <strong>directed edge</strong> from node <code>a<sub>j</sub></code> to node <code>b<sub>j</sub></code>.</p>

<p>A valid <strong>path</strong> in the graph is a sequence of nodes <code>x<sub>1</sub> -&gt; x<sub>2</sub> -&gt; x<sub>3</sub> -&gt; ... -&gt; x<sub>k</sub></code> such that there is a directed edge from <code>x<sub>i</sub></code> to <code>x<sub>i+1</sub></code> for every <code>1 &lt;= i &lt; k</code>. The <strong>color value</strong> of the path is the number of nodes that are colored the <strong>most frequently</strong> occurring color along that path.</p>

<p>Return <em>the <strong>largest color value</strong> of any valid path in the given graph, or </em><code>-1</code><em> if the graph contains a cycle</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<p><img alt="" style="width: 400px; height: 182px;" src="https://assets.leetcode.com/uploads/2021/04/21/leet1.png"></p>

<pre><strong>Input:</strong> colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The path 0 -&gt; 2 -&gt; 3 -&gt; 4 contains 3 nodes that are colored <code>"a" (red in the above image)</code>.
</pre>

<p><strong class="example">Example 2:</strong></p>

<p><img alt="" style="width: 85px; height: 85px;" src="https://assets.leetcode.com/uploads/2021/04/21/leet2.png"></p>

<pre><strong>Input:</strong> colors = "a", edges = [[0,0]]
<strong>Output:</strong> -1
<strong>Explanation:</strong> There is a cycle from 0 to 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == colors.length</code></li>
	<li><code>m == edges.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= m &lt;= 10<sup>5</sup></code></li>
	<li><code>colors</code> consists of lowercase English letters.</li>
	<li><code>0 &lt;= a<sub>j</sub>, b<sub>j</sub>&nbsp;&lt; n</code></li>
</ul>

## Solution

``` cpp
class Solution {
  using T = array<int, 26>;
public:
  int largestPathValue(string colors, vector<vector<int>>& edges) {
    vector<vector<int>> neighbors(colors.size());
    vector<int> indegree(colors.size());

    for(const auto &edge : edges) {
      neighbors[edge[0]].push_back(edge[1]);
      indegree[edge[1]] += 1;
    }

    vector<T> count(colors.size(), T{});
    queue<int> q;
    for(int i = 0; i < colors.size(); ++i) {
      if(!indegree[i]) {
        q.push(i);
        count[i][colors[i] - 'a'] = 1;
      }
    }

    int answer = 0;
    int seen = 0;
    while(q.size()) {
      int current = q.front();
      q.pop();
      seen += 1;
      answer = max(answer, *max_element(count[current].begin(), count[current].end()));

      for(auto neighbor : neighbors[current]) {
        for(int i = 0; i < 26; ++i) {
          count[neighbor][i] = max(count[neighbor][i], count[current][i] + (i == colors[neighbor] - 'a'));
        }
        indegree[neighbor] -= 1;
        if(!indegree[neighbor]) {
          q.push(neighbor);
        }
      }
    }

    if(seen < colors.size()) return -1;
    return answer;
  }
};

// Accepted
// 83/83 cases passed (314 ms)
// Your runtime beats 97.47 % of cpp submissions
// Your memory usage beats 98.17 % of cpp submissions (147.8 MB)
```
