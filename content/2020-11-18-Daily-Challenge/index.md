+++
title = "2020-11-18 Daily-Challenge"
path = "2020-11-18-Daily-Challenge"
date = 2020-11-18 00:32:13+08:00
updated = 2020-11-18 19:54:24+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done *Count Complete Tree Nodes* on [leetcode](https://leetcode.com/problems/count-complete-tree-nodes/) and leetcode's [November LeetCoding Challenge](https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/566/week-3-november-15th-november-21st/3535/) with `cpp`.

<!-- more -->

# Count Complete Tree Nodes

## Description

Given a **complete** binary tree, count the number of nodes.

**Note:**

**Definition of a complete binary tree from [Wikipedia](http://en.wikipedia.org/wiki/Binary_tree#Types_of_binary_trees):**
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

**Example:**

```
Input: 
    1
   / \
  2   3
 / \  /
4  5 6

Output: 6
```

## Solution

nothing to say

``` cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
```

# November LeetCoding Challenge18

## Description

**Merge Intervals**

Given an array of `intervals` where `intervals[i] = [starti, endi]`, merge all overlapping intervals, and return *an array of the non-overlapping intervals that cover all the intervals in the input*.

**Example 1**

```
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
```

**Example 2:**

```
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
```

**Constraints:**

- `1 <= intervals.length <= 104`
- `intervals[i].length == 2`
- `0 <= starti <= endi <= 104`

## Solution

nothing to say

``` cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pair<int, int>> q;
        for(auto &interval : intervals) {
            q.push_back(make_pair(interval[0], 0));
            q.push_back(make_pair(interval[1], 1));
        }
        sort(q.begin(), q.end());
        
        vector<vector<int>> answer;
        int cnt = 0;
        int start = -1;
        for(auto &[point, type] : q) {
            if(type == 1) {
                cnt -= 1;
                if(cnt == 0) {
                    answer.push_back({start, point});
                }
            }
            if(type == 0) {
                if(cnt == 0) {
                    start = point;
                }
                cnt += 1;
            }
        }
        return answer;
    }
};
```
