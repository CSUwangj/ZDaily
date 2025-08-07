+++
updated = 2025-08-08T00:42:16+08:00
title = "2025-08-07 Daily Challenge"
path = "2025-08-07-Daily-Challenge"
date = 2025-08-08T00:42:16+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/find-the-maximum-number-of-fruits-collected/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 7

## Description

**Find the Maximum Number of Fruits Collected**

<p>There is a game dungeon comprised of&nbsp;<code>n x n</code> rooms arranged in a grid.</p>

<p>You are given a 2D array <code>fruits</code> of size <code>n x n</code>, where <code>fruits[i][j]</code> represents the number of fruits in the room <code>(i, j)</code>. Three children will play in the game dungeon, with <strong>initial</strong> positions at the corner rooms <code>(0, 0)</code>, <code>(0, n - 1)</code>, and <code>(n - 1, 0)</code>.</p>

<p>The children will make <strong>exactly</strong> <code>n - 1</code> moves according to the following rules to reach the room <code>(n - 1, n - 1)</code>:</p>

<ul>
	<li>The child starting from <code>(0, 0)</code> must move from their current room <code>(i, j)</code> to one of the rooms <code>(i + 1, j + 1)</code>, <code>(i + 1, j)</code>, and <code>(i, j + 1)</code> if the target room exists.</li>
	<li>The child starting from <code>(0, n - 1)</code> must move from their current room <code>(i, j)</code> to one of the rooms <code>(i + 1, j - 1)</code>, <code>(i + 1, j)</code>, and <code>(i + 1, j + 1)</code> if the target room exists.</li>
	<li>The child starting from <code>(n - 1, 0)</code> must move from their current room <code>(i, j)</code> to one of the rooms <code>(i - 1, j + 1)</code>, <code>(i, j + 1)</code>, and <code>(i + 1, j + 1)</code> if the target room exists.</li>
</ul>

<p>When a child enters a room, they will collect all the fruits there. If two or more children enter the same room, only one child will collect the fruits, and the room will be emptied after they leave.</p>

<p>Return the <strong>maximum</strong> number of fruits the children can collect from the dungeon.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">fruits = [[1,2,3,4],[5,6,8,7],[9,10,11,12],[13,14,15,16]]</span></p>

<p><strong>Output:</strong> <span class="example-io">100</span></p>

<p><strong>Explanation:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/10/15/example_1.gif" style="width: 250px; height: 214px;" /></p>

<p>In this example:</p>

<ul>
	<li>The 1<sup>st</sup> child (green) moves on the path <code>(0,0) -&gt; (1,1) -&gt; (2,2) -&gt; (3, 3)</code>.</li>
	<li>The 2<sup>nd</sup> child (red) moves on the path <code>(0,3) -&gt; (1,2) -&gt; (2,3) -&gt; (3, 3)</code>.</li>
	<li>The 3<sup>rd</sup> child (blue) moves on the path <code>(3,0) -&gt; (3,1) -&gt; (3,2) -&gt; (3, 3)</code>.</li>
</ul>

<p>In total they collect <code>1 + 6 + 11 + 16 + 4 + 8 + 12 + 13 + 14 + 15 = 100</code> fruits.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">fruits = [[1,1],[1,1]]</span></p>

<p><strong>Output:</strong> <span class="example-io">4</span></p>

<p><strong>Explanation:</strong></p>

<p>In this example:</p>

<ul>
	<li>The 1<sup>st</sup> child moves on the path <code>(0,0) -&gt; (1,1)</code>.</li>
	<li>The 2<sup>nd</sup> child moves on the path <code>(0,1) -&gt; (1,1)</code>.</li>
	<li>The 3<sup>rd</sup> child moves on the path <code>(1,0) -&gt; (1,1)</code>.</li>
</ul>

<p>In total they collect <code>1 + 1 + 1 + 1 = 4</code> fruits.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n == fruits.length == fruits[i].length &lt;= 1000</code></li>
	<li><code>0 &lt;= fruits[i][j] &lt;= 1000</code></li>
</ul>


## Solution

``` cpp
template<typename T>
std::ostream& operator<<(std::ostream &out, const std::vector<T> &v) {
  if(v.size() == 0) {
    out << "[]" << std::endl;
    return out;
  }
  out << '[' << v[0];
  for(int i = 1; i < v.size(); ++i) {
    out << ", " << v[i];
  }
  out << ']';
  return out;
}
class Solution {
public:
  int maxCollectedFruits(vector<vector<int>>& fruits) {
    int n = fruits.size();
    int answer = 0;
    for(int i = 0; i < n; ++i) {
      answer += fruits[i][i];
    }

    vector<vector<int>> dp(2, vector<int>(n, -1));
    dp[0][n - 1] = fruits[0][n - 1];
    for(int i = 1; i < n - 1; ++i) {
      int parity = (i & 1);
      for(int j = max(n - 1 - i, i + 1); j < n; ++j) {
        int result = dp[!parity][j];
        if(j >= 1) result = max(result, dp[!parity][j - 1]);
        if(j < n - 1) result = max(result, dp[!parity][j + 1]);
        dp[parity][j] = result + fruits[i][j];
      }
    }
    // cout << dp << endl;
    answer += dp[(n & 1)][n - 1];

    fill(dp[0].begin(), dp[0].end(), -1);
    fill(dp[1].begin(), dp[1].end(), -1);
    dp[0][n - 1] = fruits[n - 1][0];
    for(int i = 1; i < n - 1; ++i) {
      int parity = (i & 1);
      for(int j = max(n - 1 - i, i + 1); j < n; ++j) {
        int result = dp[!parity][j];
        if(j >= 1) result = max(result, dp[!parity][j - 1]);
        if(j < n - 1) result = max(result, dp[!parity][j + 1]);
        dp[parity][j] = result + fruits[j][i];
      }
    }
    // cout << dp << endl;
    answer += dp[(n & 1)][n - 1];

    return answer;
  }
};

// Accepted
// 548/548 cases passed (10 ms)
// Your runtime beats 98.05 % of cpp submissions
// Your memory usage beats 91.56 % of cpp submissions (137.6 MB)
```
