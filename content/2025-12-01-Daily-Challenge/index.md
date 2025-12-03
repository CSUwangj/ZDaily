+++
updated = 2025-12-01T10:55:14+01:00
title = "2025-12-01 Daily Challenge"
path = "2025-12-01-Daily-Challenge"
date = 2025-12-01T10:55:14+01:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/maximum-running-time-of-n-computers/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 1

## Description

**Maximum Running Time of N Computers**

<p>You have <code>n</code> computers. You are given the integer <code>n</code> and a <strong>0-indexed</strong> integer array <code>batteries</code> where the <code>i<sup>th</sup></code> battery can <strong>run</strong> a computer for <code>batteries[i]</code> minutes. You are interested in running <strong>all</strong> <code>n</code> computers <strong>simultaneously</strong> using the given batteries.</p>

<p>Initially, you can insert <strong>at most one battery</strong> into each computer. After that and at any integer time moment, you can remove a battery from a computer and insert another battery <strong>any number of times</strong>. The inserted battery can be a totally new battery or a battery from another computer. You may assume that the removing and inserting processes take no time.</p>

<p>Note that the batteries cannot be recharged.</p>

<p>Return <em>the <strong>maximum</strong> number of minutes you can run all the </em><code>n</code><em> computers simultaneously.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" style="width: 762px; height: 150px;" src="https://assets.leetcode.com/uploads/2022/01/06/example1-fit.png">
<pre><strong>Input:</strong> n = 2, batteries = [3,3,3]
<strong>Output:</strong> 4
<strong>Explanation:</strong> 
Initially, insert battery 0 into the first computer and battery 1 into the second computer.
After two minutes, remove battery 1 from the second computer and insert battery 2 instead. Note that battery 1 can still run for one minute.
At the end of the third minute, battery 0 is drained, and you need to remove it from the first computer and insert battery 1 instead.
By the end of the fourth minute, battery 1 is also drained, and the first computer is no longer running.
We can run the two computers simultaneously for at most 4 minutes, so we return 4.

</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" style="width: 629px; height: 150px;" src="https://assets.leetcode.com/uploads/2022/01/06/example2.png">
<pre><strong>Input:</strong> n = 2, batteries = [1,1,1,1]
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
Initially, insert battery 0 into the first computer and battery 2 into the second computer. 
After one minute, battery 0 and battery 2 are drained so you need to remove them and insert battery 1 into the first computer and battery 3 into the second computer. 
After another minute, battery 1 and battery 3 are also drained so the first and second computers are no longer running.
We can run the two computers simultaneously for at most 2 minutes, so we return 2.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= batteries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= batteries[i] &lt;= 10<sup>9</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
  using ll = long long;
public:
  ll maxRunTime(int n, vector<int>& batteries) {
    ll low = 1;
    ll high = accumulate(batteries.begin(), batteries.end(), 0LL) / n;

    while(low < high) {
      ll mid = (low + high + 1) / 2;
      ll time = 0;
      for(auto battery : batteries) {
        time += min<ll>(battery, mid);
      }

      if(mid * n <= time) {
        low = mid;
      } else {
        high = mid - 1;
      }
    }

    return low;
  }
};

// Accepted
// 52/52 cases passed (140 ms)
// Your runtime beats 99.64 % of cpp submissions
// Your memory usage beats 71.58 % of cpp submissions (55.7 MB)
```
