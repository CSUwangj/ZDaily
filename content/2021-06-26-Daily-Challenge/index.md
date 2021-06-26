+++
title = "2021-06-26 Daily-Challenge"
path = "2021-06-26-Daily-Challenge"
date = 2021-06-26 02:23:57+08:00
updated = 2021-06-26 17:19:51+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [June LeetCoding Challenge](https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/606/week-4-june-22nd-june-28th/3792/) with `cpp`.

<!-- more -->

# LeetCode Review

## Pascal's Triangle

too easy to review

## Number of Matching Subsequences

``` cpp
class Solution {
  vector<const char*> curChar[128];
public:
  int numMatchingSubseq(string s, vector<string>& words) {
    for(auto &word : words) {
      curChar[word.front()].push_back(word.c_str());
    }
    vector<const char*> empty;
    for(auto c : s) {
      swap(empty, curChar[c]);
      for(auto cstr : empty) {
        curChar[*++cstr].push_back(cstr);
      }
      empty.clear();
    }
    return curChar[0].size();
  }
};
```

or more premitive way

``` cpp
const char* curChar[128][5000];
int len[128];
class Solution {
public:
  int numMatchingSubseq(string s, vector<string>& words) {
    memset(len, 0, sizeof(len));
    for(auto &word : words) {
      int c = word.front();
      curChar[c][len[c]] = word.c_str();
      len[c] += 1;
    }
    for(auto c : s) {
      int l = len[c];
      len[c] = 0;
      for(int i = 0; i < l; ++i) {
        const char* nxt = curChar[c][i] + 1;
        curChar[*nxt][len[*nxt]] = nxt;
        len[*nxt] += 1;
      }
    }
    return len[0];
  }
};
```

reduce more heap allocation

``` cpp
const char* curChar[26][5000];
int len[26];
class Solution {
public:
  int numMatchingSubseq(string s, vector<string>& words) {
    memset(len, 0, sizeof(len));
    for(auto &word : words) {
      int c = word.front() - 'a';
      curChar[c][len[c]] = word.c_str();
      len[c] += 1;
    }
    int answer = 0;
    for(auto c : s) {
      c -= 'a';
      int l = len[c];
      len[c] = 0;
      for(int i = 0; i < l; ++i) {
        const char* nxt = curChar[c][i] + 1;
        int c = *nxt - 'a';
        if(!*nxt) { 
          answer += 1;
          continue;
        }
        curChar[c][len[c]] = nxt;
        len[c] += 1;
      }
    }
    return answer;
  }
};

// 52 / 52 test cases passed.
// Status: Accepted
// Runtime: 88 ms
// Memory Usage: 30.3 MB
```

add fast IO

``` cpp
int _IO=[](){
	ios::sync_with_stdio(0);
	cin.tie(0); //cout.tie(0);
	return 0;
}();
const char* curChar[26][5000];
int len[26];
class Solution {
public:
  int numMatchingSubseq(string s, vector<string>& words) {
    memset(len, 0, sizeof(len));
    for(auto &word : words) {
      int c = word.front() - 'a';
      curChar[c][len[c]] = word.c_str();
      len[c] += 1;
    }
    int answer = 0;
    for(auto c : s) {
      c -= 'a';
      int l = len[c];
      len[c] = 0;
      for(int i = 0; i < l; ++i) {
        const char* nxt = curChar[c][i] + 1;
        int c = *nxt - 'a';
        if(!*nxt) { 
          answer += 1;
          continue;
        }
        curChar[c][len[c]] = nxt;
        len[c] += 1;
      }
    }
    return answer;
  }
};

// 52 / 52 test cases passed.
// Status: Accepted
// Runtime: 48 ms
// Memory Usage: 30.4 MB
```

someone even print answer directly...

## Reverse Linked List II

too easy to review

## Out of Boundary Paths

too easy to review

## Redundant Connection

too easy to review

## Binary Tree Maximum Path Sum

too easy to review

## Count of Smaller Numbers After Self

too easy to review

## Brace Expansion II

``` cpp
class Solution {
public:
  vector<string> braceExpansionII(string expression) {
    vector<set<string>> st;
    set<string> cur{""};
    set<string> res;
    set<string> tmp;
    set<string> pre;
    set<string> preRes;
    for(auto c : expression) {
      switch(c) {
        case '{':
          st.push_back(cur);
          st.push_back(res);
          cur = {""};
          res.clear();
          break;
        case '}':
          if(cur.begin()->length() != 0) {
            res.merge(cur);
            cur = {""};
          }
          preRes = st.back();
          st.pop_back();
          pre = st.back();
          st.pop_back();
          cur.clear();
          for(auto resE : res) {
            for(auto preE : pre) {
              cur.insert(preE + resE);
            }
          }
          res = preRes;
          break;
        case ',':
          res.merge(cur);
          cur = {""};
          break;
        default:
          tmp.clear();
          for(auto &s : cur) {
            tmp.insert(s + c);
          }
          swap(cur, tmp);
      }
    }
    if(cur.begin()->length() != 0) {
      res.merge(cur);
    }
    return vector<string>(res.begin(), res.end());
  }
};
```

## Find the Shortest Superstring

already reviewed several times

## Guess the Word

became easy when you solved it.

# June LeetCoding Challenge26

## Description

**Count of Smaller Numbers After Self**

You are given an integer array `nums` and you have to return a new `counts` array. The `counts` array has the property where `counts[i]` is the number of smaller elements to the right of `nums[i]`.

 

**Example 1:**

```
Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
```

**Example 2:**

```
Input: nums = [-1]
Output: [0]
```

**Example 3:**

```
Input: nums = [-1,-1]
Output: [0,0]
```

 

**Constraints:**

- `1 <= nums.length <= 10^5`
- `-10^4 <= nums[i] <= 10^4`

## Solution

done at Wednesday

``` cpp
#define lowbit(x) (x & (-x))

const int SZ = 20001;
const int OFFSET = 10001;
class Solution {
  int BITS[SZ + 1];

  void add(int x) {
    while(x <= SZ) {
      BITS[x] += 1;
      x += lowbit(x);
    }
  }

  int sum(int x) {
    int result = 0;
    while(x) {
      result += BITS[x];
      x -= lowbit(x);
    }
    return result;
  }
public:
  vector<int> countSmaller(vector<int>& nums) {
    vector<int> answer;
    for(int i = nums.size() - 1; i >= 0; --i) {
      int n = nums[i] + OFFSET;
      answer.push_back(sum(n - 1));
      add(n);
    }
    reverse(answer.begin(), answer.end());
    return answer;
  }
};
```
