+++
updated = 2022-06-23 18:14:00+08:00
title = "2022-06-23 Daily-Challenge"
path = "2022-06-23-Daily-Challenge"
date = 2022-06-23 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/course-schedule-iii/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 23

## Description

**Course Schedule III**

There are `n` different online courses numbered from `1` to `n`. You are given an array `courses` where `courses[i] = [durationi, lastDayi]` indicate that the `ith` course should be taken **continuously** for `durationi` days and must be finished before or on `lastDayi`.

You will start on the `1st` day and you cannot take two or more courses simultaneously.

Return *the maximum number of courses that you can take*.

 

**Example 1:**

```
Input: courses = [[100,200],[200,1300],[1000,1250],[2000,3200]]
Output: 3
Explanation: 
There are totally 4 courses, but you can take 3 courses at most:
First, take the 1st course, it costs 100 days so you will finish it on the 100th day, and ready to take the next course on the 101st day.
Second, take the 3rd course, it costs 1000 days so you will finish it on the 1100th day, and ready to take the next course on the 1101st day. 
Third, take the 2nd course, it costs 200 days so you will finish it on the 1300th day. 
The 4th course cannot be taken now, since you will finish it on the 3300th day, which exceeds the closed date.
```

**Example 2:**

```
Input: courses = [[1,2]]
Output: 1
```

**Example 3:**

```
Input: courses = [[3,2],[4,3]]
Output: 0
```

 

**Constraints:**

- `1 <= courses.length <= 10^4`
- `1 <= durationi, lastDayi <= 10^4`

## Solution

``` cpp
class Solution {
public:
  int scheduleCourse(vector<vector<int>> &courses) {
    vector<pair<int, int>> cr;
    for(auto &c : courses) cr.push_back(make_pair(c[1], c[0]));
    sort(cr.begin(), cr.end());
    priority_queue<int> q;
    int cur = 0;
    for(auto &[ddl, duration] : cr) {
      if(cur + duration <= ddl) {
        q.push(duration);
        cur += duration;
      } else if(q.size() && q.top() > duration) {
        cur += duration - q.top();
        q.pop();
        q.push(duration);
      }
    }
    return q.size();
  }
};

// Accepted
// 97/97 cases passed (152 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 50.48 % of cpp submissions (60.7 MB)
```
