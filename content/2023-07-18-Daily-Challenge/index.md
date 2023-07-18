+++
updated = 2023-07-18T13:18:28+08:00
title = "2023-07-18 Daily Challenge"
path = "2023-07-18-Daily-Challenge"
date = 2023-07-18T13:18:28+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/lru-cache/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 18

## Description

**LRU Cache**

<p>Design a data structure that follows the constraints of a <strong><a href="https://en.wikipedia.org/wiki/Cache_replacement_policies#LRU" target="_blank">Least Recently Used (LRU) cache</a></strong>.</p>

<p>Implement the <code>LRUCache</code> class:</p>

<ul>
	<li><code>LRUCache(int capacity)</code> Initialize the LRU cache with <strong>positive</strong> size <code>capacity</code>.</li>
	<li><code>int get(int key)</code> Return the value of the <code>key</code> if the key exists, otherwise return <code>-1</code>.</li>
	<li><code>void put(int key, int value)</code> Update the value of the <code>key</code> if the <code>key</code> exists. Otherwise, add the <code>key-value</code> pair to the cache. If the number of keys exceeds the <code>capacity</code> from this operation, <strong>evict</strong> the least recently used key.</li>
</ul>

<p>The functions <code>get</code> and <code>put</code> must each run in <code>O(1)</code> average time complexity.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input</strong>
[&quot;LRUCache&quot;, &quot;put&quot;, &quot;put&quot;, &quot;get&quot;, &quot;put&quot;, &quot;get&quot;, &quot;put&quot;, &quot;get&quot;, &quot;get&quot;, &quot;get&quot;]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
<strong>Output</strong>
[null, null, null, 1, null, -1, null, -1, 3, 4]

<strong>Explanation</strong>
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= capacity &lt;= 3000</code></li>
	<li><code>0 &lt;= key &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= value &lt;= 10<sup>5</sup></code></li>
	<li>At most <code>2 * 10<sup>5</sup></code> calls will be made to <code>get</code> and <code>put</code>.</li>
</ul>


## Solution

``` cpp
class LRUCache {
  int capacity;
  list<int> LRU;
  unordered_map<int, int> kv;
  unordered_map<int, list<int>::iterator> position;
  
  void update(int key) {
    LRU.erase(position[key]);
    add(key);
  }
  
  void add(int key) {
    LRU.push_front(key);
    position[key] = LRU.begin();
  }
  
  void evict_last() {
    kv.erase(LRU.back());
    position.erase(LRU.back());
    LRU.pop_back(); 
  }
public:
  LRUCache(int capacity) : capacity(capacity) {}
  
  int get(int key) {
    if(kv.count(key)) {
      update(key);
      return kv[key];
    }
    return -1;
  }
  
  void put(int key, int value) {
    if(kv.count(key)) {
      update(key);
    } else {
      if(LRU.size() == capacity) evict_last();
      add(key);
    }
    kv[key] = value;
  }
};

// Accepted
// 22/22 cases passed (538 ms)
// Your runtime beats 27.06 % of cpp submissions
// Your memory usage beats 41.51 % of cpp submissions (175.8 MB)
```
