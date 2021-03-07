+++
title = "2021-03-07 Daily-Challenge"
path = "2021-03-07-Daily-Challenge"
date = 2021-03-07 16:45:12+08:00
updated = 2021-03-07 16:56:21+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Sunday, I gonna review the tasks I've done this week, and finish today's leetcode's [March LeetCoding Challenge](https://leetcode.com/explore/featured/card/march-leetcoding-challenge-2021/588/week-1-march-1st-march-7th/3663/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge7

**Design HashMap**

## Description

Design a HashMap without using any built-in hash table libraries.

To be specific, your design should include these functions:

- `put(key, value)` : Insert a (key, value) pair into the HashMap. If the value already exists in the HashMap, update the value.
- `get(key)`: Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
- `remove(key)` : Remove the mapping for the value key if this map contains the mapping for the key.


**Example:**

```
MyHashMap hashMap = new MyHashMap();
hashMap.put(1, 1);          
hashMap.put(2, 2);         
hashMap.get(1);            // returns 1
hashMap.get(3);            // returns -1 (not found)
hashMap.put(2, 1);          // update the existing value
hashMap.get(2);            // returns 1 
hashMap.remove(2);          // remove the mapping for 2
hashMap.get(2);            // returns -1 (not found) 
```


**Note:**

- All keys and values will be in the range of `[0, 1000000]`.
- The number of operations will be in the range of `[1, 10000]`.
- Please do not use the built-in HashMap library.

## Solution

this is a great problem, but not a good leetcode problem.

how to design a hash map is a classical data structure problem, you can learn from any of the textbooks, but when it comes to a leetcode problem with little statistics on data set, it's not as good as textbooks'.

``` cpp
class MyHashMap {
    vector<int> table;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        table.resize(1000001, -1);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        table[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return table[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        table[key] = -1;
    }
};
```
