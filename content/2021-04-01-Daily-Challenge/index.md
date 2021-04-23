+++
title = "2021-04-01 Daily-Challenge"
path = "2021-04-01-Daily-Challenge"
date = 2021-04-01 16:52:45+08:00
updated = 2021-04-02 02:48:39+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Single Number](https://leetcode.com/problems/single-number/), [Single Number II](https://leetcode.com/problems/single-number-ii/), [Single Number III](https://leetcode.com/problems/single-number-iii/) and leetcode's [April LeetCoding Challenge](https://leetcode.com/explore/featured/card/april-leetcoding-challenge-2021/593/week-1-april-1st-april-7th/3693/) with `cpp`.

<!-- more -->

# Single Number

## Description

Given a **non-empty** array of integers `nums`, every element appears *twice* except for one. Find that single one.

**Follow up:** Could you implement a solution with a linear runtime complexity and without using extra memory?

 

**Example 1:**

```
Input: nums = [2,2,1]
Output: 1
```

**Example 2:**

```
Input: nums = [4,1,2,1,2]
Output: 4
```

**Example 3:**

```
Input: nums = [1]
Output: 1
```

 

**Constraints:**

- `1 <= nums.length <= 3 * 104`
- `-3 * 104 <= nums[i] <= 3 * 104`
- Each element in the array appears twice except for one element which appears only once.

## Solution

``` cpp
class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int answer = 0;
    for(auto n : nums) answer ^= n;
    return answer;
  }
};
```

# Single Number II

## Description

Given an integer array `nums` where every element appears **three times** except for one, which appears **exactly once**. *Find the single element and return it*.

 

**Example 1:**

```
Input: nums = [2,2,3,2]
Output: 3
```

**Example 2:**

```
Input: nums = [0,1,0,1,0,1,99]
Output: 99
```

 

**Constraints:**

- `1 <= nums.length <= 3 * 104`
- `-231 <= nums[i] <= 231 - 1`
- Each element in `nums` appears exactly **three times** except for one element which appears **once**.

 

**Follow up:** Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

## Solution

use two integer representation ternary number for every bit.

let's draw a Karnaugh map

a is low bit, b is high bit, because is ternary, so there is no `11`

```
a	00	01	11	10
0	 0	 1	 X	 0
1	 1	 0	 X	 0
				
b	00	01	11	10
0	 0	 0	 X	 1
1	 0	 1	 X	 0

```

``` cpp
class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int a = 0;
    int b = 0;
    for(auto n : nums) {
      int tmp = (a&(~b)&(~n)) | ((~b)&(~a)&n);
      b = (b&(~a)&(~n)) | (a&n&(~b));
      a = tmp;
    }
    return a;
  }
};
```

# Single Number III

## Description

Given an integer array `nums`, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in **any order**.

**Follow up:** Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

 

**Example 1:**

```
Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.
```

**Example 2:**

```
Input: nums = [-1,0]
Output: [-1,0]
```

**Example 3:**

```
Input: nums = [0,1]
Output: [1,0]
```

 

**Constraints:**

- $2 \le nums.length \le 3 * 10^4$
- $-2^{31} \le nums[i] \le 2^{31} - 1$
- Each integer in `nums` will appear twice, only two integers will appear once.

## Solution

find different bit and use it to separate two numbers

``` cpp
class Solution {
public:
  vector<int> singleNumber(vector<int>& nums) {
    int lowbit = 0;
    for(auto n : nums) lowbit ^= n;
    
    if(lowbit == INT_MIN) lowbit = 1;
    else lowbit &= -lowbit;
    vector<int> answer{0, 0};
    for(auto n : nums) {
      if(n & lowbit) {
        answer[0] ^= n;
      } else {
        answer[1] ^= n;
      }
    }
    return answer;
  }
};

```

# April LeetCoding challenge1

## Description

**Palindrome Linked List**

Given the `head` of a singly linked list, return `true` if it is a palindrome.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/03/03/pal1linked-list.jpg)

```
Input: head = [1,2,2,1]
Output: true
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/03/03/pal2linked-list.jpg)

```
Input: head = [1,2]
Output: false
```

 

**Constraints:**

- The number of nodes in the list is in the range `[1, 105]`.
- `0 <= Node.val <= 9`

 

**Follow up:** Could you do it in `O(n)` time and `O(1)` space?

## Solution

I found previous solution is wrong before I go to sleep, what a ...

reverse half of the list

``` cpp
class Solution {
  int length(ListNode *head) {
    int len = 0;
    while(head) {
      len += 1;
      head = head->next;
    }
    return len;
  }
public:
  bool isPalindrome(ListNode* head) {
    int len = length(head);
    ListNode *newHead = nullptr;
    ListNode *cur = head;
    ListNode *prev = nullptr;
    for(int i = 0; i < len / 2; ++i) {
      prev = cur;
      cur = cur->next;
      prev->next = newHead;
      newHead = prev;
    }
    if(len & 1) cur = cur->next;
    for(int i = 0; i < len / 2; ++i) {
      if(cur->val != newHead->val) return false;
      cur = cur->next;
      newHead = newHead->next;
    }
    return true;
  }
};
```
