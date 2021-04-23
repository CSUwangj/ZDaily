+++
title = "2021-04-15 Daily-Challenge"
path = "2021-04-15-Daily-Challenge"
date = 2021-04-15 17:59:29+08:00
updated = 2021-04-15 19:56:43+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [LFU Cache](https://leetcode.com/problems/lfu-cache/) and leetcode's [April LeetCoding Challenge](https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/594/week-2-april-8th-april-14th/3706/) with `cpp`.

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

- `0 <= capacity, key, value <= 104`
- At most `105` calls will be made to `get` and `put`.

 

**Follow up:** Could you do both operations in `O(1)` time complexity?

## Solution

worst case with $O(n)$ `get` and $O(n)$ `put`, average with $O(log n)$ `get` and $O(log n)$ `put`

``` cpp
class LFUCache {
  int capacity;
  multimap<int, int, greater<int>> mp;
  unordered_map<int, int> freq;
  unordered_map<int, int> kv;
  unordered_map<int, multimap<int, int, greater<int>>::iterator> its;
  void updateFreq(int key) {
    int f = freq[key];
    auto it = its[key];
    mp.erase(it);
    it = mp.emplace_hint(mp.lower_bound(f + 1), make_pair(f + 1, key)); 
    freq[key] = f + 1;
    its[key] = it;
  }
public:
  LFUCache(int cap) : capacity(cap) {}

  int get(int key) {
    if(!kv.count(key)) return -1;
    updateFreq(key);
    return kv[key];
  }

  void put(int key, int value) {
    // cout << "put :" << key << endl;
    if(!capacity) return;
    if(kv.count(key)) {
      updateFreq(key);
    } else{
      if(mp.size() == capacity) {
        auto it = mp.end();
        --it;
        kv.erase(it->second);
        mp.erase(it);
      }
      auto it = mp.emplace_hint(mp.lower_bound(1), make_pair(1, key));
      its[key] = it;
      freq[key] = 1;
    } 
    kv[key] = value;
  }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```

$O(1)$ `get` and $O(1)$ `put`

``` cpp
class LFUCache {
  int capacity;
  list<int> container;
  unordered_map<int, int> freq;
  unordered_map<int, int> kv;
  unordered_map<int, list<int>::iterator> its;
  unordered_map<int, list<int>::iterator> freqIts;
  void updateFreq(int key) {
    auto it = its[key];
    list<int>::iterator newIt;
    int f = freq[key];
    if(freqIts.count(f + 1)) {
      newIt = container.insert(freqIts[f + 1], key);
    } else {
      newIt = container.insert(freqIts[f], key);
    }
    if(freqIts[f] == it) {
      auto nextIt = freqIts[f];
      ++nextIt;
      if(nextIt != container.end() && freq[*nextIt] == f) {
        freqIts[f] = nextIt;
      } else {
        freqIts.erase(f);
      }
    }
    freqIts[f + 1] = newIt;
    freq[key] = f + 1;
    its[key] = newIt;
    container.erase(it);
  }
  
  void removeLast() {
    auto it = container.end();
    --it;
    kv.erase(*it);
    int f = freq[*it];
    if(freqIts[f] == it){
      freqIts.erase(f);
    }
    container.erase(it);
  }
public:
  LFUCache(int cap) : capacity(cap) {}

  int get(int key) {
    // cout << "get :" << container.size() << endl;
    if(!kv.count(key)) return -1;
    // cout << "get update" << endl;
    updateFreq(key);
    // cout << "get update success" << endl;
    return kv[key];
  }

  void put(int key, int value) {
    // cout << "put :" << container.size() << endl;
    if(!capacity) return;
    if(kv.count(key)) {
      updateFreq(key);
    } else {
      if(container.size() == capacity) {
        removeLast();
      }
      freq[key] = 1;
      list<int>::iterator newIt;
      if(freqIts.count(1)) {
        newIt = container.insert(freqIts[1], key);
      } else {
        newIt = container.insert(container.end(), key);
      }
      its[key] = newIt;
      freqIts[1] = newIt;
    }
    kv[key] = value;
  }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```

I copy the fastest here for my further learning

``` cpp
#include<bits/stdc++.h>
using namespace std;
int const N = (int)1e4 + 1;

struct Data{
  int value, count, time, pq_idx;
  Data(){
    value = -1, count = 0, time = 0, pq_idx = -1;
  }
};

Data db[N];

void init(){
  for(int i=0; i<N; i++){
    db[i].value = -1, db[i].count = 0, db[i].time = 0, db[i].pq_idx = -1;
  }
}

bool operator> (const Data& a, const Data& b){
  if(a.count != b.count) return a.count > b.count;
  return a.time > b.time;
}

class LFUCache {
private:
  int heap[N];
  int size = 0;
  int tCnt = 0;
  int time = 0;
  int capacity = 0;

  void bubbleDown(int idx){
    while(2*idx+1 < size){
      int left = 2*idx+1;
      if(left+1 < size && db[heap[left]] > db[heap[left+1]]) left += 1;
      if(db[heap[idx]] > db[heap[left]]){
        swap(db[heap[idx]].pq_idx, db[heap[left]].pq_idx);
        swap(heap[idx], heap[left]);
        idx = left;
      }else{
        break;
      }
    }
  }

  void update(int pidx){
    bubbleDown(pidx);
  }

  int pop(){
    swap(db[heap[0]].pq_idx, db[heap[size-1]].pq_idx);
    swap(heap[0], heap[size-1]);
    size--;
    bubbleDown(0);
    return heap[size];
  }

  void bubbleUp(int idx){
    while(idx > 0 && db[heap[(idx-1)/2]] > db[heap[idx]]){
      swap(db[heap[(idx-1)/2]].pq_idx, db[heap[idx]].pq_idx);
      swap(heap[idx], heap[(idx-1)/2]);
      idx = (idx-1)/2;
    } 
  }

  void push(int key){
    db[key].pq_idx = size;
    heap[size] = key;
    size++;
    bubbleUp(size-1);
  }
      
public:
  LFUCache(int c) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int size = 0;
    int tCnt = 0;
    int time = 0;
    capacity = c;
    init();
  }
  
  int get(int key) {
    time++;
    if(db[key].value == -1) return -1;
    db[key].count += 1;
    db[key].time = time;
    update(db[key].pq_idx);
    return db[key].value;
  }
  
  void put(int key, int value) {
    if(capacity == 0) return;
    time++;
    if(db[key].value != -1){
      db[key].count += 1;
      db[key].value = value;
      db[key].time = time;
      update(db[key].pq_idx);
      return;
    }else if(tCnt == capacity){
      int idx = pop();
      db[idx].value = -1;
      tCnt--;
    }
    db[key].count = 1;
    db[key].value = value;
    db[key].time = time;
    push(key);
    tCnt++;
  }
};
```

# April LeetCoding challenge15

## Description

**Fibonacci Number**

The **Fibonacci numbers**, commonly denoted `F(n)` form a sequence, called the **Fibonacci sequence**, such that each number is the sum of the two preceding ones, starting from `0` and `1`. That is,

```
F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
```

Given `n`, calculate `F(n)`.

 

**Example 1:**

```
Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
```

**Example 2:**

```
Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
```

**Example 3:**

```
Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
```

 

**Constraints:**

- `0 <= n <= 30`

## Solution

iterative way

``` cpp
class Solution {
public:
  int fib(int n) {
    int a = 0;
    int b = 1;
    for(int i = 0; i < n; ++i) {
      int c = a + b;
      a = b;
      b = c;
    }
    return a;
  }
};
```

divide and conquer way

``` cpp
struct mat {
  int val[2][2] = {};
};

const mat base = {
  .val = {{1, 1}, {1, 0}}
};

constexpr mat multiply(mat a, mat b) {
  mat result;
  result.val[0][0] = a.val[0][0] * b.val[0][0] + a.val[0][1] * b.val[1][0];
  result.val[0][1] = a.val[0][0] * b.val[0][1] + a.val[0][1] * b.val[1][1];
  result.val[1][0] = a.val[1][0] * b.val[0][0] + a.val[1][1] * b.val[1][0];
  result.val[1][1] = a.val[1][0] * b.val[0][1] + a.val[1][1] * b.val[1][1];
  return result;
}

constexpr mat exp(mat b, int e) {
  mat result = {
    .val = {{1, 0}, {0, 1}}
  };
  while(e) {
    if(e & 1) {
      result = multiply(result, b);
    }
    b = multiply(b, b);
    e >>= 1;
  }
  return result;
}

class Solution {
public:
  int fib(int n) {
    mat result = { .val = {{1, 0}, {0, 0}} };
    result = multiply(result, exp(base, n));
    return result.val[0][1];
  }
};

//  a b  \/  1 1  --  a+b b
//  0 0  /\  1 0  --   0  0
```
