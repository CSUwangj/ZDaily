+++
updated = 2022-04-10 19:38:00+08:00
title = "2022-04-10 Daily-Challenge"
path = "2022-04-10-Daily-Challenge"
date = 2022-04-10 19:35:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/baseball-game/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 10

## Description

**Baseball Game**

You are  keeping score for a baseball game with strange rules. The game consists  of several rounds, where the scores of past rounds may affect future  rounds' scores.

At the beginning of the game, you start with an empty record. You are given a list of strings `ops`, where `ops[i]` is the `ith` operation you must apply to the record and is one of the following:

1. An integer `x` - Record a new score of `x`.
2. `"+"` - Record a new score that is the sum of the previous two scores. It is guaranteed there will always be two previous scores.
3. `"D"` - Record a new score that is double the previous score. It is guaranteed there will always be a previous score.
4. `"C"` - Invalidate the previous score, removing it from the record. It is guaranteed there will always be a previous score.

Return *the sum of all the scores on the record*.

 

**Example 1:**

```
Input: ops = ["5","2","C","D","+"]
Output: 30
Explanation:
"5" - Add 5 to the record, record is now [5].
"2" - Add 2 to the record, record is now [5, 2].
"C" - Invalidate and remove the previous score, record is now [5].
"D" - Add 2 * 5 = 10 to the record, record is now [5, 10].
"+" - Add 5 + 10 = 15 to the record, record is now [5, 10, 15].
The total sum is 5 + 10 + 15 = 30.
```

**Example 2:**

```
Input: ops = ["5","-2","4","C","D","9","+","+"]
Output: 27
Explanation:
"5" - Add 5 to the record, record is now [5].
"-2" - Add -2 to the record, record is now [5, -2].
"4" - Add 4 to the record, record is now [5, -2, 4].
"C" - Invalidate and remove the previous score, record is now [5, -2].
"D" - Add 2 * -2 = -4 to the record, record is now [5, -2, -4].
"9" - Add 9 to the record, record is now [5, -2, -4, 9].
"+" - Add -4 + 9 = 5 to the record, record is now [5, -2, -4, 9, 5].
"+" - Add 9 + 5 = 14 to the record, record is now [5, -2, -4, 9, 5, 14].
The total sum is 5 + -2 + -4 + 9 + 5 + 14 = 27.
```

**Example 3:**

```
Input: ops = ["1"]
Output: 1
```

 

**Constraints:**

- `1 <= ops.length <= 1000`
- `ops[i]` is `"C"`, `"D"`, `"+"`, or a string representing an integer in the range `[-3 * 10^4, 3 * 10^4]`.
- For operation `"+"`, there will always be at least two previous scores on the record.
- For operations `"C"` and `"D"`, there will always be at least one previous score on the record.

## Solution

``` cpp
class Solution {
public:
  int calPoints(vector<string>& ops) {
    vector<int> points;
    for(const auto &op : ops) {
      if (op[0] == 'C') {
        points.pop_back();
      } else if (op[0] == 'D') {
        points.push_back(points.back() * 2);
      } else if (op[0] == '+') {
        points.push_back(points.back() + points[points.size() - 2]);
      } else {
        points.push_back(stoi(op));
      }
    }
    return accumulate(points.begin(), points.end(), 0);
  }
};

// Accepted
// 39/39 cases passed (7 ms)
// Your runtime beats 43.82 % of cpp submissions
// Your memory usage beats 95.63 % of cpp submissions (8.3 MB)
```
