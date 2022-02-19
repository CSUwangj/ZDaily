+++
title = "2022-02-19 Daily-Challenge"
path = "2022-02-19-Daily-Challenge"
date = 2022-02-19 12:00:00+08:00
updated = 2022-02-19 12:18:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/minimize-deviation-in-array/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 19

## Description

**Minimize Deviation in Array**

You are given an array `nums` of `n` positive integers.

You can perform two types of operations on any element of the array any number of times:

- If the element is 

  even

  , 

  divide

   it by 

  ```
  2
  ```

  . 	

  - For example, if the array is `[1,2,3,4]`, then you can do this operation on the last element, and the array will be `[1,2,3,2].`

- If the element is 

  odd

  , 

  multiply

   it by 

  ```
  2
  ```

  . 

  - For example, if the array is `[1,2,3,4]`, then you can do this operation on the first element, and the array will be `[2,2,3,4].`

The **deviation** of the array is the **maximum difference** between any two elements in the array.

Return *the **minimum deviation** the array can have after performing some number of operations.*

 

**Example 1:**

```
Input: nums = [1,2,3,4]
Output: 1
Explanation: You can transform the array to [1,2,3,2], then to [2,2,3,2], then the deviation will be 3 - 2 = 1.
```

**Example 2:**

```
Input: nums = [4,1,5,20,3]
Output: 3
Explanation: You can transform the array after two operations to [4,2,5,5,3], then the deviation will be 5 - 2 = 3.
```

**Example 3:**

```
Input: nums = [2,10,8]
Output: 3
```

 

**Constraints:**

- `n == nums.length`
- `2 <= n <= 10^5`
- `1 <= nums[i] <= 10^9`

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
  int minimumDeviation(vector<int>& nums) {
    set<int> st;
    for(auto i : nums) {
      st.insert((i & 1) ? (i << 1) : i);
    }
    
    int answer = *st.rbegin() - *st.begin();
    while(*st.rbegin() % 2 == 0) {
      st.insert(*st.rbegin() >> 1);
      st.erase(*st.rbegin());
      answer = min(answer, *st.rbegin() - *st.begin());
    }
    return answer;
  }
};

// Accepted
// 76/76 cases passed (503 ms)
// Your runtime beats 26.49 % of cpp submissions
// Your memory usage beats 9.93 % of cpp submissions (122.2 MB)
```
