+++
title = "2022-01-27 Daily-Challenge"
path = "2022-01-27-Daily-Challenge"
date = 2022-01-27 19:02:00+08:00
updated = 2022-01-27 19:39:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 26

## Description

**Maximum XOR of Two Numbers in an Array**

Given an integer array `nums`, return *the maximum result of* `nums[i] XOR nums[j]`, where `0 <= i <= j < n`.

 

**Example 1:**

```
Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.
```

**Example 2:**

```
Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
Output: 127
```

 

**Constraints:**

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
</ul>


## Solution

devide and conquer

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
struct TrieNode {
  TrieNode *children[2] = {};
};

void insert(TrieNode *root, int num) {
  TrieNode *cur = root;
  for(int i = 30; i >= 0; --i) {
    int bit = ((num >> i) & 1);
    if(!cur->children[bit]) {
      cur->children[bit] = new TrieNode();
    }
    cur = cur->children[bit];
  }
}

int getResult(TrieNode *cur1, TrieNode *cur2, int pos) {
  if(pos < 0 || !cur1 || !cur2) return 0;
  int result = 0;
  int result2 = 0;
  if(cur1->children[0] && cur2->children[1]) result = (1 << pos) + getResult(cur1->children[0], cur2->children[1], pos - 1);
  if(cur2->children[0] && cur1->children[1]) result = max(result, (1 << pos) + getResult(cur2->children[0], cur1->children[1], pos - 1));
  if(result) return result;
  if(cur1->children[0]) return getResult(cur1->children[0], cur2->children[0], pos - 1);
  return getResult(cur1->children[1], cur2->children[1], pos - 1);
}
class Solution {
public:
  int findMaximumXOR(vector<int>& nums) {
    TrieNode *root = new TrieNode();
    for(auto num : nums) {
      insert(root, num);
    }
    int answer = 0;
    int pos = 30;
    TrieNode *cur = root;
    while(pos >= 0) {
      if(!cur->children[0]) {
        cur = cur->children[1];
      } else if(!cur->children[1]) {
        cur = cur->children[0];
      } else {
        return (1 << pos) | getResult(cur->children[0], cur->children[1], pos - 1);
      }
      pos -= 1;
    }
    return answer;
  }
};

// Accepted
// 41/41 cases passed (295 ms)
// Your runtime beats 66.42 % of cpp submissions
// Your memory usage beats 95.74 % of cpp submissions (64.3 MB)
```

enumerate and get result

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
struct TrieNode {
  TrieNode *children[2] = {};
};

void insert(TrieNode *root, int num) {
  TrieNode *cur = root;
  for(int i = 30; i >= 0; --i) {
    int bit = ((num >> i) & 1);
    if(!cur->children[bit]) {
      cur->children[bit] = new TrieNode;
    }
    cur = cur->children[bit];
  }
}

int getResult(TrieNode *root, int num) {
  TrieNode *cur = root;
  int result = 0;
  for(int i = 30; i >= 0; --i) {
    result <<= 1;
    int bit = ((num >> i) & 1);
    if(!cur->children[!bit]) {
      cur = cur->children[bit];
    } else {
      result |= 1;
      cur = cur->children[!bit];
    }
  }
  return result;
}
class Solution {
public:
  int findMaximumXOR(vector<int>& nums) {
    TrieNode *root = new TrieNode();
    for(auto num : nums) {
      insert(root, num);
    }
    int answer = 0;
    for(auto num : nums) {
      answer = max(answer, getResult(root, num));
    }
    return answer;
  }
};

// Accepted
// 41/41 cases passed (180 ms)
// Your runtime beats 96.49 % of cpp submissions
// Your memory usage beats 62.99 % of cpp submissions (65.3 MB)
```
