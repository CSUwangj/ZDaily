+++
title = "2022-01-19 Daily-Challenge"
path = "2022-01-19-Daily-Challenge"
date = 2022-01-19 18:10:00+08:00
updated = 2022-01-19 18:18:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/linked-list-cycle-ii/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 19

## Description

**Linked List Cycle II**

Given the `head` of a linked list, return *the node where the cycle begins. If there is no cycle, return* `null`.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the `next` pointer. Internally, `pos` is used to denote the index of the node that tail's `next` pointer is connected to (**0-indexed**). It is `-1` if there is no cycle. **Note that** `pos` **is not passed as a parameter**.

**Do not modify** the linked list.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist.png)

```
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test2.png)

```
Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
```

**Example 3:**

![img](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test3.png)

```
Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.
```

 

**Constraints:**

- The number of the nodes in the list is in the range `[0, 10^4]`.
- `-105 <= Node.val <= 105`
- `pos` is `-1` or a **valid index** in the linked-list.

 

**Follow up:** Can you solve it using `O(1)` (i.e. constant) memory?

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
  ListNode *detectCycle(ListNode *head) {
    if(!head) return nullptr;
    ListNode *quick = head;
    ListNode *slow = head;
    do {
      quick = quick->next;
      if(quick) quick = quick->next;
      slow = slow->next;
    } while(quick && slow && quick != slow);
    if(!quick) return quick;
    slow = head;
    while(quick != slow) {
      slow = slow->next;
      quick = quick->next;
    }
    return quick;
  }
};

// Accepted
// 16/16 cases passed (7 ms)
// Your runtime beats 83.96 % of cpp submissions
// Your memory usage beats 16.8 % of cpp submissions (7.7 MB)
```
