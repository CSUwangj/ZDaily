+++
title = "2021-11-14 Daily-Challenge"
path = "2021-11-14-Daily-Challenge"
date = 2021-11-14 19:37:47+08:00
updated = 2021-11-14 20:08:10+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/iterator-for-combination/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 14

## Description

**Iterator for Combination**

Design the `CombinationIterator` class:

- `CombinationIterator(string characters, int combinationLength)` Initializes the object with a string `characters` of **sorted distinct** lowercase English letters and a number `combinationLength` as arguments.
- `next()` Returns the next combination of length `combinationLength` in **lexicographical order**.
- `hasNext()` Returns `true` if and only if there exists a next combination.

 

**Example 1:**

```
Input
["CombinationIterator", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[["abc", 2], [], [], [], [], [], []]
Output
[null, "ab", true, "ac", true, "bc", false]

Explanation
CombinationIterator itr = new CombinationIterator("abc", 2);
itr.next();    // return "ab"
itr.hasNext(); // return True
itr.next();    // return "ac"
itr.hasNext(); // return True
itr.next();    // return "bc"
itr.hasNext(); // return False
```

 

**Constraints:**

- `1 <= combinationLength <= characters.length <= 15`
- All the characters of `characters` are **unique**.
- At most `104` calls will be made to `next` and `hasNext`.
- It's guaranteed that all calls of the function `next` are valid.

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class CombinationIterator {
  bool _hasNext = true;
  string _next;
  string chars;
  string permutation;
  int len;
  int combLen;
public:
  CombinationIterator(string characters, int combinationLength) : chars(characters), combLen(combinationLength) {
    len = chars.length();
    _next = chars.substr(0, combLen);
    for(int i = 0; i < combLen; ++i) {
      permutation.push_back(i);
    }
  }

  string next() {
    string result = _next;
    if(_next.front() == chars[len - combLen]) {
      _hasNext = false;
    } else {
      int pos;
      for(pos = combLen - 1; pos >= 0 && permutation[pos] == pos + len - combLen; --pos) {}
      permutation[pos] += 1;
      _next[pos] = chars[permutation[pos]];
      for(int i = pos + 1; i < combLen; ++i) {
        permutation[i] = permutation[i - 1] + 1;
        _next[i] = chars[permutation[i]];
      }
    }
    return result;
  }

  bool hasNext() {
    return _hasNext;
  }
};

// Accepted
// 16/16 cases passed (8 ms)
// Your runtime beats 95.09 % of cpp submissions
// Your memory usage beats 87.95 % of cpp submissions (12.1 MB)
```
