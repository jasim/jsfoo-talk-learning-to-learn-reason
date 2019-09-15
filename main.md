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

# Reason is a new syntax on top of OCaml

## OCaml

\note{
  Reason is a new syntax on top of OCaml.
  OCaml is a language that has been around for over 20 years. But its syntax is very different to most languages that we know.
  
  Jordan Walke, who wrote React at Facebook, he wanted to be able to use OCaml for all his work, including innovation on React itself.
  
  But since the OCaml syntax was going to be a problem in commercial adoption, he went ahead and created Reason, with a syntax that is very similar to the ES6 Javascript syntax that we're used to. But it is all actually OCaml underneath.

  So I'll use both Reason and OCaml interchangeably in this presentation, depending on what fits the context better.
}

# What can we build with Reason?

### Jane Street

We can build high-frequency stock exchanges 

\note{
  So the first question is whether it is actually useful? What can we build with this language?

  We can build high-frequency stock exchanges with OCaml. If you Google for OCaml, you'll come across Jane Street, who is the largest production user of OCaml apart from Facebook, and they do billions of dollars worth of trading in systems written in OCaml.
}

# Reason is a Typed Functional Programming Language

\note{
  Reason is a new syntax on top of OCaml.
  OCaml is a programming language in the Typed Functional paradigm. That paradigm is the most defining feature when contrasted against other languages that we might be familiar with.
}

## Javascript is Dynamically Typed

_Untyped OO:_

Ruby, Python, **Javascript**

&nbsp;

_Untyped Functional:_

Clojure, Lisp/Scheme/Racket, **Javascript**

\note{
  Javascript is a dynamically typed langauge. It is a multi-paradigm language -- we can use ES6's class syntax to write classical object-oriented code, or just use functions as first-class citizens, and write purely function code. 
}


## Typed Functional

### Typed Object-Oriented Languages
C++, Java, C#, Scala

### Typed Functional Languages
Haskell, Scala, OCaml (Reason)

\note{
  Javascript is a dynamically typed langauge. And we can write both object-oriented code as well as purely functional code with it. It is sort-of multi-paradigm there.
}



# Object-oriented vs Typed Functional Code

\note{
  Let's start with a comparison of how a program looks when done in an
  untyped, object-oriented manner written in Javascript,
  vs when it is done in the Typed Functional manner written in Reason.
  Here on the screen is a JSON with a naive version of the code, and then refactors it into a clean object-oriented version.
}

---

# Object-oriented vs Typed Functional Code

\note{
  Here on the screen is a snippet of code from the book "Refactoring" by Martin Fowler. This is from the first chapter, he opens with a naive version of the code, and then refactors it into a clean object-oriented version.
}

---

## Slide with text and a note

Regular text size

\tiny Jonathan Sarna, *American Judaism* (New Haven: Yale University
Press, 2014)

\note{
NOTES: This is a note page and you ought to be able to tell.
}

## Slide with text and footnote

Surely this is true.^[Jane Doe, *Says It Here* (New York: Oxford 
University Press, 2050).] 

\note{I am sure about this point.}

## This is a heading

Regular text on a slide:

-   One
-   Two
-   Three

\note{
More notes:

Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod
tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At
vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren,
no sea takimata sanctus est Lorem ipsum dolor sit amet.
}

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

\note{
This might be easier in R or Ruby.
}

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

\note{
This might be easier in R or Ruby.
}
