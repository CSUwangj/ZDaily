+++
title = "2019-01-11 Daily Challenge"
path = "2019-01-11-daily-challenge"
date = 2019-01-11T00:37:59+00:00
updated = 2020-09-19T20:01:27.626330+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Names scores* in *Rust* and *Optimal Division* in *JavaScript*.

<!-- more -->

# Math

## Problem

```
Names scores

Problem 22 

Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?
```

## Solution

Emmmmm, use .sort so... nothing to say.

## Implementation

```rust
fn main() {
    let mut names = [
        String::from("MARY"),
        String::from("PATRICIA"),
        String::from("LINDA"),
        String::from("BARBARA"),
        /* omit 5K lines */
        String::from("HAI"),
        String::from("ELDEN"),
        String::from("DORSEY"),
        String::from("DARELL"),
        String::from("BRODERICK"),
        String::from("ALONSO"),
	];
    names.sort();
    let mut ans: i64 = 0;
    const MINES: i32 = 'A' as i32 - 1;
    for i in 0..names.len() {
        let mut score = 0;
        for letter in names[i].chars() {
            score += letter as i32 - MINES;
        }
        ans += (score * (i as i32 +1)) as i64;
    }
    println!("Answer is {}", ans);
}
```

# Algorithm

## Problem

```
553. Optimal Division

Given a list of positive integers, the adjacent integers will perform the float division. For example, [2,3,4] -> 2 / 3 / 4.

However, you can add any number of parenthesis at any position to change the priority of operations. You should find out how to add parenthesis to get the maximum result, and return the corresponding expression in string format. Your expression should NOT contain redundant parenthesis.

Example:
Input: [1000,100,10,2]
Output: "1000/(100/10/2)"
Explanation:
1000/(100/10/2) = 1000/((100/10)/2) = 200
However, the bold parenthesis in "1000/((100/10)/2)" are redundant, 
since they don't influence the operation priority. So you should return "1000/(100/10/2)". 

Other cases:
1000/(100/10)/2 = 50
1000/(100/(10/2)) = 50
1000/100/10/2 = 0.5
1000/100/(10/2) = 2
Note:

The length of the input array is [1, 10].
Elements in the given array will be in range [2, 1000].
There is only one optimal division for each test case.
```

## Solution

I first was derived into a wrong way -- DP.

But figured out that mathematical way is the best.

Check my code if you don't get it.

## Implementation

```js
/**
 * @param {number[]} nums
 * @return {string}
 */
var optimalDivision = function(nums) {
    if (nums.length === 1) return `${nums[0]}`;
    if (nums.length === 2) return `${nums[0]}/${nums[1]}`;
    return `${nums[0]}/(${nums.slice(1).join('/')})`;
};
```