+++
title = "2021-08-24 Daily-Challenge"
path = "2021-08-24-Daily-Challenge"
date = 2021-08-24 20:53:03+08:00
updated = 2021-08-24 22:24:42+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Sum Root to Leaf Numbers](https://leetcode.com/problems/sum-root-to-leaf-numbers/description/) and leetcode's [August LeetCoding Challenge](https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/616/week-4-august-22nd-august-28th/3908/) with `cpp`.

<!-- more -->

# Sum Root to Leaf Numbers

## Description

You are given the `root` of a binary tree containing digits from `0` to `9` only.

Each root-to-leaf path in the tree represents a number.

- For example, the root-to-leaf path `1 -> 2 -> 3` represents the number `123`.

Return *the total sum of all root-to-leaf numbers*. Test cases are generated so that the answer will fit in a **32-bit** integer.

A **leaf** node is a node with no children.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/02/19/num1tree.jpg)

```
Input: root = [1,2,3]
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/02/19/num2tree.jpg)

```
Input: root = [4,9,0,5,1]
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[1, 1000]`.
- `0 <= Node.val <= 9`
- The depth of the tree will not exceed `10`.

## Solution

``` cpp
class Solution {
public:
    int sumNumbers(TreeNode* root, int cur = 0) {
      if(!root) return 0;
      cur = cur * 10 + root->val;
      if(root->left || root->right) return sumNumbers(root->left, cur) + sumNumbers(root->right, cur);
      return cur;
    }
};

// Accepted
// 108/108 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 80.09 % of cpp submissions (9.1 MB)
```

# August LeetCoding Challenge 24

## Description

**Complex Number Multiplication**

A [complex number](https://en.wikipedia.org/wiki/Complex_number) can be represented as a string on the form `"**real**+**imaginary**i"` where:

- `real` is the real part and is an integer in the range `[-100, 100]`.
- `imaginary` is the imaginary part and is an integer in the range `[-100, 100]`.
- `i2 == -1`.

Given two complex numbers `num1` and `num2` as strings, return *a string of the complex number that represents their multiplications*.

 

**Example 1:**

```
Input: num1 = "1+1i", num2 = "1+1i"
Output: "0+2i"
Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
```

**Example 2:**

```
Input: num1 = "1+-1i", num2 = "1+-1i"
Output: "0+-2i"
Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
```

 

**Constraints:**

- `num1` and `num2` are valid complex numbers.

## Solution

``` cpp
class Complex {
private:
  int real;
  int imag;
public:
  Complex() : real(0), imag(0) {}
  Complex(string s): real(0), imag(0) {
    int pos = 0;
    bool realNegative = false;
    bool imagNegative = false;
    if(s[pos] == '-') {
      realNegative = true;
      pos += 1;
    }
    while(s[pos] != '+') {
      real *= 10;
      real += s[pos++] - '0';
    }
    pos += 1;
    if(s[pos] == '-') {
      imagNegative = true;
      pos += 1;
    }
    while(s[pos] != 'i') {
      imag *= 10;
      imag += s[pos++] - '0';
    }
    if(realNegative) real *= -1;
    if(imagNegative) imag *= -1;
  }
  string to_string() {
    bool realNegative = false;
    bool imagNegative = false;
    int real = this->real;
    int imag = this->imag;
    if(real < 0) {
      real = -real;
      realNegative = true;
    }
    if(imag < 0) {
      imag = -imag;
      imagNegative = true;
    }
    string result{'i'};
    if(imag) {
      while(imag) {
        result.push_back(imag % 10 + '0');
        imag /= 10;
      }
    } else {
      result.push_back('0');
    }
    if(imagNegative) result.push_back('-');
    result.push_back('+');
    if(real) {
      while(real) {
        result.push_back(real % 10 + '0');
        real /= 10;
      } 
    } else {
      result.push_back('0');
    }
    if(realNegative) result.push_back('-');
    reverse(result.begin(), result.end());
    return result;
  }
  Complex operator*(const Complex& b) {
    Complex result;
    result.real =  this->real * b.real - this->imag * b.imag;
    result.imag = this->imag * b.real + b.imag * this->real;
    return result;
  }
  // friend ostream & operator<<(ostream &os, const Complex &a);
};
// ostream & operator<<(ostream &os, const Complex &a) {
//   os << '(' << a.real << ',' << a.imag << ')';
//   return os;
// }
class Solution {
public:
  string complexNumberMultiply(string num1, string num2) {
    Complex n1(num1), n2(num2);
    // cout << n1.to_string() << ' ' << n2.to_string() << endl;
    // cout << n1 << ' ' << n2 << endl;
    auto result = n1 * n2;
    return result.to_string();
  }
};

// Accepted
// 55/55 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 62.22 % of cpp submissions (6 MB)
```
