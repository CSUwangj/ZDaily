+++
title = "2022-01-20 Daily-Challenge"
path = "2022-01-20-Daily-Challenge"
date = 2022-01-20 21:10:00+08:00
updated = 2022-01-20 21:19:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/koko-eating-bananas/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 20

## Description

**Koko Eating Bananas**

Koko loves to eat bananas. There are `n` piles of bananas, the `ith` pile has `piles[i]` bananas. The guards have gone and will come back in `h` hours.

Koko can decide her bananas-per-hour eating speed of `k`. Each hour, she chooses some pile of bananas and eats `k` bananas from that pile. If the pile has less than `k` bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return *the minimum integer* `k` *such that she can eat all the bananas within* `h` *hours*.

 

**Example 1:**

```
Input: piles = [3,6,7,11], h = 8
Output: 4
```

**Example 2:**

```
Input: piles = [30,11,23,4,20], h = 5
Output: 30
```

**Example 3:**

```
Input: piles = [30,11,23,4,20], h = 6
Output: 23
```

 

**Constraints:**

- `1 <= piles.length <= 10^4`
- `piles.length <= h <= 10^9`
- `1 <= piles[i] <= 10^9`


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  int time(const vector<int> &piles, int eat) {
    int result = 0;
    for(auto pile : piles) {
      if(pile % eat) {
        result += pile / eat + 1;
      } else {
        result += pile / eat;
      }
    }
    return result;
  }
public:
  int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1;
    int high = *max_element(piles.begin(), piles.end());
    while(low < high) {
      int mid = (low + high) >> 1;
      if(time(piles, mid) > h) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return low;
  }
};

// Accepted
// 119/119 cases passed (47 ms)
// Your runtime beats 65.52 % of cpp submissions
// Your memory usage beats 53.71 % of cpp submissions (18.9 MB)
```
