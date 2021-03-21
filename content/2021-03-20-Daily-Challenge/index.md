+++
title = "2021-03-20 Daily-Challenge"
path = "2021-03-20-Daily-Challenge"
date = 2021-03-20 09:54:45+08:00
updated = 2021-03-20 17:01:41+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [March LeetCoding Challenge](https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/590/week-3-march-15th-march-21st/3678/) with `cpp`.


<!-- more -->

# LeetCode Review

## Matrix Block Sum

``` cpp
class Solution {
public:
  vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
    int rows = mat.size();
    int cols = mat.front().size();
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        if(i) mat[i][j] += mat[i - 1][j];
        if(j) mat[i][j] += mat[i][j - 1];
        if(i && j) mat[i][j] -= mat[i - 1][j - 1];
      }
    }
    
    vector<vector<int>> answer(rows, vector<int>(cols));
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        int right = min(cols - 1, j + K);
        int bottom = min(rows - 1, i + K);
        int top = max(i - K, 0);
        int left = max(j - K, 0);
        answer[i][j] += mat[bottom][right];
        if(top) answer[i][j] -= mat[top - 1][right];
        if(left) answer[i][j] -= mat[bottom][left - 1];
        if(top && left) answer[i][j] += mat[top - 1][left - 1];
      }
    }
    return move(answer);
  }
};
```

## Best Time to Buy and Sell Stock

unoptimized dp solution

``` cpp
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int len = prices.size();
    vector<int> buy(len, INT_MIN);
    vector<int> sell(len);
    buy[0] = -prices[0];
    for(int i = 1; i < len; ++i) {
      buy[i] = max(buy[i - 1], -prices[i]);
      sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
    }
    return sell.back();
  }
};
```

after optimization

``` cpp
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int buy = -prices[0];
    int sell = 0;
    for(auto price : prices) {
      buy = max(buy, -price);
      sell = max(sell, buy + price);
    }
    return sell;
  }
};
```

## Best Time to Buy and Sell Stock II

unoptimized solution

``` cpp
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int len = prices.size();
    if(len < 2) return 0;
    vector<int> buy(len, INT_MIN);
    vector<int> sell(len);
    buy[0] = -prices.front();
    for(int i = 1; i < len; ++i) {
      buy[i] = max(buy[i - 1], sell[i - 1] - prices[i]);
      sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
    }
    return sell.back();
  }
};
```

after optimization

``` cpp
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int len = prices.size();
    if(len < 2) return 0;
    int answer = 0;
    for(int i = 1; i < len; ++i) {
      if(prices[i] > prices[i - 1]) answer += prices[i] - prices[i - 1];
    }
    return answer;
  }
};
```

## Best Time to Buy and Sell Stock IV

I think this solution can be optimized

``` cpp
class Solution {
public:
  int maxProfit(int k, vector<int>& prices) {
    int len = prices.size();
    if(len < 2) return 0;
    int buy[k + 1][len];
    int sell[k + 1][len];
    buy[0][0] = -prices[0];
    sell[0][0] = 0;
    for(int i = 1; i < len; ++i) {
      buy[0][i] = max(buy[0][i - 1], -prices[i]);
      sell[0][i] = 0;
    }
    
    for(int i = 1; i <= k; ++i) {
      buy[i][0] = INT_MIN;
      sell[i][0] = 0;
      for(int j = 1; j < len; ++j) {
        buy[i][j] = max(buy[i][j - 1], sell[i][j - 1] - prices[j]);
        
        sell[i][j] = max(sell[i - 1][j], sell[i][j - 1]);
        sell[i][j] = max(sell[i][j], buy[i - 1][j - 1] + prices[j]);
      }
    }
    return sell[k][len - 1];
  }
};
```

YES!

``` cpp
class Solution {
public:
  int maxProfit(int k, vector<int>& prices) {
    int len = prices.size();
    if(len < 2) return 0;
    int buy[len];
    int sell[len];
    buy[0] = -prices[0];
    sell[0] = 0;
    for(int i = 1; i < len; ++i) {
      buy[i] = max(buy[i - 1], -prices[i]);
      sell[i] = 0;
    }
    // cout << "$$$$$$$$$$$$$$$" << endl;
    for(int i = 1; i <= k; ++i) {
      for(int j = 1; j < len; ++j) {
        sell[j] = max(sell[j], sell[j - 1]);
        sell[j] = max(sell[j], buy[j - 1] + prices[j]);
      }
      for(int j = 1; j < len; ++j) {
        buy[j] = max(buy[j - 1], sell[j - 1] - prices[j]);
      }
      // for(int j = 0; j < len; ++j) {
      //   cout << i << ' ' << j << ' ' << buy[j] << ' ' << sell[j] << endl;
      // }
    }
    return sell[len - 1];
  }
};
```

## Best Time to Buy and Sell Stock III

``` cpp
class Solution {
  int maxProfit(int k, vector<int>& prices) {
    int len = prices.size();
    if(len < 2) return 0;
    int buy[len];
    int sell[len];
    buy[0] = -prices[0];
    sell[0] = 0;
    for(int i = 1; i < len; ++i) {
      buy[i] = max(buy[i - 1], -prices[i]);
      sell[i] = 0;
    }
    for(int i = 1; i <= k; ++i) {
      for(int j = 1; j < len; ++j) {
        sell[j] = max(sell[j], sell[j - 1]);
        sell[j] = max(sell[j], buy[j - 1] + prices[j]);
      }
      for(int j = 1; j < len; ++j) {
        buy[j] = max(buy[j - 1], sell[j - 1] - prices[j]);
      }
    }
    return sell[len - 1];
  }
public:
  int maxProfit(vector<int>& prices) {
    return maxProfit(2, prices);
  }
};
```

## Best Time to Buy and Sell Stock with Cooldown

unoptimized solution

``` cpp
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int len = prices.size();
    if(len < 2) return 0;
    vector<int> buy(len, INT_MIN);
    vector<int> sell(len);
    buy[0] = -prices[0];
    buy[1] = max(-prices[0], -prices[1]);
    sell[1] = max(0, buy[1] + prices[1]);
    for(int i = 2; i < len; ++i) {
      buy[i] = max(buy[i - 1], sell[i - 2] - prices[i]);
      sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
    }
    return sell.back();
  }
};
```

after optimization

``` cpp
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int len = prices.size();
    if(len < 2) return 0;
    int buy[2] = {-prices[0], max(-prices[0], -prices[1])};
    int sell[2] = {0, max(0, buy[1] + prices[1])};
    for(int i = 2; i < len; ++i) {
      buy[0] = buy[1];
      buy[1] = max(buy[1], sell[0] - prices[i]);
      sell[0] = sell[1];
      sell[1] = max(sell[1], buy[0] + prices[i]);
    }
    return sell[1];
  }
};
```

## Best Time to Buy and Sell Stock with Transaction Fee

unoptimized solution

``` cpp
class Solution {
public:
  int maxProfit(vector<int>& prices, int fee) {
    int len = prices.size();
    if(len < 2) return 0;
    vector<int> buy(len);
    vector<int> sell(len);
    buy[0] = -prices[0] - fee;
    for(int i = 1; i < len; ++i) {
      buy[i] = max(buy[i - 1], sell[i - 1] - fee - prices[i]);
      sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
    }
    return sell.back();
  }
};
```

after optimization

``` cpp
class Solution {
public:
  int maxProfit(vector<int>& prices, int fee) {
    int len = prices.size();
    if(len < 2) return 0;
    int sell = 0;
    int buy = -prices[0] - fee;
    for(int i = 1; i < len; ++i) {
      buy = max(buy, sell - fee - prices[i]);
      sell = max(sell, buy + prices[i]);
    }
    return sell;
  }
};
```

## Encode and Decode TinyURL

don't review system design problems.

## Generate Random Point in a Circle

already reviewed several times recently.

## Wiggle Subsequence

too easy to review

## Keys and Rooms

``` cpp
class Solution {
  void dfs(vector<vector<int>>& rooms, unordered_set<int> &opened, int cur) {
    opened.insert(cur);
    for(auto key : rooms[cur]) {
      if(!opened.count(key)) {
        dfs(rooms, opened, key);
      }
    }
  }
public:
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    unordered_set<int> opened;
    dfs(rooms, opened, 0);
    return opened.size() == rooms.size();
  }
};
```

## Prime Arrangements

``` cpp
const int answer[101] = {1,1,1,2,4,12,36,144,576,2880,17280,86400,604800,3628800,29030400,261273600,612735986,289151874,180670593,445364737,344376809,476898489,676578804,89209194,338137903,410206413,973508979,523161503,940068494,400684877,13697484,150672324,164118783,610613205,44103617,58486801,462170018,546040181,197044608,320204381,965722612,554393872,77422176,83910457,517313696,36724464,175182841,627742601,715505693,327193394,451768713,263673556,755921509,94744060,600274259,410695940,427837488,541336889,736149184,514536044,125049738,250895270,39391803,772631128,541031643,428487046,567378068,780183222,228977612,448880523,892906519,858130261,622773264,78238453,146637981,918450925,514800525,828829204,243264299,351814543,405243354,909357725,561463122,913651722,732754657,430788419,139670208,938893256,28061213,673469112,448961084,80392418,466684389,201222617,85583092,76399490,500763245,519081041,892915734,75763854,682289015};

class Solution {
public:
  int numPrimeArrangements(int n) {
    return answer[n];
  }
};
```

## Maximum Score from Performing Multiplication Operations

``` cpp
constexpr int SZ = 1001;

class Solution {
public:
  int maximumScore(vector<int>& nums, vector<int>& multipliers) {
    int m = multipliers.size();
    int len = nums.size();
    int dp[SZ][SZ] = {0};
    for(int i = 1; i <= m; ++i) {
      for(int j = 0; j <= i; ++j) {
        dp[i][j] = INT_MIN;
        if(j) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + nums[j - 1] * multipliers[i - 1]);
        if(j != i) dp[i][j] = max(dp[i][j], dp[i - 1][j] + nums[len - i + j] * multipliers[i - 1]);
      }
    }
    
    int answer = INT_MIN;
    for(int i = 0; i <= m; ++i) answer = max(answer, dp[m][i]);
    
    return answer;
  }
};
```

# March LeetCoding Challenge20

**Design Underground System**

## Description

Implement the `UndergroundSystem` class:

- ```
  void checkIn(int id, string stationName, int t)
  ```

  - A customer with a card id equal to `id`, gets in the station `stationName` at time `t`.
  - A customer can only be checked into one place at a time.

- ```
  void checkOut(int id, string stationName, int t)
  ```

  - A customer with a card id equal to `id`, gets out from the station `stationName` at time `t`.

- ```
  double getAverageTime(string startStation, string endStation)
  ```

  - Returns the average time to travel between the `startStation` and the `endStation`.
  - The average time is computed from all the previous traveling from `startStation` to `endStation` that happened **directly**.
  - Call to `getAverageTime` is always valid.

You can assume all calls to `checkIn` and `checkOut` methods are consistent. If a customer gets in at time **t1** at some station, they get out at time **t2** with **t2 > t1**. All events happen in chronological order.

 

**Example 1:**

```
Input
["UndergroundSystem","checkIn","checkIn","checkIn","checkOut","checkOut","checkOut","getAverageTime","getAverageTime","checkIn","getAverageTime","checkOut","getAverageTime"]
[[],[45,"Leyton",3],[32,"Paradise",8],[27,"Leyton",10],[45,"Waterloo",15],[27,"Waterloo",20],[32,"Cambridge",22],["Paradise","Cambridge"],["Leyton","Waterloo"],[10,"Leyton",24],["Leyton","Waterloo"],[10,"Waterloo",38],["Leyton","Waterloo"]]

Output
[null,null,null,null,null,null,null,14.00000,11.00000,null,11.00000,null,12.00000]

Explanation
UndergroundSystem undergroundSystem = new UndergroundSystem();
undergroundSystem.checkIn(45, "Leyton", 3);
undergroundSystem.checkIn(32, "Paradise", 8);
undergroundSystem.checkIn(27, "Leyton", 10);
undergroundSystem.checkOut(45, "Waterloo", 15);
undergroundSystem.checkOut(27, "Waterloo", 20);
undergroundSystem.checkOut(32, "Cambridge", 22);
undergroundSystem.getAverageTime("Paradise", "Cambridge");       // return 14.00000. There was only one travel from "Paradise" (at time 8) to "Cambridge" (at time 22)
undergroundSystem.getAverageTime("Leyton", "Waterloo");          // return 11.00000. There were two travels from "Leyton" to "Waterloo", a customer with id=45 from time=3 to time=15 and a customer with id=27 from time=10 to time=20. So the average time is ( (15-3) + (20-10) ) / 2 = 11.00000
undergroundSystem.checkIn(10, "Leyton", 24);
undergroundSystem.getAverageTime("Leyton", "Waterloo");          // return 11.00000
undergroundSystem.checkOut(10, "Waterloo", 38);
undergroundSystem.getAverageTime("Leyton", "Waterloo");          // return 12.00000
```

**Example 2:**

```
Input
["UndergroundSystem","checkIn","checkOut","getAverageTime","checkIn","checkOut","getAverageTime","checkIn","checkOut","getAverageTime"]
[[],[10,"Leyton",3],[10,"Paradise",8],["Leyton","Paradise"],[5,"Leyton",10],[5,"Paradise",16],["Leyton","Paradise"],[2,"Leyton",21],[2,"Paradise",30],["Leyton","Paradise"]]

Output
[null,null,null,5.00000,null,null,5.50000,null,null,6.66667]

Explanation
UndergroundSystem undergroundSystem = new UndergroundSystem();
undergroundSystem.checkIn(10, "Leyton", 3);
undergroundSystem.checkOut(10, "Paradise", 8);
undergroundSystem.getAverageTime("Leyton", "Paradise"); // return 5.00000
undergroundSystem.checkIn(5, "Leyton", 10);
undergroundSystem.checkOut(5, "Paradise", 16);
undergroundSystem.getAverageTime("Leyton", "Paradise"); // return 5.50000
undergroundSystem.checkIn(2, "Leyton", 21);
undergroundSystem.checkOut(2, "Paradise", 30);
undergroundSystem.getAverageTime("Leyton", "Paradise"); // return 6.66667
```

 

**Constraints:**

- There will be at most `20000` operations.
- `1 <= id, t <= 10^6`
- All strings consist of uppercase and lowercase English letters, and digits.
- `1 <= stationName.length <= 10`
- Answers within `10-5` of the actual value will be accepted as correct.

## Solution

``` cpp
struct Time {
  long long total;
  double count;
  Time(): total(0), count(0) {}
};
class UndergroundSystem {
  unordered_map<string, unordered_map<string, Time>> time;
  unordered_map<int, int> checkInTime;
  unordered_map<int, string> checkInStation;
public:
  UndergroundSystem(){}

  void checkIn(int id, string stationName, int t) {
    checkInTime[id] = t;
    checkInStation[id] = stationName;
  }

  void checkOut(int id, string end, int t) {
    int interval = t - checkInTime[id];
    checkInTime.erase(id);
    string start = checkInStation[id];
    checkInStation.erase(id);
    time[start][end].total += interval;
    time[start][end].count += 1;
  }

  double getAverageTime(string start, string end) {
    return time[start][end].total / time[start][end].count;
  }
};
```
