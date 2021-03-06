+++
title = "2021-03-06 Daily-Challenge"
path = "2021-03-06-Daily-Challenge"
date = 2021-03-06 15:12:45+08:00
updated = 2021-03-06 16:28:23+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [March LeetCoding Challenge](https://leetcode.com/explore/featured/card/march-leetcoding-challenge-2021/588/week-1-march-1st-march-7th/3662/) with `cpp`.


<!-- more -->

# LeetCode Review

## Majority Element II

``` cpp
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidates[2] = {INT_MAX, INT_MAX};
        int count[2] = {0};
        for(auto n : nums) {
            if(candidates[0] == n) {
                count[0] += 1;
            } else if(candidates[1] == n) {
                count[1] += 1;
            } else if(count[0] == 0) {
                candidates[0] = n;
                count[0] = 1;
            } else if(count[1] == 0) {
                candidates[1] = n;
                count[1] = 1;
            } else {
                count[0] -= 1;
                count[1] -= 1;
            }
        }
        vector<int> answer;
        for(auto candidate : candidates) {
            int count = 0;
            for(auto n : nums) count += (n == candidate);
            if(count > nums.size() / 3) answer.push_back(candidate);
        }
        return move(answer);
    }
};
```

## Closest Divisors

too easy to review

## Accounts Merge

``` cpp
class Solution {
    unordered_map<string, int> id;
    unordered_map<int, string> name;
    
    vector<int> parent;
    
    int find(int x) {
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void merge(int x, int y) {
        parent[find(y)] = find(x);
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int count = 0;
        for(auto &account : accounts) {
            for(int i = 1; i < account.size(); ++i) {
                if(!id.count(account[i])) {
                    id[account[i]] = count++;
                }
            }
            name[id[account[1]]] = account[0];
        }
        parent.resize(count);
        for(int i = 0; i < count; ++i) parent[i] = i;
        for(auto &account : accounts) {
            for(int i = 2; i < account.size(); ++i) {
                merge(id[account[1]], id[account[i]]);
            }
        }
        vector<vector<string>> answer;
        for(int i = 0; i < count; ++i) {
            if(find(i) != i) continue;
            vector<string> account{name[i]};
            for(auto &[email, id] : id) if(find(id) == i) account.push_back(email);
            sort(account.begin()+1, account.end());
            answer.push_back(account);
        }
        return move(answer);
    }
};


// 49 / 49 test cases passed.
// Status: Accepted
// Runtime: 84 ms
// Memory Usage: 31.7 MB

```

``` cpp
class Solution {
    unordered_map<string, int> id;
    vector<string> id2string;
    unordered_map<int, string> name;
    
    vector<int> parent;
    
    int find(int x) {
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void merge(int x, int y) {
        parent[find(y)] = find(x);
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int count = 0;
        for(auto &account : accounts) {
            for(int i = 1; i < account.size(); ++i) {
                if(!id.count(account[i])) {
                    id[account[i]] = count++;
                    id2string.push_back(account[i]);
                }
            }
            name[id[account[1]]] = account[0];
        }
        parent.resize(count);
        for(int i = 0; i < count; ++i) parent[i] = i;
        for(auto &account : accounts) {
            for(int i = 2; i < account.size(); ++i) {
                merge(id[account[1]], id[account[i]]);
            }
        }
        vector<vector<string>> answer;
        unordered_map<int, vector<int>> tmp;
        for(int i = 0; i < count; ++i) {
            tmp[find(i)].push_back(i);
        }
        for(auto [root, mails] : tmp) {
            vector<string> account{name[root]};
            for(auto id : mails) account.push_back(id2string[id]);
            sort(account.begin() + 1, account.end());
            answer.push_back(account);
        }
        return move(answer);
    }
};

// 49 / 49 test cases passed.
// Status: Accepted
// Runtime: 80 ms
// Memory Usage: 35.2 MB

```

## Map Sum Pairs

``` cpp
class MapSum {
    map<string, int> mp;
public:    
    void insert(string key, int val) {
        mp[key] = val;
    }
    
    int sum(string prefix) {
        int result = 0;
        bool found = false;
        for(auto &[s, v] : mp) {
            if(s.rfind(prefix, 0) == 0) {
                found = true;
                result += v;
            } else {
                if(found) break;
            }
        }
        return result;
    }
};
```

## Matrix Diagonal Sum

too easy to review

## Average of Levels in Binary Tree

too easy to review

## Intersection of Two Linked Lists

``` cpp
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> st;
        while(headA) {
            st.insert(headA);
            headA = headA->next;
        }
        while(headB) {
            if(st.count(headB)) return headB;
            headB = headB->next;
        }
        return nullptr;
    }
};

// 46 / 46 test cases passed.
// Status: Accepted
// Runtime: 52 ms
// Memory Usage: 17.1 MB

```

## Missing number

too easy to review

# March LeetCoding Challenge6

**Short Encoding of Words**

## Description

A **valid encoding** of an array of `words` is any reference string `s` and array of indices `indices` such that:

- `words.length == indices.length`
- The reference string `s` ends with the `'#'` character.
- For each index `indices[i]`, the **substring** of `s` starting from `indices[i]` and up to (but not including) the next `'#'` character is equal to `words[i]`.

Given an array of `words`, return *the **length of the shortest reference string*** `s` *possible of any **valid encoding** of* `words`*.*

 

**Example 1:**

```
Input: words = ["time", "me", "bell"]
Output: 10
Explanation: A valid encoding would be s = "time#bell#" and indices = [0, 2, 5].
words[0] = "time", the substring of s starting from indices[0] = 0 to the next '#' is underlined in "time#bell#"
words[1] = "me", the substring of s starting from indices[1] = 2 to the next '#' is underlined in "time#bell#"
words[2] = "bell", the substring of s starting from indices[2] = 5 to the next '#' is underlined in "time#bell#"
```

**Example 2:**

```
Input: words = ["t"]
Output: 2
Explanation: A valid encoding would be s = "t#" and indices = [0].
```

 

**Constraints:**

- `1 <= words.length <= 2000`
- `1 <= words[i].length <= 7`
- `words[i]` consists of only lowercase letters.

## Solution

we only need to check if one word is postfix of some other word.

reverse words then sort lexicographic order, if one word is postfix of some other word, that word must occur just after the word.

``` cpp
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        for(auto &word : words) reverse(word.begin(), word.end());
        sort(words.begin(), words.end());
        int answer = 0;
        int len = words.size();
        for(int i = 0; i < len; ++i) {
            bool unique = true;
            if(i < len - 1 && words[i + 1].rfind(words[i], 0) == 0) unique = false;
            if(unique) answer += words[i].length() + 1;
        }
        return answer;
    }
};

// You are here!
// Your runtime beats 100.00 % of cpp submissions.
// You are here!
// Your memory usage beats 94.00 % of cpp submissions.

```