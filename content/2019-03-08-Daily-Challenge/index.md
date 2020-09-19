+++
title = "2019-03-08 Daily Challenge"
path = "2019-03-08-daily-challenge"
date = 2019-03-08T00:32:00+00:00
updated = 2020-09-19T20:01:27.634309+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "CodeWars",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *PaginationHelper* in *JavaScript*.

Problem is misleading and description is like shit. Data is poor.

<!--more-->

# CodeWars

## Problem

### PaginationHelper

For this exercise you will be strengthening your page-fu mastery. You will complete the PaginationHelper class, which is a utility class helpful for querying paging information related to an array.

The class is designed to take in an array of values and an integer indicating how many items will be allowed per each page. The types of values contained within the collection/array are not relevant.

The following are some examples of how this class is used:

```javascript
var helper = new PaginationHelper(['a','b','c','d','e','f'], 4);
helper.pageCount(); //should == 2
helper.itemCount(); //should == 6
helper.pageItemCount(0); //should == 4
helper.pageItemCount(1); // last page - should == 2
helper.pageItemCount(2); // should == -1 since the page is invalid

// pageIndex takes an item index and returns the page that it belongs on
helper.pageIndex(5); //should == 1 (zero based index)
helper.pageIndex(2); //should == 0
helper.pageIndex(20); //should == -1
helper.pageIndex(-10); //should == -1
```

## Solution

```js
// TODO: complete this object/class

// The constructor takes in an array of items and a integer indicating how many
// items fit within a single page
function PaginationHelper(collection, itemsPerPage){
  this.cap = itemsPerPage;
  this.size = collection.length;
}

// returns the number of items within the entire collection
PaginationHelper.prototype.itemCount = function() {
  return this.size;
}

// returns the number of pages
PaginationHelper.prototype.pageCount = function() {
  return Math.ceil(this.size/this.cap);
}

// returns the number of items on the current page. page_index is zero based.
// this method should return -1 for pageIndex values that are out of range
PaginationHelper.prototype.pageItemCount = function(pageIndex) {
  if (pageIndex < 0 || pageIndex > Math.floor(this.size/this.cap)) return -1;
  else if (pageIndex === Math.floor(this.size/this.cap)) return this.size % this.cap;
  return this.cap;
}

// determines what page an item is on. Zero based indexes
// this method should return -1 for itemIndex values that are out of range
PaginationHelper.prototype.pageIndex = function(itemIndex) {
  if (itemIndex < 0 || itemIndex >= this.size) return -1;
  return this.size===0?-1:Math.floor(itemIndex/this.cap);
}
```



```js
// TODO: complete this object/class

// The constructor takes in an array of items and a integer indicating how many
// items fit within a single page
function PaginationHelper(collection, itemsPerPage){
  this.cap = itemsPerPage;
  this.size = collection.length;
}

// returns the number of items within the entire collection
PaginationHelper.prototype.itemCount = function() {
  return this.size;
}

// returns the number of pages
PaginationHelper.prototype.pageCount = function() {
  return Math.ceil(this.size/this.cap);
}

// returns the number of items on the current page. page_index is zero based.
// this method should return -1 for pageIndex values that are out of range
PaginationHelper.prototype.pageItemCount = function(pageIndex) {
  return pageIndex < this.pageCount()
    ? Math.min(this.itemsPerPage, this.size - pageIndex * this.cap)
    : -1;
}

// determines what page an item is on. Zero based indexes
// this method should return -1 for itemIndex values that are out of range
PaginationHelper.prototype.pageIndex = function(itemIndex) {
  return itemIndex < this.size && itemIndex >= 0
    ? Math.floor(itemIndex/this.cap)
    : -1;
}
```