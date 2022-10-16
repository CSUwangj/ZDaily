+++
title = "2020-12-11 Daily-Challenge"
path = "2020-12-11-Daily-Challenge"
date = 2020-12-11 18:00:14+08:00
updated = 2020-12-11 18:40:52+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Jump Game II](https://leetcode.com/problems/jump-game-ii/) on leetcode and leetcode's [December LeetCoding Challenge](https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/570/week-2-december-8th-december-14th/3562/) with `cpp`.

<!-- more -->

# Jump Game II

## Description

Given an array of non-negative integers `nums`, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

**Example 1:**

```
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
```

**Example 2:**

```
Input: nums = [2,3,0,1,4]
Output: 2
```

**Constraints:**

- `1 <= nums.length <= 3 * 104`
- `0 <= nums[i] <= 105`

## Solution

use a similar approach to the skyline problem, but it seems not so elegant. though time complexity should be $O(n)$, it has larger constant because of
container.

``` cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        function<bool(pair<int, int>, pair<int, int>)> cmp = [](pair<int, int> a, pair<int, int> b){
            return a.first > b.first || (a.first == b.first && a.second < b.second);
        };
        priority_queue<pair<int, int>, vector<pair<int,int>>, function<bool(pair<int, int>, pair<int, int>)>> q(cmp);
        q.push(make_pair(0, 0));
        int len = nums.size();
        for(int i = 0; i < len; ++i) {
            while(q.size() && q.top().second < i) q.pop();
            q.push(make_pair(q.top().first+1, i+nums[i]));
        }
        while(q.top().second < len-1) q.pop();
        return q.top().first;
    }
};
```

# December LeetCoding Challenge 11

## Description

**Remove Duplicates from Sorted Array II**

Given a sorted array *nums*, remove the duplicates [**in-place**](https://en.wikipedia.org/wiki/In-place_algorithm) such that duplicates appeared at most *twice* and return the new length.

Do not allocate extra space for another array; you must do this by **modifying the input array [in-place](https://en.wikipedia.org/wiki/In-place_algorithm)** with O(1) extra memory.

**Clarification:**

Confused why the returned value is an integer, but your answer is an array?

Note that the input array is passed in by **reference**, which means a modification to the input array will be known to the caller.

Internally you can think of this:

```
// nums is passed in by reference. (i.e., without making a copy)
int len = removeDuplicates(nums);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
```

**Example 1:**

```
Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3]
Explanation: Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively. It doesn't matter what you leave beyond the returned length.
```

**Example 2:**

```
Input: nums = [0,0,1,1,1,1,2,3,3]
Output: 7, nums = [0,0,1,1,2,3,3]
Explanation: Your function should return length = 7, with the first seven elements of nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively. It doesn't matter what values are set beyond the returned length.
```

**Constraints:**

- $0 <= nums.length <= 3 * 10^4$
- $-10^4 <= nums[i] <= 10^4$
- `nums` is sorted in ascending order.

## Solution

I can use one less variables to solve this problem.

``` cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return len;
        int pos0 = 0, pos1 = 1, cur = 2;
        while(cur < len) {
            while(cur < len && nums[cur] == nums[pos0]) ++cur;
            if(cur == len) break;
            if(cur != pos1 + 1) {
                swap(nums[pos1+1], nums[cur]);
            }
            pos1 += 1;
            pos0 += 1;
            cur += 1;
        }
        nums.resize(pos1+1);
        return pos1+1;
    }
};
```