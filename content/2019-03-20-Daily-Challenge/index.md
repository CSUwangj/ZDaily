+++
title = "2019-03-20 Daily Challenge"
path = "2019-03-20-daily-challenge"
date = 2019-03-20T10:11:15+00:00
updated = 2019-03-21T00:03:58+00:00
in_search_index = true

[taxonomies]
tags = ["Cryptography",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
Let's write some notes takes while challenging my self learning.

<!--more-->

Today I've been reading [A Tutorial on Linear and Differential Cryptanalysis](https://www.engr.mun.ca/~howard/PAPERS/ldc_tutorial.pdf).

Not done yet, so I just write some casual notes, which can help to write some more detailed article(at least I wish).



> The cipher that we shall use to present the concepts is a basic Substitution-Permutation Network (SPN). We will focus our discussion on a cipher, illustrated in Figure 1, that takes a 16-bit input block and processes the block by repeating the basic operations of a round four times. Each round consists of (1) substitution, (2) a transposition of the bits (i.e., permutation of the bit positions), and (3) key mixing. This basic structure was presented by Feistel back in 1973 [15] and these basic operations are similar to what is found in DES and many other modern ciphers, including Rijndael.

SPN is really useful.

> a subkey is applied following the last round, ensuring that the last layer of substitution cannot be easily ignored by a cryptanalyst that simply works backward through the last round’s substitution.

Apart from the advantage of symmetry of processing(symmetry of encryption/decryption), there is a reason to apply subkey at the last round.

> ***Piling-Up Lemma***
>
> for $n$ independent, random binary variables, $X_1,X_2,...X_n$,
>
> $$Pr(X_1\oplus ...\oplus X_n=0)=1/2+2^{n-1}\prod_{i=1}^n\varepsilon_i$$
>
> or, equivalently
>
> $$\varepsilon_{1,2,...,n}=2^{n-1}\prod_{i=1}^n\varepsilon_i$$
>
> where $\varepsilon_i,2,...,n$ represents the bias of $X_1\oplus ...\oplus X_n=0$.

It's easy to prove it by induction, I think.