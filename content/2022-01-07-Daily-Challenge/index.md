+++
title = "2022-01-07 Daily-Challenge"
path = "2022-01-07-Daily-Challenge"
date = 2022-01-07 18:23:00+08:00
updated = 2022-01-07 18:25:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/linked-list-random-node/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 7

## Description

**Linked List Random Node**

Given a singly linked list, return a random node's value from the linked list. Each node must have the **same probability** of being chosen.

Implement the `Solution` class:

- `Solution(ListNode head)` Initializes the object with the integer array nums.
- `int getRandom()` Chooses a node randomly from the list and returns its value. All the nodes of the list should be equally likely to be choosen.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/03/16/getrand-linked-list.jpg)

```
Input
["Solution", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom"]
[[[1, 2, 3]], [], [], [], [], []]
Output
[null, 1, 3, 2, 2, 3]

Explanation
Solution solution = new Solution([1, 2, 3]);
solution.getRandom(); // return 1
solution.getRandom(); // return 3
solution.getRandom(); // return 2
solution.getRandom(); // return 2
solution.getRandom(); // return 3
// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
```

 

<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the linked list will be in the range <code>[1, 10<sup>4</sup>]</code>.</li>
	<li><code>-10<sup>4</sup> &lt;= Node.val &lt;= 10<sup>4</sup></code></li>
	<li>At most <code>10<sup>4</sup></code> calls will be made to <code>getRandom</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong></p>

<ul>
	<li>What if the linked list is extremely large and its length is unknown to you?</li>
	<li>Could you solve this efficiently without using extra space?</li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
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

// Accepted
// 8/8 cases passed (58 ms)
// Your runtime beats 5.11 % of cpp submissions
// Your memory usage beats 21.97 % of cpp submissions (16.9 MB)
```
