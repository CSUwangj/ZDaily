+++
updated = 2024-04-28T19:26:17+08:00
title = "2024-04-28 Daily Challenge"
path = "2024-04-28-Daily-Challenge"
date = 2024-04-28T19:26:17+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/sum-of-distances-in-tree/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 28

## Description

**Sum of Distances in Tree**

<p>There is an undirected connected tree with <code>n</code> nodes labeled from <code>0</code> to <code>n - 1</code> and <code>n - 1</code> edges.</p>

<p>You are given the integer <code>n</code> and the array <code>edges</code> where <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> indicates that there is an edge between nodes <code>a<sub>i</sub></code> and <code>b<sub>i</sub></code> in the tree.</p>

<p>Return an array <code>answer</code> of length <code>n</code> where <code>answer[i]</code> is the sum of the distances between the <code>i<sup>th</sup></code> node in the tree and all other nodes.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/23/lc-sumdist1.jpg" style="width: 304px; height: 224px;" />
<pre>
<strong>Input:</strong> n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
<strong>Output:</strong> [8,12,6,10,10,10]
<strong>Explanation:</strong> The tree is shown above.
We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
equals 1 + 1 + 2 + 2 + 2 = 8.
Hence, answer[0] = 8, and so on.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/23/lc-sumdist2.jpg" style="width: 64px; height: 65px;" />
<pre>
<strong>Input:</strong> n = 1, edges = []
<strong>Output:</strong> [0]
</pre>

<p><strong class="example">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/23/lc-sumdist3.jpg" style="width: 144px; height: 145px;" />
<pre>
<strong>Input:</strong> n = 2, edges = [[1,0]]
<strong>Output:</strong> [1,1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li>The given input represents a valid tree.</li>
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
  vector<int> dp, children, answer;
  vector<vector<int>> neighbors;
  
  void init(int N, vector<vector<int>>& edges) {
    dp.resize(N);
    children.resize(N, 1);
    answer.resize(N);
    neighbors.resize(N);
    
    for(auto &edge : edges) {
      neighbors[edge[0]].push_back(edge[1]);
      neighbors[edge[1]].push_back(edge[0]);
    }
  }
  
  void initDP(int current, int parent) {
    for(auto neighbor : neighbors[current]) {
      if(neighbor == parent) continue;
      
      initDP(neighbor, current);
      children[current] += children[neighbor];
      dp[current] += children[neighbor] + dp[neighbor];
    }
  }
  
  void swapRootDP(int current, int parent) {
    answer[current] = dp[current];
    
    for(auto neighbor : neighbors[current]) {
      if(neighbor == parent) continue;
      
      dp[current] -= children[neighbor] + dp[neighbor];
      children[current] -= children[neighbor];
      dp[neighbor] += dp[current] + children[current];
      children[neighbor] += children[current];
      
      swapRootDP(neighbor, current);
      dp[neighbor] -= dp[current] + children[current];
      children[neighbor] -= children[current];
      dp[current] += children[neighbor] + dp[neighbor];
      children[current] += children[neighbor];
    }
  }
public:
  vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
    init(N, edges);
    initDP(0, -1);
    swapRootDP(0, -1);
    return move(answer);
  }
};

// Accepted
// 73/73 cases passed (390 ms)
// Your runtime beats 11.33 % of cpp submissions
// Your memory usage beats 49.76 % of cpp submissions (87.4 MB)
```
