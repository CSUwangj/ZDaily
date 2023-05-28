+++
updated = 2023-05-28T16:59:26+08:00
title = "2023-05-28 Daily Challenge"
path = "2023-05-28-Daily-Challenge"
date = 2023-05-28T16:59:26+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/minimum-cost-to-cut-a-stick/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 28

## Description

**Minimum Cost to Cut a Stick**

<p>Given a wooden stick of length <code>n</code> units. The stick is labelled from <code>0</code> to <code>n</code>. For example, a stick of length <strong>6</strong> is labelled as follows:</p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/07/21/statement.jpg" style="width: 521px; height: 111px;" />
<p>Given an integer array <code>cuts</code> where <code>cuts[i]</code> denotes a position you should perform a cut at.</p>

<p>You should perform the cuts in order, you can change the order of the cuts as you wish.</p>

<p>The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). Please refer to the first example for a better explanation.</p>

<p>Return <em>the minimum total cost</em> of the cuts.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/07/23/e1.jpg" style="width: 350px; height: 284px;" />
<pre>
<strong>Input:</strong> n = 7, cuts = [1,3,4,5]
<strong>Output:</strong> 16
<strong>Explanation:</strong> Using cuts order = [1, 3, 4, 5] as in the input leads to the following scenario:
<img alt="" src="https://assets.leetcode.com/uploads/2020/07/21/e11.jpg" style="width: 350px; height: 284px;" />
The first cut is done to a rod of length 7 so the cost is 7. The second cut is done to a rod of length 6 (i.e. the second part of the first cut), the third is done to a rod of length 4 and the last cut is to a rod of length 3. The total cost is 7 + 6 + 4 + 3 = 20.
Rearranging the cuts to be [3, 5, 1, 4] for example will lead to a scenario with total cost = 16 (as shown in the example photo 7 + 4 + 3 + 2 = 16).</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 9, cuts = [5,6,1,4,2]
<strong>Output:</strong> 22
<strong>Explanation:</strong> If you try the given cuts ordering the cost will be 25.
There are much ordering with total cost &lt;= 25, for example, the order [4, 6, 5, 2, 1] has total cost = 22 which is the minimum possible.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= cuts.length &lt;= min(n - 1, 100)</code></li>
	<li><code>1 &lt;= cuts[i] &lt;= n - 1</code></li>
	<li>All the integers in <code>cuts</code> array are <strong>distinct</strong>.</li>
</ul>


## Solution

``` cpp
class Solution {
  vector<vector<int>> dp;
  int solve(
    const vector<int> &cuts,
    int stickLeft,
    int stickRight,
    int cutLeft,
    int cutRight
  ) {
    if(cutLeft >= cutRight) return 0;
    // int pos = lower_bound(cuts.begin() + cutLeft, cuts.begin() + cutRight, (stickLeft + stickRight) / 2) - cuts.begin();
    // int subCost = INT_MAX;
    // cout << cutLeft << ' ' << cutRight << ' ' << stickLeft << ' ' << stickRight << endl;
    // if(pos + 1 < cutRight) {
    //   subCost = min(subCost,
    //     solve(cuts, stickLeft, cuts[pos + 1], cutLeft, pos + 1) + solve(cuts, cuts[pos], stickRight, pos + 2, cutRight));
    // }
    // if(pos < cutRight) {
    //   subCost = min(subCost,
    //     solve(cuts, stickLeft, cuts[pos], cutLeft, pos) + solve(cuts, cuts[pos], stickRight, pos + 1, cutRight));
    // }
    // if(pos > cutLeft) {
    //   subCost = min(subCost,
    //     solve(cuts, stickLeft, cuts[pos - 1], cutLeft, pos - 1) + solve(cuts, cuts[pos - 1], stickRight, pos, cutRight));
    // }
    if(dp[cutLeft][cutRight] != -1) {
      return dp[cutLeft][cutRight];
    }
    int subCost = INT_MAX;
    for(int i = cutLeft; i < cutRight; ++i) {
      subCost = min(subCost,
        solve(cuts, stickLeft, cuts[i], cutLeft, i) + solve(cuts, cuts[i], stickRight, i + 1, cutRight));
    }

    return dp[cutLeft][cutRight] = stickRight - stickLeft + subCost;
  }
public:
  int minCost(int n, vector<int>& cuts) {
    sort(cuts.begin(), cuts.end());
    dp.resize(cuts.size(), vector<int>(cuts.size() + 1, -1));

    return solve(cuts, 0, n, 0, cuts.size());
  }
};

// Accepted
// 100/100 cases passed (137 ms)
// Your runtime beats 12.26 % of cpp submissions
// Your memory usage beats 80.63 % of cpp submissions (10.2 MB)
```
