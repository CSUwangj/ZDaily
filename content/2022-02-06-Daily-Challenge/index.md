+++
title = "2022-02-06 Daily-Challenge"
path = "2022-02-06-Daily-Challenge"
date = 2022-02-06 14:20:00+08:00
updated = 2022-02-06 14:21:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 6

## Description

**Merge k Sorted Lists**

Given an integer array `nums` sorted in **non-decreasing order**, remove some duplicates [**in-place**](https://en.wikipedia.org/wiki/In-place_algorithm) such that each unique element appears **at most twice**. The **relative order** of the elements should be kept the **same**.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the **first part** of the array `nums`. More formally, if there are `k` elements after removing the duplicates, then the first `k` elements of `nums` should hold the final result. It does not matter what you leave beyond the first `k` elements.

Return `k` *after placing the final result in the first* `k` *slots of* `nums`.

Do **not** allocate extra space for another array. You must do this by **modifying the input array [in-place](https://en.wikipedia.org/wiki/In-place_algorithm)** with O(1) extra memory.

**Custom Judge:**

The judge will test your solution with the following code:

```
int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
```

If all assertions pass, then your solution will be **accepted**.

 

**Example 1:**

```
Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

**Example 2:**

```
Input: nums = [0,0,1,1,1,1,2,3,3]
Output: 7, nums = [0,0,1,1,2,3,3,_,_]
Explanation: Your function should return k = 7, with the first seven elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

 

**Constraints:**

<ul>
	<li><code>1 &lt;= nums.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>nums</code> is sorted in <strong>non-decreasing</strong> order.</li>
</ul>

## Solution

``` cpp
class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int len = nums.size();
    int newLen = 0;
    int pos = 0;
    while(pos < len) {
      swap(nums[pos], nums[newLen]);
      pos += 1;
      newLen += 1;
      if(pos < len && nums[pos] == nums[newLen - 1]) {
        swap(nums[pos], nums[newLen]);
        newLen += 1;
        pos += 1;
        while(pos < len && nums[newLen - 1] == nums[pos]) {
          pos += 1;
        }
      }
    }
    return newLen;
  }
};

// Accepted
// 164/164 cases passed (4 ms)
// Your runtime beats 86.5 % of cpp submissions
// Your memory usage beats 9.46 % of cpp submissions (11 MB)
```
