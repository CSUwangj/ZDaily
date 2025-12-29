+++
updated = 2025-12-29T23:43:43+01:00
title = "2025-12-29 Daily Challenge"
path = "2025-12-29-Daily-Challenge"
date = 2025-12-29T23:43:43+01:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/pyramid-transition-matrix/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 29

## Description

**Pyramid Transition Matrix**

<p>You are stacking blocks to form a pyramid. Each block has a color, which is represented by a single letter. Each row of blocks contains <strong>one less block</strong> than the row beneath it and is centered on top.</p>

<p>To make the pyramid aesthetically pleasing, there are only specific <strong>triangular patterns</strong> that are allowed. A triangular pattern consists of a <strong>single block</strong> stacked on top of <strong>two blocks</strong>. The patterns are given&nbsp;as a list of&nbsp;three-letter strings <code>allowed</code>, where the first two characters of a pattern represent the left and right bottom blocks respectively, and the third character is the top block.</p>

<ul>
	<li>For example, <code>&quot;ABC&quot;</code> represents a triangular pattern with a <code>&#39;C&#39;</code> block stacked on top of an <code>&#39;A&#39;</code> (left) and <code>&#39;B&#39;</code> (right) block. Note that this is different from <code>&quot;BAC&quot;</code> where <code>&#39;B&#39;</code> is on the left bottom and <code>&#39;A&#39;</code> is on the right bottom.</li>
</ul>

<p>You start with a bottom row of blocks <code>bottom</code>, given as a single string, that you <strong>must</strong> use as the base of the pyramid.</p>

<p>Given <code>bottom</code> and <code>allowed</code>, return <code>true</code><em> if you can build the pyramid all the way to the top such that <strong>every triangular pattern</strong> in the pyramid is in </em><code>allowed</code><em>, or </em><code>false</code><em> otherwise</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/08/26/pyramid1-grid.jpg" style="width: 600px; height: 232px;" />
<pre>
<strong>Input:</strong> bottom = &quot;BCD&quot;, allowed = [&quot;BCC&quot;,&quot;CDE&quot;,&quot;CEA&quot;,&quot;FFF&quot;]
<strong>Output:</strong> true
<strong>Explanation:</strong> The allowed triangular patterns are shown on the right.
Starting from the bottom (level 3), we can build &quot;CE&quot; on level 2 and then build &quot;A&quot; on level 1.
There are three triangular patterns in the pyramid, which are &quot;BCC&quot;, &quot;CDE&quot;, and &quot;CEA&quot;. All are allowed.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/08/26/pyramid2-grid.jpg" style="width: 600px; height: 359px;" />
<pre>
<strong>Input:</strong> bottom = &quot;AAAA&quot;, allowed = [&quot;AAB&quot;,&quot;AAC&quot;,&quot;BCD&quot;,&quot;BBE&quot;,&quot;DEF&quot;]
<strong>Output:</strong> false
<strong>Explanation:</strong> The allowed triangular patterns are shown on the right.
Starting from the bottom (level 4), there are multiple ways to build level 3, but trying all the possibilites, you will get always stuck before building level 1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= bottom.length &lt;= 6</code></li>
	<li><code>0 &lt;= allowed.length &lt;= 216</code></li>
	<li><code>allowed[i].length == 3</code></li>
	<li>The letters in all input strings are from the set <code>{&#39;A&#39;, &#39;B&#39;, &#39;C&#39;, &#39;D&#39;, &#39;E&#39;, &#39;F&#39;}</code>.</li>
	<li>All the values of <code>allowed</code> are <strong>unique</strong>.</li>
</ul>


## Solution

``` cpp
int encode(string p) {
  return (p[0] - 'A') * 36 + (p[1] - 'A') * 6 + p[2] - 'A';
}
class Solution {
  bool valid[6 * 6 * 6] = {};
  bool createString(string &s, string &current) {
    int lenS = s.length();
    int lenC = current.length();
    if(lenS == lenC + 1) {
      if(current.size() == 1) return true;
      string next;
      return createString(current, next);
    }
    int toTest = encode(s.substr(lenC, 2) + 'A');
    for(int i = 0; i < 6; ++i) {
      if(!valid[toTest + i]) continue;
      current.push_back('A' + i);
      if(createString(s, current)) return true;
      current.pop_back();
    }
    return false;
  }
public:
  bool pyramidTransition(string bottom, vector<string>& allowed) {
    for(const auto &a : allowed) {
      valid[encode(a)] = true;
    }
    string next;
    return createString(bottom, next);
  }
};

// Accepted
// 63/63 cases passed (1270 ms)
// Your runtime beats 25.95 % of cpp submissions
// Your memory usage beats 92.43 % of cpp submissions (11.7 MB)
```
