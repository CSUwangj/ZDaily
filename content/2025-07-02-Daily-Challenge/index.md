+++
updated = 2025-07-02T14:23:35+08:00
title = "2025-07-02 Daily Challenge"
path = "2025-07-02-Daily-Challenge"
date = 2025-07-02T14:23:35+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/find-the-original-typed-string-ii/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 2

## Description

**Find the Original Typed String II**

<p>Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and <strong>may</strong> press a key for too long, resulting in a character being typed <strong>multiple</strong> times.</p>

<p>You are given a string <code>word</code>, which represents the <strong>final</strong> output displayed on Alice's screen. You are also given a <strong>positive</strong> integer <code>k</code>.</p>

<p>Return the total number of <em>possible</em> original strings that Alice <em>might</em> have intended to type, if she was trying to type a string of size <strong>at least</strong> <code>k</code>.</p>

<p>Since the answer may be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">word = "aabbccdd", k = 7</span></p>

<p><strong>Output:</strong> <span class="example-io">5</span></p>

<p><strong>Explanation:</strong></p>

<p>The possible strings are: <code>"aabbccdd"</code>, <code>"aabbccd"</code>, <code>"aabbcdd"</code>, <code>"aabccdd"</code>, and <code>"abbccdd"</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">word = "aabbccdd", k = 8</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<p>The only possible string is <code>"aabbccdd"</code>.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">word = "aaabbb", k = 3</span></p>

<p><strong>Output:</strong> <span class="example-io">8</span></p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 5 * 10<sup>5</sup></code></li>
	<li><code>word</code> consists only of lowercase English letters.</li>
	<li><code>1 &lt;= k &lt;= 2000</code></li>
</ul>


## Solution

``` cpp
class Solution {
  const int MOD = 1e9 + 7;
public:
  int possibleStringCount(string word, int k) {
    int count = 0;
    long long total = 1;
    vector<int> counts;
    char prev = word.front();
    for(auto c : word) {
      if(c == prev) {
        count += 1;
        continue;
      }
      counts.push_back(count);
      total *= count;
      total %= MOD;
      count = 1;
      prev = c;
    }
    counts.push_back(count);
    total *= count;
    total %= MOD;
    
    vector<vector<int>> dp(2, vector<int>(k + 1, 0));
    for(int i = 1; i <= min(counts.front(), k - 1); ++i) dp[0][i] = 1;
    vector<int> prefix(k + 1, 0);
    int segs = counts.size();

    for(int i = 1; i < min(segs, k); ++i) {
      int parity = (i & 1);
      prefix[0] = dp[!parity][0];
      for(int j = 1; j <= k; ++j) {
        prefix[j] = (prefix[j - 1] + dp[!parity][j]) % MOD;
      }

      for(int j = 1; j <= k; ++j) {
        int pos = max(i, j - counts[i]);
        dp[parity][j] = (prefix[j - 1] - prefix[pos - 1] + MOD) % MOD;
      }
    }

    int notValid = 0;
    int parity = !(min(segs, k) & 1);
    for(int i = 0; i < k; ++i) {
      notValid += dp[parity][i];
      notValid %= MOD;
    }
    return (total - notValid + MOD) % MOD;
  }
};

// Accepted
// 846/846 cases passed (656 ms)
// Your runtime beats 10.46 % of cpp submissions
// Your memory usage beats 47.67 % of cpp submissions (80 MB)
```
