+++
title = "2021-08-29 Daily-Challenge"
path = "2021-08-29-Daily-Challenge"
date = 2021-08-29 15:11:34+08:00
updated = 2021-08-29 16:03:42+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Sunday, I gonna review the tasks I've done this week, and finish today's leetcode's [August LeetCoding Challenge](https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/616/week-4-august-22nd-august-28th/3907/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 29

## Description

**Patching Array**

Given a sorted integer array `nums` and an integer `n`, add/patch elements to the array such that any number in the range `[1, n]` inclusive can be formed by the sum of some elements in the array.

Return *the minimum number of patches required*.

 

**Example 1:**

```
Input: nums = [1,3], n = 6
Output: 1
Explanation:
Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], [1,2,3].
Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
So we only need 1 patch.
```

**Example 2:**

```
Input: nums = [1,5,10], n = 20
Output: 2
Explanation: The two patches can be [2, 4].
```

**Example 3:**

```
Input: nums = [1,2,2], n = 5
Output: 0
```

 

**Constraints:**

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>nums</code> is sorted in <strong>ascending order</strong>.</li>
	<li><code>1 &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
</ul>


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
  int minPatches(vector<int>& nums, int n) {
    int len = nums.size();
    long long all = 1;
    int count = 0;
    int pos = 0;
    if(nums.front() != 1) {
      count += 1;
    } else {
      pos += 1;
    }
    while(pos < len && all < n) {
      while(all < n && all < nums[pos] - 1) {
        all = all + all + 1;
        count += 1;
      }
      all += nums[pos];
      pos += 1;
    }
    while(all < n) {
      all = all + all + 1;
      count += 1;
    }
    return count;
  }
};

// Accepted
// 146/146 cases passed (4 ms)
// Your runtime beats 94.37 % of cpp submissions
// Your memory usage beats 48.45 % of cpp submissions (11.4 MB)
```

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int minPatches(vector<int>& nums, int n) {
    int count = 0;
    int pos = 0;
    int len = nums.size();
    long long next = 1;
    while(next <= n) {
      if(pos < len && nums[pos] <= next) {
        next += nums[pos];
        pos += 1;
      } else {
        next += next;
        count += 1;
      }
    }
    return count;
  }
};

// Accepted
// 146/146 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 48.45 % of cpp submissions (11.5 MB)
```
