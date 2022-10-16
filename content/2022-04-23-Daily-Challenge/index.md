+++
updated = 2022-04-23 13:58:00+08:00
title = "2022-04-23 Daily-Challenge"
path = "2022-04-23-Daily-Challenge"
date = 2022-04-23 13:57:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/encode-and-decode-tinyurl/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 23

## Description

**Encode and Decode TinyURL**

> Note: This is a companion problem to the [System Design](https://leetcode.com/discuss/interview-question/system-design/) problem: [Design TinyURL](https://leetcode.com/discuss/interview-question/124658/Design-a-URL-Shortener-(-TinyURL-)-System/).

TinyURL is a URL shortening service where you enter a URL such as `https://leetcode.com/problems/design-tinyurl` and it returns a short URL such as `http://tinyurl.com/4e9iAk`. Design a class to encode a URL and decode a tiny URL.

There is no restriction on how your encode/decode algorithm should  work. You just need to ensure that a URL can be encoded to a tiny URL  and the tiny URL can be decoded to the original URL.

Implement the `Solution` class:

- `Solution()` Initializes the object of the system.
- `String encode(String longUrl)` Returns a tiny URL for the given `longUrl`.
- `String decode(String shortUrl)` Returns the original long URL for the given `shortUrl`. It is guaranteed that the given `shortUrl` was encoded by the same object.

 

**Example 1:**

```
Input: url = "https://leetcode.com/problems/design-tinyurl"
Output: "https://leetcode.com/problems/design-tinyurl"

Explanation:
Solution obj = new Solution();
string tiny = obj.encode(url); // returns the encoded tiny url.
string ans = obj.decode(tiny); // returns the original url after deconding it.
```

 

**Constraints:**

- `1 <= url.length <= 104`
- `url` is guranteed to be a valid URL.

## Solution

``` cpp
class Solution {
public:
  unordered_map<string, string> mp;
  unordered_map<string, string> rmp;
  int count = 0;
  // Encodes a URL to a shortened URL.
  string encode(string longUrl) {
    if(!mp.count(longUrl)) {
      string cnt = to_string(count++);
      mp[longUrl] = cnt;
      rmp[cnt] = longUrl;
    }
    return mp[longUrl];
  }

  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl) {
    return rmp[shortUrl];
  }
};

// Accepted
// 739/739 cases passed (6 ms)
// Your runtime beats 44.57 % of cpp submissions
// Your memory usage beats 16.54 % of cpp submissions (7.4 MB)
```
