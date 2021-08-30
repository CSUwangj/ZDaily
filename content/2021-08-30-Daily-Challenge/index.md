+++
title = "2021-08-30 Daily-Challenge"
path = "2021-08-30-Daily-Challenge"
date = 2021-08-30 18:10:07+08:00
updated = 2021-08-30 18:35:21+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Sorting the Sentence](https://leetcode.com/problems/sorting-the-sentence/description/) and leetcode's [August LeetCoding Challenge](https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/617/week-5-august-29th-august-31st/3957/) with `cpp`.

<!-- more -->

# Sorting the Sentence

## Description

A **sentence** is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of lowercase and uppercase English letters.

A sentence can be **shuffled** by appending the **1-indexed word position** to each word then rearranging the words in the sentence.

- For example, the sentence `"This is a sentence"` can be shuffled as `"sentence4 a3 is2 This1"` or `"is2 sentence4 This1 a3"`.

Given a **shuffled sentence** `s` containing no more than `9` words, reconstruct and return *the original sentence*.

 

**Example 1:**

```
Input: s = "is2 sentence4 This1 a3"
Output: "This is a sentence"
Explanation: Sort the words in s to their original positions "This1 is2 a3 sentence4", then remove the numbers.
```

**Example 2:**

```
Input: s = "Myself2 Me1 I4 and3"
Output: "Me Myself and I"
Explanation: Sort the words in s to their original positions "Me1 Myself2 and3 I4", then remove the numbers.
```

 

**Constraints:**

- `2 <= s.length <= 200`
- `s` consists of lowercase and uppercase English letters, spaces, and digits from `1` to `9`.
- The number of words in `s` is between `1` and `9`.
- The words in `s` are separated by a single space.
- `s` contains no leading or trailing spaces.

## Solution

``` cpp
class Solution {
public:
  string sortSentence(string s) {
    vector<string> container(9);
    string word;
    int len = 0;
    for(auto c : s) {
      if(isdigit(c)) {
        container[c - '1'] = word;
        len = max(c - '0', len);
        word = "";
      } else if(isalpha(c)) {
        word.push_back(c);
      }
    }
    string answer = container[0];
    for(int i = 1; i < len; ++i) {
      answer = answer + " " + container[i];
    }
    return answer;
  }
};

// Accepted
// 45/45 cases passed (3 ms)
// Your runtime beats 9.94 % of cpp submissions
// Your memory usage beats 40.63 % of cpp submissions (6.4 MB)
```

# August LeetCoding Challenge 30

## Description

**Range Addition II**

You are given an `m x n` matrix `M` initialized with all `0`'s and an array of operations `ops`, where `ops[i] = [ai, bi]` means `M[x][y]` should be incremented by one for all `0 <= x < ai` and `0 <= y < bi`.

Count and return *the number of maximum integers in the matrix after performing all the operations*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/10/02/ex1.jpg)

```
Input: m = 3, n = 3, ops = [[2,2],[3,3]]
Output: 4
Explanation: The maximum integer in M is 2, and there are four of it in M. So return 4.
```

**Example 2:**

```
Input: m = 3, n = 3, ops = [[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3]]
Output: 4
```

**Example 3:**

```
Input: m = 3, n = 3, ops = []
Output: 9
```

 

**Constraints:**

<ul>
	<li><code>1 &lt;= m, n &lt;= 4 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= ops.length &lt;= 10<sup>4</sup></code></li>
	<li><code>ops[i].length == 2</code></li>
	<li><code>1 &lt;= a<sub>i</sub> &lt;= m</code></li>
	<li><code>1 &lt;= b<sub>i</sub> &lt;= n</code></li>
</ul>


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
  int maxCount(int m, int n, vector<vector<int>>& ops) {
    for(auto &op : ops) {
      m = min(m, op[0]);
      n = min(n, op[1]);
    }
    return m * n;
  }
};

// Accepted
// 69/69 cases passed (12 ms)
// Your runtime beats 54.99 % of cpp submissions
// Your memory usage beats 57.77 % of cpp submissions (11 MB)
```
