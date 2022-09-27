+++
updated = 2022-09-27 18:14:00+08:00
title = "2022-09-27 Daily-Challenge"
path = "2022-09-27-Daily-Challenge"
date = 2022-09-27 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/push-dominoes/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 27

## Description

**Push Dominoes**

There are `n` dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the  left or to the right.

After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the  right push their adjacent dominoes standing on the right.

When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.

For the purposes of this question, we will consider that a falling  domino expends no additional force to a falling or already fallen  domino.

You are given a string `dominoes` representing the initial state where:

- `dominoes[i] = 'L'`, if the `ith` domino has been pushed to the left,
- `dominoes[i] = 'R'`, if the `ith` domino has been pushed to the right, and
- `dominoes[i] = '.'`, if the `ith` domino has not been pushed.

Return *a string representing the final state*.

 

**Example 1:**

```
Input: dominoes = "RR.L"
Output: "RR.L"
Explanation: The first domino expends no additional force on the second domino.
```

**Example 2:**

![img](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/05/18/domino.png)

```
Input: dominoes = ".L.R...LR..L.."
Output: "LL.RR.LLRRLL.."
```

 

**Constraints:**

- `n == dominoes.length`
- `1 <= n <= 10^5`
- `dominoes[i]` is either `'L'`, `'R'`, or `'.'`.

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
  string pushDominoes(string dominoes) {
    int len = dominoes.length();
    bool prevLeft = true;
    int prevPos = -1;
    for(int i = 0; i < len; ++i) {
      if(dominoes[i] == '.') continue;
      if(dominoes[i] == 'L') {
        if(prevLeft) {
          for(int j = prevPos + 1; j < i; ++j) dominoes[j] = 'L';
        } else {
          for(int left = prevPos + 1, right = i - 1; left < right; ++left, --right) {
            dominoes[left] = 'R';
            dominoes[right] = 'L';
          }
        }
        prevLeft = true;
        prevPos = i;
      } else {
        if(!prevLeft) for(int j = prevPos + 1; j < i; j++) dominoes[j] = 'R';
        prevLeft = false;
        prevPos = i;
      }
    }
    if(!prevLeft) {
      for(int i = prevPos + 1; i < len; ++i) dominoes[i] = 'R';
    }
    return dominoes;
  }
};

// Accepted
// 43/43 cases passed (21 ms)
// Your runtime beats 99.83 % of cpp submissions
// Your memory usage beats 94.28 % of cpp submissions (12.7 MB)
```
