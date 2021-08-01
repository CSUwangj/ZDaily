+++
title = "2021-04-26 Daily-Challenge"
path = "2021-04-26-Daily-Challenge"
date = 2021-04-26 18:48:00+08:00
updated = 2021-04-26 19:40:57+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Word Pattern](https://leetcode.com/problems/word-pattern/) and leetcode's [April LeetCoding Challenge](https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/596/week-4-april-22nd-april-28th/3721/) with `cpp`.

<!-- more -->

# Word Pattern

## Description

Given a `pattern` and a string `s`, find if `s` follows the same pattern.

Here **follow** means a full match, such that there is a bijection between a letter in `pattern` and a **non-empty** word in `s`.

 

**Example 1:**

```
Input: pattern = "abba", s = "dog cat cat dog"
Output: true
```

**Example 2:**

```
Input: pattern = "abba", s = "dog cat cat fish"
Output: false
```

**Example 3:**

```
Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
```

**Example 4:**

```
Input: pattern = "abba", s = "dog dog dog dog"
Output: false
```

 

**Constraints:**

- `1 <= pattern.length <= 300`
- `pattern` contains only lower-case English letters.
- `1 <= s.length <= 3000`
- `s` contains only lower-case English letters and spaces `' '`.
- `s` **does not contain** any leading or trailing spaces.
- All the words in `s` are separated by a **single space**.

## Solution

``` cpp
class Solution {
  int countWords(string &s) {
    bool isSpace = true;
    int result = 0;
    for(auto c : s) {
      result += (c != ' ') * isSpace;
      isSpace = c == ' ';
    }
    return result;
  }
  string nextWord(string &s, int &index) {
    while(s[index] == ' ') index += 1;
    int len = 0;
    while(index + len < s.length() && s[index + len] != ' ') len += 1;
    index += len;
    return s.substr(index - len, len);
  }
public:
  bool wordPattern(string pattern, string s) {
    if(pattern.length() != countWords(s)) return false;
    unordered_map<char, string> mp;
    unordered_map<string, int> cnt;
    int pos = 0;
    for(auto c : pattern) {
      auto word = nextWord(s, pos);
      if(mp.count(c) && mp[c] != word) return false;
      if(!mp.count(c)){
        mp[c] = word;
        cnt[word] += 1;
      } 
    }
    for(auto [_word, c] : cnt) if(c > 1) return false;
    return true;
  }
};
```

# April LeetCoding challenge 26

## Description

**Furthest Building You Can Reach**

You are given an integer array `heights` representing the heights of buildings, some `bricks`, and some `ladders`.

You start your journey from building `0` and move to the next building by possibly using bricks or ladders.

While moving from building `i` to building `i+1` (**0-indexed**),

- If the current building's height is **greater than or equal** to the next building's height, you do **not** need a ladder or bricks.
- If the current building's height is **less than** the next building's height, you can either use **one ladder** or `(h[i+1] - h[i])` **bricks**.

*Return the furthest building index (0-indexed) you can reach if you use the given ladders and bricks optimally.*

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/10/27/q4.gif)

```
Input: heights = [4,2,7,6,9,14,12], bricks = 5, ladders = 1
Output: 4
Explanation: Starting at building 0, you can follow these steps:
- Go to building 1 without using ladders nor bricks since 4 >= 2.
- Go to building 2 using 5 bricks. You must use either bricks or ladders because 2 < 7.
- Go to building 3 without using ladders nor bricks since 7 >= 6.
- Go to building 4 using your only ladder. You must use either bricks or ladders because 6 < 9.
It is impossible to go beyond building 4 because you do not have any more bricks or ladders.
```

**Example 2:**

```
Input: heights = [4,12,2,7,3,18,20,3,19], bricks = 10, ladders = 2
Output: 7
```

**Example 3:**

```
Input: heights = [14,3,19,3], bricks = 17, ladders = 0
Output: 3
```

 

**Constraints:**

- <code>1 <= heights.length <= 10<sup>5</sup></code>
- <code>1 <= heights[i] <= 10<sup>6</sup></code>
- <code>0 <= bricks <= 10<sup>9</sup></code>
- <code>0 <= ladders <= heights.length</code>


## Solution

``` cpp
class Solution {
public:
  int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    int len = heights.size();
    int pos = 0;
    priority_queue<int> q;
    for(;pos < len - 1; pos += 1) {
      // cout << pos << ' ' << bricks << ' ' << ladders << endl;
      int diff = heights[pos + 1] - heights[pos];
      if(diff <= 0) {
        continue;
      }
      if(diff <= bricks) {
        bricks -= diff;
        q.push(diff);
      } else {
        if(!ladders) break;
        if(q.size() && q.top() > diff) {
          bricks += q.top() - diff;
          q.pop();
          q.push(diff);
        }
        ladders -= 1;
      }
    }
    return pos;
  }
};
```
