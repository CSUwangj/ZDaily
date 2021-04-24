+++
title = "2021-03-01 Daily-Challenge"
path = "2021-03-01-Daily-Challenge"
date = 2021-03-01 18:03:31+08:00
updated = 2021-03-01 19:42:49+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Map Sum Pairs](https://leetcode.com/problems/map-sum-pairs/) and leetcode's [March LeetCoding Challenge](https://leetcode.com/explore/featured/card/march-leetcoding-challenge-2021/588/week-1-march-1st-march-7th/3657/) with `cpp`.

<!-- more -->

# Map Sum Pairs

## Description

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
class MapSum {
    unordered_map<string, int> mp;
public:    
    void insert(string key, int val) {
        mp[key] = val;
    }
    
    int sum(string prefix) {
        int result = 0;
        for(auto &[s, v] : mp) {
            if(s.rfind(prefix, 0) == 0) {
                result += v;
            }
        }
        return result;
    }
};
```

# March LeetCoding Challenge1

## Description

**Distribute Candies**

Alice has `n` candies, where the `ith` candy is of type `candyType[i]`. Alice noticed that she started to gain weight, so she visited a doctor.

The doctor advised Alice to only eat `n / 2` of the candies she has (`n` is always even). Alice likes her candies very much, and she wants to eat the maximum number of different types of candies while still following the doctor's advice.

Given the integer array `candyType` of length `n`, return *the **maximum** number of different types of candies she can eat if she only eats* `n / 2` *of them*.

 

**Example 1:**

```
Input: candyType = [1,1,2,2,3,3]
Output: 3
Explanation: Alice can only eat 6 / 2 = 3 candies. Since there are only 3 types, she can eat one of each type.
```

**Example 2:**

```
Input: candyType = [1,1,2,3]
Output: 2
Explanation: Alice can only eat 4 / 2 = 2 candies. Whether she eats types [1,2], [1,3], or [2,3], she still can only eat 2 different types.
```

**Example 3:**

```
Input: candyType = [6,6,6,6]
Output: 1
Explanation: Alice can only eat 4 / 2 = 2 candies. Even though she can eat 2 candies, she only has 1 type.
```

 

**Constraints:**

- `n == candyType.length`
- <pre><code>2 <= n <= 10<sup>4</sup></code></pre>
- `n` is even.
- <pre><code>-10<sup>5</sup> <= candyType[i] <= 10<sup>5</sup></code></pre>

## Solution

``` cpp
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int pos = 0;
        int len = pushed.size();
        vector<int> st;
        for(int i = 0; i < len; ++i) {
            if(st.size() && st.back() == popped[i]) {
                st.pop_back();
                continue;
            }
            while(pos < len && pushed[pos] != popped[i]) {
                st.push_back(pushed[pos]);
                pos += 1;
            }
            if(pos < len && pushed[pos] == popped[i]) {
                pos += 1;
                continue;
            }
            return false;
        }
        return true;
    }
};
```
