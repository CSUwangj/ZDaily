+++
updated = 2024-08-13T15:54:48+08:00
title = "2024-08-13 Daily Challenge"
path = "2024-08-13-Daily-Challenge"
date = 2024-08-13T15:54:48+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/combination-sum-ii/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 13

## Description

**Combination Sum II**

<p>Given a collection of candidate numbers (<code>candidates</code>) and a target number (<code>target</code>), find all unique combinations in <code>candidates</code>&nbsp;where the candidate numbers sum to <code>target</code>.</p>

<p>Each number in <code>candidates</code>&nbsp;may only be used <strong>once</strong> in the combination.</p>

<p><strong>Note:</strong>&nbsp;The solution set must not contain duplicate combinations.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> candidates = [10,1,2,7,6,1,5], target = 8
<strong>Output:</strong> 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> candidates = [2,5,2,1,2], target = 5
<strong>Output:</strong> 
[
[1,2,2],
[5]
]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;=&nbsp;candidates.length &lt;= 100</code></li>
	<li><code>1 &lt;=&nbsp;candidates[i] &lt;= 50</code></li>
	<li><code>1 &lt;= target &lt;= 30</code></li>
</ul>


## Solution

``` cpp
class Solution {
  int len;
  void dfs(
    vector<vector<int>> &answer,
    vector<int> &cur,
    vector<int> &candidates,
    int rest,
    int index
  ) {
    if(!rest) {
      answer.push_back(cur);
      return;
    }
    if(index == len) return;
    for(int i = index; i < len; ++i) {
      if(i > index && candidates[i] == candidates[i - 1]) continue;
      if(candidates[i] <= rest) {
        cur.push_back(candidates[i]);
        dfs(answer, cur, candidates, rest - candidates[i], i + 1);
        cur.pop_back();
      }
    }
  }
public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    len = candidates.size();
    sort(candidates.rbegin(), candidates.rend());
    vector<vector<int>> answer;
    vector<int> tmp;
    dfs(answer, tmp, candidates, target, 0);
    sort(answer.begin(), answer.end());
    answer.resize(unique(answer.begin(), answer.end()) - answer.begin());
    return answer;
  }
};
```
