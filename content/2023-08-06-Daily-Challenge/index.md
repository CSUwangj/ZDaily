+++
updated = 2023-08-06T12:26:26+08:00
title = "2023-08-06 Daily Challenge"
path = "2023-08-06-Daily-Challenge"
date = 2023-08-06T12:26:26+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/number-of-music-playlists/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 6

## Description

**Number of Music Playlists**

<p>Your music player contains <code>n</code> different songs. You want to listen to <code>goal</code> songs (not necessarily different) during your trip. To avoid boredom, you will create a playlist so that:</p>

<ul>
	<li>Every song is played <strong>at least once</strong>.</li>
	<li>A song can only be played again only if <code>k</code> other songs have been played.</li>
</ul>

<p>Given <code>n</code>, <code>goal</code>, and <code>k</code>, return <em>the number of possible playlists that you can create</em>. Since the answer can be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 3, goal = 3, k = 1
<strong>Output:</strong> 6
<strong>Explanation:</strong> There are 6 possible playlists: [1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], and [3, 2, 1].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 2, goal = 3, k = 0
<strong>Output:</strong> 6
<strong>Explanation:</strong> There are 6 possible playlists: [1, 1, 2], [1, 2, 1], [2, 1, 1], [2, 2, 1], [2, 1, 2], and [1, 2, 2].
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> n = 2, goal = 3, k = 1
<strong>Output:</strong> 2
<strong>Explanation:</strong> There are 2 possible playlists: [1, 2, 1] and [2, 1, 2].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= k &lt; n &lt;= goal &lt;= 100</code></li>
</ul>


## Solution

``` cpp
class Solution {
  using ll = long long;
  const int MOD = 1e9 + 7;
public:
  int numMusicPlaylists(int n, int goal, int k) {
    vector<vector<ll>> dp(2, vector<ll>(n + 1));
    dp[0][0] = 1;
    
    for(int i = 1; i <= goal; ++i) {
      int parity = i & 1;
      dp[parity][0] = 0;
      for(int j = 1; j <= min(i, n); ++j) {
        dp[parity][j] = dp[parity ^ 1][j - 1] * (n - j + 1);
        dp[parity][j] %= MOD;
        if(i > k) {
          dp[parity][j] += dp[parity ^ 1][j] * (j - k);
          dp[parity][j] %= MOD;
        }
      }
    }

    return dp[goal & 1][n];
  }
};

// Accepted
// 83/83 cases passed (3 ms)
// Your runtime beats 83.78 % of cpp submissions
// Your memory usage beats 61.26 % of cpp submissions (6.3 MB)
```
