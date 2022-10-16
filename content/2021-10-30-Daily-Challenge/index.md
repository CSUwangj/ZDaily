+++
title = "2021-10-30 Daily-Challenge"
path = "2021-10-30-Daily-Challenge"
date = 2021-10-30 13:05:33+08:00
updated = 2021-10-30 14:17:21+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/rotting-oranges/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 30

## Description

**Longest Duplicate Substring**

Given a string `s`, consider all *duplicated substrings*: (contiguous) substrings of s that occur 2 or more times. The occurrences may overlap.

Return **any** duplicated substring that has the longest possible length. If `s` does not have a duplicated substring, the answer is `""`.

 

**Example 1:**

```
Input: s = "banana"
Output: "ana"
```

**Example 2:**

```
Input: s = "abcd"
Output: ""
```

 

**Constraints:**

- `2 <= s.length <= 3 * 10^4`
- `s` consists of lowercase English letters.


## Solution

almost copied from <https://leetcode.com/problems/longest-duplicate-substring/discuss/695101/C%2B%2B-short-O(n-log(n))-solution-with-std%3A%3Aunordered_setlessstd%3A%3Astring_viewgreater>

`std::string_view` does not copy the whole string and `std::unordered_set` handles the logic of hashing and comparing `std::string_view`'s.

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class rabinFingerprint {
public:
  size_t operator()(const string_view& s)
  {
    if (m_clear) {
      m_pow = 1;
      for (size_t i = 1; i != s.size(); ++i) {
        m_pow = (m_pow * base) % p;
      }
      m_cur = 0;
      for (auto c : s) {
        m_cur = ((m_cur * base) % p + (c - 'a')) % p;
      }
      m_clear = false;
    } else {
      m_cur = ((ssize_t(m_cur) - ssize_t(m_pow * (m_first - 'a'))) % ssize_t(p) + p) % p;
      m_cur = (m_cur * base + (s.back() - 'a')) % p;
    }
    m_first = s.front();
    return m_cur;
  };
  
  void clear() { m_clear = true; }

private:
  static constexpr size_t p = 19260817;
  static constexpr size_t base = 26;

  bool m_clear = true;
  size_t m_cur;
  size_t m_pow;
  char m_first;
};
struct wrapper {
  size_t operator()(const string_view& s) const {
    return m_hasher(s);
  }
  
  rabinFingerprint& m_hasher;  
};
class Solution {
public:
  string longestDupSubstring(string &s) {
    int len = s.length();
    rabinFingerprint hasher;
    unordered_set<string_view, wrapper> st{10, wrapper{hasher}};

    string_view answer;
    int low = 1;
    int high = len;
    while(low <= high) {
      int mid = (low + high) >> 1;
      bool found = false;
      for(int i = 0; i + mid <= len; ++ i) {
        const auto [it, inserted] = st.emplace(s.data() + i, mid);
        if(!inserted) {
          answer = *it;
          found = true;
          break;
        }
      }
      if(found) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
      
      st.clear();
      hasher.clear();
    }

    return {answer.begin(), answer.end()};
  }
};

// Accepted
// 66/66 cases passed (604 ms)
// Your runtime beats 91.95 % of cpp submissions
// Your memory usage beats 80.2 % of cpp submissions (167.4 MB)
```

will learn <https://leetcode.com/problems/longest-duplicate-substring/discuss/1548070/solution-with-explanation-C%2B%2B-beats-99-time-85-memory-(suffix-array)> later
