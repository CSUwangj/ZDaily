+++
title = "2021-05-13 Daily-Challenge"
path = "2021-05-13-Daily-Challenge"
date = 2021-05-13 19:30:17+08:00
updated = 2021-05-13 18:39:46+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

I'm busy playing Dungeons & Fighters, so won't do pick up.

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/599/week-2-may-8th-may-14th/3741/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 13

## Description

**Ambiguous Coordinates**

We had some 2-dimensional coordinates, like `"(1, 3)"` or `"(2, 0.5)"`. Then, we removed all commas, decimal points, and spaces, and ended up with the string `s`. Return a list of strings representing all possibilities for what our original coordinates could have been.

Our original representation never had extraneous zeroes, so we never started with numbers like "00", "0.0", "0.00", "1.0", "001", "00.01", or any other number that can be represented with less digits. Also, a decimal point within a number never occurs without at least one digit occuring before it, so we never started with numbers like ".1".

The final answer list can be returned in any order. Also note that all coordinates in the final answer have exactly one space between them (occurring after the comma.)

```
Example 1:
Input: s = "(123)"
Output: ["(1, 23)", "(12, 3)", "(1.2, 3)", "(1, 2.3)"]
Example 2:
Input: s = "(00011)"
Output:  ["(0.001, 1)", "(0, 0.011)"]
Explanation: 
0.0, 00, 0001 or 00.01 are not allowed.
Example 3:
Input: s = "(0123)"
Output: ["(0, 123)", "(0, 12.3)", "(0, 1.23)", "(0.1, 23)", "(0.1, 2.3)", "(0.12, 3)"]
Example 4:
Input: s = "(100)"
Output: [(10, 0)]
Explanation: 
1.0 is not allowed.
```

 

**Note:**

- `4 <= s.length <= 12`.
- `s[0]` = "(", `s[s.length - 1]` = ")", and the other elements in `s` are digits.

## Solution

``` cpp
class Solution {
  vector<string> getCoordinate(string num) {
    if(num.length() > 1 && num.front() == '0' && num.back() == '0') return {};
    if(num.back() == '0') return {num};
    if(num.front() == '0') return {"0." + num.substr(1)};
    vector<string> result{num};
    for(int i = 1; i < num.length(); ++i) {
      result.push_back(num.substr(0, i) + "." + num.substr(i));
    }
    return result;
  }
public:
  vector<string> ambiguousCoordinates(string s) {
    int len = s.length();
    vector<string> answer;
    for(int i = 1; i < s.length() - 2; ++i) {
      for(auto first : getCoordinate(s.substr(1, i))) {
        for(auto second : getCoordinate(s.substr(1 + i, len - 2 - i))) {
          answer.push_back("(" + first + ", " + second + ")");
        }
      }
    }
    return answer;
  }
};
```
