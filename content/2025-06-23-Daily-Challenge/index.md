+++
updated = 2025-06-24T05:51:13+08:00
title = "2025-06-23 Daily Challenge"
path = "2025-06-23-Daily-Challenge"
date = 2025-06-24T05:51:13+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/sum-of-k-mirror-numbers/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 23

## Description

**Sum of k-Mirror Numbers**

<p>A <strong>k-mirror number</strong> is a <strong>positive</strong> integer <strong>without leading zeros</strong> that reads the same both forward and backward in base-10 <strong>as well as</strong> in base-k.</p>

<ul>
	<li>For example, <code>9</code> is a 2-mirror number. The representation of <code>9</code> in base-10 and base-2 are <code>9</code> and <code>1001</code> respectively, which read the same both forward and backward.</li>
	<li>On the contrary, <code>4</code> is not a 2-mirror number. The representation of <code>4</code> in base-2 is <code>100</code>, which does not read the same both forward and backward.</li>
</ul>

<p>Given the base <code>k</code> and the number <code>n</code>, return <em>the <strong>sum</strong> of the</em> <code>n</code> <em><strong>smallest</strong> k-mirror numbers</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> k = 2, n = 5
<strong>Output:</strong> 25
<strong>Explanation:
</strong>The 5 smallest 2-mirror numbers and their representations in base-2 are listed as follows:
  base-10    base-2
    1          1
    3          11
    5          101
    7          111
    9          1001
Their sum = 1 + 3 + 5 + 7 + 9 = 25. 
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> k = 3, n = 7
<strong>Output:</strong> 499
<strong>Explanation:
</strong>The 7 smallest 3-mirror numbers are and their representations in base-3 are listed as follows:
  base-10    base-3
    1          1
    2          2
    4          11
    8          22
    121        11111
    151        12121
    212        21212
Their sum = 1 + 2 + 4 + 8 + 121 + 151 + 212 = 499.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> k = 7, n = 17
<strong>Output:</strong> 20379000
<strong>Explanation:</strong> The 17 smallest 7-mirror numbers are:
1, 2, 3, 4, 5, 6, 8, 121, 171, 242, 292, 16561, 65656, 2137312, 4602064, 6597956, 6958596
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= k &lt;= 9</code></li>
	<li><code>1 &lt;= n &lt;= 30</code></li>
</ul>


## Solution

``` cpp
class Solution {
  static constexpr long long ans[][30] = {
    {1,     3,     5,    7,     9,     33,
     99,    313,   585,    717,     7447,    9009,
     15351,   32223,   39993,  53235,   53835,   73737,
     585585,  1758571, 1934391,  1979791,   3129213,   5071705,
     5259525, 5841485, 13500531, 719848917, 910373019, 939474939},
    {1,     2,     4,     8,     121,    151,
     212,   242,   484,   656,   757,    29092,
     48884,   74647,   75457,   76267,   92929,  93739,
     848848,  1521251, 2985892, 4022204, 4219124,  4251524,
     4287824, 5737375, 7875787, 7949497, 27711772, 83155138},
    {1,     2,     3,    5,     55,    373,
     393,   666,   787,    939,     7997,    53235,
     55255,   55655,   57675,  506605,  1801081,   2215122,
     3826283, 3866683, 5051505,  5226225,   5259525,   5297925,
     5614165, 5679765, 53822835, 623010326, 954656459, 51717171715},
    {1,      2,      3,      4,       6,
     88,     252,    282,    626,     676,
     1221,     15751,    18881,    10088001,  10400401,
     27711772,   30322303,   47633674,   65977956,  808656808,
     831333138,  831868138,  836131638,  836181638,   2512882152,
     2596886952, 2893553982, 6761551676, 12114741121, 12185058121},
    {1,     2,     3,     4,     5,     7,    55,   111,
     141,   191,   343,   434,   777,   868,  1441,   7667,
     7777,  22022,   39893,   74647,   168861,  808808, 909909, 1867681,
     3097903, 4232324, 4265624, 4298924, 4516154, 4565654},
    {1,       2,       3,       4,       5,
     6,       8,       121,     171,     242,
     292,     16561,     65656,     2137312,   4602064,
     6597956,   6958596,   9470749,   61255216,  230474032,
     466828664,   485494584,   638828836,   657494756,   858474858,
     25699499652, 40130703104, 45862226854, 61454945416, 64454545446},
    {1,    2,     3,     4,     5,     6,     7,    9,
     121,  292,   333,   373,   414,   585,   3663,   8778,
     13131,  13331,   26462,   26662,   30103,   30303,   207702, 628826,
     660066, 1496941, 1935391, 1970791, 4198914, 55366355},
    {1,     2,     3,     4,     5,     6,     7,     8,
     191,   282,   373,   464,   555,   646,   656,   6886,
     25752,   27472,   42324,   50605,   626626,  1540451, 1713171, 1721271,
     1828281, 1877781, 1885881, 2401042, 2434342, 2442442}};
public:
  long long kMirror(int k, int n) {
    return accumulate(ans[k - 2], ans[k - 2] + n, 0LL);
  }
};

// Accepted
// 97/97 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 91.3 % of cpp submissions (7.9 MB)
```
