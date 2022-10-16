+++
updated = 2022-06-26 18:14:00+08:00
title = "2022-06-26 Daily-Challenge"
path = "2022-06-26-Daily-Challenge"
date = 2022-06-26 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 26

## Description

**Maximum Points You Can Obtain from Cards**

There are several cards **arranged in a row**, and each card has an associated number of points. The points are given in the integer array `cardPoints`.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly `k` cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array `cardPoints` and the integer `k`, return the *maximum score* you can obtain.

 

**Example 1:**

```
Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.
```

**Example 2:**

```
Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4.
```

**Example 3:**

```
Input: cardPoints = [9,7,7,9,7,7,9], k = 7
Output: 55
Explanation: You have to take all the cards. Your score is the sum of points of all cards.
```

 

**Constraints:**

- `1 <= cardPoints.length <= 10^5`
- `1 <= cardPoints[i] <= 10^4`
- `1 <= k <= cardPoints.length`

## Solution

``` cpp
class Solution {
public:
	int maxScore(vector<int>& cardPoints, int k) {
		int len = cardPoints.size();
		vector<int> sum(len + 1);
		vector<int> rsum(len + 1);
		for(int i = 0; i < len; ++i) {
			sum[i + 1] = cardPoints[i] + sum[i];
			rsum[i + 1] = cardPoints[len - 1 - i] + rsum[i];
		}
		int answer = 0;
		for(int i = 0; i <=k; ++i) {
			answer = max(answer, sum[i] + rsum[k - i]);
		}
		return answer;
	}
};

// Accepted
// 40/40 cases passed (110 ms)
// Your runtime beats 24.54 % of cpp submissions
// Your memory usage beats 8.03 % of cpp submissions (45.8 MB)
```
