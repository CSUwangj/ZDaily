+++
title = "2020-12-31 Daily-Challenge"
path = "2020-12-31-Daily-Challenge"
date = 2020-12-31 08:03:39+08:00
updated = 2020-12-31 18:22:21+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Task Scheduler](https://leetcode.com/problems/task-scheduler/) on leetcode and leetcode's [December LeetCoding Challenge](https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/573/week-4-december-29th-december-31st/3587/) with `cpp`.

<!-- more -->

# Task Scheduler

## Description

Given a characters array `tasks`, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

However, there is a non-negative integer `n` that represents the cooldown period between two **same tasks** (the same letter in the array), that is that there must be at least `n` units of time between any two same tasks.

Return *the least number of units of times that the CPU will take to finish all the given tasks*.

**Example 1:**

```
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: 
A -> B -> idle -> A -> B -> idle -> A -> B
There is at least 2 units of time between any two same tasks.
```

**Example 2:**

```
Input: tasks = ["A","A","A","B","B","B"], n = 0
Output: 6
Explanation: On this case any permutation of size 6 would work since n = 0.
["A","A","A","B","B","B"]
["A","B","A","B","A","B"]
["B","B","B","A","A","A"]
...
And so on.
```

**Example 3:**

```
Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
Output: 16
Explanation: 
One possible solution is
A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A
```

**Constraints:**

- `1 <= task.length <= 104`
- `tasks[i]` is upper-case English letter.
- The integer `n` is in the range `[0, 100]`.

## Solution

we only need to care about letters that are of maximum appearance, to get the answer we need to determine if it is possible that we can find a way not to use idle schedule tasks or how many idles we need to schedule tasks.

take an example, ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2, where `A` has maximum appearance, so we put `A` at front, and check conditions we mentioned above. we will find the best we can do is "fill the space" between `A`, and leave rest for idles. we can find that answer is `appearance of A` times `n+1` minus `n`(because we don't need to idle after the last task).

what if there are multiple letters of the maximum appearance? image every time we run the task of maximum appearance is a round, we need to put them together at every round. take an example, ["A","A","A","A","A","A","B","B","B","B","B","B","B","C","D"], n = 2. best we can do is

```
A -> B -> C -> A -> B -> D -> A -> B -> idle -> A -> B -> idle -> A -> B -> idle -> A -> B -> idle -> A -> B
```

answer is (`appearance of A` × `n+1`) - `n` + `1`.

we could assume that answer is maximum appearance minus 1, then times n+1, and plus the amount of letters of maximum appearance. although the result might less than the amount of tasks, which is impossible, so we need to choose a higher value as the final answer.

we could verify this assumption by category discussion and induction.

``` cpp
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        int all = tasks.size();
        int maximum = 0;
        for(auto c : tasks) {
            mp[c] += 1;
            if(mp[c] > maximum) {
                maximum = mp[c];
            }
        }
        int answer = (maximum-1) * (n+1);
        for(auto [_, cnt] : mp) {
            if(cnt == maximum) answer += 1;
        }
        return max(answer, all);
    }
};
```

# December LeetCoding Challenge31

**Largest Rectangle in Histogram**

## Description

Given *n* non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

![img](https://assets.leetcode.com/uploads/2018/10/12/histogram.png)
Above is a histogram where width of each bar is 1, given height = `[2,1,5,6,2,3]`.

 

![img](https://assets.leetcode.com/uploads/2018/10/12/histogram_area.png)
The largest rectangle is shown in the shaded area, which has area = `10` unit.

**Example:**

```
Input: [2,1,5,6,2,3]
Output: 10
```

## Solution

another way of next great element.

``` cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        vector<int> monoStack;
        vector<int> lastLess(len);
        for(int i = 0; i < len; ++i) {
            while(monoStack.size() && heights[monoStack.back()] >= heights[i]) monoStack.pop_back();
            lastLess[i] = monoStack.empty() ? -1 : monoStack.back();
            monoStack.push_back(i);
        }
        monoStack.clear();
        vector<int> nextLess(len);
        for(int i = len-1; i >= 0; --i) {
            while(monoStack.size() && heights[monoStack.back()] >= heights[i]) monoStack.pop_back();
            nextLess[i] = monoStack.size() ? monoStack.back() : -1;
            monoStack.push_back(i);
        }
        int answer = 0;
        for(int i = 0; i < len; ++i) {
            int length = lastLess[i] == -1 ? i+1 : i-lastLess[i];
            length += nextLess[i] == -1 ? len-i : nextLess[i]-i;
            length -= 1;
            answer = max(answer, length*heights[i]);
        }
        return answer;
    }
};
```