+++
title = "2021-09-13 Daily-Challenge"
path = "2021-09-13-Daily-Challenge"
date = 2021-09-13 20:17:03+08:00
updated = 2021-09-13 20:19:36+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/637/week-2-september-8th-september-14th/3973/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 13

## Description

**Maximum Number of Balloons**

Given a string `text`, you want to use the characters of `text` to form as many instances of the word **"balloon"** as possible.

You can use each character in `text` **at most once**. Return the maximum number of instances that can be formed.

 

**Example 1:**

**![img](https://assets.leetcode.com/uploads/2019/09/05/1536_ex1_upd.JPG)**

```
Input: text = "nlaebolko"
Output: 1
```

**Example 2:**

**![img](https://assets.leetcode.com/uploads/2019/09/05/1536_ex2_upd.JPG)**

```
Input: text = "loonbalxballpoon"
Output: 2
```

**Example 3:**

```
Input: text = "leetcode"
Output: 0
```

 

**Constraints:**

- `1 <= text.length <= 10^4`
- `text` consists of lower case English letters only.

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int maxNumberOfBalloons(string text) {
    int cnt[128] = {};
    for(auto c : text) {
      cnt[c] += 1;
    }

    int answer = INT_MAX;
    answer = min(answer, cnt['b']);
    answer = min(answer, cnt['a']);
    answer = min(answer, cnt['n']);
    answer = min(answer, cnt['l'] / 2);
    answer = min(answer, cnt['o'] / 2);

    return answer;
  }
};

// Accepted
// 24/24 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 85.28 % of cpp submissions (6.6 MB)
```
