+++
title = "2021-02-03 Daily-Challenge"
path = "2021-02-03-Daily-Challenge"
date = 2021-02-03 18:00:59+08:00
updated = 2021-02-03 21:29:14+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Integer to English Words](https://leetcode.com/problems/integer-to-english-words/) and leetcode's [January LeetCoding Challenge](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/583/week-5-january-29th-january-31st/3623/) with `cpp`.

<!-- more -->

# Integer to English Words

## Description

Convert a non-negative integer `num` to its English words representation.

 

**Example 1:**

```
Input: num = 123
Output: "One Hundred Twenty Three"
```

**Example 2:**

```
Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"
```

**Example 3:**

```
Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
```

**Example 4:**

```
Input: num = 1234567891
Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
```

 

**Constraints:**

- $0 \le num \le 2^{31} - 1$

## Solution

``` cpp
class Solution {
    const string ZERO = "Zero";
    const string B = "Billion";
    const int b = 1000000000;
    const string M = "Million";
    const int m = 1000000;
    const string K = "Thousand";
    const int k = 1000;
    unordered_map<int, string> mp = {
        {1, "One"},
        {2, "Two"},
        {3, "Three"},
        {4, "Four"},
        {5, "Five"},
        {6, "Six"},
        {7, "Seven"},
        {8, "Eight"},
        {9, "Nine"},
        {10, "Ten"},
        {11, "Eleven"},
        {12, "Twelve"},
        {13, "Thirteen"},
        {14, "Fourteen"},
        {15, "Fifteen"},
        {16, "Sixteen"},
        {17, "Seventeen"},
        {18, "Eighteen"},
        {19, "Nineteen"},
        {20, "Twenty"},
        {30, "Thirty"},
        {40, "Forty"},
        {50, "Fifty"},
        {60, "Sixty"},
        {70, "Seventy"},
        {80, "Eighty"},
        {90, "Ninety"}
    };
    string numberLT1000ToWords(int num) {
        string result;
        if(num >= 100) {
            result += mp[num / 100] + " Hundred";
            if(num % 100 == 0) return result;
            result += " ";
        }
        if(mp.count(num%100)) {
            result += mp[num % 100];
        } else {
            result += mp[(num % 100) / 10 * 10] + " " + mp[(num % 10)];
        }
        return result;
    }
public:
    string numberToWords(int num) {
        if(!num) return move(ZERO);
        string answer = "";
        if(num >= b) {
            answer += numberLT1000ToWords(num / b) + " " + B;
            num %= b;
        }
        if(num >= m) {
            if(answer.length()) answer += " ";
            answer += numberLT1000ToWords(num / m) + " " + M;
            num %= m;
        }
        if(num >= k) {
            if(answer.length()) answer += " ";
            answer += numberLT1000ToWords(num / k) + " " + K;
            num %= k;
        }
        if(num) {
            if(answer.length()) answer += " ";
            answer += numberLT1000ToWords(num);
        }
        return answer;
    }
};
```

oh, so many repeat, should do some refactor


``` cpp
class Solution {
    const string ZERO = "Zero";
    const vector<pair<int, string>> units= {
        {1000000000, "Billion"},
        {1000000, "Million"},
        {1000, "Thousand"},
        {1, ""}
    };
    unordered_map<int, string> mp = {
        {1, "One"},
        {2, "Two"},
        {3, "Three"},
        {4, "Four"},
        {5, "Five"},
        {6, "Six"},
        {7, "Seven"},
        {8, "Eight"},
        {9, "Nine"},
        {10, "Ten"},
        {11, "Eleven"},
        {12, "Twelve"},
        {13, "Thirteen"},
        {14, "Fourteen"},
        {15, "Fifteen"},
        {16, "Sixteen"},
        {17, "Seventeen"},
        {18, "Eighteen"},
        {19, "Nineteen"},
        {20, "Twenty"},
        {30, "Thirty"},
        {40, "Forty"},
        {50, "Fifty"},
        {60, "Sixty"},
        {70, "Seventy"},
        {80, "Eighty"},
        {90, "Ninety"}
    };
    string numberLT1000ToWords(int num) {
        string result;
        if(num >= 100) {
            result += mp[num / 100] + " Hundred";
            if(num % 100 == 0) return result;
            result += " ";
        }
        if(mp.count(num%100)) {
            result += mp[num % 100];
        } else {
            result += mp[(num % 100) / 10 * 10] + " " + mp[(num % 10)];
        }
        return result;
    }
    void numberPartToWords(string &result, int &num, const int threshold, const string &unit) {
        if(num >= threshold) {
            if(result.length()) result += " ";
            result += numberLT1000ToWords(num / threshold);
            if(unit.length()) result += " " +unit;
            num %= threshold;
        }
    }
public:
    string numberToWords(int num) {
        if(!num) return move(ZERO);
        string answer = "";
        for(const auto &[threshold, unit] : units) {
            numberPartToWords(answer, num, threshold, unit);
        }
        return answer;
    }
};
```

# February LeetCoding Challenge3

**Linked List Cycle**

## Description

Given `head`, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the `next` pointer. Internally, `pos` is used to denote the index of the node that tail's `next` pointer is connected to. **Note that `pos` is not passed as a parameter**.

Return `true` *if there is a cycle in the linked list*. Otherwise, return `false`.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist.png)

```
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test2.png)

```
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
```

**Example 3:**

![img](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test3.png)

```
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
```

 

**Constraints:**

- The number of the nodes in the list is in the range `[0, 104]`.
- `-105 <= Node.val <= 105`
- `pos` is `-1` or a **valid index** in the linked-list.

 

**Follow up:** Can you solve it using `O(1)` (i.e. constant) memory?

## Solution

``` cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode *fast = head, *slow = head;
        do {
            if(fast->next == nullptr) return false;
            fast = fast->next;
            if(fast->next == nullptr) return false;
            fast = fast->next;
            slow = slow->next;
        }while(fast != slow);
        return true;
    }
};
```