+++
updated = 2022-07-04 18:14:00+08:00
title = "2022-07-04 Daily-Challenge"
path = "2022-07-04-Daily-Challenge"
date = 2022-07-04 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/candy/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 4

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
int cd[20000];
class Solution {
public:
  int candy(vector<int>& ratings) {
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    int len = ratings.size();
    for(int i = 0; i < len; ++i) {
      pq.push({ratings[i], i});
      cd[i] = 0;
    }
    while(pq.size()) {
      auto [rating, pos] = pq.top();
      pq.pop();
      if(cd[pos]) continue;
      cd[pos] = 1;
      for(int i = pos + 1; i < len; ++i) {
        if(ratings[i] <= ratings[i - 1]) break;
        if(cd[i] > cd[i - 1] + 1) break;
        cd[i] = cd[i - 1] + 1;
      }
      for(int i = pos - 1; i >= 0; --i) {
        if(ratings[i] <= ratings[i + 1]) break;
        if(cd[i] > cd[i + 1] + 1) break;
        cd[i] = cd[i + 1] + 1;
      }
    }
    int answer = 0;
    for(int i = 0; i < len; ++i) {
      // cout << cd[i] << ' ';
      answer += cd[i];
    }
    // cout << endl;
    return answer;
  }
};

// Accepted
// 48/48 cases passed (56 ms)
// Your runtime beats 12.87 % of cpp submissions
// Your memory usage beats 8.43 % of cpp submissions (19.8 MB)
```
