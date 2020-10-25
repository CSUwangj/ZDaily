+++
title = "2020-10-24 Daily-Challenge"
path = "2020-10-24-Daily-Challenge"
date = 2020-10-24 13:48:44+08:00
updated = 2020-10-24 23:59:59+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [October LeetCoding Challenge](https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/562/week-4-october-22nd-october-28th/3506/) with `cpp`.

BTW I decided to write solution directly on website rather than on VSCode when reviewing.

<!-- more -->

# LeetCode review

## Ugly Number II

use dp

``` cpp
class Solution {
 public:
  int nthUglyNumber(int n) {
    vector<int> dp{1};
    int two = 0, three = 0, five = 0;
    while(dp.size() < n) {
      int new_two = dp[two]*2;
      int new_three = dp[three]*3;
      int new_five = dp[five]*5;
      int new_num = min({new_two, new_three, new_five});
      if(new_two == new_num) two += 1;
      if(new_three == new_num) three += 1;
      if(new_five == new_num) five += 1;
      dp.push_back(new_num);
    }
    return dp[n-1];
  }
};
```

## Clone Graph

more gentle

``` cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    map<int, Node*> m;
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        if(m.count(node->val)) return m[node->val];
        Node* root = new Node(node->val);
        m[node->val] = root;
        for(auto n : node->neighbors) {
            root->neighbors.push_back(cloneGraph(n));
        }
        return root;
    }
};
```

## Minimum Domino Rotations For Equal Row

quick

``` cpp
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        if(A.size() != B.size()) return -1;
        vector<int> AA(7), BB(7), same(7);
        for(int i = 0; i < A.size(); ++i) {
            AA[A[i]] += 1;
            BB[B[i]] += 1;
            if(A[i] == B[i]) same[A[i]] += 1;
        }
        for(int i = 1; i < 7; ++i) {
            if(AA[i] + BB[i] - same[i] >= A.size()) {
                return A.size()-max(AA[i], BB[i]);
            }
        }
        return -1;
    }
};
```

## Linked List Components

more gentle

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
    set<int> s;
public:
    int numComponents(ListNode* head, vector<int>& G) {
        if(!head) return 0;
        for(auto i : G) {
            s.insert(i);
        }
        if(!(head->next)) return s.count(head->val);
        int ans = s.count(head->val);
        ListNode *cur = head->next, *pre = head;
        while(cur) {
            ans += s.count(cur->val) ^ s.count(pre->val);
            pre = cur;
            cur = cur->next;
        }
        ans = (ans+1)/2;
        return ans;
    }
};
```

## Asteroid Collision

more gentle

``` cpp
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> s;
        s.push_back(asteroids[0]);
        for(int i = 1; i < asteroids.size(); ++i) {
            if(s.empty() || s.back() < 0) {
                s.push_back(asteroids[i]);
                continue;
            }
            if(asteroids[i] > 0) {
                s.push_back(asteroids[i]);
                continue;
            }
            while(s.size() && s.back() > 0 && -asteroids[i] > s.back()) s.pop_back();
            if(s.empty() || s.back() < 0) s.push_back(asteroids[i]);
            else if(s.size() && -asteroids[i] == s.back()) s.pop_back();
        }
        return s;
    }
};
```

# October LeetCoding Challenge24

## Description

**Bag of Tokens**

You have an initial **power** of `P`, an initial **score** of `0`, and a bag of `tokens` where `tokens[i]` is the value of the `ith` token (0-indexed).

Your goal is to maximize your total **score** by potentially playing each token in one of two ways:

- If your current **power** is at least `tokens[i]`, you may play the `ith` token face up, losing `tokens[i]` **power** and gaining `1` **score**.
- If your current **score** is at least `1`, you may play the `ith` token face down, gaining `tokens[i]` **power** and losing `1` **score**.

Each token may be played **at most** once and **in any order**. You do **not** have to play all the tokens.

Return *the largest possible **score** you can achieve after playing any number of tokens*.

**Example 1:**

```
Input: tokens = [100], P = 50
Output: 0
Explanation: Playing the only token in the bag is impossible because you either have too little power or too little score.
```

**Example 2:**

```
Input: tokens = [100,200], P = 150
Output: 1
Explanation: Play the 0th token (100) face up, your power becomes 50 and score becomes 1.
There is no need to play the 1st token since you cannot play it face up to add to your score.
```

**Example 3:**

```
Input: tokens = [100,200,300,400], P = 200
Output: 2
Explanation: Play the tokens in this order to get a score of 2:
1. Play the 0th token (100) face up, your power becomes 100 and score becomes 1.
2. Play the 3rd token (400) face down, your power becomes 500 and score becomes 0.
3. Play the 1st token (200) face up, your power becomes 300 and score becomes 1.
4. Play the 2nd token (300) face up, your power becomes 0 and score becomes 2.
```

**Constraints:**

- `0 <= tokens.length <= 1000`
- `0 <= tokens[i], P < 104`

## Solution

sort then take

``` cpp
class Solution {
public:
  int bagOfTokensScore(vector<int>& tokens, int P) {
    sort(tokens.begin(), tokens.end());
    int head = 0, tail = tokens.size();
    int ans = 0, cur = 0;
    while(head != tail) {
      while(head != tail && P >= tokens[head]) {
        P -= tokens[head];
        cur += 1;
        head += 1;
      }
      ans = max(ans, cur);
      if(!cur || head == tail) break;
      tail -= 1;
      cur -= 1;
      P += tokens[tail];
    }
    return ans;
  }
};
```