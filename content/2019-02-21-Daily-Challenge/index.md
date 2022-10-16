+++
title = "2019-02-21 Daily Challenge"
path = "2019-02-21-daily-challenge"
date = 2019-02-21T00:36:02+00:00
updated = 2020-09-19T20:01:27.631316+00:00
description = "DailyChallenge"

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Powerful digit counts* in *Rust* and *Partition to K Equal Sum Subsets* in *JavaScript*.

<!-- more -->

# Math

## Problem

### Powerful digit counts

### Problem 63

The 5-digit number, 16807=75, is also a fifth power. Similarly, the 9-digit number, 134217728=89, is a ninth power.

How many *n*-digit positive integers exist which are also an *n*th power?

## Solution

Knowledge behind this problem is easy to understand but not easy to illustrate, so check my code~

## Implementation

```rust
fn main() {
    let mut ans = 0;
    for i in 1u128..10u128 {
        let mut stop = false; // Don't stop!
        let mut exp: u32 = 1; 
        while !stop {
            let len = i.pow(exp).to_string().len();
            if len != exp as usize {
                stop = true;
            } else {
                ans += 1;
            }
            exp += 1;
        }
    }
    println!("Answer is {}", ans);
}
```

# Algorithm

## Problem

### 698. Partition to K Equal Sum Subsets

Given an array of integers `nums` and a positive integer `k`, find whether it's possible to divide this array into `k` non-empty subsets whose sums are all equal.

 

**Example 1:**

```
Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
Output: True
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
```

 

**Note:**

- `1 <= k <= len(nums) <= 16`.
- `0 < nums[i] < 10000`.

## Solution

JS's sort is just like shit.

## Implementation

```js
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var canPartitionKSubsets = function(nums, k) {
  let sum = 0;
  for (let i = 0; i < nums.length; ++i) sum+=nums[i];
  let part = sum/k;
  for (let i = 0; i < nums.length; ++i) if (nums[i] > part) return false;
  if (sum % k !== 0 || nums.length < k ) return false;
  let used = Array.from({length:nums.length}, x=>false);
  let left = nums.length;
  return (function dfs(target, start) {
    if (left === 0) return true;
    if (target === 0) return dfs(part, 0);
    for(let i = start; i < nums.length; ++i) {
      if (!used[i] && nums[i] <= target) {
        used[i] = true;
        left -= 1;
        if (dfs(target - nums[i], i + 1)) return true;
        used[i] = false;
        left += 1;
      }
    }
    return false;
  })(part, 0);
};

// console.log(canPartitionKSubsets([18,20,39,73,96,99,101,111,114,190,207,295,471,649,700,1037], 4));
```