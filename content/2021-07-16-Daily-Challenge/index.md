+++
title = "2021-07-16 Daily-Challenge"
path = "2021-07-16-Daily-Challenge"
date = 2021-07-16 20:02:50+08:00
updated = 2021-07-16 23:44:33+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Sort Items by Groups Respecting Dependencies](https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/description/) and leetcode's [July LeetCoding Challenge](https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/610/week-3-july-15th-july-21st/3816/) with `cpp`.

<!-- more -->

# Sort Items by Groups Respecting Dependencies

## Description

There are `n` items each belonging to zero or one of `m` groups where `group[i]` is the group that the `i`-th item belongs to and it's equal to `-1` if the `i`-th item belongs to no group. The items and the groups are zero indexed. A group can have no item belonging to it.

Return a sorted list of the items such that:

- The items that belong to the same group are next to each other in the sorted list.
- There are some relations between these items where `beforeItems[i]` is a list containing all the items that should come before the `i`-th item in the sorted array (to the left of the `i`-th item).

Return any solution if there is more than one solution and return an **empty list** if there is no solution.

 

**Example 1:**

**![img](https://assets.leetcode.com/uploads/2019/09/11/1359_ex1.png)**

```
Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3,6],[],[],[]]
Output: [6,3,4,1,5,2,0,7]
```

**Example 2:**

```
Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3],[],[4],[]]
Output: []
Explanation: This is the same as example 1 except that 4 needs to be before 6 in the sorted list.
```

 

**Constraints:**

- `1 <= m <= n <= 3 * 10^4`
- `group.length == beforeItems.length == n`
- `-1 <= group[i] <= m - 1`
- `0 <= beforeItems[i].length <= n - 1`
- `0 <= beforeItems[i][j] <= n - 1`
- `i != beforeItems[i][j]`
- `beforeItems[i] `does not contain duplicates elements.

## Solution

amazing double topological sort

``` cpp
class Solution {
  int groupDegree[30000] = {};
  int degree[30000] = {};
  vector<int> children[30000];
  vector<int> groupChildren[30000];
  vector<int> items[30000];
public:
  vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
    // init
    for(int i = 0; i < n; ++i) {
      if(group[i] == -1) group[i] = m++;
      items[group[i]].push_back(i);
    }
    for(int i = 0; i < n; ++i) {
      for(auto p : beforeItems[i]) {
        children[p].push_back(i);
        degree[i] += 1;
        if(group[p] != group[i]) {
          groupDegree[group[i]] += 1;
          groupChildren[group[p]].push_back(group[i]);
        }
      }
    }

    // topological sort for group
    vector<int> groupOrder;
    queue<int> q;
    for(int i = 0; i < m; ++i) {
      if(!groupDegree[i]) q.push(i);
    }
    while(q.size()) {
      int cur = q.front();
      q.pop();
      groupOrder.push_back(cur);
      for(auto c : groupChildren[cur]) {
        groupDegree[c] -= 1;
        if(!groupDegree[c]) q.push(c);
      }
    }
    // cout << groupOrder << endl;
    if(groupOrder.size() != m) return {};

    // sort items
    vector<int> answer;
    for(auto g : groupOrder) {
      int sz = answer.size();
      for(auto item : items[g]) {
        if(!degree[item]) q.push(item);
      }
      while(q.size()) {
        int cur = q.front();
        q.pop();
        answer.push_back(cur);
        for(auto c : children[cur]) {
          degree[c] -= 1;
          if(group[c] == group[cur] && !degree[c]) {
            q.push(c);
          }
        }
      }
      if(answer.size() - sz != items[g].size()) return {};
    }

    return answer;
  }
};

// Accepted
// 17/17 cases passed (112 ms)
// Your runtime beats 65.23 % of cpp submissions
// Your memory usage beats 83.77 % of cpp submissions (41.5 MB)
```

# July LeetCoding Challenge 16

## Description

**4Sum**

Given an array `nums` of `n` integers, return *an array of all the **unique** quadruplets* `[nums[a], nums[b], nums[c], nums[d]]` such that:

- `0 <= a, b, c, d < n`
- `a`, `b`, `c`, and `d` are **distinct**.
- `nums[a] + nums[b] + nums[c] + nums[d] == target`

You may return the answer in **any order**.

 

**Example 1:**

```
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
```

**Example 2:**

```
Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
```

 

**Constraints:**

<ul>
	<li><code>1 &lt;= nums.length &lt;= 200</code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= target &lt;= 10<sup>9</sup></code></li>
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
  int len;
  void solve(
    vector<vector<int>> &answer,
    vector<int> &cur,
    vector<int> &nums,
    int index,
    int rest,
    int count
  ) {
    // cout << rest << " " << index << " " << count << endl;
    if(!count) {
      if(!rest) answer.push_back(cur);
      return;
    }
    if(nums.back() * count < rest) return;
    int prev = INT_MIN;
    while(index < len) {
      index = upper_bound(nums.begin() + index, nums.end(), prev) - nums.begin();
      if(index >= len) return;
      prev = nums[index];
      if(prev * count <= rest) {
        cur.push_back(prev);
        solve(answer, cur, nums, index + 1, rest - prev, count - 1);
        cur.pop_back();
      }
    }
  }
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> answer;
    vector<int> tmp;
    sort(nums.begin(), nums.end());
    len = nums.size();
    solve(answer, tmp, nums, 0, target, 4);
    return answer;
  }
};

// Accepted
// 283/283 cases passed (288 ms)
// Your runtime beats 6.98 % of cpp submissions
// Your memory usage beats 45.62 % of cpp submissions (13.1 MB)
```
