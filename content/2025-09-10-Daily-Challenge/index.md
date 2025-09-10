+++
updated = 2025-09-10T23:27:26+02:00
title = "2025-09-10 Daily Challenge"
path = "2025-09-10-Daily-Challenge"
date = 2025-09-10T23:27:26+02:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/minimum-number-of-people-to-teach/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 10

## Description

**Minimum Number of People to Teach**

<p>On a social network consisting of <code>m</code> users and some friendships between users, two users can communicate with each other if they know a common language.</p>

<p>You are given an integer <code>n</code>, an array <code>languages</code>, and an array <code>friendships</code> where:</p>

<ul>
	<li>There are <code>n</code> languages numbered <code>1</code> through <code>n</code>,</li>
	<li><code>languages[i]</code> is the set of languages the <code>i<sup>​​​​​​th</sup></code>​​​​ user knows, and</li>
	<li><code>friendships[i] = [u<sub>​​​​​​i</sub>​​​, v<sub>​​​​​​i</sub>]</code> denotes a friendship between the users <code>u<sup>​​​​​</sup><sub>​​​​​​i</sub></code>​​​​​ and <code>v<sub>i</sub></code>.</li>
</ul>

<p>You can choose <strong>one</strong> language and teach it to some users so that all friends can communicate with each other. Return <i data-stringify-type="italic">the</i> <i><strong>minimum</strong> </i><i data-stringify-type="italic">number of users you need to teach.</i></p>
Note that friendships are not transitive, meaning if <code>x</code> is a friend of <code>y</code> and <code>y</code> is a friend of <code>z</code>, this doesn't guarantee that <code>x</code> is a friend of <code>z</code>.
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> n = 2, languages = [[1],[2],[1,2]], friendships = [[1,2],[1,3],[2,3]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> You can either teach user 1 the second language or user 2 the first language.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> n = 3, languages = [[2],[1,3],[1,2],[3]], friendships = [[1,4],[1,2],[3,4],[2,3]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> Teach the third language to users 1 and 3, yielding two users to teach.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 500</code></li>
	<li><code>languages.length == m</code></li>
	<li><code>1 &lt;= m &lt;= 500</code></li>
	<li><code>1 &lt;= languages[i].length &lt;= n</code></li>
	<li><code>1 &lt;= languages[i][j] &lt;= n</code></li>
	<li><code>1 &lt;= u<sub>​​​​​​i</sub> &lt; v<sub>​​​​​​i</sub> &lt;= languages.length</code></li>
	<li><code>1 &lt;= friendships.length &lt;= 500</code></li>
	<li>All tuples <code>(u<sub>​​​​​i, </sub>v<sub>​​​​​​i</sub>)</code> are unique</li>
	<li><code>languages[i]</code> contains only unique values</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
    int m = languages.size();
    vector<unordered_set<int>> lang(m+1);
    for(int i = 0; i < m; ++i) {
      lang[i+1] = unordered_set<int>(languages[i].begin(), languages[i].end());
    }
    vector<bool> sat;
    for(auto &f : friendships) {
      bool s = false;
      for(auto l : lang[f[0]]) {
        if(lang[f[1]].count(l)) {
          sat.push_back(true);
          s = true;
          break;
        }
      }
      if(!s) sat.push_back(false);
      
    }
    int answer = m;
    for(int i = 1; i <= n; ++i) {
      int cnt = 0;
      for(int j = 0; j < friendships.size(); ++j) {
        if(sat[j]) continue;
        // cout << friendships[j][0] << ' ' << friendships[j][1] << endl;
        cnt += !lang[friendships[j][0]].count(i);
        cnt += !lang[friendships[j][1]].count(i);
        lang[friendships[j][0]].insert(i);
        lang[friendships[j][1]].insert(i);
      }
      answer = min(answer, cnt);
    }
    return answer;
  }
};

// Accepted
// 100/100 cases passed (288 ms)
// Your runtime beats 10.59 % of cpp submissions
// Your memory usage beats 17.65 % of cpp submissions (152.3 MB)
```
