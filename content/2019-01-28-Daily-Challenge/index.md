+++
title = "2019-01-28 Daily Challenge"
path = "2019-01-28-daily-challenge"
date = 2019-01-28T00:04:05+00:00
updated = 2020-09-19T20:01:27.627328+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Integer right triangles* in *Rust* and *Implement Magic Dictionary* in *JavaScript*.

<!-- more -->

# Math

## Problem

### Integer right triangles

### Problem 39

If *p* is the perimeter of a right angle triangle with integral length sides, {*a*,*b*,*c*}, there are exactly three solutions for *p* = 120.

{20,48,52}, {24,45,51}, {30,40,50}

For which value of *p* ≤ 1000, is the number of solutions maximised?

## Solution

Nothing to say.

## Implementation

```rust
fn main() {
    let mut ans = 0;
    let mut cnt = 0;
    for i in 12..1001 {
        let mut tmp = 0;
        for j in 1..i {
            for k in (2..i).rev() {
                let l = i-j-k;
                if k <= j {
                    break;
                }
                if l <= k {
                    continue;
                }
                // println!("{},{},{},{}", i, j, k, l);
                if l*l == j*j+k*k {
                    tmp += 1;
                }
            }
        }
        if tmp > cnt {
            ans = i;
            cnt = tmp;
        }
        // println!("{}, {}", i, tmp);
    }
    println!("Answer is {}", ans);
}
```

# Algorithm

## Problem

### 676. Implement Magic Dictionary

Implement a magic directory with `buildDict`, and `search`methods.

For the method `buildDict`, you'll be given a list of non-repetitive words to build a dictionary.

For the method `search`, you'll be given a word, and judge whether if you modify **exactly** one character into **another** character in this word, the modified word is in the dictionary you just built.

**Example 1:**

```
Input: buildDict(["hello", "leetcode"]), Output: Null
Input: search("hello"), Output: False
Input: search("hhllo"), Output: True
Input: search("hell"), Output: False
Input: search("leetcoded"), Output: False
```



**Note:**

1. You may assume that all the inputs are consist of lowercase letters `a-z`.
2. For contest purpose, the test data is rather small by now. You could think about highly efficient algorithm after the contest.
3. Please remember to **RESET** your class variables declared in class MagicDictionary, as static/class variables are **persisted across multiple test cases**. Please see [here](https://leetcode.com/faq/#different-output) for more details.

## Solution

Nothing to say.

## Implementation

```js
/**
 * Initialize your data structure here.
 */
var MagicDictionary = function() {
  if (this.set) this.set.clear();
  else this.set = new Set();
};

/**
 * Build a dictionary through a list of words
 * @param {string[]} dict
 * @return {void}
 */
MagicDictionary.prototype.buildDict = function(dict) {
  for (const w of dict) {
    this.set.add(w);
  }
};

/**
 * Returns if there is any word in the trie that equals to the given word after modifying exactly one character
 * @param {string} word
 * @return {boolean}
 */
MagicDictionary.prototype.search = function(word) {
  const isOK = (w1, w2) => {
    if (w1.length !== w2.length) return false;
    let cnt = 0;
    for (let i = 0; i < w1.length; ++i) {
      if (w1.charAt(i) !== w2.charAt(i)) ++cnt;
    }
    return cnt === 1;
  };
  for (const w of this.set) {
    if (w.length === word.length && isOK(w, word)) return true;
  }
  return false;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * var obj = Object.create(MagicDictionary).createNew()
 * obj.buildDict(dict)
 * var param_2 = obj.search(word)
 */
```