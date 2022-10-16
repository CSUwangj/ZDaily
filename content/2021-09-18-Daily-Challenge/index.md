+++
title = "2021-09-18 Daily-Challenge"
path = "2021-09-18-Daily-Challenge"
date = 2021-09-18 15:12:13+08:00
updated = 2021-09-18 17:07:23+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/638/week-3-september-15th-september-21st/3979/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 18

## Description

**Expression Add Operators**

Given a string `num` that contains only digits and an integer `target`, return *all possibilities to add the binary operators* `'+'`, `'-'`, *or* `'*'` *between the digits of* `num` *so that the resultant expression evaluates to the* `target` *value*.

 

**Example 1:**

```
Input: num = "123", target = 6
Output: ["1*2*3","1+2+3"]
```

**Example 2:**

```
Input: num = "232", target = 8
Output: ["2*3+2","2+3*2"]
```

**Example 3:**

```
Input: num = "105", target = 5
Output: ["1*0+5","10-5"]
```

**Example 4:**

```
Input: num = "00", target = 0
Output: ["0*0","0+0","0-0"]
```

**Example 5:**

```
Input: num = "3456237490", target = 9191
Output: []
```

 

**Constraints:**

<ul>
	<li><code>1 &lt;= num.length &lt;= 10</code></li>
	<li><code>num</code> consists of only digits.</li>
	<li><code>-2<sup>31</sup> &lt;= target &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  vector<string> answer;
  void solve(string &num, int target, int start, string expr, long value, long last) {
    if(start == num.length()) {
      if(target == value) {
        answer.push_back(expr);
      }
      return;
    }

    long n = 0;
    string nStr;
    for(int i = start; i < num.length(); ++i) {
      n *= 10;
      n += num[i] - '0';
      nStr.push_back(num[i]);

      if(!start) {
        solve(num, target, i + 1, nStr, n, n);
      } else {
        solve(num, target, i + 1, expr + "*" + nStr, value - last + n * last, n * last);
        solve(num, target, i + 1, expr + "+" + nStr, value + n, n);
        solve(num, target, i + 1, expr + "-" + nStr, value - n, -n);
      }

      if(n == 0) break;
    }
  }
public:
  vector<string> addOperators(string num, int target) {
    solve(num, target, 0, "", 0, 0);
    return answer;
  }
};

// Accepted
// 20/20 cases passed (415 ms)
// Your runtime beats 49.31 % of cpp submissions
// Your memory usage beats 12.67 % of cpp submissions (95.2 MB)
```
