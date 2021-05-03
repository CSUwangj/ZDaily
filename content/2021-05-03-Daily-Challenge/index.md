+++
title = "2021-05-03 Daily-Challenge"
path = "2021-05-03-Daily-Challenge"
date = 2021-05-03 15:00:00+08:00
updated = 2021-05-03 15:28:55+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Course Schedule](https://leetcode.com/problems/course-schedule/description/) and leetcode's [May LeetCoding Challenge](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3730/) with `cpp`.

<!-- more -->

# Course Schedule

## Description

There are a total of `numCourses` courses you have to take, labeled from `0` to `numCourses - 1`. You are given an array `prerequisites` where <code>prerequisites[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> indicates that you **must** take course `bi` first if you want to take course `ai`.

- For example, the pair `[0, 1]`, indicates that to take course `0` you have to first take course `1`.

Return `true` if you can finish all courses. Otherwise, return `false`.

 

**Example 1:**

```
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
```

**Example 2:**

```
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
```

 

**Constraints:**

- <code>1 <= numCourses <= 10<sup>5</sup></code>
- `0 <= prerequisites.length <= 5000`
- `prerequisites[i].length == 2`
- <code>0 <= a<sub>i</sub>, b<sub>i</sub> < numCourses</code>
- All the pairs prerequisites[i] are **unique**.

## Solution

``` cpp
class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> degree(numCourses);
    vector<vector<int>> edges(numCourses);
    for(auto &edge : prerequisites) {
      edges[edge[0]].push_back(edge[1]);
      degree[edge[1]] += 1;
    }
    queue<int> q;
    int answer = 0;
    for(int i = 0; i < numCourses; ++i) {
      if(!degree[i]) {
        answer += 1;
        q.push(i);
      }
    }
    while(q.size()) {
      int cur = q.front();
      q.pop();
      for(auto nxt : edges[cur]) {
        degree[nxt] -= 1;
        if(!degree[nxt]) {
          answer += 1;
          q.push(nxt);
        }
      }
    }
    return answer == numCourses;
  }
};
```

# May LeetCoding Challenge3

## Description

**Running Sum of 1d Array**

Given an array `nums`. We define a running sum of an array as `runningSum[i] = sum(nums[0]…nums[i])`.

Return the running sum of `nums`.

 

**Example 1:**

```
Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
```

**Example 2:**

```
Input: nums = [1,1,1,1,1]
Output: [1,2,3,4,5]
Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].
```

**Example 3:**

```
Input: nums = [3,1,2,10,1]
Output: [3,4,6,16,17]
```

 

**Constraints:**

- `1 <= nums.length <= 1000`
- `-10^6 <= nums[i] <= 10^6`

## Solution

``` cpp
class Solution {
public:
  vector<int> runningSum(vector<int>& nums) {
    int len = nums.size();
    for(int i = 1; i < len; ++i) nums[i] += nums[i - 1];
    return nums;
  }
};
```
