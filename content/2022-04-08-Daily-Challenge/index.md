+++
updated = 2022-04-08 19:17:00+08:00
title = "2022-04-08 Daily-Challenge"
path = "2022-04-08-Daily-Challenge"
date = 2022-04-08 19:19:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/kth-largest-element-in-a-stream/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 8

## Description

**Kth Largest Element in a Stream**

Design a class to find the `kth` largest element in a stream. Note that it is the `kth` largest element in the sorted order, not the `kth` distinct element.

Implement `KthLargest` class:

- `KthLargest(int k, int[] nums)` Initializes the object with the integer `k` and the stream of integers `nums`.
- `int add(int val)` Appends the integer `val` to the stream and returns the element representing the `kth` largest element in the stream.

 

**Example 1:**

```
Input
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
Output
[null, 4, 5, 5, 8, 8]

Explanation
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3);   // return 4
kthLargest.add(5);   // return 5
kthLargest.add(10);  // return 5
kthLargest.add(9);   // return 8
kthLargest.add(4);   // return 8
```

 

**Constraints:**

- `1 <= k <= 10^4`
- `0 <= nums.length <= 10^4`
- `-10^4 <= nums[i] <= 10^4`
- `-10^4 <= val <= 10^4`
- At most `10^4` calls will be made to `add`.
- It is guaranteed that there will be at least `k` elements in the array when you search for the `kth` element.

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class KthLargest {
  priority_queue<int, vector<int>, greater<int>> pq;
public:
  KthLargest(int k, vector<int>& nums) {
    int len = nums.size();
    for(int i = 0; i < len && i < k; ++i) {
      pq.push(nums[i]);
    }
    for(int i = k; i < len; ++i) {
      pq.push(nums[i]);
      pq.pop();
    }
    if(len < k) pq.push(INT_MIN);
  }
  
  int add(int val) {
    pq.push(val);
    pq.pop();
    return pq.top();
  }
};

// Accepted
// 10/10 cases passed (20 ms)
// Your runtime beats 99.9 % of cpp submissions
// Your memory usage beats 17.93 % of cpp submissions (19.9 MB)
```
