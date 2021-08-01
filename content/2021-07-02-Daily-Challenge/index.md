+++
title = "2021-07-02 Daily-Challenge"
path = "2021-07-02-Daily-Challenge"
date = 2021-07-02 18:09:53+08:00
updated = 2021-07-02 18:37:17+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Capacity To Ship Packages Within D Days](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/) and leetcode's [July LeetCoding Challenge](https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/608/week-1-july-1st-july-7th/3800/) with `cpp`.

<!-- more -->

# Capacity To Ship Packages Within D Days

## Description

<p>A conveyor belt has packages that must be shipped from one port to another within <code>days</code> days.</p>

<p>The <code>i<sup>th</sup></code> package on the conveyor belt has a weight of <code>weights[i]</code>. Each day, we load the ship with packages on the conveyor belt (in the order given by <code>weights</code>). We may not load more weight than the maximum weight capacity of the ship.</p>

<p>Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within <code>days</code> days.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><code><strong>Input:</strong> weights = [1,2,3,4,5,6,7,8,9,10], days = 5
<strong>Output:</strong> 15
<strong>Explanation:</strong> A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
</code></pre>

<p><strong>Example 2:</strong></p>

<pre><code><strong>Input:</strong> weights = [3,2,2,4,1,4], days = 3
<strong>Output:</strong> 6
<strong>Explanation:</strong> A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4
</code></pre>

<p><strong>Example 3:</strong></p>

<pre><code><strong>Input:</strong> weights = [1,2,3,1,1], days = 4
<strong>Output:</strong> 3
<strong>Explanation:</strong>
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1
</code></pre>

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
```

# July LeetCoding Challenge 2

## Description

**Find K Closest Elements**

Given a **sorted** integer array `arr`, two integers `k` and `x`, return the `k` closest integers to `x` in the array. The result should also be sorted in ascending order.

An integer `a` is closer to `x` than an integer `b` if:

- `|a - x| < |b - x|`, or
- `|a - x| == |b - x|` and `a < b`

 

**Example 1:**

```
Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
```

**Example 2:**

```
Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]
```

 

**Constraints:**

- `1 <= k <= arr.length`
- `1 <= arr.length <= 10^4`
- `arr` is sorted in **ascending** order.
- `-10^4 <= arr[i], x <= 10^4`

## Solution

``` cpp
auto _ = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int len = arr.size();
    if(k == len) return arr;
    int pos = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    if(pos == 0) return vector<int>(arr.begin(), arr.begin() + k);
    if(pos == len) return vector<int>(arr.end() - k, arr.end());
    int start = pos;
    int sz = (arr[pos] == x);
    while(sz < k) {
      if(start == 0) break;
      if(start + sz == len) {
        start = len - k;
        break;
      }
      if(x - arr[start - 1] <= arr[start + sz] - x) {
        start -= 1;
      }
      sz += 1;
    }
    return vector<int>(arr.begin() + start, arr.begin() + start + k);
  }
};
```
