+++
title = "2020-12-08 Daily-Challenge"
path = "2020-12-08-Daily-Challenge"
date = 2020-12-08 16:41:33+08:00
updated = 2020-12-08 21:53:07+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Minimum Moves to Make Array Complementary](https://leetcode.com/problems/minimum-moves-to-make-array-complementary/) and [Smallest Rotation with Highest Score](https://leetcode.com/problems/smallest-rotation-with-highest-score/) on leetcode and leetcode's [December LeetCoding Challenge](https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/570/week-2-december-8th-december-14th/3559/) with `cpp`.

<!-- more -->

# Minimum Moves to Make Array Complementary

## Description

You are given an integer array `nums` of **even** length `n` and an integer `limit`. In one move, you can replace any integer from `nums` with another integer between `1` and `limit`, inclusive.

The array `nums` is **complementary** if for all indices `i` (**0-indexed**), `nums[i] + nums[n - 1 - i]` equals the same number. For example, the array `[1,2,3,4]` is complementary because for all indices `i`, `nums[i] + nums[n - 1 - i] = 5`.

Return the ***minimum** number of moves required to make* `nums` ***complementary***.

**Example 1:**

```
Input: nums = [1,2,4,3], limit = 4
Output: 1
Explanation: In 1 move, you can change nums to [1,2,2,3] (underlined elements are changed).
nums[0] + nums[3] = 1 + 3 = 4.
nums[1] + nums[2] = 2 + 2 = 4.
nums[2] + nums[1] = 2 + 2 = 4.
nums[3] + nums[0] = 3 + 1 = 4.
Therefore, nums[i] + nums[n-1-i] = 4 for every i, so nums is complementary.
```

**Example 2:**

```
Input: nums = [1,2,2,1], limit = 2
Output: 2
Explanation: In 2 moves, you can change nums to [2,2,2,2]. You cannot change any number to 3 since 3 > limit.
```

**Example 3:**

```
Input: nums = [1,2,1,2], limit = 2
Output: 0
Explanation: nums is already complementary.
```

**Constraints:**

- `n == nums.length`
- 2 <= n <= $10^5$
- 1 <= nums[i] <= limit <= $10^5$
- `n` is even.

## Solution

spent quite a time to understand how to translate this problem into a sweeping line problem

but I didn't get why, so I'm not so confident if I can solve another similar problem.

check <https://leetcode.com/problems/minimum-moves-to-make-array-complementary/discuss/953078/Prefix-sum-O(n-%2B-limit)-with-detailed-examples-and-pseudocode> for explanation

``` cpp
class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        vector<int> cnt(2*limit+3);
        int len = nums.size();
        for(int i = 0; i*2 < len; ++i) {
            int mmin = min(nums[i], nums[len-i-1]);
            int mmax = max(nums[i], nums[len-i-1]);
            cnt[mmin+1] -= 1;
            cnt[mmin+mmax] -= 1;
            cnt[mmin+mmax+1] += 1;
            cnt[mmax+limit+1] += 1;
        }
        int answer = INT_MAX;
        int current = len;
        for(auto cnt : cnt) {
            current += cnt;
            answer = min(answer, current);
        }
        return answer;
    }
};
```

# Smallest Rotation with Highest Score

## Description

Given an array `A`, we may rotate it by a non-negative integer `K` so that the array becomes `A[K], A[K+1], A{K+2], ... A[A.length - 1], A[0], A[1], ..., A[K-1]`. Afterward, any entries that are less than or equal to their index are worth 1 point. 

For example, if we have `[2, 4, 1, 3, 0]`, and we rotate by `K = 2`, it becomes `[1, 3, 0, 2, 4]`. This is worth 3 points because 1 > 0 [no points], 3 > 1 [no points], 0 <= 2 [one point], 2 <= 3 [one point], 4 <= 4 [one point].

Over all possible rotations, return the rotation index K that corresponds to the highest score we could receive. If there are multiple answers, return the smallest such index K.

```
Example 1:
Input: [2, 3, 1, 4, 0]
Output: 3
Explanation:  
Scores for each K are listed below: 
K = 0,  A = [2,3,1,4,0],    score 2
K = 1,  A = [3,1,4,0,2],    score 3
K = 2,  A = [1,4,0,2,3],    score 3
K = 3,  A = [4,0,2,3,1],    score 4
K = 4,  A = [0,2,3,1,4],    score 3
```

So we should choose K = 3, which has the highest score.

```
Example 2:
Input: [1, 3, 0, 2, 4]
Output: 0
Explanation:  A will always have 3 points no matter how it shifts.
So we will choose the smallest K, which is 0.
```

**Note:**

- `A` will have length at most `20000`.
- `A[i]` will be in the range `[0, A.length]`.

## Solution

so I do another problem to train myself.

I think this problem is easier.

I think the point is that we can choose some moves to get a maximum result, but we can use brute
force to determine how many we need, with the scoring moves for a element is a range.

``` cpp
 class Solution {
public:
    int bestRotation(vector<int>& A) {
        int len = A.size();
        vector<int> offset(len);
        for(int i = 0; i < len; ++i) {
            int beginPos = A[i];
            int endPos = len - 1;
            int leastTurn = (i - endPos + len) % len;
            int mostTurn = (i - beginPos + len) % len;
            offset[leastTurn] += 1;
            if(leastTurn > mostTurn) offset[0] += 1;
            offset[(mostTurn + 1) % len] -= 1;
        }
        int answer = offset.front();
        int turns = 0;
        for(int i = 1; i < len; ++i) {
            offset[i] += offset[i-1];
            if(answer < offset[i]) {
                answer = offset[i];
                turns = i;
            }
        }
        return turns;
    }
};
```

# December LeetCoding Challenge8

## Description

**Pairs of Songs With Total Durations Divisible by 60**

You are given a list of songs where the ith song has a duration of `time[i]` seconds.

Return *the number of pairs of songs for which their total duration in seconds is divisible by* `60`. Formally, we want the number of indices `i`, `j` such that `i < j` with `(time[i] + time[j]) % 60 == 0`.

**Example 1:**

```
Input: time = [30,20,150,100,40]
Output: 3
Explanation: Three pairs have a total duration divisible by 60:
(time[0] = 30, time[2] = 150): total duration 180
(time[1] = 20, time[3] = 100): total duration 120
(time[1] = 20, time[4] = 40): total duration 60
```

**Example 2:**

```
Input: time = [60,60,60]
Output: 3
Explanation: All three pairs have a total duration of 120, which is divisible by 60.
```

**Constraints:**

- $1 \le time.length \le 6 \times 10^4$
- `1 <= time[i] <= 500`

## Solution

nothing to say

``` cpp
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> cnt(60);
        for(auto t : time) {
            cnt[t%60] += 1;
        }
        int answer = cnt[0] * (cnt[0]-1) / 2 + cnt[30] * (cnt[30]-1) / 2;
        for(int i = 1; i < 30; ++i) {
            answer += cnt[i] * cnt[60-i];
        }
        return answer;
    }
};
```