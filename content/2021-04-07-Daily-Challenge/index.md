+++
title = "2021-04-07 Daily-Challenge"
path = "2021-04-07-Daily-Challenge"
date = 2021-04-07 19:40:02+08:00
updated = 2021-04-07 19:56:35+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Number of Boomerangs](https://leetcode.com/problems/number-of-boomerangs/) and leetcode's [April LeetCoding Challenge](https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/593/week-1-april-1st-april-7th/3699/) with `cpp`.

<!-- more -->

# Number of Boomerangs

## Description

You are given `n` `points` in the plane that are all **distinct**, where `points[i] = [xi, yi]`. A **boomerang** is a tuple of points `(i, j, k)` such that the distance between `i` and `j` equals the distance between `i` and `k` **(the order of the tuple matters)**.

Return *the number of boomerangs*.

 

**Example 1:**

```
Input: points = [[0,0],[1,0],[2,0]]
Output: 2
Explanation: The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]].
```

**Example 2:**

```
Input: points = [[1,1],[2,2],[3,3]]
Output: 2
```

**Example 3:**

```
Input: points = [[1,1]]
Output: 0
```

 

**Constraints:**

- `n == points.length`
- `1 <= n <= 500`
- `points[i].length == 2`
- `-104 <= xi, yi <= 104`
- All the points are **unique**.

## Solution

``` cpp
constexpr int distance(int x1, int y1, int x2, int y2) {
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

class Solution {
public:
  int numberOfBoomerangs(vector<vector<int>>& points) {
    int len = points.size();
    int answer = 0;
    for(auto &p : points) {
      unordered_map<int, int> cnt;
      for(auto &pp : points) {
        int d = distance(p[0], p[1], pp[0], pp[1]);
        answer += 2 * cnt[d];
        cnt[d] += 1;
      }
    }
    return answer;
  }
};
```

# April LeetCoding challenge7

**Determine if String Halves Are Alike**

You are given a string `s` of even length. Split this string into two halves of equal lengths, and let `a` be the first half and `b` be the second half.

Two strings are **alike** if they have the same number of vowels (`'a'`, `'e'`, `'i'`, `'o'`, `'u'`, `'A'`, `'E'`, `'I'`, `'O'`, `'U'`). Notice that `s` contains uppercase and lowercase letters.

Return `true` *if* `a` *and* `b` *are **alike***. Otherwise, return `false`.

 

**Example 1:**

```
Input: s = "book"
Output: true
Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.
```

**Example 2:**

```
Input: s = "textbook"
Output: false
Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2. Therefore, they are not alike.
Notice that the vowel o is counted twice.
```

**Example 3:**

```
Input: s = "MerryChristmas"
Output: false
```

**Example 4:**

```
Input: s = "AbCdEfGh"
Output: true
```

 

**Constraints:**

- `2 <= s.length <= 1000`
- `s.length` is even.
- `s` consists of **uppercase and lowercase** letters.

## Solution

``` cpp
constexpr int vowel(char c) {
  switch(c) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
      return 1;
  }
  return 0;
}
class Solution {
public:
  bool halvesAreAlike(string s) {
    int front = 0;
    int back = 0;
    int len = s.length();
    for(int i = 0; i < len / 2; ++i) {
      front += vowel(s[i]);
    }
    for(int i = len / 2; i < len; ++i) {
      back += vowel(s[i]);
    }
    return front == back;
  }
};
```
