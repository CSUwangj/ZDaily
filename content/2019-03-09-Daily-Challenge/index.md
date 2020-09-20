+++
title = "2019-03-09 Daily Challenge"
path = "2019-03-09-daily-challenge"
date = 2019-03-09T08:48:52+00:00
updated = 2020-09-19T20:01:27.633312+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "CodeWars",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Simple Pig Latin* in *JavaScript*.

Problem is misleading and description is like shit. Data is poor.

<!-- more -->

# CodeWars

## Problem

### Simple Pig Latin

Move the first letter of each word to the end of it, then add "ay" to the end of the word. Leave punctuation marks untouched.

## Examples

```javascript
pigIt('Pig latin is cool'); // igPay atinlay siay oolcay
pigIt('Hello world !');     // elloHay orldway !
```

## Solution

```js
function pigIt(str){
  return str.replace(/([a-zA-Z])([a-zA-Z]*)/gi, "$2$1ay");
}

function pigIt(str){
  return str.replace(/(\w)(\w*)/gi, "$2$1ay");
}
```