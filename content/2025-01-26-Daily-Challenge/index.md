+++
updated = 2025-01-26T22:54:09+08:00
title = "2025-01-26 Daily Challenge"
path = "2025-01-26-Daily-Challenge"
date = 2025-01-26T22:54:09+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 26

## Description

**Maximum Employees to Be Invited to a Meeting**

<p>A company is organizing a meeting and has a list of <code>n</code> employees, waiting to be invited. They have arranged for a large <strong>circular</strong> table, capable of seating <strong>any number</strong> of employees.</p>

<p>The employees are numbered from <code>0</code> to <code>n - 1</code>. Each employee has a <strong>favorite</strong> person and they will attend the meeting <strong>only if</strong> they can sit next to their favorite person at the table. The favorite person of an employee is <strong>not</strong> themself.</p>

<p>Given a <strong>0-indexed</strong> integer array <code>favorite</code>, where <code>favorite[i]</code> denotes the favorite person of the <code>i<sup>th</sup></code> employee, return <em>the <strong>maximum number of employees</strong> that can be invited to the meeting</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/12/14/ex1.png" style="width: 236px; height: 195px;" />
<pre>
<strong>Input:</strong> favorite = [2,2,1,2]
<strong>Output:</strong> 3
<strong>Explanation:</strong>
The above figure shows how the company can invite employees 0, 1, and 2, and seat them at the round table.
All employees cannot be invited because employee 2 cannot sit beside employees 0, 1, and 3, simultaneously.
Note that the company can also invite employees 1, 2, and 3, and give them their desired seats.
The maximum number of employees that can be invited to the meeting is 3. 
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> favorite = [1,2,0]
<strong>Output:</strong> 3
<strong>Explanation:</strong> 
Each employee is the favorite person of at least one other employee, and the only way the company can invite them is if they invite every employee.
The seating arrangement will be the same as that in the figure given in example 1:
- Employee 0 will sit between employees 2 and 1.
- Employee 1 will sit between employees 0 and 2.
- Employee 2 will sit between employees 1 and 0.
The maximum number of employees that can be invited to the meeting is 3.
</pre>

<p><strong class="example">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/12/14/ex2.png" style="width: 219px; height: 220px;" />
<pre>
<strong>Input:</strong> favorite = [3,0,1,4,1]
<strong>Output:</strong> 4
<strong>Explanation:</strong>
The above figure shows how the company will invite employees 0, 1, 3, and 4, and seat them at the round table.
Employee 2 cannot be invited because the two spots next to their favorite employee 1 are taken.
So the company leaves them out of the meeting.
The maximum number of employees that can be invited to the meeting is 4.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == favorite.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= favorite[i] &lt;=&nbsp;n - 1</code></li>
	<li><code>favorite[i] != i</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int maximumInvitations(vector<int>& favorite) {
    int n = favorite.size();
    vector<int> degree(n);
    vector<int> chain(n);
    vector<bool> visited(n);

    for(auto f : favorite) {
      degree[f] += 1;
    }

    queue<int> q;
    for(int i = 0; i < n; ++i) {
      if(!degree[i]) q.push(i);
    }

    while(q.size()) {
      auto current = q.front();
      q.pop();
      visited[current] = true;
      
      int next = favorite[current];
      chain[next] = chain[current] + 1;
      degree[next] -= 1;
      if(!degree[next]) q.push(next);
    }

    int longestCycle = 0;
    int totalChains = 0;
    for(int i = 0; i < n; ++i) {
      if(!visited[i]) {
        int current = i;
        int len = 0;
        while(!visited[current]) {
          visited[current] = true;
          current = favorite[current];
          len += 1;
        }

        if(len == 2) {
          totalChains += 2 + chain[i] + chain[favorite[i]];
        } else {
          longestCycle = max(longestCycle, len);
        }
      }
    }

    return max(longestCycle, totalChains);
  }
};

// Accepted
// 98/98 cases passed (21 ms)
// Your runtime beats 78.28 % of cpp submissions
// Your memory usage beats 78.28 % of cpp submissions (93.4 MB)
```
