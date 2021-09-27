+++
title = "2021-09-27 Daily-Challenge"
path = "2021-09-27-Daily-Challenge"
date = 2021-09-27 20:02:13+08:00
updated = 2021-09-27 22:19:36+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/639/week-4-september-22nd-september-28th/3989/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 27

## Description

**Unique Email Addresses**

Every **valid email** consists of a **local name** and a **domain name**, separated by the `'@'` sign. Besides lowercase letters, the email may contain one or more `'.'` or `'+'`.

- For example, in `"alice@leetcode.com"`, `"alice"` is the **local name**, and `"leetcode.com"` is the **domain name**.

If you add periods `'.'` between some characters in the **local name** part of an email address, mail sent there will be forwarded to the same address without dots in the local name. Note that this rule **does not apply** to **domain names**.

- For example, `"alice.z@leetcode.com"` and `"alicez@leetcode.com"` forward to the same email address.

If you add a plus `'+'` in the **local name**, everything after the first plus sign **will be ignored**. This allows certain emails to be filtered. Note that this rule **does not apply** to **domain names**.

- For example, `"m.y+name@email.com"` will be forwarded to `"my@email.com"`.

It is possible to use both of these rules at the same time.

Given an array of strings `emails` where we send one email to each `email[i]`, return *the number of different addresses that actually receive mails*.

 

**Example 1:**

```
Input: emails = ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
Output: 2
Explanation: "testemail@leetcode.com" and "testemail@lee.tcode.com" actually receive mails.
```

**Example 2:**

```
Input: emails = ["a@leetcode.com","b@leetcode.com","c@leetcode.com"]
Output: 3
```

 

**Constraints:**

- `1 <= emails.length <= 100`
- `1 <= emails[i].length <= 100`
- `email[i]` consist of lowercase English letters, `'+'`, `'.'` and `'@'`.
- Each `emails[i]` contains exactly one `'@'` character.
- All local and domain names are non-empty.
- Local names do not start with a `'+'` character.

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int numUniqueEmails(vector<string>& emails) {
    unordered_set<string> st;
    for(auto &email : emails) {
      string result;
      bool at = false;
      bool plus = false;
      for(auto c : email) {
        at |= c == '@';
        if(at) {
          result.push_back(c);
        } else {
          plus |= c == '+';
          if(plus || c == '.') continue;
          result.push_back(c);
        }
      }
      st.insert(result);
    }
    return st.size();
  }
};

// Accepted
// 183/183 cases passed (16 ms)
// Your runtime beats 98.73 % of cpp submissions
// Your memory usage beats 74.59 % of cpp submissions (13.7 MB)
```
