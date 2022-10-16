+++
title = "2019-01-10 Daily Challenge"
path = "2019-01-10-daily-challenge"
date = 2019-01-10T00:08:38+00:00
updated = 2020-09-19T20:01:27.626330+00:00
description = "DailyChallenge"

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Amicable number* in *Rust* and *Unique Morse Code Words* in *JavaScript*.

<!-- more -->

# Math

## Problem

```
Amicable numbers

Problem 21 

Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.
```

## Solution

One way to do it is check the divisor in $O(\sqrt n)$ time complexity.

One way to do it is get the primal factorial of number, and do it with DFS approach. I came up with this idea and don't checked its time complexity, nor implemented it.

One way to do it is get the prima factorial of number which:

$$n=p_1^{a_1}p_2^{a_2}...p_k^{a_k}$$

Then, the sum of divisors(including itself) is 

$$\prod_{i=1}^{k}(p_i^0+p_i^1+...+p_i^{a_i})$$

ref: https://mathschallenge.net/library/number/sum_of_divisors

## Implementation

```rust
extern crate primal;

use std::vec::Vec;
use primal::Sieve;

fn main() {
    let sieve = Sieve::new(10000);
    let mut ans = 0;
    assert!(sum_of_divisor(284, &sieve) == 220);
    assert!(sum_of_divisor(220, &sieve) == 284);
    for num in 2..10000 {
        let tmp = sum_of_divisor(num, &sieve);
        if tmp < 10000 && tmp != num &&sum_of_divisor(tmp, &sieve) == num {
            ans += tmp + num;
        } 
    }
    ans /= 2;
    println!("Answer is {}", ans);
}

fn sum_of_divisor(n: i32, sieve: &Sieve) -> i32 {
    let factors: Vec<(usize, usize)> = match sieve.factor(n as usize) {
        Ok(v) => v,
        Err(_) => Vec::new(),
    };
    let mut ans = 1;
    for factor in factors {
        let mut tmp = 1;
        let mut sum = 1;
        for _ in 0..factor.1 {
            tmp *= factor.0;
            sum += tmp;
        }
        ans *= sum;
    }
    ans as i32 - n
}
```

# Algorithm

## Problem

```
804. Unique Morse Code Words

International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows: "a" maps to ".-", "b" maps to "-...", "c" maps to "-.-.", and so on.

For convenience, the full table for the 26 letters of the English alphabet is given below:

[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
Now, given a list of words, each word can be written as a concatenation of the Morse code of each letter. For example, "cba" can be written as "-.-..--...", (which is the concatenation "-.-." + "-..." + ".-"). We'll call such a concatenation, the transformation of a word.

Return the number of different transformations among all words we have.

Example:
Input: words = ["gin", "zen", "gig", "msg"]
Output: 2
Explanation: 
The transformation of each word is:
"gin" -> "--...-."
"zen" -> "--...-."
"gig" -> "--...--."
"msg" -> "--...--."

There are 2 different transformations, "--...-." and "--...--.".
Note:

The length of words will be at most 100.
Each words[i] will have length in range [1, 12].
words[i] will only consist of lowercase letters.
```

## Solution

Use map to encode, set to record.

## Implementation

```js
/**
 * @param {string[]} words
 * @return {number}
 */
var uniqueMorseRepresentations = function(words) {
  let map = new Map([
    ['a','.-'], ['b','-...'], ['c','-.-.'], ['d','-..'],
    ['e','.'], ['f','..-.'], ['g','--.'], ['h','....'],
    ['i','..'], ['j','.---'], ['k','-.-'], ['l','.-..'],
    ['m','--'], ['n','-.'], ['o','---'], ['p','.--.'],
    ['q','--.-'], ['r','.-.'], ['s','...'], ['t','-'],
    ['u','..-'], ['v','...-'], ['w','.--'], ['x','-..-'],
    ['y','-.--'], ['z','--..']]);
  let set = new Set();
  for(const word of words) {
    let str = "";
    for(const c of word) {
      str += map.get(c);
    }
    set.add(str);
  }
  return set.size;
};
```