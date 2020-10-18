+++
title = "2020-10-18 Daily-Challenge"
path = "2020-10-18-Daily-Challenge"
date = 2020-10-18 11:39:44+08:00
updated = 2020-10-18 12:40:04+08:00
in_search_index = true

[taxonomies]
tags = ["Design", "Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [October LeetCoding Challenge](https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/559/week-1-october-1st-october-7th/3499/) with `cpp`.

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

# October LeetCoding Challenge1
