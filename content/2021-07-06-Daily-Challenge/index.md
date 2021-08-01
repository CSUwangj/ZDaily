+++
title = "2021-07-06 Daily-Challenge"
path = "2021-07-06-Daily-Challenge"
date = 2021-07-06 20:55:33+08:00
updated = 2021-07-06 22:28:30+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Make Sum Divisible by P](https://leetcode.com/problems/make-sum-divisible-by-p/description/) and leetcode's [July LeetCoding Challenge](https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/608/week-1-july-1st-july-7th/3804/) with `cpp`.

<!-- more -->

# Make Sum Divisible by P

## Description

Given an array of positive integers `nums`, remove the **smallest** subarray (possibly **empty**) such that the **sum** of the remaining elements is divisible by `p`. It is **not** allowed to remove the whole array.

Return *the length of the smallest subarray that you need to remove, or* `-1` *if it's impossible*.

A **subarray** is defined as a contiguous block of elements in the array.

 

**Example 1:**

```
Input: nums = [3,1,4,2], p = 6
Output: 1
Explanation: The sum of the elements in nums is 10, which is not divisible by 6. We can remove the subarray [4], and the sum of the remaining elements is 6, which is divisible by 6.
```

**Example 2:**

```
Input: nums = [6,3,5,2], p = 9
Output: 2
Explanation: We cannot remove a single element to get a sum divisible by 9. The best way is to remove the subarray [5,2], leaving us with [6,3] with sum 9.
```

**Example 3:**

```
Input: nums = [1,2,3], p = 3
Output: 0
Explanation: Here the sum is 6. which is already divisible by 3. Thus we do not need to remove anything.
```

**Example 4:**

```
Input: nums = [1,2,3], p = 7
Output: -1
Explanation: There is no way to remove a subarray in order to get a sum divisible by 7.
```

**Example 5:**

```
Input: nums = [1000000000,1000000000,1000000000], p = 3
Output: 0
```

 

**Constraints:**

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^9`
- `1 <= p <= 10^9`

## Solution

``` cpp
class Solution {
public:
  int minSubarray(vector<int>& nums, int p) {
    for(auto &i : nums) i %= p;
    int sum = accumulate(nums.begin(), nums.end(), 0, [=](int a, int b) { 
      return (a + b) % p;
    });
    if(!sum) return 0;
    unordered_map<int, int> prefix{{0, -1}};
    int len = nums.size();
    int invTarget = p - sum;
    int curSum = 0;
    int answer = len;
    for(int i = 0; i < len; ++i) {
      curSum += nums[i];
      curSum %= p;
      if(prefix.count((curSum + invTarget) % p)) {
        answer = min(answer, i - prefix[(curSum + invTarget) % p]);
      }
      prefix[curSum] = i;
    }

    return answer == len ? -1 : answer;
  }
};
```

# July LeetCoding Challenge 6

## Description

**Reduce Array Size to The Half**

Given an array `arr`. You can choose a set of integers and remove all the occurrences of these integers in the array.

Return *the minimum size of the set* so that **at least** half of the integers of the array are removed.

 

**Example 1:**

```
Input: arr = [3,3,3,3,5,5,5,2,2,7]
Output: 2
Explanation: Choosing {3,7} will make the new array [5,5,5,2,2] which has size 5 (i.e equal to half of the size of the old array).
Possible sets of size 2 are {3,5},{3,2},{5,2}.
Choosing set {2,7} is not possible as it will make the new array [3,3,3,3,5,5,5] which has size greater than half of the size of the old array.
```

**Example 2:**

```
Input: arr = [7,7,7,7,7,7]
Output: 1
Explanation: The only possible set you can choose is {7}. This will make the new array empty.
```

**Example 3:**

```
Input: arr = [1,9]
Output: 1
```

**Example 4:**

```
Input: arr = [1000,1000,3,7]
Output: 1
```

**Example 5:**

```
Input: arr = [1,2,3,4,5,6,7,8,9,10]
Output: 5
```

 

**Constraints:**

- `1 <= arr.length <= 10^5`
- `arr.length` is even.
- `1 <= arr[i] <= 10^5`

## Solution

``` cpp
auto speedup = []() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int minSetSize(vector<int>& arr) {
    unordered_map<int, int> cnt;
    for(auto i : arr) cnt[i] += 1;
    vector<int> amount;
    for(auto [_, c] : cnt) amount.push_back(c);
    sort(amount.begin(), amount.end(), greater<int>());
    for(int i = 1; i < amount.size(); ++i) {
      amount[i] += amount[i-1];
    }
    int target = (arr.size() + 1) / 2;
    return lower_bound(amount.begin(), amount.end(), target) - amount.begin() + 1;
  }
};

// Accepted
// 31/31 cases passed (136 ms)
// Your runtime beats 91.3 % of cpp submissions
// Your memory usage beats 47.42 % of cpp submissions (78.4 MB)
```

``` cpp
auto speedup = []() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
int cnt[100001];
class Solution {
public:
  int minSetSize(vector<int>& arr) {
    memset(cnt, 0, sizeof(cnt));
    int maxNum = *max_element(arr.begin(), arr.end());
    for(auto i : arr) cnt[i] += 1;
    int target = arr.size() / 2;
    sort(cnt, cnt + maxNum + 1, greater<int>());
    if(cnt[0] == 1) return target;
    if(cnt[0] > target) return 1;
    int len = 1;
    for(int i = 1; cnt[i]; ++i) {
      cnt[i] += cnt[i - 1];
      len = i; 
    }
    return lower_bound(cnt, cnt + len, target) - cnt + 1;
  }
};

// Accepted
// 31/31 cases passed (72 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 97.93 % of cpp submissions (55.5 MB)
```
