+++
updated = 2025-10-12T23:56:04+02:00
title = "2025-10-12 Daily Challenge"
path = "2025-10-12-Daily-Challenge"
date = 2025-10-12T23:56:04+02:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/find-sum-of-array-product-of-magical-sequences/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 12

## Description

**Find Sum of Array Product of Magical Sequences**

<p>You are given two integers, <code>m</code> and <code>k</code>, and an integer array <code>nums</code>.</p>
A sequence of integers <code>seq</code> is called <strong>magical</strong> if:

<ul>
	<li><code>seq</code> has a size of <code>m</code>.</li>
	<li><code>0 &lt;= seq[i] &lt; nums.length</code></li>
	<li>The <strong>binary representation</strong> of <code>2<sup>seq[0]</sup> + 2<sup>seq[1]</sup> + ... + 2<sup>seq[m - 1]</sup></code> has <code>k</code> <strong>set bits</strong>.</li>
</ul>

<p>The <strong>array product</strong> of this sequence is defined as <code>prod(seq) = (nums[seq[0]] * nums[seq[1]] * ... * nums[seq[m - 1]])</code>.</p>

<p>Return the <strong>sum</strong> of the <strong>array products</strong> for all valid <strong>magical</strong> sequences.</p>

<p>Since the answer may be large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>A <strong>set bit</strong> refers to a bit in the binary representation of a number that has a value of 1.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">m = 5, k = 5, nums = [1,10,100,10000,1000000]</span></p>

<p><strong>Output:</strong> <span class="example-io">991600007</span></p>

<p><strong>Explanation:</strong></p>

<p>All permutations of <code>[0, 1, 2, 3, 4]</code> are magical sequences, each with an array product of 10<sup>13</sup>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">m = 2, k = 2, nums = [5,4,3,2,1]</span></p>

<p><strong>Output:</strong> <span class="example-io">170</span></p>

<p><strong>Explanation:</strong></p>

<p>The magical sequences are <code>[0, 1]</code>, <code>[0, 2]</code>, <code>[0, 3]</code>, <code>[0, 4]</code>, <code>[1, 0]</code>, <code>[1, 2]</code>, <code>[1, 3]</code>, <code>[1, 4]</code>, <code>[2, 0]</code>, <code>[2, 1]</code>, <code>[2, 3]</code>, <code>[2, 4]</code>, <code>[3, 0]</code>, <code>[3, 1]</code>, <code>[3, 2]</code>, <code>[3, 4]</code>, <code>[4, 0]</code>, <code>[4, 1]</code>, <code>[4, 2]</code>, and <code>[4, 3]</code>.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">m = 1, k = 1, nums = [28]</span></p>

<p><strong>Output:</strong> <span class="example-io">28</span></p>

<p><strong>Explanation:</strong></p>

<p>The only magical sequence is <code>[0]</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= m &lt;= 30</code></li>
	<li><code>1 &lt;= nums.length &lt;= 50</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>8</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
  using ll = long long;
  const int MOD = 1e9 + 7;
  ll dp[55][35][35][35] = {};
  bool vis[55][35][35][35] = {};
  vector<vector<ll>> powNum;
  vector<vector<ll>> C;
  int len;
  int k;
  int m;
  void init(const vector<int>& nums) {
    powNum.resize(len, vector<ll>(m + 1, 1));
    for(int i = 0; i < len; ++i) {
      for(int j = 1; j <= m; ++j) {
        powNum[i][j] = powNum[i][j - 1] * nums[i] % MOD;
      }
    }
    C.resize(m + 1, vector<ll>(m + 1));
    for(int i = 0; i <= m; ++i) {
      C[i][0] = C[i][i] = 1;
      for(int j = 1; j < i; ++j) {
        C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
      }
    }
  }
  ll dfs(int pos, int carry, int used, int ones) {
    if(pos == len) {
      int extra = 0;
      int c = carry;
      while(c) {
        if(c & 1) extra += 1;
        c >>= 1;
      }
      return (used == m && ones + extra == k) ? 1 : 0;
    }
    if(dp[pos][carry][used][ones] != -1) return dp[pos][carry][used][ones];
    ll answer = 0;
    for(int count = 0; count + used <= m; ++count) {
      int total = carry + count;
      int bit = total & 1;
      int ncarry = total >> 1;
      int nones = ones + bit;
      ll sub = dfs(pos + 1, ncarry, used + count, nones);
      if(!sub) continue;
      ll ways = C[m - used][count];
      ll prod = powNum[pos][count];
      answer += sub * ways % MOD * prod % MOD;
      answer %= MOD;
    }
    // cout << pos << ' ' << carry << ' ' << used << ' ' << ones << ' ' << answer << endl;
    return dp[pos][carry][used][ones] = answer;
  }
public:
  int magicalSum(int m, int k, vector<int>& nums) {
    memset(dp, -1, sizeof(dp));
    this->m = m;
    this->k = k;
    len = nums.size();
    init(nums);
    return dfs(0, 0, 0, 0);
  }
};

// Accepted
// 528/528 cases passed (700 ms)
// Your runtime beats 8.57 % of cpp submissions
// Your memory usage beats 40 % of cpp submissions (45.2 MB)
```
