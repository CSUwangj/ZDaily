+++
updated = 2024-02-16T11:03:20+08:00
title = "2024-02-16 Daily Challenge"
path = "2024-02-16-Daily-Challenge"
date = 2024-02-16T11:03:20+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 16

## Description

**Least Number of Unique Integers after K Removals**

<p>Given an array of integers&nbsp;<code>arr</code>&nbsp;and an integer <code>k</code>.&nbsp;Find the <em>least number of unique integers</em>&nbsp;after removing <strong>exactly</strong> <code>k</code> elements<b>.</b></p>

<ol>
</ol>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input: </strong>arr = [5,5,4], k = 1
<strong>Output: </strong>1
<strong>Explanation</strong>: Remove the single 4, only 5 is left.
</pre>
<strong class="example">Example 2:</strong>

<pre>
<strong>Input: </strong>arr = [4,3,1,1,3,3,2], k = 3
<strong>Output: </strong>2
<strong>Explanation</strong>: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length&nbsp;&lt;= 10^5</code></li>
	<li><code>1 &lt;= arr[i] &lt;= 10^9</code></li>
	<li><code>0 &lt;= k&nbsp;&lt;= arr.length</code></li>
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
  int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
    map<int, int> count, ccount;
    for(auto i : arr) {
      count[i] += 1;
    }
    for(auto [_, c] : count) {
      ccount[c] += 1;
    }
    int answer = count.size();
    for(auto [count, times] : ccount) {
      if(k > count * times) {
        k -= count * times;
        answer -= times;
      } else {
        answer -= k / count;
        break;
      }
    }
    return answer;
  }
};

// Accepted
// 43/43 cases passed (154 ms)
// Your runtime beats 50.87 % of cpp submissions
// Your memory usage beats 81 % of cpp submissions (63.1 MB)
```
