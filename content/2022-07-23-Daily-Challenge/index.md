+++
updated = 2022-07-23 18:14:00+08:00
title = "2022-07-23 Daily-Challenge"
path = "2022-07-23-Daily-Challenge"
date = 2022-07-23 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/count-of-smaller-numbers-after-self/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 23

## Description

**Count of Smaller Numbers After Self**

You are given an integer array `nums` and you have to return a new `counts` array. The `counts` array has the property where `counts[i]` is the number of smaller elements to the right of `nums[i]`.

 

**Example 1:**

```
Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
```

**Example 2:**

```
Input: nums = [-1]
Output: [0]
```

**Example 3:**

```
Input: nums = [-1,-1]
Output: [0,0]
```

 

**Constraints:**

- `1 <= nums.length <= 10^5`
- `-10^4 <= nums[i] <= 10^4`

## Solution

``` cpp
#define lowbit(x) (x & (-x))

const int SZ = 20001;
const int OFFSET = 10001;
class Solution {
  int BITS[SZ + 1];

  void add(int x) {
    while(x <= SZ) {
      BITS[x] += 1;
      x += lowbit(x);
    }
  }

  int sum(int x) {
    int result = 0;
    while(x) {
      result += BITS[x];
      x -= lowbit(x);
    }
    return result;
  }
public:
  vector<int> countSmaller(vector<int>& nums) {
    vector<int> answer;
    for(int i = nums.size() - 1; i >= 0; --i) {
      int n = nums[i] + OFFSET;
      answer.push_back(sum(n - 1));
      add(n);
    }
    reverse(answer.begin(), answer.end());
    return answer;
  }
};

// Accepted
// 65/65 cases passed (242 ms)
// Your runtime beats 91.76 % of cpp submissions
// Your memory usage beats 96.24 % of cpp submissions (73.4 MB)
```
