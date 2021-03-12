+++
title = "2021-03-12 Daily-Challenge"
path = "2021-03-12-Daily-Challenge"
date = 2021-03-12 11:03:31+08:00
updated = 2021-03-12 21:30:02+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Find Servers That Handled Most Number of Requests](https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/) and leetcode's [March LeetCoding Challenge](https://leetcode.com/explore/featured/card/march-leetcoding-challenge-2021/588/week-1-march-1st-march-7th/3657/) with `cpp`.

<!-- more -->

# Find Servers That Handled Most Number of Requests

## Description

You have `k` servers numbered from `0` to `k-1` that are being used to handle multiple requests simultaneously. Each server has infinite computational capacity but **cannot handle more than one request at a time**. The requests are assigned to servers according to a specific algorithm:

- The `ith` (0-indexed) request arrives.
- If all servers are busy, the request is dropped (not handled at all).
- If the `(i % k)th` server is available, assign the request to that server.
- Otherwise, assign the request to the next available server (wrapping around the list of servers and starting from 0 if necessary). For example, if the `ith` server is busy, try to assign the request to the `(i+1)th` server, then the `(i+2)th` server, and so on.

You are given a **strictly increasing** array `arrival` of positive integers, where `arrival[i]` represents the arrival time of the `ith` request, and another array `load`, where `load[i]` represents the load of the `ith` request (the time it takes to complete). Your goal is to find the **busiest server(s)**. A server is considered **busiest** if it handled the most number of requests successfully among all the servers.

Return *a list containing the IDs (0-indexed) of the **busiest server(s)***. You may return the IDs in any order.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/09/08/load-1.png)

```
Input: k = 3, arrival = [1,2,3,4,5], load = [5,2,3,3,3] 
Output: [1] 
Explanation:
All of the servers start out available.
The first 3 requests are handled by the first 3 servers in order.
Request 3 comes in. Server 0 is busy, so it's assigned to the next available server, which is 1.
Request 4 comes in. It cannot be handled since all servers are busy, so it is dropped.
Servers 0 and 2 handled one request each, while server 1 handled two requests. Hence server 1 is the busiest server.
```

**Example 2:**

```
Input: k = 3, arrival = [1,2,3,4], load = [1,2,1,2]
Output: [0]
Explanation:
The first 3 requests are handled by first 3 servers.
Request 3 comes in. It is handled by server 0 since the server is available.
Server 0 handled two requests, while servers 1 and 2 handled one request each. Hence server 0 is the busiest server.
```

**Example 3:**

```
Input: k = 3, arrival = [1,2,3], load = [10,12,11]
Output: [0,1,2]
Explanation: Each server handles a single request, so they are all considered the busiest.
```

**Example 4:**

```
Input: k = 3, arrival = [1,2,3,4,8,9,10], load = [5,2,10,3,1,2,2]
Output: [1]
```

**Example 5:**

```
Input: k = 1, arrival = [1], load = [1]
Output: [0]
```

 

**Constraints:**

- $1 \le k \le 10^5$
- $1 \le arrival.length, load.length \le 10^5$
- $arrival.length == load.length$
- $1 \le arrival[i], load[i] \le 10^9$
- `arrival` is **strictly increasing**.

## Solution

writing code on phone is not comfortable, but I finally managed to get AC at first time!

``` cpp
class Solution {
public:
  vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
    using pii = pair<int, int>;
    int len = arrival.size();
    set<int> ok;
    for(int i = 0; i < k; ++i) ok.insert(i);
    priority_queue<pii, vector<pii>, greater<pii>> q;
    vector<int> count(k);
    for(int i = 0; i < len; ++i) {
      while(!q.empty() && q.top().first <= arrival[i]) {
        ok.insert(q.top().second);
        q.pop();
      }
      if(ok.empty()) continue;
      auto it = ok.lower_bound(i % k);
      int pos = (it == ok.end() ? *(ok.begin()) : *it);
      ok.erase(pos);
      q.push(make_pair(arrival[i] + load[i], pos));
      count[pos] += 1;
    }
    
    int mmax = *max_element(count.begin(), count.end());
    vector<int> answer;
    for(int i = 0; i < k; ++i) {
      if(count[i] == mmax) answer.push_back(i);
    }
    return move(answer);
  }
};
```

# March LeetCoding Challenge12

**Check If a String Contains All Binary Codes of Size K**

## Description

Given a binary string `s` and an integer `k`.

Return *True* if every binary code of length `k` is a substring of `s`. Otherwise, return *False*.

 

**Example 1:**

```
Input: s = "00110110", k = 2
Output: true
Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indicies 0, 1, 3 and 2 respectively.
```

**Example 2:**

```
Input: s = "00110", k = 2
Output: true
```

**Example 3:**

```
Input: s = "0110", k = 1
Output: true
Explanation: The binary codes of length 1 are "0" and "1", it is clear that both exist as a substring. 
```

**Example 4:**

```
Input: s = "0110", k = 2
Output: false
Explanation: The binary code "00" is of length 2 and doesn't exist in the array.
```

**Example 5:**

```
Input: s = "0000000001011100", k = 4
Output: false
```

 

**Constraints:**

- `1 <= s.length <= 5 * 10^5`
- `s` consists of 0's and 1's only.
- `1 <= k <= 20`

## Solution

``` cpp
class Solution {
public:
  bool hasAllCodes(string s, int k) {
    int len = s.length();
    if((1 << k) > len - k + 1) return false;
    int cur = 0;
    const int MASK = (1 << k) - 1;
    vector<bool> has(1 << k);
    for(int i = 0; i < k; ++i) {
      cur <<= 1;
      cur |= (s[i] == '1');
    }
    has[cur] = true;
    for(int i = k; i < len; ++i) {
      cur <<= 1;
      cur |= (s[i] == '1');
      cur &= MASK;
      has[cur] = true;
    }
    for(auto b : has) if(!b) return false;
    return true;
  }
};
```
