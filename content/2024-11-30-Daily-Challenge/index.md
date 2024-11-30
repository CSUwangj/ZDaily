+++
updated = 2024-11-30T15:56:12+08:00
title = "2024-11-30 Daily Challenge"
path = "2024-11-30-Daily-Challenge"
date = 2024-11-30T15:56:12+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/valid-arrangement-of-pairs/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 30

## Description

**Valid Arrangement of Pairs**

<p>You are given a <strong>0-indexed</strong> 2D integer array <code>pairs</code> where <code>pairs[i] = [start<sub>i</sub>, end<sub>i</sub>]</code>. An arrangement of <code>pairs</code> is <strong>valid</strong> if for every index <code>i</code> where <code>1 &lt;= i &lt; pairs.length</code>, we have <code>end<sub>i-1</sub> == start<sub>i</sub></code>.</p>

<p>Return <em><strong>any</strong> valid arrangement of </em><code>pairs</code>.</p>

<p><strong>Note:</strong> The inputs will be generated such that there exists a valid arrangement of <code>pairs</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> pairs = [[5,1],[4,5],[11,9],[9,4]]
<strong>Output:</strong> [[11,9],[9,4],[4,5],[5,1]]
<strong>Explanation:
</strong>This is a valid arrangement since end<sub>i-1</sub> always equals start<sub>i</sub>.
end<sub>0</sub> = 9 == 9 = start<sub>1</sub> 
end<sub>1</sub> = 4 == 4 = start<sub>2</sub>
end<sub>2</sub> = 5 == 5 = start<sub>3</sub>
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> pairs = [[1,3],[3,2],[2,1]]
<strong>Output:</strong> [[1,3],[3,2],[2,1]]
<strong>Explanation:</strong>
This is a valid arrangement since end<sub>i-1</sub> always equals start<sub>i</sub>.
end<sub>0</sub> = 3 == 3 = start<sub>1</sub>
end<sub>1</sub> = 2 == 2 = start<sub>2</sub>
The arrangements [[2,1],[1,3],[3,2]] and [[3,2],[2,1],[1,3]] are also valid.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> pairs = [[1,2],[1,3],[2,1]]
<strong>Output:</strong> [[1,2],[2,1],[1,3]]
<strong>Explanation:</strong>
This is a valid arrangement since end<sub>i-1</sub> always equals start<sub>i</sub>.
end<sub>0</sub> = 2 == 2 = start<sub>1</sub>
end<sub>1</sub> = 1 == 1 = start<sub>2</sub>
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= pairs.length &lt;= 10<sup>5</sup></code></li>
	<li><code>pairs[i].length == 2</code></li>
	<li><code>0 &lt;= start<sub>i</sub>, end<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
	<li><code>start<sub>i</sub> != end<sub>i</sub></code></li>
	<li>No two pairs are exactly the same.</li>
	<li>There <strong>exists</strong> a valid arrangement of <code>pairs</code>.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
    int sz = pairs.size();
    map<int, vector<int>> neighbors;
    map<int, int> degree;

    for(const auto &p : pairs) {
      neighbors[p[0]].push_back(p[1]);
      degree[p[0]] += 1;
      degree[p[1]] -= 1;
    }

    int current = neighbors.begin()->first;
    for(const auto &[p, d] : degree) {
      if(d == 1) current = p;
    }
    vector<int> path;
    vector<int> st = {current};
    while(st.size()) {
      int current = st.back();
      if(neighbors[current].empty()) {
        path.push_back(current);
        st.pop_back();
      } else {
        int next = neighbors[current].back();
        neighbors[current].pop_back();
        st.push_back(next);
      }
    }

    vector<vector<int>> answer;
    reverse(path.begin(), path.end());
    for(int i = 0; i < sz; ++i) {
      answer.push_back({path[i], path[i + 1]});
    }
    return answer;
  }
};
```
