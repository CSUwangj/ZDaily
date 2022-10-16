+++
updated = 2022-10-06 18:14:00+08:00
title = "2022-10-06 Daily-Challenge"
path = "2022-10-06-Daily-Challenge"
date = 2022-10-06 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/time-based-key-value-store/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 6

## Description

**Time Based Key-Value Store**

Design a  time-based key-value data structure that can store multiple values for  the same key at different time stamps and retrieve the key's value at a  certain timestamp.

Implement the `TimeMap` class:

- `TimeMap()` Initializes the object of the data structure.
- `void set(String key, String value, int timestamp)` Stores the key `key` with the value `value `at the given time `timestamp`.
- `String get(String key, int timestamp)` Returns a value such that `set` was called previously, with `timestamp_prev <= timestamp`. If there are multiple such values, it returns the value associated with the largest `timestamp_prev`. If there are no values, it returns `""`.

 

**Example 1:**

```
Input
["TimeMap", "set", "get", "get", "set", "get", "get"]
[[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]
Output
[null, null, "bar", "bar", null, "bar2", "bar2"]

Explanation
TimeMap timeMap = new TimeMap();
timeMap.set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1.
timeMap.get("foo", 1);         // return "bar"
timeMap.get("foo", 3);         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
timeMap.set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4.
timeMap.get("foo", 4);         // return "bar2"
timeMap.get("foo", 5);         // return "bar2"
```

 

**Constraints:**

- `1 <= key.length, value.length <= 100`
- `key` and `value` consist of lowercase English letters and digits.
- `1 <= timestamp <= 10^7`
- All the timestamps `timestamp` of `set` are strictly increasing.
- At most `2 * 10^5` calls will be made to `set` and `get`.

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class TimeMap {
  unordered_map<string, map<int, string, std::greater<int>>> container;
public:
  TimeMap() {}
  
  void set(string key, string value, int timestamp) {
    container[key][timestamp] = value;
  }
  
  string get(string key, int timestamp) {
    if(!container.count(key)) return "";
    auto it = container[key].lower_bound(timestamp);
    if(it == container[key].end()) return "";
    return it->second;
  }
};

// Accepted
// 48/48 cases passed (618 ms)
// Your runtime beats 49.72 % of cpp submissions
// Your memory usage beats 6.52 % of cpp submissions (131.9 MB)
```
