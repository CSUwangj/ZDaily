+++
updated = 2026-01-22T13:13:49+01:00
title = "2026-01-22 Daily Challenge"
path = "2026-01-22-Daily-Challenge"
date = 2026-01-22T13:13:49+01:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 22

## Description

**Minimum Pair Removal to Sort Array I**

<p>Given an array <code>nums</code>, you can perform the following operation any number of times:</p>

<ul>
	<li>Select the <strong>adjacent</strong> pair with the <strong>minimum</strong> sum in <code>nums</code>. If multiple such pairs exist, choose the leftmost one.</li>
	<li>Replace the pair with their sum.</li>
</ul>

<p>Return the <strong>minimum number of operations</strong> needed to make the array <strong>non-decreasing</strong>.</p>

<p>An array is said to be <strong>non-decreasing</strong> if each element is greater than or equal to its previous element (if it exists).</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [5,2,3,1]</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>The pair <code>(3,1)</code> has the minimum sum of 4. After replacement, <code>nums = [5,2,4]</code>.</li>
	<li>The pair <code>(2,4)</code> has the minimum sum of 6. After replacement, <code>nums = [5,6]</code>.</li>
</ul>

<p>The array <code>nums</code> became non-decreasing in two operations.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,2,2]</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<p>The array <code>nums</code> is already sorted.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 50</code></li>
	<li><code>-1000 &lt;= nums[i] &lt;= 1000</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
    typedef long long ll;
    int minimumPairRemoval(vector<int>& nums1) {
        int n = nums1.size();

        //converting nums to long long to avoid overflow.
        vector<ll> nums(n,0);
        for(int i=0;i<n;i++){
            nums[i] = nums1[i];
        }

        //we created next and prev arrays to make nums as doubly linked list
        vector<int> nextIndex(n),prevIndex(n);

        for(int i=0;i<n;i++){
            nextIndex[i] = i+1;
        }

        for(int i=0;i<n;i++){
            prevIndex[i] = i-1;
        }

        //ordered set that stores {sum,i} in increasing order
        //set.begin() -> smallest sum at index i
        set<pair<ll,int>> pairSumSet;

        //stores total pairs which are in out of order.
        //if badPairCount is zero then already in asc order
        int badPairCount = 0;

        for(int i=0;i<n-1;i++){
            //count pairs
            if(nums[i] > nums[i+1])badPairCount++;

            //store {sum,i} 
            pairSumSet.insert({nums[i]+nums[i+1], i});
        }

        //stores total mergeOperations happend
        int mergeOperations = 0;

        while(badPairCount > 0){

            //pairSumSet.begin() -> {sum,i} smallest sum and index of sum
            auto it = pairSumSet.begin();
            int currIdx = it->second;
            int nextIdx = nextIndex[currIdx];
            int prevIdx = prevIndex[currIdx];

            //curr->next->next
            int nextNextIdx = nextIndex[nextIdx];

            pairSumSet.erase(it);

            if(nums[currIdx] > nums[nextIdx])badPairCount--;

            if(prevIdx >= 0){
                if(nums[prevIdx] > nums[currIdx]) badPairCount--;
                if(nums[prevIdx] > nums[currIdx] + nums[nextIdx]) badPairCount++;
                pairSumSet.erase({nums[prevIdx] + nums[currIdx], prevIdx});
            }

            if(nextNextIdx < n){
                if(nums[nextIdx] > nums[nextNextIdx]) badPairCount--;
                if(nums[currIdx] + nums[nextIdx] > nums[nextNextIdx]) badPairCount++;
                pairSumSet.erase({nums[nextIdx] + nums[nextNextIdx], nextIdx});
            }

            //updation of set after merge operation happens
            
            //before merge operation 
            // prev <=> curr <=> next <=> nextNext

            //after merge operation
            // prev <=> curr+next <=> nextNext

            nums[currIdx] = nums[currIdx] + nums[nextIdx];

            nextIndex[currIdx] = nextNextIdx;
            if(nextNextIdx < n) prevIndex[nextNextIdx] = currIdx;

            if(prevIdx >= 0){
                pairSumSet.insert({nums[prevIdx] + nums[currIdx], prevIdx});
            }

            if(nextNextIdx < n){
                pairSumSet.insert({nums[currIdx] + nums[nextNextIdx], currIdx});
            }

            mergeOperations++;
        }
        return mergeOperations;
    }
};

// Accepted
// 37/37 cases passed (125 ms)
// Your runtime beats 97.77 % of cpp submissions
// Your memory usage beats 30.13 % of cpp submissions (100.1 MB)
```
