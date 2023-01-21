+++
updated = 2023-01-21T13:57:03+08:00
title = "2023-01-21 Daily Challenge"
path = "2023-01-21-Daily-Challenge"
date = 2023-01-21T13:57:03+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/restore-ip-addresses/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 21

## Description

**Restore IP Addresses**

<p>A <strong>valid IP address</strong> consists of exactly four integers separated by single dots. Each integer is between <code>0</code> and <code>255</code> (<strong>inclusive</strong>) and cannot have leading zeros.</p>

<ul>
	<li>For example, <code>&quot;0.1.2.201&quot;</code> and <code>&quot;192.168.1.1&quot;</code> are <strong>valid</strong> IP addresses, but <code>&quot;0.011.255.245&quot;</code>, <code>&quot;192.168.1.312&quot;</code> and <code>&quot;192.168@1.1&quot;</code> are <strong>invalid</strong> IP addresses.</li>
</ul>

<p>Given a string <code>s</code> containing only digits, return <em>all possible valid IP addresses that can be formed by inserting dots into </em><code>s</code>. You are <strong>not</strong> allowed to reorder or remove any digits in <code>s</code>. You may return the valid IP addresses in <strong>any</strong> order.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;25525511135&quot;
<strong>Output:</strong> [&quot;255.255.11.135&quot;,&quot;255.255.111.35&quot;]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;0000&quot;
<strong>Output:</strong> [&quot;0.0.0.0&quot;]
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;101023&quot;
<strong>Output:</strong> [&quot;1.0.10.23&quot;,&quot;1.0.102.3&quot;,&quot;10.1.0.23&quot;,&quot;10.10.2.3&quot;,&quot;101.0.2.3&quot;]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 20</code></li>
	<li><code>s</code> consists of digits only.</li>
</ul>


## Solution

``` cpp
class Solution {
  int len;
  int minmax[4][2] = {{}, {-1, 10}, {9, 100}, {99, 256}};
  void addIP(
    vector<string> &answer,
    vector<string> &currentIP
  ) {
    string ip;
    for(auto subnet : currentIP) {
      ip += subnet;
      ip.push_back('.');
    }
    ip.pop_back();
    answer.emplace_back(ip);
  }
  void dfs(
    vector<string> &answer,
    vector<string> &currentIP,
    string &s,
    int pos
  ) {
    if(pos == len) {
      if(currentIP.size() == 4) addIP(answer, currentIP);
      return;
    }
    for(int i = 1; i < 4 && pos + i <= s.length(); ++i) {
      string subnet = s.substr(pos, i);
      int n = stoi(subnet);
      if(n <= minmax[i][0]) break;
      if(n < minmax[i][1]) {
        currentIP.emplace_back(subnet);
        dfs(answer, currentIP, s, pos + i);
        currentIP.pop_back();
      }
    }
  }
public:
  vector<string> restoreIpAddresses(string s) {
    len = s.length();
    vector<string> answer;
    vector<string> ip;
    dfs(answer, ip, s, 0);
    return answer;
  }
};

// Accepted
// 145/145 cases passed (8 ms)
// Your runtime beats 19.08 % of cpp submissions
// Your memory usage beats 70.83 % of cpp submissions (6.6 MB)
```
