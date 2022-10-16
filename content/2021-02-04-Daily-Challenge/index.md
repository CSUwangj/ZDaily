+++
title = "2021-02-04 Daily-Challenge"
path = "2021-02-04-Daily-Challenge"
date = 2021-02-04 18:00:59+08:00
updated = 2021-02-04 22:39:04+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Throne Inheritance](https://leetcode.com/problems/throne-inheritance/) and leetcode's [February LeetCoding Challenge](https://leetcode.com/explore/featured/card/february-leetcoding-challenge-2021/584/week-1-february-1st-february-7th/3628/) with `cpp`.

<!-- more -->

# Throne Inheritance

## Description

A kingdom consists of a king, his children, his grandchildren, and so on. Every once in a while, someone in the family dies or a child is born.

The kingdom has a well-defined order of inheritance that consists of the king as the first member. Let's define the recursive function `Successor(x, curOrder)`, which given a person `x` and the inheritance order so far, returns who should be the next person after `x` in the order of inheritance.

```
Successor(x, curOrder):
    if x has no children or all of x's children are in curOrder:
        if x is the king return null
        else return Successor(x's parent, curOrder)
    else return x's oldest child who's not in curOrder
```

For example, assume we have a kingdom that consists of the king, his children Alice and Bob (Alice is older than Bob), and finally Alice's son Jack.

1. In the beginning, `curOrder` will be `["king"]`.
2. Calling `Successor(king, curOrder)` will return Alice, so we append to `curOrder` to get `["king", "Alice"]`.
3. Calling `Successor(Alice, curOrder)` will return Jack, so we append to `curOrder` to get `["king", "Alice", "Jack"]`.
4. Calling `Successor(Jack, curOrder)` will return Bob, so we append to `curOrder` to get `["king", "Alice", "Jack", "Bob"]`.
5. Calling `Successor(Bob, curOrder)` will return `null`. Thus the order of inheritance will be `["king", "Alice", "Jack", "Bob"]`.

Using the above function, we can always obtain a unique order of inheritance.

Implement the `ThroneInheritance` class:

- `ThroneInheritance(string kingName)` Initializes an object of the `ThroneInheritance` class. The name of the king is given as part of the constructor.
- `void birth(string parentName, string childName)` Indicates that `parentName` gave birth to `childName`.
- `void death(string name)` Indicates the death of `name`. The death of the person doesn't affect the `Successor` function nor the current inheritance order. You can treat it as just marking the person as dead.
- `string[] getInheritanceOrder()` Returns a list representing the current order of inheritance **excluding** dead people.

 

**Example 1:**

```
Input
["ThroneInheritance", "birth", "birth", "birth", "birth", "birth", "birth", "getInheritanceOrder", "death", "getInheritanceOrder"]
[["king"], ["king", "andy"], ["king", "bob"], ["king", "catherine"], ["andy", "matthew"], ["bob", "alex"], ["bob", "asha"], [null], ["bob"], [null]]
Output
[null, null, null, null, null, null, null, ["king", "andy", "matthew", "bob", "alex", "asha", "catherine"], null, ["king", "andy", "matthew", "alex", "asha", "catherine"]]

Explanation
ThroneInheritance t= new ThroneInheritance("king"); // order: king
t.birth("king", "andy"); // order: king > andy
t.birth("king", "bob"); // order: king > andy > bob
t.birth("king", "catherine"); // order: king > andy > bob > catherine
t.birth("andy", "matthew"); // order: king > andy > matthew > bob > catherine
t.birth("bob", "alex"); // order: king > andy > matthew > bob > alex > catherine
t.birth("bob", "asha"); // order: king > andy > matthew > bob > alex > asha > catherine
t.getInheritanceOrder(); // return ["king", "andy", "matthew", "bob", "alex", "asha", "catherine"]
t.death("bob"); // order: king > andy > matthew > bob > alex > asha > catherine
t.getInheritanceOrder(); // return ["king", "andy", "matthew", "alex", "asha", "catherine"]
```

 

**Constraints:**

- `1 <= kingName.length, parentName.length, childName.length, name.length <= 15`
- `kingName`, `parentName`, `childName`, and `name` consist of lowercase English letters only.
- All arguments `childName` and `kingName` are **distinct**.
- All `name` arguments of `death` will be passed to either the constructor or as `childName` to `birth` first.
- For each call to `birth(parentName, childName)`, it is guaranteed that `parentName` is alive.
- At most `100000` calls will be made to `birth` and `death`.
- At most `10` calls will be made to `getInheritanceOrder`.

## Solution

``` cpp
class ThroneInheritance {
    string king;
    int count = 1;
    unordered_map<int, vector<int>> children;
    unordered_map<string, int> revMapping;
    vector<string> mapping;
    vector<bool> dead;
    
    void dfs(vector<string> &result, int cur) {
        if(!dead[cur]) result.push_back(mapping[cur]);
        for(auto child : children[cur]) {
            dfs(result, child);
        }
    }
public:
    ThroneInheritance(string kingName): king(kingName) {
        mapping.push_back(kingName);
        dead.push_back(false);
        revMapping[kingName] = 0;
    }
    
    void birth(string parentName, string childName) {
        mapping.push_back(childName);
        dead.push_back(false);
        revMapping[childName] = count;
        children[revMapping[parentName]].push_back(count);
        count += 1;
        
    }
    
    void death(string name) {
        dead[revMapping[name]] = true;
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> result;
        dfs(result, 0);
        return move(result);
    }
};
```

# February LeetCoding Challenge 4

## Description

**Longest Harmonious Subsequence**

We define a harmonious array as an array where the difference between its maximum value and its minimum value is **exactly** `1`.

Given an integer array `nums`, return *the length of its longest harmonious subsequence among all its possible subsequences*.

A **subsequence** of array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.

 

**Example 1:**

```
Input: nums = [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].
```

**Example 2:**

```
Input: nums = [1,2,3,4]
Output: 2
```

**Example 3:**

```
Input: nums = [1,1,1,1]
Output: 0
```

 

**Constraints:**

- $1 \le nums.length \le 2 * 10^4$
- $-10^9 \le nums[i] \le 10^9$

## Solution

``` cpp
class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> count;
        for(auto i : nums) count[i] += 1;
        int answer = 0;
        for(auto [num, cnt] : count) {
            if(count.count(num+1)) answer = max(answer, cnt + count[num+1]);
        }
        return answer;
    }
};
```