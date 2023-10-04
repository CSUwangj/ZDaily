+++
updated = 2023-10-04T14:40:10+08:00
title = "2023-10-04 Daily Challenge"
path = "2023-10-04-Daily-Challenge"
date = 2023-10-04T14:40:10+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/design-hashmap/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 4

## Description

**Design HashMap**

<p>Design a HashMap without using any built-in hash table libraries.</p>

<p>Implement the <code>MyHashMap</code> class:</p>

<ul>
	<li><code>MyHashMap()</code> initializes the object with an empty map.</li>
	<li><code>void put(int key, int value)</code> inserts a <code>(key, value)</code> pair into the HashMap. If the <code>key</code> already exists in the map, update the corresponding <code>value</code>.</li>
	<li><code>int get(int key)</code> returns the <code>value</code> to which the specified <code>key</code> is mapped, or <code>-1</code> if this map contains no mapping for the <code>key</code>.</li>
	<li><code>void remove(key)</code> removes the <code>key</code> and its corresponding <code>value</code> if the map contains the mapping for the <code>key</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input</strong>
[&quot;MyHashMap&quot;, &quot;put&quot;, &quot;put&quot;, &quot;get&quot;, &quot;get&quot;, &quot;put&quot;, &quot;get&quot;, &quot;remove&quot;, &quot;get&quot;]
[[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
<strong>Output</strong>
[null, null, null, 1, -1, null, 1, null, -1]

<strong>Explanation</strong>
MyHashMap myHashMap = new MyHashMap();
myHashMap.put(1, 1); // The map is now [[1,1]]
myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
myHashMap.get(1);    // return 1, The map is now [[1,1], [2,2]]
myHashMap.get(3);    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
myHashMap.get(2);    // return 1, The map is now [[1,1], [2,1]]
myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
myHashMap.get(2);    // return -1 (i.e., not found), The map is now [[1,1]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= key, value &lt;= 10<sup>6</sup></code></li>
	<li>At most <code>10<sup>4</sup></code> calls will be made to <code>put</code>, <code>get</code>, and <code>remove</code>.</li>
</ul>


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
// 36/36 cases passed (95 ms)
// Your runtime beats 92.1 % of cpp submissions
// Your memory usage beats 59.66 % of cpp submissions (55.2 MB)
```
