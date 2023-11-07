+++
updated = 2023-11-07T08:45:23+08:00
title = "2023-11-07 Daily Challenge"
path = "2023-11-07-Daily-Challenge"
date = 2023-11-07T08:45:23+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/eliminate-maximum-number-of-monsters/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 7

## Description

**Eliminate Maximum Number of Monsters**

<p>You are playing a video game where you are defending your city from a group of <code>n</code> monsters. You are given a <strong>0-indexed</strong> integer array <code>dist</code> of size <code>n</code>, where <code>dist[i]</code> is the <strong>initial distance</strong> in kilometers of the <code>i<sup>th</sup></code> monster from the city.</p>

<p>The monsters walk toward the city at a <strong>constant</strong> speed. The speed of each monster is given to you in an integer array <code>speed</code> of size <code>n</code>, where <code>speed[i]</code> is the speed of the <code>i<sup>th</sup></code> monster in kilometers per minute.</p>

<p>You have a weapon that, once fully charged, can eliminate a <strong>single</strong> monster. However, the weapon takes <strong>one minute</strong> to charge. The weapon is fully charged at the very start.</p>

<p>You lose when any monster reaches your city. If a monster reaches the city at the exact moment the weapon is fully charged, it counts as a <strong>loss</strong>, and the game ends before you can use your weapon.</p>

<p>Return <em>the <strong>maximum</strong> number of monsters that you can eliminate before you lose, or </em><code>n</code><em> if you can eliminate all the monsters before they reach the city.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> dist = [1,3,4], speed = [1,1,1]
<strong>Output:</strong> 3
<strong>Explanation:</strong>
In the beginning, the distances of the monsters are [1,3,4]. You eliminate the first monster.
After a minute, the distances of the monsters are [X,2,3]. You eliminate the second monster.
After a minute, the distances of the monsters are [X,X,2]. You eliminate the thrid monster.
All 3 monsters can be eliminated.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> dist = [1,1,2,3], speed = [1,1,1,1]
<strong>Output:</strong> 1
<strong>Explanation:</strong>
In the beginning, the distances of the monsters are [1,1,2,3]. You eliminate the first monster.
After a minute, the distances of the monsters are [X,0,1,2], so you lose.
You can only eliminate 1 monster.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> dist = [3,2,4], speed = [5,3,2]
<strong>Output:</strong> 1
<strong>Explanation:</strong>
In the beginning, the distances of the monsters are [3,2,4]. You eliminate the first monster.
After a minute, the distances of the monsters are [X,0,2], so you lose.
You can only eliminate 1 monster.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == dist.length == speed.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= dist[i], speed[i] &lt;= 10<sup>5</sup></code></li>
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
  int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
    vector<int> arriveTime(dist.size());
    for(int i = 0; i < dist.size(); ++i) {
      arriveTime[i] = ceil(1.0 * dist[i] / speed[i]);
    }

    sort(arriveTime.begin(), arriveTime.end());
    for(int i = 1; i < arriveTime.size(); ++i) {
      if(arriveTime[i] <= i) return i;
    }
    return dist.size();
  }
};

// Accepted
// 131/131 cases passed (76 ms)
// Your runtime beats 99.73 % of cpp submissions
// Your memory usage beats 86.67 % of cpp submissions (83.2 MB)
```
