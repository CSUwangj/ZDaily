+++
updated = 2022-05-08 18:21:00+08:00
title = "2022-05-08 Daily-Challenge"
path = "2022-05-08-Daily-Challenge"
date = 2022-05-08 18:19:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/flatten-nested-list-iterator/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 8

## Description

**Flatten Nested List Iterator**

You are given a nested list of integers `nestedList`. Each element is either an integer or a list whose elements may also be  integers or other lists. Implement an iterator to flatten it.

Implement the `NestedIterator` class:

- `NestedIterator(List<NestedInteger> nestedList)` Initializes the iterator with the nested list `nestedList`.
- `int next()` Returns the next integer in the nested list.
- `boolean hasNext()` Returns `true` if there are still some integers in the nested list and `false` otherwise.

Your code will be tested with the following pseudocode:

```
initialize iterator with nestedList
res = []
while iterator.hasNext()
    append iterator.next() to the end of res
return res
```

If `res` matches the expected flattened list, then your code will be judged as correct.

 

**Example 1:**

```
Input: nestedList = [[1,1],2,[1,1]]
Output: [1,1,2,1,1]
Explanation: By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].
```

**Example 2:**

```
Input: nestedList = [1,[4,[6]]]
Output: [1,4,6]
Explanation: By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].
```

 

**Constraints:**

- `1 <= nestedList.length <= 500`
- The values of the integers in the nested list is in the range `[-10^6, 10^6]`.

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  bool find132pattern(vector<int>& nums) {
    if(nums.size() < 3) return false;
    stack<int> three;
    int two = INT_MIN;
    three.push(nums.back());
    for(int i = nums.size()-1; i >=0 ; --i) {
      if(nums[i] < two) return true;
      while(three.size() && three.top() < nums[i]) {
        two = three.top();
        three.pop();
      }
      three.push(nums[i]);
    }
    return false;
  }
};

// Accepted
// 102/102 cases passed (60 ms)
// Your runtime beats 99.08 % of cpp submissions
// Your memory usage beats 98.98 % of cpp submissions (37.4 MB)
```
