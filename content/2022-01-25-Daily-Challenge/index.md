+++
title = "2022-01-25 Daily-Challenge"
path = "2022-01-25-Daily-Challenge"
date = 2022-01-25 18:12:00+08:00
updated = 2022-01-25 18:13:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/valid-mountain-array/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 25

## Description

**Valid Mountain Array**

Given an array of integers `arr`, return *`true` if and only if it is a valid mountain array*.

Recall that arr is a mountain array if and only if:

- `arr.length >= 3`

- There exists some 

  ```
  i
  ```

   with 

  ```
  0 < i < arr.length - 1
  ```

   such that: 

  - `arr[0] < arr[1] < ... < arr[i - 1] < arr[i] `
  - `arr[i] > arr[i + 1] > ... > arr[arr.length - 1]`

![img](https://assets.leetcode.com/uploads/2019/10/20/hint_valid_mountain_array.png)

 

**Example 1:**

```
Input: arr = [2,1]
Output: false
```

**Example 2:**

```
Input: arr = [3,5,5]
Output: false
```

**Example 3:**

```
Input: arr = [0,3,2,1]
Output: true
```

 

**Constraints:**

- `1 <= arr.length <= 10^4`
- `0 <= arr[i] <= 10^4`


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
  bool validMountainArray(vector<int>& arr) {
    int len = arr.size();
    if(len < 3) return false;
    int pos = 1;
    if(arr[pos] <= arr[pos - 1]) return false;
    while(pos < len && arr[pos] > arr[pos - 1]) pos += 1;
    if(pos == len || arr[pos] == arr[pos - 1]) return false;
    while(pos < len && arr[pos] < arr[pos - 1]) pos += 1;
    return pos == len;
  }
};

// Accepted
// 53/53 cases passed (16 ms)
// Your runtime beats 99.68 % of cpp submissions
// Your memory usage beats 48.39 % of cpp submissions (22.4 MB)
```
