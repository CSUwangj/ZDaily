+++
title = "2021-02-18 Daily-Challenge"
path = "2021-02-18-Daily-Challenge"
date = 2021-02-18 17:51:26+08:00
updated = 2021-02-18 17:58:28+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/586/week-3-february-15th-february-21st/3644/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge18

**Arithmetic Slices**

## Description

A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, these are arithmetic sequences:

```
1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
```

The following sequence is not arithmetic.

```
1, 1, 2, 5, 7
```

 

A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.

A slice (P, Q) of the array A is called arithmetic if the sequence:
A[P], A[P + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.

The function should return the number of arithmetic slices in the array A.

 

**Example:**

```
A = [1, 2, 3, 4]

return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.
```

## Solution

``` cpp
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int len = A.size();
        if(len < 3) return 0;
        
        int answer = 0;
        int curLen = 1;
        int diff = A[1] - A[0];
        int pos = 2;
        while(pos < len) {
            while(pos < len && A[pos] - A[pos-1] == diff) {
                pos += 1;
                curLen += 1;
            }
            answer += curLen * (curLen - 1) / 2;
            if(pos < len) {
                diff = A[pos] - A[pos - 1];
                curLen = 1;
                pos += 1;
            }
        }
        
        return answer;
    }
};
```