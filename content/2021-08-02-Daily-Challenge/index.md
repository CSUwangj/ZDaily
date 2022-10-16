+++
title = "2021-08-02 Daily-Challenge"
path = "2021-08-02-Daily-Challenge"
date = 2021-08-02 20:02:12+08:00
updated = 2021-08-02 20:18:34+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Mean of Array After Removing Some Elements](https://leetcode.com/problems/mean-of-array-after-removing-some-elements/description/) and leetcode's [August LeetCoding Challenge](https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/613/week-1-august-1st-august-7th/3836/) with `cpp`.

<!-- more -->

# Mean of Array After Removing Some Elements

## Description

Given an integer array `arr`, return *the mean of the remaining integers after removing the smallest `5%` and the largest `5%` of the elements.*

Answers within `10-5` of the **actual answer** will be considered accepted.

 

**Example 1:**

```
Input: arr = [1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3]
Output: 2.00000
Explanation: After erasing the minimum and the maximum values of this array, all elements are equal to 2, so the mean is 2.
```

**Example 2:**

```
Input: arr = [6,2,7,5,1,2,0,3,10,2,5,0,5,5,0,8,7,6,8,0]
Output: 4.00000
```

**Example 3:**

```
Input: arr = [6,0,7,0,7,5,7,8,3,4,0,7,8,1,6,8,1,1,2,4,8,1,9,5,4,3,8,5,10,8,6,6,1,0,6,10,8,2,3,4]
Output: 4.77778
```

**Example 4:**

```
Input: arr = [9,7,8,7,7,8,4,4,6,8,8,7,6,8,8,9,2,6,0,0,1,10,8,6,3,3,5,1,10,9,0,7,10,0,10,4,1,10,6,9,3,6,0,0,2,7,0,6,7,2,9,7,7,3,0,1,6,1,10,3]
Output: 5.27778
```

**Example 5:**

```
Input: arr = [4,8,4,10,0,7,1,3,7,8,8,3,4,1,6,2,1,1,8,0,9,8,0,3,9,10,3,10,1,10,7,3,2,1,4,9,10,7,6,4,0,8,5,1,2,1,6,2,5,0,7,10,9,10,3,7,10,5,8,5,7,6,7,6,10,9,5,10,5,5,7,2,10,7,7,8,2,0,1,1]
Output: 5.29167
```

 

**Constraints:**

- `20 <= arr.length <= 1000`
- `arr.length` **is a multiple** of `20`.
- `0 <= arr[i] <= 10^5`

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
  double trimMean(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int sz = arr.size();
    double sum = 0;
    for(int i = sz / 20; i < sz - sz / 20; ++i) {
      sum += arr[i];
    }
    return sum / (sz - sz / 10);
  }
};

// Accepted
// 50/50 cases passed (8 ms)
// Your runtime beats 71.57 % of cpp submissions
// Your memory usage beats 13.07 % of cpp submissions (9.6 MB)
```

# August LeetCoding Challenge 2

## Description

**Two Sum**

Given an array of integers `nums` and an integer `target`, return *indices of the two numbers such that they add up to `target`*.

You may assume that each input would have ***exactly\* one solution**, and you may not use the *same* element twice.

You can return the answer in any order.

 

**Example 1:**

```
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].
```

**Example 2:**

```
Input: nums = [3,2,4], target = 6
Output: [1,2]
```

**Example 3:**

```
Input: nums = [3,3], target = 6
Output: [0,1]
```

<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= target &lt;= 10<sup>9</sup></code></li>
	<li><strong>Only one valid answer exists.</strong></li>
</ul>

<p>&nbsp;</p>
<strong>Follow-up:&nbsp;</strong>Can you come up with an algorithm that is less than&nbsp;<code>O(n<sup>2</sup>)&nbsp;</code>time complexity?


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
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> pos;
    int p = 0;
    for(auto i : nums) {
      if(pos.count(target - i)) {
        return {pos[target - i], p};
      }
      pos[i] = p++;
    }
    return {};
  }
};

// Accepted
// 54/54 cases passed (4 ms)
// Your runtime beats 99.68 % of cpp submissions
// Your memory usage beats 57.34 % of cpp submissions (10.6 MB)
```