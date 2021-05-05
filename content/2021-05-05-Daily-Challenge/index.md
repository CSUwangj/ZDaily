+++
title = "2021-05-05 Daily-Challenge"
path = "2021-05-05-Daily-Challenge"
date = 2021-05-05 18:40:24+08:00
updated = 2021-05-05 20:20:47+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Set Intersection Size At Least Two](https://leetcode.com/problems/set-intersection-size-at-least-two/) and leetcode's [May LeetCoding Challenge](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3732/) with `cpp`.

<!-- more -->

# Set Intersection Size At Least Two

## Description

An integer interval `[a, b]` (for integers `a < b`) is a set of all consecutive integers from `a` to `b`, including `a` and `b`.

Find the minimum size of a set S such that for every integer interval A in `intervals`, the intersection of S with A has a size of at least two.

 

**Example 1:**

```
Input: intervals = [[1,3],[1,4],[2,5],[3,5]]
Output: 3
Explanation: Consider the set S = {2, 3, 4}.  For each interval, there are at least 2 elements from S in the interval.
Also, there isn't a smaller size set that fulfills the above condition.
Thus, we output the size of this set, which is 3.
```

**Example 2:**

```
Input: intervals = [[1,2],[2,3],[2,4],[4,5]]
Output: 5
Explanation: An example of a minimum sized set is {1, 2, 3, 4, 5}.
```

 

**Constraints:**

- `1 <= intervals.length <= 3000`
- `intervals[i].length == 2`
- <code>0 <= ai < bi <= 10<sup>8</sup></code>

## Solution

sort the intervals by end ascending then by start descending. always take the higher two number as subset, and maintain the current higher two number in our subset. check the code for more details.

``` cpp
class Solution {
public:
  int intersectionSizeTwo(vector<vector<int>>& intervalsVector) {
    vector<pair<int, int>> intervals;
    for(auto &interval : intervalsVector) {
      intervals.push_back(make_pair(interval[0], interval[1]));
    }
    sort(intervals.begin(), intervals.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
      return a.second < b.second || (a.second == b.second && a.first > b.first);
    });
    int answer = 0;
    pair<int, int> pre = {-1, -1};
    for(auto [start, end] : intervals) {
      if(pre.second < start) {
        answer += 2;
        pre.first = end - 1;
        pre.second = end;
      } else if(pre.first < start) {
        pre = {pre.second, end};
        answer += 1;
      }
    }
    return answer;
  }
};
```

# May LeetCoding Challenge5

## Description

**Jump Game II**

Given an array of non-negative integers `nums`, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

 

**Example 1:**

```
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
```

**Example 2:**

```
Input: nums = [2,3,0,1,4]
Output: 2
```

 

**Constraints:**

- `1 <= nums.length <= 1000`
- `0 <= nums[i] <= 10^5`

## Solution

``` cpp
class Solution {
public:
  int jump(vector<int>& nums) {
    int len = nums.size();
    queue<pair<int, int>> q;
    q.push({0, nums[0]});
    nums[0] = -1;
    int answer = 0;
    while(q.size()) {
      int sz = q.size();
      // cout << "round " << answer << ": " << endl;
      for(int i = 0; i < sz; ++i) {
        auto [index, offset] = q.front();
        // cout << index << ' ' << offset << endl;
        if(index == len - 1) return answer;
        q.pop();
        for(int j = max(0, index - offset); j < min(len, index + offset + 1); ++j) {
          if(nums[j] < 0) continue;
          q.push({j, nums[j]});
          nums[j] = - 1;
        }
      }
      // cout << endl;
      answer += 1;
    }
    return -1;
  }
};
```
