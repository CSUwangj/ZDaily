+++
title = "2021-03-04 Daily-Challenge"
path = "2021-03-04-Daily-Challenge"
date = 2021-03-04 18:07:32+08:00
updated = 2021-03-04 18:59:43+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Majority Element II](https://leetcode.com/problems/majority-element-ii/) and leetcode's [March LeetCoding Challenge](https://leetcode.com/explore/featured/card/march-leetcoding-challenge-2021/588/week-1-march-1st-march-7th/3660/) with `cpp`.

<!-- more -->

# Majority Element II

## Description

Given an integer array of size `n`, find all elements that appear more than `⌊ n/3 ⌋` times.

**Follow-up:** Could you solve the problem in linear time and in O(1) space?

 

**Example 1:**

```
Input: nums = [3,2,3]
Output: [3]
```

**Example 2:**

```
Input: nums = [1]
Output: [1]
```

**Example 3:**

```
Input: nums = [1,2]
Output: [1,2]
```

 

**Constraints:**

- $1 \le nums.length \le 5 \times 10^4$
- $-10^9 \le nums[i] \le 10^9$

## Solution

similar to [Majority Element](https://leetcode.com/problems/majority-element/)

``` cpp
class Solution {
    const int IMPOSSIBLE = INT_MAX;
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> candidates{IMPOSSIBLE, IMPOSSIBLE};
        vector<int> count{0, 0};
        for(auto num : nums) {
            if(num == candidates[0]) {
                count[0] += 1;
            } else if(num == candidates[1]) {
                count[1] += 1;
            } else if(count[0] == 0) {
                candidates[0] = num;
                count[0] = 1;
            } else if(count[1] == 0) {
                candidates[1] = num;
                count[1] = 1;
            } else {
                count[0] -= 1;
                count[1] -= 1;
            }
        }
        vector<int> answer;
        int len = nums.size();
        for(auto candidate : candidates) {
            int cnt = 0;
            for(auto num : nums) cnt += (num == candidate);
            if(cnt > len / 3) answer.push_back(candidate);
        }
        return answer;
    }
};
```

# March LeetCoding Challenge 4

## Description

**Missing Number**

Given an array `nums` containing `n` distinct numbers in the range `[0, n]`, return *the only number in the range that is missing from the array.*

**Follow up:** Could you implement a solution using only `O(1)` extra space complexity and `O(n)` runtime complexity?

 

**Example 1:**

```
Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
```

**Example 2:**

```
Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
```

**Example 3:**

```
Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.
```

**Example 4:**

```
Input: nums = [0]
Output: 1
Explanation: n = 1 since there is 1 number, so all numbers are in the range [0,1]. 1 is the missing number in the range since it does not appear in nums.
```

 

**Constraints:**

- `n == nums.length`
- $1 \le n \le 10^4$
- `0 <= nums[i] <= n`
- All the numbers of `nums` are **unique**.

## Solution

``` cpp
class Solution {
    pair<int, ListNode*> getLengthAndTail(ListNode *head) {
        ListNode *tail;
        int len = 0;
        while(head) {
            len += 1;
            tail = head;
            head = head->next;
        }
        return make_pair(len, tail);
    }
    ListNode* advance(ListNode *head, int dis) {
        while(head && dis) {
            head = head->next;
            dis -= 1;
        }
        return head;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto [lenA, tailA] = getLengthAndTail(headA);
        auto [lenB, tailB] = getLengthAndTail(headB);
        if(tailA != tailB) return nullptr;
        if(lenA > lenB) headA = advance(headA, lenA - lenB);
        if(lenB > lenA) headB = advance(headB, lenB - lenA);
        while(headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};


// 46 / 46 test cases passed.
// Status: Accepted
// Runtime: 40 ms
// Memory Usage: 14.6 MB

```

``` cpp
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA = headA;
        ListNode *curB = headB;
        while(curA != curB) {
            curA = curA ? curA->next : headB;
            curB = curB ? curB->next : headA;
        }
        return curA;
    }
};


// 46 / 46 test cases passed.
// Status: Accepted
// Runtime: 56 ms
// Memory Usage: 14.4 MB

```