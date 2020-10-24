+++
title = "2020-10-18 Daily-Challenge"
path = "2020-10-18-Daily-Challenge"
date = 2020-10-18 11:39:44+08:00
updated = 2020-10-18 23:02:02+08:00
in_search_index = true

[taxonomies]
tags = ["Design", "Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Sunday, I gonna review the tasks I've done this week, and finish today's leetcode's [October LeetCoding Challenge](https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/559/week-3-october-15th-october-21st/3499/) with `cpp`.

<!-- more -->

# The non-Designer's Design Book

my second answer on Page 71:

- [T] use black background
- [T] increase the font size of website information, and it is well cut to let website in a single line
- [T] increase the font size of the title
- [T] use the same font for `WHY ... OTHERS?` as the logo
- [T] repeat the red at the dotted line of the bottom
- [F] align dotted line with website information

reference answer has three more differences:

- spacing between main text decrement by half a pound, so there is more space
- text block has been widened so the last line of the main text becomes a complete sentence
- cut off the title in a more suitable position

# LeetCode review

## Sort List

bottom-up merge sort

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
    int length(ListNode* head){
        int len = 0;
        while(head) {
            len += 1;
            head = head->next;
        }
        return len;
    }
public:
    ListNode* sortList(ListNode* head) {
        int interval = 1, len = length(head);
        if(len < 2) return head;
        ListNode *new_head = new ListNode(-1, head);
        while(interval < len) {
            ListNode *pre = new_head, *h = pre->next;
            while(h) {
                ListNode *h1 = h;
                int cnt = interval;
                while(h && cnt) {
                    h = h->next;
                    cnt -= 1;
                }
                if(cnt) break;
                ListNode *h2 = h;
                cnt = interval;
                while(h && cnt) {
                    h = h->next;
                    cnt -= 1;
                }
                int len1 = interval, len2 = interval - cnt;
                while(len1 && len2) {
                    if(h1->val < h2->val) {
                        pre->next = h1;
                        h1 = h1->next;
                        len1 -= 1;
                    } else {
                        pre->next = h2;
                        h2 = h2->next;
                        len2 -= 1;
                    }
                    pre = pre->next;
                }
                pre->next = len1 ? h1 : h2;
                while(len1 > 0 || len2 > 0) {
                    pre = pre->next;
                    len1 -= 1;
                    len2 -= 1;
                }
                pre->next = h;
            }
            interval *= 2;
        }
        return new_head->next;
    }
};
```

## Maximum Number of Achievable Transfer Requests

use dfs to enumerate combinations

dfs has a shortcoming that can not enumerate combinations by number of `1` in its binary representation

``` cpp
class Solution {
    vector<int> record;
    int ans;
    bool sat() {
        for(auto i : record) {
            if(i) return false;
        }
        return true;
    }
    void dfs(int index, int cur, vector<vector<int>>& requests){
        if(index == requests.size()) {
            if(sat() && cur > ans) ans = cur;
            return;
        }
        dfs(index+1, cur, requests);
        record[requests[index][0]] -= 1;
        record[requests[index][1]] += 1;
        dfs(index+1, cur+1, requests);
        record[requests[index][0]] += 1;
        record[requests[index][1]] -= 1;
    }
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        record = vector<int>(n+1);
        dfs(0, 0, requests);
        return ans;
    }
};
```

# October LeetCoding Challenge18

## Description

**Best Time to Buy and Sell Stock IV**

You are given an integer array `prices` where `prices[i]` is the price of a given stock on the `ith` day.

Design an algorithm to find the maximum profit. You may complete at most `k` transactions.

**Notice** that you may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

**Example 1:**

```
Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
```

**Example 2:**

```
Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
```

**Constraints:**

- `0 <= k <= 109`
- `0 <= prices.length <= 104`
- `0 <= prices[i] <= 1000`

## Solution

dp

``` cpp
class Solution {
  int maxProfit(vector<int>& prices) {
    int ans = 0;
    for(int i = 1; i < prices.size(); ++i) {
      if(prices[i] > prices[i-1]) ans += prices[i] - prices[i-1];
    }
    return ans;
  }
 public:
  int maxProfit(int k, vector<int>& prices) {
    if(!prices.size()) return 0;
    if(k*2 >= prices.size()) return maxProfit(prices);
    vector<int> dp(prices.size());
    for(int i = 0; i < k; ++i) {
      int previous = dp[0];
      int min_paid = prices[0];
      for(int j = 1; j < prices.size(); ++j) {
        int tmp = dp[j];
        min_paid = min(min_paid, prices[j]-previous);
        dp[j] = max(dp[j-1], prices[j]-min_paid);
        previous = tmp;
      }
    }
    return dp[prices.size()-1];
  }
};
```