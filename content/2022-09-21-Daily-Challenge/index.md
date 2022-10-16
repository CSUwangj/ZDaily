+++
updated = 2022-09-21 18:14:00+08:00
title = "2022-09-21 Daily-Challenge"
path = "2022-09-21-Daily-Challenge"
date = 2022-09-21 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/sum-of-even-numbers-after-queries/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 21

## Description

**Sum of Even Numbers After Queries**

You are given an integer array `nums` and an array `queries` where `queries[i] = [vali, indexi]`.

For each query `i`, first, apply `nums[indexi] = nums[indexi] + vali`, then print the sum of the even values of `nums`.

Return *an integer array* `answer` *where* `answer[i]` *is the answer to the* `ith` *query*.

 

**Example 1:**

```
Input: nums = [1,2,3,4], queries = [[1,0],[-3,1],[-4,0],[2,3]]
Output: [8,6,2,4]
Explanation: At the beginning, the array is [1,2,3,4].
After adding 1 to nums[0], the array is [2,2,3,4], and the sum of even values is 2 + 2 + 4 = 8.
After adding -3 to nums[1], the array is [2,-1,3,4], and the sum of even values is 2 + 4 = 6.
After adding -4 to nums[0], the array is [-2,-1,3,4], and the sum of even values is -2 + 4 = 2.
After adding 2 to nums[3], the array is [-2,-1,3,6], and the sum of even values is -2 + 6 = 4.
```

**Example 2:**

```
Input: nums = [1], queries = [[4,0]]
Output: [0]
```

 

**Constraints:**

- `1 <= nums.length <= 10^4`
- `-104 <= nums[i] <= 10^4`
- `1 <= queries.length <= 10^4`
- `-104 <= vali <= 10^4`
- `0 <= indexi < nums.length`

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
  vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
    vector<int> answer;
    answer.reserve(queries.size());

    int current = accumulate(nums.begin(), nums.end(), 0, [](int s, int a) {
      return s + !(a & 1) * a;
    });
    for(const auto &query : queries) {
      if(!(nums[query[1]] & 1)) {
        current -= nums[query[1]];
      }
      nums[query[1]] += query[0];
      if(!(nums[query[1]] & 1)) {
        current += nums[query[1]];
      }
      answer.push_back(current);
    }
    return answer;
  }
};

// Accepted
// 58/58 cases passed (191 ms)
// Your runtime beats 49.8 % of cpp submissions
// Your memory usage beats 85.52 % of cpp submissions (45.4 MB)
```
