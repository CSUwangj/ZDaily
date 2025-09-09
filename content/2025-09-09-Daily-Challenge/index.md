+++
updated = 2025-09-09T23:27:26+02:00
title = "2025-09-09 Daily Challenge"
path = "2025-09-09-Daily-Challenge"
date = 2025-09-09T23:27:26+02:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/number-of-people-aware-of-a-secret/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 9

## Description

**Number of People Aware of a Secret**

<p>On day <code>1</code>, one person discovers a secret.</p>

<p>You are given an integer <code>delay</code>, which means that each person will <strong>share</strong> the secret with a new person <strong>every day</strong>, starting from <code>delay</code> days after discovering the secret. You are also given an integer <code>forget</code>, which means that each person will <strong>forget</strong> the secret <code>forget</code> days after discovering it. A person <strong>cannot</strong> share the secret on the same day they forgot it, or on any day afterwards.</p>

<p>Given an integer <code>n</code>, return<em> the number of people who know the secret at the end of day </em><code>n</code>. Since the answer may be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 6, delay = 2, forget = 4
<strong>Output:</strong> 5
<strong>Explanation:</strong>
Day 1: Suppose the first person is named A. (1 person)
Day 2: A is the only person who knows the secret. (1 person)
Day 3: A shares the secret with a new person, B. (2 people)
Day 4: A shares the secret with a new person, C. (3 people)
Day 5: A forgets the secret, and B shares the secret with a new person, D. (3 people)
Day 6: B shares the secret with E, and C shares the secret with F. (5 people)
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 4, delay = 1, forget = 3
<strong>Output:</strong> 6
<strong>Explanation:</strong>
Day 1: The first person is named A. (1 person)
Day 2: A shares the secret with B. (2 people)
Day 3: A and B share the secret with 2 new people, C and D. (4 people)
Day 4: A forgets the secret. B, C, and D share the secret with 3 new people. (6 people)
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= delay &lt; forget &lt;= n</code></li>
</ul>


## Solution

``` cpp
class Solution {
  const int MOD = 1e9 + 7;
public:
  int peopleAwareOfSecret(int n, int delay, int forget) {
    int sz = forget + 1;
    vector<int> newPerson(sz);
    newPerson[1] = 1;
    int afterDelay = 0;
    for(int i = 2; i <= n; ++i) {
      afterDelay += newPerson[(i - delay + sz) % sz] - newPerson[(i + 1) % sz];
      afterDelay %= MOD;
      afterDelay += MOD;
      afterDelay %= MOD;
      newPerson[i % sz] = afterDelay;
    }
    int answer = 0;
    for(int i = n - forget + 1; i <= n; i++){
      answer += newPerson[i % sz];
      answer %= MOD;
    }
    return answer;
  }
};

// Accepted
// 82/82 cases passed (1 ms)
// Your runtime beats 68.54 % of cpp submissions
// Your memory usage beats 69.82 % of cpp submissions (9.4 MB)
```
