+++
title = "2021-05-26 Daily-Challenge"
path = "2021-05-26-Daily-Challenge"
date = 2021-05-26 18:00:16+08:00
updated = 2021-05-26 18:34:22+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Dice Roll Simulation](https://leetcode.com/problems/dice-roll-simulation/) and leetcode's [May LeetCoding Challenge](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/601/week-4-may-22nd-may-28th/3756/) with `cpp`.

<!-- more -->

# Dice Roll Simulation

## Description

A die simulator generates a random number from 1 to 6 for each roll. You introduced a constraint to the generator such that it cannot roll the number `i` more than `rollMax[i]` (1-indexed) **consecutive** times. 

Given an array of integers `rollMax` and an integer `n`, return the number of distinct sequences that can be obtained with exact `n` rolls.

Two sequences are considered different if at least one element differs from each other. Since the answer may be too large, return it modulo `10^9 + 7`.

 

**Example 1:**

```
Input: n = 2, rollMax = [1,1,2,2,2,3]
Output: 34
Explanation: There will be 2 rolls of die, if there are no constraints on the die, there are 6 * 6 = 36 possible combinations. In this case, looking at rollMax array, the numbers 1 and 2 appear at most once consecutively, therefore sequences (1,1) and (2,2) cannot occur, so the final answer is 36-2 = 34.
```

**Example 2:**

```
Input: n = 2, rollMax = [1,1,1,1,1,1]
Output: 30
```

**Example 3:**

```
Input: n = 3, rollMax = [1,1,1,2,2,3]
Output: 181
```

 

**Constraints:**

- `1 <= n <= 5000`
- `rollMax.length == 6`
- `1 <= rollMax[i] <= 15`

## Solution

digit dynamic programming

using $DP[last\ digit][length\ of\ consecutive\ last\ digit][len]$ represent a state, then state transition equation will be:

$$dp[i][j][k] = \left\{\begin{matrix} dp[i][j-1][k-1],j \neq 1 \And j \le rollMax[i]\\ \sum\limits_{\substack{i'=1\\i'\neq i}}^6\sum\limits_{j'=1}^{rollMax[i']}dp[i'][j'][k-1], j = 1 \end{matrix}\right.$$

``` cpp
const int MOD = 1e9 + 7;
// change order for a useless optimization, check memeset below
int dp[5000][6][16] = {};
class Solution {
public:
  int dieSimulator(int n, vector<int>& rollMax) {
    // useless optimization
    memset(dp, 0, sizeof(dp) / 5000 * n);
    for(int i = 0; i < 6; ++i) {
      dp[0][i][0] = 1;
      dp[0][i][1] = 1;
    }
    for(int len = 1; len < n; ++len) {
      for(int dice = 0; dice < 6; ++dice) {
        for(int prevDice = 0; prevDice < 6; ++prevDice) {
          if(dice == prevDice) continue;
          dp[len][dice][1] += dp[len - 1][prevDice][0];
          dp[len][dice][1] %= MOD;
        }
        dp[len][dice][0] = dp[len][dice][1];
        for(int i = 1; i < rollMax[dice] && dp[len - 1][dice][i]; ++i) {
          dp[len][dice][i + 1] = dp[len - 1][dice][i];
          dp[len][dice][0] += dp[len - 1][dice][i];
          dp[len][dice][0] %= MOD;
        }
      }
    }
    int answer = 0;
    for(int i = 0; i < 6; ++i) {
      answer += dp[n - 1][i][0];
      answer %= MOD;
    }
    return answer;
  }
};
```

# May LeetCoding Challenge 26

## Description

**Partitioning Into Minimum Number Of Deci-Binary Numbers**

<p>A decimal number is called <strong>deci-binary</strong> if each of its digits is either <code>0</code> or <code>1</code> without any leading zeros. For example, <code>101</code> and <code>1100</code> are <strong>deci-binary</strong>, while <code>112</code> and <code>3001</code> are not.</p>

<p>Given a string <code>n</code> that represents a positive decimal integer, return <em>the <strong>minimum</strong> number of positive <strong>deci-binary</strong> numbers needed so that they sum up to </em><code>n</code><em>.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><code><strong>Input:</strong> n = &quot;32&quot;
<strong>Output:</strong> 3
<strong>Explanation:</strong> 10 + 11 + 11 = 32</code></pre>

<p><strong>Example 2:</strong></p>

<pre><code><strong>Input:</strong> n = &quot;82734&quot;
<strong>Output:</strong> 8</code></pre>

<p><strong>Example 3:</strong></p>

<pre><code><strong>Input:</strong> n = &quot;27346209830709182346&quot;
<strong>Output:</strong> 9</code></pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n.length &lt;= 10<sup>5</sup></code></li>
	<li><code>n</code> consists of only digits.</li>
	<li><code>n</code> does not contain any leading zeros and represents a positive integer.</li>
</ul>

## Solution

``` cpp
class Solution {
public:
  int minPartitions(string n) {
    return *max_element(n.begin(), n.end()) - '0';
  }
};
```
