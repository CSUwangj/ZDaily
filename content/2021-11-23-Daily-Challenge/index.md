+++
title = "2021-11-23 Daily-Challenge"
path = "2021-11-23-Daily-Challenge"
date = 2021-11-23 20:33:00+08:00
updated = 2021-11-23 21:15:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/largest-component-size-by-common-factor/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 23

## Description

**Largest Component Size by Common Factor**

You are given an integer array of unique positive integers `nums`. Consider the following graph:

- There are `nums.length` nodes, labeled `nums[0]` to `nums[nums.length - 1]`,
- There is an undirected edge between `nums[i]` and `nums[j]` if `nums[i]` and `nums[j]` share a common factor greater than `1`.

Return *the size of the largest connected component in the graph*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2018/12/01/ex1.png)

```
Input: nums = [4,6,15,35]
Output: 4
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2018/12/01/ex2.png)

```
Input: nums = [20,50,9,63]
Output: 2
```

**Example 3:**

![img](https://assets.leetcode.com/uploads/2018/12/01/ex3.png)

```
Input: nums = [2,3,6,7,4,12,21,39]
Output: 8
```

 

**Constraints:**

- `1 <= nums.length <= 2 * 10^4`
- `1 <= nums[i] <= 10^5`
- All the values of `nums` are **unique**.

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  int parent[100001] = {};
  int count[100001] = {};
  
  int find(int x) {
    if(!parent[x]) parent[x] = x;
    else if(parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
  }
  
  void merge(int x, int y) {
    x = find(x);
    y = find(y);
    parent[x] = y;
  }
public:
  int largestComponentSize(vector<int>& A) {
    // optimize by locality
    sort(A.begin(), A.end());
    int n = A.back();
    int st[n + 1];
    bool visit[n + 1];
    memset(visit, 0, sizeof(visit));
    memset(st, 0, sizeof(st));
    for(auto i : A) {
      st[i] = 1;
    }
    for(int i = 2; 2 * i <= n; ++i) {
      if(visit[i]) continue;
      int last = 0;
      for(int j = i; j <= n; j += i) {
        visit[j] = true;
        if(st[j]) {
          if(last) merge(last, j);
          last = j;
          // cout << i << ' ' << j << endl;
        }  
      }
    }
    int answer = 0;
    for(auto i : A) {
      answer = max(answer, ++count[find(i)]);
      // cout << i << ' ' << find(i) << endl;
    }
    return answer;
  }
};

// Accepted
// 104/104 cases passed (76 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 92.13 % of cpp submissions (32.9 MB)
```
