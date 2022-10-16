+++
title = "2020-10-10 Daily-Challenge"
path = "2020-10-10-Daily-Challenge"
date = 2020-10-10 12:17:34+08:00
updated = 2020-10-10 23:10:04+08:00

[taxonomies]
tags = ["Design", "Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [October LeetCoding Challenge](https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/559/week-1-october-1st-october-7th/3490/) with `cpp`.

<!-- more -->

# LeetCode Review

## Range Sum Query - Mutable

rewrite it with segment tree

``` cpp
class NumArray {
  vector<int> val;
  vector<int> lazy;
  int operation_begin;
  int operation_end;
  int size;
  void build(vector<int>& nums, int root_index, int begin, int end) {
    if(begin == end) {
      val[root_index] = nums[begin];
    } else {
      int mid = (begin + end) >> 1;
      build(nums, root_index*2+1, begin, mid);
      build(nums, root_index*2+2, mid+1, end);
      val[root_index] = val[root_index*2+1] + val[root_index*2+2];
    }
  }
  void pushdown(int root_index, int count) {
    if(lazy[root_index]) {
      val[root_index*2+1] += (count - count/2)*lazy[root_index];
      val[root_index*2+2] += (count/2)*lazy[root_index];
      lazy[root_index*2+1] += lazy[root_index];
      lazy[root_index*2+2] += lazy[root_index];
      lazy[root_index] = 0;
    }
  }
  void update(int root_index, int begin, int end, int difference) {
    if(operation_begin <= begin && operation_end >= end) {
      val[root_index] += difference * (operation_end-operation_begin+1);
      lazy[root_index] += difference;
      return;
    }
    pushdown(root_index, end-begin+1);
    int mid = (end + begin) >> 1;
    if(operation_begin <= mid) update(root_index*2+1, begin, mid, difference);
    if(operation_end > mid) update(root_index*2+2, mid+1, end, difference);
    val[root_index] = val[root_index*2+1] + val[root_index*2+2];
  }
  int query(int root_index, int begin, int end) {
    if(operation_begin <= begin && operation_end >= end) {
      return val[root_index];
    }
    pushdown(root_index, end-begin+1);
    int ans = 0;
    int mid = (begin + end) >> 1;
    if(operation_begin <= mid) ans += query(root_index*2+1, begin, mid);
    if(operation_end > mid) ans += query(root_index*2+2, mid+1, end);
    return ans;
  }
public:
  NumArray(vector<int>& nums) {
    val = vector<int>(nums.size()*4);
    lazy = vector<int>(nums.size()*4);
    size = nums.size()-1;
    if(size == 0) return;
    build(nums, 0, 0, size);
  }
  
  void update(int i, int val) {
    operation_begin = i;
    operation_end = i;
    int diff = val - query(0, 0, size);
    update(0, 0, size, diff);
  }
  
  int sumRange(int i, int j) {
    operation_begin = i;
    operation_end = j;
    return query(0, 0, size);
  }
};
```

## Complement of Base 10 Integer

not using built-in function

``` cpp
class Solution {
public:
  int bitwiseComplement(int N) {
    int val = 1;
    while(val <= N) {
      val <<= 1;
    }
    // same with (val-1|1)-N
    return N^(val-1 | 1);
  }
};
```

## Distribute Candies to People

seems not change much

``` cpp
class Solution {
public:
  vector<int> distributeCandies(int candies, int num_people) {
    vector<int> answer = vector<int>(num_people, 0);
    long long start = 0, end = candies;
    while(start < end) {
      long long mid = (start + end) >> 1;
      if(mid*(1+mid) / 2 >= candies) {
        end = mid;
      } else {
        start = mid + 1;
      }
    }
    int last_index = end-1;
    int rounds = last_index / num_people;
    int remain = last_index % num_people;
    for(int i = 0; i < num_people; ++i) {
      answer[i] = (i+1) * (last_index/num_people) + num_people*(rounds-1)*rounds/2;
      if(i < remain) {
        answer[i] += i+1 + rounds*num_people;
      }
    }
    answer[remain] += candies - last_index*(last_index+1)/2;
    return answer;
  }
};
```

## Insert into a Binary Search Tree

more elegant code

``` cpp
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        if(val > root->val) root->right = insertIntoBST(root->right, val);
        else root->left = insertIntoBST(root->left, val);
        return root;
    }
};
```

## Data Stream as Disjoint Intervals

I need more practice

and this solution runs slower

``` cpp
class SummaryRanges {
  set<pair<int, int>> m;
public:
  void addNum(int val) {
    auto it = m.lower_bound(make_pair(val, val));
    int new_begin = val, new_end = val;
    if(it != m.begin() && ((--it)->second+1 < val)) ++it;
    while(it != m.end() && val+1 >= it->first && val-1 <= it->second) {
      new_begin = min(new_begin, it->first);
      new_end = max(new_end, it->second);
      it = m.erase(it);
    }
    m.insert(make_pair(new_begin, new_end));
  }
  
  vector<vector<int>> getIntervals() {
    vector<vector<int>> ans;
    vector<int> tmp;
    for(auto it = m.begin(); it != m.end(); ++it) {
      tmp.push_back(it->first);
      tmp.push_back(it->second);
      ans.push_back(tmp);
      tmp.clear();
    }
    return ans;
  }
};
```

## Rotate List

nothing to say

``` cpp
class Solution {
    int length(ListNode* head) {
        ListNode *cur = head;
        int len = 0;
        while(cur) {
            cur = cur->next;
            len += 1;
        }
        return len;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int len = length(head);
        if(!len || k%len == 0) return head;
        k = len-(k%len);
        cout << k << endl;
        ListNode *cur = head, *previous;
        while(k--) {
            previous = cur;
            cur = cur->next;
        }
        ListNode *new_head = cur;
        while(cur->next) cur = cur->next;
        cur->next = head;
        previous->next = NULL;
        return new_head;
    }
};
```

# October LeetCoding Challenge 10

## Description

**Minimum Number of Arrows to Burst Balloons**

There are some spherical balloons spread in two-dimensional space. For each balloon, provided input is the start and end coordinates of the horizontal diameter. Since it's horizontal, y-coordinates don't matter, and hence the x-coordinates of start and end of the diameter suffice. The start is always smaller than the end.

An arrow can be shot up exactly vertically from different points along the x-axis. A balloon with `xstart` and `xend` bursts by an arrow shot at `x` if `xstart ≤ x ≤ xend`. There is no limit to the number of arrows that can be shot. An arrow once shot keeps traveling up infinitely.

Given an array `points` where `points[i] = [xstart, xend]`, return *the minimum number of arrows that must be shot to burst all balloons*.

**Example 1:**

```
Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] and [1,6]) and another arrow at x = 11 (bursting the other two balloons).
```

**Example 2:**

```
Input: points = [[1,2],[3,4],[5,6],[7,8]]
Output: 4
```

**Example 3:**

```
Input: points = [[1,2],[2,3],[3,4],[4,5]]
Output: 2
```

**Example 4:**

```
Input: points = [[1,2]]
Output: 1
```

**Example 5:**

```
Input: points = [[2,3],[2,3]]
Output: 1
```

**Constraints:**

- `0 <= points.length <= 104`
- `points.length == 2`
- `-231 <= xstart < xend <= 231 - 1`

## Solution

simple greedy

``` cpp
class Solution {
public:
  int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end());
    int cnt = 0, min_end = -1;
    bool hasBalloon = false;
    for(int i = 0; i < points.size(); ++i) {
      if(!hasBalloon) {
        min_end = points[i][1];
        hasBalloon = true;
      } else {
        if(points[i][0] > min_end) {
          cnt += 1;
          hasBalloon = true;
          min_end = points[i][1];
        } else {
          min_end = min(points[i][1], min_end);
        }
      }
    }
    if(hasBalloon) cnt += 1;
    return cnt;
  }
};
```