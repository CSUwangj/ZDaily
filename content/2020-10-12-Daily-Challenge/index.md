+++
title = "2020-10-12 Daily-Challenge"
path = "2020-10-12-Daily-Challenge"
date = 2020-10-12 01:15:46+08:00
updated = 2020-10-12 21:31:52+08:00
in_search_index = true

[taxonomies]
tags = ["Design", "Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is an example of *The non-Designer's Design Book* on bottom of Page 71 and *Subsets* on [leetcode](https://leetcode.com/problems/subsets/) and leetcode's [October LeetCoding Challenge](https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/560/week-2-october-8th-october-14th/3492/) with `cpp`.

<!-- more -->

# The non-Designer's Design Book

my answer:

- [T] use black background and white text
- [T] use larger font size for the title
- [T] change font of `WHY READ ... OTHERS?` different from main text
- [T] use red for bottom dashed dotted line
- [F] website url as single line
- [F] use more bright red

# Subsets

## Description

Given a set of **distinct** integers, nums, return all possible subsets (the power set).

**Note:** The solution set must not contain duplicate subsets.

**Example:**

```
Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
```

## Solution

use number to visit all subset, no extra memory for recursion, but because of `vector::clear()` it dose have to do some extra work.

``` cpp
class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> answer;
    vector<int> tmp;
    int size = 1 << nums.size();
    for(int i = 0; i < size; ++i) {
      for(int index = 0; i >= (1<<index); ++index) {
        if(i & (1<<index)) tmp.push_back(nums[index]);
      }
      answer.push_back(tmp);
      tmp.clear();
    }
    return answer;
  }
};
```

# October LeetCoding Challenge12

## Description

**BuddyString**

Given two strings `A` and `B` of lowercase letters, return `true` *if you can swap two letters in* `A` *so the result is equal to* `B`*, otherwise, return* `false`*.*

Swapping letters is defined as taking two indices `i` and `j` (0-indexed) such that `i != j` and swapping the characters at `A[i]` and `A[j]`. For example, swapping at indices `0` and `2` in `"abcd"` results in `"cbad"`.

**Example 1:**

```
Input: A = "ab", B = "ba"
Output: true
Explanation: You can swap A[0] = 'a' and A[1] = 'b' to get "ba", which is equal to B.
```

**Example 2:**

```
Input: A = "ab", B = "ab"
Output: false
Explanation: The only letters you can swap are A[0] = 'a' and A[1] = 'b', which results in "ba" != B.
```

**Example 3:**

```
Input: A = "aa", B = "aa"
Output: true
Explanation: You can swap A[0] = 'a' and A[1] = 'a' to get "aa", which is equal to B.
```

**Example 4:**

```
Input: A = "aaaaaaabc", B = "aaaaaaacb"
Output: true
```

**Example 5:**

```
Input: A = "", B = "aa"
Output: false
```

**Constraints:**

- `0 <= A.length <= 20000`
- `0 <= B.length <= 20000`
- `A` and `B` consist of lowercase letters.

## Solution

brute solution

``` cpp
class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size() != B.size()) return false;
        int index = -1;
        map<char, int> cnt;
        for(int i = 0; i < A.size(); ++i) {
            cnt[A[i]] += 1;
            if(A[i] != B[i]) {
                if(index == -1) {
                    index = i;
                } else {
                    char tmp = A[i];
                    A[i] = A[index];
                    A[index] = tmp;
                    return A == B;
                }
            }
        }
        for(auto &kv : cnt) {
            if (kv.second > 1) {
                return index == -1;
            }
        }
        return false;
    }
};
```