+++
updated = 2022-08-06 18:14:00+08:00
title = "2022-08-06 Daily-Challenge"
path = "2022-08-06-Daily-Challenge"
date = 2022-08-06 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/poor-pigs/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 6

## Description

**Poor Pigs**

There are `buckets` buckets of liquid, where **exactly one** of the buckets is poisonous. To figure out which one is poisonous, you  feed some number of (poor) pigs the liquid to see whether they will die  or not. Unfortunately, you only have `minutesToTest` minutes to determine which bucket is poisonous.

You can feed the pigs according to these steps:

1. Choose some live pigs to feed.
2. For each pig, choose which buckets to feed it. The pig will consume all the chosen buckets simultaneously and will take no time.
3. Wait for `minutesToDie` minutes. You may **not** feed any other pigs during this time.
4. After `minutesToDie` minutes have passed, any pigs that have been fed the poisonous bucket will die, and all others will survive.
5. Repeat this process until you run out of time.

Given `buckets`, `minutesToDie`, and `minutesToTest`, return *the **minimum** number of pigs needed to figure out which bucket is poisonous within the allotted time*.

 

**Example 1:**

```
Input: buckets = 1000, minutesToDie = 15, minutesToTest = 60
Output: 5
```

**Example 2:**

```
Input: buckets = 4, minutesToDie = 15, minutesToTest = 15
Output: 2
```

**Example 3:**

```
Input: buckets = 4, minutesToDie = 15, minutesToTest = 30
Output: 2
```

 

**Constraints:**

- `1 <= buckets <= 1000`
- `1 <= minutesToDie <= minutesToTest <= 100`

## Solution

``` cpp
class Solution {
public:
  int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    int base = 1 + minutesToTest / minutesToDie;
    return ceil(log(buckets) / log(base));
  }
};

// Accepted
// 17/17 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 58.91 % of cpp submissions (6 MB)
```
