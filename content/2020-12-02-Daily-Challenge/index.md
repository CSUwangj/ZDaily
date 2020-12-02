+++
title = "2020-12-02 Daily-Challenge"
path = "2020-12-02-Daily-Challenge"
date = 2020-12-02 12:03:18+08:00
updated = 2020-12-02 19:11:36+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Decrypt String from Alphabet to Integer Mapping](https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/) on leetcode and leetcode's [December LeetCoding Challenge](https://leetcode.com/explore/featured/card/december-leetcoding-challenge/569/week-1-december-1st-december-7th/3552/) with `cpp`.

<!-- more -->

# Decrypt String from Alphabet to Integer Mapping

## Description

Given a string `s` formed by digits (`'0'` - `'9'`) and `'#'` . We want to map `s` to English lowercase characters as follows:

- Characters (`'a'` to `'i')` are represented by (`'1'` to `'9'`) respectively.
- Characters (`'j'` to `'z')` are represented by (`'10#'` to `'26#'`) respectively. 

Return the string formed after mapping.

It's guaranteed that a unique mapping will always exist.

**Example 1:**

```
Input: s = "10#11#12"
Output: "jkab"
Explanation: "j" -> "10#" , "k" -> "11#" , "a" -> "1" , "b" -> "2".
```

**Example 2:**

```
Input: s = "1326#"
Output: "acz"
```

**Example 3:**

```
Input: s = "25#"
Output: "y"
```

**Example 4:**

```
Input: s = "12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#"
Output: "abcdefghijklmnopqrstuvwxyz"
```

**Constraints:**

- `1 <= s.length <= 1000`
- `s[i]` only contains digits letters (`'0'`-`'9'`) and `'#'` letter.
- `s` will be valid string such that mapping is always possible.

## Solution

nothing to say

``` cpp
class Solution {
public:
    string freqAlphabets(string s) {
        int pos = 0, len = s.length();
        string answer;
        while(pos < len) {
            char c;
            if(pos + 2 < len && s[pos+2] == '#') {
                c = (s[pos]-'0')*10 + s[pos+1] - '0' + 96;
                pos += 3;
            } else {
                c = s[pos] - '0' + 96;
                pos += 1;
            }
            answer.push_back(c);
        }
        return answer;
    }
};
```

# December LeetCoding Challenge2

**Linked List Random Node**

## Description

Given a singly linked list, return a random node's value from the linked list. Each node must have the **same probability** of being chosen.

**Follow up:**
What if the linked list is extremely large and its length is unknown to you? Could you solve this efficiently without using extra space?

**Example:**

```
// Init a singly linked list [1,2,3].
ListNode head = new ListNode(1);
head.next = new ListNode(2);
head.next.next = new ListNode(3);
Solution solution = new Solution(head);

// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
solution.getRandom();
```

## Solution

nothing to say

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
    std::default_random_engine generator;
    uniform_int_distribution<int> roll;
    int listLength(ListNode* head) {
        int len = 0;
        while(head) {
            len += 1;
            head = head->next;
        }
        return len;
    }
    ListNode* head;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
        int len = listLength(head);
        roll = uniform_int_distribution<int>(1, len);
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int pos = roll(generator);
        cout << pos << endl;
        ListNode* cur = head;
        while(--pos) {
            cur = cur->next;
        }
        return cur->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
```