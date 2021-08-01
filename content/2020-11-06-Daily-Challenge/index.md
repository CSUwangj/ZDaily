+++
title = "2020-11-06 Daily-Challenge"
path = "2020-11-06-Daily-Challenge"
date = 2020-11-06 07:49:21+08:00
updated = 2020-11-06 21:40:14+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done *Bitwise ORs of Subarrays* on [leetcode](https://leetcode.com/problems/bitwise-ors-of-subarrays/) and leetcode's [November LeetCoding Challenge](https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/564/week-1-november-1st-november-7th/3521/) with `cpp`.

<!-- more -->

# Bitwise ORs of Subarrays

## Description

We have an array `A` of non-negative integers.

For every (contiguous) subarray `B = [A[i], A[i+1], ..., A[j]]` (with `i <= j`), we take the bitwise OR of all the elements in `B`, obtaining a result `A[i] | A[i+1] | ... | A[j]`.

Return the number of possible results. (Results that occur more than once are only counted once in the final answer.)

**Example 1:**

```
Input: [0]
Output: 1
Explanation: 
There is only one possible result: 0.
```

**Example 2:**

```
Input: [1,1,2]
Output: 3
Explanation: 
The possible subarrays are [1], [1], [2], [1, 1], [1, 2], [1, 1, 2].
These yield the results 1, 1, 2, 1, 3, 3.
There are 3 unique values, so the answer is 3.
```

**Example 3:**

```
Input: [1,2,4]
Output: 6
Explanation: 
The possible results are 1, 2, 3, 4, 6, and 7.
```

**Note:**

1. `1 <= A.length <= 50000`
2. `0 <= A[i] <= 10^9`

## Solution

nothing to say

``` cpp
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> cur[2];
        unordered_set<int> answer;
        cur[0].insert(0);
        for(int i = 0; i < A.size(); ++i) {
            cur[1].clear();
            for(auto num : cur[0]) {
                cur[1].insert(num|A[i]);
            }
            cur[1].insert(A[i]);
            cur[0] = cur[1];
            answer.merge(cur[1]);
        }
        return answer.size();
    }
};
```

# November LeetCoding Challenge 6

## Description

**Find the Smallest Divisor Given a Threshold**

Given an array of integers `nums` and an integer `threshold`, we will choose a positive integer divisor and divide all the array by it and sum the result of the division. Find the **smallest** divisor such that the result mentioned above is less than or equal to `threshold`.

Each result of division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

It is guaranteed that there will be an answer.

**Example 1:**

```
Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
If the divisor is 4 we can get a sum to 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 
```

**Example 2:**

```
Input: nums = [2,3,5,7,11], threshold = 11
Output: 3
```

**Example 3:**

```
Input: nums = [19], threshold = 5
Output: 4
```

**Constraints:**

- `1 <= nums.length <= 5 * 10^4`
- `1 <= nums[i] <= 10^6`
- `nums.length <= threshold <= 10^6`

## Solution

parity

``` cpp
class Solution {
  bool satisfied(vector<int> &nums, int threshold, double divisor) {
    int sum = 0;
    for(auto n : nums) {
      sum += ceil(n/divisor);
    }
    return sum <= threshold;
  }
public:
  int smallestDivisor(vector<int> &nums, int threshold) {
    int start = 1, end = INT_MAX-1;
    while(start < end) {
      int mid = (end + start) / 2;
      if(satisfied(nums, threshold, mid)) end = mid;
      else start = mid + 1; 
    }
    return start;
  }
};
```
