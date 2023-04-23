+++
updated = 2023-04-23T08:32:58+08:00
title = "2023-04-23 Daily Challenge"
path = "2023-04-23-Daily-Challenge"
date = 2023-04-23T08:32:58+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/restore-the-array/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 23

## Description

**Restore The Array**

<p>A program was supposed to print an array of integers. The program forgot to print whitespaces and the array is printed as a string of digits <code>s</code> and all we know is that all integers in the array were in the range <code>[1, k]</code> and there are no leading zeros in the array.</p>

<p>Given the string <code>s</code> and the integer <code>k</code>, return <em>the number of the possible arrays that can be printed as </em><code>s</code><em> using the mentioned program</em>. Since the answer may be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;1000&quot;, k = 10000
<strong>Output:</strong> 1
<strong>Explanation:</strong> The only possible array is [1000]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;1000&quot;, k = 10
<strong>Output:</strong> 0
<strong>Explanation:</strong> There cannot be an array that was printed this way and has all integer &gt;= 1 and &lt;= 10.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;1317&quot;, k = 2000
<strong>Output:</strong> 8
<strong>Explanation:</strong> Possible arrays are [1317],[131,7],[13,17],[1,317],[13,1,7],[1,31,7],[1,3,17],[1,3,1,7]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> consists of only digits and does not contain leading zeros.</li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
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
  const int MOD = 1e9 + 7;
  vector<int> dp;
  int solve(const string &s, int k, int pos) {
    if(pos == s.length()) return 1;
    if(s[pos] == '0') return 0;
    if(dp[pos] != -1) return dp[pos];
    int answer = 0;
    int num = 0;
    for(int j = pos; j < s.length(); ++j) {
      if((k - s[j] + '0') / 10 < num) break;
      num *= 10;
      num += s[j] - '0';
      answer += solve(s, k, j + 1);
      answer %= MOD;
    }

    return dp[pos] = answer;
  }
public:
  int numberOfArrays(string s, int k) {
    dp.resize(s.length(), -1);
    return solve(s, k, 0);
  }
};

// Accepted
// 83/83 cases passed (81 ms)
// Your runtime beats 45.35 % of cpp submissions
// Your memory usage beats 36.05 % of cpp submissions (20.8 MB)
```
