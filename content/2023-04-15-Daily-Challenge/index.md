+++
updated = 2023-04-15T09:11:55+08:00
title = "2023-04-15 Daily Challenge"
path = "2023-04-15-Daily-Challenge"
date = 2023-04-15T09:11:55+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 15

## Description

**Maximum Value of K Coins From Piles**

<p>There are <code>n</code> <strong>piles</strong> of coins on a table. Each pile consists of a <strong>positive number</strong> of coins of assorted denominations.</p>

<p>In one move, you can choose any coin on <strong>top</strong> of any pile, remove it, and add it to your wallet.</p>

<p>Given a list <code>piles</code>, where <code>piles[i]</code> is a list of integers denoting the composition of the <code>i<sup>th</sup></code> pile from <strong>top to bottom</strong>, and a positive integer <code>k</code>, return <em>the <strong>maximum total value</strong> of coins you can have in your wallet if you choose <strong>exactly</strong></em> <code>k</code> <em>coins optimally</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/11/09/e1.png" style="width: 600px; height: 243px;" />
<pre>
<strong>Input:</strong> piles = [[1,100,3],[7,8,9]], k = 2
<strong>Output:</strong> 101
<strong>Explanation:</strong>
The above diagram shows the different ways we can choose k coins.
The maximum total we can obtain is 101.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> piles = [[100],[100],[100],[100],[100],[100],[1,1,1,1,1,1,700]], k = 7
<strong>Output:</strong> 706
<strong>Explanation:
</strong>The maximum total can be obtained if we choose all coins from the last pile.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == piles.length</code></li>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= piles[i][j] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= sum(piles[i].length) &lt;= 2000</code></li>
</ul>


## Solution

bottom-up approach

``` cpp
class Solution {
public:
  int maxValueOfCoins(vector<vector<int>>& piles, int k) {
    int n = piles.size();
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));

    for(int p = 0; p < n; ++p) {
      dp[p + 1] = dp[p];
      int sum = 0;
      for(int i = 0; i < min<int>(piles[p].size(), k); ++i) {
        sum += piles[p][i];
        for(int j = 0; j + i + 1 <= k; ++j) {
          // cout << p + 1 << ' ' << j + i + 1 <<  ' ' << j << endl;
          dp[p + 1][j + i + 1] = max(dp[p + 1][j + i + 1], dp[p][j] + sum);
        }
        // cout << "OUT!?" << endl;
      }
    }

    return dp[n][k];
  }
};

// Accepted
// 122/122 cases passed (391 ms)
// Your runtime beats 29.06 % of cpp submissions
// Your memory usage beats 65.97 % of cpp submissions (18.1 MB)
```

top-down approach

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int maxValueOfCoins(vector<vector<int>>& piles, int k) {
    int n = piles.size();
    for(auto &pile : piles) {
      for(int i = 1; i < pile.size(); ++i) {
        pile[i] += pile[i - 1];
      }
    }
    vector<vector<int>> dp(n, vector<int>(k + 1));

    function<int(int, int)> solve = [&](int pile, int rest) {
      if(!rest || pile == n) return 0;
      if(dp[pile][rest]) return dp[pile][rest];
      int result = solve(pile + 1, rest);
      for(int i = 0; i < piles[pile].size() && i < rest; ++i) {
        result = max(result, piles[pile][i] + solve(pile + 1, rest - i - 1));
      }

      return dp[pile][rest] = result;
    };

    return solve(0, k);
  }
};

// Accepted
// 122/122 cases passed (447 ms)
// Your runtime beats 23.03 % of cpp submissions
// Your memory usage beats 46.34 % of cpp submissions (18.4 MB)
```
