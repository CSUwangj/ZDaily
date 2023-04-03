+++
updated = 2023-04-03T15:24:18+08:00
title = "2023-04-03 Daily Challenge"
path = "2023-04-03-Daily-Challenge"
date = 2023-04-03T15:24:18+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/boats-to-save-people/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 3

## Description

**Boats to Save People**

<p>You are given an array <code>people</code> where <code>people[i]</code> is the weight of the <code>i<sup>th</sup></code> person, and an <strong>infinite number of boats</strong> where each boat can carry a maximum weight of <code>limit</code>. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most <code>limit</code>.</p>

<p>Return <em>the minimum number of boats to carry every given person</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> people = [1,2], limit = 3
<strong>Output:</strong> 1
<strong>Explanation:</strong> 1 boat (1, 2)
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> people = [3,2,2,1], limit = 3
<strong>Output:</strong> 3
<strong>Explanation:</strong> 3 boats (1, 2), (2) and (3)
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> people = [3,5,3,4], limit = 5
<strong>Output:</strong> 4
<strong>Explanation:</strong> 4 boats (3), (3), (4), (5)
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= people.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= people[i] &lt;= limit &lt;= 3 * 10<sup>4</sup></code></li>
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
  int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(), people.end());
    int len = people.size();
    if(people.back() * 2 <= limit) return (len + 1) / 2;
    if(people.front() * 2 > limit) return len;
    int ed = len - 1;
    int st = 0;
    int answer = 0;
    while(st < ed) {
      if(people[st] + people[ed] > limit) {
        ed -= 1;
      } else {
        ed -= 1;
        st += 1;
      }
      answer += 1;
    }
    answer += (st == ed);
    return answer;
  }
};


// Accepted
// 78/78 cases passed (68 ms)
// Your runtime beats 97.18 % of cpp submissions
// Your memory usage beats 57.42 % of cpp submissions (42 MB)
```
