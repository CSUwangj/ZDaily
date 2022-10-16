+++
title = "2021-01-09 Daily-Challenge"
path = "2021-01-09-Daily-Challenge"
date = 2021-01-09 11:57:46+08:00
updated = 2021-01-09 20:48:55+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [January LeetCoding Challenge](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/580/week-2-january-8th-january-14th/3598/) with `cpp`.

<!-- more -->

# LeetCode Review

## Minimum Remove to Make Valid Parentheses

track of if characters are removed instead of build string,
inplace edit will be better at speed and space usage, but won't be
so readable

``` cpp
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int len = s.length();
        vector<bool> removed(len);
        stack<int> st;
        for(int i = 0; i < len; ++i) {
            if(s[i] == '(') {
                st.push(i);
            } else if(s[i] == ')') {
                if(st.empty()) removed[i] = true;
                else st.pop();
            }
        }
        while(!st.empty()) {
            removed[st.top()] = true;
            st.pop();
        }
        string answer;
        for(int i = 0; i < len; ++i) {
            if(!removed[i]) answer.push_back(s[i]);
        }
        return answer;
    }
};
```

## Partition List

use two list

``` cpp
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *lessPart = new ListNode(-1);
        ListNode *lessCur = lessPart;
        ListNode *greaterPart = new ListNode(-1);
        ListNode *greaterCur = greaterPart;
        while(head) {
            if(head->val < x) {
                lessCur->next = head;
                lessCur = lessCur->next;
            } else {
                greaterCur->next = head;
                greaterCur = greaterCur->next;
            }
            head = head->next;
        }
        lessCur->next = greaterPart->next;
        greaterCur->next = nullptr;
        head = lessPart->next;
        delete lessPart;
        delete greaterPart;
        return head;
    }
};
```

## Remove Duplicates from Sorted List II

too easy to review

## Minimum Swaps To Make Sequences Increasing

dp

``` cpp
class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int /*swap = 1, keep = 0, */len = A.size();
        vector<int> swap(len);
        vector<int> keep(len);
        swap[0] = 1;
        for(int i = 1; i < len; ++i) {
            if(A[i] <= B[i-1] || B[i] <= A[i-1]) {
                swap[i] = swap[i-1] + 1;
                keep[i] = keep[i-1];
            } else if (A[i] <= A[i-1] || B[i] <= B[i-1]) {
                swap[i] = keep[i-1] + 1;
                keep[i] = swap[i-1];
            } else {
                swap[i] = min(swap[i-1], keep[i-1]) + 1;
                keep[i] = min(swap[i-1], keep[i-1]);
            }
        }
        return min(swap.back(), keep.back());
    }
};
```

dp with operation

``` cpp
class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int swapMove = 1, keepMove = 0, len = A.size();
        for(int i = 1; i < len; ++i) {
            if(A[i] <= B[i-1] || B[i] <= A[i-1]) {
                swapMove += 1;
            } else if (A[i] <= A[i-1] || B[i] <= B[i-1]) {
                swap(swapMove, keepMove);
                swapMove += 1;
            } else {
                int mmin = min(swapMove, keepMove);
                keepMove = mmin;
                swapMove = mmin + 1;
            }
        }
        return min(swapMove, keepMove);
    }
};
```

## Kth Missing Positive Number

too easy to review

## Verbal Arithmetic Puzzle

``` cpp
class Solution {
    char mp[128];
    bool leading[128] = {false};
    bool used[10] = {false};
    int resultLength = 0;
    
    bool dfs(vector<string> &words, string &result, int index, int pos, int sum) {
        // cout << index << ' ' << pos << ' ' << sum << endl;
        if(pos == resultLength) return sum == 0;
        if(index == words.size()) {
            if(mp[result[pos]] != -1 && mp[result[pos]] == sum%10) {
                return dfs(words, result, 0, pos+1, sum/10);
            }
            if(mp[result[pos]] == -1) {
                if(used[sum%10] || (sum%10 == 0 && leading[result[pos]])) return false;
                mp[result[pos]] = sum % 10;
                used[sum%10] = true;
                if(dfs(words, result, 0, pos+1, sum/10)) return true;
                mp[result[pos]] = -1;
                used[sum%10] = false;
            }
            return false;
        }
        if(pos >= words[index].length()) return dfs(words, result, index+1, pos, sum);
        if(mp[words[index][pos]] != -1) return dfs(words, result, index+1, pos, sum+mp[words[index][pos]]);
        for(int i = leading[words[index][pos]]; i < 10; ++i) {
            if(used[i]) continue;
            mp[words[index][pos]] = i;
            used[i] = true;
            if(dfs(words, result, index+1, pos, sum+i)) return true;
            mp[words[index][pos]] = -1;
            used[i] = false;
        }
        return false;
    }
public:
    bool isSolvable(vector<string>& words, string result) {
        for(auto &word : words) {
            if(resultLength < word.length()) resultLength = word.length();
            if(word.length() != 1)leading[word[0]] = true;
            for(auto c : word) mp[c] = -1;
            reverse(word.begin(), word.end());
        }
        
        if(resultLength > result.length()) return false;
        resultLength = result.length();
        if(result.length() != 1) leading[result[0]] = true;
        for(auto c : result) mp[c] = -1;
        reverse(result.begin(), result.end());
        
        return dfs(words, result, 0, 0, 0);
    }
};
```

## Check If Two String Arrays are Equivalent

too easy to review

## Thousand Separator

too easy to review

## Intersection of Two Linked Lists

``` cpp

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return nullptr;
        ListNode *curA = headA, *curB = headB;
        int swapA = 0, swapB = 0;
        while(swapA < 2) {
            if(curA == curB && curA) return curA;
            if(curA) curA = curA->next;
            else {
                if(!swapA) {
                    curA = headB;
                    swapA += 1;
                } else {
                    curA = headA;
                    swapA += 1;
                }
            }
            if(curB) curB = curB->next;
            else {
                if(!swapB) {
                    curB = headA;
                    swapB += 1;
                } else {
                    curB = headB;
                    swapB += 1;
                }
            }
        }
        return nullptr;
    }
};
```

## Customers Who Never Order

using parent pointers

``` SQL
SELECT Name as Customers FROM Customers
WHERE Id NOT IN
(SELECT CustomerId FROM Orders)
```

# January LeetCoding Challenge 9

## Description

**Word Ladder**

Given two words `beginWord` and `endWord`, and a dictionary `wordList`, return *the length of the shortest transformation sequence from* `beginWord` *to* `endWord`, *such that*:

- Only one letter can be changed at a time.
- Each transformed word must exist in the word list.

Return `0` if there is no such transformation sequence.

 

**Example 1:**

```
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog", return its length 5.
```

**Example 2:**

```
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
```

 

**Constraints:**

- `1 <= beginWord.length <= 100`
- `endWord.length == beginWord.length`
- `1 <= wordList.length <= 5000`
- `wordList[i].length == beginWord.length`
- `beginWord`, `endWord`, and `wordList[i]` consist of lowercase English letters.
- `beginWord != endWord`
- All the strings in `wordList` are **unique**.

## Solution

shortest path/BFS

``` cpp
class Solution {
    unordered_map<string, int> mp;
    unordered_map<int, int> dis;
    vector<vector<int>> neighbors;
    bool oneTransform(string &a, string &b) {
        int len = a.length();
        int cnt = 0;
        for(int i = 0; i < len; ++i) cnt += a[i] != b[i];
        return cnt == 1;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int len = wordList.size();
        for(int i = 0; i < len; ++i) mp[wordList[i]] = i;
        neighbors.resize(len+2);
        for(int i = 0; i < len-1; ++i) {
            for(int j = i+1; j < len; ++j) {
                if(oneTransform(wordList[i], wordList[j])) {
                    neighbors[i].push_back(j);
                    neighbors[j].push_back(i);
                }
            }
        }
        int offset = 0;
        if(!mp.count(beginWord)) {
            mp[beginWord] = len;
            offset += 1;
            for(int i = 0; i < len; ++i) {
                if(oneTransform(beginWord, wordList[i])) {
                    neighbors[i].push_back(len);
                    neighbors[len].push_back(i);
                }
            }
        }
        if(!mp.count(endWord)) return false;
        int begin = mp[beginWord], end = mp[endWord];
        dis[begin] = 1;
        queue<int> q;
        q.push(begin);
        while(q.size()) {
            int cur = q.front();
            q.pop();
            if(cur == end) return dis[cur];
            for(auto nxt : neighbors[cur]) {
                if(dis.count(nxt)) continue;
                dis[nxt] = dis[cur] + 1;
                q.push(nxt);
            }
        }
        return 0;
    }
};
```
