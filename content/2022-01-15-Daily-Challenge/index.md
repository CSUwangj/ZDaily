+++
title = "2022-01-15 Daily-Challenge"
path = "2022-01-15-Daily-Challenge"
date = 2022-01-15 11:17:00+08:00
updated = 2022-01-15 11:24:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/jump-game-iv/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 15

## Description

**Jump Game IV**

Given an array of integers `arr`, you are initially positioned at the first index of the array.

In one step you can jump from index `i` to index:

- `i + 1` where: `i + 1 < arr.length`.
- `i - 1` where: `i - 1 >= 0`.
- `j` where: `arr[i] == arr[j]` and `i != j`.

Return *the minimum number of steps* to reach the **last index** of the array.

Notice that you can not jump outside of the array at any time.

 

**Example 1:**

```
Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
Output: 3
Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.
```

**Example 2:**

```
Input: arr = [7]
Output: 0
Explanation: Start index is the last index. You do not need to jump.
```

**Example 3:**

```
Input: arr = [7,6,9,6,9,6,9,7]
Output: 1
Explanation: You can jump directly from index 0 to index 7 which is last index of the array.
```

 

**Constraints:**

- `1 <= arr.length <= 5 * 10^4`
- `-10^8 <= arr[i] <= 10^8`


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
  int minJumps(vector<int>& arr) {
    if(arr.size() < 3) return arr.size() - 1;
    unordered_map<int, vector<int>> positions;
    int len = arr.size();
    vector<bool> posVisit(len);
    for(int i = 0; i < len; ++i) {
      positions[arr[i]].push_back(i);
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    posVisit[0] = true;

    while(q.size()) {
      auto [cnt, pos] = q.front();
      if(pos == len - 1) return cnt;
      q.pop();
      if(pos && !posVisit[pos - 1]) {
        q.push({cnt + 1, pos - 1});
        posVisit[pos - 1] = true;
      }
      if(pos < len - 1 && !posVisit[pos + 1]) {
        q.push({cnt + 1, pos + 1});
        posVisit[pos + 1] = true;
      }
      int num = arr[pos];
      for(auto next : positions[num]) {
        if(next == pos) continue;
        posVisit[next] = true;
        q.push({cnt + 1, next});
      }
      positions[num].clear();
    }
    return - 1;
  }
};

// Accepted
// 32/32 cases passed (152 ms)
// Your runtime beats 90.78 % of cpp submissions
// Your memory usage beats 42.32 % of cpp submissions (70.8 MB)
```
