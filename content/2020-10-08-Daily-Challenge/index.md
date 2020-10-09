+++
title = "2020-10-08 Daily-Challenge"
path = "2020-10-08-Daily-Challenge"
date = 2020-10-08 15:15:46+08:00
updated = 2020-10-08 16:10:28+08:00
in_search_index = true

[taxonomies]
tags = ["Design", "Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is an example of *The non-Designer's Design Book* on bottom of Page 134 and *Queries on a Permutation With Key* on [leetcode](https://leetcode.com/problems/queries-on-a-permutation-with-key/) and leetcode's [October LeetCoding Challenge](https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/560/week-2-october-8th-october-14th/3488//) with `cpp`.

<!-- more -->

# The non-Designer's Design Book

my answer:

- first one:
  - [F] neat left alignment
  - [F] use divide line insead of `·`
  - [T] renove useless shape
  - [HT] increase font size of company name
  - [T] not using italic font on title
  - [F] unify font
- second one:
  - [T] add black banner for the title and contact information
  - [F] uing `..` instead of `·`
  - [T] leave no space on left of image
  - [T] not uing italic font on title

# Queries on a Permutation With Key

## Description

Given a linked list, rotate the list to the right by *k* places, where *k* is non-negative.

**Example 1:**

```
Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
```

**Example 2:**

```
Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
```

Given the array `queries` of positive integers between `1` and `m`, you have to process all `queries[i]` (from `i=0` to `i=queries.length-1`) according to the following rules:

- In the beginning, you have the permutation `P=[1,2,3,...,m]`.
- For the current `i`, find the position of `queries[i]` in the permutation `P` (**indexing from 0**) and then move this at the beginning of the permutation `P.` Notice that the position of `queries[i]` in `P` is the result for `queries[i]`.

Return an array containing the result for the given `queries`.

**Example 1:**

```
Input: queries = [3,1,2,1], m = 5
Output: [2,1,2,1] 
Explanation: The queries are processed as follow: 
For i=0: queries[i]=3, P=[1,2,3,4,5], position of 3 in P is 2, then we move 3 to the beginning of P resulting in P=[3,1,2,4,5]. 
For i=1: queries[i]=1, P=[3,1,2,4,5], position of 1 in P is 1, then we move 1 to the beginning of P resulting in P=[1,3,2,4,5]. 
For i=2: queries[i]=2, P=[1,3,2,4,5], position of 2 in P is 2, then we move 2 to the beginning of P resulting in P=[2,1,3,4,5]. 
For i=3: queries[i]=1, P=[2,1,3,4,5], position of 1 in P is 1, then we move 1 to the beginning of P resulting in P=[1,2,3,4,5]. 
Therefore, the array containing the result is [2,1,2,1].  
```

**Example 2:**

```
Input: queries = [4,1,2,2], m = 4
Output: [3,1,2,0]
```

**Example 3:**

```
Input: queries = [7,5,5,8,3], m = 8
Output: [6,5,0,7,5]
```

**Constraints:**

- `1 <= m <= 10^3`
- `1 <= queries.length <= m`
- `1 <= queries[i] <= m`


## Solution

using `std::list` with brute force

BIT seems can solve it, leave it for review days.

``` cpp
class Solution {
public:
  vector<int> processQueries(vector<int>& queries, int m) {
    list<int> permutation;
    vector<int> ans;
    for(int i = 0; i < m; ++i) {
      permutation.push_back(i+1);
    }
    for(int i = 0; i < queries.size(); ++i) {
      auto it = find(permutation.begin(), permutation.end(), queries[i]);
      ans.push_back(distance(permutation.begin(), it));
      permutation.erase(it);
      permutation.push_front(queries[i]);
    }
    return ans;
  }
};
```

# October LeetCoding Challenge8

## Description

**Binary Search**

Given a **sorted** (in ascending order) integer array `nums` of `n` elements and a `target` value, write a function to search `target` in `nums`. If `target` exists, then return its index, otherwise return `-1`.
**Example 1:**

```
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
```

**Example 2:**

```
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
```

**Note:**

1. You may assume that all elements in `nums` are unique.
2. `n` will be in the range `[1, 10000]`.
3. The value of each element in `nums` will be in the range `[-9999, 9999]`.

## Solution

naive problem, using stl solve it.

``` cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        if (*it != target) return -1;
        return distance(nums.begin(), it);
    }
};
```