+++
title = "2021-06-27 Daily-Challenge"
path = "2021-06-27-Daily-Challenge"
date = 2021-06-27 22:01:33+08:00
updated = 2021-06-27 22:10:47+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [June LeetCoding Challenge](https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/606/week-4-june-22nd-june-28th/3792/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge27

## Description

**Candy**

There are `n` children standing in a line. Each child is assigned a rating value given in the integer array `ratings`.

You are giving candies to these children subjected to the following requirements:

- Each child must have at least one candy.
- Children with a higher rating get more candies than their neighbors.

Return *the minimum number of candies you need to have to distribute the candies to the children*.

 

**Example 1:**

```
Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
```

**Example 2:**

```
Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.
```

 

**Constraints:**

- `n == ratings.length`
- `1 <= n <= 2 * 10^4`
- `0 <= ratings[i] <= 2 * 10^4`

## Solution

``` cpp
using pi = pair<int, int>;
class Solution {
public:
  int candy(vector<int>& ratings) {
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    int len = ratings.size();
    vector<int> candy(len);
    for(int i = 0; i < len; ++i) {
      pq.push({ratings[i], i});
    }
    while(pq.size()) {
      auto [rating, pos] = pq.top();
      // cout << pos << ' ' << rating << ' ';
      pq.pop();
      candy[pos] = 1;
      if(pos && ratings[pos - 1] < rating) {
        candy[pos] = max(candy[pos], candy[pos - 1] + 1);
      }
      if(pos < len - 1 && ratings[pos + 1] < rating) {
        candy[pos] = max(candy[pos], candy[pos + 1] + 1);
      }
      // cout << pos << ' ' << candy[pos] << endl;
    }
    return accumulate(candy.begin(), candy.end(), 0);
  }
};
```
