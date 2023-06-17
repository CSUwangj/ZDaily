+++
updated = 2023-06-17T16:53:07+08:00
title = "2023-06-17 Daily Challenge"
path = "2023-06-17-Daily-Challenge"
date = 2023-06-17T16:53:07+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/make-array-strictly-increasing/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 17

## Description

**Make Array Strictly Increasing**

<p>Given two integer arrays&nbsp;<code>arr1</code> and <code>arr2</code>, return the minimum number of operations (possibly zero) needed&nbsp;to make <code>arr1</code> strictly increasing.</p>

<p>In one operation, you can choose two indices&nbsp;<code>0 &lt;=&nbsp;i &lt; arr1.length</code>&nbsp;and&nbsp;<code>0 &lt;= j &lt; arr2.length</code>&nbsp;and do the assignment&nbsp;<code>arr1[i] = arr2[j]</code>.</p>

<p>If there is no way to make&nbsp;<code>arr1</code>&nbsp;strictly increasing,&nbsp;return&nbsp;<code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
<strong>Output:</strong> 1
<strong>Explanation:</strong> Replace <code>5</code> with <code>2</code>, then <code>arr1 = [1, 2, 3, 6, 7]</code>.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> arr1 = [1,5,3,6,7], arr2 = [4,3,1]
<strong>Output:</strong> 2
<strong>Explanation:</strong> Replace <code>5</code> with <code>3</code> and then replace <code>3</code> with <code>4</code>. <code>arr1 = [1, 3, 4, 6, 7]</code>.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> arr1 = [1,5,3,6,7], arr2 = [1,6,3,3]
<strong>Output:</strong> -1
<strong>Explanation:</strong> You can&#39;t make <code>arr1</code> strictly increasing.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr1.length, arr2.length &lt;= 2000</code></li>
	<li><code>0 &lt;= arr1[i], arr2[i] &lt;= 10^9</code></li>
</ul>

<p>&nbsp;</p>

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
    int pos,
    int left,
    const vector<int> &arr1,
    const vector<int> &arr2,
    vector<map<int, int>> &dp
  ) {
    if(pos == arr1.size()) return 0;

    if(dp[pos].count(left)) return dp[pos][left];

    int exclude = INT_MAX;
    int include = INT_MAX;

    if(arr1[pos] > left) {
      exclude = solve(pos + 1, arr1[pos], arr1, arr2, dp);
    }
    int replace = upper_bound(arr2.begin(), arr2.end(), left) - arr2.begin();
    if(replace != arr2.size()) {
      include = solve(pos + 1, arr2[replace], arr1, arr2, dp);
    }
    if(include == INT_MAX) {
      dp[pos][left] = exclude;
    } else {
      dp[pos][left] = min(exclude, include + 1);
    }
    return dp[pos][left];
  }
public:
  int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
    sort(arr2.begin(), arr2.end());
    vector<map<int, int>> dp(2001);

    int result = solve(0, INT_MIN, arr1, arr2, dp);
    if(result == INT_MAX) return -1;
    return result;
  }
};

// Accepted
// 21/21 cases passed (897 ms)
// Your runtime beats 12.21 % of cpp submissions
// Your memory usage beats 11.05 % of cpp submissions (80.1 MB)
```
