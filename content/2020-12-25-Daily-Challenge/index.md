+++
title = "2020-12-25 Daily-Challenge"
path = "2020-12-25-Daily-Challenge"
date = 2020-12-25 18:00:42+08:00
updated = 2020-12-25 21:05:34+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [3Sum](https://leetcode.com/problems/3sum/), [3Sum Closest](https://leetcode.com/problems/3sum-closest/) and [4Sum](https://leetcode.com/problems/4sum/) on leetcode and leetcode's [December LeetCoding Challenge](https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/572/week-4-december-22nd-december-28th/3580/) with `cpp`.

<!-- more -->

# 3Sum

## Description

Given an array `nums` of *n* integers, are there elements *a*, *b*, *c* in `nums` such that *a* + *b* + *c* = 0? Find all unique triplets in the array which gives the sum of zero.

Notice that the solution set must not contain duplicate triplets.

**Example 1:**

```
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
```

**Example 2:**

```
Input: nums = []
Output: []
```

**Example 3:**

```
Input: nums = [0]
Output: []
```

 **Constraints:**

- `0 <= nums.length <= 3000`
- `-105 <= nums[i] <= 105`

## Solution

two pointers

``` cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;
        for(int i = 0; i < len-2; ++i) {
            if(i && i < len-2 && nums[i] == nums[i-1]) continue;
            int begin = i+1, end = len-1;
            while(begin < end) {
                if(nums[begin]+nums[end] == -nums[i]) {
                    answer.push_back(vector<int>{nums[i], nums[begin], nums[end]});
                    int curBegin = nums[begin];
                    int curEnd = nums[end];
                    while(begin < end && nums[begin] == curBegin) ++begin;
                    while(begin < end && nums[end] == curEnd) --end;
                } else if (nums[begin]+nums[end] < -nums[i]) {
                    ++begin;
                } else {
                    --end;
                }
            }
        }
        return answer;
    }
};
```

# 3Sum Closest

## Description

Given an array `nums` of *n* integers and an integer `target`, find three integers in `nums` such that the sum is closest to `target`. Return the sum of the three integers. You may assume that each input would have exactly one solution.

**Example 1:**

```
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
```

**Constraints:**

- `3 <= nums.length <= 10^3`
- `-10^3 <= nums[i] <= 10^3`
- `-10^4 <= target <= 10^4`

## Solution

two pointers

``` cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX;
        int answer = -1;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < len-2; ++i) {
            if(i && i < len-2 && nums[i] == nums[i-1]) continue;
            int begin = i+1, end = len-1;
            while(begin < end) {
                int curSum = nums[i] + nums[begin] + nums[end];
                int curDiff = abs(curSum-target);
                if(curDiff < diff) {
                    diff = curDiff;
                    answer = curSum;
                }
                if (curSum < target) {
                    ++begin;
                } else {
                    --end;
                }
            }
        }
        return answer;
    }
};
```

# 4Sum

## Description

Given an array `nums` of *n* integers and an integer `target`, are there elements *a*, *b*, *c*, and *d* in `nums` such that *a* + *b* + *c* + *d* = `target`? Find all unique quadruplets in the array which gives the sum of `target`.

**Notice** that the solution set must not contain duplicate quadruplets.

**Example 1:**

```
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
```

**Example 2:**

```
Input: nums = [], target = 0
Output: []
```

**Constraints:**

- `0 <= nums.length <= 200`
- `-109 <= nums[i] <= 109`
- `-109 <= target <= 109`

## Solution

two pointers

``` cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;
        for(int i = 0; i < len-3; ++i) {
            if(i && i < len-3 && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j < len-2; ++j) {
                if(j > i+1 && j < len-2 && nums[j] == nums[j-1]) continue;
                int begin = j+1, end = len-1, tar = target-nums[i]-nums[j];
                while(begin < end) {
                    if(nums[begin]+nums[end] == tar) {
                        answer.push_back(vector<int>{nums[i], nums[j], nums[begin], nums[end]});
                        int curBegin = nums[begin];
                        int curEnd = nums[end];
                        while(begin < end && nums[begin] == curBegin) ++begin;
                        while(begin < end && nums[end] == curEnd) --end;
                    } else if (nums[begin]+nums[end] < tar) {
                        ++begin;
                    } else {
                        --end;
                    }
                }
            }
        }
        return answer;
    }
};
```

# December LeetCoding Challenge 25

## Description

**Diagonal Traverse**

Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.

**Example:**

```
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

Output:  [1,2,4,7,5,3,6,8,9]

Explanation:
```

**Note:**

The total number of elements of the given matrix will not exceed 10,000.

## Solution

nothing to say

``` cpp
class Solution {
    int rows, cols;
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix.front().empty()) return vector<int>();
        rows = matrix.size(), cols = matrix.front().size();
        vector<int> answer;
        int row = 0, col = 0, dir = 1;
        while(true) {
            answer.push_back(matrix[row][col]);
            if(row == rows-1 && col == cols-1) break;
            if(row-dir >= 0 && row-dir < rows && col+dir >= 0 && col+dir < cols) {
                row -= dir;
                col += dir;
            } else {
                if(dir > 0) {
                    if(col+1 < cols) col += 1;
                    else row += 1;
                } else {
                    if(row+1 < rows) row += 1;
                    else col += 1;
                }
                dir = -dir;
            }
        }
        return answer;
    }
};
```