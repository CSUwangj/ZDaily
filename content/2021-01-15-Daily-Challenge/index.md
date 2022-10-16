+++
title = "2021-01-15 Daily-Challenge"
path = "2021-01-15-Daily-Challenge"
date = 2021-01-15 18:00:59+08:00
updated = 2021-01-15 22:06:49+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string/), [Spiral Matrix](https://leetcode.com/problems/spiral-matrix/) and leetcode's [January LeetCoding Challenge](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/581/week-3-january-15th-january-21st/3605/) with `cpp`.

<!-- more -->

# Reverse Words in a String

## Description

Given an input string `s`, reverse the order of the **words**.

A **word** is defined as a sequence of non-space characters. The **words** in `s` will be separated by at least one space.

Return *a string of the words in reverse order concatenated by a single space.*

**Note** that `s` may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

**Example 1:**

```
Input: s = "the sky is blue"
Output: "blue is sky the"
```

**Example 2:**

```
Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
```

**Example 3:**

```
Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
```

**Example 4:**

```
Input: s = "  Bob    Loves  Alice   "
Output: "Alice Loves Bob"
```

**Example 5:**

```
Input: s = "Alice does not even like bob"
Output: "bob like even not does Alice"
```

 

**Constraints:**

- `1 <= s.length <= 104`
- `s` contains English letters (upper-case and lower-case), digits, and spaces `' '`.
- There is **at least one** word in `s`.

 

**Follow up:**

- Could you solve it **in-place** with `O(1)` extra space?

## Solution

``` cpp
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        cout << s << endl;
        int len = s.length();
        
        int cnt = 1;
        int newPos = 0;
        for(int pos = 0; pos < len; ++pos) {
            if(s[pos] != ' ' || !cnt) {
                s[newPos] = s[pos];
                newPos += 1;
                if(s[pos] == ' ') cnt = 1;
                else cnt = 0;
            }
        }
        if(s[newPos-1] == ' ') newPos -= 1;
        s.resize(newPos);
        len = newPos;
        cout << s << endl;
        
        int begin = -1, end = -1;
        for(int pos = 0; pos < len; ++pos) {
            if(begin == -1 && s[pos] != ' ') begin = pos;
            if(s[pos] != ' ') end = pos;
            if(s[pos] == ' ') {
                reverse(s.begin()+begin, s.begin()+end+1);
                begin = -1;
                end = -1;
            }
        }
        if(begin != -1) reverse(s.begin()+begin, s.begin()+end+1);
        return move(s);
    }
};
```

# Spiral Matrix

## Description

Given an `m x n` `matrix`, return *all elements of the* `matrix` *in spiral order*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/11/13/spiral1.jpg)

```
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/11/13/spiral.jpg)

```
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
```

 

**Constraints:**

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 10`
- `-100 <= matrix[i][j] <= 100`

## Solution

``` cpp
class Solution {
    const int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<bool>> visit;
    int rows;
    int cols;
    bool check(int row, int col) {
        return row >= 0 && col >=0 && row < rows && col < cols && !visit[row][col];
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        rows = matrix.size();
        cols = matrix.front().size();
        int total = rows*cols;
        visit.resize(rows, vector<bool>(cols));
        
        vector<int> answer;
        int row = 0, col = 0, direction = 0; 
        while(answer.size() < total) {
            answer.push_back(matrix[row][col]);
            visit[row][col] = true;
            int turn = 0;
            while(turn < 4 && !check(row+moves[direction][0], col+moves[direction][1])) {
                direction += 1;
                direction %= 4;
                turn += 1;
            }
            row += moves[direction][0];
            col += moves[direction][1];
        }
        return move(answer);
    }
};
```

# January LeetCoding Challenge 15

## Description

**Get Maximum in Generated Array**

You are given an integer `n`. An array `nums` of length `n + 1` is generated in the following way:

- `nums[0] = 0`
- `nums[1] = 1`
- `nums[2 * i] = nums[i]` when `2 <= 2 * i <= n`
- `nums[2 * i + 1] = nums[i] + nums[i + 1]` when `2 <= 2 * i + 1 <= n`

Return *the **maximum** integer in the array* `nums`.

 

**Example 1:**

```
Input: n = 7
Output: 3
Explanation: According to the given rules:
  nums[0] = 0
  nums[1] = 1
  nums[(1 * 2) = 2] = nums[1] = 1
  nums[(1 * 2) + 1 = 3] = nums[1] + nums[2] = 1 + 1 = 2
  nums[(2 * 2) = 4] = nums[2] = 1
  nums[(2 * 2) + 1 = 5] = nums[2] + nums[3] = 1 + 2 = 3
  nums[(3 * 2) = 6] = nums[3] = 2
  nums[(3 * 2) + 1 = 7] = nums[3] + nums[4] = 2 + 1 = 3
Hence, nums = [0,1,1,2,1,3,2,3], and the maximum is 3.
```

**Example 2:**

```
Input: n = 2
Output: 1
Explanation: According to the given rules, the maximum between nums[0], nums[1], and nums[2] is 1.
```

**Example 3:**

```
Input: n = 3
Output: 2
Explanation: According to the given rules, the maximum between nums[0], nums[1], nums[2], and nums[3] is 2.
```

 

**Constraints:**

- `0 <= n <= 100`

## Solution

``` cpp
class Solution {
public:
    int getMaximumGenerated(int n) {
        if(!n) return n;
        vector<int> nums(n+1);
        nums[1] = 1;
        for(int i = 1; i*2-1 <= n; ++i) {
            nums[i+i-1] = nums[i] + nums[i-1];
            if(i*2 <= n) nums[i*2] = nums[i];
        }
        int answer = 0;
        for(auto i : nums) answer = max(answer, i);
        return answer;
    }
};
```
