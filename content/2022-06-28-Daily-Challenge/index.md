+++
updated = 2022-06-28 18:14:00+08:00
title = "2022-06-28 Daily-Challenge"
path = "2022-06-28-Daily-Challenge"
date = 2022-06-28 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 28

## Description

**Minimum Deletions to Make Character Frequencies Unique**

A string `s` is called **good** if there are no two different characters in `s` that have the same **frequency**.

Given a string `s`, return *the **minimum** number of characters you need to delete to make* `s` ***good**.*

The **frequency** of a character in a string is the number of times it appears in the string. For example, in the string `"aab"`, the **frequency** of `'a'` is `2`, while the **frequency** of `'b'` is `1`.

 

**Example 1:**

```
Input: s = "aab"
Output: 0
Explanation: s is already good.
```

**Example 2:**

```
Input: s = "aaabbbcc"
Output: 2
Explanation: You can delete two 'b's resulting in the good string "aaabcc".
Another way it to delete one 'b' and one 'c' resulting in the good string "aaabbc".
```

**Example 3:**

```
Input: s = "ceabaacb"
Output: 2
Explanation: You can delete both 'c's resulting in the good string "eabaab".
Note that we only care about characters that are still in the string at the end (i.e. frequency of 0 is ignored).
```

 

**Constraints:**

- `1 <= s.length <= 10^5`
- `s` contains only lowercase English letters.

## Solution

``` cpp
class Solution {
  bool noDeletion(int *cnt) {
    int pos = 0;
    while(pos < 26 && !cnt[pos]) pos += 1;
    if(!pos) pos += 1;
    while(pos < 26 && cnt[pos] != cnt[pos - 1]) pos += 1;
    return pos == 26;
  }
public:
  int minDeletions(string s) {
    int cnt[26] = {};
    for(auto c : s) {
      cnt[c - 'a'] += 1;
    }
    sort(cnt, cnt + 26);
    if(noDeletion(cnt)) return 0;
    int pos = 0;
    while(pos < 26 && !cnt[pos]) pos += 1;
    int answer = 0;
    for(int i = pos + 1; i < 26; ++i) {
      if(cnt[i] != cnt[i - 1]) continue;
      for(int j = i - 1; j >= pos; --j) {
        if(!cnt[j] || cnt[j] != cnt[j + 1]) break;
        cnt[j] -= 1;
        answer += 1;
      }
    }
    return answer;
  }
};

// Accepted
// 103/103 cases passed (79 ms)
// Your runtime beats 62.49 % of cpp submissions
// Your memory usage beats 81.59 % of cpp submissions (17.3 MB)
```
