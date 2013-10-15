## Search Engine

### 1. Description
This is a search engine written in **python**, according to **Udacity CS101**.

### 2. Modules

### 2.1 web_crawler
This module aims to crawl on the Internet, generate two dictionaries: **index** and **graph**.

In the *crawl_web* function, I use a **DPS**, an argument *depth* controls the depths of crawl, its default value is 10.

### 2.2 build_index
This module provides functions to make **index** in web_crawler.

### 2.3 page_rank
This module ranks all the pages crawled using the **PageRank** algorithm.

In the function *compute_ranks*, the damping factor and number of iterates are adjustable.

## Remark
***Version 1.0***