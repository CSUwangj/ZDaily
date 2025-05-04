+++
updated = 2025-05-04T11:47:58+08:00
title = "2025-05-04 Daily Challenge"
path = "2025-05-04-Daily-Challenge"
date = 2025-05-04T11:47:58+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/number-of-equivalent-domino-pairs/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 4

## Description

**Number of Equivalent Domino Pairs**

<p>Given a list of <code>dominoes</code>, <code>dominoes[i] = [a, b]</code> is <strong>equivalent to</strong> <code>dominoes[j] = [c, d]</code> if and only if either (<code>a == c</code> and <code>b == d</code>), or (<code>a == d</code> and <code>b == c</code>) - that is, one domino can be rotated to be equal to another domino.</p>

<p>Return <em>the number of pairs </em><code>(i, j)</code><em> for which </em><code>0 &lt;= i &lt; j &lt; dominoes.length</code><em>, and </em><code>dominoes[i]</code><em> is <strong>equivalent to</strong> </em><code>dominoes[j]</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> dominoes = [[1,2],[2,1],[3,4],[5,6]]
<strong>Output:</strong> 1
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> dominoes = [[1,2],[1,2],[1,1],[1,2],[2,2]]
<strong>Output:</strong> 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= dominoes.length &lt;= 4 * 10<sup>4</sup></code></li>
	<li><code>dominoes[i].length == 2</code></li>
	<li><code>1 &lt;= dominoes[i][j] &lt;= 9</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    map<int, int> count;
    for(auto &domino : dominoes) {
      if(domino[0] < domino[1]) {
        count[domino[0] * 10 + domino[1]] += 1;
      } else {
        count[domino[1] * 10 + domino[0]] += 1;
      }
    }
    int answer = 0;
    for(auto [_code, c] : count) {
      answer += c * (c - 1) / 2;
    }
    return answer;
  }
};

// Accepted
// 19/19 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 32.75 % of cpp submissions (26.4 MB)
```
