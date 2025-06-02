+++
updated = 2025-06-03T05:20:33+08:00
title = "2025-06-02 Daily Challenge"
path = "2025-06-02-Daily-Challenge"
date = 2025-06-03T05:20:33+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/candy/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 2

## Description

**Candy**

<p>There are <code>n</code> children standing in a line. Each child is assigned a rating value given in the integer array <code>ratings</code>.</p>

<p>You are giving candies to these children subjected to the following requirements:</p>

<ul>
	<li>Each child must have at least one candy.</li>
	<li>Children with a higher rating get more candies than their neighbors.</li>
</ul>

<p>Return <em>the minimum number of candies you need to have to distribute the candies to the children</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> ratings = [1,0,2]
<strong>Output:</strong> 5
<strong>Explanation:</strong> You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> ratings = [1,2,2]
<strong>Output:</strong> 4
<strong>Explanation:</strong> You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == ratings.length</code></li>
	<li><code>1 &lt;= n &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= ratings[i] &lt;= 2 * 10<sup>4</sup></code></li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
using pi = pair<int, int>;
int cd[20000];
class Solution {
public:
  int candy(vector<int>& ratings) {
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    int len = ratings.size();
    for(int i = 0; i < len; ++i) {
      pq.push({ratings[i], i});
      cd[i] = 0;
    }
    while(pq.size()) {
      auto [rating, pos] = pq.top();
      pq.pop();
      if(cd[pos]) continue;
      cd[pos] = 1;
      for(int i = pos + 1; i < len; ++i) {
        if(ratings[i] <= ratings[i - 1]) break;
        if(cd[i] > cd[i - 1] + 1) break;
        cd[i] = cd[i - 1] + 1;
      }
      for(int i = pos - 1; i >= 0; --i) {
        if(ratings[i] <= ratings[i + 1]) break;
        if(cd[i] > cd[i + 1] + 1) break;
        cd[i] = cd[i + 1] + 1;
      }
    }
    int answer = 0;
    for(int i = 0; i < len; ++i) {
      // cout << cd[i] << ' ';
      answer += cd[i];
    }
    // cout << endl;
    return answer;
  }
};

// Accepted
// 49/49 cases passed (13 ms)
// Your runtime beats 8.91 % of cpp submissions
// Your memory usage beats 5.1 % of cpp submissions (25.2 MB)
```
