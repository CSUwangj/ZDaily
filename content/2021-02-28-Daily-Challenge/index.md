+++
title = "2021-02-28 Daily-Challenge"
path = "2021-02-28-Daily-Challenge"
date = 2021-02-28 13:44:36+08:00
updated = 2021-02-28 20:28:26+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Sunday, I gonna review the tasks I've done this week, and finish today's leetcode's [February LeetCoding Challenge](https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/587/week-4-february-22nd-february-28th/3654/) with `cpp`.


<!-- more -->

# LeetCode Review

## Furthest Building You Can Reach

``` cpp
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> q;
        int len = heights.size();
        for(int i = 0; i < len - 1; ++i) {
            if(heights[i] < heights[i + 1]) {
                q.push(heights[i] - heights[i + 1]);
            }
            if(q.size() > ladders) {
                bricks += q.top();
                q.pop();
            }
            if(bricks < 0) return i;
        }
        return len - 1;
    }
};
```

## Smallest Subsequence of Distinct Characters

``` cpp
class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> cnt(26);
        for(auto c : s) cnt[c - 'a'] += 1;
        vector<bool> used(26);
        string answer;
        for(auto c : s) {
            if(used[c - 'a']) {
                cnt[c - 'a'] -= 1;
                continue;
            }
            while(answer.length() && answer.back() > c && cnt[answer.back() - 'a']) {
                used[answer.back() - 'a'] = false;
                answer.pop_back();
            }
            answer.push_back(c);
            used[c - 'a'] = true;
            cnt[c - 'a'] -= 1;
        }
        return answer;
    }
};
```

## Delete Nodes And Return Forest

``` cpp
class Solution {
    TreeNode* delRoot(TreeNode *root, vector<TreeNode*> &answer, unordered_set<int> &to_delete) {
        if(!root) return nullptr;
        root->left = delRoot(root->left, answer, to_delete);
        root->right = delRoot(root->right, answer, to_delete);
        if(to_delete.count(root->val)) {
            if(root->left) answer.push_back(root->left);
            if(root->right) answer.push_back(root->right);
            return nullptr;
        }
        return root;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> answer;
        unordered_set<int> st(to_delete.begin(), to_delete.end());
        if(delRoot(root, answer, st)) answer.push_back(root);
        return move(answer);
    }
};
```

## Bulb Switcher III

too easy to review

## Dungeon Game

dp forward cannot form a optimal structure, because maximum current HP does not mean maximum historical HP. take an example

<table><tbody>
    <tr>
        <td>0</td>
        <td>-5</td>
        <td>100</td>
    </tr>
    <tr>
        <td>-1</td>
        <td>1</td>
        <td>0</td>
    </tr>
</tbody></table>

but if we dp backwords, we can get a optimal structure. instead of finding path towards destination, we try to find the way from the princess to knight. we keep track of minimum HP needed for pass through the rest of path.

``` cpp
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows = dungeon.size();
        int cols = dungeon.front().size();
        if(dungeon.back().back() > 0) dungeon.back().back() = 0;
        for(int row = rows - 1; row >= 0; row -= 1) {
            for(int col = cols - 1; col >= 0; col -= 1) {
                if(col == cols - 1 && row == rows - 1) continue;
                int maxDown = row == rows - 1 ? INT_MIN : dungeon[row + 1][col];
                int maxRight = col == cols - 1 ? INT_MIN : dungeon[row][col + 1];
                int target = max(maxDown, maxRight) + dungeon[row][col];
                dungeon[row][col] = target < 0 ? target : 0;
            }
        }
        return dungeon.front().front() < 1 ? 1 - dungeon.front().front() : 1;
    }
};

```

# February LeetCoding Challenge28

**Maximum Frequency Stack**

## Description

Implement `FreqStack`, a class which simulates the operation of a stack-like data structure.

`FreqStack` has two functions:

- `push(int x)`, which pushes an integer `x` onto the stack.

- ```
  pop()
  ```

  , which

   

  removes

   

  and returns the most frequent element in the stack.

  - If there is a tie for most frequent element, the element closest to the top of the stack is removed and returned.

 

**Example 1:**

```
Input: 
["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"],
[[],[5],[7],[5],[7],[4],[5],[],[],[],[]]
Output: [null,null,null,null,null,null,null,5,7,5,4]
Explanation:
After making six .push operations, the stack is [5,7,5,7,4,5] from bottom to top.  Then:

pop() -> returns 5, as 5 is the most frequent.
The stack becomes [5,7,5,7,4].

pop() -> returns 7, as 5 and 7 is the most frequent, but 7 is closest to the top.
The stack becomes [5,7,5,4].

pop() -> returns 5.
The stack becomes [5,7,4].

pop() -> returns 4.
The stack becomes [5,7].
```

 

**Note:**

- Calls to `FreqStack.push(int x)` will be such that `0 <= x <= 10^9`.
- It is guaranteed that `FreqStack.pop()` won't be called if the stack has zero elements.
- The total number of `FreqStack.push` calls will not exceed `10000` in a single test case.
- The total number of `FreqStack.pop` calls will not exceed `10000` in a single test case.
- The total number of `FreqStack.push` and `FreqStack.pop` calls will not exceed `150000` across all test cases.

## Solution

I first come up with a solution using list and insert, just like [LRU Cache](https://leetcode.com/problems/lru-cache/)

``` cpp
class FreqStack {
    unordered_map<int, vector<list<pair<int, int>>::iterator>> pos;
    list<pair<int, int>> count;
public:
    FreqStack() {}
    
    void push(int x) {
        int sz = pos[x].size();
        auto p = make_pair(sz, x);
        auto it = lower_bound(count.begin(), count.end(), p, [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.first > b.first;
        });
        it = count.insert(it, p);
        pos[x].push_back(it);
    }
    
    int pop() {
        int result = count.front().second;
        count.pop_front();
        pos[result].pop_back();
        return result;
    }
};

// 37 / 37 test cases passed, but took too long.
// Status: Time Limit Exceeded
// Submitted: 20 minutes ago
```

then I'm trying to optimize this solution

I found that iterator is useless

``` cpp
class FreqStack {
    unordered_map<int, int> pos;
    list<pair<int, int>> count;
public:
    FreqStack() {}
    
    void push(int x) {
        int sz = pos[x];
        auto p = make_pair(sz, x);
        auto it = lower_bound(count.begin(), count.end(), p, [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.first > b.first;
        });
        it = count.insert(it, p);
        pos[x] += 1;
    }
    
    int pop() {
        int result = count.front().second;
        count.pop_front();
        pos[result] -= 1;
        return result;
    }
};

// 37 / 37 test cases passed, but took too long.
// Status: Time Limit Exceeded

```

I thought pair was too slow

``` cpp
class FreqStack {
    struct p {
        int size;
        int value;
        bool operator <(const p &other) const {
            return this->size > other.size;
        }
    };
    unordered_map<int, int> pos;
    list<p> count;
public:
    FreqStack() {}
    
    void push(int x) {
        int sz = pos[x];
        auto pa = p{sz, x};
        auto it = lower_bound(count.begin(), count.end(), pa);
        it = count.insert(it, pa);
        pos[x] += 1;
    }
    
    int pop() {
        int result = count.front().value;
        count.pop_front();
        pos[result] -= 1;
        return result;
    }
};

// 37 / 37 test cases passed, but took too long.
// Status: Time Limit Exceeded

```

I found I can use `priority_queue`

``` cpp
class FreqStack {
    struct p {
        int size;
        int pos;
        int value;
        bool operator <(const p &other) const {
            return this->size < other.size || (this->size == other.size && this->pos < other.pos);
        }
    };
    int pos = 0;
    unordered_map<int, int> count;
    priority_queue<p> q;
public:
    FreqStack() {}
    
    void push(int x) {
        int sz = count[x];
        auto pa = p{sz, pos++, x};
        q.push(pa);
        count[x] += 1;
    }
    
    int pop() {
        int result = q.top().value;
        q.pop();
        count[result] -= 1;
        return result;
    }
};

// 37 / 37 test cases passed.
// Status: Accepted
// Runtime: 180 ms
// Memory Usage: 79.1 MB

```

And I learned from solution to use stack to solve it.

``` cpp
class FreqStack {
    unordered_map<int, int> freq;
    unordered_map<int, vector<int>> stacks;
    int maxFreq = 0;
public:    
    void push(int x) {
        freq[x] += 1;
        stacks[freq[x]].push_back(x);
        maxFreq = max(maxFreq, freq[x]);
    }
    
    int pop() {
        int value = stacks[maxFreq].back();
        stacks[maxFreq].pop_back();
        freq[value] -= 1;
        if(stacks[maxFreq].empty()) maxFreq -= 1;
        return value;
    }
};

// 37 / 37 test cases passed.
// Status: Accepted
// Runtime: 168 ms
// Memory Usage: 79.7 MB

```
