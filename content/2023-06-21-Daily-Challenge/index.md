+++
updated = 2023-06-21T12:45:13+08:00
title = "2023-06-21 Daily Challenge"
path = "2023-06-21-Daily-Challenge"
date = 2023-06-21T12:45:13+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/minimum-cost-to-make-array-equal/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 21

## Description

**Minimum Cost to Make Array Equal**

<p>You are given two <strong>0-indexed</strong> arrays <code>nums</code> and <code>cost</code> consisting each of <code>n</code> <strong>positive</strong> integers.</p>

<p>You can do the following operation <strong>any</strong> number of times:</p>

<ul>
	<li>Increase or decrease <strong>any</strong> element of the array <code>nums</code> by <code>1</code>.</li>
</ul>

<p>The cost of doing one operation on the <code>i<sup>th</sup></code> element is <code>cost[i]</code>.</p>

<p>Return <em>the <strong>minimum</strong> total cost such that all the elements of the array </em><code>nums</code><em> become <strong>equal</strong></em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,3,5,2], cost = [2,3,1,14]
<strong>Output:</strong> 8
<strong>Explanation:</strong> We can make all the elements equal to 2 in the following way:
- Increase the 0<sup>th</sup> element one time. The cost is 2.
- Decrease the 1<sup><span style="font-size: 10.8333px;">st</span></sup> element one time. The cost is 3.
- Decrease the 2<sup>nd</sup> element three times. The cost is 1 + 1 + 1 = 3.
The total cost is 2 + 3 + 3 = 8.
It can be shown that we cannot make the array equal with a smaller cost.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,2,2,2,2], cost = [4,2,8,1,3]
<strong>Output:</strong> 0
<strong>Explanation:</strong> All the elements are already equal, so no operations are needed.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length == cost.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i], cost[i] &lt;= 10<sup>6</sup></code></li>
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
  long long minCost(vector<int>& nums, vector<int>& cost) {
    int len = nums.size();
    vector<pair<int, int>> pairs;
    pairs.reserve(len);
    for(int i = 0; i < len; ++i) {
      pairs.push_back({nums[i], cost[i]});
    }
    sort(pairs.begin(), pairs.end());

    long long costs = 0;
    long long addOneCost = pairs[0].second;
    long long minusOneCost = 0;
    for(int i = len - 1; i > 0; --i) {
      costs += 1LL * (pairs[i].first - pairs[0].first) * (pairs[i].second);
      minusOneCost += pairs[i].second;
    }
    long long answer = costs;
    for(int i = 1; i < len; addOneCost += pairs[i].second, minusOneCost -= pairs[i].second, ++i) {
      if(pairs[i].first == pairs[i - 1].first) {
        continue;
      }
      int diff = pairs[i].first - pairs[i - 1].first;
      costs += 1LL * diff * addOneCost;
      costs -= 1LL * diff * minusOneCost;
      answer = min(costs, answer);
    }

    return answer;
  }
};

// Accepted
// 48/48 cases passed (92 ms)
// Your runtime beats 89.42 % of cpp submissions
// Your memory usage beats 47.08 % of cpp submissions (40.8 MB)
```
