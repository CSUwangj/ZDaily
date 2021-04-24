+++
title = "2020-12-05 Daily-Challenge"
path = "2020-12-05-Daily-Challenge"
date = 2020-12-05 11:26:27+08:00
updated = 2020-12-05 16:50:24+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [November LeetCoding Challenge](https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/569/week-1-december-1st-december-7th/3555/) with `cpp`.

<!-- more -->

# LeetCode Review

## The Skyline Problem

nothing to say

``` cpp
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<tuple<int, int, int>> points;
        for(auto &b : buildings) {
            points.push_back(make_tuple(b[0], b[1], b[2]));
            points.push_back(make_tuple(b[1], -1, b[2]));
        }
        sort(points.begin(), points.end(), [](tuple<int, int, int> &a, tuple<int, int, int> &b){
            auto [al, ar, ah] = a;
            auto [bl, br, bh] = b;
            return al < bl || (al == bl && ((ar != -1 && br == -1) || (ar != -1 && br != -1 && ah > bh)));
        });
        int curHeight = 0;
        priority_queue<pair<int, int>> q;
        vector<vector<int>> answer;
        for(auto [curPos, rightPos, height] : points) {
            if(rightPos == -1) {
                while(q.size() && q.top().second >= -curPos) q.pop();
                int newHeight = q.size() ? q.top().first : 0;
                if(newHeight != curHeight) answer.push_back({curPos, newHeight});
                curHeight = newHeight;
            } else {
                // -rightPos is little trick that i dont need to write compare
                // function for priority queue
                q.push(make_pair(height, -rightPos));
                if(height > curHeight) {
                    curHeight = height;
                    answer.push_back({curPos, curHeight});
                }
            }
        }
        return answer;
    }
};
```

## Power of Two

nothing to say

``` cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && n == (n&(-n));
    }
};
```

## Maximum Depth of Binary Tree

nothing to say

``` cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return root ? 1+max(maxDepth(root->left), maxDepth(root->right)) : 0;
    }
};
```

## Substring with Concatenation of All Words

simple solution gets better result

time complexity is $O(sn)$

``` cpp
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> cnt;
        int wordLen = words[0].length();
        int total = words.size();
        int slen = s.length();
        for(auto &word : words) {
            cnt[word] += 1;
        }
        vector<int> answer;
        for(int i = 0; i <= slen - total*wordLen; ++i) {
            if(cnt.count(s.substr(i, wordLen))) {
                int rest = total;
                unordered_map<string, int> cur = cnt;
                int pos = i;
                string curWord = s.substr(pos, wordLen);
                do {
                    cur[curWord] -= 1;
                    rest -= 1;
                    if(!cur[curWord]) cur.erase(curWord);
                    pos += wordLen;
                    curWord = s.substr(pos, wordLen);
                }while(rest && cur.count(curWord));
                if(rest == 0) {
                    answer.push_back(i);
                }
            }
        }
        return answer;
    }
};
```

## Unique Paths II

nothing to say

``` cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.front().front() || obstacleGrid.back().back()) return 0;
        int w = obstacleGrid[0].size(), h = obstacleGrid.size();
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        dp[0][0] = 1;
        for(int i = 0; i < h; ++i) {
            for(int j = 0; j < w; ++j) {
                if(obstacleGrid[i][j]) continue;
                if(i) dp[i][j] += dp[i-1][j];
                if(j) dp[i][j] += dp[i][j-1];
            }
        }
        return dp.back().back();
    }
};
```

## Linked List Random Node

Reservoir Sampling

``` cpp
class Solution {
    ListNode* head;
    mt19937 generator;
    uniform_real_distribution<double> distribution = uniform_real_distribution<double>(0.0, 1.0);
    function<double(void)> rng = bind(distribution, generator);
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode *cur = head;
        double curIndex = 1;
        int result = -1;
        while(cur) {
            if(rng() < 1 / curIndex) result = cur->val;
            cur = cur->next;
            curIndex += 1;
        }
        return result;
    }
};
```

## Decrypt String from Alphabet to Integer Mapping

nothing to say

``` cpp
class Solution {
public:
    string freqAlphabets(string s) {
        int cur = 0;
        string answer;
        for(auto c : s) {
            if(isdigit(c)) {
                cur *= 10;
                cur += c - '0';
                if(cur > 99) {
                    answer.push_back((cur / 100) + 96);
                    cur %= 100;
                }
            } else {
                answer.push_back(cur + 96);
                cur = 0;
            }
        }
        if(cur) {
            if(cur > 9) answer.push_back((cur / 10) + 96);
            answer.push_back((cur % 10) + 96);
        }
        return answer;
    }
};
```

## Increasing Order Search Tree

nothing to say

``` cpp
class Solution {
    void inorder(TreeNode *root, TreeNode *&cur) {
        if(!root) return;
        inorder(root->left, cur);
        cur->right = new TreeNode(root->val);
        cur = cur->right;
        inorder(root->right, cur);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *newRoot = new TreeNode(-1);
        TreeNode *cur = newRoot;
        inorder(root, cur);
        return newRoot->right;
    }
};
```

## Sort the Matrix Diagonally

disgusting problem, won't redo it.

## Merge k Sorted Lists

devide and conquer

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
    ListNode* merge2Lists(ListNode *a, ListNode *b) {
        ListNode *newHead = new ListNode(-1);
        ListNode *cur = newHead;
        while(a && b) {
            if(a->val < b->val) {
                cur->next = a;
                a = a->next;
                cur = cur->next;
            } else {
                cur->next = b;
                b = b->next;
                cur = cur->next;
            }
        }
        if(a) cur->next = a;
        if(b) cur->next = b;
        return newHead->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        int interval = 1;
        int len = lists.size();
        while(interval < len) {
            for(int i = 0; i+interval < len; i += 2*interval) {
                lists[i] = merge2Lists(lists[i], lists[i+interval]);
            }
            interval *= 2;
        }
        return lists.front();
    }
};
```

## The kth Factor of n

too easy to review

## Equal Rational Numbers

same ways, more elegant codes.

``` cpp
class Solution {
    pair<string, string> unify(string n) {
        int pos = 0, len = n.length();
        string number, decimal, repeatPart;
        while(pos < len && isdigit(n[pos])) {
            number += n[pos];
            pos += 1;
        }
        if(pos == len) return make_pair(number, string(16, '0'));
        pos += 1;
        while(pos < len && isdigit(n[pos])) {
            decimal += n[pos];
            pos += 1;
        }
        if(pos == len) return make_pair(number, decimal + string(4-decimal.length() + 12, '0'));
        pos += 1;
        bool all9 = true, all0 = true;
        while(pos < len && isdigit(n[pos])) {
            if(n[pos] != '9') all9 = false;
            if(n[pos] != '0') all0 = false;
            repeatPart += n[pos];
            pos += 1;
        }
        if(all9) {
            repeatPart = "0";
            int carry = 1;
            for(auto it = decimal.rbegin(); carry && it != decimal.rend(); ++it) {
                if(*it == '9') *it = '0';
                else {
                    *it += 1;
                    carry = 0;
                }
            }
            for(auto it = number.rbegin(); carry && it != number.rend(); ++it) {
                if(*it == '9') *it = '0';
                else {
                    *it += 1;
                    carry = 0;
                }
            }
            if(carry) number = "1" + number;
        }
        if(decimal.length() < 4) {
          if(repeatPart.length() == 1) {
              decimal += string(4-decimal.length(), repeatPart[0]);
          } else {
              while(decimal.length() < 4) {
                  decimal += repeatPart[0];
                  repeatPart = repeatPart.substr(1) + repeatPart[0];
              }
          }
        }
        while(decimal.length() < 16) {
            decimal += repeatPart;
        }
        return make_pair(number, decimal);
    }
public:
    bool isRationalEqual(string S, string T) {
        return unify(S) == unify(T);
    }
};
```

# December LeetCoding Challenge5

## Description

**Can Place Flowers**

You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in **adjacent** plots.

Given an integer array `flowerbed` containing `0`'s and `1`'s, where `0` means empty and `1` means not empty, and an integer `n`, return *if* `n` new flowers can be planted in the `flowerbed` without violating the no-adjacent-flowers rule.

**Example 1:**

```
Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
```

**Example 2:**

```
Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
```

**Constraints:**

- `1 <= flowerbed.length <= 2 * 104`
- `flowerbed[i]` is `0` or `1`.
- There are no two adjacent flowers in `flowerbed`.
- `0 <= n <= flowerbed.length`

## Solution

solution is easy, but think of elegant solutions is not so easy.

``` cpp
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int maxCount = 0;
        int zero = 0;
        for(int i = 0; i < flowerbed.size(); ++i) {
            if(!flowerbed[i]) {
                zero += 1;
            } else {
                maxCount += zero / 2;
                zero = -1;
            }
        }
        if(zero) maxCount += (zero + 1) / 2;
        return maxCount >= n;
    }
};
```
