+++
title = "2020-10-28 Daily-Challenge"
path = "2020-10-28-Daily-Challenge"
date = 2020-10-28 00:38:47+08:00
updated = 2020-10-28 19:32:58+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done *Count Primes* on [leetcode](https://leetcode.com/problems/count-primes/) and leetcode's [October LeetCoding Challenge](https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/562/week-4-october-22nd-october-28th/3510/) with `cpp`.

<!-- more -->

# Count Primes

## Description

Count the number of prime numbers less than a non-negative number, `n`.

**Example 1:**

```
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
```

**Example 2:**

```
Input: n = 0
Output: 0
```

**Example 3:**

```
Input: n = 1
Output: 0
```

**Constraints:**

- `0 <= n <= 5 * 106`

## Solution

sieve of Eratosthenes

``` cpp
class Solution {
public:
  int countPrimes(int n) {
    if(n < 3) return 0;
    int ans = 0;
    vector<bool> isPrime(n, true);
    for(int i = 2; i*i < n; ++i) {
      if(!isPrime[i]) continue;
      for(int j = i*i; j < n; j += i) {
        isPrime[j] = false;
      }
    }
    for(int i = 2; i < n; ++i) {
      ans += isPrime[i];
    }
    return ans;
  }
};
```

# October LeetCoding Challenge28

## Description

**Summary Ranges**

## Description

You are given a **sorted unique** integer array `nums`.

Return *the **smallest sorted** list of ranges that **cover all the numbers in the array exactly***. That is, each element of `nums` is covered by exactly one of the ranges, and there is no integer `x` such that `x` is in one of the ranges but not in `nums`.

Each range `[a,b]` in the list should be output as:

- `"a->b"` if `a != b`
- `"a"` if `a == b`

**Example 1:**

```
Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"
```

**Example 2:**

```
Input: nums = [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: The ranges are:
[0,0] --> "0"
[2,4] --> "2->4"
[6,6] --> "6"
[8,9] --> "8->9"
```

**Example 3:**

```
Input: nums = []
Output: []
```

**Example 4:**

```
Input: nums = [-1]
Output: ["-1"]
```

**Example 5:**

```
Input: nums = [0]
Output: ["0"]
```

**Constraints:**

- `0 <= nums.length <= 20`
- `-231 <= nums[i] <= 231 - 1`
- All the values of `nums` are **unique**.

## Solution

nothing to say

``` cpp
class Solution {
public:
  vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ans;
    if(nums.empty()) return ans;
    int begin = nums[0], end = nums[0];
    for(int i = 1; i < nums.size(); ++i) {
      if(nums[i]-1 != end) {
        string tmp = to_string(begin);
        if(end != begin) tmp += "->"+to_string(end);
        ans.push_back(tmp);
        begin = nums[i];
        end = nums[i];
      } else {
        end = nums[i];
      }
    }
    string tmp = to_string(begin);
    if(end != begin) tmp += "->"+to_string(end);
    ans.push_back(tmp);
    return ans;
  }
};
```
