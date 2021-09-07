+++
title = "2021-09-07 Daily-Challenge"
path = "2021-09-07-Daily-Challenge"
date = 2021-09-07 21:05:12+08:00
updated = 2021-09-07 21:48:13+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Lexicographical Numbers](https://leetcode.com/problems/lexicographical-numbers/description/) and leetcode's [September LeetCoding Challenge](https://leetcode.com/explore/featured/card/september-leetcoding-challenge-2021/636/week-1-september-1st-september-7th/3961/) with `cpp`.

<!-- more -->

# Lexicographical Numbers

## Description

Given an integer `n`, return all the numbers in the range `[1, n]` sorted in lexicographical order.

You must write an algorithm that runs in `O(n)` time and uses `O(1)` extra space. 

 

**Example 1:**

```
Input: n = 13
Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
```

**Example 2:**

```
Input: n = 2
Output: [1,2]
```

 

**Constraints:**

- `1 <= n <= 5 * 10^4`

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  vector<int> lexicalOrder(int n) {
    int curInt = 1;
    vector<int> answer{1};
    while(answer.size() < n) {
      if(curInt * 10 <= n) {
        curInt *= 10;
        answer.push_back(curInt);
      } else {
        while(curInt % 10 == 9 || curInt == n) {
          int count = 1;
          curInt /= 10;
        }
        curInt += 1;
        answer.push_back(curInt);
      }
    }

    return answer;
  }
};

// Accepted
// 26/26 cases passed (8 ms)
// Your runtime beats 82.37 % of cpp submissions
// Your memory usage beats 81.38 % of cpp submissions (11 MB)
```

# September LeetCoding Challenge 7

## Description

**Reverse Linked List**

Given the `head` of a singly linked list, reverse the list, and return *the reversed list*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/02/19/rev1ex1.jpg)

```
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/02/19/rev1ex2.jpg)

```
Input: head = [1,2]
Output: [2,1]
```

**Example 3:**

```
Input: head = []
Output: []
```

 

**Constraints:**

- The number of nodes in the list is the range `[0, 5000]`.
- `-5000 <= Node.val <= 5000`

 

**Follow up:** A linked list can be reversed either iteratively or recursively. Could you implement both?

## Solution

``` cpp
class Solution {
public:
  ListNode* reverseList(ListNode* head, ListNode* tail = nullptr) {
    if(!head) return tail;
    ListNode *next = head->next;
    head->next = tail;
    return reverseList(next, head);
  }
};

// Accepted
// 28/28 cases passed (4 ms)
// Your runtime beats 96.22 % of cpp submissions
// Your memory usage beats 97.51 % of cpp submissions (8.2 MB)
```

``` cpp
class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    ListNode *newHead = nullptr;
    ListNode *prev;
    ListNode *cur = head;
    while(cur) {
      prev = cur;
      cur = cur->next;
      prev->next = newHead;
      newHead = prev;
    }
    return newHead;
  }
};

// Accepted
// 28/28 cases passed (4 ms)
// Your runtime beats 96.22 % of cpp submissions
// Your memory usage beats 97.51 % of cpp submissions (8.2 MB)
```
