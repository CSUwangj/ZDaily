+++
title = "2021-04-13 Daily-Challenge"
path = "2021-04-13-Daily-Challenge"
date = 2021-04-13 18:55:45+08:00
updated = 2021-04-13 19:29:23+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Average Salary Excluding the Minimum and Maximum Salary](https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/) and leetcode's [April LeetCoding Challenge](https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/594/week-2-april-8th-april-14th/3706/) with `cpp`.

<!-- more -->

# Average Salary Excluding the Minimum and Maximum Salary

## Description

Given an array of **unique** integers `salary` where `salary[i]` is the salary of the employee `i`.

Return the average salary of employees excluding the minimum and maximum salary.

 

**Example 1:**

```
Input: salary = [4000,3000,1000,2000]
Output: 2500.00000
Explanation: Minimum salary and maximum salary are 1000 and 4000 respectively.
Average salary excluding minimum and maximum salary is (2000+3000)/2= 2500
```

**Example 2:**

```
Input: salary = [1000,2000,3000]
Output: 2000.00000
Explanation: Minimum salary and maximum salary are 1000 and 3000 respectively.
Average salary excluding minimum and maximum salary is (2000)/1= 2000
```

**Example 3:**

```
Input: salary = [6000,5000,4000,3000,2000,1000]
Output: 3500.00000
```

**Example 4:**

```
Input: salary = [8000,9000,2000,3000,6000,1000]
Output: 4750.00000
```

 

**Constraints:**

- `3 <= salary.length <= 100`
- `10^3 <= salary[i] <= 10^6`
- `salary[i]` is unique.
- Answers within `10^-5` of the actual value will be accepted as correct.

## Solution

``` cpp
class Solution {
public:
  double average(vector<int>& salary) {
    return (accumulate(salary.begin(), salary.end(), 0) - (*max_element(salary.begin(), salary.end())) - (*min_element(salary.begin(), salary.end()))) 
              * 1.0 
              / (salary.size() - 2);
  }
};
```

# April LeetCoding challenge 13

## Description

**Flatten Nested List Iterator**

You are given a nested list of integers `nestedList`. Each element is either an integer or a list whose elements may also be integers or other lists. Implement an iterator to flatten it.

Implement the `NestedIterator` class:

- `NestedIterator(List<NestedInteger> nestedList)` Initializes the iterator with the nested list `nestedList`.
- `int next()` Returns the next integer in the nested list.
- `boolean hasNext()` Returns `true` if there are still some integers in the nested list and `false` otherwise.

 

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
- The values of the integers in the nested list is in the range <code>[-10<sup>6</sup>, 10<sup>6</sup>]</code>.

## Solution

pre flatten, but not a iterator

``` cpp
class NestedIterator {
  vector<int> integers;
  vector<int>::iterator it;
  void solve(NestedInteger &nestedInt) {
    if(nestedInt.isInteger()) {
      integers.push_back(nestedInt.getInteger());
      return;
    }
    for(auto &l : nestedInt.getList()) {
      solve(l);
    }
  }
public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    for(auto &nestedInt : nestedList) solve(nestedInt);
    it = integers.begin();
  }

  int next() {
    // int result = *it;
    // ++it;
    return *it++;
  }

  bool hasNext() {
    return it != integers.end();
  }
};

// 43 / 43 test cases passed.
// Status: Accepted
// Runtime: 16 ms
// Memory Usage: 12.8 MB
```

then try to be iterator

``` cpp
using it = vector<NestedInteger>::iterator;
class NestedIterator {
  it cur;
  it curEnd;
  vector<pair<it, it>> st;
  bool findInteger() {
    if(cur == curEnd) return false;
    while(cur != curEnd && !(cur->isInteger())) {
      st.push_back(make_pair(cur, curEnd));
      curEnd = cur->getList().end();
      cur = cur->getList().begin();
    }
    return cur != curEnd;
  }
  bool goUp() {
    if(!st.size()) return false;
    while(st.size() && cur == curEnd) {
      curEnd = st.back().second;
      cur = st.back().first;
      st.pop_back();
      cur += 1;
    }
    return true;
  }
  void moveForward() {
    cur += 1;
  }
public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    // cout << "#########" << endl;
    cur = nestedList.begin();
    curEnd = nestedList.end();
    while(!findInteger()) {
      if(!goUp()) break;
    }
  }

  int next() {
    int result = cur->getInteger();
    // cout << "next" << ' ' << result << endl;
    moveForward();
    goUp();
    while(!findInteger()) {
      if(!goUp()) break;
    }
    return result;
  }

  bool hasNext() {
    // cout << "hasNext" << endl;
    return st.size() || cur != curEnd;
  }
};

// 43 / 43 test cases passed.
// Status: Accepted
// Runtime: 16 ms
// Memory Usage: 13 MB
```
