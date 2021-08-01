+++
title = "2020-11-16 Daily-Challenge"
path = "2020-11-16-Daily-Challenge"
date = 2020-11-16 19:38:33+08:00
updated = 2020-11-16 20:02:42+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done *Alert Using Same Key-Card Three or More Times in a One Hour Period* on [leetcode](https://leetcode.com/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/) and leetcode's [November LeetCoding Challenge](https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/566/week-3-november-15th-november-21st/3533/) with `cpp`.

<!-- more -->

# Alert Using Same Key-Card Three or More Times in a One Hour Period

## Description

LeetCode company workers use key-cards to unlock office doors. Each time a worker uses their key-card, the security system saves the worker's name and the time when it was used. The system emits an **alert** if any worker uses the key-card **three or more times** in a one-hour period.

You are given a list of strings `keyName` and `keyTime` where `[keyName[i], keyTime[i]]` corresponds to a person's name and the time when their key-card was used **in a** **single day**.

Access times are given in the **24-hour time format "HH:MM"**, such as `"23:51"` and `"09:49"`.

Return a *list of unique worker names who received an alert for frequent keycard use*. Sort the names in **ascending order alphabetically**.

Notice that `"10:00"` - `"11:00"` is considered to be within a one-hour period, while `"22:51"` - `"23:52"` is not considered to be within a one-hour period.

**Example 1:**

```
Input: keyName = ["daniel","daniel","daniel","luis","luis","luis","luis"], keyTime = ["10:00","10:40","11:00","09:00","11:00","13:00","15:00"]
Output: ["daniel"]
Explanation: "daniel" used the keycard 3 times in a one-hour period ("10:00","10:40", "11:00").
```

**Example 2:**

```
Input: keyName = ["alice","alice","alice","bob","bob","bob","bob"], keyTime = ["12:01","12:00","18:00","21:00","21:20","21:30","23:00"]
Output: ["bob"]
Explanation: "bob" used the keycard 3 times in a one-hour period ("21:00","21:20", "21:30").
```

**Example 3:**

```
Input: keyName = ["john","john","john"], keyTime = ["23:58","23:59","00:01"]
Output: []
```

**Example 4:**

```
Input: keyName = ["leslie","leslie","leslie","clare","clare","clare","clare"], keyTime = ["13:00","13:20","14:00","18:00","18:51","19:30","19:49"]
Output: ["clare","leslie"]
```

**Constraints:**

- `1 <= keyName.length, keyTime.length <= 105`
- `keyName.length == keyTime.length`
- `keyTime[i]` is in the format **"HH:MM"**.
- `[keyName[i], keyTime[i]]` is **unique**.
- `1 <= keyName[i].length <= 10`
- `keyName[i] contains only lowercase English letters.`

## Solution

sliding window, but could be more elegant

``` cpp
class Solution {
    int timeToMinutes(string time) {
        return ((time[0]-'0')*10 + time[1] - '0')*60 + (time[3]-'0')*10 + time[4]-'0';
    }
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        vector<pair<int, string>> key;
        for(int i = 0; i < keyName.size(); ++i) {
            key.push_back(make_pair(timeToMinutes(keyTime[i]), keyName[i]));
        }
        sort(key.begin(), key.end());
        unordered_map<string, int> count;
        queue<pair<int, string>> q;
        set<string> answer;
        for(auto &[time, name] : key) {
            while(q.size() && q.front().first+60 < time) {
                count[q.front().second] -= 1;
                q.pop();
            }
            q.push(make_pair(time, name));
            count[name] += 1;
            if(count[name] > 2) answer.insert(name);
        }
        return vector<string>(answer.begin(), answer.end());
    }
};
```

# November LeetCoding Challenge 16

## Description

**Longest Mountain in Array**

Let's call any (contiguous) subarray B (of A) a *mountain* if the following properties hold:

- `B.length >= 3`
- There exists some `0 < i < B.length - 1` such that `B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]`

(Note that B could be any subarray of A, including the entire array A.)

Given an array `A` of integers, return the length of the longest *mountain*. 

Return `0` if there is no mountain.

**Example 1:**

```
Input: [2,1,4,7,3,2,5]
Output: 5
Explanation: The largest mountain is [1,4,7,3,2] which has length 5.
```

**Example 2:**

```
Input: [2,2,2]
Output: 0
Explanation: There is no mountain.
```

**Note:**

1. `0 <= A.length <= 10000`
2. `0 <= A[i] <= 10000`

**Follow up:**

- Can you solve it using only one pass?
- Can you solve it in `O(1)` space?

## Solution

nothing to say

``` cpp
class Solution {
    int checkMountain(vector<int> &A, int &pos) {
        int len = A.size();
        int start = pos;
        while(pos < len && A[pos] > A[pos-1]) ++pos;
        if(pos == len || A[pos] == A[pos-1]) return 1;
        int top = pos-1;
        while(pos < len && A[pos] < A[pos-1]) ++pos;
        pos -= 1; // end point could be a start point of another mountain
        return pos-start+2;
    }
public:
    int longestMountain(vector<int>& A) {
        int answer = 1;
        int curLength = 1;
        for(int i = 1; i < A.size(); ++i) {
            if(A[i] > A[i-1]) {
                answer = max(answer, checkMountain(A, i));
            }
        }
        return answer > 2 ? answer : 0;
    }
};
```
