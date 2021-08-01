+++
title = "2021-03-31 Daily-Challenge"
path = "2021-03-31-Daily-Challenge"
date = 2021-03-31 01:45:24+08:00
updated = 2021-03-31 20:54:09+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Coin Change 2](https://leetcode.com/problems/coin-change-2/) and leetcode's [March LeetCoding Challenge](https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/592/week-5-march-29th-march-31st/3691/) with `cpp`.

<!-- more -->

# Coin Change 2

## Description

You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.



 

**Example 1:**

```
Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
```

**Example 2:**

```
Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
```

**Example 3:**

```
Input: amount = 10, coins = [10] 
Output: 1
```

 

**Note:**

You can assume that

- 0 <= amount <= 5000
- 1 <= coin <= 5000
- the number of coins is less than 500
- the answer is guaranteed to fit into signed 32-bit integer

## Solution

``` cpp
class Solution {
public:
  int change(int amount, vector<int>& coins) {
    int dp[amount + 1];
    for(int i = 0; i <= amount; ++i) dp[i] = 0;
    dp[0] = 1;
    for(auto c : coins) {
      for(int i = c; i <= amount; ++i) {
        dp[i] += dp[i - c];
      }
    }
    return dp[amount];
  }
};


```

# March LeetCoding challenge 31

## Description

**Stamping The Sequence**

You want to form a `target` string of **lowercase letters**.

At the beginning, your sequence is `target.length` `'?'` marks. You also have a `stamp` of lowercase letters.

On each turn, you may place the stamp over the sequence, and replace every letter in the sequence with the corresponding letter from the stamp. You can make up to `10 * target.length` turns.

For example, if the initial sequence is "?????", and your stamp is `"abc"`, then you may make "abc??", "?abc?", "??abc" in the first turn. (Note that the stamp must be fully contained in the boundaries of the sequence in order to stamp.)

If the sequence is possible to stamp, then return an array of the index of the left-most letter being stamped at each turn. If the sequence is not possible to stamp, return an empty array.

For example, if the sequence is "ababc", and the stamp is `"abc"`, then we could return the answer `[0, 2]`, corresponding to the moves "?????" -> "abc??" -> "ababc".

Also, if the sequence is possible to stamp, it is guaranteed it is possible to stamp within `10 * target.length` moves. Any answers specifying more than this number of moves will not be accepted.

 

**Example 1:**

```
Input: stamp = "abc", target = "ababc"
Output: [0,2]
([1,0,2] would also be accepted as an answer, as well as some other answers.)
```

**Example 2:**

```
Input: stamp = "abca", target = "aabcaca"
Output: [3,0,1]
```

 

**Note:**

1. `1 <= stamp.length <= target.length <= 1000`
2. `stamp` and `target` only contain lowercase letters.

## Solution

I come up with work backward solution, but fail to write a elegant solution. At least I've done it myself!

it's a struggle debugging this

``` cpp
template<typename T>
std::ostream& operator<<(std::ostream &out, const std::vector<T> &v) {
  if(v.size() == 0) {
    out << "[]" << std::endl;
    return out;
  }
  out << '[' << v[0];
  for(int i = 1; i < v.size(); ++i) {
    out << ", " << v[i];
  }
  out << ']' << std::endl;
  return out;
}

class Solution {
  int sLen;
  int tLen;
  int rightMost = -1;
  
  int findStart(string &s, string &t) {
    for(int i = rightMost + 1; i <= tLen - sLen; ++i) {
      bool eq = true;
      for(int j = 0; j < sLen; ++j) eq &= t[i + j] == s[j];
      if(eq) return i;
    }
    return -1;
  }
  
  void findLeft(int start, string &s, string &t, vector<int> &answer) {
    while(start > rightMost + 1) {
      int find = 0;
      for(int i = 1; i < sLen && start - i > rightMost; ++i) {
        bool ok = true;
        for(int j = 0; start - i + j < start; ++j) {
          ok &= t[start - i + j] == s[j];
        }
        // cout << start << ' ' << i << ' ' << ok << endl;
        if(ok) find = i;
      }
      if(!find) return;
      start -= find;
      
      // cout << "[left]: push " << start << endl;
      answer.push_back(start);
    }
    // cout << "[left] true" << endl;
    return;
  }
  
  void findRight(int start, string &s, string &t, vector<int> &answer) {
    while(start < tLen - sLen) {
      int find = 0;
      for(int i = 1; i < sLen && start + i + sLen <= tLen; ++i) {
        bool ok = true;
        for(int j = 1; start + i - j >= start; ++j) {
          ok &= t[start + i - j + sLen] == s[sLen - j];
        }
        if(ok) find = i;
      }
      if(!find) return;
      start += find;
      rightMost = start + sLen - 1;
      // cout << "[right]: push " << start << endl;
      answer.push_back(start);
    }
    // cout << "[right] true" << endl;
    return;
  }
  
  void findEdge(string &stamp, string &helper, string &target,vector<int> &answer) {
    if(sLen < 3) return;
    for(int i = 0; i <= tLen - sLen; ++i) {
      bool ok = true;
      bool need = false;
      for(int j = 0; j < sLen; ++j) {
        if(helper[i + j] == '?') need = true;
        if(helper[i + j] == '?') ok &= target[i + j] == stamp[j];
      }
      if(need && ok) answer.push_back(i);
    }
  }
  
  void apply(string &stamp, string &helper, int pos) {
    for(int i = 0; i < sLen; ++i) {
      helper[pos + i] = stamp[i];
    }
  }
public:
  vector<int> movesToStamp(string stamp, string target) {
    sLen = stamp.length();
    tLen = target.length();
    string helper(tLen, '?');
    vector<int> answer;
    
    int start = -1;
    while(rightMost < tLen - sLen) {
      int prevStart = start;
      start = findStart(stamp, target);
      // cout << "[start]: " << start << endl;
      // cout << "[right most]: " << rightMost << endl;
      if(start == -1) break;
      answer.push_back(start);
      
      findLeft(start, stamp, target, answer);
      findRight(start, stamp, target, answer);
      rightMost = max(rightMost, start + sLen - 1);
    }
    
    for(auto it = answer.rbegin(); it != answer.rend(); ++it) {
      apply(stamp, helper, *it);
    }
    // cout << answer << endl;
    // cout << "[result]: " << helper << endl;
    // cout << "[expect]: " << target << endl;
    findEdge(stamp, helper, target, answer);
    for(auto it = answer.rbegin(); it != answer.rend(); ++it) {
      apply(stamp, helper, *it);
    }
    // cout << answer << endl;
    // cout << "[result]: " << helper << endl;
    // cout << "[expect]: " << target << endl;
    if(helper != target) return {};
    reverse(answer.begin(), answer.end());
    return answer;
  }
};
```
