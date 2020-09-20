+++
title = "2019-03-10 Daily Challenge"
path = "2019-03-10-daily-challenge"
date = 2019-03-10T00:04:01+00:00
updated = 2020-09-19T20:01:27.633312+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "CodeWars",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Where my anagrams at?* in *JavaScript*.

<!-- more -->

# CodeWars

## Problem

### Where my anagrams at?


What is an anagram? Well, two words are anagrams of each other if they both contain the same letters. For example:

```
'abba' & 'baab' == true

'abba' & 'bbaa' == true

'abba' & 'abbba' == false

'abba' & 'abca' == false
```

Write a function that will find all the anagrams of a word from a list. You will be given two inputs a word and an array with words. You should return an array of all the anagrams or an empty array if there are none. For example:

```javascript
anagrams('abba', ['aabb', 'abcd', 'bbaa', 'dada']) => ['aabb', 'bbaa']

anagrams('racer', ['crazer', 'carer', 'racar', 'caers', 'racer']) => ['carer', 'racer']

anagrams('laser', ['lazing', 'lazy',  'lacer']) => []
```

## Solution

```js
function anagrams(word, words) {
  return words.filter(w => word.split("").sort().join("")===w.split("").sort().join(""))
}

////

function anagrams(word, words) {
  word = word.split("").sort().join("");
  return words.filter(w => word===w.split("").sort().join(""))
}

////

String.prototype.sort = function() {
  return this.split("").sort().join("");
};

function anagrams(word, words) {
  return words.filter(x => x.sort() === word.sort());
}
////
```