+++
title = "2021-05-08 Daily-Challenge"
path = "2021-05-08-Daily-Challenge"
date = 2021-05-08 16:39:47+08:00
updated = 2021-05-08 21:25:21+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [May LeetCoding Challenge](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/599/week-2-may-8th-may-14th/3736/) with `cpp`.

<!-- more -->

# LeetCode Review

## Reverse Words in a String III

too easy to review

## Jump Game VI

too easy to review

## Set Intersection Size At Least Two

once you know, it's not hard

## Find N Unique Integers Sum up to Zero

too easy to review

## Course Schedule

too easy to review

## Running Sum of 1d Array

too easy to review

## Non-decreasing Array

too easy to review

## Jump Game II

too easy to review

## Convert Sorted List to Binary Search Tree

too easy to review

## Delete Operation for Two Strings

too easy to review

# May LeetCoding Challenge 8

## Description

**Super Palindromes**

Let's say a positive integer is a **super-palindrome** if it is a palindrome, and it is also the square of a palindrome.

Given two positive integers `left` and `right` represented as strings, return *the number of **super-palindromes** integers in the inclusive range* `[left, right]`.

 

**Example 1:**

```
Input: left = "4", right = "1000"
Output: 4
Explanation: 4, 9, 121, and 484 are superpalindromes.
Note that 676 is not a superpalindrome: 26 * 26 = 676, but 26 is not a palindrome.
```

**Example 2:**

```
Input: left = "1", right = "2"
Output: 1
```

 

**Constraints:**

- `1 <= left.length, right.length <= 18`
- `left` and `right` consist of only digits.
- `left` and `right` cannot have leading zeros.
- `left` and `right` represent integers in the range `[1, 10^18]`.
- `left` is less than or equal to `right`.

## Solution

digit DP I guess

use `dp[digits length]` represent state of DP, states that with digits length `i`, there will be `dp[i]` super palindrome numbers. $dp[i] = 9 \times (dp[i - 2]+dp[i-4] +...+dp[i\%2])$

Oops, I misunderstood problem again, it's **super palindrome numbers** not palindrome numbers. amount of these numbers is small, so I write a program to count them and print into my code.

below is my solution

``` cpp
class Solution {
  vector<long long> table = {0, 1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 400080004, 404090404, 10000200001, 10221412201, 12102420121, 12345654321, 40000800004, 1000002000001, 1002003002001, 1004006004001, 1020304030201, 1022325232201, 1024348434201, 1210024200121, 1212225222121, 1214428244121, 1232346432321, 1234567654321, 4000008000004, 4004009004004, 100000020000001, 100220141022001, 102012040210201, 102234363432201, 121000242000121, 121242363242121, 123212464212321, 123456787654321, 400000080000004, 10000000200000001, 10002000300020001, 10004000600040001, 10020210401202001, 10022212521222001, 10024214841242001, 10201020402010201, 10203040504030201, 10205060806050201, 10221432623412201, 10223454745432201, 12100002420000121, 12102202520220121, 12104402820440121, 12122232623222121, 12124434743442121, 12321024642012321, 12323244744232321, 12343456865434321, 12345678987654321, 40000000800000004, 40004000900040004};
public:
  int superpalindromesInRange(string left, string right) {
    auto l = stoll(left);
    auto r = stoll(right);
    return lower_bound(table.begin(), table.end(), r + 1) - lower_bound(table.begin(), table.end(), l);
  }
};
```

and below is my program

``` cpp
#include<bits/stdc++.h>

#define LL long long
#define mk(a,b) make_pair(a,b)
#define ULL unsigned long long
#define mem(a,n) memset(a,n,sizeof(a))
#define lowbit(x) ((x)&(-x))
#define sz 1010
#define INF 0x3f3f3f3f
#define MOD 10000007
#define eps 1e-10

using namespace std;
vector<vector<string>> dp = {{""}};
void init() {
	dp.resize(10);
	for(int i = 0; i < 10; ++i) dp[1].push_back(to_string(i));
	for(int i = 2; i < 10; i++) {
		for(int j = i & 1; j < i; j += 2) {
		    for(int k = 1; k < 10; ++k) {
		    	for(auto &tmp : dp[j]) {
			    	string res = to_string(k);
			    	for(int z = 0; z * 2 + tmp.length() < i - 2; ++z) res.push_back('0');
			    	res += tmp;
			    	for(int z = 0; z * 2 + tmp.length() < i - 2; ++z) res.push_back('0');
			    	res.push_back(k + '0');
			    	dp[i].push_back(res);
		    	}
			}
		}
	}
}
bool isPal(unsigned long long i) {
	string a = to_string(i);
	auto it = a.begin();
	auto rit = a.rbegin();
	while(it != a.end()) {
		if(*it != *rit) return false;
		++it;
		++rit;
	}
	return true;
}
int main()
{
	init();
	vector<long long> answer;
	for(int i = 1; i < 10; ++i ) {
		for(auto &tmp : dp[i]) {
//			cout << tmp << ' ';
			auto i = stoll(tmp);
			i *= i;
			if(isPal(i)) answer.push_back(i);	
		}
//		cout << endl << "########################"<< endl;
	}
	sort(answer.begin(), answer.end()); // !important
	for(auto i : answer) cout << i << ", ";
	return 0;
}

```
