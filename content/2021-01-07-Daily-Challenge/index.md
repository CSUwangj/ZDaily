+++
title = "2021-01-07 Daily-Challenge"
path = "2021-01-07-Daily-Challenge"
date = 2021-01-07 21:08:41+08:00
updated = 2021-01-07 21:49:01+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Customers Who Never Order](https://leetcode.com/problems/customers-who-never-order/) with `sql`, [Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/) and leetcode's [January LeetCoding Challenge](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/579/week-1-january-1st-january-7th/3595/) with `cpp`.

<!-- more -->

# Customers Who Never Order

## Description

<details><summary>SQL Schema</summary>
<pre style="background-color:#2b303b;"><code><span style="color:#c0c5ce;">Create table If Not Exists Customers (Id int, Name varchar(255))
Create table If Not Exists Orders (Id int, CustomerId int)
Truncate table Customers
insert into Customers (Id, Name) values ('1', 'Joe')
insert into Customers (Id, Name) values ('2', 'Henry')
insert into Customers (Id, Name) values ('3', 'Sam')
insert into Customers (Id, Name) values ('4', 'Max')
Truncate table Orders
insert into Orders (Id, CustomerId) values ('1', '3')
insert into Orders (Id, CustomerId) values ('2', '1')
</span></code></pre>
</details>

Suppose that a website contains two tables, the `Customers` table and the `Orders` table. Write a SQL query to find all customers who never order anything.

Table: `Customers`.

```
+----+-------+
| Id | Name  |
+----+-------+
| 1  | Joe   |
| 2  | Henry |
| 3  | Sam   |
| 4  | Max   |
+----+-------+
```

Table: `Orders`.

```
+----+------------+
| Id | CustomerId |
+----+------------+
| 1  | 3          |
| 2  | 1          |
+----+------------+
```

Using the above tables as example, return the following:

```
+-----------+
| Customers |
+-----------+
| Henry     |
| Max       |
+-----------+
```

## Solution

``` sql
# Write your MySQL query statement below
SELECT Name as Customers FROM Customers
WHERE NOT EXISTS
(SELECT Id FROM Orders WHERE Customers.Id = Orders.CustomerId)
```

# Intersection of Two Linked Lists

## Description

Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

[![img](https://assets.leetcode.com/uploads/2018/12/13/160_statement.png)](https://assets.leetcode.com/uploads/2018/12/13/160_statement.png)

begin to intersect at node c1.

 

**Example 1:**

[![img](https://assets.leetcode.com/uploads/2020/06/29/160_example_1_1.png)](https://assets.leetcode.com/uploads/2020/06/29/160_example_1_1.png)

```
Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Reference of the node with value = 8
Input Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect). From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
```

 

**Example 2:**

[![img](https://assets.leetcode.com/uploads/2020/06/29/160_example_2.png)](https://assets.leetcode.com/uploads/2020/06/29/160_example_2.png)

```
Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
Output: Reference of the node with value = 2
Input Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect). From the head of A, it reads as [1,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.
```

 

**Example 3:**

[![img](https://assets.leetcode.com/uploads/2018/12/13/160_example_3.png)](https://assets.leetcode.com/uploads/2018/12/13/160_example_3.png)

```
Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
Output: null
Input Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
Explanation: The two lists do not intersect, so return null.
```

 

**Notes:**

- If the two linked lists have no intersection at all, return `null`.
- The linked lists must retain their original structure after the function returns.
- You may assume there are no cycles anywhere in the entire linked structure.
- Each value on each linked list is in the range `[1, 10^9]`.
- Your code should preferably run in O(n) time and use only O(1) memory.

## Solution

``` cpp
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return nullptr;
        ListNode *tailA = headA;
        int lengthA = 0;
        while(tailA->next) {
            tailA = tailA->next;
            lengthA += 1;
        }
        ListNode *tailB = headB;
        int lengthB = 0;
        while(tailB->next) {
            tailB = tailB->next;
            lengthB += 1;
        }
        if(tailB != tailA) return nullptr;
        while(lengthA > lengthB) {
            headA = headA->next;
            lengthA -= 1;
        }
        while(lengthB > lengthA) {
            headB = headB->next;
            lengthB -= 1;
        }
        while(headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};
```

# January LeetCoding Challenge 7

## Description

**Longest Substring Without Repeating Characters**

Given a string `s`, find the length of the **longest substring** without repeating characters.

 

**Example 1:**

```
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
```

**Example 2:**

```
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
```

**Example 3:**

```
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
```

**Example 4:**

```
Input: s = ""
Output: 0
```

 

**Constraints:**

- `0 <= s.length <= 5 * 104`
- `s` consists of English letters, digits, symbols and spaces.

## Solution

``` cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool has[128] = {false};
        int head = 0, tail = 0;
        int answer = 0;
        int len = s.length();
        while(head < len) {
            if(!has[s[head]]) {
                has[s[head]] = true;
                ++head;
                answer = max(head-tail, answer);
            } else {
                while(has[s[head]]) {
                    has[s[tail]] = false;
                    ++tail;
                }
            }
        }
        return answer;
    }
};
```