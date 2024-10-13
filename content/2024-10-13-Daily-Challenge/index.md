+++
updated = 2024-10-13T08:12:34+08:00
title = "2024-10-13 Daily Challenge"
path = "2024-10-13-Daily-Challenge"
date = 2024-10-13T08:12:34+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 13

## Description

**Smallest Range Covering Elements from K Lists**

<p>You have <code>k</code> lists of sorted integers in <strong>non-decreasing&nbsp;order</strong>. Find the <b>smallest</b> range that includes at least one number from each of the <code>k</code> lists.</p>

<p>We define the range <code>[a, b]</code> is smaller than range <code>[c, d]</code> if <code>b - a &lt; d - c</code> <strong>or</strong> <code>a &lt; c</code> if <code>b - a == d - c</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
<strong>Output:</strong> [20,24]
<strong>Explanation: </strong>
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [[1,2,3],[1,2,3],[1,2,3]]
<strong>Output:</strong> [1,1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>nums.length == k</code></li>
	<li><code>1 &lt;= k &lt;= 3500</code></li>
	<li><code>1 &lt;= nums[i].length &lt;= 50</code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i][j] &lt;= 10<sup>5</sup></code></li>
	<li><code>nums[i]</code>&nbsp;is sorted in <strong>non-decreasing</strong> order.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  vector<int> smallestRange(vector<vector<int>>& nums) {
    using ti = tuple<int, int, int>;
    priority_queue<ti, vector<ti>, greater<ti>> pq;
    vector<int> current{INT_MAX, INT_MIN};
    int range = -1;
    for(int i = 0; i < nums.size(); ++i) {
      current[0] = min(current[0], nums[i][0]);
      current[1] = max(current[1], nums[i][0]);
      pq.push({nums[i][0], i, 0});
    }
    range = current[1] - current[0];
    if(!range) return current;
    vector<int> answer = current;
    while(pq.size() == nums.size()) {
      auto [num, indexList, index] = pq.top();
      pq.pop();
      if(nums[indexList].size() == index + 1) break;
      int newNum = nums[indexList][index + 1];
      pq.push({newNum, indexList, index + 1});
      if(newNum > current[1]) {
        current[1] = newNum;
      }
      current[0] = max(current[0], get<0>(pq.top()));
      if(current[1] - current[0] < range) {
        answer = current;
        range = current[1] - current[0];
      }
    }
    return answer;
  }
};
```
