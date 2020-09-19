+++
title = "2019-02-17 Daily Challenge"
path = "2019-02-17-daily-challenge"
date = 2019-02-17T01:04:46+00:00
updated = 2020-09-19T20:01:27.631316+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "Math", "ProjectEuler", "Algorithm", "LeetCode",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *XOR decryption* in *Rust* and *Sort List* in *JavaScript*.

<!--more-->

# Math

## Problem

### XOR decryption

### Problem 59

> Please note that the file associated with this problem, 
> p059_cipher.txt, was changed on Tuesday 5 February 2019. 
> If you downloaded the file before this date, please download 
> the new version. This notice will remain for seven days.

Each character on a computer is assigned a unique code and 
the preferred standard is ASCII (American Standard Code for 
Information Interchange). For example, uppercase A = 65, 
asterisk (*) = 42, and lowercase k = 107.

A modern encryption method is to take a text file, convert 
the bytes to ASCII, then XOR each byte with a given value, 
taken from a secret key. The advantage with the XOR function 
is that using the same encryption key on the cipher text, 
restores the plain text; for example, 65 XOR 42 = 107, then 107 XOR 42 = 65.

For unbreakable encryption, the key is the same length as 
the plain text message, and the key is made up of random 
bytes. The user would keep the encrypted message and the 
encryption key in different locations, and without both "halves", 
it is impossible to decrypt the message.

Unfortunately, this method is impractical for most users, so the 
modified method is to use a password as a key. If the password 
is shorter than the message, which is likely, the key is repeated 
cyclically throughout the message. The balance for this method is 
using a sufficiently long password key for security, but short 
enough to be memorable.

Your task has been made easy, as the encryption key consists of 
three lower case characters. Using [p059_cipher.txt](https://projecteuler.net/project/resources/p059_cipher.txt) (right click and 'Save Link/Target As...'), 
a file containing the encrypted ASCII codes, and the knowledge 
that the plain text must contain common English words, decrypt 
the message and find the sum of the ASCII values in the original text.

## Solution

MTP hahaha.

Simply assume that space is most character~

## Implementation

```rust
fn main() {
    let cipher: [u8; 1455] = [36,22,80,0,0,4,23,25,19,17,88,4,4,19,21,11,88,
    22,23,23,29,69,12,24,0,88,25,11,12,2,10,28,5,6,12,25,10,22,80,10,30,80,10,
    22,21,69,23,22,69,61,5,9,29,2,66,11,80,8,23,3,17,88,19,0,20,21,7,10,17,17,
    29,20,69,8,17,21,29,2,22,84,80,71,60,21,69,11,5,8,21,25,22,88,3,0,10,25,0,
    10,5,8,88,2,0,27,25,21,10,31,6,25,2,16,21,82,69,35,63,11,88,4,13,29,80,22,
    13,29,22,88,31,3,88,3,0,10,25,0,11,80,10,30,80,23,29,19,12,8,2,10,27,17,9,
    11,45,95,88,57,69,16,17,19,29,80,23,29,19,0,22,4,9,1,80,3,23,5,11,28,92,69,
    9,5,12,12,21,69,13,30,0,0,0,0,27,4,0,28,28,28,84,80,4,22,80,0,20,21,2,25,
    30,17,88,21,29,8,2,0,11,3,12,23,30,69,30,31,23,88,4,13,29,80,0,22,4,12,10,
    21,69,11,5,8,88,31,3,88,4,13,17,3,69,11,21,23,17,21,22,88,65,69,83,80,84,
    87,68,69,83,80,84,87,73,69,83,80,84,87,65,83,88,91,69,29,4,6,86,92,69,15,
    24,12,27,24,69,28,21,21,29,30,1,11,80,10,22,80,17,16,21,69,9,5,4,28,2,4,12
    5,23,29,80,10,30,80,17,16,21,69,27,25,23,27,28,0,84,80,22,23,80,17,16,17
    17,88,25,3,88,4,13,29,80,17,10,5,0,88,3,16,21,80,10,30,80,17,16,25,22,88,3
    0,10,25,0,11,80,12,11,80,10,26,4,4,17,30,0,28,92,69,30,2,10,21,80,12,12,80
    4,12,80,10,22,19,0,88,4,13,29,80,20,13,17,1,10,17,17,13,2,0,88,31,3,88,4
    13,29,80,6,17,2,6,20,21,69,30,31,9,20,31,18,11,94,69,54,17,8,29,28,28,84
    80,44,88,24,4,14,21,69,30,31,16,22,20,69,12,24,4,12,80,17,16,21,69,11,5,8
    88,31,3,88,4,13,17,3,69,11,21,23,17,21,22,88,25,22,88,17,69,11,25,29,12,24
    69,8,17,23,12,80,10,30,80,17,16,21,69,11,1,16,25,2,0,88,31,3,88,4,13,29,80
    21,29,2,12,21,21,17,29,2,69,23,22,69,12,24,0,88,19,12,10,19,9,29,80,18,16
    31,22,29,80,1,17,17,8,29,4,0,10,80,12,11,80,84,67,80,10,10,80,7,1,80,21,13
    4,17,17,30,2,88,4,13,29,80,22,13,29,69,23,22,69,12,24,12,11,80,22,29,2,12
    29,3,69,29,1,16,25,28,69,12,31,69,11,92,69,17,4,69,16,17,22,88,4,13,29,80
    23,25,4,12,23,80,22,9,2,17,80,70,76,88,29,16,20,4,12,8,28,12,29,20,69,26,9
    69,11,80,17,23,80,84,88,31,3,88,4,13,29,80,21,29,2,12,21,21,17,29,2,69,12
    31,69,12,24,0,88,20,12,25,29,0,12,21,23,86,80,44,88,7,12,20,28,69,11,31,10
    22,80,22,16,31,18,88,4,13,25,4,69,12,24,0,88,3,16,21,80,10,30,80,17,16,25
    22,88,3,0,10,25,0,11,80,17,23,80,7,29,80,4,8,0,23,23,8,12,21,17,17,29,28
    28,88,65,75,78,68,81,65,67,81,72,70,83,64,68,87,74,70,81,75,70,81,67,80,4
    22,20,69,30,2,10,21,80,8,13,28,17,17,0,9,1,25,11,31,80,17,16,25,22,88,30
    16,21,18,0,10,80,7,1,80,22,17,8,73,88,17,11,28,80,17,16,21,11,88,4,4,19,25
    11,31,80,17,16,21,69,11,1,16,25,2,0,88,2,10,23,4,73,88,4,13,29,80,11,13,29
    7,29,2,69,75,94,84,76,65,80,65,66,83,77,67,80,64,73,82,65,67,87,75,72,69
    17,3,69,17,30,1,29,21,1,88,0,23,23,20,16,27,21,1,84,80,18,16,25,6,16,80,0
    0,0,23,29,3,22,29,3,69,12,24,0,88,0,0,10,25,8,29,4,0,10,80,10,30,80,4,88
    19,12,10,19,9,29,80,18,16,31,22,29,80,1,17,17,8,29,4,0,10,80,12,11,80,84
    86,80,35,23,28,9,23,7,12,22,23,69,25,23,4,17,30,69,12,24,0,88,3,4,21,21,69
    11,4,0,8,3,69,26,9,69,15,24,12,27,24,69,49,80,13,25,20,69,25,2,23,17,6,0
    28,80,4,12,80,17,16,25,22,88,3,16,21,92,69,49,80,13,25,6,0,88,20,12,11,19
    10,14,21,23,29,20,69,12,24,4,12,80,17,16,21,69,11,5,8,88,31,3,88,4,13,29
    80,22,29,2,12,29,3,69,73,80,78,88,65,74,73,70,69,83,80,84,87,72,84,88,91
    69,73,95,87,77,70,69,83,80,84,87,70,87,77,80,78,88,21,17,27,94,69,25,28,22
    23,80,1,29,0,0,22,20,22,88,31,11,88,4,13,29,80,20,13,17,1,10,17,17,13,2,0
    88,31,3,88,4,13,29,80,6,17,2,6,20,21,75,88,62,4,21,21,9,1,92,69,12,24,0,88
    3,16,21,80,10,30,80,17,16,25,22,88,29,16,20,4,12,8,28,12,29,20,69,26,9,69
    65,64,69,31,25,19,29,3,69,12,24,0,88,18,12,9,5,4,28,2,4,12,21,69,80,22,10
    13,2,17,16,80,21,23,7,0,10,89,69,23,22,69,12,24,0,88,19,12,10,19,16,21,22
    0,10,21,11,27,21,69,23,22,69,12,24,0,88,0,0,10,25,8,29,4,0,10,80,10,30,80
    4,88,19,12,10,19,9,29,80,18,16,31,22,29,80,1,17,17,8,29,4,0,10,80,12,11,80
    84,86,80,36,22,20,69,26,9,69,11,25,8,17,28,4,10,80,23,29,17,22,23,30,12,22
    23,69,49,80,13,25,6,0,88,28,12,19,21,18,17,3,0,88,18,0,29,30,69,25,18,9,29
    80,17,23,80,1,29,4,0,10,29,12,22,21,69,12,24,0,88,3,16,21,3,69,23,22,69,12
    24,0,88,3,16,26,3,0,9,5,0,22,4,69,11,21,23,17,21,22,88,25,11,88,7,13,17,19
    13,88,4,13,29,80,0,0,0,10,22,21,11,12,3,69,25,2,0,88,21,19,29,30,69,22,5,8
    26,21,23,11,94];
    let key:[u8; 3] = [key(&cipher, 0, 3), key(&cipher, 1, 3), key(&cipher, 2, 3)];
    let plain_text = otp_decrypt(&cipher, &key);
    println!("Plain text is \n```\n{}\n```", plain_text);
    let mut ans = 0;
    for i in plain_text.chars() {
        ans += i as i32;
    }
    println!("Answer is {}", ans);
}

fn key(cipher: &[u8], index: usize, length: usize) -> u8 {
    let mut max_cnt = 0;
    let mut ans = 0;
    for i in 97u8..123 {
        let mut cnt = 0;
        for j in (index..cipher.len()).step_by(length) {
            if cipher[j] ^ i == 32 {
                cnt += 1;
            }
        }
        if cnt > max_cnt {
            max_cnt = cnt;
            ans = i;
        }
    }
    ans
}

fn otp_decrypt(cipher: &[u8], key: &[u8]) -> String {
    let mut ans: String = String::new();
    for i in 0..cipher.len() {
        ans.push((cipher[i]^key[i%key.len()]) as char);
    }
    ans
}
```

# Algorithm

## Problem

### 148. Sort List

Sort a linked list in *O*(*n* log *n*) time using constant space complexity.

**Example 1:**

```
Input: 4->2->1->3
Output: 1->2->3->4
```

**Example 2:**

```
Input: -1->5->3->4->0
Output: -1->0->3->4->5
```

## Solution

simple mergesort.

## Implementation

```js
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var sortList = function(head) {
  if (head == null || head.next == null) return head;
  let prev = null;
  let mid = head;
  let end = head;
  while (end !== null && end.next !== null) {
    prev = mid;
    mid = mid.next;
    end = end.next.next;
  }
  prev.next = null;
  
  const  merge = (head1, head2) => {
    let tmp_head = new ListNode;
    let cur = tmp_head;
    while (head1 !== null && head2 !== null) {
      if (head1.val < head2.val) {
        cur.next = head1;
        head1 = head1.next;
      } else {
        cur.next = head2;
        head2 = head2.next;
      }
      cur = cur.next;
    }
    while (head1 !== null) {
      cur.next = head1;
      head1 = head1.next;
      cur = cur.next;
    }
    while (head2 !== null) {
      cur.next = head2;
      head2 = head2.next;
      cur = cur.next;
    }
    return tmp_head.next;
  };
  let l1 = sortList(head);
  let l2 = sortList(mid);
  return merge(l1, l2);
};
```