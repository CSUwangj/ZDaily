+++
updated = 2024-01-27T17:38:05+08:00
title = "2024-01-27 Daily Challenge"
path = "2024-01-27-Daily-Challenge"
date = 2024-01-27T17:38:05+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/k-inverse-pairs-array/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 27

## Description

**K Inverse Pairs Array**

<p>For an integer array <code>nums</code>, an <strong>inverse pair</strong> is a pair of integers <code>[i, j]</code> where <code>0 &lt;= i &lt; j &lt; nums.length</code> and <code>nums[i] &gt; nums[j]</code>.</p>

<p>Given two integers n and k, return the number of different arrays consist of numbers from <code>1</code> to <code>n</code> such that there are exactly <code>k</code> <strong>inverse pairs</strong>. Since the answer can be huge, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 3, k = 0
<strong>Output:</strong> 1
<strong>Explanation:</strong> Only the array [1,2,3] which consists of numbers from 1 to 3 has exactly 0 inverse pairs.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 3, k = 1
<strong>Output:</strong> 2
<strong>Explanation:</strong> The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li><code>0 &lt;= k &lt;= 1000</code></li>
</ul>


## Solution

``` cpp
const int MOD = 1e9 + 7;
int values[1001][1001] = {};
const int SZ = 1000;
void init(int N) {
  values[0][0] = 1;
  for(int i = 1; i <= N; ++i) {
    int nextJ = i * (i + 1) / 2;
    int J = i * (i - 1) / 2;
    J = J > SZ ? SZ : J;
    nextJ = nextJ > SZ ? SZ : nextJ;
    for(int j = 0; j <= J; ++j) {
      values[i][j] = (j ? values[i][j - 1] : 0) + values[i - 1][j] - (i > j ? 0 : values[i - 1][j - i]);
      values[i][j] = (values[i][j] % MOD + MOD) % MOD;
    }
    for(int j = J + 1; j <= nextJ; ++j) {
      values[i][j] = values[i][j - 1];
    }
  }
}

class Solution {
public:
  int kInversePairs(int n, int k) {
    if(!k) return 1;
    init(n);
    int answer = values[n][k] - values[n][k - 1];
    answer = (answer % MOD + MOD) % MOD;
    return answer;
  }
};

// Accepted
// 80/80 cases passed (66 ms)
// Your runtime beats 27.47 % of cpp submissions
// Your memory usage beats 44.5 % of cpp submissions (11 MB)
```
