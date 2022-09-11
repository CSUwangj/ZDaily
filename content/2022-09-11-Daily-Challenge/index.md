+++
updated = 2022-09-11 18:14:00+08:00
title = "2022-09-11 Daily-Challenge"
path = "2022-09-11-Daily-Challenge"
date = 2022-09-11 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/maximum-performance-of-a-team/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 11

## Description

**Maximum Performance of a Team**

You are given two integers `n` and `k` and two integer arrays `speed` and `efficiency` both of length `n`. There are `n` engineers numbered from `1` to `n`. `speed[i]` and `efficiency[i]` represent the speed and efficiency of the `ith` engineer respectively.

Choose **at most** `k` different engineers out of the `n` engineers to form a team with the maximum **performance**.

The performance of a team is the sum of their engineers' speeds multiplied by the minimum efficiency among their engineers.

Return *the maximum performance of this team*. Since the answer can be a huge number, return it **modulo** `109 + 7`.

 

**Example 1:**

```
Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 2
Output: 60
Explanation: 
We have the maximum performance of the team by selecting engineer 2 (with speed=10 and efficiency=4) and engineer 5 (with speed=5 and efficiency=7). That is, performance = (10 + 5) * min(4, 7) = 60.
```

**Example 2:**

```
Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 3
Output: 68
Explanation:
This is the same example as the first but k = 3. We can select engineer 1, engineer 2 and engineer 5 to get the maximum performance of the team. That is, performance = (2 + 10 + 5) * min(5, 4, 7) = 68.
```

**Example 3:**

```
Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 4
Output: 72
```

 

**Constraints:**

- `1 <= k <= n <= 10^5`
- `speed.length == n`
- `efficiency.length == n`
- `1 <= speed[i] <= 10^5`
- `1 <= efficiency[i] <= 10^8`

## Solution

``` cpp
const int MOD = 1e9 + 7;
class Solution {
public:
  int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
    vector<int> index(n);
    for (int i = 0; i < n; ++i) index[i] = i;
    sort(index.begin(), index.end(), [&](int a, int b) { 
      return efficiency[a] > efficiency[b] || (efficiency[a] == efficiency[b] && speed[a] > speed[b]);
    });
    priority_queue<int, vector<int>, greater<int>> q;
    int ef = INT_MAX;
    long long sum = 0;
    long long answer = 0;
    for(int i = 0; i < n; ++i) {
      int idx = index[i];
      if(q.size() < k) {
        sum += speed[idx];
        ef = min(ef, efficiency[idx]);
        answer = max(answer, sum * ef);
        q.push(speed[idx]);
      } else {
        if(q.top() >= speed[idx]) continue;
        sum += speed[idx] - q.top();
        q.pop();
        q.push(speed[idx]);
        ef = min(ef, efficiency[idx]);
        answer = max(answer, sum * ef);
      }
    }
    return answer % MOD;
  }
};

// Accepted
// 55/55 cases passed (211 ms)
// Your runtime beats 17.43 % of cpp submissions
// Your memory usage beats 99.12 % of cpp submissions (34.9 MB)
```
