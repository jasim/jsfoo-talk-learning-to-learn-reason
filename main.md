---
author:
- Jasim A Basheer
subtitle: Thinking with Types
title: Learning to learn ReasonML
titlepage-note: |
  Hello, my name is Jasim, and I'm here today to talk about ReasonML. 
  
  I don't imagine, that many of us here would've watched any talks or read any blogposts about Driving, before we ever tried to learn it. We just sit behind the wheels and fumble and get stressed out and then slowly build an intuition. And then over time it becomes second nature to us. 
  
  Most physical activities are like that. Mental activities are also like that - and it is the same when trying to learn a new programming language as well.
  
  But learning a language, particularly a language that is quite different from what we're used to, that requires a significant amount of time and effort. 
  
  I've found that it also requires an emotional sort of commitment. And once we're emotionally invested, the time and space will just make itself available.
  
  My hope today is to help you with that. To show you how Reason is an interesting language, and sort of give you a feel for what it could be to be programming in it. 
  
institute: "@jasim_ab"
fontsize: 17pt
...

# Reason is OCaml

::: notes

Reason is a new syntax on top of the OCaml programming language. 

:::

---

## OCaml

* First released in 1990 in France

* ISWIM syntax (OCaml, Haskell)

(most languages including ES6 follow ALGOL style)

::: notes

OCaml was first released about 20 years ago, and it has been in active development ever since.

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

Jordan Walke, who wrote React at Facebook, he wanted to be able to use OCaml for all his programming, including further work on React itself.

But since the OCaml syntax was unfamiliar to mainstream programmers, he went ahead and created Reason, with a syntax that is very similar to the ES6 Javascript syntax which we're used to. But it is all actually OCaml underneath.

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

The point is, underneath, it is the same language and same semantics. So I'll use both Reason and OCaml interchangeably in this presentation, depending on what fits the context better.

:::

---

# What can we build with Reason/OCaml?

::: notes

So the first question is whether it is actually useful? What can we build with this language?

:::

---

## What can we build with Reason/OCaml?

### High-frequency trading software

&nbsp;

![](images/jane-street.png)

::: notes

When you start reading about OCaml, you'll come across Jane Street, who is the largest production user of the language, apart from Facebook, and they do billions of dollars worth of trading, all exclusively in software written in OCaml.

:::

---

## What can we build with Reason/OCaml?

### World's second largest crawler

&nbsp;

![](images/ahrefs.png)

::: notes

If you have done any SEO work, you might be familiar with Ahrefs. They crawl about 5 million pages every minute, just behind Googlebot. They use OCaml for all the back-end infra and Reason on the front-end.

:::

---

## What can we build with Reason/OCaml?

### Compilers

* First version of the Rust compiler
* Flow (typechecker for Javascript)

&nbsp;

::: notes

OCaml is also particularly nice to write compilers on - in fact anything that deals with a lot of tree manipulation is a great fit.
:::

---

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

# Object-oriented vs Typed Functional Code

::: notes

Let's start with a comparison of how a program looks when done in an
untyped, object-oriented manner written in Javascript,
vs when it is done in the Typed Functional manner written in Reason.
Here on the screen is a JSON with a naive version of the code, and then refactors it into a clean object-oriented version.

:::

---

# Object-oriented vs Typed Functional Code

::: notes

Here on the screen is a snippet of code from the book "Refactoring" by Martin Fowler. This is from the first chapter, he opens with a naive version of the code, and then refactors it into a clean object-oriented version.

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

