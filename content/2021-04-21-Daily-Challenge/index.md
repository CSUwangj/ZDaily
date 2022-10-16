+++
title = "2021-04-21 Daily-Challenge"
path = "2021-04-21-Daily-Challenge"
date = 2021-04-21 18:35:27+08:00
updated = 2021-04-21 19:00:51+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Count Items Matching a Rule](https://leetcode.com/problems/count-items-matching-a-rule/)  and leetcode's [April LeetCoding Challenge](https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/595/week-3-april-15th-april-21st/3715/) with `cpp`.

<!-- more -->

# Count Items Matching a Rule

## Description

You are given an array `items`, where each `items[i] = [typei, colori, namei]` describes the type, color, and name of the `ith` item. You are also given a rule represented by two strings, `ruleKey` and `ruleValue`.

The `ith` item is said to match the rule if **one** of the following is true:

- `ruleKey == "type"` and `ruleValue == typei`.
- `ruleKey == "color"` and `ruleValue == colori`.
- `ruleKey == "name"` and `ruleValue == namei`.

Return *the number of items that match the given rule*.

 

**Example 1:**

```
Input: items = [["phone","blue","pixel"],["computer","silver","lenovo"],["phone","gold","iphone"]], ruleKey = "color", ruleValue = "silver"
Output: 1
Explanation: There is only one item matching the given rule, which is ["computer","silver","lenovo"].
```

**Example 2:**

```
Input: items = [["phone","blue","pixel"],["computer","silver","phone"],["phone","gold","iphone"]], ruleKey = "type", ruleValue = "phone"
Output: 2
Explanation: There are only two items matching the given rule, which are ["phone","blue","pixel"] and ["phone","gold","iphone"]. Note that the item ["computer","silver","phone"] does not match.
```

 

**Constraints:**

- <code>1 <= items.length <= 10<sup>4</sup></code>
- `1 <= typei.length, colori.length, namei.length, ruleValue.length <= 10`
- `ruleKey` is equal to either `"type"`, `"color"`, or `"name"`.
- All strings consist only of lowercase letters.

## Solution

``` cpp
static auto x = []() {ios_base::sync_with_stdio(false); cin.tie(NULL); return NULL; }();
class Solution {
public:
  int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
    int index = ruleKey[0] == 't' ? 0 :
      ruleKey[0] == 'c' ? 1 : 2;
    return count_if(items.begin(), items.end(), [&](const auto &item){
      return item[index] == ruleValue;
    });
  }
};
```

# April LeetCoding challenge 21

## Description

**Triangle**

Given a `triangle` array, return *the minimum path sum from top to bottom*.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index `i` on the current row, you may move to either index `i` or index `i + 1` on the next row.

 

**Example 1:**

```
Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
```

**Example 2:**

```
Input: triangle = [[-10]]
Output: -10
```

 

**Constraints:**

- `1 <= triangle.length <= 200`
- `triangle[0].length == 1`
- `triangle[i].length == triangle[i - 1].length + 1`
- <code>-10<sup>4</sup> <= triangle[i][j] <= 10<sup>4</sup></code>

 

**Follow up:** Could you do this using only `O(n)` extra space, where `n` is the total number of rows in the triangle?

## Solution

dp forward

``` cpp
class Solution {
public:
  int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<int> dp(n, INT_MAX);
    dp[0] = triangle.front().front();
    for(int i = 1; i < n; ++i) {
      for(int j = i; j >= 0; --j) {
        if(j == i) dp[j] = dp[j - 1];
        else if(j) dp[j] = min(dp[j], dp[j - 1]);
        dp[j] += triangle[i][j];
      }
    }
    return *min_element(dp.begin(), dp.end());
  }
};
```

dp backward

``` cpp
class Solution {
public:
  int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<int> dp(n + 1, 0);
    for(int i = n - 1; i >= 0; --i) {
      for(int j = 0; j <= i; ++j) {
        dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
      }
    }
    return dp[0];
  }
};
```
