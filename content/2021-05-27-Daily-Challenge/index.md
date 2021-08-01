+++
title = "2021-05-27 Daily-Challenge"
path = "2021-05-27-Daily-Challenge"
date = 2021-05-27 18:59:26+08:00
updated = 2021-05-27 22:44:55+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Create Maximum Number](https://leetcode.com/problems/create-maximum-number/) and leetcode's [May LeetCoding Challenge](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/601/week-4-may-22nd-may-28th/3757/) with `cpp`.

<!-- more -->

# Create Maximum Number

## Description

You are given two integer arrays `nums1` and `nums2` of lengths `m` and `n` respectively. `nums1` and `nums2` represent the digits of two numbers. You are also given an integer `k`.

Create the maximum number of length `k <= m + n` from digits of the two numbers. The relative order of the digits from the same array must be preserved.

Return an array of the `k` digits representing the answer.

 

**Example 1:**

```
Input: nums1 = [3,4,6,5], nums2 = [9,1,2,5,8,3], k = 5
Output: [9,8,6,5,3]
```

**Example 2:**

```
Input: nums1 = [6,7], nums2 = [6,0,4], k = 5
Output: [6,7,6,0,4]
```

**Example 3:**

```
Input: nums1 = [3,9], nums2 = [8,9], k = 3
Output: [9,8,9]
```

 

**Constraints:**

- `m == nums1.length`
- `n == nums2.length`
- `1 <= m, n <= 500`
- `0 <= nums1[i], nums2[i] <= 9`
- `1 <= k <= m + n`

 

**Follow up:** Try to optimize your time and space complexity.

## Solution

when it comes one nums, it's easy to get maximum by erase some digit, but when it comes two, it's difficult.

I first write this and find it wrong

``` cpp
bool cmp(const vector<int> &v1, int i1, const vector<int> &v2, int i2) {
  while(i1 < v1.size() && i2 < v2.size()) {
    if(v1[i1] != v2[i2]) return v1[i1] < v2[i2];
    i1 += 1;
    i2 += 1;
  }
  return i1 < v1.size();
}
class Solution {
  int getCur(const vector<int> &v1, int &i1, const vector<int> &v2, int &i2) {
    if(cmp(v1, i1, v2, i2)) {
      return v2[i2++];
    }
    return v1[i1++];
  }
public:
  vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<int> answer;
    int pos1 = 0;
    int pos2 = 0;
    int len1 = nums1.size();
    int len2 = nums2.size();
    while(pos1 < len1 && pos2 < len2) {
      int cur = getCur(nums1, pos1, nums2, pos2);
      while(answer.size() && answer.back() < cur && len1 - pos1 + len2 - pos2 + answer.size() >= k) {
        answer.pop_back();
      }
      answer.push_back(cur);
    }
    vector<int> &rest = pos1 == len1 ? nums2 : nums1;
    int restIndex = pos1 == len1 ? pos2 : pos1;
    int restLen = rest.size();
    while(restIndex < restLen) {
      int cur = rest[restIndex++];
      while(answer.size() && answer.back() < cur && restLen - restIndex + answer.size() >= k) {
        answer.pop_back();
      }
      answer.push_back(cur);
    }
    return answer;
  }
};
```

'cause for example 1, when we meet `8` in nums2, `6`, `5` is already in answer, so we will work backwords to get the right answer, it's so hard.

Remember I said that it's easy to get one max number, so we can use merge sort to get the max number by merging two max numbers from each vector. and we need to enumerate all length combinations, so time complexity is $O((m+n)^2)$

``` cpp
string getNumber(vector<int> &nums, int remove) {
  string answer;
  for(auto i : nums) {
    while(answer.length() && answer.back() < i && remove) {
      answer.pop_back();
      remove -= 1;
    }
    answer.push_back(char(i));
  }
  while(remove--) answer.pop_back();
  return answer;
}

bool lexicGreater(string &s1, int pos1, string &s2, int pos2) {
  for(int i = 0; i + pos1 < s1.length() && i + pos2 < s2.length(); ++i) {
    if(s1[i + pos1] != s2[i + pos2]) return s1[i + pos1] > s2[i + pos2];
  }
  return s1.length() - pos1 > s2.length() - pos2;
}

string merge(string &s1, string &s2) {
  int pos1 = 0;
  int pos2 = 0;
  int len1 = s1.length();
  int len2 = s2.length();
  string answer;
  while(pos1 < len1 && pos2 < len2) {
    if(lexicGreater(s1, pos1, s2, pos2)) {
      answer.push_back(s1[pos1++]);
    } else {
      answer.push_back(s2[pos2++]);
    }
  }
  while(pos1 < len1) answer.push_back(s1[pos1++]);
  while(pos2 < len2) answer.push_back(s2[pos2++]);
  return answer;
}
class Solution {
public:
  vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    int len1 = nums1.size();
    int len2 = nums2.size();
    int diff = len1 + len2 - k;
    string answer;
    for(int i = 0; i <= diff; ++i) {
      int j = diff - i;
      if(i > len1 || j > len2) continue;
      string s1 = getNumber(nums1, i);
      string s2 = getNumber(nums2, j);
      answer = max(answer, merge(s1, s2));
    }
    vector<int> realAnswer;
    for(auto c : answer) realAnswer.push_back(c);
    return realAnswer;
  }
};
```

# May LeetCoding Challenge 27

## Description

**Maximum Product of Word Lengths**

Given a string array `words`, return *the maximum value of* `length(word[i]) * length(word[j])` *where the two words do not share common letters*. If no such two words exist, return `0`.

 

**Example 1:**

```
Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
Output: 16
Explanation: The two words can be "abcw", "xtfn".
```

**Example 2:**

```
Input: words = ["a","ab","abc","d","cd","bcd","abcd"]
Output: 4
Explanation: The two words can be "ab", "cd".
```

**Example 3:**

```
Input: words = ["a","aa","aaa","aaaa"]
Output: 0
Explanation: No such pair of words.
```

 

**Constraints:**

- `2 <= words.length <= 1000`
- `1 <= words[i].length <= 1000`
- `words[i]` consists only of lowercase English letters.

## Solution

using mask

``` cpp
class Solution {
public:
  int maxProduct(vector<string>& words) {
    int sz = words.size();
    vector<int> mask(sz);
    vector<int> len(sz);
    for(int i = 0; i < sz; ++i) {
      for(auto c : words[i]) mask[i] |= (1 << (c - 'a'));
      len[i] = words[i].length();
    }
    int answer = 0;
    for(int i = 0; i < sz - 1; ++i) {
      for(int j = i + 1; j < sz; ++j) {
        if(!(mask[i] & mask[j])) answer = max(answer, len[i] * len[j]);
      }
    }
    return answer;
  }
};
```
