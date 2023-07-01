+++
updated = 2023-07-01T13:40:08+08:00
title = "2023-07-01 Daily Challenge"
path = "2023-07-01-Daily-Challenge"
date = 2023-07-01T13:40:08+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/fair-distribution-of-cookies/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 1

## Description

**Fair Distribution of Cookies**

<p>You are given an integer array <code>cookies</code>, where <code>cookies[i]</code> denotes the number of cookies in the <code>i<sup>th</sup></code> bag. You are also given an integer <code>k</code> that denotes the number of children to distribute <strong>all</strong> the bags of cookies to. All the cookies in the same bag must go to the same child and cannot be split up.</p>

<p>The <strong>unfairness</strong> of a distribution is defined as the <strong>maximum</strong> <strong>total</strong> cookies obtained by a single child in the distribution.</p>

<p>Return <em>the <strong>minimum</strong> unfairness of all distributions</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> cookies = [8,15,10,20,8], k = 2
<strong>Output:</strong> 31
<strong>Explanation:</strong> One optimal distribution is [8,15,8] and [10,20]
- The 1<sup>st</sup> child receives [8,15,8] which has a total of 8 + 15 + 8 = 31 cookies.
- The 2<sup>nd</sup> child receives [10,20] which has a total of 10 + 20 = 30 cookies.
The unfairness of the distribution is max(31,30) = 31.
It can be shown that there is no distribution with an unfairness less than 31.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> cookies = [6,1,3,2,2,4,1,2], k = 3
<strong>Output:</strong> 7
<strong>Explanation:</strong> One optimal distribution is [6,1], [3,2,2], and [4,1,2]
- The 1<sup>st</sup> child receives [6,1] which has a total of 6 + 1 = 7 cookies.
- The 2<sup>nd</sup> child receives [3,2,2] which has a total of 3 + 2 + 2 = 7 cookies.
- The 3<sup>rd</sup> child receives [4,1,2] which has a total of 4 + 1 + 2 = 7 cookies.
The unfairness of the distribution is max(7,7,7) = 7.
It can be shown that there is no distribution with an unfairness less than 7.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= cookies.length &lt;= 8</code></li>
	<li><code>1 &lt;= cookies[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>2 &lt;= k &lt;= cookies.length</code></li>
</ul>

## Solution

``` cpp
class Solution {
  void solve(
    int position,
    int k,
    int &answer,
    vector<int> &children,
    const vector<int>& cookies
  ) {
    int current = *max_element(children.begin(), children.end());
    if(position == cookies.size()) {
      answer = min(answer, current);
      return;
    }
    if(answer <= current) {
      return;
    }

    for(int i = 0; i < k; ++i) {
      children[i] += cookies[position];
      solve(position + 1, k, answer, children, cookies);
      children[i] -= cookies[position];
    }
  }
public:
  int distributeCookies(vector<int>& cookies, int k) {
    vector<int> children(k);
    int answer = INT_MAX;
    solve(0, k, answer, children, cookies);

    return answer;
  }
};

// Accepted
// 38/38 cases passed (883 ms)
// Your runtime beats 67.14 % of cpp submissions
// Your memory usage beats 23.11 % of cpp submissions (6.9 MB)
```
