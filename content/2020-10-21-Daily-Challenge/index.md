+++
title = "2020-10-21 Daily-Challenge"
path = "2020-10-21-Daily-Challenge"
date = 2020-10-21 01:11:11+08:00
updated = 2020-10-21 20:18:48+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done *Linked List Components* on [leetcode](https://leetcode.com/problems/linked-list-components/) and leetcode's [October LeetCoding Challenge](https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/560/week-3-october-15th-october-21st/3502/) with `cpp`.

<!-- more -->

# Linked List Components

## Description

We are given `head`, the head node of a linked list containing **unique integer values**.

We are also given the list `G`, a subset of the values in the linked list.

Return the number of connected components in `G`, where two values are connected if they appear consecutively in the linked list.

**Example 1:**

```
Input: 
head: 0->1->2->3
G = [0, 1, 3]
Output: 2
Explanation: 
0 and 1 are connected, so [0, 1] and [3] are the two connected components.
```

**Example 2:**

```
Input: 
head: 0->1->2->3->4
G = [0, 3, 1, 4]
Output: 2
Explanation: 
0 and 1 are connected, 3 and 4 are connected, so [0, 1] and [3, 4] are the two connected components.
```

**Note:**

- If `N` is the length of the linked list given by `head`, `1 <= N <= 10000`.
- The value of each node in the linked list will be in the range` [0, N - 1]`.
- `1 <= G.length <= 10000`.
- `G` is a subset of all values in the linked list.

## Solution

space–time tradeoff

``` cpp
class Solution {/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    vector<bool> inG = vector<bool>(10000);
public:
    int numComponents(ListNode* head, vector<int>& G) {
        for(auto i : G) {
            inG[i] = true;
        }
        ListNode *cur = head;
        bool inComp = false;
        int ans = 0;
        while(cur) {
            if(!inG[cur->val]){
                inComp = false;
            } else {
                if(!inComp) {
                    ans += 1;
                }
                inComp = true;
            }
            cur = cur->next;
        }
        return ans;
    }
};

/*
 * Runtime: 40 ms, faster than 99.09% of C++ online submissions for Linked List Components.
 * Memory Usage: 19.9 MB, less than 10.51% of C++ online submissions for Linked List Components.
 */
```

or time-space tradeoff? set use so many spaces...

``` cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    set<int> G;
public:
    int numComponents(ListNode* head, vector<int>& G) {
        for(auto i : G) {
            this->G.insert(i);
        }
        ListNode *cur = head;
        bool inComp = false;
        int ans = 0;
        while(cur) {
            if(!this->G.count(cur->val)){
                inComp = false;
            } else {
                if(!inComp) {
                    ans += 1;
                }
                inComp = true;
            }
            cur = cur->next;
        }
        return ans;
    }
};

/*
 * Runtime: 72 ms, faster than 49.37% of C++ online submissions for Linked List Components.
 * Memory Usage: 22.2 MB, less than 10.51% of C++ online submissions for Linked List Components. 
 */
```

# October LeetCoding Challenge 21

## Description

**Asteroid Collision**

We are given an array `asteroids` of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

**Example 1:**

```
Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10.  The 5 and 10 never collide.
```

**Example 2:**

```
Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
```

**Example 3:**

```
Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
```

**Example 4:**

```
Input: asteroids = [-2,-1,1,2]
Output: [-2,-1,1,2]
Explanation: The -2 and -1 are moving left, while the 1 and 2 are moving right. Asteroids moving the same direction never meet, so no asteroids will meet each other.
```

**Constraints:**

- `1 <= asteroids <= 104`
- `-1000 <= asteroids[i] <= 1000`
- `asteroids[i] != 0`

## Solution

simple simulation

``` cpp
class Solution {
public:
  vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> ans;
    for(int i = 0; i < asteroids.size(); ++i){
      if(asteroids[i] > 0){
        ans.push_back(asteroids[i]);
        continue;
      }
      bool have = true;
      for(int j = ans.size()-1; j >= 0 && have; --j) {
        if(ans[j] < 0) break;
        if(-asteroids[i] > ans[j]) {
          ans.pop_back();
        } else if(-asteroids[i] < ans[j]) {
          have = false;
        } else {
          ans.pop_back();
          have = false;
        }
      }
      if(have) ans.push_back(asteroids[i]);
    }
    return ans;
  }
};
```
