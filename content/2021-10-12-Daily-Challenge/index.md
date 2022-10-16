+++
title = "2021-10-12 Daily-Challenge"
path = "2021-10-12-Daily-Challenge"
date = 2021-10-12 18:45:44+08:00
updated = 2021-10-12 18:56:19+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/guess-number-higher-or-lower/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 12

## Description

**Guess Number Higher or Lower**

We are playing the Guess Game. The game is as follows:

I pick a number from `1` to `n`. You have to guess which number I picked.

Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.

You call a pre-defined API `int guess(int num)`, which returns 3 possible results:

- `-1`: The number I picked is lower than your guess (i.e. `pick < num`).
- `1`: The number I picked is higher than your guess (i.e. `pick > num`).
- `0`: The number I picked is equal to your guess (i.e. `pick == num`).

Return *the number that I picked*.

 

**Example 1:**

```
Input: n = 10, pick = 6
Output: 6
```

**Example 2:**

```
Input: n = 1, pick = 1
Output: 1
```

**Example 3:**

```
Input: n = 2, pick = 1
Output: 1
```

**Example 4:**

```
Input: n = 2, pick = 2
Output: 2
```

 

**Constraints:**

<ul>
	<li><code>1 &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
	<li><code>1 &lt;= pick &lt;= n</code></li>
</ul>

## Solution

``` cpp
class Solution {
public:
  int guessNumber(int n) {
    int begin = 1, end = n;
    while(begin < end) {
      int mid = begin + (end - begin) / 2;
      int res = guess(mid);
      if(res != 1) {
        end = mid;
      } else {
        begin = mid + 1;
      }
    }
    return begin;
  }
};

// Accepted
// 25/25 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 67.31 % of cpp submissions (5.9 MB)
```
