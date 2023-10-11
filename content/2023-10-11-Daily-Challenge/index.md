+++
updated = 2023-10-11T22:36:17+08:00
title = "2023-10-11 Daily Challenge"
path = "2023-10-11-Daily-Challenge"
date = 2023-10-11T22:36:17+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/number-of-flowers-in-full-bloom/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 11

## Description

**Number of Flowers in Full Bloom**

<p>You are given a <strong>0-indexed</strong> 2D integer array <code>flowers</code>, where <code>flowers[i] = [start<sub>i</sub>, end<sub>i</sub>]</code> means the <code>i<sup>th</sup></code> flower will be in <strong>full bloom</strong> from <code>start<sub>i</sub></code> to <code>end<sub>i</sub></code> (<strong>inclusive</strong>). You are also given a <strong>0-indexed</strong> integer array <code>people</code> of size <code>n</code>, where <code>people[i]</code> is the time that the <code>i<sup>th</sup></code> person will arrive to see the flowers.</p>

<p>Return <em>an integer array </em><code>answer</code><em> of size </em><code>n</code><em>, where </em><code>answer[i]</code><em> is the <strong>number</strong> of flowers that are in full bloom when the </em><code>i<sup>th</sup></code><em> person arrives.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/03/02/ex1new.jpg" style="width: 550px; height: 216px;" />
<pre>
<strong>Input:</strong> flowers = [[1,6],[3,7],[9,12],[4,13]], poeple = [2,3,7,11]
<strong>Output:</strong> [1,2,2,2]
<strong>Explanation: </strong>The figure above shows the times when the flowers are in full bloom and when the people arrive.
For each person, we return the number of flowers in full bloom during their arrival.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/03/02/ex2new.jpg" style="width: 450px; height: 195px;" />
<pre>
<strong>Input:</strong> flowers = [[1,10],[3,3]], poeple = [3,3,2]
<strong>Output:</strong> [2,2,1]
<strong>Explanation:</strong> The figure above shows the times when the flowers are in full bloom and when the people arrive.
For each person, we return the number of flowers in full bloom during their arrival.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= flowers.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>flowers[i].length == 2</code></li>
	<li><code>1 &lt;= start<sub>i</sub> &lt;= end<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= people.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= people[i] &lt;= 10<sup>9</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
    map<int, int> flowersAbs;
    for(const auto &flower : flowers) {
      flowersAbs[flower[0]] += 1;
      flowersAbs[flower[1] + 1] -= 1;
    }
    vector<int> indice(people.size());
    for(int i = 1; i < people.size(); ++i) {
      indice[i] = i;
    }
    sort(indice.begin(), indice.end(), [&](int a, int b) {
      return people[a] < people[b];
    });
    vector<int> answer(people.size());

    auto it = flowersAbs.begin();
    int flower = 0;
    for(auto index : indice) {
      while(it != flowersAbs.end() && it->first <= people[index]) {
        flower += it->second;
        ++it;
      }
      answer[index] = flower;
    }

    return answer;
  }
};

// Accepted
// 52/52 cases passed (284 ms)
// Your runtime beats 31.94 % of cpp submissions
// Your memory usage beats 60.07 % of cpp submissions (87 MB)
```
