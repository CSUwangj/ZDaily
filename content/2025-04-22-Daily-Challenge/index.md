+++
updated = 2025-04-22T12:52:27+08:00
title = "2025-04-22 Daily Challenge"
path = "2025-04-22-Daily-Challenge"
date = 2025-04-22T12:52:27+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/count-the-number-of-ideal-arrays/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 22

## Description

**Count the Number of Ideal Arrays**

<p>You are given two integers <code>n</code> and <code>maxValue</code>, which are used to describe an <strong>ideal</strong> array.</p>

<p>A <strong>0-indexed</strong> integer array <code>arr</code> of length <code>n</code> is considered <strong>ideal</strong> if the following conditions hold:</p>

<ul>
	<li>Every <code>arr[i]</code> is a value from <code>1</code> to <code>maxValue</code>, for <code>0 &lt;= i &lt; n</code>.</li>
	<li>Every <code>arr[i]</code> is divisible by <code>arr[i - 1]</code>, for <code>0 &lt; i &lt; n</code>.</li>
</ul>

<p>Return <em>the number of <strong>distinct</strong> ideal arrays of length </em><code>n</code>. Since the answer may be very large, return it modulo <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 2, maxValue = 5
<strong>Output:</strong> 10
<strong>Explanation:</strong> The following are the possible ideal arrays:
- Arrays starting with the value 1 (5 arrays): [1,1], [1,2], [1,3], [1,4], [1,5]
- Arrays starting with the value 2 (2 arrays): [2,2], [2,4]
- Arrays starting with the value 3 (1 array): [3,3]
- Arrays starting with the value 4 (1 array): [4,4]
- Arrays starting with the value 5 (1 array): [5,5]
There are a total of 5 + 2 + 1 + 1 + 1 = 10 distinct ideal arrays.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 5, maxValue = 3
<strong>Output:</strong> 11
<strong>Explanation:</strong> The following are the possible ideal arrays:
- Arrays starting with the value 1 (9 arrays): 
   - With no other distinct values (1 array): [1,1,1,1,1] 
   - With 2<sup>nd</sup> distinct value 2 (4 arrays): [1,1,1,1,2], [1,1,1,2,2], [1,1,2,2,2], [1,2,2,2,2]
   - With 2<sup>nd</sup> distinct value 3 (4 arrays): [1,1,1,1,3], [1,1,1,3,3], [1,1,3,3,3], [1,3,3,3,3]
- Arrays starting with the value 2 (1 array): [2,2,2,2,2]
- Arrays starting with the value 3 (1 array): [3,3,3,3,3]
There are a total of 9 + 1 + 1 = 11 distinct ideal arrays.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= maxValue &lt;= 10<sup>4</sup></code></li>
</ul>


## Solution

firstly it's natural to think that we could use `dp[len][lastDigit]` to do a dynamic programming, then you would find there is no need to store every state of `len`, so we just have `dp[lastDigit]` & `dp[prevLastDigit]`.

then you would realize it's just like Matrix Exponentiation problem but here we need to calculate the matrix first.

take maxValue = 5 as an example, if we reach a state with `[a, b, c, d, e]`, then next state will be `[a, a + b, a + c, a + b + d, a + e]`. which we could accelerate the calculation by Matrix Exponentiation like we do in fibonacci problem. Though we need to calculate the matrix.

in this case, the original array is $[1, 1, 1, 1, 1]$, and the matrix would be $\begin{bmatrix}1 & 0 & 0 & 0 & 0\\1 & 1 & 0 & 0 & 0\\1 & 0 & 1 & 0 & 0\\1 & 1 & 0 & 1 & 0\\1 & 0 & 0 & 0 & 1\end{bmatrix}$. basically if $a$ is divisible by $b$, then $matrix[a][b]$ would be $1$.

ah fk, I got memory limit exceed...

``` cpp
using ll = long long;
vector<vector<ll>> unitMatrix(int sz) {
  vector<vector<ll>> result(sz, vector<ll>(sz));
  for(int i = 0; i < sz; ++i) result[i][i] = 1;
  return result;
}

void multiply(
  const vector<vector<ll>> &a,
  const vector<vector<ll>> &b,
  vector<vector<ll>> &result,
  const int mod
) {
  int rows = result.size();
  int cols = result.front().size();
  int aRows = b.size();

  for(int i = 0; i < rows; ++i) {
    for(int j = 0; j < cols; ++j) {
      result[i][j] = 0;
      for(int k = 0; k < aRows; ++k) {
        result[i][j] += a[i][k] * b[k][j];
        result[i][j] %= mod;
      }
    }
  }
}

void qpow(
  vector<vector<ll>> &base,
  int exp,
  vector<vector<ll>> &result,
  const int mod
) {
  vector<vector<ll>> temp(result);
  while(exp) {
    if(exp & 1) {
      multiply(base, result, temp, mod);
      swap(result, temp);
    }
    multiply(base, base, temp, mod);
    swap(base, temp);
    exp >>= 1;
  }
}

class Solution {
  const int MOD = 1e9 + 7;
public:
  int idealArrays(int n, int maxValue) {
    if(n == 1) return maxValue;
    vector<vector<ll>> initial(1, vector<ll>(maxValue, 1));
    // cout << initial << endl;
    vector<vector<ll>> formula(maxValue, vector<ll>(maxValue));
    for(int i = 1; i <= maxValue; ++i) {
      for(int j = i; j <= maxValue; j += i) {
        formula[j - 1][i - 1] = 1;
      }
    }
    // cout << formula << endl;
    vector<vector<ll>> temp = unitMatrix(maxValue);
    // cout << temp<< endl;
    qpow(formula, n - 1, temp, MOD);
    // cout << temp << endl;
    vector<vector<ll>> result(initial);
    multiply(initial, temp, result, MOD);
    // cout << result << endl;

    int answer = 0;
    for(int i = 0; i < maxValue; ++i) {
      answer += result[0][i];
      answer %= MOD;
    }
    return answer;
  }
};

// Memory Limit Exceeded
// Your Input
// 3
// 10000
```

the real solution is really great though.

``` cpp
using ll = long long;
ll factorial[10001] = {};
inline ll qpow(ll base, ll exp, ll mod) {
  ll result = 1;
  while(exp) {
    if(exp & 1) {
      result *= base;
      result %= mod;
    }
    base *= base;
    base %= mod;
    exp >>= 1;
  }
  return result;
}

inline ll fact(ll a, ll mod) {
  if(a == 0) return 1;
  if(factorial[a]) return factorial[a];
  return factorial[a] = (a * fact(a - 1, mod)) % mod;
}

inline ll modInv(ll a, ll b, ll mod) {
  return (((fact(a, mod) * qpow(fact(b, mod), mod - 2, mod)) % mod) * qpow(fact(a - b, mod), mod - 2, mod)) % mod;
}


class Solution {
  const int MOD = 1e9 + 7;
public:
  int idealArrays(int n, int maxValue) {
    vector<vector<ll>> dp(maxValue + 1, vector<ll>(15));
    for(int i = 1; i <= maxValue; ++i) {
      dp[i][1] = 1;
      for(int j = 2; j * i <= maxValue; ++j) {
        for(int k = 1; k < min(n, 14); ++k) {
          dp[i * j][k + 1] += dp[i][k];
        }
      }
    }
    ll answer = 0;
    for(int i = 1; i <= maxValue; ++i) {
      for(int j = 1; j <= min(n, 14); ++j) {
        answer += modInv(n - 1, n - j, MOD) * dp[i][j];
        answer %= MOD;
      }
    }
    return answer;
  }
};

// Accepted
// 47/47 cases passed (467 ms)
// Your runtime beats 5.17 % of cpp submissions
// Your memory usage beats 20.69 % of cpp submissions (31.4 MB)
```
