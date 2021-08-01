+++
title = "2021-03-24 Daily-Challenge"
path = "2021-03-24-Daily-Challenge"
date = 2021-03-24 16:35:00+08:00
updated = 2021-03-24 17:55:35+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Reverse Integer](https://leetcode.com/problems/reverse-integer/) and leetcode's [March LeetCoding Challenge](https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/591/week-4-march-22nd-march-28th/3683/) with `cpp`.

<!-- more -->

# Reverse Integer

## Description

Given a signed 32-bit integer `x`, return `x` *with its digits reversed*. If reversing `x` causes the value to go outside the signed 32-bit integer range `[-231, 231 - 1]`, then return `0`.

**Assume the environment does not allow you to store 64-bit integers (signed or unsigned).**

 

**Example 1:**

```
Input: x = 123
Output: 321
```

**Example 2:**

```
Input: x = -123
Output: -321
```

**Example 3:**

```
Input: x = 120
Output: 21
```

**Example 4:**

```
Input: x = 0
Output: 0
```

 

**Constraints:**

- $-2^{31} \le x \le 2^{31} - 1$

## Solution

`reverse(INT_MIN) < INT_MIN`

`reverse(INT_MAX) > INT_MAX`

``` cpp
template <class T>
inline constexpr int sgn(const T &a) {
  return a > 0 ?  1 :
         a < 0 ? -1 :
         0;
}
class Solution {
public:
  int reverse(int x) {
    int sign = sgn(x);
    x *= -sign;
    int result = 0;
    while(x) {
      if(INT_MIN / 10 > result) return 0;
      result *= 10;
      result += x % 10;
      x /= 10;
    }
    return result * -sign;
  }
};
```

# March LeetCoding challenge 24

## Description

**Advantage Shuffle**

Given two arrays `A` and `B` of equal size, the *advantage of `A` with respect to `B`* is the number of indices `i` for which `A[i] > B[i]`.

Return **any** permutation of `A` that maximizes its advantage with respect to `B`.

 

**Example 1:**

```
Input: A = [2,7,11,15], B = [1,10,4,11]
Output: [2,11,7,15]
```

**Example 2:**

```
Input: A = [12,24,8,32], B = [13,25,32,11]
Output: [24,32,8,12]
```

 

**Note:**

1. `1 <= A.length = B.length <= 10000`
2. $0 \le A[i] \le 10^9$
3. $0 \le B[i] \le 10^9$

## Solution

``` cpp
class Solution {
public:
  vector<int> advantageCount(vector<int>& A, vector<int>& B) {
    int len = A.size();
    vector<int> answer(len);
    sort(A.begin(), A.end());
    vector<int> bIndex(len);
    for(int i = 0; i < len; ++i) bIndex[i] = i;
    sort(bIndex.begin(), bIndex.end(), [&](int a, int b) {
      return B[a] < B[b];
    });
    int begin = 0;
    int end = len - 1;
    for(int i = len - 1; i >= 0; --i) {
      if(A[end] > B[bIndex[i]]){
        answer[bIndex[i]] = A[end];
        end -= 1;
      } else {
        answer[bIndex[i]] = A[begin];
        begin += 1;
      }
    }
    return answer;
  }
};
```
