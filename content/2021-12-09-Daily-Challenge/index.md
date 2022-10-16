+++
title = "2021-12-09 Daily-Challenge"
path = "2021-12-09-Daily-Challenge"
date = 2021-12-09 18:55:00+08:00
updated = 2021-12-09 19:03:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/jump-game-iii/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 9

## Description

**Jump Game III**

Given an array of non-negative integers `arr`, you are initially positioned at `start` index of the array. When you are at index `i`, you can jump to `i + arr[i]` or `i - arr[i]`, check if you can reach to **any** index with value 0.

Notice that you can not jump outside of the array at any time.

 

**Example 1:**

```
Input: arr = [4,2,3,0,3,1,2], start = 5
Output: true
Explanation: 
All possible ways to reach at index 3 with value 0 are: 
index 5 -> index 4 -> index 1 -> index 3 
index 5 -> index 6 -> index 4 -> index 1 -> index 3 
```

**Example 2:**

```
Input: arr = [4,2,3,0,3,1,2], start = 0
Output: true 
Explanation: 
One possible way to reach at index 3 with value 0 is: 
index 0 -> index 4 -> index 1 -> index 3
```

**Example 3:**

```
Input: arr = [3,0,2,1,2], start = 2
Output: false
Explanation: There is no way to reach at index 1 with value 0.
```

 

**Constraints:**

- `1 <= arr.length <= 5 * 10^4`
- `0 <= arr[i] < arr.length`
- `0 <= start < arr.length`


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
  bool canReach(vector<int>& arr, int start) {
    int len = arr.size();
    vector<bool> vis(arr.size());
    queue<int> q;
    q.push(start);
    vis[start] = true;
    while(q.size()) {
      int cur = q.front();
      q.pop();
      if(!arr[cur]) return true;
      if(cur + arr[cur] < len && !vis[cur + arr[cur]]) {
        q.push(cur + arr[cur]);
        vis[cur + arr[cur]] = true;
      }
      if(cur - arr[cur] >= 0 && !vis[cur - arr[cur]]) {
        q.push(cur - arr[cur]);
        vis[cur - arr[cur]] = true;
      }
    }
    return false;
  }
};

// Accepted
// 56/56 cases passed (24 ms)
// Your runtime beats 99.69 % of cpp submissions
// Your memory usage beats 83.03 % of cpp submissions (31.3 MB)
```
