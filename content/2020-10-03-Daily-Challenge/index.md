+++
title = "2020-10-03 Daily-Challenge"
path = "2020-10-03-Daily-Challenge"
date = 2020-10-03 15:40:38+08:00
updated = 2020-10-03 18:03:50+08:00
in_search_index = true

[taxonomies]
tags = ["Design", "Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is an example of *The non-Designer's Design Book* on top of Page 56 and *Reshape the Matrix* on [leetcode](https://leetcode.com/problems/reshape-the-matrix/) and leetcode's [October LeetCoding Challenge](https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/559/week-1-october-1st-october-7th/3482/) with `cpp`.

<!-- more -->

# The non-Designer's Design Book

my answer:

- [F] dashed font and dashed ellipse
- [F] same orange color
- [T] author and location use same font
- [F] same black color

# Reshape the Matrix

## Description

In MATLAB, there is a very useful function called 'reshape', which can reshape a matrix into a new one with different size but keep its original data.

You're given a matrix represented by a two-dimensional array, and two **positive** integers **r** and **c** representing the **row** number and **column** number of the wanted reshaped matrix, respectively.

The reshaped matrix need to be filled with all the elements of the original matrix in the same **row-traversing** order as they were.

If the 'reshape' operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

**Example 1:**

```
Input: 
nums = 
[[1,2],
 [3,4]]
r = 1, c = 4
Output: 
[[1,2,3,4]]
Explanation:The row-traversing of nums is [1,2,3,4]. The new reshaped matrix is a 1 * 4 matrix, fill it row by row by using the previous list.
```

**Example 2:**

```
Input: 
nums = 
[[1,2],
 [3,4]]
r = 2, c = 4
Output: 
[[1,2],
 [3,4]]
Explanation:There is no way to reshape a 2 * 2 matrix to a 2 * 4 matrix. So output the original matrix
```

**Note:**

1. The height and width of the given matrix is in range [1, 100].
2. The given r and c are all positive.

## Solution

basic cpp

``` cpp
class Solution {
public:
  vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
    if(nums.size() * nums[0].size() != r * c) return nums;
    vector<vector<int>> ans;
    vector<int> cur;
    int l = nums[0].size();
    for(int i = 0; i < r * c; ++i) {
      cur.push_back(nums[i/l][i%l]);
      if(cur.size() == c) {
        ans.push_back(cur);
        cur.clear();
      }
    }
    return ans;
  }
};
```

# October LeetCoding Challenge 3

## Description

**K-diff Pairs in an Array**
Given an array of integers `nums` and an integer `k`, return *the number of **unique** k-diff pairs in the array*.

A **k-diff** pair is an integer pair `(nums[i], nums[j])`, where the following are true:

- `0 <= i, j < nums.length`
- `i != j`
- `a <= b`
- `b - a == k`

**Example 1:**

```
Input: nums = [3,1,4,1,5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.
```

**Example 2:**

```
Input: nums = [1,2,3,4,5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
```

**Example 3:**

```
Input: nums = [1,3,1,5,4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).
```

**Example 4:**

```
Input: nums = [1,2,4,4,3,3,0,9,2,3], k = 3
Output: 2
```

**Example 5:**

```
Input: nums = [-1,-2,-3], k = 1
Output: 2
```

**Constraints:**

- `1 <= nums.length <= 104`
- `-107 <= nums[i] <= 107`
- `0 <= k <= 107`
## Solution

simple two pointers

```cpp
class Solution {
public:
  int findPairs(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int ans = 0;
    if(k == 0) {
      int last_pair = -10000001;
      for (int i = 1; i < nums.size(); ++i) {
        if(nums[i] == nums[i-1] && nums[i] != last_pair) {
          ans += 1;
          last_pair = nums[i];
        }
      }
      return ans;
    }
    auto end = unique(nums.begin(), nums.end());
    auto front = nums.begin();
    for(auto back = nums.begin()+1; back != end; ++back) {
      while(front+1 != back && *back - *front > k) ++front;
      if(*back - *front == k) ++ans;
    }
    return ans;
  }
};
```