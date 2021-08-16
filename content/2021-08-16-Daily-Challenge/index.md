+++
title = "2021-08-16 Daily-Challenge"
path = "2021-08-16-Daily-Challenge"
date = 2021-08-16 18:58:03+08:00
updated = 2021-08-16 19:32:56+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [LFU Cache](https://leetcode.com/problems/lfu-cache/description/) and leetcode's [August LeetCoding Challenge](https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/615/week-3-august-15th-august-21st/3892/) with `cpp`.

<!-- more -->

# LFU Cache

## Description

Design and implement a data structure for a [Least Frequently Used (LFU)](https://en.wikipedia.org/wiki/Least_frequently_used) cache.

Implement the `LFUCache` class:

- `LFUCache(int capacity)` Initializes the object with the `capacity` of the data structure.
- `int get(int key)` Gets the value of the `key` if the `key` exists in the cache. Otherwise, returns `-1`.
- `void put(int key, int value)` Update the value of the `key` if present, or inserts the `key` if not already present. When the cache reaches its `capacity`, it should invalidate and remove the **least frequently used** key before inserting a new item. For this problem, when there is a **tie** (i.e., two or more keys with the same frequency), the **least recently used** `key` would be invalidated.

To determine the least frequently used key, a **use counter** is maintained for each key in the cache. The key with the smallest **use counter** is the least frequently used key.

When a key is first inserted into the cache, its **use counter** is set to `1` (due to the `put` operation). The **use counter** for a key in the cache is incremented either a `get` or `put` operation is called on it.

The functions `get` and `put` must each run in `O(1)` average time complexity.

 

**Example 1:**

```
Input
["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, 3, null, -1, 3, 4]

Explanation
// cnt(x) = the use counter for key x
// cache=[] will show the last used order for tiebreakers (leftmost element is  most recent)
LFUCache lfu = new LFUCache(2);
lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
lfu.get(1);      // return 1
                 // cache=[1,2], cnt(2)=1, cnt(1)=2
lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
                 // cache=[3,1], cnt(3)=1, cnt(1)=2
lfu.get(2);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,1], cnt(3)=2, cnt(1)=2
lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
                 // cache=[4,3], cnt(4)=1, cnt(3)=2
lfu.get(1);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,4], cnt(4)=1, cnt(3)=3
lfu.get(4);      // return 4
                 // cache=[3,4], cnt(4)=2, cnt(3)=3
```

 

**Constraints:**

- `0 <= capacity <= 10^4`
- `0 <= key <= 10^5`
- `0 <= value <= 10^9`
- At most `2 * 10^5` calls will be made to `get` and `put`.

## Solution

``` cpp
class LFUCache {
  int capacity;
  int lowestFrequency = 0;
  unordered_map<int, int> kv;
  unordered_map<int, list<int>> freqList;
  unordered_map<int, int> frequencies;
  unordered_map<int, list<int>::iterator> pos;
  void updateFrequency(int key) {
    int frequency = frequencies[key];
    freqList[frequency].erase(pos[key]);
    if(freqList[lowestFrequency].empty()) {
      lowestFrequency += 1;
    }
    frequencies[key] += 1;
    freqList[frequency + 1].push_front(key);
    pos[key] = freqList[frequency + 1].begin();
  }
public:
  LFUCache(int cap): capacity(cap) {}
  
  int get(int key) {
    if(kv.count(key)) {
      updateFrequency(key);
      return kv[key];
    }
    return -1;
  }
  
  void put(int key, int value) {
    if(!capacity) return;
    if(kv.count(key)) {
      updateFrequency(key);
    } else {
      if(capacity == kv.size()) {
        int removedKey = freqList[lowestFrequency].back();
        // cout << "remove " << removedKey << endl; 
        kv.erase(removedKey);
        pos.erase(removedKey);
        freqList[lowestFrequency].pop_back();
      }
      freqList[0].push_front(key);
      pos[key] = freqList[0].begin();
      lowestFrequency = 0;
    }
    kv[key] = value;
  }
};

// Accepted
// 24/24 cases passed (476 ms)
// Your runtime beats 54.1 % of cpp submissions
// Your memory usage beats 53.17 % of cpp submissions (185.7 MB)
```

# August LeetCoding Challenge 16

## Description

**Range Sum Query - Immutable**

Given an integer array `nums`, handle multiple queries of the following type:

1. Calculate the **sum** of the elements of `nums` between indices `left` and `right` **inclusive** where `left <= right`.

Implement the `NumArray` class:

- `NumArray(int[] nums)` Initializes the object with the integer array `nums`.
- `int sumRange(int left, int right)` Returns the **sum** of the elements of `nums` between indices `left` and `right` **inclusive** (i.e. `nums[left] + nums[left + 1] + ... + nums[right]`).

 

**Example 1:**

```
Input
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
Output
[null, 1, -1, -3]

Explanation
NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3
```

 

**Constraints:**

- `1 <= nums.length <= 10^4`
- `-10^5 <= nums[i] <= 10^5`
- `0 <= left <= right < nums.length`
- At most `10^4` calls will be made to `sumRange`.


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class NumArray {
  vector<int> prefix{0};
public:
  NumArray(vector<int>& nums) {
    for(int i = 0; i < nums.size(); ++i) {
      prefix.push_back(prefix[i] + nums[i]);
    }
  }
  
  int sumRange(int left, int right) {
    return prefix[right + 1] - prefix[left];
  }
};

// Accepted
// 15/15 cases passed (20 ms)
// Your runtime beats 87.17 % of cpp submissions
// Your memory usage beats 11.03 % of cpp submissions (17.3 MB)
```
