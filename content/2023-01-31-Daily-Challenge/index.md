+++
updated = 2023-01-31T14:38:04+08:00
title = "2023-01-31 Daily Challenge"
path = "2023-01-31-Daily-Challenge"
date = 2023-01-31T14:38:04+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/best-team-with-no-conflicts/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 31

## Description

**Best Team With No Conflicts**

<p>You are the manager of a basketball team. For the upcoming tournament, you want to choose the team with the highest overall score. The score of the team is the <strong>sum</strong> of scores of all the players in the team.</p>

<p>However, the basketball team is not allowed to have <strong>conflicts</strong>. A <strong>conflict</strong> exists if a younger player has a <strong>strictly higher</strong> score than an older player. A conflict does <strong>not</strong> occur between players of the same age.</p>

<p>Given two lists, <code>scores</code> and <code>ages</code>, where each <code>scores[i]</code> and <code>ages[i]</code> represents the score and age of the <code>i<sup>th</sup></code> player, respectively, return <em>the highest overall score of all possible basketball teams</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> scores = [1,3,5,10,15], ages = [1,2,3,4,5]
<strong>Output:</strong> 34
<strong>Explanation:</strong>&nbsp;You can choose all the players.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> scores = [4,5,6,5], ages = [2,1,2,1]
<strong>Output:</strong> 16
<strong>Explanation:</strong>&nbsp;It is best to choose the last 3 players. Notice that you are allowed to choose multiple people of the same age.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> scores = [1,2,3,5], ages = [8,9,10,1]
<strong>Output:</strong> 6
<strong>Explanation:</strong>&nbsp;It is best to choose the first 3 players. 
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= scores.length, ages.length &lt;= 1000</code></li>
	<li><code>scores.length == ages.length</code></li>
	<li><code>1 &lt;= scores[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= ages[i] &lt;= 1000</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int bestTeamScore(vector<int>& scores, vector<int>& ages) {
    vector<pair<int, int>> players;
    for(int i = 0; i < scores.size(); ++i) {
      players.push_back({scores[i], ages[i]});
    }
    sort(players.begin(), players.end());

    map<int, int> result{{0, 0}};
    for(const auto &[score, age] : players) {
      auto it = result.upper_bound(age);
      --it; // less or equal
      int scoreSum = score + it->second;
      auto insertPos = result.insert(it, {age, scoreSum});
      if(insertPos->second < scoreSum) {
        insertPos->second = scoreSum;
      }
      ++insertPos;
      while(insertPos != result.end() && insertPos->second <= scoreSum) {
        result.erase(insertPos++);
      }
    }

    return result.rbegin()->second;
  }
};

// Accepted
// 149/149 cases passed (41 ms)
// Your runtime beats 99.03 % of cpp submissions
// Your memory usage beats 40.91 % of cpp submissions (22.4 MB)
```
