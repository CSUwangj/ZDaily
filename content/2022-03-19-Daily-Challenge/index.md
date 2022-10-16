+++
updated = 2022-03-19 14:50:00+08:00
title = "2022-03-19 Daily-Challenge"
path = "2022-03-19-Daily-Challenge"
date = 2022-03-19 14:30:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/maximum-frequency-stack/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 19

## Description

**Maximum Frequency Stack**

Design a stack-like data structure to push elements to the stack and pop the most frequent element from the stack.

Implement the `FreqStack` class:

- `FreqStack()` constructs an empty frequency stack.

- `void push(int val)` pushes an integer `val` onto the top of the stack.

- ```
  int pop()
  ```

   removes and returns the most frequent element in the stack. 

  - If there is a tie for the most frequent element, the element closest to the stack's top is removed and returned.

 

**Example 1:**

```
Input
["FreqStack", "push", "push", "push", "push", "push", "push", "pop", "pop", "pop", "pop"]
[[], [5], [7], [5], [7], [4], [5], [], [], [], []]
Output
[null, null, null, null, null, null, null, 5, 7, 5, 4]

Explanation
FreqStack freqStack = new FreqStack();
freqStack.push(5); // The stack is [5]
freqStack.push(7); // The stack is [5,7]
freqStack.push(5); // The stack is [5,7,5]
freqStack.push(7); // The stack is [5,7,5,7]
freqStack.push(4); // The stack is [5,7,5,7,4]
freqStack.push(5); // The stack is [5,7,5,7,4,5]
freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,5,7,4].
freqStack.pop();   // return 7, as 5 and 7 is the most frequent, but 7 is closest to the top. The stack becomes [5,7,5,4].
freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,4].
freqStack.pop();   // return 4, as 4, 5 and 7 is the most frequent, but 4 is closest to the top. The stack becomes [5,7].
```

 

**Constraints:**

- `0 <= val <= 10^9`
- At most `2 * 10^4` calls will be made to `push` and `pop`.
- It is guaranteed that there will be at least one element in the stack before calling `pop`.

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class FreqStack {
  vector<vector<int>> stack;
  unordered_map<int, int> count;
  int maxCount;
public:
  FreqStack(): maxCount(0) {}
  
  void push(int val) {
    if(maxCount == count[val]) {
      stack.push_back({});
    }
    stack[count[val]].push_back(val);
    count[val] += 1;
    maxCount = max(maxCount, count[val]);
  }
  
  int pop() {
    int val = stack.back().back();
    count[val] -= 1;
    stack.back().pop_back();
    if(stack.back().empty()) {
      stack.pop_back();
      maxCount -= 1;
    }
    return val;
  }
};

// Accepted
// 37/37 cases passed (196 ms)
// Your runtime beats 82.29 % of cpp submissions
// Your memory usage beats 82.96 % of cpp submissions (79.9 MB)
```
