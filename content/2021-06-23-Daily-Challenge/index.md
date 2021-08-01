+++
title = "2021-06-23 Daily-Challenge"
path = "2021-06-23-Daily-Challenge"
date = 2021-06-23 18:44:33+08:00
updated = 2021-06-23 20:19:43+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Count of Smaller Numbers After Self](https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/) and leetcode's [June LeetCoding Challenge](https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/606/week-4-june-22nd-june-28th/3789/) with `cpp`.

<!-- more -->

# Count of Smaller Numbers After Self

## Description

You are given an integer array `nums` and you have to return a new `counts` array. The `counts` array has the property where `counts[i]` is the number of smaller elements to the right of `nums[i]`.

 

**Example 1:**

```
Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
```

**Example 2:**

```
Input: nums = [-1]
Output: [0]
```

**Example 3:**

```
Input: nums = [-1,-1]
Output: [0,0]
```

 

**Constraints:**

- `1 <= nums.length <= 10^5`
- `-10^4 <= nums[i] <= 10^4`

## Solution

``` cpp
#define lowbit(x) (x & (-x))

const int SZ = 20001;
const int OFFSET = 10001;
class Solution {
  int BITS[SZ + 1];

  void add(int x) {
    while(x <= SZ) {
      BITS[x] += 1;
      x += lowbit(x);
    }
  }

  int sum(int x) {
    int result = 0;
    while(x) {
      result += BITS[x];
      x -= lowbit(x);
    }
    return result;
  }
public:
  vector<int> countSmaller(vector<int>& nums) {
    vector<int> answer;
    for(int i = nums.size() - 1; i >= 0; --i) {
      int n = nums[i] + OFFSET;
      answer.push_back(sum(n - 1));
      add(n);
    }
    reverse(answer.begin(), answer.end());
    return answer;
  }
};

// Accepted
// 65/65 cases passed (116 ms)
// Your runtime beats 98.63 % of cpp submissions
// Your memory usage beats 94.14 % of cpp submissions (73.3 MB)
```

# June LeetCoding Challenge 23

## Description

**Reverse Linked List II**

Given the `head` of a singly linked list and two integers `left` and `right` where `left <= right`, reverse the nodes of the list from position `left` to position `right`, and return *the reversed list*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/02/19/rev2ex2.jpg)

```
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
```

**Example 2:**

```
Input: head = [5], left = 1, right = 1
Output: [5]
```

 

**Constraints:**

- The number of nodes in the list is `n`.
- `1 <= n <= 500`
- `-500 <= Node.val <= 500`
- `1 <= left <= right <= n`

 

**Follow up:** Could you do it in one pass?

## Solution

``` cpp
class Solution {
public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode *newHead = new ListNode();
    ListNode *newCur = newHead;
    ListNode *cur = head;
    int pos = 1;
    while(pos < left) {
      newCur->next = cur;
      cur = cur->next;
      newCur = newCur->next;
      pos += 1;
    }
    ListNode *midTail = cur;
    ListNode *midCur = nullptr;
    ListNode *next;
    while(pos <= right) {
      next = cur->next;
      cur->next = midCur;
      midCur = cur;
      cur = next;
      pos += 1;
    }
    newCur->next = midCur;
    newCur = midTail;
    newCur->next = next;
    return newHead->next;
  }
};

// Accepted
// 44/44 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 56.86 % of cpp submissions (7.4 MB)
```
