+++
title = "2021-04-05 Daily-Challenge"
path = "2021-04-05-Daily-Challenge"
date = 2021-04-05 17:00:00+08:00
updated = 2021-04-05 21:08:33+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Number of Students Unable to Eat Lunch](https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/) and leetcode's [April LeetCoding Challenge](https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/593/week-1-april-1st-april-7th/3697) with `cpp`.

<!-- more -->

# Number of Students Unable to Eat Lunch

## Description

The school cafeteria offers circular and square sandwiches at lunch break, referred to by numbers `0` and `1` respectively. All students stand in a queue. Each student either prefers square or circular sandwiches.

The number of sandwiches in the cafeteria is equal to the number of students. The sandwiches are placed in a **stack**. At each step:

- If the student at the front of the queue **prefers** the sandwich on the top of the stack, they will **take it** and leave the queue.
- Otherwise, they will **leave it** and go to the queue's end.

This continues until none of the queue students want to take the top sandwich and are thus unable to eat.

You are given two integer arrays `students` and `sandwiches` where `sandwiches[i]` is the type of the `ith` sandwich in the stack (`i = 0` is the top of the stack) and `students[j]` is the preference of the `jth` student in the initial queue (`j = 0` is the front of the queue). Return *the number of students that are unable to eat.*

 

**Example 1:**

```
Input: students = [1,1,0,0], sandwiches = [0,1,0,1]
Output: 0 
Explanation:
- Front student leaves the top sandwich and returns to the end of the line making students = [1,0,0,1].
- Front student leaves the top sandwich and returns to the end of the line making students = [0,0,1,1].
- Front student takes the top sandwich and leaves the line making students = [0,1,1] and sandwiches = [1,0,1].
- Front student leaves the top sandwich and returns to the end of the line making students = [1,1,0].
- Front student takes the top sandwich and leaves the line making students = [1,0] and sandwiches = [0,1].
- Front student leaves the top sandwich and returns to the end of the line making students = [0,1].
- Front student takes the top sandwich and leaves the line making students = [1] and sandwiches = [1].
- Front student takes the top sandwich and leaves the line making students = [] and sandwiches = [].
Hence all students are able to eat.
```

**Example 2:**

```
Input: students = [1,1,1,0,0,1], sandwiches = [1,0,0,0,1,1]
Output: 3
```

 

**Constraints:**

- `1 <= students.length, sandwiches.length <= 100`
- `students.length == sandwiches.length`
- `sandwiches[i]` is `0` or `1`.
- `students[i]` is `0` or `1`.

## Solution

``` cpp
class Solution {
public:
  int countStudents(vector<int>& students, vector<int>& sandwiches) {
    int len = students.size();
    vector<bool> eat(len);
    int pos = 0;
    while(pos < len) {
      bool found = false;
      for(int i = 0; i < len; ++i) {
        if(eat[i]) continue;
        if(students[i] == sandwiches[pos]) {
          eat[i] = true;
          pos += 1;
          found = true;
        }
      }
      if(!found) break;
    }
    return len - pos;
  }
};
```

# April LeetCoding challenge5

**Global and Local Inversions**

We have some permutation `A` of `[0, 1, ..., N - 1]`, where `N` is the length of `A`.

The number of (global) inversions is the number of `i < j` with `0 <= i < j < N` and `A[i] > A[j]`.

The number of local inversions is the number of `i` with `0 <= i < N` and `A[i] > A[i+1]`.

Return `true` if and only if the number of global inversions is equal to the number of local inversions.

**Example 1:**

```
Input: A = [1,0,2]
Output: true
Explanation: There is 1 global inversion, and 1 local inversion.
```

**Example 2:**

```
Input: A = [1,2,0]
Output: false
Explanation: There are 2 global inversions, and 1 local inversion.
```

**Note:**

- `A` will be a permutation of `[0, 1, ..., A.length - 1]`.
- `A` will have length in range `[1, 5000]`.
- The time limit for this problem has been reduced.

## Solution

I first come up with a solution using Binary Indexed Tree

``` cpp
constexpr int lowbit(int x) {
  return x&(-x);
}

class Solution {
  int len;
  vector<int> BITS;
  int sum(int x) {
    int result = 0;
    while(x) {
      result += BITS[x];
      x -= lowbit(x);
    }
    return result;
  }
  void add(int x) {
    while(x <= len) {
      BITS[x] += 1;
      x += lowbit(x);
    }
  }
public:
  bool isIdealPermutation(vector<int>& A) {
    len = A.size();
    BITS.resize(len + 1);
    for(int i = 0; i < len - 1; ++i) {
      int n = A[i] + 1;
      if(sum(n) < n - 2 || (sum(n) == n - 2 && A[i + 1] + 1 != A[i])) return false;
      add(n);
    }
    if(sum(A.back() + 1) != A.back()) return false;
    return true;
  }
};

// 208 / 208 test cases passed.
// Status: Accepted
// Runtime: 60 ms
// Memory Usage: 37.2 MB
```

optimize it

``` cpp
constexpr int lowbit(int x) {
  return x&(-x);
}

class Solution {
  int len;
  int BITS[5002] = {0};
  int sum(int x) {
    int result = 0;
    while(x) {
      result += BITS[x];
      x -= lowbit(x);
    }
    return result;
  }
  void add(int x) {
    while(x <= len) {
      BITS[x] += 1;
      x += lowbit(x);
    }
  }
public:
  bool isIdealPermutation(vector<int>& A) {
    len = A.size();
    for(int i = 0; i < len - 1; ++i) {
      int n = A[i] + 1;
      if(sum(n) < n - 2 || (sum(n) == n - 2 && A[i + 1] + 1 != A[i])) return false;
      add(n);
    }
    if(sum(A.back() + 1) != A.back()) return false;
    return true;
  }
};


// 208 / 208 test cases passed.
// Status: Accepted
// Runtime: 52 ms
// Memory Usage: 35.6 MB
```

then I recgnize that number can only be valid at some positions.

``` cpp
class Solution {
public:
  bool isIdealPermutation(vector<int>& A) {
    int pos = 0;
    int len = A.size();
    while(pos < len) {
      if(A[pos] == pos) {
        pos += 1;
        continue;
      }
      if(pos < len - 1 && A[pos] == pos + 1 && A[pos + 1] == pos) {
        pos += 2;
        continue;
      }
      return false;
    }
    return true;
  }
};

// 208 / 208 test cases passed.
// Status: Accepted
// Runtime: 40 ms
// Memory Usage: 35.7 MB
```
