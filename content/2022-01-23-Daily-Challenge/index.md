+++
title = "2022-01-23 Daily-Challenge"
path = "2022-01-23-Daily-Challenge"
date = 2022-01-23 17:34:00+08:00
updated = 2022-01-23 17:44:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/sequential-digits/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 23

## Description

**Sequential Digits**

An integer has *sequential digits* if and only if each digit in the number is one more than the previous digit.

Return a **sorted** list of all the integers in the range `[low, high]` inclusive that have sequential digits.

 

**Example 1:**

```
Input: low = 100, high = 300
Output: [123,234]
```

**Example 2:**

```
Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]
```

 

**Constraints:**

- `10 <= low <= high <= 10^9`

## Solution

``` cpp
const vector<int> nums{1, 12, 123, 1234, 12345, 123456, 1234567, 12345678, 123456789};
class Solution {
public:
  vector<int> sequentialDigits(int low, int high) {
    int diff = 0;
    vector<int> answer;
    for(auto num : nums) {
      diff = diff * 10 + 1;
      if(num > high) break;
      while(num % 10 && num <= high) {
        if(num >= low) answer.push_back(num);
        num += diff;
      }
    }
    return answer;
  }
};

// Accepted
// 23/23 cases passed (3 ms)
// Your runtime beats 18.21 % of cpp submissions
// Your memory usage beats 76.43 % of cpp submissions (6.2 MB)
```
