+++
title = "2021-04-20 Daily-Challenge"
path = "2021-04-20-Daily-Challenge"
date = 2021-04-20 18:23:35+08:00
updated = 2021-04-20 20:33:36+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Human Traffic of Stadium](https://leetcode.com/problems/human-traffic-of-stadium/) with `sql`, [Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/), [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/), [Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/), [Number of Lines To Write String](https://leetcode.com/problems/number-of-lines-to-write-string/), and leetcode's [April LeetCoding Challenge](https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/595/week-3-april-15th-april-21st/3714/) with `cpp`.

<!-- more -->

# Human Traffic of Stadium

## Description

<details>
  <summary>SQL Schema</summary>
<pre style="background-color:#2b303b;"><code><span style="color:#c0c5ce;">Create table If Not Exists stadium (id int, visit_date DATE NULL, people int)
Truncate table stadium
insert into stadium (id, visit_date, people) values ('1', '2017-01-01', '10')
insert into stadium (id, visit_date, people) values ('2', '2017-01-02', '109')
insert into stadium (id, visit_date, people) values ('3', '2017-01-03', '150')
insert into stadium (id, visit_date, people) values ('4', '2017-01-04', '99')
insert into stadium (id, visit_date, people) values ('5', '2017-01-05', '145')
insert into stadium (id, visit_date, people) values ('6', '2017-01-06', '1455')
insert into stadium (id, visit_date, people) values ('7', '2017-01-07', '199')
insert into stadium (id, visit_date, people) values ('8', '2017-01-09', '188')
</span></code></pre>
</details>

Table: `Stadium`

```
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| visit_date    | date    |
| people        | int     |
+---------------+---------+
visit_date is the primary key for this table.
Each row of this table contains the visit date and visit id to the stadium with the number of people during the visit.
No two rows will have the same visit_date, and as the id increases, the dates increase as well.
```

 

Write an SQL query to display the records with three or more rows with **consecutive** `id`'s, and the number of people is greater than or equal to 100 for each.

Return the result table ordered by `visit_date` in **ascending order**.

The query result format is in the following example.

 

```
Stadium table:
+------+------------+-----------+
| id   | visit_date | people    |
+------+------------+-----------+
| 1    | 2017-01-01 | 10        |
| 2    | 2017-01-02 | 109       |
| 3    | 2017-01-03 | 150       |
| 4    | 2017-01-04 | 99        |
| 5    | 2017-01-05 | 145       |
| 6    | 2017-01-06 | 1455      |
| 7    | 2017-01-07 | 199       |
| 8    | 2017-01-09 | 188       |
+------+------------+-----------+

Result table:
+------+------------+-----------+
| id   | visit_date | people    |
+------+------------+-----------+
| 5    | 2017-01-05 | 145       |
| 6    | 2017-01-06 | 1455      |
| 7    | 2017-01-07 | 199       |
| 8    | 2017-01-09 | 188       |
+------+------------+-----------+
The four rows with ids 5, 6, 7, and 8 have consecutive ids and each of them has >= 100 people attended. Note that row 8 was included even though the visit_date was not the next day after row 7.
The rows with ids 2 and 3 are not included because we need at least three consecutive ids.
```

## Solution

``` SQL
SELECT distinct t1.*
FROM stadium t1, stadium t2, stadium t3
WHERE t1.people >= 100 AND t2.people >= 100 AND t3.people >= 100
AND
(
    (t1.id - t2.id = 1 AND t1.id - t3.id = 2 AND t2.id - t3.id = 1) -- t1, t2, t3
    OR
    (t2.id - t1.id = 1 AND t2.id - t3.id = 2 AND t1.id - t3.id = 1) -- t2, t1, t3
    OR
    (t2.id - t3.id = 1 AND t3.id - t1.id = 1 AND t2.id - t1.id = 2) -- t2, t3, t1
)
ORDER BY t1.id;
```

# Number of Lines To Write String

## Description

You are given a string `s` of lowercase English letters and an array `widths` denoting **how many pixels wide** each lowercase English letter is. Specifically, `widths[0]` is the width of `'a'`, `widths[1]` is the width of `'b'`, and so on.

You are trying to write `s` across several lines, where **each line is no longer than** `100` **pixels**. Starting at the beginning of `s`, write as many letters on the first line such that the total width does not exceed `100` pixels. Then, from where you stopped in `s`, continue writing as many letters as you can on the second line. Continue this process until you have written all of `s`.

Return *an array* `result` *of length 2 where:*

- `result[0]` *is the total number of lines.*
- `result[1]` *is the width of the last line in pixels.*

 

**Example 1:**

```
Input: widths = [10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10], s = "abcdefghijklmnopqrstuvwxyz"
Output: [3,60]
Explanation: You can write s as follows:
abcdefghij  // 100 pixels wide
klmnopqrst  // 100 pixels wide
uvwxyz      // 60 pixels wide
There are a total of 3 lines, and the last line is 60 pixels wide.
```

**Example 2:**

```
Input: widths = [4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10], s = "bbbcccdddaaa"
Output: [2,4]
Explanation: You can write s as follows:
bbbcccdddaa  // 98 pixels wide
a            // 4 pixels wide
There are a total of 2 lines, and the last line is 4 pixels wide.
```

 

**Constraints:**

- `widths.length == 26`
- `2 <= widths[i] <= 10`
- `1 <= s.length <= 1000`
- `s` contains only lowercase English letters.

## Solution

``` cpp
class Solution {
public:
  vector<int> numberOfLines(vector<int>& widths, string s) {
    int line = 1;
    int cur = 0;
    for(auto c : s) {
      if(widths[c - 'a'] + cur > 100) {
        line += 1;
        cur = 0;
      }
      cur += widths[c - 'a'];
    }
    return {line, cur};
  }
};
```

# Binary Tree Preorder Traversal

## Description

Given the `root` of a binary tree, return *the preorder traversal of its nodes' values*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/09/15/inorder_1.jpg)

```
Input: root = [1,null,2,3]
Output: [1,2,3]
```

**Example 2:**

```
Input: root = []
Output: []
```

**Example 3:**

```
Input: root = [1]
Output: [1]
```

**Example 4:**

![img](https://assets.leetcode.com/uploads/2020/09/15/inorder_5.jpg)

```
Input: root = [1,2]
Output: [1,2]
```

**Example 5:**

![img](https://assets.leetcode.com/uploads/2020/09/15/inorder_4.jpg)

```
Input: root = [1,null,2]
Output: [1,2]
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[0, 100]`.
- `-100 <= Node.val <= 100`

 

**Follow up:** Recursive solution is trivial, could you do it iteratively?

## Solution

``` cpp
class Solution {
public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> answer;
    TreeNode *cur = root;
    while(cur) {
      if(!(cur->left)) {
        answer.push_back(cur->val);
        cur = cur->right;
      } else {
        TreeNode *left = cur->left;
        while(left->right && left->right != cur) {
          left = left->right;
        }
        if(left->right == cur) {
          left->right = nullptr;
          cur = cur->right;
        } else {
          answer.push_back(cur->val);
          left->right = cur;
          cur = cur->left;
        }
      }
    }
    return answer;
  }
};
```

# Binary Tree Inorder Traversal

## Description

Given the `root` of a binary tree, return *the inorder traversal of its nodes' values*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/09/15/inorder_1.jpg)

```
Input: root = [1,null,2,3]
Output: [1,3,2]
```

**Example 2:**

```
Input: root = []
Output: []
```

**Example 3:**

```
Input: root = [1]
Output: [1]
```

**Example 4:**

![img](https://assets.leetcode.com/uploads/2020/09/15/inorder_5.jpg)

```
Input: root = [1,2]
Output: [2,1]
```

**Example 5:**

![img](https://assets.leetcode.com/uploads/2020/09/15/inorder_4.jpg)

```
Input: root = [1,null,2]
Output: [1,2]
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[0, 100]`.
- `-100 <= Node.val <= 100`

 

**Follow up:**

Recursive solution is trivial, could you do it iteratively?

## Solution

``` cpp
class Solution {
public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> answer;
    TreeNode *cur = root;
    while(cur) {
      if(!(cur->left)) {
        answer.push_back(cur->val);
        cur = cur->right;
      } else {
        TreeNode *left = cur->left;
        while(left->right && left->right != cur) {
          left = left->right;
        }
        if(left->right == cur) {
          answer.push_back(cur->val);
          left->right = nullptr;
          cur = cur->right;
        } else {
          left->right = cur;
          cur = cur->left;
        }
      }
    }
    return answer;
  }
};
```

# Binary Tree Postorder Traversal

## Description

Given the `root` of a binary tree, return *the postorder traversal of its nodes' values*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/08/28/pre1.jpg)

```
Input: root = [1,null,2,3]
Output: [3,2,1]
```

**Example 2:**

```
Input: root = []
Output: []
```

**Example 3:**

```
Input: root = [1]
Output: [1]
```

**Example 4:**

![img](https://assets.leetcode.com/uploads/2020/08/28/pre3.jpg)

```
Input: root = [1,2]
Output: [2,1]
```

**Example 5:**

![img](https://assets.leetcode.com/uploads/2020/08/28/pre2.jpg)

```
Input: root = [1,null,2]
Output: [2,1]
```

 

**Constraints:**

- The number of the nodes in the tree is in the range `[0, 100]`.
- `-100 <= Node.val <= 100`

 

**Follow up:**

Recursive solution is trivial, could you do it iteratively?

## Solution

``` cpp
class Solution {
public:
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> answer;
    TreeNode *cur = root;
    while(cur) {
      if(!(cur->right)) {
        answer.push_back(cur->val);
        cur = cur->left;
      } else {
        TreeNode *right = cur->right;
        while(right->left && right->left != cur) {
          right = right->left;
        }
        if(right->left == cur) {
          right->left = nullptr;
          cur = cur->left;
        } else {
          answer.push_back(cur->val);
          right->left = cur;
          cur = cur->right;
        }
      }
    }
    reverse(answer.begin(), answer.end());
    return answer;
  }
};
```

# April LeetCoding challenge 20

## Description

**N-ary Tree Preorder Traversal**

Given the `root` of an n-ary tree, return *the preorder traversal of its nodes' values*.

Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png)

```
Input: root = [1,null,3,2,4,null,5,6]
Output: [1,3,5,6,2,4]
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2019/11/08/sample_4_964.png)

```
Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [1,2,3,6,7,11,14,4,8,12,5,9,13,10]
```

 

**Constraints:**

- The number of nodes in the tree is in the range <code>[0, 10<sup>4</sup>]</code>.
- `0 <= Node.val <= 104`
- The height of the n-ary tree is less than or equal to `1000`.

 

**Follow up:** Recursive solution is trivial, could you do it iteratively?

## Solution

I failed to come up with morris traversal in this case.

``` cpp
class Solution {
  void solve(vector<int> &answer, Node* cur) {
    if(!cur) return;
    answer.push_back(cur->val);
    for(auto node : cur->children) {
      solve(answer, node);
    }
  }
public:
  vector<int> preorder(Node* root) {
    vector<int> answer;
    solve(answer, root);
    return answer;
  }
};
```
