+++
title = "2021-06-06 Daily-Challenge"
path = "2021-06-06-Daily-Challenge"
date = 2021-06-06 15:15:33+08:00
updated = 2021-06-07 02:10:32+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Sunday, I gonna review the tasks I've done this week, and finish today's leetcode's [June LeetCoding Challenge](https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/603/week-1-june-1st-june-7th/3769/) with `cpp`.

<!-- more -->

# LeetCode Review

## Rectangle Area II

``` cpp
const int MOD = 1e9 + 7;
struct Node {
  int l, r, y, v;
  bool operator<(const Node& a) const {
    return this->y < a.y;
  }
};
struct SegTree {
  vector<int> lazy;
  vector<int> sum;
  vector<int> mp;
  vector<Node> nodes;
  int n;
  int id(int x) {
    return lower_bound(mp.begin(), mp.end(), x) - mp.begin();
  }

  SegTree(vector<vector<int>>& rectangles) {
    int len = rectangles.size();
    nodes.resize(len * 2);
    mp.resize(len * 2);
    for(int i = 0; i < len; ++i) {
      nodes[i * 2].l = rectangles[i][0];
      nodes[i * 2].r = rectangles[i][2];
      nodes[i * 2].y = rectangles[i][1];
      nodes[i * 2].v = 1;
      mp[i * 2] = rectangles[i][0];
      nodes[i * 2 + 1].l = rectangles[i][0];
      nodes[i * 2 + 1].r = rectangles[i][2];
      nodes[i * 2 + 1].y = rectangles[i][3];
      nodes[i * 2 + 1].v = -1;
      mp[i * 2 + 1] = rectangles[i][2];
    }
    sort(nodes.begin(), nodes.end());
    sort(mp.begin(), mp.end());
    mp.resize(unique(mp.begin(), mp.end()) - mp.begin());
    n = mp.size();
    lazy.resize(n * 8);
    sum.resize(n * 8);
    for(auto &node : nodes) {
      node.l = id(node.l);
      node.r = id(node.r);
    }
  }

  void pull(int l, int r, int o) {
    if(lazy[o] > 0) sum[o] = mp[r + 1] - mp[l];
    else sum[o] = sum[o * 2 + 1] + sum[o * 2 + 2];
  }

  void update(int l, int r, int ql, int qr, int v, int o = 0) {
    cout<< "?" << l << ' '  << r << ' ' << ql << ' ' << qr << endl;
    if(l >= ql && r <= qr) {
      lazy[o] += v;
    } else {
    // cout << l << ' '  << r << ' ' << ql << ' ' << qr << endl;
      int mid = (l + r) >> 1;
      if(mid >= ql) update(l, mid, ql, qr, v, o * 2 + 1);
      if(mid < qr) update(mid + 1, r, ql, qr, v, o * 2 + 2);
    }
    pull(l, r, o);
  }

  int solve() {
    long long prevY = nodes[0].y;
    long long area = 0;
    for(auto &node : nodes) {
      area += sum[0] * (node.y - prevY);
      // cout << node.l << ' ' << node.r << ' ' << sum[0] << ' ' << node.y << ' ' << prevY << endl;
      update(0, n - 1, node.l, node.r - 1, node.v);
      prevY = node.y;
    }
    return area % MOD;
  }
};

class Solution {
public:
  int rectangleArea(vector<vector<int>>& rectangles) {
    auto segTree = SegTree(rectangles);
    return segTree.solve();
  }
};
```

# June LeetCoding Challenge 6

## Description

**Longest Consecutive Sequence**

Given an unsorted array of integers `nums`, return *the length of the longest consecutive elements sequence.*

You must write an algorithm that runs in `O(n)` time.

 

**Example 1:**

```
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
```

**Example 2:**

```
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
```

 

**Constraints:**

- `0 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`

## Solution

``` cpp
class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    if(nums.empty()) return 0;
    sort(nums.begin(), nums.end());
    int cur = nums.front();
    int len = 0;
    int answer = 1;
    for(auto i : nums) {
      if(i == cur + 1) {
        len += 1;
        answer = max(answer, len);
      } else if(i == cur) {
        continue;
      } else {
        len = 1;
      }
      cur = i;
    }
    return answer;
  }
};
```

``` cpp
class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> st(nums.begin(), nums.end());
    int answer = 0;
    for(auto i : st) {
      if(st.count(i - 1)) continue;
      int cur = i;
      int len = 0;
      while(st.count(cur)) {
        len += 1;
        cur += 1;
      }
      answer = max(answer, len);
    }
    return answer;
  }
};
```
