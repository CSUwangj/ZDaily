+++
title = "2020-12-15 Daily-Challenge"
path = "2020-12-15-Daily-Challenge"
date = 2020-12-15 18:00:42+08:00
updated = 2020-12-15 19:05:46+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Distant Barcodes](https://leetcode.com/problems/distant-barcodes/) on leetcode and leetcode's [December LeetCoding Challenge](https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/571/week-3-december-15th-december-21st/3567/) with `cpp`.

<!-- more -->

# Distant Barcodes

## Description

In a warehouse, there is a row of barcodes, where the `ith` barcode is `barcodes[i]`.

Rearrange the barcodes so that no two adjacent barcodes are equal. You may return any answer, and it is guaranteed an answer exists.

**Example 1:**

```
Input: barcodes = [1,1,1,2,2,2]
Output: [2,1,2,1,2,1]
```

**Example 2:**

```
Input: barcodes = [1,1,1,1,2,2,3,3]
Output: [1,3,1,3,1,2,1,2]
```

**Constraints:**

- `1 <= barcodes.length <= 10000`
- `1 <= barcodes[i] <= 10000`

## Solution

only need to put most number to separate position, then it was done.

``` cpp
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        typedef pair<int, int> pii;
        unordered_map<int, int> cnt;
        for(auto i : barcodes) cnt[i] += 1;
        vector<pii> barcodeV(cnt.begin(), cnt.end());
        sort(barcodeV.begin(), barcodeV.end(), [](pii &a, pii &b) {
            return a.second > b.second;
        });
        int len = barcodes.size();
        vector<int> result(len);
        int pos = 0;
        for(auto [num, cnt] : barcodeV) {
            while(cnt--) {
                result[pos] = num;
                pos += 2;
                if(pos >= len) pos = 1;
            }
        }
        return result;
    }
};
```

# December LeetCoding Challenge15

## Description

**Squares of a Sorted Array**

## Description

Given an integer array `nums` sorted in **non-decreasing** order, return *an array of **the squares of each number** sorted in non-decreasing order*.

**Example 1:**

```
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
```

**Example 2:**

```
Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
```

**Constraints:**

- `1 <= nums.length <= 104`
- `-104 <= nums[i] <= 104`
- `nums` is sorted in **non-decreasing** order.

## Solution

nothing to say

``` cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int len = nums.size();
        int right = 1;
        while(right < len && abs(nums[right]) <= abs(nums[right-1])) ++right;
        vector<int> answer {nums[right-1]*nums[right-1]};
        int left = right - 2;
        while(left >=0 && right < len) {
            int neg = nums[left]*nums[left];
            int pos = nums[right]*nums[right];
            if(neg < pos) {
                answer.push_back(neg);
                --left;
            } else {
                answer.push_back(pos);
                ++right;
            }
        }
        while(left >= 0) {
            answer.push_back(nums[left]*nums[left]);
            --left;
        }
        while(right < len) {
            answer.push_back(nums[right]*nums[right]);
            ++right;
        }
        return answer;
    }
};
```