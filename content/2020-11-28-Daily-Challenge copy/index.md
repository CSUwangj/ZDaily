+++
title = "2020-11-29 Daily-Challenge"
path = "2020-11-29-Daily-Challenge"
date = 2020-11-29 15:04:31+08:00
updated = 2020-11-29 17:45:45+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Sunday, I gonna review the tasks I've done this week, and finish today's leetcode's [November LeetCoding Challenge](https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/568/week-5-november-29th-november-30th/3548/) with `cpp`.

<!-- more -->

# LeetCode Review

## Sliding Window Maximum

nothing to say

``` cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> monoQueue;
        for(int i = 0; i < k; ++i) {
            while(monoQueue.size() && monoQueue.back() < nums[i]) monoQueue.pop_back();
            monoQueue.push_back(nums[i]);
        }
        vector<int> answer{monoQueue.front()};
        for(int i = k; i < nums.size(); ++i) {
            while(monoQueue.size() && monoQueue.back() < nums[i]) monoQueue.pop_back();
            if(monoQueue.size() && monoQueue.front() == nums[i-k]) monoQueue.pop_front();
            monoQueue.push_back(nums[i]);
            answer.push_back(monoQueue.front());
        }
        return answer;
    }
};
```

# November LeetCoding Challenge29

**Jump Game III**

## Description

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

DFS, time complexity is $O(n)$

``` cpp
class Solution {
    vector<bool> visited;
    bool dfs(vector<int> &arr, int current) {
        if(visited[current]) return false;
        if(arr[current] == 0) return true;
        visited[current] = true;
        if(current + arr[current] < arr.size() && dfs(arr, current + arr[current])) return true;
        if(current - arr[current] >= 0 && dfs(arr, current - arr[current])) return true;
        return false;
    }
public:
    bool canReach(vector<int>& arr, int start) {
        visited = vector<bool>(arr.size(), false);
        return dfs(arr, start);
    }
};
```

BFS is ok too, with same time complexity and space complexity.

``` cpp
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size());
        queue<int> q;
        q.push(start);
        int len = arr.size();
        while(q.size()) {
            int current = q.front();
            q.pop();
            if(arr[current] == 0) return true;
            visited[current] = true;
            int farther = current + arr[current];
            if(farther < len && !visited[farther]) q.push(farther);
            int near = current - arr[current];
            if(near >= 0 && !visited[near]) q.push(near);
        }
        return false;
    }
};
```
