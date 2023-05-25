+++
updated = 2023-05-25T20:54:54+08:00
title = "2023-05-25 Daily Challenge"
path = "2023-05-25-Daily-Challenge"
date = 2023-05-25T20:54:54+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/new-21-game/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 25

## Description

**New 21 Game**

<p>Alice plays the following game, loosely based on the card game <strong>&quot;21&quot;</strong>.</p>

<p>Alice starts with <code>0</code> points and draws numbers while she has less than <code>k</code> points. During each draw, she gains an integer number of points randomly from the range <code>[1, maxPts]</code>, where <code>maxPts</code> is an integer. Each draw is independent and the outcomes have equal probabilities.</p>

<p>Alice stops drawing numbers when she gets <code>k</code> <strong>or more points</strong>.</p>

<p>Return the probability that Alice has <code>n</code> or fewer points.</p>

<p>Answers within <code>10<sup>-5</sup></code> of the actual answer are considered accepted.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 10, k = 1, maxPts = 10
<strong>Output:</strong> 1.00000
<strong>Explanation:</strong> Alice gets a single card, then stops.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 6, k = 1, maxPts = 10
<strong>Output:</strong> 0.60000
<strong>Explanation:</strong> Alice gets a single card, then stops.
In 6 out of 10 possibilities, she is at or below 6 points.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> n = 21, k = 17, maxPts = 10
<strong>Output:</strong> 0.73278
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= k &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= maxPts &lt;= 10<sup>4</sup></code></li>
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
  double new21Game(int n, int k, int maxPts) {
    if(k == 0) return 1;
    int maxP = k + maxPts;
    if(n + 1 >= maxP) return 1;
    vector<double> probability(maxP);
    probability[0] = 1;

    double sum = 1;
    double answer = 0;
    for(int i = 1; i <= n; ++i) {
      probability[i] = sum / maxPts;
      
      if(i < k) {
        sum += probability[i];
      } else {
        answer += probability[i];
      }

      if(i >= maxPts) sum -= probability[i - maxPts]; 
    }

    return answer;
  }
};

// Accepted
// 151/151 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 20.16 % of cpp submissions (10.7 MB)
```
