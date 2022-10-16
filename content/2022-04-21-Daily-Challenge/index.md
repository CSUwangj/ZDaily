+++
updated = 2022-04-21 22:57:00+08:00
title = "2022-04-21 Daily-Challenge"
path = "2022-04-21-Daily-Challenge"
date = 2022-04-21 22:37:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/design-hashset/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 21

## Description

**Design HashSet**

Design a HashSet without using any built-in hash table libraries.

Implement `MyHashSet` class:

- `void add(key)` Inserts the value `key` into the HashSet.
- `bool contains(key)` Returns whether the value `key` exists in the HashSet or not.
- `void remove(key)` Removes the value `key` in the HashSet. If `key` does not exist in the HashSet, do nothing.

 

**Example 1:**

```
Input
["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
[[], [1], [2], [1], [3], [2], [2], [2], [2]]
Output
[null, null, null, true, false, null, true, null, false]

Explanation
MyHashSet myHashSet = new MyHashSet();
myHashSet.add(1);      // set = [1]
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(1); // return True
myHashSet.contains(3); // return False, (not found)
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(2); // return True
myHashSet.remove(2);   // set = [1]
myHashSet.contains(2); // return False, (already removed)
```

 

**Constraints:**

- `0 <= key <= 10^6`
- At most `10^4` calls will be made to `add`, `remove`, and `contains`.

## Solution

``` cpp
constexpr int MOD = 4001;
class MyHashSet {
  vector<vector<int>> container;
public:
  MyHashSet(): container(MOD) {}
  
  void add(int key) {
    int val = key;
    key %= MOD;
    for(auto v : container[key]) {
      if(v == val) return;
    }
    container[key].push_back(val);
  }
  
  void remove(int key) {
    int val = key;
    key %= MOD;
    auto it = container[key].begin();
    while(it != container[key].end() && *it != val) {
      ++it;
    }
    if(it != container[key].end()) {
      container[key].erase(it);
    }
  }
  
  bool contains(int key) {
    int val = key;
    key %= MOD;
    for(auto v : container[key]) {
      if(v == val) return true;
    }
    return false;
  }
};

// Accepted
// 32/32 cases passed (93 ms)
// Your runtime beats 87.94 % of cpp submissions
// Your memory usage beats 39.75 % of cpp submissions (43.9 MB)
```
