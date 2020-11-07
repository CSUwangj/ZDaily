+++
title = "2020-11-07 Daily-Challenge"
path = "2020-11-07-Daily-Challenge"
date = 2020-11-07 12:39:21+08:00
updated = 2020-11-07 17:05:32+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [October LeetCoding Challenge](https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/564/week-1-november-1st-november-7th/3522/) with `cpp`.

BTW I decided to write solution directly on website rather than on VSCode when reviewing.

<!-- more -->

# LeetCode Review

## 2 Keys Keyboard

nothing to say

``` cpp
class Solution {
public:
    int minSteps(int n) {
        int ans = 0;
        for(int i = 2; i*i <= n; ++i) {
            if(n % i != 0) continue;
            while(n % i == 0) {
                n /= i;
                ans += i;
            }
        }
        if(n != 1) ans += n;
        return ans;
    }
};
```

## Next Greater Element I

nothing to say

``` cpp
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        vector<int> monoStack;
        for(auto it = nums2.rbegin(); it != nums2.rend(); ++it) {
            while(monoStack.size() && monoStack.back() <= *it) monoStack.pop_back();
            nextGreater[*it] = monoStack.size() ? monoStack.back() : -1;
            monoStack.push_back(*it);
        }
        vector<int> answer(nums1.size());
        for(int i = 0; i < nums1.size(); ++i) {
            answer[i] = nextGreater[nums1[i]];
        }
        return answer;
    }
};
```

## Flip Columns For Maximum Number of Equal Rows

nothing to say

``` cpp
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> cnt;
        for(auto &row : matrix) {
            bool flipped = row[0];
            string cur = "";
            for(auto i : row) {
                cur += to_string(i^flipped);
            }
            cnt[cur] += 1;
        }
        return max_element(cnt.begin(), cnt.end(), [](const pair<string, int> &p1, const pair<string, int> &p2){
            return p1.second < p2.second;
        })->second;
    }
};
```

## Bulls and Cows

nothing to say

``` cpp
class Solution {
public:
    string getHint(string secret, string guess) {
        int secret_cnt[10] = {0}, guess_cnt[10] = {0};
        int bulls = 0, cows = 0;
        for(int i = 0; i < secret.size(); ++i) {
            if(secret[i] == guess[i]) bulls += 1;
            else {
                secret_cnt[secret[i]^'0'] += 1;
                guess_cnt[guess[i]^'0'] += 1;
            }
        }
        for(int i = 0; i < 10; ++i) {
            cows += min(secret_cnt[i], guess_cnt[i]);
        }
        return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }
};
```

## Bitwise ORs of Subarrays

brute force runs quicker...

``` cpp
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> cnt;
        for(int i = 0; i < A.size(); ++i) {
            int pre = 0;
            cnt.insert(A[i]);
            for(int j = i-1; j >= 0 && (pre|A[i]) != pre; --j) {
                pre |= A[j];
                cnt.insert(pre|A[i]);
            }
        }
        return cnt.size();
    }
};
```

## Find the Smallest Divisor Given a Threshold

nothing to say

``` cpp
class Solution {
    bool satisfied(vector<int> &nums, int threshold, double k) {
        int sum = 0;
        for(auto i : nums) {
            sum += ceil(i/k);
        }
        return sum <= threshold;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start = 1, end = INT_MAX-1;
        while(start < end) {
            int mid = (start+end) / 2;
            if(satisfied(nums, threshold, mid)) end = mid;
            else start = mid+1;
        }
        return start;
    }
};
```

## Minimum Cost to Move Chips to The Same Position

nothing to say

``` cpp
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int parity[2] = {0};
        for(auto p : position) {
            parity[p&1] += 1;
        }
        return parity[0] < parity[1] ? parity[0] : parity[1];
    }
};
```

## Consecutive Characters

nothing to say

``` cpp
class Solution {
public:
    int maxPower(string s) {
        int ans = 0, cnt = 0;
        char cur;
        for(auto c : s) {
            if(c != cur) {
                cur = c;
                cnt = 0;
            }
            cnt += 1;
            ans = max(cnt, ans);
        }
        return ans;
    }
};
```

## Insertion Sort List

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
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *newHead = new ListNode(INT_MIN);
        ListNode *cur = head;
        while(cur) {
            ListNode *insertPoint = newHead;
            while(insertPoint->next && insertPoint->next->val < cur->val) insertPoint = insertPoint->next;
            ListNode *tmp = cur->next;
            cur->next = insertPoint->next;
            insertPoint->next = cur;
            cur = tmp;
        }
        return newHead->next;
    }
};
```

# November LeetCoding Challenge7

**Add Two Numbers II**

## Description

You are given two **non-empty** linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

**Follow up:**
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

**Example:**

```
Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
```

## Solution

parity

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
    pair<ListNode*, int> addTwoNumber(ListNode* l1, int len1, ListNode* l2, int len2) {
        if(!len1 || !len2) return len1 ? make_pair(l1, 0) : make_pair(l2, 0);
        ListNode *nextNode;
        int carry, curVal;
        if(len1 > len2) {
            tie(nextNode, carry) = addTwoNumber(l1->next, len1-1, l2, len2);
            curVal = l1->val + carry;
        } else if(len1 < len2) {
            tie(nextNode, carry) = addTwoNumber(l1, len1, l2->next, len2-1);
            curVal = l2->val + carry;
        } else {
            tie(nextNode, carry) = addTwoNumber(l1->next, len1-1, l2->next, len2-1);
            curVal = l1->val +l2->val + carry;
        }
        ListNode *node = new ListNode(curVal%10, nextNode);
        return make_pair(node, curVal/10);
    }
    
    int length(ListNode* l) {
        int len = 0;
        while(l) {
            len += 1;
            l = l->next;
        }
        return len;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = length(l1);
        int len2 = length(l2);
        auto [head, carry] = addTwoNumber(l1, len1, l2, len2);
        if(!carry) return head;
        return new ListNode(carry, head);
    }
};
```
