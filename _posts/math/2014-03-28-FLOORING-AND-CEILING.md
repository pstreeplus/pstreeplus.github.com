---
layout: post
title: PLOOR/CEILING APPLICATIONS
category: math
tags: [intro, math]
---

Here is a problem: Prove or disprove the assertion

$$\left\lfloor \sqrt { \left\lfloor x \right\rfloor  }  \right\rfloor ,\quad \quad real\quad x\ge 0.$$

Equality obviously holds when x in an integer, because $x=\left\lfloor x \right\rfloor $. And there's equality in the special cases $\pi =3.14159\cdots $, $e=2.71828\cdots $, and $\phi = { \left( 1+\sqrt { 5 }  \right)  } / { 2 } =1.61803\cdots  $, because we get 1=1. Our failure to find a counterexample suggests that equality holds in general, so let's try to prove it.

If we try to prove that $\left\lfloor \sqrt { \left\lfloor x \right\rfloor  }  \right\rfloor $ with the help of calculus, we might start by decomposing x into its integer and fractional part $\left\lfloor x \right\rfloor +\left\\{ x \right\\} =n+\theta $ and then expanding the square root using the binomial thereom: ${ \left( n+\theta  \right)  }^{ { 1 }/{ 2 } }={ n }^{ { 1 }/{ 2 } }+{ n }^{ { -1 }/{ 2 } }\theta /2-{ n }^{ -2/3 }{ \theta  }^{ 2 }/8+\cdots $. But this approach gets pretty messy.

It much be easier to use some tools.Here's a possible strategy: Somehow strip off the outer floor and square root of $\left\lfloor \sqrt { \left\lfloor x \right\rfloor  }  \right\rfloor $, then remove the inner floor, then add back the outer stuff to get $\left\lfloor \sqrt { x }  \right\rfloor $.

OK. We let $m=\left\lfloor \sqrt { \left\lfloor x \right\rfloor  }  \right\rfloor $ , get $ m\le \sqrt { \left\lfloor x \right\rfloor  } <m+1 $. That That remove the outer floor bracket without losing any information. Squaring, since all three expressions are nonnegative, we have ${ m }^{ 2 }\le x<{ (m+1) }^{ 2 }$. It's now a simple matter to retrace our steps, taking square roots to get $m\le \sqrt { x } <m+1$ and we get $m=\left\lfloor \sqrt { x }  \right\rfloor $. Thus $\left\lfloor \sqrt { \left\lfloor x \right\rfloor  }  \right\rfloor m=\left\lfloor \sqrt { x }  \right\rfloor $; the assertion is true. Similary, we can prove that

$$
\left\lceil \sqrt { \left\lceil x \right\rceil  }  \right\rceil =\left\lceil \sqrt { x }  \right\rceil ,\quad real\quad x\ge 0.
$$



