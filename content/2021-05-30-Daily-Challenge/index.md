+++
title = "2021-05-30 Daily-Challenge"
path = "2021-05-30-Daily-Challenge"
date = 2021-05-30 15:07:46+08:00
updated = 2021-05-30 16:46:54+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Sunday, I gonna review the tasks I've done this week, and finish today's leetcode's [May LeetCoding Challenge](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/602/week-5-may-29th-may-31st/3761/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 30

## Description

**Maximum Gap**

Given an integer array `nums`, return *the maximum difference between two successive elements in its sorted form*. If the array contains less than two elements, return `0`.

You must write an algorithm that runs in linear time and uses linear extra space.

 

**Example 1:**

```
Input: nums = [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
```

**Example 2:**

```
Input: nums = [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.
```

 

**Constraints:**

- `1 <= nums.length <= 10^4`
- `0 <= nums[i] <= 10^9`

## Solution

time complexity and space complexity of trie solution is both $O(9n)$ which is $O(n)$

``` cpp
const int mask[] = {
  100000000,
  10000000,
  1000000,
  100000,
  10000,
  1000,
  100,
  10,
  1,
};
struct Node {
  Node* children[10] = {};
};
void insert(Node *root, int num) {
  auto cur = root;
  for(int i = 0; i < 9; ++i) {
    int digit = num / mask[i] % 10;
    if(!(cur->children[digit])) {
      cur->children[digit] = new Node();
    }
    cur = cur->children[digit];
  }
}

class Solution {
  int answer = INT_MIN;
  int prev = INT_MAX;
  void solve(Node *cur, int num, int rest) {
    if(!rest) {
      // cout << num << ' '<< prev << endl;
      answer = max(answer, num - prev);
      prev = num;
      return;
    }
    for(int i = 0; i < 10; ++i) {
      if(cur->children[i]) {
        solve(cur->children[i], num * 10 + i, rest - 1);
      }
    }
  }
public:
  int maximumGap(vector<int>& nums) {
    // cout << "$$$$$$$$$$$$"<<endl;
    if(nums.size() < 2) return 0;
    Node *root = new Node();
    bool has1e9 = false;
    for(auto i : nums) {
      prev = min(i, prev);
      if(i == 1000000000) {
        has1e9 = true;
        continue;
      }
      insert(root, i);
    }
    solve(root, 0, 9);
    if(has1e9) {
      answer = max(answer, 1000000000 - prev);
    }
    return answer;
  }
};

// Accepted
// 17/17 cases passed (12 ms)
// Your runtime beats 14.33 % of cpp submissions
// Your memory usage beats 6.33 % of cpp submissions (13.7 MB)
```

but use sort will be better

``` cpp
class Solution {
public:
  int maximumGap(vector<int>& nums) {
    int len = nums.size();
    if(len < 2) return 0;
    sort(nums.begin(), nums.end());
    int answer = 0;
    for(int i = 1; i < len; ++i) {
      answer = max(answer, nums[i] - nums[i - 1]);
    }
    return answer;
  }
};

// 17 / 17 test cases passed.
// Status: Accepted
// Runtime: 4 ms
// Memory Usage: 8.6 MB
```
