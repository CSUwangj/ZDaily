+++
updated = 2023-08-01T11:29:44+08:00
title = "2023-08-01 Daily Challenge"
path = "2023-08-01-Daily-Challenge"
date = 2023-08-01T11:29:44+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/combinations/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 1

## Description

**Combinations**

<p>Given two integers <code>n</code> and <code>k</code>, return <em>all possible combinations of</em> <code>k</code> <em>numbers chosen from the range</em> <code>[1, n]</code>.</p>

<p>You may return the answer in <strong>any order</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 4, k = 2
<strong>Output:</strong> [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
<strong>Explanation:</strong> There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 1, k = 1
<strong>Output:</strong> [[1]]
<strong>Explanation:</strong> There is 1 choose 1 = 1 total combination.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 20</code></li>
	<li><code>1 &lt;= k &lt;= n</code></li>
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
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> answer;
    for(int mask = (1 << k) - 1; mask < (1 << n); mask = (mask + (mask & -mask)) | ((mask & ~(mask + (mask & -mask))) / (mask & -mask) >> 1)) {
      vector<int> result;
      for(int i = 0; i < n; ++i) {
        if(mask & (1 << i)) {
          result.push_back(i + 1);
        }
      }
      answer.push_back(result);
    }
    return answer;
  }
};

// Accepted
// 27/27 cases passed (11 ms)
// Your runtime beats 95.34 % of cpp submissions
// Your memory usage beats 40.55 % of cpp submissions (10.6 MB)
```
