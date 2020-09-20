+++
title = "2019-03-01 Daily Challenge"
path = "2019-03-01-daily-challenge"
date = 2019-03-01T09:01:02+00:00
updated = 2020-09-19T20:01:27.633312+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "CodeWars",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Create Phone Number* in *JavaScript*.
<!-- more -->

# CodeWars

## Problem

### Create Phone Number

Write a function that accepts an array of 10 integers (between 0 and 9), that returns a string of those numbers in the form of a phone number.

### Example:

```javascript
createPhoneNumber([1, 2, 3, 4, 5, 6, 7, 8, 9, 0]) // => returns "(123) 456-7890"
```

The returned format must be correct in order to complete this challenge. 
Don't forget the space after the closing parentheses!

## Solution

```js
function createPhoneNumber(numbers){
  return `(${numbers.slice(0, 3).toString().replace(/,/gi, '')}) ${numbers.slice(3, 6).toString().replace(/,/gi, '')}-${numbers.slice(6, 10).toString().replace(/,/gi, '')}`;
}

function createPhoneNumber(numbers){
  return numbers.join('').replace(/(...)(...)(.*)/, '($1) $2-$3');
}
```