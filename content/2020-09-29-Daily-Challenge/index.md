+++
title = "2020-09-29 Daily-Challenge"
path = "2020-09-29-Daily-Challenge"
date = 2019-09-29
updated = 2020-09-29 14:56:06+08:00
in_search_index = true

[taxonomies]
tags = ["Design",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is an example of *The non-Designer's Design Book* on Page 42 and *Check If a Word Occurs As a Prefix of Any Word in a Sentence* on leetcode with `cpp`.

<!-- more -->

# The non-Designer's Design Book

my answer:
  - [T] reduce the distance between serial numbers and items
  - [T] change `6` in title to word `six` so it doesn't confuse the reader
  - [T] increase the size of the font of the title
  - [ ] increase size of the image so it aligns with text both on top and bottom

I got 3/3 of the correct rate, and I think the one answer doesn't give is also a useful difference!

# Check If a Word Occurs As a Prefix of Any Word in a Sentence

## Description

Given a `sentence` that consists of some words separated by a **single space**, and a `searchWord`.

You have to check if `searchWord` is a prefix of any word in `sentence`.

Return *the index of the word* in `sentence` where `searchWord` is a prefix of this word (**1-indexed**).

If `searchWord` is a prefix of more than one word, return the index of the first word **(minimum index)**. If there is no such word return **-1**.

A **prefix** of a string `S` is any leading contiguous substring of `S`.

**Example 1:**

```
Input: sentence = "i love eating burger", searchWord = "burg"
Output: 4
Explanation: "burg" is prefix of "burger" which is the 4th word in the sentence.
```

**Example 2:**

```
Input: sentence = "this problem is an easy problem", searchWord = "pro"
Output: 2
Explanation: "pro" is prefix of "problem" which is the 2nd and the 6th word in the sentence, but we return 2 as it's the minimal index.
```

**Example 3:**

```
Input: sentence = "i am tired", searchWord = "you"
Output: -1
Explanation: "you" is not a prefix of any word in the sentence.
```

**Example 4:**

```
Input: sentence = "i use triple pillow", searchWord = "pill"
Output: 4
```

**Example 5:**

```
Input: sentence = "hello from the other side", searchWord = "they"
Output: -1
```

**Constraints:**

- `1 <= sentence.length <= 100`
- `1 <= searchWord.length <= 10`
- `sentence` consists of lowercase English letters and spaces.
- `searchWord` consists of lowercase English letters.

## Solution

simple question, but remember that string.length() returns `size_t` which is a unsigned number, which leads to first `Runtime Errro` :(

``` cpp
class Solution {
public:
  bool isPrefixOfIndex(const int offset, const string& prefix, const string& str) {
    for (int i = 0; i < prefix.length(); ++i) {
      if (prefix[i] != str[offset + i]) {
        return false;
      }
    }
    return true;
  }
  int isPrefixOfWord(string sentence, string searchWord) {
    int count = 0;
    for (int i = 0; i <= int(sentence.length()) - int(searchWord.length()); ++i) {
      if (sentence[i] == ' ') {
        count += 1;
      } else if (!i || sentence[i - 1] == ' ') {
        if (isPrefixOfIndex(i, searchWord, sentence)) {
          return count + 1;
        }
      }
    }
    return -1;
  }
};
```