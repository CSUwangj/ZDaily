+++
updated = 2022-04-22 20:20:00+08:00
title = "2022-04-22 Daily-Challenge"
path = "2022-04-22-Daily-Challenge"
date = 2022-04-22 22:18:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/design-hashmap/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 22

## Description

**Design HashMap**

Design a HashMap without using any built-in hash table libraries.

Implement the `MyHashMap` class:

- `MyHashMap()` initializes the object with an empty map.
- `void put(int key, int value)` inserts a `(key, value)` pair into the HashMap. If the `key` already exists in the map, update the corresponding `value`.
- `int get(int key)` returns the `value` to which the specified `key` is mapped, or `-1` if this map contains no mapping for the `key`.
- `void remove(key)` removes the `key` and its corresponding `value` if the map contains the mapping for the `key`.

 

**Example 1:**

```
Input
["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
[[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
Output
[null, null, null, 1, -1, null, 1, null, -1]

Explanation
MyHashMap myHashMap = new MyHashMap();
myHashMap.put(1, 1); // The map is now [[1,1]]
myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
myHashMap.get(1);    // return 1, The map is now [[1,1], [2,2]]
myHashMap.get(3);    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
myHashMap.get(2);    // return 1, The map is now [[1,1], [2,1]]
myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
myHashMap.get(2);    // return -1 (i.e., not found), The map is now [[1,1]]
```

 

**Constraints:**

- `0 <= key, value <= 10^6`
- At most `10^4` calls will be made to `put`, `get`, and `remove`.

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
constexpr int MOD = 4001;
class MyHashMap {
  vector<vector<pair<int, int>>> container;
public:
  /** Initialize your data structure here. */
  MyHashMap(): container(MOD) {}
  
  /** value will always be non-negative. */
  void put(int key, int value) {
    int val = key;
    key %= MOD;
    for(auto &[k, v] : container[key]) {
      if(k == val) {
        v = value;
        return;
      }
    }
    container[key].push_back({val, value});
  }
  
  /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
  int get(int key) {
    int val = key;
    key %= MOD;
    for(auto [k, v] : container[key]) {
      if(k == val) return v;
    }
    return -1;
  }
  
  /** Removes the mapping of the specified value key if this map contains a mapping for the key */
  void remove(int key) {
    int val = key;
    key %= MOD;
    auto it = container[key].begin();
    while(it != container[key].end() && it->first != val) {
      ++it;
    }
    if(it != container[key].end()) {
      container[key].erase(it);
    }
  }
};

// Accepted
// 36/36 cases passed (110 ms)
// Your runtime beats 94.72 % of cpp submissions
// Your memory usage beats 60.03 % of cpp submissions (55.2 MB)
```
