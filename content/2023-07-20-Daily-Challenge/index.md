+++
updated = 2023-07-20T11:40:27+08:00
title = "2023-07-20 Daily Challenge"
path = "2023-07-20-Daily-Challenge"
date = 2023-07-20T11:40:27+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/asteroid-collision/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 20

## Description

**Asteroid Collision**

<p>We are given an array <code>asteroids</code> of integers representing asteroids in a row.</p>

<p>For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.</p>

<p>Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> asteroids = [5,10,-5]
<strong>Output:</strong> [5,10]
<strong>Explanation:</strong> The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> asteroids = [8,-8]
<strong>Output:</strong> []
<strong>Explanation:</strong> The 8 and -8 collide exploding each other.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> asteroids = [10,2,-5]
<strong>Output:</strong> [10]
<strong>Explanation:</strong> The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= asteroids.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-1000 &lt;= asteroids[i] &lt;= 1000</code></li>
	<li><code>asteroids[i] != 0</code></li>
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
  vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> s;
    s.push_back(asteroids[0]);
    for(int i = 1; i < asteroids.size(); ++i) {
      if(s.empty() || s.back() < 0) {
        s.push_back(asteroids[i]);
        continue;
      }
      if(asteroids[i] > 0) {
        s.push_back(asteroids[i]);
        continue;
      }
      while(s.size() && s.back() > 0 && -asteroids[i] > s.back()) s.pop_back();
      if(s.empty() || s.back() < 0) s.push_back(asteroids[i]);
      else if(s.size() && -asteroids[i] == s.back()) s.pop_back();
    }
    return s;
  }
};

// Accepted
// 275/275 cases passed (15 ms)
// Your runtime beats 71.71 % of cpp submissions
// Your memory usage beats 81.53 % of cpp submissions (17.5 MB)
```
