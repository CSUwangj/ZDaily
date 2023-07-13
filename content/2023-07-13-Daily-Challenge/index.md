+++
updated = 2023-07-13T16:06:27+08:00
title = "2023-07-13 Daily Challenge"
path = "2023-07-13-Daily-Challenge"
date = 2023-07-13T16:06:27+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/course-schedule/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 13

## Description

**Course Schedule**

<p>There are a total of <code>numCourses</code> courses you have to take, labeled from <code>0</code> to <code>numCourses - 1</code>. You are given an array <code>prerequisites</code> where <code>prerequisites[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> indicates that you <strong>must</strong> take course <code>b<sub>i</sub></code> first if you want to take course <code>a<sub>i</sub></code>.</p>

<ul>
	<li>For example, the pair <code>[0, 1]</code>, indicates that to take course <code>0</code> you have to first take course <code>1</code>.</li>
</ul>

<p>Return <code>true</code> if you can finish all courses. Otherwise, return <code>false</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> numCourses = 2, prerequisites = [[1,0]]
<strong>Output:</strong> true
<strong>Explanation:</strong> There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> numCourses = 2, prerequisites = [[1,0],[0,1]]
<strong>Output:</strong> false
<strong>Explanation:</strong> There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= numCourses &lt;= 2000</code></li>
	<li><code>0 &lt;= prerequisites.length &lt;= 5000</code></li>
	<li><code>prerequisites[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; numCourses</code></li>
	<li>All the pairs prerequisites[i] are <strong>unique</strong>.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> degree(numCourses);
    vector<vector<int>> edges(numCourses);
    for(auto &edge : prerequisites) {
      edges[edge[0]].push_back(edge[1]);
      degree[edge[1]] += 1;
    }
    queue<int> q;
    int answer = 0;
    for(int i = 0; i < numCourses; ++i) {
      if(!degree[i]) {
        answer += 1;
        q.push(i);
      }
    }
    while(q.size()) {
      int cur = q.front();
      q.pop();
      for(auto nxt : edges[cur]) {
        degree[nxt] -= 1;
        if(!degree[nxt]) {
          answer += 1;
          q.push(nxt);
        }
      }
    }
    return answer == numCourses;
  }
};

// Accepted
// 52/52 cases passed (25 ms)
// Your runtime beats 62.83 % of cpp submissions
// Your memory usage beats 83.94 % of cpp submissions (13.2 MB)
```
