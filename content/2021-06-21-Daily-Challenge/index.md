+++
title = "2021-06-21 Daily-Challenge"
path = "2021-06-21-Daily-Challenge"
date = 2021-06-21 18:49:33+08:00
updated = 2021-06-21 21:16:39+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Find the Shortest Superstring](https://leetcode.com/problems/find-the-shortest-superstring/description/) and leetcode's [June LeetCoding Challenge](https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/605/week-3-june-15th-june-21st/3786/) with `cpp`.

<!-- more -->

# Find the Shortest Superstring

## Description

Given an array of strings `words`, return *the smallest string that contains each string in* `words` *as a substring*. If there are multiple valid strings of the smallest length, return **any of them**.

You may assume that no string in `words` is a substring of another string in `words`.

 

**Example 1:**

```
Input: words = ["alex","loves","leetcode"]
Output: "alexlovesleetcode"
Explanation: All permutations of "alex","loves","leetcode" would also be accepted.
```

**Example 2:**

```
Input: words = ["catg","ctaagt","gcta","ttca","atgcatc"]
Output: "gctaagttcatgcatc"
```

 

**Constraints:**

- `1 <= words.length <= 12`
- `1 <= words[i].length <= 20`
- `words[i]` consists of lowercase English letters.
- All the strings of `words` are **unique**.

## Solution

solve forward, not quick enough

``` cpp
const int SZ = (1 << 12);

int pre[SZ][12];
int overlap[12][12];

using ti = tuple<int, int, int, int>;

void init(vector<string> &words) {
  int len = words.size();
  for(int i = 0; i < len; ++i) {
    for(int j = 0; j < len; ++j) {
      if(i == j) continue;
      overlap[i][j] = 0;
      for(int k = min(words[i].length(), words[j].length()) - 1; k > 0; --k) {
        if(words[i].substr(words[i].length() - k) == words[j].substr(0, k)) {
          overlap[i][j] = k;
          break;
        }
      }
    }
  }
}

string constructAnswer(vector<string> &words, int state, int last) {
  string answer = words[last];
  while(pre[state][last] != -1) {
    int p = pre[state][last];
    state ^= (1 << last);
    answer = words[p].substr(0, words[p].length() - overlap[p][last]) + answer;
    last = p;
  }
  return answer;
}

string solve(vector<string> &words) {
  memset(pre, -1, sizeof(pre));
  priority_queue<ti, vector<ti>, greater<ti>> pq;
  int len = words.size();
  int target = (1 << len) - 1;
  for(int i = 0; i < len; ++i) {
    pq.push({words[i].length(), 1 << i, -1, i});
  }
  while(pq.size()) {
    auto [length, state, p, last] = pq.top();
    // cout << length << " " << state <<  " " << p << " " << last  << endl;
    pq.pop();
    if(pre[state][last] != -1) continue;
    pre[state][last] = p;
    if(state == target) return constructAnswer(words, state, last);
    for(int i = 0; i < len; ++i) {
      if(state & (1 << i)) continue;
      pq.push({length + words[i].length() - overlap[last][i], state | (1 << i), last, i});
    }
  }
  return "";
}
class Solution {
public:
  string shortestSuperstring(vector<string>& words) {
    init(words);    
    return solve(words);
  }
};
```

# June LeetCoding Challenge21

## Description

**Pascal's Triangle**

Given an integer `numRows`, return the first numRows of **Pascal's triangle**.

In **Pascal's triangle**, each number is the sum of the two numbers directly above it as shown:

![img](https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif)

 

**Example 1:**

```
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
```

**Example 2:**

```
Input: numRows = 1
Output: [[1]]
```

 

**Constraints:**

- `1 <= numRows <= 30`

## Solution

``` cpp
class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> answer(numRows);
    answer[0] = {1};
    for(int i = 1; i < numRows; ++i) {
      for(int j = 0; j <= i; ++j) {
        if(!j || j == i) {
          answer[i].push_back(1);
        } else {
          answer[i].push_back(answer[i - 1][j - 1] + answer[i - 1][j]);
        }
      }
    }
    return answer;
  }
};
```
