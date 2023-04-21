+++
updated = 2023-04-21T12:15:10+08:00
title = "2023-04-21 Daily Challenge"
path = "2023-04-21-Daily-Challenge"
date = 2023-04-21T12:15:10+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/profitable-schemes/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 21

## Description

**Profitable Schemes**

<p>There is a group of <code>n</code> members, and a list of various crimes they could commit. The <code>i<sup>th</sup></code> crime generates a <code>profit[i]</code> and requires <code>group[i]</code> members to participate in it. If a member participates in one crime, that member can&#39;t participate in another crime.</p>

<p>Let&#39;s call a <strong>profitable scheme</strong> any subset of these crimes that generates at least <code>minProfit</code> profit, and the total number of members participating in that subset of crimes is at most <code>n</code>.</p>

<p>Return the number of schemes that can be chosen. Since the answer may be very large, <strong>return it modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 5, minProfit = 3, group = [2,2], profit = [2,3]
<strong>Output:</strong> 2
<strong>Explanation:</strong> To make a profit of at least 3, the group could either commit crimes 0 and 1, or just crime 1.
In total, there are 2 schemes.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 10, minProfit = 5, group = [2,3,5], profit = [6,7,8]
<strong>Output:</strong> 7
<strong>Explanation:</strong> To make a profit of at least 5, the group could commit any crimes, as long as they commit one.
There are 7 possible schemes: (0), (1), (2), (0,1), (0,2), (1,2), and (0,1,2).</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>0 &lt;= minProfit &lt;= 100</code></li>
	<li><code>1 &lt;= group.length &lt;= 100</code></li>
	<li><code>1 &lt;= group[i] &lt;= 100</code></li>
	<li><code>profit.length == group.length</code></li>
	<li><code>0 &lt;= profit[i] &lt;= 100</code></li>
</ul>


## Solution

``` cpp
class Solution {
  int len;
  const int MOD = 1e9 + 7;
  using pi = pair<int, int>;
  vector<pi> crimes;
  int dp[101][101][100];

  int solve(int restPeople, int restProfit, int position) {
    if(position == len || restPeople < crimes[position].first) {
      return restProfit <= 0;
    }
    restProfit = max(0, restProfit);
    if(dp[restPeople][restProfit][position] != -1) return dp[restPeople][restProfit][position];
    int result = solve(restPeople - crimes[position].first, restProfit - crimes[position].second, position + 1);
    result += solve(restPeople, restProfit, position + 1);
    result %= MOD;

    return dp[restPeople][restProfit][position] = result;
  }
public:
  int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
    len = group.size();
    memset(dp, -1, sizeof(dp));
    crimes.reserve(len);
    for(int i = 0; i < len; ++i) {
      crimes.push_back({group[i], profit[i]});
    }
    sort(crimes.begin(), crimes.end());

    return solve(n, minProfit, 0);
  }
};

// Accepted
// 45/45 cases passed (120 ms)
// Your runtime beats 91.04 % of cpp submissions
// Your memory usage beats 54.72 % of cpp submissions (13 MB)
```
