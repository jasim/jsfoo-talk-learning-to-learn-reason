---
author:
- Jasim A Basheer
subtitle: Thinking with Types
title: Learning to learn ReasonML
titlepage-note: |
  Hello, my name is Jasim, and I'm here today to talk about ReasonML. 
  
  Those of you here who have learnt to drive, I don't imagine you would have read any blogposts or watched any talks about it. We just sit behind the wheel, fumble, and get stressed out, and slowly painfully build an intuition. Over time it becomes second nature though.
  
  Any activity that requires skill is like that. It is the same when trying to learn a new programming language as well.
  
  But learning a language, particularly something that is quite different from what we're used to, will require a significant amount of time and effort. 
  
  I've found that it also requires an emotional sort of commitment. And once we're emotionally invested, it becomes play and then time is no longer a concern.
  
  My hope today is to help you with that. I'll show you the most interesting bits of Reason, and sort of give you a feel for what it could be to be programming in it.
  
institute: "@jasim_ab"
fontsize: 17pt
...

## Reason is OCaml

* First released in 1990 in France

* Fast programs approaching C-like speeds

* ISWIM syntax (OCaml, Haskell) not ALGOL (C, Java, Javascript etc.)

::: notes

Reason is a new syntax on top of the OCaml programming language. 

OCaml has a long history - it was first released in 1990 - about 20 years ago. It is a compiled language and produces very performant binaries; it is sort of like GoLang in that respect. 

But its syntax is a little different from most languages that we know.

:::

---

## OCaml sample code

``` {.ocaml}
let rec read_and_accumulate accum =
  let line = In_channel.input_line In_channel.stdin in
  match line with
  | None -> accum
  | Some x -> read_and_accumulate (accum +. Float.of_string x)

let () =
  printf "Total: %F\n" (read_and_accumulate 0.)  
```

::: notes

Here is a program that reads a list of numbers from the standard input and prints their sum.

:::

---

## Same code, in Reason

``` {.javascript}
let rec read_and_accumulate = accum => {
  let line = In_channel.input_line(In_channel.stdin);
  switch (line) {
  | None => accum
  | Some(x) => read_and_accumulate(accum +. Float.of_string(x))
  };
};

let () = printf("Total: %F\n", read_and_accumulate(0.));
```

::: notes

Here's the same OCaml code, but in the Reason syntax.

The point is, underneath, it is the same language and same semantics. So I'll use both Reason and OCaml interchangeably in this presentation, depending on what fits the context better.

:::

---

# What can we build with Reason/OCaml?

::: notes

So is it actually useful? This language. What can we build with it? Let me take you through some examples.

:::

---

## What can we build with Reason/OCaml?

### High-frequency trading software

&nbsp;

![](images/jane-street.png)

::: notes

When you start reading about OCaml, you'll often come across Jane Street. They are one of the largest production users of the language and they do billions of dollars worth of trading, all with software written in OCaml.

:::

---

## What can we build with Reason/OCaml?

### World's second largest crawler

&nbsp;

![](images/ahrefs.png)

::: notes

If you have done any SEO work, you might be familiar with Ahrefs. They crawl about 5 million pages every minute, and they have the second largest index after Google. They use native OCaml for all the back-end infra and for the front-end web they use Reason.

:::

---

## What can we build with Reason/OCaml?

### Compilers

* First version of the Rust compiler
* Flow (typechecker for Javascript)
* Hack (Facebook's PHP compiler)

&nbsp;

::: notes

OCaml is also particularly nice to write compilers on - in fact anything that deals with a lot of tree manipulation is a great fit. Rust borrows many ideas from OCaml, and their first compiler was written in the language. Facebook is also a large user of OCaml internally.

5mins

:::

---

## What can we build with Reason/OCaml?

### Front-end web applications!

* BuckleScript compiles Reason/OCaml to Javascript

/large Reason syntax + BuckleScript compiler = Performant Front-end web applications

::: notes

Those were the traditional applications of OCaml. 

OCaml can also be used to build front-end web applications. That's what this talk is about.

The regular OCaml compiler emits executable binary, but we want Javascript. So there is an OCaml compiler called BuckleScript - it emits performant Javascript. This is readable Javascript and plays nicely with npm.

:::

---




# Object-oriented vs Typed Functional Code

::: notes

Let's start off with a code comparison.

Here's a snippet of code that is object-oriented Javascript, from the book "Refactoring" by Martin Fowler.

:::

---

# Object-oriented vs Typed Functional Code

::: notes


:::

# Reason is a Typed Functional Programming Language

::: notes

  Reason is a new syntax on top of OCaml.
  OCaml is a programming language in the Typed Functional paradigm. That paradigm is the most defining feature when contrasted against other languages that we might be familiar with.

:::

---

## Javascript is Dynamically Typed

_Untyped OO:_

Ruby, Python, **Javascript**

&nbsp;

_Untyped Functional:_

Clojure, Lisp/Scheme/Racket, **Javascript**

::: notes

Javascript is a dynamically typed langauge. It is a multi-paradigm language -- we can use ES6's class syntax to write classical object-oriented code, or just use functions as first-class citizens, and write purely function code. 

:::

---

## Typed Functional

### Typed Object-Oriented Languages
C++, Java, C#, Scala

### Typed Functional Languages
Haskell, Scala, OCaml (Reason)

::: notes

Javascript is a dynamically typed langauge. And we can write both object-oriented code as well as purely functional code with it. It is sort-of multi-paradigm there.

:::

---

## Slide with text and a note

Regular text size

\tiny Jonathan Sarna, *American Judaism* (New Haven: Yale University
Press, 2014)

::: notes

NOTES: This is a note page and you ought to be able to tell.

::: notes


## Slide with text and footnote

Surely this is true.^[Jane Doe, *Says It Here* (New York: Oxford 
University Press, 2050).] 


## This is a heading

Regular text on a slide:

-   One
-   Two
-   Three

---

## First step

``` {.javascript}
switch (play.type) {
  case "tragedy":  
    return new TragedyCalculator(
      aPerformance, aPlay
    );
    
  case "comedy":
    thisAmount = 30000;
    if (perf.audience > 20) {
      thisAmount += 10000 + 500 * (perf.audience - 20);
    }
    thisAmount += 300 * perf.audience;
    break;
  default:
    throw new Error(`unknown type: ${play.type}`);
}
```


---

## Code example

``` {.javascript}
type type_ =
  | Tragedy
  | Comedy;

type play = {
  name: string,
  audience: int,
  type_,
};
```

