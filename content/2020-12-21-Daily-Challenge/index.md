+++
title = "2020-12-21 Daily-Challenge"
path = "2020-12-21-Daily-Challenge"
date = 2020-12-21 18:00:42+08:00
updated = 2020-12-21 19:59:51+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Smallest Range I](https://leetcode.com/problems/smallest-range-i/) and [Shopping Offers](https://leetcode.com/problems/shopping-offers/) on leetcode and leetcode's [December LeetCoding Challenge](https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/571/week-3-december-15th-december-21st/3573/) with `cpp`.

<!-- more -->

# Shopping Offers

## Description

In LeetCode Store, there are some kinds of items to sell. Each item has a price.

However, there are some special offers, and a special offer consists of one or more different kinds of items with a sale price.

You are given the each item's price, a set of special offers, and the number we need to buy for each item. The job is to output the lowest price you have to pay for **exactly** certain items as given, where you could make optimal use of the special offers.

Each special offer is represented in the form of an array, the last number represents the price you need to pay for this special offer, other numbers represents how many specific items you could get if you buy this offer.

You could use any of special offers as many times as you want.

**Example 1:**

```
Input: [2,5], [[3,0,5],[1,2,10]], [3,2]
Output: 14
Explanation: 
There are two kinds of items, A and B. Their prices are $2 and $5 respectively. 
In special offer 1, you can pay $5 for 3A and 0B
In special offer 2, you can pay $10 for 1A and 2B. 
You need to buy 3A and 2B, so you may pay $10 for 1A and 2B (special offer #2), and $4 for 2A.
```

**Example 2:**

```
Input: [2,3,4], [[1,1,0,4],[2,2,1,9]], [1,2,1]
Output: 11
Explanation: 
The price of A is $2, and $3 for B, $4 for C. 
You may pay $4 for 1A and 1B, and $9 for 2A ,2B and 1C. 
You need to buy 1A ,2B and 1C, so you may pay $4 for 1A and 1B (special offer #1), and $3 for 1B, $4 for 1C. 
You cannot add more items, though only $9 for 2A ,2B and 1C.
```

**Note:**

1. There are at most 6 kinds of items, 100 special offers.
2. For each item, you need to buy at most 6 of them.
3. You are **not** allowed to buy more items than you want, even if that would lower the overall price.

## Solution

DFS

``` cpp
class Solution {
    int answer = INT_MAX;
    void plus(vector<int> &current, vector<int> &offer) {
        for(int i = 0; i < current.size(); ++i) {
            current[i] += offer[i];
        }
    }
    
    void minus(vector<int> &current, vector<int> &offer) {
        for(int i = 0; i < current.size(); ++i) {
            current[i] -= offer[i];
        }
    }
    
    bool sat(vector<int> &current, vector<int> &needs) {
        for(int i = 0; i < needs.size(); ++i) {
            if(current[i] > needs[i]) return false;
        }
        return true;
    }
    
    void dfs(vector<int> &price, vector<vector<int>> &special, vector<int> &needs, vector<int> &current) {
        int result = current.back();
        for(int i = 0; i < needs.size(); ++i) {
            result += (needs[i]-current[i])*price[i];
        }
        answer = min(answer, result);
        for(auto &offer : special) {
            plus(current, offer);
            if(sat(current, needs)) {
                dfs(price, special, needs, current);
            }
            minus(current, offer);
        }
    }
public:
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs) {
        vector<int> current(needs.size()+1);
        dfs(price, special, needs, current);
        return answer;
    }
};
```

# Smallest Range I

## Description

Given an array A of integers, for each integer A[i] we may choose any x with -K <= x <= K, and add x to A[i].

After this process, we have some array B.

Return the smallest possible difference between the maximum value of B and the minimum value of B.

 

Example 1:

Input: A = [1], K = 0
Output: 0
Explanation: B = [1]
Example 2:

Input: A = [0,10], K = 2
Output: 6
Explanation: B = [2,8]
Example 3:

Input: A = [1,3,6], K = 3
Output: 0
Explanation: B = [3,3,3] or B = [4,4,4]
 

Note:

1 <= A.length <= 10000
0 <= A[i] <= 10000
0 <= K <= 10000

## Solution

nothing to say

``` cpp
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int mmin = INT_MAX, mmax = INT_MIN;
        for(auto i : A) {
            mmin = min(i, mmin);
            mmax = max(i, mmax);
        }
        return max(0, mmax-mmin-2*K);
    }
};
```

# December LeetCoding Challenge21

**Smallest Range II**

## Description

Given an array `A` of integers, for each integer `A[i]` we need to choose **either `x = -K` or `x = K`**, and add `x` to `A[i] **(only once)**`.

After this process, we have some array `B`.

Return the smallest possible difference between the maximum value of `B` and the minimum value of `B`.

**Example 1:**

```
Input: A = [1], K = 0
Output: 0
Explanation: B = [1]
```

**Example 2:**

```
Input: A = [0,10], K = 2
Output: 6
Explanation: B = [2,8]
```

**Example 3:**

```
Input: A = [1,3,6], K = 3
Output: 3
Explanation: B = [4,6,3]
```

**Note:**

1. `1 <= A.length <= 10000`
2. `0 <= A[i] <= 10000`
3. `0 <= K <= 10000`

## Solution

need more time to think.

``` cpp
class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        int mmin = INT_MAX, mmax = INT_MIN;
        sort(A.begin(), A.end());
        int len = A.size();
        int answer = A.back()-A.front();
        for(int i = 0; i < len-1; ++i) {
            int high = max(A.back()-K, A[i]+K);
            int low = min(A.front()+K, A[i+1]-K);
            answer = min(high-low, answer);
        }
        return answer;
    }
};
```