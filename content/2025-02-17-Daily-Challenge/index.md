+++
updated = 2025-02-17T15:34:06+08:00
title = "2025-02-17 Daily Challenge"
path = "2025-02-17-Daily-Challenge"
date = 2025-02-17T15:34:06+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/letter-tile-possibilities/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 17

## Description

**Letter Tile Possibilities**

<p>You have <code>n</code>&nbsp;&nbsp;<code>tiles</code>, where each tile has one letter <code>tiles[i]</code> printed on it.</p>

<p>Return <em>the number of possible non-empty sequences of letters</em> you can make using the letters printed on those <code>tiles</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> tiles = &quot;AAB&quot;
<strong>Output:</strong> 8
<strong>Explanation: </strong>The possible sequences are &quot;A&quot;, &quot;B&quot;, &quot;AA&quot;, &quot;AB&quot;, &quot;BA&quot;, &quot;AAB&quot;, &quot;ABA&quot;, &quot;BAA&quot;.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> tiles = &quot;AAABBC&quot;
<strong>Output:</strong> 188
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> tiles = &quot;V&quot;
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= tiles.length &lt;= 7</code></li>
	<li><code>tiles</code> consists of uppercase English letters.</li>
</ul>


## Solution

``` cpp
class Solution {
  int permutation[8] = {1, 1, 2, 6, 24, 120, 720, 5040};
  int answer = 0;
  map<char, int> mp;
  
  int result(vector<int> &chars, int len) {
    int res = permutation[len];
    for(auto cnt : chars) res /= permutation[cnt];
    return res;
  }
  
  void helper(map<char, int>::iterator &it, vector<int> chars, int len, int count) {
    if(it == mp.end()) {
      if(count == len) answer += result(chars, len);
      return;
    }
    
    for(int i = 0; i <= it->second; ++i) {
      chars.push_back(i);
      ++it;
      helper(it, chars, len, count + i);
      --it;
      chars.pop_back();
    }
  }
public:
  int numTilePossibilities(string tiles) {
    for(auto c : tiles) mp[c] += 1;
    vector<int> tmp;
    auto tmpIt = mp.begin();
    for(int i = 1; i <= tiles.length(); ++i) {
      helper(tmpIt, tmp, i, 0);
    }
    return answer;
  }
};

// Accepted
// 86/86 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 53.21 % of cpp submissions (10.7 MB)
```
