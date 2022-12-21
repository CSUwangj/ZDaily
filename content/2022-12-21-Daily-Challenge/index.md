+++
updated = 2022-12-21T13:31:03+08:00
title = "2022-12-21 Daily Challenge"
path = "2022-12-21-Daily-Challenge"
date = 2022-12-21T13:31:03+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/possible-bipartition/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 21

## Description

**Possible Bipartition**

<p>We want to split a group of <code>n</code> people (labeled from <code>1</code> to <code>n</code>) into two groups of <strong>any size</strong>. Each person may dislike some other people, and they should not go into the same group.</p>

<p>Given the integer <code>n</code> and the array <code>dislikes</code> where <code>dislikes[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> indicates that the person labeled <code>a<sub>i</sub></code> does not like the person labeled <code>b<sub>i</sub></code>, return <code>true</code> <em>if it is possible to split everyone into two groups in this way</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 4, dislikes = [[1,2],[1,3],[2,4]]
<strong>Output:</strong> true
<strong>Explanation:</strong> group1 [1,4] and group2 [2,3].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 3, dislikes = [[1,2],[1,3],[2,3]]
<strong>Output:</strong> false
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> n = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2000</code></li>
	<li><code>0 &lt;= dislikes.length &lt;= 10<sup>4</sup></code></li>
	<li><code>dislikes[i].length == 2</code></li>
	<li><code>1 &lt;= dislikes[i][j] &lt;= n</code></li>
	<li><code>a<sub>i</sub> &lt; b<sub>i</sub></code></li>
	<li>All the pairs of <code>dislikes</code> are <strong>unique</strong>.</li>
</ul>


## Solution

``` cpp
class Solution {
  vector<vector<int>> dislike;
public:
  bool possibleBipartition(int N, vector<vector<int>>& dislikePairs) {
    dislike.resize(N+1);
    
    for(auto &pair : dislikePairs) {
      dislike[pair[0]].push_back(pair[1]);
      dislike[pair[1]].push_back(pair[0]);
    }
    
    vector<int> group(N+1, -1);
    while(true) {
      queue<int> q;
      for(int i = 1; i <= N; ++i) {
        if(group[i] == -1) {
          q.push(i);
          group[i] = 0;
          break;
        }
      }
      if(q.empty()) break;
      while(!q.empty()) {
        int current = q.front();
        q.pop();
        for(auto dis : dislike[current]) {
          if(group[dis] != -1 && group[dis] == group[current]) return false;
          if(group[dis] == -1) q.push(dis);
          group[dis] = group[current] ^ 1;
        }
      }
    }
    return true;
  }
};

// Accepted
// 70/70 cases passed (472 ms)
// Your runtime beats 40.43 % of cpp submissions
// Your memory usage beats 75.45 % of cpp submissions (64.7 MB)
```
