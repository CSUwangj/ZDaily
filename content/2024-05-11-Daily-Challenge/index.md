+++
updated = 2024-05-11T12:19:42+08:00
title = "2024-05-11 Daily Challenge"
path = "2024-05-11-Daily-Challenge"
date = 2024-05-11T12:19:42+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/minimum-cost-to-hire-k-workers/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 11

## Description

**Minimum Cost to Hire K Workers**

<p>There are <code>n</code> workers. You are given two integer arrays <code>quality</code> and <code>wage</code> where <code>quality[i]</code> is the quality of the <code>i<sup>th</sup></code> worker and <code>wage[i]</code> is the minimum wage expectation for the <code>i<sup>th</sup></code> worker.</p>

<p>We want to hire exactly <code>k</code> workers to form a <strong>paid group</strong>. To hire a group of <code>k</code> workers, we must pay them according to the following rules:</p>

<ol>
	<li>Every worker in the paid group must be paid at least their minimum wage expectation.</li>
	<li>In the group, each worker&#39;s pay must be directly proportional to their quality. This means if a worker&rsquo;s quality is double that of another worker in the group, then they must be paid twice as much as the other worker.</li>
</ol>

<p>Given the integer <code>k</code>, return <em>the least amount of money needed to form a paid group satisfying the above conditions</em>. Answers within <code>10<sup>-5</sup></code> of the actual answer will be accepted.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> quality = [10,20,5], wage = [70,50,30], k = 2
<strong>Output:</strong> 105.00000
<strong>Explanation:</strong> We pay 70 to 0<sup>th</sup> worker and 35 to 2<sup>nd</sup> worker.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> quality = [3,1,10,10,1], wage = [4,8,2,2,7], k = 3
<strong>Output:</strong> 30.66667
<strong>Explanation:</strong> We pay 4 to 0<sup>th</sup> worker, 13.33333 to 2<sup>nd</sup> and 3<sup>rd</sup> workers separately.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == quality.length == wage.length</code></li>
	<li><code>1 &lt;= k &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= quality[i], wage[i] &lt;= 10<sup>4</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
    vector<pair<double, int>> ratio;
    int n = wage.size();
    for(int i = 0; i < n; ++i) {
      ratio.push_back({wage[i] * 1.0 / quality[i], i});
    }

    sort(ratio.begin(), ratio.end());
    priority_queue<int> pq;
    int qualitySum = 0;
    double maxRate = 0;
    for(int i = 0; i < k; ++i) {
      qualitySum += quality[ratio[i].second];
      maxRate = max(maxRate, ratio[i].first);
      pq.push(quality[ratio[i].second]);
    }

    double answer = maxRate * qualitySum;
    for(int i = k; i < n; ++i) {
      maxRate = max(maxRate, ratio[i].first);
      qualitySum -= pq.top();
      pq.pop();

      qualitySum += quality[ratio[i].second];
      pq.push(quality[ratio[i].second]);
      answer = min(answer, maxRate * qualitySum);
    }

    return answer;
  }
};
```
