+++
title = "2021-01-04 Daily-Challenge"
path = "2021-01-04-Daily-Challenge"
date = 2021-01-04 18:09:45+08:00
updated = 2021-01-04 18:57:09+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Partition List](https://leetcode.com/problems/partition-list/) and [Minimum Remove to Make Valid Parentheses](https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/) with `cpp`. leetcoding challenge is a problem I have done at 2020-12-28.

<!-- more -->

# Partition List

## Description

Given a linked list and a value *x*, partition it such that all nodes less than *x* come before nodes greater than or equal to *x*.

You should preserve the original relative order of the nodes in each of the two partitions.

**Example:**

```
Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
```

## Solution

partition of quick sort

``` cpp
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *newHead = new ListNode(-1, head);
        ListNode *front = newHead;
        while(front->next && front->next->val < x) front = front->next;
        ListNode *cur = front->next, *prev = front;
        while(cur && cur->val >= x) {
            prev = cur;
            cur = cur->next;
        }
        if(!cur) return newHead->next;
        while(cur) {
            if(cur->val >= x) {
                prev = cur;
                cur = cur->next;
            } else {
                prev->next = cur->next;
                cur->next = front->next;
                front->next = cur;
                front = front->next;
                cur = prev->next;
            }
        }
        return newHead->next;
    }
};
```

# Minimum Remove to Make Valid Parentheses

## Description

Given a string s of `'('` , `')'` and lowercase English characters. 

Your task is to remove the minimum number of parentheses ( `'('` or `')'`, in any positions ) so that the resulting *parentheses string* is valid and return **any** valid string.

Formally, a *parentheses string* is valid if and only if:

- It is the empty string, contains only lowercase characters, or
- It can be written as `AB` (`A` concatenated with `B`), where `A` and `B` are valid strings, or
- It can be written as `(A)`, where `A` is a valid string.

**Example 1:**

```
Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
```

**Example 2:**

```
Input: s = "a)b(c)d"
Output: "ab(c)d"
```

**Example 3:**

```
Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.
```

**Example 4:**

```
Input: s = "(a(b(c)d)"
Output: "a(b(c)d)"
```

**Constraints:**

- `1 <= s.length <= 10^5`
- `s[i]` is one of `'('` , `')'` and lowercase English letters`.`

## Solution

``` cpp
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string current = "";
        stack<string> st;
        for(auto c : s) {
            if(c == ')') {
                if(!st.empty()) {
                    string newCurrent = st.top();
                    st.pop();
                    current = newCurrent + "(" + current + ")";
                }
            } else if(c == '(') {
                st.push(current);
                current = "";
            } else {
                current.push_back(c);
            }
        }
        while(!st.empty()) {
            string newCurrent = st.top();
            st.pop();
            current = newCurrent + current;
        }
        return current;
    }
};
```