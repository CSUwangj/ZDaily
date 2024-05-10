+++
updated = 2024-05-10T09:54:07+08:00
title = "2024-05-10 Daily Challenge"
path = "2024-05-10-Daily-Challenge"
date = 2024-05-10T09:54:07+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/k-th-smallest-prime-fraction/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 10

## Description

**K-th Smallest Prime Fraction**

<p>You are given a sorted integer array <code>arr</code> containing <code>1</code> and <strong>prime</strong> numbers, where all the integers of <code>arr</code> are unique. You are also given an integer <code>k</code>.</p>

<p>For every <code>i</code> and <code>j</code> where <code>0 &lt;= i &lt; j &lt; arr.length</code>, we consider the fraction <code>arr[i] / arr[j]</code>.</p>

<p>Return <em>the</em> <code>k<sup>th</sup></code> <em>smallest fraction considered</em>. Return your answer as an array of integers of size <code>2</code>, where <code>answer[0] == arr[i]</code> and <code>answer[1] == arr[j]</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> arr = [1,2,3,5], k = 3
<strong>Output:</strong> [2,5]
<strong>Explanation:</strong> The fractions to be considered in sorted order are:
1/5, 1/3, 2/5, 1/2, 3/5, and 2/3.
The third fraction is 2/5.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> arr = [1,7], k = 1
<strong>Output:</strong> [1,7]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= arr.length &lt;= 1000</code></li>
	<li><code>1 &lt;= arr[i] &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>arr[0] == 1</code></li>
	<li><code>arr[i]</code> is a <strong>prime</strong> number for <code>i &gt; 0</code>.</li>
	<li>All the numbers of <code>arr</code> are <strong>unique</strong> and sorted in <strong>strictly increasing</strong> order.</li>
	<li><code>1 &lt;= k &lt;= arr.length * (arr.length - 1) / 2</code></li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Can you solve the problem with better than <code>O(n<sup>2</sup>)</code> complexity?

## Solution

``` cpp
struct s{
  double val;
  int up;
  int dn;
  
  bool operator<(const s& b){
    return val<b.val;
  }
}v[2000000];
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
    vector<int> ans;
    int cnt = 0;
    for(int i=1;i<A.size();++i){
      for(int j=0;j<i;++j){
        v[cnt].val = 1.0*A[j]/A[i];
        v[cnt].up = A[j];
        v[cnt].dn = A[i];
        ++cnt;
      }
    }
    nth_element(v,v+K-1,v+cnt);
    // for(int i=0;i<v.size();++i){
    //     cout<<v[i].up<<" "<<v[i].dn<<endl;
    // }
    ans.push_back(v[K-1].up);
    ans.push_back(v[K-1].dn);
    return ans;
  }
};
```
