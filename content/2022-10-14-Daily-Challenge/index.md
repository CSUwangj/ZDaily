+++
updated = 2022-10-14 18:14:00+08:00
title = "2022-10-14 Daily-Challenge"
path = "2022-10-14-Daily-Challenge"
date = 2022-10-14 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 14

## Description

**Delete the Middle Node of a Linked List**

You are given the `head` of a linked list. **Delete** the **middle node**, and return *the* `head` *of the modified linked list*.

The **middle node** of a linked list of size `n` is the `⌊n / 2⌋th` node from the **start** using **0-based indexing**, where `⌊x⌋` denotes the largest integer less than or equal to `x`.

- For `n` = `1`, `2`, `3`, `4`, and `5`, the middle nodes are `0`, `1`, `1`, `2`, and `2`, respectively.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/11/16/eg1drawio.png)

```
Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]
Explanation:
The above figure represents the given linked list. The indices of the nodes are written below.
Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
We return the new list after removing this node. 
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/11/16/eg2drawio.png)

```
Input: head = [1,2,3,4]
Output: [1,2,4]
Explanation:
The above figure represents the given linked list.
For n = 4, node 2 with value 3 is the middle node, which is marked in red.
```

**Example 3:**

![img](https://assets.leetcode.com/uploads/2021/11/16/eg3drawio.png)

```
Input: head = [2,1]
Output: [2]
Explanation:
The above figure represents the given linked list.
For n = 2, node 1 with value 1 is the middle node, which is marked in red.
Node 0 with value 2 is the only node remaining after removing node 1.
```

 

**Constraints:**

- The number of nodes in the list is in the range `[1, 10^5]`.
- `1 <= Node.val <= 10^5`

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
  ListNode* deleteMiddle(ListNode* head) {
    ListNode *newHead = new ListNode(0, head);
    ListNode *fast = newHead;
    ListNode *slow = newHead;
    ListNode *cur = newHead;
    while(fast->next && fast->next->next) {
      fast = fast->next;
      if(fast->next) {
        fast = fast->next;
      }
      slow = slow->next;
    }
    slow->next = slow->next->next;
    return newHead->next;
  }
};

// Accepted
// 70 / 70 cases passed (1043 ms)
// Your runtime beats 97.62 % of cpp submissions
// Your memory usage beats 20.46 % of cpp submissions (294.9 MB)
```
