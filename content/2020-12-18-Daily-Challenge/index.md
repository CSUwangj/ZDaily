+++
title = "2020-12-18 Daily-Challenge"
path = "2020-12-18-Daily-Challenge"
date = 2020-12-18 18:00:42+08:00
updated = 2020-12-18 18:36:27+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/) and [Transpose File](https://leetcode.com/problems/transpose-file/) on leetcode and leetcode's [December LeetCoding Challenge](https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/571/week-3-december-15th-december-21st/3570/) with `cpp`.

<!-- more -->

# Letter Combinations of a Phone Number

## Description

Given a string containing digits from `2-9` inclusive, return all possible letter combinations that the number could represent. Return the answer in **any order**.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

![img](https://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png)

 

**Example 1:**

```
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
```

**Example 2:**

```
Input: digits = ""
Output: []
```

**Example 3:**

```
Input: digits = "2"
Output: ["a","b","c"]
```

**Constraints:**

- `0 <= digits.length <= 4`
- `digits[i]` is a digit in the range `['2', '9']`.

## Solution

nothing to say.

``` cpp
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return vector<string>();
        vector<string> mp = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> nxt;
        vector<string> current{""};
        for(auto c : digits) {
            for(auto &s : current) {
                for(auto letter : mp[c-'2']) {
                    nxt.push_back(s+letter);
                }
            }
            current = nxt;
            nxt.clear();
        }
        return current;
    }
};
```

# Transpose File

## Description

Given a text file `file.txt`, transpose its content.

You may assume that each row has the same number of columns and each field is separated by the `' '` character.

**Example:**

If `file.txt` has the following content:

```
name age
alice 21
ryan 30
```

Output the following:

```
name alice ryan
age 21 30
```

## Solution

`awk` solution

``` bash
# Read from the file file.txt and print its transposed content to stdout.
awk '
{ 
    for (i=1; i<=NF; i++)  {
        a[NR,i] = $i
    }
}
NF>p { p = NF }
END {    
    for(j=1; j<=p; j++) {
        str=a[1,j]
        for(i=2; i<=NR; i++){
            str=str" "a[i,j];
        }
        print str
    }
}' file.txt
```

# December LeetCoding Challenge 18

## Description

**Increasing Triplet Subsequence**

Given an integer array `nums`, return `true` *if there exists a triple of indices* `(i, j, k)` *such that* `i < j < k` *and* `nums[i] < nums[j] < nums[k]`. If no such indices exists, return `false`.

**Example 1:**

```
Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.
```

**Example 2:**

```
Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.
```

**Example 3:**

```
Input: nums = [2,1,5,0,4,6]
Output: true
Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.
```

**Constraints:**

- `1 <= nums.length <= 105`
- `-231 <= nums[i] <= 231 - 1`

**Follow up:** Could you implement a solution that runs in `O(n)` time complexity and `O(1)` space complexity?

## Solution

could be more percise.

``` cpp
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        bool hasMin = false, hasMiddle = false;
        int min, middle;
        for(auto i : nums) {
            if(!hasMin) {
                min = i;
                hasMin = true;
                continue;
            }
            if(i < min) {
                min = i;
            } else if(!hasMiddle && i > min) {
                middle = i;
                hasMiddle = true;
            } else if(hasMiddle && i > min && i < middle) {
                middle = i;
            }
            if(hasMiddle && i > middle) return true;
        }
        return false;
    }
};
```