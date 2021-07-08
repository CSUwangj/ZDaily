+++
title = "2021-07-08 Daily-Challenge"
path = "2021-07-08-Daily-Challenge"
date = 2021-07-08 23:08:00+08:00
updated = 2021-07-08 23:20:20+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Apply Discount Every n Orders](https://leetcode.com/problems/apply-discount-every-n-orders/description/) and leetcode's [July LeetCoding Challenge](https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/609/week-2-july-8th-july-14th/3807/) with `cpp`.

<!-- more -->

# Apply Discount Every n Orders

## Description

There is a sale in a supermarket, there will be a `discount` every `n` customer.
There are some products in the supermarket where the id of the `i-th` product is `products[i]` and the price per unit of this product is `prices[i]`.
The system will count the number of customers and when the `n-th` customer arrive he/she will have a `discount` on the bill. (i.e if the cost is `x` the new cost is `x - (discount * x) / 100`). Then the system will start counting customers again.
The customer orders a certain amount of each product where `product[i]` is the id of the `i-th` product the customer ordered and `amount[i]` is the number of units the customer ordered of that product.

Implement the `Cashier` class:

- `Cashier(int n, int discount, int[] products, int[] prices)` Initializes the object with `n`, the `discount`, the `products` and their `prices`.
- `double getBill(int[] product, int[] amount)` returns the value of the bill and apply the discount if needed. Answers within `10^-5` of the actual value will be accepted as correct.

 

**Example 1:**

```
Input
["Cashier","getBill","getBill","getBill","getBill","getBill","getBill","getBill"]
[[3,50,[1,2,3,4,5,6,7],[100,200,300,400,300,200,100]],[[1,2],[1,2]],[[3,7],[10,10]],[[1,2,3,4,5,6,7],[1,1,1,1,1,1,1]],[[4],[10]],[[7,3],[10,10]],[[7,5,3,1,6,4,2],[10,10,10,9,9,9,7]],[[2,3,5],[5,3,2]]]
Output
[null,500.0,4000.0,800.0,4000.0,4000.0,7350.0,2500.0]
Explanation
Cashier cashier = new Cashier(3,50,[1,2,3,4,5,6,7],[100,200,300,400,300,200,100]);
cashier.getBill([1,2],[1,2]);                        // return 500.0, bill = 1 * 100 + 2 * 200 = 500.
cashier.getBill([3,7],[10,10]);                      // return 4000.0
cashier.getBill([1,2,3,4,5,6,7],[1,1,1,1,1,1,1]);    // return 800.0, The bill was 1600.0 but as this is the third customer, he has a discount of 50% which means his bill is only 1600 - 1600 * (50 / 100) = 800.
cashier.getBill([4],[10]);                           // return 4000.0
cashier.getBill([7,3],[10,10]);                      // return 4000.0
cashier.getBill([7,5,3,1,6,4,2],[10,10,10,9,9,9,7]); // return 7350.0, Bill was 14700.0 but as the system counted three more customers, he will have a 50% discount and the bill becomes 7350.0
cashier.getBill([2,3,5],[5,3,2]);                    // return 2500.0
```

 

**Constraints:**

- `1 <= n <= 10^4`
- `0 <= discount <= 100`
- `1 <= products.length <= 200`
- `1 <= products[i] <= 200`
- There are **not** repeated elements in the array `products`.
- `prices.length == products.length`
- `1 <= prices[i] <= 1000`
- `1 <= product.length <= products.length`
- `product[i]` exists in `products`.
- `amount.length == product.length`
- `1 <= amount[i] <= 1000`
- At most `1000` calls will be made to `getBill`.
- Answers within `10^-5` of the actual value will be accepted as correct.

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Cashier {
  unordered_map<int, int> prices;
  int discountOrder;
  int orderCount = 0;
  double discount;
public:
  Cashier(int n, int discount, vector<int>& products, vector<int>& prices): discountOrder(n) {
    this->discount = (100 - discount) / 100.0;
    for(int i = 0; i < products.size(); ++i) {
      this->prices[products[i]] = prices[i];
    }
  }
  
  double getBill(vector<int> product, vector<int> amount) {
    double answer = 0;
    for(int i = 0; i < product.size(); ++i) {
      answer += prices[product[i]] * amount[i];
    }
    if(++orderCount % discountOrder == 0) {
      answer *= discount;
    }
    return answer;
  }
};

// Accepted
// 25/25 cases passed (172 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 95.6 % of cpp submissions (120.3 MB)
```

# July LeetCoding Challenge7

## Description

**Kth Smallest Element in a Sorted Matrix**

Given an `n x n` `matrix` where each of the rows and columns are sorted in ascending order, return *the* `kth` *smallest element in the matrix*.

Note that it is the `kth` smallest element **in the sorted order**, not the `kth` **distinct** element.

 

**Example 1:**

```
Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
```

**Example 2:**

```
Input: matrix = [[-5]], k = 1
Output: -5
```

 

**Constraints:**

<ul>
	<li><code>n == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 300</code></li>
	<li><code>-10<sup>9</sup> &lt;= matrix[i][j] &lt;= 10<sup>9</sup></code></li>
	<li>All the rows and columns of <code>matrix</code> are <strong>guaranteed</strong> to be sorted in <strong>non-decreasing order</strong>.</li>
	<li><code>1 &lt;= k &lt;= n<sup>2</sup></code></li>
</ul>


## Solution

heard someone said that brute force will Time Limit Exceeded?

``` cpp
class Solution {
public:
  int findLength(vector<int>& nums1, vector<int>& nums2) {
    int len1 = nums1.size();
    int len2 = nums2.size();
    int answer = 0;
    for(int i = 0; i < len1; i++) {
      if(answer > len1 - i) break;
      for(int j = 0; j < len2; j++) {
        if(answer > len2 - j) break;
        int k = 0;;
        while(i + k < len1 && j + k < len2 && nums1[i + k] == nums2[j + k]){
          k += 1;
        }
        answer = max(k, answer);
      }
    }
    return answer;
  }
};

// Accepted
// 55/55 cases passed (880 ms)
// Your runtime beats 5.07 % of cpp submissions
// Your memory usage beats 98.96 % of cpp submissions (11.5 MB)
```
