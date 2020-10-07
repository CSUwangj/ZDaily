+++
title = "2020-10-06 Daily-Challenge"
path = "2020-10-06-Daily-Challenge"
date = 2020-10-06 01:36:36+08:00
updated = 2020-10-06 15:58:26+08:00
in_search_index = true

[taxonomies]
tags = ["Design", "Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is an example of *The non-Designer's Design Book* on bottom of Page 72-73 and *Distribute Candies to People* on [leetcode](https://leetcode.com/problems/distribute-candies-to-people/) and leetcode's [October LeetCoding Challenge](https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/559/week-1-october-1st-october-7th/3485/) with `cpp`.

<!-- more -->

# The non-Designer's Design Book

my answer:

- [F] change font
- [F] add background for the shop name
- [F] use circle for shop name decoration
- [T] use left align and right align
- [T] use conspicuous way to display `SOMEBODY NEEDS A HUG`
- [F] use `·` to separate contact information
- [T] remove abundant `TELEPHONE`
- [T] use sentence case for URL
- [F] use part of pie image

# Distribute Candies to People

## Description

We distribute some number of `candies`, to a row of **`n = num_people`** people in the following way:

We then give 1 candy to the first person, 2 candies to the second person, and so on until we give `n` candies to the last person.

Then, we go back to the start of the row, giving `n + 1` candies to the first person, `n + 2` candies to the second person, and so on until we give `2 * n` candies to the last person.

This process repeats (with us giving one more candy each time, and moving to the start of the row after we reach the end) until we run out of candies. The last person will receive all of our remaining candies (not necessarily one more than the previous gift).

Return an array (of length `num_people` and sum `candies`) that represents the final distribution of candies.

**Example 1:**

```
Input: candies = 7, num_people = 4
Output: [1,2,3,1]
Explanation:
On the first turn, ans[0] += 1, and the array is [1,0,0,0].
On the second turn, ans[1] += 2, and the array is [1,2,0,0].
On the third turn, ans[2] += 3, and the array is [1,2,3,0].
On the fourth turn, ans[3] += 1 (because there is only one candy left), and the final array is [1,2,3,1].
```

**Example 2:**

```
Input: candies = 10, num_people = 3
Output: [5,2,3]
Explanation: 
On the first turn, ans[0] += 1, and the array is [1,0,0].
On the second turn, ans[1] += 2, and the array is [1,2,0].
On the third turn, ans[2] += 3, and the array is [1,2,3].
On the fourth turn, ans[0] += 4, and the final array is [5,2,3].
```

**Constraints:**

- 1 <= candies <= 10^9
- 1 <= num_people <= 1000

## Solution

using binary search to find after which turn candies is over, then distribute these turns to people.

``` cpp
class Solution {
public:
  vector<int> distributeCandies(int candies, int num_people) {
    vector<int> answer(num_people);
    int begin = 0, end=sqrt(candies)*1.6;
    while (begin < end) {
      int mid = (begin + end)/2;
      if(1LL*mid*(mid+1)/2 > candies) {
        end = mid;
      } else {
        begin = mid + 1;
      }
    }
    int turns = end - 1;
    int rounds = turns / num_people, remainder = turns % num_people, last = candies - 1LL*turns*(turns+1)/2;
    for(int i = 0; i < num_people; ++i) {
      answer[i] = (i+1) * rounds + 1LL*(rounds-1)*rounds*num_people/2;
      if(i < remainder) {
        answer[i] += rounds*num_people + i+1;
      }
    }
    answer[remainder] += last;
    return answer;
  }
};
```

# October LeetCoding Challenge6

## Description

**Insert into a Binary Search Tree**

You are given the `root` node of a binary search tree (BST) and a `value` to insert into the tree. Return *the root node of the BST after the insertion*. It is **guaranteed** that the new value does not exist in the original BST.

**Notice** that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return **any of them**.

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/10/05/insertbst.jpg)

```
Input: root = [4,2,7,1,3], val = 5
Output: [4,2,7,1,3,5]
Explanation: Another accepted tree is:
```

**Example 2:**

```
Input: root = [40,20,60,10,30,50,70], val = 25
Output: [40,20,60,10,30,50,70,null,null,25]
```

**Example 3:**

```
Input: root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
Output: [4,2,7,1,3,5]
```

**Constraints:**

- The number of nodes in the tree will be in the range `[0, 104]`.
- `-108 <= Node.val <= 108`
- All the values `Node.val` are **unique**.
- `-108 <= val <= 108`
- It's **guaranteed** that `val` does not exist in the original BST.

## Solution

my code is somewhat ugly, rewrite it later.

``` cpp
class Solution {
public:
  TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(!root) {
      root = new TreeNode(val);
    }
    if(val < root->val) {
      if(root->left) {
        insertIntoBST(root->left, val);
      } else {
        root->left = new TreeNode(val);
      }
    } else if(val > root->val) {
      if(root->right) {
        insertIntoBST(root->right, val);
      } else {
        root->right = new TreeNode(val);
      }
    }
    return root;
  }
};
```