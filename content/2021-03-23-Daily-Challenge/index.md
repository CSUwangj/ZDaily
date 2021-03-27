+++
title = "2021-03-23 Daily-Challenge"
path = "2021-03-23-Daily-Challenge"
date = 2021-03-23 16:33:00+08:00
updated = 2021-03-23 18:06:27+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Search Insert Position](https://leetcode.com/problems/search-insert-position/) and leetcode's [March LeetCoding Challenge](https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/591/week-4-march-22nd-march-28th/3682/) with `cpp`.

<!-- more -->

# Search Insert Position

## Description

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

 

**Example 1:**

```
Input: nums = [1,3,5,6], target = 5
Output: 2
```

**Example 2:**

```
Input: nums = [1,3,5,6], target = 2
Output: 1
```

**Example 3:**

```
Input: nums = [1,3,5,6], target = 7
Output: 4
```

**Example 4:**

```
Input: nums = [1,3,5,6], target = 0
Output: 0
```

**Example 5:**

```
Input: nums = [1], target = 0
Output: 0
```

 

**Constraints:**

- `1 <= nums.length <= 10^4`
- `-10^4 <= nums[i] <= 10^4`
- `nums` contains **distinct** values sorted in **ascending** order.
- `-10^4 <= target <= 10^4`

## Solution

``` cpp
class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
  }
};
```

# March LeetCoding Challenge23

**3Sum With Multiplicity**

## Description

Given an integer array arr, and an integer target, return the number of tuples i, j, k such that i < j < k and arr[i] + arr[j] + arr[k] == target.

As the answer can be very large, return it modulo 109 + 7.

 

Example 1:

Input: arr = [1,1,2,2,3,3,4,4,5,5], target = 8
Output: 20
Explanation: 
Enumerating by the values (arr[i], arr[j], arr[k]):
(1, 2, 5) occurs 8 times;
(1, 3, 4) occurs 8 times;
(2, 2, 4) occurs 2 times;
(2, 3, 3) occurs 2 times.
Example 2:

Input: arr = [1,1,2,2,2,2], target = 5
Output: 12
Explanation: 
arr[i] = 1, arr[j] = arr[k] = 2 occurs 12 times:
We choose one 1 from [1,1] in 2 ways,
and two 2s from [2,2,2,2] in 6 ways.
 

Constraints:

3 <= arr.length <= 3000
0 <= arr[i] <= 100
0 <= target <= 300

## Solution

``` cpp
const int MOD = 1e9 + 7;
// need is too small to use this to calculate multiplicative inverse
// constexpr inline int qpow(long long a) {
//   int ans = 1;
//   int b = MOD - 2;
//   a = (a % MOD + MOD) % MOD;
//   for (; b; b >>= 1) {
//     if (b & 1) ans = (a * ans) % p;
//     a = (a * a) % MOD;
//   }
//   return ans;
// }
constexpr int pick(int total, int need) {
  if(total < need) return 0;
  long long answer = 1;
  for(int i = 1; i <= need; ++i) {
    answer *= (total + 1 - i);
    answer /= i;
    answer %= MOD;
  }
  return answer;
}

class Solution {
public:
  int threeSumMulti(vector<int>& arr, int target) {
    map<int, int> count;
    for(auto num : arr) count[num] += 1;
    
    long long answer = 0;
    for(auto it = count.begin(); it != count.end(); ++it) {
      for(auto jt = it; jt != count.end(); ++jt) {
        int rest = target - it->first - jt->first;
        if(rest < jt->first || !count.count(rest)) continue;
        if(it->first == jt->first && it->first == rest) {
          answer += pick(it->second, 3);
        } else if(it->first == jt->first) {
          answer += pick(it->second, 2) * count[rest];
        } else if(jt->first == rest) {
          answer += pick(jt->second, 2) * it->second;
        } else {
          answer += it->second * jt->second * count[rest];
        }
        answer %= MOD;
      }
    }
    return answer;
  }
};
```
