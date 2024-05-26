+++
updated = 2024-05-26T12:33:15+08:00
title = "2024-05-26 Daily Challenge"
path = "2024-05-26-Daily-Challenge"
date = 2024-05-26T12:33:15+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/student-attendance-record-ii/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 26

## Description

**Student Attendance Record II**

<p>An attendance record for a student can be represented as a string where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:</p>

<ul>
	<li><code>&#39;A&#39;</code>: Absent.</li>
	<li><code>&#39;L&#39;</code>: Late.</li>
	<li><code>&#39;P&#39;</code>: Present.</li>
</ul>

<p>Any student is eligible for an attendance award if they meet <strong>both</strong> of the following criteria:</p>

<ul>
	<li>The student was absent (<code>&#39;A&#39;</code>) for <strong>strictly</strong> fewer than 2 days <strong>total</strong>.</li>
	<li>The student was <strong>never</strong> late (<code>&#39;L&#39;</code>) for 3 or more <strong>consecutive</strong> days.</li>
</ul>

<p>Given an integer <code>n</code>, return <em>the <strong>number</strong> of possible attendance records of length</em> <code>n</code><em> that make a student eligible for an attendance award. The answer may be very large, so return it <strong>modulo</strong> </em><code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 2
<strong>Output:</strong> 8
<strong>Explanation:</strong> There are 8 records with length 2 that are eligible for an award:
&quot;PP&quot;, &quot;AP&quot;, &quot;PA&quot;, &quot;LP&quot;, &quot;PL&quot;, &quot;AL&quot;, &quot;LA&quot;, &quot;LL&quot;
Only &quot;AA&quot; is not eligible because there are 2 absences (there need to be fewer than 2).
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 1
<strong>Output:</strong> 3
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> n = 10101
<strong>Output:</strong> 183236316
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int checkRecord(int n) {
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp(2, vector<int>(6));
    dp[0][0] = 1;
    dp[0][1] = 1;
    dp[0][3] = 1;
    for(int i = 1; i < n; ++i) {
      dp[i & 1][0] = (dp[(~i) & 1][0] + dp[(~i) & 1][1]) % MOD;
      dp[i & 1][0] = (dp[i & 1][0] + dp[(~i) & 1][2]) % MOD;
      dp[i & 1][1] = dp[(~i) & 1][0];
      dp[i & 1][2] = dp[(~i) & 1][1];
      dp[i & 1][3] = 0;
      for (int j = 0; j < 6; ++j) {
        dp[i & 1][3] += dp[(~i) & 1][j];
        dp[i & 1][3] %= MOD;
      }
      dp[i & 1][4] = dp[(~i) & 1][3];
      dp[i & 1][5] = dp[(~i) & 1][4];
    }
    int answer = 0;
    for (int i = 0; i < 6; ++i) {
      answer += dp[(~n) & 1][i];
      answer %= MOD;
    }
    return answer;
  }
};
```
