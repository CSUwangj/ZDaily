+++
updated = 2023-01-04T12:04:17+08:00
title = "2023-01-04 Daily Challenge"
path = "2023-01-04-Daily-Challenge"
date = 2023-01-04T12:04:17+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 4

## Description

**Minimum Rounds to Complete All Tasks**

<p>You are given a <strong>0-indexed</strong> integer array <code>tasks</code>, where <code>tasks[i]</code> represents the difficulty level of a task. In each round, you can complete either 2 or 3 tasks of the <strong>same difficulty level</strong>.</p>

<p>Return <em>the <strong>minimum</strong> rounds required to complete all the tasks, or </em><code>-1</code><em> if it is not possible to complete all the tasks.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> tasks = [2,2,3,3,2,4,4,4,4,4]
<strong>Output:</strong> 4
<strong>Explanation:</strong> To complete all the tasks, a possible plan is:
- In the first round, you complete 3 tasks of difficulty level 2. 
- In the second round, you complete 2 tasks of difficulty level 3. 
- In the third round, you complete 3 tasks of difficulty level 4. 
- In the fourth round, you complete 2 tasks of difficulty level 4.  
It can be shown that all the tasks cannot be completed in fewer than 4 rounds, so the answer is 4.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> tasks = [2,3,3]
<strong>Output:</strong> -1
<strong>Explanation:</strong> There is only 1 task of difficulty level 2, but in each round, you can only complete either 2 or 3 tasks of the same difficulty level. Hence, you cannot complete all the tasks, and the answer is -1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= tasks.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= tasks[i] &lt;= 10<sup>9</sup></code></li>
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
public:
  int minimumRounds(vector<int>& tasks) {
    map<int, int> count;
    for(auto task : tasks) {
      count[task] += 1;
    }
    int answer = 0;
    for(const auto &[_, c] : count) {
      if(c == 1) return -1;
      int result = INT_MAX;
      if(c % 2 == 0) {
        result = c / 2;
      }
      if((c - 4 > 0 && (c - 4) % 3 == 0) || (c - 2 > 0 && (c - 2) % 3 == 0)) {
        result = c / 3 + 1;
      }
      if(c % 3 == 0) {
        result = c / 3;
      }
      answer += result;
    }
    return answer;
  }
};

// Accepted
// 79/79 cases passed (276 ms)
// Your runtime beats 66.53 % of cpp submissions
// Your memory usage beats 23.86 % of cpp submissions (104.7 MB)
```
