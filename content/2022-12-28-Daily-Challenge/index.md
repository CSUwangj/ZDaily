+++
updated = 2022-12-28T15:08:02+08:00
title = "2022-12-28 Daily Challenge"
path = "2022-12-28-Daily-Challenge"
date = 2022-12-28T15:08:02+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/remove-stones-to-minimize-the-total/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 28

## Description

**Remove Stones to Minimize the Total**

<p>You are given a <strong>0-indexed</strong> integer array <code>piles</code>, where <code>piles[i]</code> represents the number of stones in the <code>i<sup>th</sup></code> pile, and an integer <code>k</code>. You should apply the following operation <strong>exactly</strong> <code>k</code> times:</p>

<ul>
	<li>Choose any <code>piles[i]</code> and <strong>remove</strong> <code>floor(piles[i] / 2)</code> stones from it.</li>
</ul>

<p><strong>Notice</strong> that you can apply the operation on the <strong>same</strong> pile more than once.</p>

<p>Return <em>the <strong>minimum</strong> possible total number of stones remaining after applying the </em><code>k</code><em> operations</em>.</p>

<p><code>floor(x)</code> is the <b>greatest</b> integer that is <strong>smaller</strong> than or <strong>equal</strong> to <code>x</code> (i.e., rounds <code>x</code> down).</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> piles = [5,4,9], k = 2
<strong>Output:</strong> 12
<strong>Explanation:</strong>&nbsp;Steps of a possible scenario are:
- Apply the operation on pile 2. The resulting piles are [5,4,<u>5</u>].
- Apply the operation on pile 0. The resulting piles are [<u>3</u>,4,5].
The total number of stones in [3,4,5] is 12.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> piles = [4,3,6,7], k = 3
<strong>Output:</strong> 12
<strong>Explanation:</strong>&nbsp;Steps of a possible scenario are:
- Apply the operation on pile 2. The resulting piles are [4,3,<u>3</u>,7].
- Apply the operation on pile 3. The resulting piles are [4,3,3,<u>4</u>].
- Apply the operation on pile 0. The resulting piles are [<u>2</u>,3,3,4].
The total number of stones in [2,3,3,4] is 12.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= piles.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= piles[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int minStoneSum(vector<int>& piles, int k) {
    map<int, int, greater<int>> count;
    int answer = 0;
    for(auto pile : piles) {
      count[pile] += 1;
      answer += pile;
    }
    while(k) {
      auto it = count.begin();
      if(it->first < 2) break;
      if(k > it->second) {
        answer -= (it->first / 2) * it->second;
        count[it->first - it->first / 2] += it->second;
        k -= it->second;
        count.erase(it);
      } else {
        answer -= (it->first / 2) * k;
        k = 0;
      }
    }
    return answer;
  }
};

// Accepted
// 59/59 cases passed (352 ms)
// Your runtime beats 99.48 % of cpp submissions
// Your memory usage beats 5 % of cpp submissions (107.8 MB)
```
