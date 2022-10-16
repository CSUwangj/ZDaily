+++
title = "2021-08-11 Daily-Challenge"
path = "2021-08-11-Daily-Challenge"
date = 2021-08-11 19:02:03+08:00
updated = 2021-08-11 19:28:35+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Largest Time for Given Digits](https://leetcode.com/problems/largest-time-for-given-digits/description/) and leetcode's [August LeetCoding Challenge](https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/614/week-2-august-8th-august-14th/3877/) with `cpp`.

<!-- more -->

# Largest Time for Given Digits

## Description

Given an array `arr` of 4 digits, find the latest 24-hour time that can be made using each digit **exactly once**.

24-hour times are formatted as `"HH:MM"`, where `HH` is between `00` and `23`, and `MM` is between `00` and `59`. The earliest 24-hour time is `00:00`, and the latest is `23:59`.

Return *the latest 24-hour time in `"HH:MM"` format*. If no valid time can be made, return an empty string.

 

**Example 1:**

```
Input: arr = [1,2,3,4]
Output: "23:41"
Explanation: The valid 24-hour times are "12:34", "12:43", "13:24", "13:42", "14:23", "14:32", "21:34", "21:43", "23:14", and "23:41". Of these times, "23:41" is the latest.
```

**Example 2:**

```
Input: arr = [5,5,5,5]
Output: ""
Explanation: There are no valid 24-hour times as "55:55" is not valid.
```

**Example 3:**

```
Input: arr = [0,0,0,0]
Output: "00:00"
```

**Example 4:**

```
Input: arr = [0,0,1,0]
Output: "10:00"
```

 

**Constraints:**

- `arr.length == 4`
- `0 <= arr[i] <= 9`

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
  string largestTimeFromDigits(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    string answer = ":::::";
    do {
      if(arr[0] > 2) break;
      if(arr[0] == 2 && arr[1] > 3) break;
      if(arr[2] > 5) continue;
      answer[0] = arr[0] + '0';
      answer[1] = arr[1] + '0';
      answer[3] = arr[2] + '0';
      answer[4] = arr[3] + '0';
    } while(next_permutation(arr.begin(), arr.end())); 
    return answer[0] != ':' ? answer : "";
  }
};

// Accepted
// 172/172 cases passed (4 ms)
// Your runtime beats 56.47 % of cpp submissions
// Your memory usage beats 17.45 % of cpp submissions (9.7 MB)
```

# August LeetCoding Challenge 11

## Description

**Array of Doubled Pairs**

Given an array of integers `arr` of even length, return `true` if and only if it is possible to reorder it such that `arr[2 * i + 1] = 2 * arr[2 * i]` for every `0 <= i < len(arr) / 2`.

 

**Example 1:**

```
Input: arr = [3,1,3,6]
Output: false
```

**Example 2:**

```
Input: arr = [2,1,2,6]
Output: false
```

**Example 3:**

```
Input: arr = [4,-2,2,-4]
Output: true
Explanation: We can take two groups, [-2,-4] and [2,4] to form [-2,-4,2,4] or [2,4,-2,-4].
```

**Example 4:**

```
Input: arr = [1,2,4,16,8,4]
Output: false
```
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= arr.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>arr.length</code> is even.</li>
	<li><code>-10<sup>5</sup> &lt;= arr[i] &lt;= 10<sup>5</sup></code></li>
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
  bool valid(map<int, int> cnt) {
    for(auto [i, c] : cnt) {
      if(!c) continue;
      if(!cnt.count(i * 2) || cnt[2 * i] < c) return false;
      cnt[i * 2] -= c;
    }
    return true;
  }
public:
  bool canReorderDoubled(vector<int>& arr) {
    map<int, int> cnt;
    for(auto i : arr) {
      if(i >= 0) cnt[i] += 1;
    }
    if((cnt[0]&1) || !valid(cnt)) return false;
    cnt.clear();
    for(auto i : arr) {
      if(i < 0) cnt[0 - i] += 1;
    }
    return valid(cnt);
  }
};

// Accepted
// 102/102 cases passed (48 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 16.93 % of cpp submissions (58.9 MB)
```
