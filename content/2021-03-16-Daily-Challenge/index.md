+++
title = "2021-03-16 Daily-Challenge"
path = "2021-03-16-Daily-Challenge"
date = 2021-03-16 18:31:03+08:00
updated = 2021-03-16 21:19:24+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/), [Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/), [Best Time to Buy and Sell Stock III](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/), [Best Time to Buy and Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/), [Best Time to Buy and Sell Stock with Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/) and leetcode's [March LeetCoding Challenge](https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/590/week-3-march-15th-march-21st/3674/) with `cpp`.

<!-- more -->

# Best Time to Buy and Sell Stock

## Description

You are given an array `prices` where `prices[i]` is the price of a given stock on the `ith` day.

You want to maximize your profit by choosing a **single day** to buy one stock and choosing a **different day in the future** to sell that stock.

Return *the maximum profit you can achieve from this transaction*. If you cannot achieve any profit, return `0`.

 

**Example 1:**

```
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
```

**Example 2:**

```
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
```

 

**Constraints:**

- `1 <= prices.length <= 10^5`
- `0 <= prices[i] <= 10^4`

## Solution

``` cpp
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int mmin = INT_MAX;
    int answer = 0;
    for(auto price : prices) {
      mmin = min(mmin, price);
      answer = max(answer, price - mmin);
    }
    return answer;
  }
};
```

# Best Time to Buy and Sell Stock II

## Description

You are given an array `prices` where `prices[i]` is the price of a given stock on the `ith` day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

**Note:** You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

**Example 1:**

```
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
```

**Example 2:**

```
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
```

**Example 3:**

```
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e., max profit = 0.
```

 

**Constraints:**

- `1 <= prices.length <= 3 * 10^4`
- `0 <= prices[i] <= 10^4`

## Solution

``` cpp
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int answer = 0;
    int cur = INT_MAX;
    for(auto price : prices) {
      if(price > cur) {
        answer += price - cur;
      } 
      cur = price;
    }
    return answer;
  }
};
```

# Best Time to Buy and Sell Stock III

## Description

You are given an array `prices` where `prices[i]` is the price of a given stock on the `ith` day.

Find the maximum profit you can achieve. You may complete **at most two transactions**.

**Note:** You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

**Example 1:**

```
Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
```

**Example 2:**

```
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
```

**Example 3:**

```
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
```

**Example 4:**

```
Input: prices = [1]
Output: 0
```

 

**Constraints:**

- `1 <= prices.length <= 10^5`
- `0 <= prices[i] <= 10^5`

## Solution

``` cpp
class Solution {
  int maxProfit(int k, vector<int>& prices) {
    int len = prices.size();
    if(len < 2) return 0;
    int dp[k + 1][len][2];
    for(int i = 0; i <= k; ++i) {
      for(int j = 0; j < len; ++j) {
        dp[i][j][0] = -1e9;
        dp[i][j][1] = -1e9;
      }
    }
    
    dp[0][0][0] = -prices[0];
    dp[0][0][1] = 0;
    for(int i = 0; i <= k; ++i) {
      for(int j = 0; j < len; ++j) {
        if(j) dp[i][j][0] = max(dp[i][j - 1][1] - prices[j], dp[i][j - 1][0]);
        if(j) dp[i][j][1] = max(dp[i][j][1], dp[i][j - 1][1]);
        if(j && i) dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - 1][0] + prices[j]);
      }
    }
    int answer = 0;
    for(int i = 0; i <= k; ++i) answer = max(answer, dp[i][len - 1][1]);
    
    return answer;
  }
public:
  int maxProfit(vector<int>& prices) {
    return maxProfit(2, prices);
  }
};
```

# Best Time to Buy and Sell Stock IV

## Description

You are given an integer array `prices` where `prices[i]` is the price of a given stock on the `ith` day, and an integer `k`.

Find the maximum profit you can achieve. You may complete at most `k` transactions.

**Note:** You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

**Example 1:**

```
Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
```

**Example 2:**

```
Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
```

 

**Constraints:**

- `0 <= k <= 100`
- `0 <= prices.length <= 1000`
- `0 <= prices[i] <= 1000`

## Solution

``` cpp
class Solution {
public:
  int maxProfit(int k, vector<int>& prices) {
    int len = prices.size();
    if(len < 2) return 0;
    int dp[k + 1][len][2];
    for(int i = 0; i <= k; ++i) {
      for(int j = 0; j < len; ++j) {
        dp[i][j][0] = -1e9;
        dp[i][j][1] = -1e9;
      }
    }
    
    dp[0][0][0] = -prices[0];
    dp[0][0][1] = 0;
    for(int i = 0; i <= k; ++i) {
      for(int j = 0; j < len; ++j) {
        if(j) dp[i][j][0] = max(dp[i][j - 1][1] - prices[j], dp[i][j - 1][0]);
        if(j) dp[i][j][1] = max(dp[i][j][1], dp[i][j - 1][1]);
        if(j && i) dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - 1][0] + prices[j]);
      }
    }
    // for(int i = 0; i <= k; ++i) {
    //   for(int j = 0; j < len; ++j) {
    //     cout << dp[i][j][0] << ' ';
    //   }
    //   cout << endl;
    // }
    // for(int i = 0; i <= k; ++i) {
    //   for(int j = 0; j < len; ++j) {
    //     cout << dp[i][j][1] << ' ';
    //   }
    //   cout << endl;
    // }
    
    int answer = 0;
    for(int i = 0; i <= k; ++i) answer = max(answer, dp[i][len - 1][1]);
    
    return answer;
  }
};
```

# Best Time to Buy and Sell Stock with Cooldown

## Description

You are given an array `prices` where `prices[i]` is the price of a given stock on the `ith` day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

- After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).

**Note:** You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

**Example 1:**

```
Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
```

**Example 2:**

```
Input: prices = [1]
Output: 0
```

 

**Constraints:**

- `1 <= prices.length <= 5000`
- `0 <= prices[i] <= 1000`

## Solution

``` cpp
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int len = prices.size();
    if(len < 2) return 0;
    vector<int> buy(len, INT_MIN);
    vector<int> sell(len, INT_MIN);
    buy[0] = -prices[0];
    buy[1] = max(-prices[0], -prices[1]);
    sell[0] = 0;
    sell[1] = max(0, prices[1] - prices[0]);
    for(int i = 2; i < len; ++i) {
      buy[i] = max(buy[i-1], sell[i-2] - prices[i]);
      sell[i] = max(buy[i-1] + prices[i], sell[i-1]);
    }
    return sell.back();
  }
};
```

# March LeetCoding Challenge16

## Description

**Best Time to Buy and Sell Stock with Transaction Fee**

## Description

You are given an array `prices` where `prices[i]` is the price of a given stock on the `ith` day, and an integer `fee` representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

**Note:** You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

**Example 1:**

```
Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
```

**Example 2:**

```
Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6
```

 

**Constraints:**

- `1 < prices.length <= 5 * 10^4`
- `0 < prices[i], fee < 5 * 10^4`

## Solution

because of this problem, I reviewed the whole `Best Time To Buy and Sell Stock` series problem.

when using DP to solve them, we need to keep track of the optimal state for buy and sell.

``` cpp
class Solution {
public:
  int maxProfit(vector<int>& prices, int fee) {
    stack<pair<int, int>> st;
    int mmin = prices.front();
    // cout << "$$$$$$" << endl;
    for(auto price : prices) {
      mmin = min(mmin, price);
      int mergeProfit = 0;
      int addProfit = 0;
      if(st.size() && price > st.top().second && 0 < mmin + fee - st.top().second) {
        auto [low, high] = st.top();
        mergeProfit = price - high;
      }
      if(price > mmin && price - mmin > fee) {
        addProfit = price - mmin - fee;
      }
      if(!mergeProfit && !addProfit) continue;
      if(mergeProfit >= addProfit) {
        auto [low, _high] = st.top();
        st.pop();
        st.push(make_pair(low, price));
      } else {
        st.push(make_pair(mmin, price));
      }
      mmin = price;
    }
    
    int answer = 0;
    while(st.size()) {
      auto [low, high] = st.top();
      st.pop();
      answer += high - low - fee;
    }
    return answer;
  }
};
```
