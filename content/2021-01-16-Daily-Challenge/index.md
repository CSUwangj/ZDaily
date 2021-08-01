+++
title = "2021-01-16 Daily-Challenge"
path = "2021-01-16-Daily-Challenge"
date = 2021-01-16 16:06:57+08:00
updated = 2021-01-16 22:47:01+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [January LeetCoding Challenge](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/581/week-3-january-15th-january-21st/3606/) with `cpp`.

<!-- more -->

# LeetCode Review

## Reverse Nodes in k-Group

reversing nodes group every k steps instead of get length and reverse

``` cpp
class Solution {
    ListNode* reverseKNodes(ListNode* head, int k) {
        ListNode *tail = nullptr;
        ListNode *next;
        while(k--) {
            next = head->next;
            head->next = tail;
            tail = head;
            head = next;
        }
        return tail;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *newHead = new ListNode();
        ListNode *cur = head;
        ListNode *newTail = newHead;
        while(cur) {
            // cout << cur << ' ' << cur->val << endl;
            bool longEnough = true;
            ListNode *groupHead = cur;
            for(int i = 0; i < k; ++i) {
                if(!cur) {
                    longEnough = false;
                    break;
                }
                cur = cur->next;
            }
            if(longEnough) {
                newTail->next = reverseKNodes(groupHead, k);
                while(newTail->next) newTail = newTail->next;
            } else {
                newTail->next = groupHead;
            }
        }
        return newHead->next;
    }
};
```

## Merge Sorted Array

``` cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while(m && n) {
            if(nums1[m-1] > nums2[n-1]) {
                nums1[m+n-1] = nums1[m-1];
                m -= 1;
            } else {
                nums1[m+n-1] = nums2[n-1];
                n -= 1;
            }
        }
        while(n) {
            nums1[n-1] = nums2[n-1];
            n -= 1;   
        }
    }
};
```

## Best Time to Buy and Sell stock

``` cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mmin = prices.front();
        int answer = 0;
        for(auto i : prices) {
            mmin = min(i, mmin);
            answer = max(answer, i - mmin);
        }
        return answer;
    }
};
```

## Add Two Numbers

too easy to review

## Boats to Save People

``` cpp
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int begin = 0, end = people.size()-1;
        int answer = 0;
        while(begin < end) {
            if(people[begin]+people[end] <= limit) {
                begin += 1;
            }
            end -= 1;
            answer += 1;
        }
        if(begin == end) answer += 1;
        return answer;
    }
};
```

## Nth Magical Number

``` cpp
class Solution {
    const int MOD = 1e9 + 7;
    int gcd(int a, int b) { return b ? gcd(b, a%b): a; }
    int count(int x, int a, int b) {
        return x / a + x / b;
    }
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long answer = 0;
        long long lcm = a / gcd(a, b) * b;
        long long round = lcm / a + lcm / b - 1;
        answer = (lcm * (n / round)) % MOD;
        int rest = n % round;
        long long begin = 0, end = lcm-1;
        while(begin < end) {
            int mid = (begin + end) / 2;
            if(count(mid, a, b) < rest) {
                begin = mid + 1;
            } else {
                end = mid;
            }
        }
        answer = (answer + begin) % MOD;
        return answer;
    }
};
```

## Minimum Operations to Reduce X to Zero

``` cpp
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int, int> sumLeft, sumRight;
        int len = nums.size();
        int sum = 0;
        for(int i = 0; i < len; ++i) {
            sum += nums[i];
            sumLeft[sum] = i+1;
        }
        sumLeft[0] = 0;
        sum = 0;
        for(int i = 1; i <= len; ++i) {
            sum += nums[len-i];
            sumRight[sum] = i;
        }
        sumRight[0] = 0;
        
        int answer = INT_MAX;
        for(auto [sum, cnt] : sumLeft) {
            if(sumRight.count(x-sum) && cnt+sumRight[x-sum] <= len) answer = min(answer, cnt+sumRight[x-sum]);
        }
        return answer == INT_MAX ? -1 : answer;
    }
};
```

## Get Maximum in Generated Array

``` cpp
class Solution {
public:
    int getMaximumGenerated(int n) {
        if(!n) return n;
        vector<int> nums(n+2);
        nums[1] = 1;
        for(int i = 1; i*2-2 < n; ++i) {
            nums[i+i-1] = nums[i] + nums[i-1];
            nums[i*2] = nums[i];
        }
        int answer = 0;
        for(auto i : nums) answer = max(answer, i);
        return answer;
    }
};
```

## Copy List with Random Pointer

not using unordered_map

``` cpp
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *cur = head;
        while(cur) {
            Node *newNode = new Node(cur->val);
            newNode->next = cur->next;
            newNode->random = cur->random;
            cur->next = newNode;
            cur = cur->next->next;
        }
        cur = head;
        while(cur) {
            cur = cur->next;
            if(cur->random != nullptr) cur->random = cur->random->next;
            cur = cur->next;
        }
        
        Node *newHead = new Node(-1);
        Node *newCur = newHead;
        cur = head;
        while(cur) {
            newCur->next = cur->next;
            cur->next = cur->next->next;
            newCur = newCur->next;
            cur = cur->next;
        }
        return newHead->next;
    }
};
```

## LRU Cache

more method, but seems not more elegant.

``` cpp
class LRUCache {
    int capacity;
    list<int> LRU;
    unordered_map<int, int> kv;
    unordered_map<int, list<int>::iterator> position;
    
    void update(int key) {
        LRU.erase(position[key]);
        add(key);
    }
    
    void add(int key) {
        LRU.push_front(key);
        position[key] = LRU.begin();
    }
    
    void evict_last() {
        kv.erase(LRU.back());
        position.erase(LRU.back());
        LRU.pop_back(); 
    }
public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        if(kv.count(key)) {
            update(key);
            return kv[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(kv.count(key)) {
            update(key);
        } else {
            if(LRU.size() == capacity) evict_last();
            add(key);
        }
        kv[key] = value;
    }
};
```

## Reverse Words in a String

``` cpp
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int len = s.length();
        bool hasSpace = true;
        int newLength = 0;
        for(int i = 0; i < len; ++i) {
            if(s[i] != ' ' || !hasSpace) {
                if(s[i] == ' ') hasSpace = true;
                else hasSpace = false;
                s[newLength] = s[i];
                newLength += 1;
            }
        }
        if(!newLength) return "";
        if(s[newLength-1] == ' ') newLength -= 1;
        s.resize(newLength);
        len = newLength;
        int begin = -1, end = -1;
        for(int i = 0; i < len; ++i) {
            if(s[i] != ' ') {
                if(begin == -1) begin = i;
                end = i+1;
            } else {
                if(begin != -1 && begin != end-1) {
                    reverse(s.begin()+begin, s.begin()+end);
                }
                begin = -1;
                end = -1;
            }
        }
        if(begin != -1 && begin != end-1) reverse(s.begin()+begin, s.begin()+end);
        return move(s);
    }
};
```

## Spiral Matrix

one dimensional, but more ugly

``` cpp
class Solution {
    int moves[4];
    vector<bool> visit;
    int cols;
    int total;
    
    void init() {
        moves[0] = 1;
        moves[1] = cols;
        moves[2] = -1;
        moves[3] = -cols;
    }
    
    bool check(int pos, int direction) {
        return (direction == 0 && !((pos+1) % cols)) || \
                (pos + moves[direction] >= total)    || \
                (direction == 2 && !(pos % cols))    || \
                (pos + moves[direction] < 0)         || \
                visit[pos+moves[direction]]; 
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        cols = matrix.front().size();
        total = cols * matrix.size();
        init();
        visit.resize(total);
        vector<int> answer;
        int direction = 0, pos = 0;
        while(answer.size() < total) {
            answer.push_back(matrix[pos/cols][pos%cols]);
            visit[pos] = true;
            int turns = 0;
            while(turns < 4 && check(pos, direction)) {
                turns += 1;
                direction = (direction + 1) % 4;
            }
            pos += moves[direction];
        }
        return move(answer);
    }
};
```

# January LeetCoding Challenge 16

## Description

**Kth Largest Element in an Array**

Find the **k**th largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

**Example 1:**

```
Input: [3,2,1,5,6,4] and k = 2
Output: 5
```

**Example 2:**

```
Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
```

**Note:**
You may assume k is always valid, 1 ≤ k ≤ array's length.

## Solution

the algorithm behind kth element is partition of quicksort, complexity of the algorithm is $O(n)$ by amortization analysis

``` cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin()+k-1, nums.end(), greater<int>());
        return nums[k-1];
    }
};
```
