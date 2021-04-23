+++
title = "2021-01-28 Daily-Challenge"
path = "2021-01-28-Daily-Challenge"
date = 2021-01-28 18:00:59+08:00
updated = 2021-01-28 22:58:24+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Jump Game V](https://leetcode.com/problems/jump-game-v/), [Find Longest Awesome Substring](https://leetcode.com/problems/find-longest-awesome-substring/), [Max Sum of Rectangle No Larger Than K](https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/) and leetcode's [January LeetCoding Challenge](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/582/week-4-january-22nd-january-28th/3619/) with `cpp`.

dp is so hard................................

but ICPC guy won't give up on it.

<!-- more -->

# Jump Game V

## Description

Given an array of integers `arr` and an integer `d`. In one step you can jump from index `i` to index:

- `i + x` where: `i + x < arr.length` and `0 < x <= d`.
- `i - x` where: `i - x >= 0` and `0 < x <= d`.

In addition, you can only jump from index `i` to index `j` if `arr[i] > arr[j]` and `arr[i] > arr[k]` for all indices `k` between `i` and `j` (More formally `min(i, j) < k < max(i, j)`).

You can choose any index of the array and start jumping. Return *the maximum number of indices* you can visit.

Notice that you can not jump outside of the array at any time.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/01/23/meta-chart.jpeg)

```
Input: arr = [6,4,14,6,8,13,9,7,10,6,12], d = 2
Output: 4
Explanation: You can start at index 10. You can jump 10 --> 8 --> 6 --> 7 as shown.
Note that if you start at index 6 you can only jump to index 7. You cannot jump to index 5 because 13 > 9. You cannot jump to index 4 because index 5 is between index 4 and 6 and 13 > 9.
Similarly You cannot jump from index 3 to index 2 or index 1.
```

**Example 2:**

```
Input: arr = [3,3,3,3,3], d = 3
Output: 1
Explanation: You can start at any index. You always cannot jump to any index.
```

**Example 3:**

```
Input: arr = [7,6,5,4,3,2,1], d = 1
Output: 7
Explanation: Start at index 0. You can visit all the indicies. 
```

**Example 4:**

```
Input: arr = [7,1,7,1,7,1], d = 2
Output: 2
```

**Example 5:**

```
Input: arr = [66], d = 1
Output: 1
```

 

**Constraints:**

- `1 <= arr.length <= 1000`
- `1 <= arr[i] <= 10^5`
- `1 <= d <= arr.length`

## Solution

DAG then get max depth

``` cpp
class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int len = arr.size();
        vector<int> degree(len), jump(len);
        vector<vector<int>> edge(len);
        for(int i = 0; i < len; ++i) {
            for(int j = 1; j <= d && (i-j) >= 0 && arr[i-j] < arr[i]; ++j) {
                edge[i].push_back(i-j);
                degree[i-j] += 1;
            }
        }
        for(int i = 0; i < len; ++i) {
            for(int j = 1; j <= d && (i+j) < len && arr[i+j] < arr[i]; ++j) {
                edge[i].push_back(i+j);
                degree[i+j] += 1;
            }
        }
        queue<int> q;
        for(int i = 0; i < len; ++i) {
            if(degree[i] == 0) q.push(i);
        }
        while(!q.empty()) {
            int current = q.front();
            q.pop();
            for(auto i : edge[current]) {
                degree[i] -= 1;
                jump[i] = max(jump[i], jump[current] + 1);
                if(degree[i] == 0) q.push(i);
            }
        }

        return *max_element(jump.begin(), jump.end())+1;
    }
};
```

# Find Longest Awesome Substring

## Description

Given a string `s`. An *awesome* substring is a non-empty substring of `s` such that we can make any number of swaps in order to make it palindrome.

Return the length of the maximum length **awesome substring** of `s`.

 

**Example 1:**

```
Input: s = "3242415"
Output: 5
Explanation: "24241" is the longest awesome substring, we can form the palindrome "24142" with some swaps.
```

**Example 2:**

```
Input: s = "12345678"
Output: 1
```

**Example 3:**

```
Input: s = "213123"
Output: 6
Explanation: "213123" is the longest awesome substring, we can form the palindrome "231132" with some swaps.
```

**Example 4:**

```
Input: s = "00"
Output: 2
```

 

**Constraints:**

- `1 <= s.length <= 10^5`
- `s` consists only of digits.

## Solution

digits dp

``` cpp
class Solution {
public:
    int longestAwesome(string s) {
        vector<int> pos(1024, 100100);
        int len = s.length();
        int current = 0;
        int answer = 1;
        pos[0] = -1;
        for(int i = 0; i < len; ++i) {
            current ^= (1 << (s[i]-'0'));
            pos[current] = min(pos[current], i);
            answer = max(answer, i-pos[current]);
            for(int j = 0; j < 10; ++j) {
                answer = max(answer, i-pos[current^(1<<j)]);
            }
            // cout << i << ' ' << answer << endl;
        }
        return answer;
    }
};
```

# Max Sum of Rectangle No Larger Than K

## Description

Given a non-empty 2D matrix *matrix* and an integer *k*, find the max sum of a rectangle in the *matrix* such that its sum is no larger than *k*.

**Example:**

```
Input: matrix = [[1,0,1],[0,-2,3]], k = 2
Output: 2 
Explanation: Because the sum of rectangle [[0, 1], [-2, 3]] is 2,
             and 2 is the max number no larger than k (k = 2).
```

**Note:**

1. The rectangle inside the matrix must have an area > 0.
2. What if the number of rows is much larger than the number of columns?

## Solution

prefix sum with binary search

``` cpp
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int kk) {
        int rows = matrix.size();
        int cols = matrix.front().size();
        vector<vector<int>> prefix(rows+1, vector<int>(cols+1));

        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                prefix[i+1][j+1] = matrix[i][j] + prefix[i+1][j] + prefix[i][j+1] - prefix[i][j];
            }
        }

        auto sumRange = [&](int left, int right, int up, int down) {
            return prefix[down][right] - prefix[up][right] - prefix[down][left] + prefix[up][left];
        };

        int answer = INT_MIN;
        for(int i = 0; i < cols; ++i) {
            for(int j = i+1; j <= cols; ++j) {
                vector<int> arr = {0};
                for(int k = 1; k <= rows; ++k) {
                    int s = sumRange(i, j, 0, k);
                    auto it = lower_bound(arr.begin(), arr.end(), s-kk);
                    if(it != arr.end()) {
                        answer = max(answer, s-*it);
                    }
                    arr.insert(lower_bound(arr.begin(), arr.end(), s), s);
                }
            }
        }
        return answer;
    }
};
```

# January LeetCoding Challenge28

## Description

**Smallest String With A Given Numeric Value**

## Description

The **numeric value** of a **lowercase character** is defined as its position `(1-indexed)` in the alphabet, so the numeric value of `a` is `1`, the numeric value of `b` is `2`, the numeric value of `c` is `3`, and so on.

The **numeric value** of a **string** consisting of lowercase characters is defined as the sum of its characters' numeric values. For example, the numeric value of the string `"abe"` is equal to `1 + 2 + 5 = 8`.

You are given two integers `n` and `k`. Return *the **lexicographically smallest string** with **length** equal to `n` and **numeric value** equal to `k`.*

Note that a string `x` is lexicographically smaller than string `y` if `x` comes before `y` in dictionary order, that is, either `x` is a prefix of `y`, or if `i` is the first position such that `x[i] != y[i]`, then `x[i]` comes before `y[i]` in alphabetic order.

 

**Example 1:**

```
Input: n = 3, k = 27
Output: "aay"
Explanation: The numeric value of the string is 1 + 1 + 25 = 27, and it is the smallest string with such a value and length equal to 3.
```

**Example 2:**

```
Input: n = 5, k = 73
Output: "aaszz"
```

 

**Constraints:**

- $1 \le  n \le 10^5$
- `n <= k <= 26 * n`

## Solution

``` cpp
class Solution {
public:
    string getSmallestString(int n, int k) {
        int zs = max(ceil((k - n) / 25.0) - 1, 0.0);
        k -= zs * 26;
        n -= zs;
        return string(n-1, 'a') + string(1, 'a'+ k - n) + string(zs, 'z');
    }
};
```
