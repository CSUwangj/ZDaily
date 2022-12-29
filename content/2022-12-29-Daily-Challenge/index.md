+++
updated = 2022-12-29T14:29:21+08:00
title = "2022-12-29 Daily Challenge"
path = "2022-12-29-Daily-Challenge"
date = 2022-12-29T14:29:21+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/single-threaded-cpu/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 29

## Description

**Single-Threaded CPU**

<p>You are given <code>n</code>​​​​​​ tasks labeled from <code>0</code> to <code>n - 1</code> represented by a 2D integer array <code>tasks</code>, where <code>tasks[i] = [enqueueTime<sub>i</sub>, processingTime<sub>i</sub>]</code> means that the <code>i<sup>​​​​​​th</sup></code>​​​​ task will be available to process at <code>enqueueTime<sub>i</sub></code> and will take <code>processingTime<sub>i</sub></code><sub> </sub>to finish processing.</p>

<p>You have a single-threaded CPU that can process <strong>at most one</strong> task at a time and will act in the following way:</p>

<ul>
	<li>If the CPU is idle and there are no available tasks to process, the CPU remains idle.</li>
	<li>If the CPU is idle and there are available tasks, the CPU will choose the one with the <strong>shortest processing time</strong>. If multiple tasks have the same shortest processing time, it will choose the task with the smallest index.</li>
	<li>Once a task is started, the CPU will <strong>process the entire task</strong> without stopping.</li>
	<li>The CPU can finish a task then start a new one instantly.</li>
</ul>

<p>Return <em>the order in which the CPU will process the tasks.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> tasks = [[1,2],[2,4],[3,2],[4,1]]
<strong>Output:</strong> [0,2,3,1]
<strong>Explanation: </strong>The events go as follows: 
- At time = 1, task 0 is available to process. Available tasks = {0}.
- Also at time = 1, the idle CPU starts processing task 0. Available tasks = {}.
- At time = 2, task 1 is available to process. Available tasks = {1}.
- At time = 3, task 2 is available to process. Available tasks = {1, 2}.
- Also at time = 3, the CPU finishes task 0 and starts processing task 2 as it is the shortest. Available tasks = {1}.
- At time = 4, task 3 is available to process. Available tasks = {1, 3}.
- At time = 5, the CPU finishes task 2 and starts processing task 3 as it is the shortest. Available tasks = {1}.
- At time = 6, the CPU finishes task 3 and starts processing task 1. Available tasks = {}.
- At time = 10, the CPU finishes task 1 and becomes idle.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> tasks = [[7,10],[7,12],[7,5],[7,4],[7,2]]
<strong>Output:</strong> [4,3,2,0,1]
<strong>Explanation</strong><strong>: </strong>The events go as follows:
- At time = 7, all the tasks become available. Available tasks = {0,1,2,3,4}.
- Also at time = 7, the idle CPU starts processing task 4. Available tasks = {0,1,2,3}.
- At time = 9, the CPU finishes task 4 and starts processing task 3. Available tasks = {0,1,2}.
- At time = 13, the CPU finishes task 3 and starts processing task 2. Available tasks = {0,1}.
- At time = 18, the CPU finishes task 2 and starts processing task 0. Available tasks = {1}.
- At time = 28, the CPU finishes task 0 and starts processing task 1. Available tasks = {}.
- At time = 40, the CPU finishes task 1 and becomes idle.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>tasks.length == n</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= enqueueTime<sub>i</sub>, processingTime<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
  using pi = pair<int, int>;
public:
  vector<int> getOrder(vector<vector<int>>& tasks) {
    int len = tasks.size();
    vector<int> indice(len);
    for(int i = 0; i < len; ++i) {
      indice[i] = i;
    }
    sort(indice.begin(), indice.end(), [&](int a, int b) {
      return tasks[a] < tasks[b];
    });
    vector<int> answer;
    answer.reserve(len);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    unsigned int current = 0;
    int pos = 0;
    while(pos < len) {
      if(pq.size()) {
        auto [processing, index] = pq.top();
        pq.pop();
        current = max<unsigned int>(current, tasks[index][0]) + processing;
        answer.push_back(index);
      }
      if(current < tasks[indice[pos]][0] && pq.empty()) {
        pq.push({tasks[indice[pos]][1], indice[pos]});
        pos += 1;
        continue;
      }
      while(pos < len && current >= tasks[indice[pos]][0]) {
        pq.push({tasks[indice[pos]][1], indice[pos]});
        pos += 1;
      }
    }
    while(pq.size()) {
      auto [_processing, index] = pq.top();
      pq.pop();
      answer.push_back(index);
    }
    return answer;
  }
};

// Accepted
// 39/39 cases passed (596 ms)
// Your runtime beats 94.18 % of cpp submissions
// Your memory usage beats 97.88 % of cpp submissions (114.8 MB)
```
