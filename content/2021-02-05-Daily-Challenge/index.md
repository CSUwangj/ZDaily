+++
title = "2021-02-05 Daily-Challenge"
path = "2021-02-05-Daily-Challenge"
date = 2021-02-05 18:00:59+08:00
updated = 2021-02-05 18:39:04+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [String Compression](https://leetcode.com/problems/string-compression/) and leetcode's [February LeetCoding Challenge](https://leetcode.com/explore/featured/card/february-leetcoding-challenge-2021/584/week-1-february-1st-february-7th/3629/) with `cpp`.

<!-- more -->

# String Compression

## Description

Given an array of characters `chars`, compress it using the following algorithm:

Begin with an empty string `s`. For each group of **consecutive repeating characters** in `chars`:

- If the group's length is 1, append the character to `s`.
- Otherwise, append the character followed by the group's length.

The compressed string `s` **should not be returned separately**, but instead be stored **in the input character array `chars`**. Note that group lengths that are 10 or longer will be split into multiple characters in `chars`.

After you are done **modifying the input array**, return *the new length of the array*.

 

**Follow up:**
Could you solve it using only `O(1)` extra space?

 

**Example 1:**

```
Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
```

**Example 2:**

```
Input: chars = ["a"]
Output: Return 1, and the first character of the input array should be: ["a"]
Explanation: The only group is "a", which remains uncompressed since it's a single character.
```

**Example 3:**

```
Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".
```

**Example 4:**

```
Input: chars = ["a","a","a","b","b","a","a"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","3","b","2","a","2"].
Explanation: The groups are "aaa", "bb", and "aa". This compresses to "a3b2a2". Note that each group is independent even if two groups have the same character.
```

 

**Constraints:**

- `1 <= chars.length <= 2000`
- `chars[i]` is a lower-case English letter, upper-case English letter, digit, or symbol.

## Solution

``` cpp
class Solution {
public:
    int compress(vector<char>& chars) {
        int newPos = 0;
        int len = chars.size();
        int pos = 0;
        while(pos < len) {
            chars[newPos] = chars[pos];
            int cnt = 0;
            while(pos < len && chars[pos] == chars[newPos]) {
                pos += 1;
                cnt += 1;
            }
            newPos += 1;
            if(cnt == 1) continue;
            bool leading = false;
            if(cnt > 999) {
                chars[newPos++] = (cnt/1000) + '0';
                leading = true;
                cnt %= 1000;
            }
            if(leading || cnt > 99) { 
                chars[newPos++] = (cnt/100) + '0';
                leading = true;
                cnt %= 100;
            }
            if(leading || cnt > 9) { 
                chars[newPos++] = (cnt/10) + '0';
                leading = true;
                cnt %= 10;
            }
            chars[newPos++] = cnt + '0';
        }
        return newPos;
    }
};
```

emmmm, so ugly. I'd rather use a string

``` cpp
class Solution {
public:
    int compress(vector<char>& chars) {
        int newPos = 0;
        int len = chars.size();
        int pos = 0;
        while(pos < len) {
            chars[newPos] = chars[pos];
            int cnt = 0;
            while(pos < len && chars[pos] == chars[newPos]) {
                pos += 1;
                cnt += 1;
            }
            newPos += 1;
            if(cnt == 1) continue;
            string count = to_string(cnt);
            for(auto it = count.begin(); it != count.end(); ++it) chars[newPos++] = *it;
        }
        return newPos;
    }
};
```

# February LeetCoding Challenge 5

## Description

**Simplify Path**

Given a string `path`, which is an **absolute path** (starting with a slash `'/'`) to a file or directory in a Unix-style file system, convert it to the simplified **canonical path**.

In a Unix-style file system, a period `'.'` refers to the current directory, a double period `'..'` refers to the directory up a level, and any multiple consecutive slashes (i.e. `'//'`) are treated as a single slash `'/'`. For this problem, any other format of periods such as `'...'` are treated as file/directory names.

The **canonical path** should have the following format:

- The path starts with a single slash `'/'`.
- Any two directories are separated by a single slash `'/'`.
- The path does not end with a trailing `'/'`.
- The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period `'.'` or double period `'..'`)

Return *the simplified **canonical path***.

 

**Example 1:**

```
Input: path = "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.
```

**Example 2:**

```
Input: path = "/../"
Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.
```

**Example 3:**

```
Input: path = "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.
```

**Example 4:**

```
Input: path = "/a/./b/../../c/"
Output: "/c"
```

 

**Constraints:**

- `1 <= path.length <= 3000`
- `path` consists of English letters, digits, period `'.'`, slash `'/'` or `'_'`.
- `path` is a valid absolute Unix path.

## Solution

``` cpp
class Solution {
    bool isCurrent(string &path, int pos) {
        int len = path.length();
        return pos < len && path[pos] == '.' && (pos == len-1 || path[pos+1] == '/');
    }
    bool isUpLevel(string &path, int pos) {
        int len = path.length();
        return pos < len-1 && path[pos] == '.' && path[pos+1] == '.' && (pos == len-2 || path[pos+2] == '/');
    }
public:
    string simplifyPath(string path) {
        vector<pair<int, int>> st;
        int len = path.length();
        int pos = 0;
        while(pos < len) {
            if(path[pos] == '/') {
                while(pos < len && path[pos] == '/') pos += 1;
            } else if(isCurrent(path, pos)) {
                pos += 1;
            } else if(isUpLevel(path, pos)){
                pos += 2;
                if(!st.empty()) st.pop_back();
            } else {
                int begin = pos;
                while(pos < len && (path[pos] == '.' || path[pos] == '_' || isalnum(path[pos]))) ++pos;
                st.push_back(make_pair(begin, pos - begin));
            }
        }
        if(st.empty()) return "/";
        string answer;
        for(auto [begin, len] : st) {
            answer += "/" + path.substr(begin, len);
        }
        return answer;
    }
};
```