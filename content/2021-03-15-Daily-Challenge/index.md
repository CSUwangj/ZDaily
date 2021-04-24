+++
title = "2021-03-15 Daily-Challenge"
path = "2021-03-15-Daily-Challenge"
date = 2021-03-15 18:31:03+08:00
updated = 2021-03-15 20:10:02+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Matrix Block Sum](https://leetcode.com/problems/matrix-block-sum/) and leetcode's [March LeetCoding Challenge](https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/590/week-3-march-15th-march-21st/3673/) with `cpp`.

<!-- more -->

# Matrix Block Sum

## Description

Given a `m * n` matrix `mat` and an integer `K`, return a matrix `answer` where each `answer[i][j]` is the sum of all elements `mat[r][c]` for `i - K <= r <= i + K, j - K <= c <= j + K`, and `(r, c)` is a valid position in the matrix.

 

**Example 1:**

```
Input: mat = [[1,2,3],[4,5,6],[7,8,9]], K = 1
Output: [[12,21,16],[27,45,33],[24,39,28]]
```

**Example 2:**

```
Input: mat = [[1,2,3],[4,5,6],[7,8,9]], K = 2
Output: [[45,45,45],[45,45,45],[45,45,45]]
```

 

**Constraints:**

- `m == mat.length`
- `n == mat[i].length`
- `1 <= m, n, K <= 100`
- `1 <= mat[i][j] <= 100`

## Solution

``` cpp
class Solution {
public:
  vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
    int rows = mat.size();
    int cols = mat.front().size();
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        if(i) mat[i][j] += mat[i - 1][j];
        if(j) mat[i][j] += mat[i][j - 1];
        if(i && j) mat[i][j] -= mat[i - 1][j - 1];
      }
    }
    
    vector<vector<int>> answer(rows, vector<int>(cols));
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        int bottom = i + K < rows ? i + K : rows - 1;
        int right = j + K < cols ? j + K : cols - 1;
        int left = j - K;
        int top = i - K;
        int result = mat[bottom][right];
        if(left > 0) result -= mat[bottom][left - 1];
        if(top > 0) result -= mat[top - 1][right];
        if(left > 0 && top > 0) result += mat[top - 1][left - 1];
        answer[i][j] = result;
      }
    }
    return answer;
  }
};

```

# March LeetCoding Challenge15

## Description

**Encode and Decode TinyURL**

> Note: This is a companion problem to the [System Design](https://leetcode.com/discuss/interview-question/system-design/) problem: [Design TinyURL](https://leetcode.com/discuss/interview-question/124658/Design-a-URL-Shortener-(-TinyURL-)-System/).

TinyURL is a URL shortening service where you enter a URL such as `https://leetcode.com/problems/design-tinyurl` and it returns a short URL such as `http://tinyurl.com/4e9iAk`.

Design the `encode` and `decode` methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.

## Solution

another system design problem...

``` cpp
class Solution {
public:
  unordered_map<string, string> mp, rmp;
  int count = 0;
  // Encodes a URL to a shortened URL.
  string encode(string longUrl) {
    if(!mp.count(longUrl)) {
      string cnt = to_string(count++);
      mp[longUrl] = cnt;
      rmp[cnt] = longUrl;
    }
    return mp[longUrl];
  }

  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl) {
    return rmp[shortUrl];
  }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
```
