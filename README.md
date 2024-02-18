# Parser: Understand How compilers check for errors on the Code

# Concept Introduction 💻

Building on the foundational work in lexical analysis from Lab1, Lab2 introduces the concept of parsing, also known as syntax analysis. Parsing plays a critical role in the compiler process, as it checks the syntactical correctness of the input program and constructs a parse tree, which can be explicit or implicit. The parser's ability to produce diagnostic messages and recover from errors enables the detection of multiple errors in a single run.

Parsers can be categorized into two main types

based on the direction of parse tree construction:

- Top-Down Parsers: Start building the parse tree from the root, moving downwards.

- Bottom-Up Parsers: Begin at the leaves and work upwards towards the root.

# The Recursive-Descent Parsing Process

Recursive-descent parsing, a method of top-down parsing, utilizes a set of recursive subprograms to construct the parse tree. Each nonterminal in the grammar is represented by one subprogram, making EBNF (Extended Backus-Naur Form) particularly suitable for describing the grammar for recursive-descent parsers.

Example Grammar for Arithmetic Expressions:

```bash
<expr> -> <term> {(+ | -) <term>}
<term> -> <factor> {(* | /) <factor>}
<factor> -> id | int constant | ( <expr> )
```

# Diagram for a top-down approach to the Parsing logic, by starting in <expr>:


```bash
<expr>
 |        \
<term>     +
 |          \
"3"         <term>
              |
             <factor>
              |     \
             "5"     *
                      |
                    <term>
                    /  |   \
                 <factor>  /   <factor>
                    |         |         |
                   "2"       "1"

```
