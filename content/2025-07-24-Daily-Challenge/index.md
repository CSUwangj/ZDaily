+++
updated = 2025-07-25T01:28:57+08:00
title = "2025-07-24 Daily Challenge"
path = "2025-07-24-Daily-Challenge"
date = 2025-07-25T01:28:57+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/minimum-score-after-removals-on-a-tree/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 24

## Description

**Minimum Score After Removals on a Tree**

<p>There is an undirected connected tree with <code>n</code> nodes labeled from <code>0</code> to <code>n - 1</code> and <code>n - 1</code> edges.</p>

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code> of length <code>n</code> where <code>nums[i]</code> represents the value of the <code>i<sup>th</sup></code> node. You are also given a 2D integer array <code>edges</code> of length <code>n - 1</code> where <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> indicates that there is an edge between nodes <code>a<sub>i</sub></code> and <code>b<sub>i</sub></code> in the tree.</p>

<p>Remove two <strong>distinct</strong> edges of the tree to form three connected components. For a pair of removed edges, the following steps are defined:</p>

<ol>
	<li>Get the XOR of all the values of the nodes for <strong>each</strong> of the three components respectively.</li>
	<li>The <strong>difference</strong> between the <strong>largest</strong> XOR value and the <strong>smallest</strong> XOR value is the <strong>score</strong> of the pair.</li>
</ol>

<ul>
	<li>For example, say the three components have the node values: <code>[4,5,7]</code>, <code>[1,9]</code>, and <code>[3,3,3]</code>. The three XOR values are <code>4 ^ 5 ^ 7 = <u><strong>6</strong></u></code>, <code>1 ^ 9 = <u><strong>8</strong></u></code>, and <code>3 ^ 3 ^ 3 = <u><strong>3</strong></u></code>. The largest XOR value is <code>8</code> and the smallest XOR value is <code>3</code>. The score is then <code>8 - 3 = 5</code>.</li>
</ul>

<p>Return <em>the <strong>minimum</strong> score of any possible pair of edge removals on the given tree</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/05/03/ex1drawio.png" style="width: 193px; height: 190px;" />
<pre>
<strong>Input:</strong> nums = [1,5,5,4,11], edges = [[0,1],[1,2],[1,3],[3,4]]
<strong>Output:</strong> 9
<strong>Explanation:</strong> The diagram above shows a way to make a pair of removals.
- The 1<sup>st</sup> component has nodes [1,3,4] with values [5,4,11]. Its XOR value is 5 ^ 4 ^ 11 = 10.
- The 2<sup>nd</sup> component has node [0] with value [1]. Its XOR value is 1 = 1.
- The 3<sup>rd</sup> component has node [2] with value [5]. Its XOR value is 5 = 5.
The score is the difference between the largest and smallest XOR value which is 10 - 1 = 9.
It can be shown that no other pair of removals will obtain a smaller score than 9.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/05/03/ex2drawio.png" style="width: 287px; height: 150px;" />
<pre>
<strong>Input:</strong> nums = [5,5,2,4,4,2], edges = [[0,1],[1,2],[5,2],[4,3],[1,3]]
<strong>Output:</strong> 0
<strong>Explanation:</strong> The diagram above shows a way to make a pair of removals.
- The 1<sup>st</sup> component has nodes [3,4] with values [4,4]. Its XOR value is 4 ^ 4 = 0.
- The 2<sup>nd</sup> component has nodes [1,0] with values [5,5]. Its XOR value is 5 ^ 5 = 0.
- The 3<sup>rd</sup> component has nodes [2,5] with values [2,2]. Its XOR value is 2 ^ 2 = 0.
The score is the difference between the largest and smallest XOR value which is 0 - 0 = 0.
We cannot obtain a smaller score than 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>3 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>8</sup></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li><code>edges</code> represents a valid tree.</li>
</ul>


## Solution

``` cpp
class Solution {
  void dfs(
    int current,
    int parent,
    const vector<int> &nums,
    const vector<vector<int>> &neighbors,
    vector<unordered_set<int>> &children,
    vector<int> &xorValue
  ) {
    xorValue[current] ^= nums[current];
    children[current].insert(current);

    for(auto next : neighbors[current]) {
      if(next == parent) continue;
      dfs(next, current, nums, neighbors, children, xorValue);
      xorValue[current] ^= xorValue[next];
      children[current].insert(children[next].begin(), children[next].end());
    }
  }
public:
  int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
    int n = nums.size();
    vector<vector<int>> neighbors(n);
    for(auto &e : edges) {
      neighbors[e[0]].push_back(e[1]);
      neighbors[e[1]].push_back(e[0]);
    }

    vector<unordered_set<int>> children(n);
    vector<int> xorValue(n);
    dfs(0, -1, nums, neighbors, children, xorValue);
    // cout << xorValue << endl;

    int totalXor = xorValue[0];
    int answer = INT_MAX;
    for(int i = 1; i < n - 1; ++i) {
      for(int j = i + 1; j < n; ++j) {
        int v1, v2, v3;
        int xorI = xorValue[i];
        int xorJ = xorValue[j];

        if(children[i].count(j)) {
          v1 = xorJ;
          v2 = xorI ^ xorJ;
          v3 = totalXor ^ xorI;
        } else if(children[j].count(i)) {
          v1 = xorI;
          v2 = xorI ^ xorJ;
          v3 = totalXor ^ xorJ;
        } else {
          v1 = xorI;
          v2 = xorJ;
          v3 = totalXor ^ xorI ^ xorJ;
        }

        answer = min(answer, max({v1, v2, v3}) - min({v1, v2, v3}));
      }
    }

    return answer;
  }
};

// Accepted
// 65/65 cases passed (612 ms)
// Your runtime beats 27.77 % of cpp submissions
// Your memory usage beats 18.25 % of cpp submissions (125.7 MB)
```
