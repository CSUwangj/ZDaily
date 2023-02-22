+++
updated = 2023-02-22T08:54:28+08:00
title = "2023-02-22 Daily Challenge"
path = "2023-02-22-Daily-Challenge"
date = 2023-02-22T08:54:28+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 22

## Description

**Capacity To Ship Packages Within D Days**

<p>A conveyor belt has packages that must be shipped from one port to another within <code>days</code> days.</p>

<p>The <code>i<sup>th</sup></code> package on the conveyor belt has a weight of <code>weights[i]</code>. Each day, we load the ship with packages on the conveyor belt (in the order given by <code>weights</code>). We may not load more weight than the maximum weight capacity of the ship.</p>

<p>Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within <code>days</code> days.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> weights = [1,2,3,4,5,6,7,8,9,10], days = 5
<strong>Output:</strong> 15
<strong>Explanation:</strong> A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> weights = [3,2,2,4,1,4], days = 3
<strong>Output:</strong> 6
<strong>Explanation:</strong> A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> weights = [1,2,3,1,1], days = 4
<strong>Output:</strong> 3
<strong>Explanation:</strong>
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= days &lt;= weights.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= weights[i] &lt;= 500</code></li>
</ul>

## Solution

``` cpp
class Solution {
  bool validate(vector<int> &weights, int days, int capacity) {
    int cur = 0;
    int ships = 1;
    for(auto w : weights) {
      if(cur + w > capacity) {
        cur = w;
        ships += 1;
      } else {
        cur += w;
      }
      if(ships > days) return false;
    }
    // cout << capacity << ' ' << days << endl;
    return true;
  }
public:
  int shipWithinDays(vector<int>& weights, int days) {
    int sum = accumulate(weights.begin(), weights.end(), 0);
    int maxW = *max_element(weights.begin(), weights.end());
    int len = weights.size();
    if(days >= len) return maxW;
    if(days == 1) return sum;
    int low = maxW;
    int high = sum;
    while(low < high) {
      int mid = (low + high) >> 1;
      if(validate(weights, days, mid)) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    return low;
  }
};

// Accepted
// 85/85 cases passed (61 ms)
// Your runtime beats 68.27 % of cpp submissions
// Your memory usage beats 77.07 % of cpp submissions (26.1 MB)
```
