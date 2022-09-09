+++
updated = 2022-09-09 18:14:00+08:00
title = "2022-09-09 Daily-Challenge"
path = "2022-09-09-Daily-Challenge"
date = 2022-09-09 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 9

## Description

**The Number of Weak Characters in the Game**

You are playing a game that contains multiple characters, and each of the characters has **two** main properties: **attack** and **defense**. You are given a 2D integer array `properties` where `properties[i] = [attacki, defensei]` represents the properties of the `ith` character in the game.

A character is said to be **weak** if any other character has **both** attack and defense levels **strictly greater** than this character's attack and defense levels. More formally, a character `i` is said to be **weak** if there exists another character `j` where `attackj > attacki` and `defensej > defensei`.

Return *the number of **weak** characters*.

 

**Example 1:**

```
Input: properties = [[5,5],[6,3],[3,6]]
Output: 0
Explanation: No character has strictly greater attack and defense than the other.
```

**Example 2:**

```
Input: properties = [[2,2],[3,3]]
Output: 1
Explanation: The first character is weak because the second character has a strictly greater attack and defense.
```

**Example 3:**

```
Input: properties = [[1,5],[10,4],[4,3]]
Output: 1
Explanation: The third character is weak because the second character has a strictly greater attack and defense.
```

 

**Constraints:**

- `2 <= properties.length <= 10^5`
- `properties[i].length == 2`
- `1 <= attacki, defensei <= 10^5`

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
  int numberOfWeakCharacters(vector<vector<int>>& properties) {
    sort(properties.begin(), properties.end(), [](const vector<int> &a, const vector<int> &b){
      return a[0] > b[0] || (a[0] == b[0] && a[1] > b[1]);
    });
    int mmax = 0;
    int cur = 0;
    int curMax = 0;
    int answer = 0;
    for(const auto &property : properties) {
      if(property[0] != cur) {
        cur = property[0];
        mmax = max(mmax, curMax);
        curMax = property[1];
      }
      if(property[1] < mmax) {
        answer += 1;
      }
    }
    return answer;
  }
};

// Accepted
// 44/44 cases passed (1242 ms)
// Your runtime beats 37.02 % of cpp submissions
// Your memory usage beats 99.91 % of cpp submissions (124.7 MB)
```
