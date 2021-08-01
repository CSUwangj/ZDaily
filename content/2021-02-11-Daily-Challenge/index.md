+++
title = "2021-02-11 Daily-Challenge"
path = "2021-02-11-Daily-Challenge"
date = 2021-02-11 10:21:16+08:00
updated = 2021-02-11 16:35:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

**HAPPY NEW YEAR!!!!**

Today I have done [Random Point in Non-overlapping Rectangles](https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/) and leetcode's [February LeetCoding Challenge](https://leetcode.com/explore/featured/card/february-leetcoding-challenge-2021/585/week-2-february-8th-february-14th/3636/) with `cpp`.

<!-- more -->

# Random Point in Non-overlapping Rectangles

## Description

Given a list of **non-overlapping** axis-aligned rectangles `rects`, write a function `pick` which randomly and uniformily picks an **integer point** in the space covered by the rectangles.

Note:

1. An **integer point** is a point that has integer coordinates. 
2. A point on the perimeter of a rectangle is **included** in the space covered by the rectangles. 
3. `i`th rectangle = `rects[i]` = `[x1,y1,x2,y2]`, where `[x1, y1]` are the integer coordinates of the bottom-left corner, and `[x2, y2]` are the integer coordinates of the top-right corner.
4. length and width of each rectangle does not exceed `2000`.
5. `1 <= rects.length <= 100`
6. `pick` return a point as an array of integer coordinates `[p_x, p_y]`
7. `pick` is called at most `10000` times.

**Example 1:**

```
Input: 
["Solution","pick","pick","pick"]
[[[[1,1,5,5]]],[],[],[]]
Output: 
[null,[4,1],[4,1],[3,3]]
```

**Example 2:**

```
Input: 
["Solution","pick","pick","pick","pick","pick"]
[[[[-2,-2,-1,-1],[1,0,3,0]]],[],[],[],[],[]]
Output: 
[null,[-1,-2],[2,0],[-2,-1],[3,0],[-2,-2]]
```

**Explanation of Input Syntax:**

The input is two lists: the subroutines called and their arguments. `Solution`'s constructor has one argument, the array of rectangles `rects`. `pick` has no arguments. Arguments are always wrapped with a list, even if there aren't any.

## Solution

``` cpp
class Solution {
    vector<vector<int>> rects;
    vector<int> prefix;
    random_device rd;
    mt19937 generator;
    uniform_int_distribution<int> distribution;
public:
    Solution(vector<vector<int>>& rects): rects(rects){
        int len = rects.size();
        prefix = vector<int>{0};
        for(int i = 0; i < len; ++i) {
            prefix.push_back(prefix[i] + (rects[i][2] - rects[i][0] + 1) * (rects[i][3] - rects[i][1] + 1));
        }
        distribution = uniform_int_distribution<int>(0, prefix.back()-1);
        generator = mt19937(rd());
    }
    
    vector<int> pick() {
        int number = distribution(generator);
        auto it = upper_bound(prefix.begin(), prefix.end(), number);
        --it;
        int offset = distance(prefix.begin(), it);
        number -= *it;
        int width = rects[offset][2] - rects[offset][0] + 1;
        int x = rects[offset][0] + (number % width);
        int y = rects[offset][1] + (number / width);
        return vector<int>{x, y};
    }
};
```

# February LeetCoding Challenge 11

## Description

**Valid Anagram**

Given two strings *s* and *t* , write a function to determine if *t* is an anagram of *s*.

**Example 1:**

```
Input: s = "anagram", t = "nagaram"
Output: true
```

**Example 2:**

```
Input: s = "rat", t = "car"
Output: false
```

**Note:**
You may assume the string contains only lowercase alphabets.

**Follow up:**
What if the inputs contain unicode characters? How would you adapt your solution to such case?

## Solution

``` cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
```

if inputs contain unicode characters, I would switch to Rust to solve it XD

if I need to use cpp to solve it, I would use a map to count the number of every character.
