+++
title = "2021-04-12 Daily-Challenge"
path = "2021-04-12-Daily-Challenge"
date = 2021-04-12 20:45:55+08:00
updated = 2021-04-12 21:23:29+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Find a Value of a Mysterious Function Closest to Target](https://leetcode.com/problems/find-a-value-of-a-mysterious-function-closest-to-target/) and leetcode's [April LeetCoding Challenge](https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/594/week-2-april-8th-april-14th/3705/) with `cpp`.

<!-- more -->

# Find a Value of a Mysterious Function Closest to Target

## Description

![img](https://assets.leetcode.com/uploads/2020/07/09/change.png)

Winston was given the above mysterious function `func`. He has an integer array `arr` and an integer `target` and he wants to find the values `l` and `r` that make the value `|func(arr, l, r) - target|` minimum possible.

Return *the minimum possible value* of `|func(arr, l, r) - target|`.

Notice that `func` should be called with the values `l` and `r` where `0 <= l, r < arr.length`.

 

**Example 1:**

```
Input: arr = [9,12,3,7,15], target = 5
Output: 2
Explanation: Calling func with all the pairs of [l,r] = [[0,0],[1,1],[2,2],[3,3],[4,4],[0,1],[1,2],[2,3],[3,4],[0,2],[1,3],[2,4],[0,3],[1,4],[0,4]], Winston got the following results [9,12,3,7,15,8,0,3,7,0,0,3,0,0,0]. The value closest to 5 is 7 and 3, thus the minimum difference is 2.
```

**Example 2:**

```
Input: arr = [1000000,1000000,1000000], target = 1
Output: 999999
Explanation: Winston called the func with all possible values of [l,r] and he always got 1000000, thus the min difference is 999999.
```

**Example 3:**

```
Input: arr = [1,2,4,8,16], target = 0
Output: 0
```

 

**Constraints:**

- <code>1 <= arr.length <= 10<sup>5</sup></code>
- <code>1 <= arr[i] <= 10<sup>6</sup></code>
- <code>0 <= target <= 10<sup>7</sup></code>

## Solution

because union operation can only make value smaller, just enumerate every possible bit

``` cpp
const int maxBit(int x) {
  for(int i = 30; i >= 0 ; --i){
    if((1 << i) & x) return (1 << i);
  }
  return -1;
}
class Solution {
  int len;
  int closestToOneBit(vector<int>& arr, int bit, int target) {
    int pos = 0;
    int result = INT_MAX;
    while(pos < len) {
      if(!(arr[pos] & bit)) {
        pos += 1;
      } else {
        int res = arr[pos];
        while(pos < len && (arr[pos] & bit)) {
          res &= arr[pos];
          pos += 1;
        }
        result = min(result, abs(res - target));
      }
    }
    return result;
  }
public:
  int closestToTarget(vector<int>& arr, int target) {
    int all = (1 << 26) - 1;
    len = arr.size();
    int mmax = 0;
    for(auto n : arr) {
      mmax = max(n, mmax);
      all &= n;
    }
    if(mmax <= target) return target - mmax;
    if(all >= target) return all - target;
    int bit = (maxBit(target) << 1);
    int answer = INT_MAX;
    while(bit) {
      answer = min(answer, closestToOneBit(arr, bit, target));
      bit >>= 1;
    }
    return answer;
  }
};
```

# April LeetCoding challenge12

**Beautiful Arrangement II**

Given two integers `n` and `k`, you need to construct a list which contains `n` different positive integers ranging from `1` to `n` and obeys the following requirement:
Suppose this list is [a1, a2, a3, ... , an], then the list [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] has exactly `k` distinct integers.

If there are multiple answers, print any of them.

**Example 1:**

```
Input: n = 3, k = 1
Output: [1, 2, 3]
Explanation: The [1, 2, 3] has three different positive integers ranging from 1 to 3, and the [1, 1] has exactly 1 distinct integer: 1.
```



**Example 2:**

```
Input: n = 3, k = 2
Output: [1, 3, 2]
Explanation: The [1, 3, 2] has three different positive integers ranging from 1 to 3, and the [2, 1] has exactly 2 distinct integers: 1 and 2.
```



**Note:**

1. The `n` and `k` are in the range 1 <= k < n <= 10<sup>4</sup>.

## Solution

``` cpp
class Solution {
public:
  vector<int> constructArray(int n, int k) {
    vector<int> answer;
    while(n > k + 1) {
      answer.push_back(n);
      n -= 1;
    }
    if(k == 1) {
      answer.push_back(2);
      answer.push_back(1);
      return answer;
    }
    int cur = (n + 1) >> 1;
    int sign = 1;
    answer.push_back(cur);
    for(int i = 1; i <= k; ++i) {
      cur += sign * i;
      answer.push_back(cur);
      sign = -sign;
    }
    return answer;
  }
};
```
