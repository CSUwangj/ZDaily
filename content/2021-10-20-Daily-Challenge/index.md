+++
title = "2021-10-20 Daily-Challenge"
path = "2021-10-20-Daily-Challenge"
date = 2021-10-20 14:34:51+08:00
updated = 2021-10-20 20:00:43+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/reverse-words-in-a-string/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 20

## Description

**Reverse Words in a String**

Given an input string `s`, reverse the order of the **words**.

A **word** is defined as a sequence of non-space characters. The **words** in `s` will be separated by at least one space.

Return *a string of the words in reverse order concatenated by a single space.*

**Note** that `s` may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

**Example 1:**

```
Input: s = "the sky is blue"
Output: "blue is sky the"
```

**Example 2:**

```
Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
```

**Example 3:**

```
Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
```

**Example 4:**

```
Input: s = "  Bob    Loves  Alice   "
Output: "Alice Loves Bob"
```

**Example 5:**

```
Input: s = "Alice does not even like bob"
Output: "bob like even not does Alice"
```

 

**Constraints:**

- `1 <= s.length <= 104`
- `s` contains English letters (upper-case and lower-case), digits, and spaces `' '`.
- There is **at least one** word in `s`.

 

**Follow-up:** If the string data type is mutable in your language, can you solve it **in-place** with `O(1)` extra space?

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
  string reverseWords(string s) {
    reverse(s.begin(), s.end());
    int len = s.length();
    bool hasSpace = true;
    int newLength = 0;
    for(int i = 0; i < len; ++i) {
      if(s[i] != ' ' || !hasSpace) {
        if(s[i] == ' ') hasSpace = true;
        else hasSpace = false;
        s[newLength] = s[i];
        newLength += 1;
      }
    }
    if(!newLength) return "";
    if(s[newLength-1] == ' ') newLength -= 1;
    s.resize(newLength);
    len = newLength;
    int begin = -1, end = -1;
    for(int i = 0; i < len; ++i) {
      if(s[i] != ' ') {
        if(begin == -1) begin = i;
        end = i+1;
      } else {
        if(begin != -1 && begin != end-1) {
          reverse(s.begin() + begin, s.begin() + end);
        }
        begin = -1;
        end = -1;
      }
    }
    if(begin != -1 && begin != end-1) reverse(s.begin() + begin, s.begin() + end);
    return move(s);
  }
};

// Accepted
// 57/57 cases passed (8 ms)
// Your runtime beats 42.75 % of cpp submissions
// Your memory usage beats 80.89 % of cpp submissions (7.1 MB)
```
