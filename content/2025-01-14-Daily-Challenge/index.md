+++
updated = 2025-01-14T15:38:02+08:00
title = "2025-01-14 Daily Challenge"
path = "2025-01-14-Daily-Challenge"
date = 2025-01-14T15:38:02+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 14

## Description

**Find the Prefix Common Array of Two Arrays**

<p>You are given two <strong>0-indexed </strong>integer<strong> </strong>permutations <code>A</code> and <code>B</code> of length <code>n</code>.</p>

<p>A <strong>prefix common array</strong> of <code>A</code> and <code>B</code> is an array <code>C</code> such that <code>C[i]</code> is equal to the count of numbers that are present at or before the index <code>i</code> in both <code>A</code> and <code>B</code>.</p>

<p>Return <em>the <strong>prefix common array</strong> of </em><code>A</code><em> and </em><code>B</code>.</p>

<p>A sequence of <code>n</code> integers is called a&nbsp;<strong>permutation</strong> if it contains all integers from <code>1</code> to <code>n</code> exactly once.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> A = [1,3,2,4], B = [3,1,2,4]
<strong>Output:</strong> [0,2,3,4]
<strong>Explanation:</strong> At i = 0: no number is common, so C[0] = 0.
At i = 1: 1 and 3 are common in A and B, so C[1] = 2.
At i = 2: 1, 2, and 3 are common in A and B, so C[2] = 3.
At i = 3: 1, 2, 3, and 4 are common in A and B, so C[3] = 4.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> A = [2,3,1], B = [3,1,2]
<strong>Output:</strong> [0,1,3]
<strong>Explanation:</strong> At i = 0: no number is common, so C[0] = 0.
At i = 1: only 3 is common in A and B, so C[1] = 1.
At i = 2: 1, 2, and 3 are common in A and B, so C[2] = 3.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= A.length == B.length == n &lt;= 50</code></li>
	<li><code>1 &lt;= A[i], B[i] &lt;= n</code></li>
	<li><code>It is guaranteed that A and B are both a permutation of n integers.</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    int len = A.size();
    set<int> a, b;
    vector<int> answer;
    answer.reserve(len);
    A.reserve(len);
    B.reserve(len);
    int count = 0;
    for(int i = 0; i < A.size(); ++i) {
      a.insert(A[i]);
      b.insert(B[i]);
      count += a.count(B[i]) + b.count(A[i]) - (A[i] == B[i]);
      answer.push_back(count);
    }
    return answer;
  }
};

// Accepted
// 1773/1773 cases passed (14 ms)
// Your runtime beats 35.21 % of cpp submissions
// Your memory usage beats 11.23 % of cpp submissions (91.1 MB)
```
