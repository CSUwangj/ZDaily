+++
updated = 2023-08-20T18:01:15+08:00
title = "2023-08-20 Daily Challenge"
path = "2023-08-20-Daily-Challenge"
date = 2023-08-20T18:01:15+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 20

## Description

**Sort Items by Groups Respecting Dependencies**

<p>There are&nbsp;<code>n</code>&nbsp;items each&nbsp;belonging to zero or one of&nbsp;<code>m</code>&nbsp;groups where <code>group[i]</code>&nbsp;is the group that the <code>i</code>-th item belongs to and it&#39;s equal to <code>-1</code>&nbsp;if the <code>i</code>-th item belongs to no group. The items and the groups are zero indexed. A group can have no item belonging to it.</p>

<p>Return a sorted list of the items such that:</p>

<ul>
	<li>The items that belong to the same group are next to each other in the sorted list.</li>
	<li>There are some&nbsp;relations&nbsp;between these items where&nbsp;<code>beforeItems[i]</code>&nbsp;is a list containing all the items that should come before the&nbsp;<code>i</code>-th item in the sorted array (to the left of the&nbsp;<code>i</code>-th item).</li>
</ul>

<p>Return any solution if there is more than one solution and return an <strong>empty list</strong>&nbsp;if there is no solution.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/09/11/1359_ex1.png" style="width: 191px; height: 181px;" /></strong></p>

<pre>
<strong>Input:</strong> n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3,6],[],[],[]]
<strong>Output:</strong> [6,3,4,1,5,2,0,7]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3],[],[4],[]]
<strong>Output:</strong> []
<strong>Explanation:</strong>&nbsp;This is the same as example 1 except that 4 needs to be before 6 in the sorted list.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= m &lt;= n &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>group.length == beforeItems.length == n</code></li>
	<li><code>-1 &lt;= group[i] &lt;= m - 1</code></li>
	<li><code>0 &lt;= beforeItems[i].length &lt;= n - 1</code></li>
	<li><code>0 &lt;= beforeItems[i][j] &lt;= n - 1</code></li>
	<li><code>i != beforeItems[i][j]</code></li>
	<li><code>beforeItems[i]&nbsp;</code>does not contain&nbsp;duplicates elements.</li>
</ul>


## Solution

``` cpp
class Solution {
  int groupDegree[30000] = {};
  int degree[30000] = {};
  vector<int> children[30000];
  vector<int> groupChildren[30000];
  vector<int> items[30000];
public:
  vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
    // init
    for(int i = 0; i < n; ++i) {
      if(group[i] == -1) group[i] = m++;
      items[group[i]].push_back(i);
    }
    for(int i = 0; i < n; ++i) {
      for(auto p : beforeItems[i]) {
        children[p].push_back(i);
        degree[i] += 1;
        if(group[p] != group[i]) {
          groupDegree[group[i]] += 1;
          groupChildren[group[p]].push_back(group[i]);
        }
      }
    }

    // topological sort for group
    vector<int> groupOrder;
    queue<int> q;
    for(int i = 0; i < m; ++i) {
      if(!groupDegree[i]) q.push(i);
    }
    while(q.size()) {
      int cur = q.front();
      q.pop();
      groupOrder.push_back(cur);
      for(auto c : groupChildren[cur]) {
        groupDegree[c] -= 1;
        if(!groupDegree[c]) q.push(c);
      }
    }
    // cout << groupOrder << endl;
    if(groupOrder.size() != m) return {};

    // sort items
    vector<int> answer;
    for(auto g : groupOrder) {
      int sz = answer.size();
      for(auto item : items[g]) {
        if(!degree[item]) q.push(item);
      }
      while(q.size()) {
        int cur = q.front();
        q.pop();
        answer.push_back(cur);
        for(auto c : children[cur]) {
          degree[c] -= 1;
          if(group[c] == group[cur] && !degree[c]) {
            q.push(c);
          }
        }
      }
      if(answer.size() - sz != items[g].size()) return {};
    }

    return answer;
  }
};

// Accepted
// 17/17 cases passed (80 ms)
// Your runtime beats 90.12 % of cpp submissions
// Your memory usage beats 88.95 % of cpp submissions (41.8 MB)
```
