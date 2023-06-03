+++
updated = 2023-06-03T12:14:59+08:00
title = "2023-06-03 Daily Challenge"
path = "2023-06-03-Daily-Challenge"
date = 2023-06-03T12:14:59+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/time-needed-to-inform-all-employees/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 3

## Description

**Time Needed to Inform All Employees**

<p>A company has <code>n</code> employees with a unique ID for each employee from <code>0</code> to <code>n - 1</code>. The head of the company is the one with <code>headID</code>.</p>

<p>Each employee has one direct manager given in the <code>manager</code> array where <code>manager[i]</code> is the direct manager of the <code>i-th</code> employee, <code>manager[headID] = -1</code>. Also, it is guaranteed that the subordination relationships have a tree structure.</p>

<p>The head of the company wants to inform all the company employees of an urgent piece of news. He will inform his direct subordinates, and they will inform their subordinates, and so on until all employees know about the urgent news.</p>

<p>The <code>i-th</code> employee needs <code>informTime[i]</code> minutes to inform all of his direct subordinates (i.e., After informTime[i] minutes, all his direct subordinates can start spreading the news).</p>

<p>Return <em>the number of minutes</em> needed to inform all the employees about the urgent news.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 1, headID = 0, manager = [-1], informTime = [0]
<strong>Output:</strong> 0
<strong>Explanation:</strong> The head of the company is the only employee in the company.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/02/27/graph.png" style="width: 404px; height: 174px;" />
<pre>
<strong>Input:</strong> n = 6, headID = 2, manager = [2,2,-1,2,2,2], informTime = [0,0,1,0,0,0]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The head of the company with id = 2 is the direct manager of all the employees in the company and needs 1 minute to inform them all.
The tree structure of the employees in the company is shown.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= headID &lt; n</code></li>
	<li><code>manager.length == n</code></li>
	<li><code>0 &lt;= manager[i] &lt; n</code></li>
	<li><code>manager[headID] == -1</code></li>
	<li><code>informTime.length == n</code></li>
	<li><code>0 &lt;= informTime[i] &lt;= 1000</code></li>
	<li><code>informTime[i] == 0</code> if employee <code>i</code> has no subordinates.</li>
	<li>It is <strong>guaranteed</strong> that all the employees can be informed.</li>
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
  int solve(
    int current,
    const vector<vector<int>> &subordinates,
    const vector<int>& informTime
  ) {
    int subResult = 0;
    for(auto subordinate : subordinates[current]) {
      subResult = max(subResult, solve(subordinate, subordinates, informTime));
    }

    return informTime[current] + subResult;
  }
public:
  int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
    if(n == 1) return 0;
    vector<vector<int>> subordinates(n);
    for(int i = 0; i < n; ++i) {
      if(manager[i] == -1) continue;
      subordinates[manager[i]].push_back(i);
    }

    int answer = 0;
    return solve(headID, subordinates, informTime);
  }
};

// Accepted
// 39/39 cases passed (260 ms)
// Your runtime beats 90.17 % of cpp submissions
// Your memory usage beats 59.75 % of cpp submissions (121.9 MB)
```
