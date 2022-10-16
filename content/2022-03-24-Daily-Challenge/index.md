+++
updated = 2022-03-24 20:12:00+08:00
title = "2022-03-24 Daily-Challenge"
path = "2022-03-24-Daily-Challenge"
date = 2022-03-24 20:11:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/boats-to-save-people/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 24

## Description

**Boats to Save People**

You are given an array `people` where `people[i]` is the weight of the `ith` person, and an **infinite number of boats** where each boat can carry a maximum weight of `limit`. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most `limit`.

Return *the minimum number of boats to carry every given person*.

 

**Example 1:**

```
Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)
```

**Example 2:**

```
Input: people = [3,2,2,1], limit = 3
Output: 3
Explanation: 3 boats (1, 2), (2) and (3)
```

**Example 3:**

```
Input: people = [3,5,3,4], limit = 5
Output: 4
Explanation: 4 boats (3), (3), (4), (5)
```

 

**Constraints:**

- `1 <= people.length <= 5 * 10^4`
- `1 <= people[i] <= limit <= 3 * 10^4`

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
  int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(), people.end());
    int len = people.size();
    if(people.back() * 2 <= limit) return (len + 1) / 2;
    if(people.front() * 2 > limit) return len;
    int ed = len - 1;
    int st = 0;
    int answer = 0;
    while(st < ed) {
      if(people[st] + people[ed] > limit) {
        ed -= 1;
      } else {
        ed -= 1;
        st += 1;
      }
      answer += 1;
    }
    answer += (st == ed);
    return answer;
  }
};


// Accepted
// 78/78 cases passed (68 ms)
// Your runtime beats 97.18 % of cpp submissions
// Your memory usage beats 57.42 % of cpp submissions (42 MB)
```
