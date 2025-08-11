+++
updated = 2025-08-11T13:30:06+08:00
title = "2025-08-11 Daily Challenge"
path = "2025-08-11-Daily-Challenge"
date = 2025-08-11T13:30:06+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/range-product-queries-of-powers/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 11

## Description

**Range Product Queries of Powers**

<p>Given a positive integer <code>n</code>, there exists a <strong>0-indexed</strong> array called <code>powers</code>, composed of the <strong>minimum</strong> number of powers of <code>2</code> that sum to <code>n</code>. The array is sorted in <strong>non-decreasing</strong> order, and there is <strong>only one</strong> way to form the array.</p>

<p>You are also given a <strong>0-indexed</strong> 2D integer array <code>queries</code>, where <code>queries[i] = [left<sub>i</sub>, right<sub>i</sub>]</code>. Each <code>queries[i]</code> represents a query where you have to find the product of all <code>powers[j]</code> with <code>left<sub>i</sub> &lt;= j &lt;= right<sub>i</sub></code>.</p>

<p>Return<em> an array </em><code>answers</code><em>, equal in length to </em><code>queries</code><em>, where </em><code>answers[i]</code><em> is the answer to the </em><code>i<sup>th</sup></code><em> query</em>. Since the answer to the <code>i<sup>th</sup></code> query may be too large, each <code>answers[i]</code> should be returned <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 15, queries = [[0,1],[2,2],[0,3]]
<strong>Output:</strong> [2,4,64]
<strong>Explanation:</strong>
For n = 15, powers = [1,2,4,8]. It can be shown that powers cannot be a smaller size.
Answer to 1st query: powers[0] * powers[1] = 1 * 2 = 2.
Answer to 2nd query: powers[2] = 4.
Answer to 3rd query: powers[0] * powers[1] * powers[2] * powers[3] = 1 * 2 * 4 * 8 = 64.
Each answer modulo 10<sup>9</sup> + 7 yields the same answer, so [2,4,64] is returned.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 2, queries = [[0,0]]
<strong>Output:</strong> [2]
<strong>Explanation:</strong>
For n = 2, powers = [2].
The answer to the only query is powers[0] = 2. The answer modulo 10<sup>9</sup> + 7 is the same, so [2] is returned.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= start<sub>i</sub> &lt;= end<sub>i</sub> &lt; powers.length</code></li>
</ul>


## Solution

``` cpp
const int MOD = 1e9 + 7;
constexpr int qmul(long long a, long long b, int m) {
  return a * b % m;
}
constexpr int qpow(int b, int e, int m) {
  int result = 1;
  while(e) {
    if(e & 1) {
      result = qmul(result, b, m);
    }
    b = qmul(b, b, m);
    e >>= 1;
  }
  return result;
}
constexpr int inv(int a) {
  return qpow(a, MOD - 2, MOD);
}

class Solution {
  const int MOD = 1e9 + 7;
public:
  vector<int> productQueries(int n, vector<vector<int>>& queries) {
    vector<int> powers(1);
    for(int i = 0; i < 30; ++i) {
      if((1 << i) & n) powers.push_back(i);
    }
    int len = powers.size();
    for(int i = 1; i < len; ++i) {
      powers[i] += powers[i - 1];
    }
    int qLen = queries.size();
    vector<int> answer(qLen);
    for(int i = 0; i < qLen; ++i) {
      answer[i] = qpow(2, powers[queries[i][1] + 1] - powers[queries[i][0]], MOD);
    }
    return answer;
  }
};

// Accepted
// 70/70 cases passed (8 ms)
// Your runtime beats 90.43 % of cpp submissions
// Your memory usage beats 89.89 % of cpp submissions (144.9 MB)
```
