+++
title = "2021-10-21 Daily-Challenge"
path = "2021-10-21-Daily-Challenge"
date = 2021-10-21 19:02:33+08:00
updated = 2021-10-21 19:22:18+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/insert-delete-getrandom-o1/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 21

## Description

**Insert Delete GetRandom O(1)**

Implement the `RandomizedSet` class:

- `RandomizedSet()` Initializes the `RandomizedSet` object.
- `bool insert(int val)` Inserts an item `val` into the set if not present. Returns `true` if the item was not present, `false` otherwise.
- `bool remove(int val)` Removes an item `val` from the set if present. Returns `true` if the item was present, `false` otherwise.
- `int getRandom()` Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the **same probability** of being returned.

You must implement the functions of the class such that each function works in **average** `O(1)` time complexity.

 

**Example 1:**

```
Input
["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
[[], [1], [2], [2], [], [1], [2], []]
Output
[null, true, false, true, 2, true, false, 2]

Explanation
RandomizedSet randomizedSet = new RandomizedSet();
randomizedSet.insert(1); // Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomizedSet.remove(2); // Returns false as 2 does not exist in the set.
randomizedSet.insert(2); // Inserts 2 to the set, returns true. Set now contains [1,2].
randomizedSet.getRandom(); // getRandom() should return either 1 or 2 randomly.
randomizedSet.remove(1); // Removes 1 from the set, returns true. Set now contains [2].
randomizedSet.insert(2); // 2 was already in the set, so return false.
randomizedSet.getRandom(); // Since 2 is the only number in the set, getRandom() will always return 2.
```

 

**Constraints:**

<ul>
	<li><code>-2<sup>31</sup> &lt;= val &lt;= 2<sup>31</sup> - 1</code></li>
	<li>At most <code>2 *&nbsp;</code><code>10<sup>5</sup></code> calls will be made to <code>insert</code>, <code>remove</code>, and <code>getRandom</code>.</li>
	<li>There will be <strong>at least one</strong> element in the data structure when <code>getRandom</code> is called.</li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class RandomizedSet {
  vector<int> container;
  map<int, int> index;
public:
  RandomizedSet() { }
  
  bool insert(int val) {
    if(index.count(val)) return false;
    index[val] = container.size();
    container.push_back(val);
    return true;
  }
  
  bool remove(int val) {
    if(!index.count(val)) return false;
    int i = index[val];
    int back = container.back();
    index[back] = i;
    container[i] = back;
    container.pop_back();
    index.erase(val);
    return true;
  }
  
  int getRandom() {
    return container[rand() % container.size()];
  }
};

// Accepted
// 19/19 cases passed (217 ms)
// Your runtime beats 61.75 % of cpp submissions
// Your memory usage beats 5.43 % of cpp submissions (97.8 MB)
```
