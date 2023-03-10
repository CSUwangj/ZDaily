+++
updated = 2023-03-10T08:02:29+08:00
title = "2023-03-10 Daily Challenge"
path = "2023-03-10-Daily-Challenge"
date = 2023-03-10T08:02:29+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/linked-list-random-node/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 10

## Description

**Linked List Random Node**

<p>Given a singly linked list, return a random node&#39;s value from the linked list. Each node must have the <strong>same probability</strong> of being chosen.</p>

<p>Implement the <code>Solution</code> class:</p>

<ul>
	<li><code>Solution(ListNode head)</code> Initializes the object with the head of the singly-linked list <code>head</code>.</li>
	<li><code>int getRandom()</code> Chooses a node randomly from the list and returns its value. All the nodes of the list should be equally likely to be chosen.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/16/getrand-linked-list.jpg" style="width: 302px; height: 62px;" />
<pre>
<strong>Input</strong>
[&quot;Solution&quot;, &quot;getRandom&quot;, &quot;getRandom&quot;, &quot;getRandom&quot;, &quot;getRandom&quot;, &quot;getRandom&quot;]
[[[1, 2, 3]], [], [], [], [], []]
<strong>Output</strong>
[null, 1, 3, 2, 2, 3]

<strong>Explanation</strong>
Solution solution = new Solution([1, 2, 3]);
solution.getRandom(); // return 1
solution.getRandom(); // return 3
solution.getRandom(); // return 2
solution.getRandom(); // return 2
solution.getRandom(); // return 3
// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
</pre>

<p>&nbsp;</p>
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
// 8/8 cases passed (36 ms)
// Your runtime beats 7.46 % of cpp submissions
// Your memory usage beats 8.14 % of cpp submissions (16.9 MB)
```
