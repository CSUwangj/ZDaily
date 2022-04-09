+++
updated = 2022-04-09 19:14:00+08:00
title = "2022-04-09 Daily-Challenge"
path = "2022-04-09-Daily-Challenge"
date = 2022-04-09 19:17:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/top-k-frequent-elements/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 9

## Description

**Top K Frequent Elements**

Given an integer array `nums` and an integer `k`, return *the* `k` *most frequent elements*. You may return the answer in **any order**.

 

**Example 1:**

```
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
```

**Example 2:**

```
Input: nums = [1], k = 1
Output: [1]
```

 

**Constraints:**

- `1 <= nums.length <= 10^5`
- `k` is in the range `[1, the number of unique elements in the array]`.
- It is **guaranteed** that the answer is **unique**.

 

**Follow up:** Your algorithm's time complexity must be better than `O(n log n)`, where n is the array's size.

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  using pi = pair<int, int>;
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> count;
    for(auto n : nums) {
      count[n] += 1;
    }
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    for(auto [n, c] : count) {
      pq.push({c, n});
      if(pq.size() > k) pq.pop();
    }
    vector<int> answer;
    answer.reserve(k);
    while(pq.size()) {
      answer.push_back(pq.top().second);
      pq.pop();
    }
    return answer;
  }
};

// Accepted
// 21/21 cases passed (12 ms)
// Your runtime beats 95.02 % of cpp submissions
// Your memory usage beats 41.62 % of cpp submissions (13.7 MB)
```
