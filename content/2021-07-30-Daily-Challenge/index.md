+++
title = "2021-07-30 Daily-Challenge"
path = "2021-07-30-Daily-Challenge"
date = 2021-07-30 18:03:22+08:00
updated = 2021-07-30 19:03:44+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/description/) and leetcode's [July LeetCoding Challenge](https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/612/week-5-july-29th-july-31st/3832/) with `cpp`.

<!-- more -->

# Range Sum Query - Immutable

## Description

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

# July LeetCoding Challenge30

## Description

**Map Sum Pairs**

Implement the `MapSum` class:

- `MapSum()` Initializes the `MapSum` object.
- `void insert(String key, int val)` Inserts the `key-val` pair into the map. If the `key` already existed, the original `key-value` pair will be overridden to the new one.
- `int sum(string prefix)` Returns the sum of all the pairs' value whose `key` starts with the `prefix`.

 

**Example 1:**

```
Input
["MapSum", "insert", "sum", "insert", "sum"]
[[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
Output
[null, null, 3, null, 5]

Explanation
MapSum mapSum = new MapSum();
mapSum.insert("apple", 3);  
mapSum.sum("ap");           // return 3 (apple = 3)
mapSum.insert("app", 2);    
mapSum.sum("ap");           // return 5 (apple + app = 3 + 2 = 5)
```

 

**Constraints:**

- `1 <= key.length, prefix.length <= 50`
- `key` and `prefix` consist of only lowercase English letters.
- `1 <= val <= 1000`
- At most `50` calls will be made to `insert` and `sum`.

## Solution

``` cpp
struct Node {
  int sum = 0;
  Node *children[26] = {};
};
class MapSum {
  Node *root = nullptr;
  unordered_map<string, int> kv;
public:
  MapSum() {
    root = new Node();
  }
  
  void insert(string key, int val) {
    int diff = val;
    if(kv.count(key)) diff = val - kv[key];
    auto cur = root;
    for(auto c : key) {
      if(!(cur->children[c - 'a'])) cur->children[c - 'a'] = new Node();
      cur = cur->children[c - 'a'];
      cur->sum += diff;
    }
    kv[key] = val;
  }
  
  int sum(string prefix) {
    auto cur = root;
    for(auto c : prefix) {
      if(!(cur->children[c - 'a'])) return 0;
      cur = cur->children[c - 'a'];
    }
    return cur->sum;
  }
};

// Accepted
// 34/34 cases passed (4 ms)
// Your runtime beats 68.72 % of cpp submissions
// Your memory usage beats 60.16 % of cpp submissions (8.1 MB)
```