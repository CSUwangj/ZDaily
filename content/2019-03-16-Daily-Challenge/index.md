+++
title = "2019-03-16 Daily Challenge"
path = "2019-03-16-daily-challenge"
date = 2019-03-16T00:53:11+00:00
updated = 2020-09-19T20:01:27.634309+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "CodeWars",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Nesting Structure Comparison* in *JavaScript*.

<!--more-->

# CodeWars

## Problem

### Nesting Structure Comparison

Complete the function/method (depending on the language) to return `true`/`True` when its argument is an array that has the same nesting structure as the first array.

For example:

```javascript
 // should return true
[ 1, 1, 1 ].sameStructureAs( [ 2, 2, 2 ] );          
[ 1, [ 1, 1 ] ].sameStructureAs( [ 2, [ 2, 2 ] ] );  

 // should return false 
[ 1, [ 1, 1 ] ].sameStructureAs( [ [ 2, 2 ], 2 ] );  
[ 1, [ 1, 1 ] ].sameStructureAs( [ [ 2 ], 2 ] );  

// should return true
[ [ [ ], [ ] ] ].sameStructureAs( [ [ [ ], [ ] ] ] ); 

// should return false
[ [ [ ], [ ] ] ].sameStructureAs( [ [ 1, 1 ] ] );     
```

## Solution

```js
Array.prototype.sameStructureAs = function (other) {
  if (this.length !== other.length) return false;
  for (let i = 0; i < this.length; ++i) {
    if (Array.isArray(this[i]) && !this[i].sameStructureAs(other[i])) return false;
    if (!Array.isArray(this[i]) && Array.isArray(other[i])) return false;
  }
  return true;
};

////

Array.prototype.sameStructureAs = function (other) {
  return (this.length === other.length) ? this.every(
    (e, i) => Array.isArray(e) ? e.sameStructureAs(other[i]) : true
  ) : false;
};
```