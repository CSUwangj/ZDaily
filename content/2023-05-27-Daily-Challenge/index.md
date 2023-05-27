+++
updated = 2023-05-27T11:51:31+08:00
title = "2023-05-27 Daily Challenge"
path = "2023-05-27-Daily-Challenge"
date = 2023-05-27T11:51:31+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/stone-game-iii/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 27

## Description

**Stone Game III**

<p>Alice and Bob continue their games with piles of stones. There are several stones <strong>arranged in a row</strong>, and each stone has an associated value which is an integer given in the array <code>stoneValue</code>.</p>

<p>Alice and Bob take turns, with Alice starting first. On each player&#39;s turn, that player can take <code>1</code>, <code>2</code>, or <code>3</code> stones from the <strong>first</strong> remaining stones in the row.</p>

<p>The score of each player is the sum of the values of the stones taken. The score of each player is <code>0</code> initially.</p>

<p>The objective of the game is to end with the highest score, and the winner is the player with the highest score and there could be a tie. The game continues until all the stones have been taken.</p>

<p>Assume Alice and Bob <strong>play optimally</strong>.</p>

<p>Return <code>&quot;Alice&quot;</code><em> if Alice will win, </em><code>&quot;Bob&quot;</code><em> if Bob will win, or </em><code>&quot;Tie&quot;</code><em> if they will end the game with the same score</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> values = [1,2,3,7]
<strong>Output:</strong> &quot;Bob&quot;
<strong>Explanation:</strong> Alice will always lose. Her best move will be to take three piles and the score become 6. Now the score of Bob is 7 and Bob wins.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> values = [1,2,3,-9]
<strong>Output:</strong> &quot;Alice&quot;
<strong>Explanation:</strong> Alice must choose all the three piles at the first move to win and leave Bob with negative score.
If Alice chooses one pile her score will be 1 and the next move Bob&#39;s score becomes 5. In the next move, Alice will take the pile with value = -9 and lose.
If Alice chooses two piles her score will be 3 and the next move Bob&#39;s score becomes 3. In the next move, Alice will take the pile with value = -9 and also lose.
Remember that both play optimally so here Alice will choose the scenario that makes her win.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> values = [1,2,3,6]
<strong>Output:</strong> &quot;Tie&quot;
<strong>Explanation:</strong> Alice cannot win this game. She can end the game in a draw if she decided to choose all the first three piles, otherwise she will lose.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= stoneValue.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>-1000 &lt;= stoneValue[i] &lt;= 1000</code></li>
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
public:
  string stoneGameIII(vector<int>& stoneValue) {
    int len = stoneValue.size();
    for(int i = 0; i < 3; ++i) {
      stoneValue.push_back(0);
    }
    partial_sum(stoneValue.begin(), stoneValue.end(), stoneValue.begin());
    int dp[len + 3];
    for(int i = 0; i < 3; ++i) {
      dp[len + i] = 0;
    }
    for(int i = len - 1; i >= 0; --i) {
      dp[i] = INT_MIN;
      for(int j = 0; j < 3; ++j) {
        dp[i] = max(dp[i], stoneValue[i + j] - (i ? stoneValue[i - 1] : 0) - dp[i + j + 1]);
      }
    }
    if(dp[0] > 0) return "Alice";
    if(dp[0] < 0) return "Bob";
    return "Tie";
  }
};

// Accepted
// 185/185 cases passed (136 ms)
// Your runtime beats 99.72 % of cpp submissions
// Your memory usage beats 93.84 % of cpp submissions (126.6 MB)
```
