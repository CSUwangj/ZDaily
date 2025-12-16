+++
updated = 2025-12-16T09:32:02+01:00
title = "2025-12-16 Daily Challenge"
path = "2025-12-16-Daily-Challenge"
date = 2025-12-16T09:32:02+01:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/maximum-profit-from-trading-stocks-with-discounts/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 16

## Description

**Maximum Profit from Trading Stocks with Discounts**

<p>You are given an integer <code>n</code>, representing the number of employees in a company. Each employee is assigned a unique ID from 1 to <code>n</code>, and employee 1 is the CEO. You are given two <strong>1-based </strong>integer arrays, <code>present</code> and <code>future</code>, each of length <code>n</code>, where:</p>

<ul>
	<li><code>present[i]</code> represents the <strong>current</strong> price at which the <code>i<sup>th</sup></code> employee can buy a stock today.</li>
	<li><code>future[i]</code> represents the <strong>expected</strong> price at which the <code>i<sup>th</sup></code> employee can sell the stock tomorrow.</li>
</ul>

<p>The company&#39;s hierarchy is represented by a 2D integer array <code>hierarchy</code>, where <code>hierarchy[i] = [u<sub>i</sub>, v<sub>i</sub>]</code> means that employee <code>u<sub>i</sub></code> is the direct boss of employee <code>v<sub>i</sub></code>.</p>

<p>Additionally, you have an integer <code>budget</code> representing the total funds available for investment.</p>

<p>However, the company has a discount policy: if an employee&#39;s direct boss purchases their own stock, then the employee can buy their stock at <strong>half</strong> the original price (<code>floor(present[v] / 2)</code>).</p>

<p>Return the <strong>maximum</strong> profit that can be achieved without exceeding the given budget.</p>

<p><strong>Note:</strong></p>

<ul>
	<li>You may buy each stock at most <strong>once</strong>.</li>
	<li>You <strong>cannot</strong> use any profit earned from future stock prices to fund additional investments and must buy only from <code>budget</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 2, present = [1,2], future = [4,3], hierarchy = [[1,2]], budget = 3</span></p>

<p><strong>Output:</strong> <span class="example-io">5</span></p>

<p><strong>Explanation:</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2025/04/09/screenshot-2025-04-10-at-053641.png" style="width: 200px; height: 80px;" /></p>

<ul>
	<li>Employee 1 buys the stock at price 1 and earns a profit of <code>4 - 1 = 3</code>.</li>
	<li>Since Employee 1 is the direct boss of Employee 2, Employee 2 gets a discounted price of <code>floor(2 / 2) = 1</code>.</li>
	<li>Employee 2 buys the stock at price 1 and earns a profit of <code>3 - 1 = 2</code>.</li>
	<li>The total buying cost is <code>1 + 1 = 2 &lt;= budget</code>. Thus, the maximum total profit achieved is <code>3 + 2 = 5</code>.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 2, present = [3,4], future = [5,8], hierarchy = [[1,2]], budget = 4</span></p>

<p><strong>Output:</strong> <span class="example-io">4</span></p>

<p><strong>Explanation:</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2025/04/09/screenshot-2025-04-10-at-053641.png" style="width: 200px; height: 80px;" /></p>

<ul>
	<li>Employee 2 buys the stock at price 4 and earns a profit of <code>8 - 4 = 4</code>.</li>
	<li>Since both employees cannot buy together, the maximum profit is 4.</li>
</ul>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 3, present = [4,6,8], future = [7,9,11], hierarchy = [[1,2],[1,3]], budget = 10</span></p>

<p><strong>Output:</strong> 10</p>

<p><strong>Explanation:</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2025/04/09/image.png" style="width: 180px; height: 153px;" /></p>

<ul>
	<li>Employee 1 buys the stock at price 4 and earns a profit of <code>7 - 4 = 3</code>.</li>
	<li>Employee 3 would get a discounted price of <code>floor(8 / 2) = 4</code> and earns a profit of <code>11 - 4 = 7</code>.</li>
	<li>Employee 1 and Employee 3 buy their stocks at a total cost of <code>4 + 4 = 8 &lt;= budget</code>. Thus, the maximum total profit achieved is <code>3 + 7 = 10</code>.</li>
</ul>
</div>

<p><strong class="example">Example 4:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 3, present = [5,2,3], future = [8,5,6], hierarchy = [[1,2],[2,3]], budget = 7</span></p>

<p><strong>Output:</strong> <span class="example-io">12</span></p>

<p><strong>Explanation:</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2025/04/09/screenshot-2025-04-10-at-054114.png" style="width: 300px; height: 85px;" /></p>

<ul>
	<li>Employee 1 buys the stock at price 5 and earns a profit of <code>8 - 5 = 3</code>.</li>
	<li>Employee 2 would get a discounted price of <code>floor(2 / 2) = 1</code> and earns a profit of <code>5 - 1 = 4</code>.</li>
	<li>Employee 3 would get a discounted price of <code>floor(3 / 2) = 1</code> and earns a profit of <code>6 - 1 = 5</code>.</li>
	<li>The total cost becomes <code>5 + 1 + 1 = 7&nbsp;&lt;= budget</code>. Thus, the maximum total profit achieved is <code>3 + 4 + 5 = 12</code>.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 160</code></li>
	<li><code>present.length, future.length == n</code></li>
	<li><code>1 &lt;= present[i], future[i] &lt;= 50</code></li>
	<li><code>hierarchy.length == n - 1</code></li>
	<li><code>hierarchy[i] == [u<sub>i</sub>, v<sub>i</sub>]</code></li>
	<li><code>1 &lt;= u<sub>i</sub>, v<sub>i</sub> &lt;= n</code></li>
	<li><code>u<sub>i</sub> != v<sub>i</sub></code></li>
	<li><code>1 &lt;= budget &lt;= 160</code></li>
	<li>There are no duplicate edges.</li>
	<li>Employee 1 is the direct or indirect boss of every employee.</li>
	<li>The input graph <code>hierarchy </code>is <strong>guaranteed</strong> to have no cycles.</li>
</ul>


## Solution

``` cpp
class Solution {
  static constexpr int N = 161;
  vector<vector<int>> children;
  int DP[N][2][2][N] = {};
  vector<bool> visit;
  int profit[N][2] = {};
  void init(int n, const vector<vector<int>>& hierarchy) {
    children.resize(n + 2);
    for(const auto &e : hierarchy) {
      children[e[0] - 1].push_back(e[1] - 1);
    }
    visit.resize(n * 4);
  }

  void dfs(
    int current,
    bool bossBuy,
    bool buy,
    int budget,
    const vector<int> &present
  ) {
    if(visit[(current << 2) | (bossBuy << 1) | buy]) return;
    visit[(current << 2) | (bossBuy << 1) | buy] = true;

    int *cache = DP[current][bossBuy][buy];
    fill(cache, cache + budget + 1, INT_MIN);

    int cost = buy ? (bossBuy ? present[current] / 2 : present[current]) : 0;
    if(cost <= budget) {
      cache[cost] = buy ? profit[current][bossBuy] : 0;
    }
    vector<int> cur(cache, cache + budget + 1);
    vector<int> merged(budget + 1);

    for(auto child : children[current]) {
      dfs(child, buy, true, budget, present);
      dfs(child, false, false, budget, present);

      int *take = DP[child][buy][true];
      int *skip = DP[child][false][false];

      fill(merged.begin(), merged.end(), INT_MIN);

      for(int b = 0; b <= budget; ++b) {
        if(cur[b] == INT_MIN) continue;
        for(int x = 0; b + x <= budget; ++ x) {
          int best = max(take[x], skip[x]);
          if(best == INT_MIN) continue;
          merged[b + x] = max(merged[b + x], cur[b] + best);
        }
      }
      cur = merged;
    }
    for(int i = 0; i <= budget; ++i) {
      cache[i] = cur[i];
    }
  }
public:
  int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
    for(int i = 0; i < n; ++i) {
      profit[i][0] = future[i] - present[i];
      profit[i][1] = future[i] - present[i] / 2;
    }
    init(n, hierarchy);

    dfs(0, false, false, budget, present);
    dfs(0, false, true, budget, present);

    int answer = 0;
    for(int b = 0; b <= budget; ++b) {
      answer = max({answer, DP[0][0][0][b], DP[0][0][1][b]});
    }
    answer = max(answer, *max_element(DP[0][0][0], DP[0][0][1] + budget + 1));
    return answer;
  }
};

// Accepted
// 790/790 cases passed (109 ms)
// Your runtime beats 93.75 % of cpp submissions
// Your memory usage beats 76.39 % of cpp submissions (104.2 MB)
```
