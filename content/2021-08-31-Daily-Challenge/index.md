+++
title = "2021-08-31 Daily-Challenge"
path = "2021-08-31-Daily-Challenge"
date = 2021-08-31 18:33:34+08:00
updated = 2021-08-31 19:02:53+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Largest Number At Least Twice of Others](https://leetcode.com/problems/largest-number-at-least-twice-of-others/description/) and leetcode's [August LeetCoding Challenge](https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/617/week-5-august-29th-august-31st/3957/) with `cpp`.

<!-- more -->

# Largest Number At Least Twice of Others

## Description

You are given an integer array `nums` where the largest integer is **unique**.

Determine whether the largest element in the array is **at least twice** as much as every other number in the array. If it is, return *the **index** of the largest element, or return* `-1` *otherwise*.

 

**Example 1:**

```
Input: nums = [3,6,1,0]
Output: 1
Explanation: 6 is the largest integer.
For every other number in the array x, 6 is at least twice as big as x.
The index of value 6 is 1, so we return 1.
```

**Example 2:**

```
Input: nums = [1,2,3,4]
Output: -1
Explanation: 4 is less than twice the value of 3, so we return -1.
```

**Example 3:**

```
Input: nums = [1]
Output: 0
Explanation: 1 is trivially at least twice the value as any other number because there are no other numbers.
```

 

**Constraints:**

- `1 <= nums.length <= 50`
- `0 <= nums[i] <= 100`
- The largest element in `nums` is unique.

## Solution

``` cpp
class Solution {
public:
  int dominantIndex(vector<int>& nums) {
    int max[2] = {};
    int answer = -1;
    for(int i = 0; i < nums.size(); ++i) {
      if(nums[i] > max[0]) {
        max[1] = max[0];
        max[0] = nums[i];
        answer = i;
      } else if(nums[i] > max[1]) {
        max[1] = nums[i];
      }
    }
    return (max[0] >= max[1] * 2) ? answer : -1;
  }
};

// Accepted
// 232/232 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 69.27 % of cpp submissions (10.8 MB)
```

# August LeetCoding Challenge 31

## Description

**Find Minimum in Rotated Sorted Array**

Suppose an array of length `n` sorted in ascending order is **rotated** between `1` and `n` times. For example, the array `nums = [0,1,2,4,5,6,7]` might become:

- `[4,5,6,7,0,1,2]` if it was rotated `4` times.
- `[0,1,2,4,5,6,7]` if it was rotated `7` times.

Notice that **rotating** an array `[a[0], a[1], a[2], ..., a[n-1]]` 1 time results in the array `[a[n-1], a[0], a[1], a[2], ..., a[n-2]]`.

Given the sorted rotated array `nums` of **unique** elements, return *the minimum element of this array*.

You must write an algorithm that runs in `O(log n) time.`

 

**Example 1:**

```
Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
```

**Example 2:**

```
Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
```

**Example 3:**

```
Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 
```

 

**Constraints:**

- `n == nums.length`
- `1 <= n <= 5000`
- `-5000 <= nums[i] <= 5000`
- All the integers of `nums` are **unique**.
- `nums` is sorted and rotated between `1` and `n` times.


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
  int findMin(vector<int>& nums) {
    int len = nums.size();
    int low = 0;
    int high = len - 1;
    while(nums[low] > nums[high]) {
      int mid = (low + high) >> 1;
      if(nums[mid] >= nums[low]) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return nums[low];
  }
};

// Accepted
// 150/150 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 23.47 % of cpp submissions (10.4 MB)
```
