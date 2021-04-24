+++
title = "2020-12-27 Daily-Challenge"
path = "2020-12-27-Daily-Challenge"
date = 2020-12-27 00:02:47+08:00
updated = 2020-12-27 16:31:49+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Sunday, I gonna review the tasks I've done this week, and finish today's leetcode's [November LeetCoding Challenge](https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/571/week-3-december-15th-december-21st/3571/) with `cpp`.

<!-- more -->

# LeetCode Review

## 3Sum Closest

loop with binary search

``` cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX;
        int answer = -1;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < len-2; ++i) {
            for(int j = i+1; j < len-1; ++j) {
                if(j != i+1 && nums[j] == nums[j-1]) continue;
                int tar = target-nums[i]-nums[j], start = j+1, end = len;
                while(start < end) {
                    int mid = (start + end) / 2;
                    if(nums[mid] > tar) {
                        if(nums[mid] - tar < diff) {
                            diff = nums[mid]-tar;
                            answer = nums[mid] + nums[i] + nums[j];
                        }
                        end = mid;
                    } else {
                        if(tar - nums[mid] < diff) {
                            diff = tar - nums[mid];
                            answer = nums[mid] + nums[i] + nums[j];
                        }
                        start = mid + 1;
                    }
                }
            }
        }
        return answer;
    }
};
```

# December LeetCoding Challenge27

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
Explanation: Start index is the last index. You don't need to jump.
```

**Example 3:**

```
Input: arr = [7,6,9,6,9,6,9,7]
Output: 1
Explanation: You can jump directly from index 0 to index 7 which is last index of the array.
```

**Example 4:**

```
Input: arr = [6,1,9]
Output: 2
```

**Example 5:**

```
Input: arr = [11,22,7,7,7,7,7,7,7,22,13]
Output: 3
```

**Constraints:**

- `1 <= arr.length <= 5 * 10^4`
- `-10^8 <= arr[i] <= 10^8`

## Solution

simple BFS, but need some optimization

``` cpp
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int len = arr.size();
        unordered_map<int, vector<int>> positions;
        for(int i = 0; i < len; ++i) {
            int n = arr[i];
            if(positions.count(n)) {
                positions[n].push_back(i);
            } else {
                positions.insert(make_pair(n, vector<int>{i}));
            }
        }
        queue<int> q;
        q.push(0);
        vector<int> step(len);
        // so don't need a `visited` vector
        step[0] = 1;
        while(q.size()) {
            auto pos = q.front();
            q.pop();
            if(pos == len-1) return step[pos]-1;
            if(pos && !step[pos-1]) {
                q.push(pos-1);
                step[pos-1] = step[pos] + 1;
            }
            if(!step[pos+1]) {
                q.push(pos+1);
                step[pos+1] = step[pos] + 1;
            }
            for(auto anotherPos : positions[arr[pos]]) {
                if(anotherPos == pos || step[anotherPos]) continue;
                q.push(anotherPos);
                step[anotherPos] = step[pos] + 1;
            }
            // optimization here
            positions[arr[pos]].clear();
        }
        return -1;
    }
};
```
