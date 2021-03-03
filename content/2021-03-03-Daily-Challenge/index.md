+++
title = "2021-03-03 Daily-Challenge"
path = "2021-03-03-Daily-Challenge"
date = 2021-03-03 18:07:32+08:00
updated = 2021-03-03 18:32:54+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Closest Divisors](https://leetcode.com/problems/closest-divisors/) and leetcode's [March LeetCoding Challenge](https://leetcode.com/explore/featured/card/march-leetcoding-challenge-2021/588/week-1-march-1st-march-7th/3659/) with `cpp`.

<!-- more -->

# Closest Divisors

## Description

Given an integer `num`, find the closest two integers in absolute difference whose product equals `num + 1` or `num + 2`.

Return the two integers in any order.

 

**Example 1:**

```
Input: num = 8
Output: [3,3]
Explanation: For num + 1 = 9, the closest divisors are 3 & 3, for num + 2 = 10, the closest divisors are 2 & 5, hence 3 & 3 is chosen.
```

**Example 2:**

```
Input: num = 123
Output: [5,25]
```

**Example 3:**

```
Input: num = 999
Output: [40,25]
```

 

**Constraints:**

- $1 \le num \le 10^9$

## Solution

``` cpp
class Solution {
public:
    vector<int> closestDivisors(int num) {
        int minDiff = INT_MAX;
        vector<int> answer{0, 0};
        for(int target = num + 1; target < num + 3; ++target) {
            for(int i = 1; i * i <= target; ++i) {
                if(target % i == 0 && target / i - i < minDiff) {
                    minDiff = target / i - i;
                    answer[0] = i;
                    answer[1] = target / i;
                }
            }
        }
        return answer;
    }
};
```

then compute backforward and fast return

``` cpp
class Solution {
public:
    vector<int> closestDivisors(int num) {
        int minDiff = INT_MAX;
        vector<int> answer{0, 0};
        for(int target = num + 1; target < num + 3; ++target) {
            for(int i = 1; i * i <= target; ++i) {
                if(target % i == 0 && target / i - i < minDiff) {
                    minDiff = target / i - i;
                    answer[0] = i;
                    answer[1] = target / i;
                }
            }
        }
        return answer;
    }
};
```

# March LeetCoding Challenge3

**Missing Number**

## Description

Given an array `nums` containing `n` distinct numbers in the range `[0, n]`, return *the only number in the range that is missing from the array.*

**Follow up:** Could you implement a solution using only `O(1)` extra space complexity and `O(n)` runtime complexity?

 

**Example 1:**

```
Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
```

**Example 2:**

```
Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
```

**Example 3:**

```
Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.
```

**Example 4:**

```
Input: nums = [0]
Output: 1
Explanation: n = 1 since there is 1 number, so all numbers are in the range [0,1]. 1 is the missing number in the range since it does not appear in nums.
```

 

**Constraints:**

- `n == nums.length`
- $1 \le n \le 10^4$
- `0 <= nums[i] <= n`
- All the numbers of `nums` are **unique**.

## Solution

``` cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int sum = (len + 1) * len / 2;
        for(auto i : nums) sum -= i;
        return sum;
    }
};
```
