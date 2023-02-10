<h1 align=center>
	<b>Push_swap</b>
</h1>

## Introduction 
This project involves sorting data from a stack, with a limited set of instructions and the fewest moves.

## General Description
Sort a random list of integers using the smallest number of moves, 2 stacks
and a limited set of operations. 
You start with two empty stacks: **a** and **b**. You are given a random list of integers via command line arguments.

Only these moves are allowed:
- `sa` : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
- `sb` : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
- `ss` : `sa` and `sb` at the same time.
- `pa` : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.
- `pb` : push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.
- `ra` : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.
- `rb` : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
- `rr` : `ra` and `rb` at the same time.
- `rra` : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
- `rrb` : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
- `rrr` : `rra` and `rrb` at the same time.

At the end, **stack b** must empty empty and all integers must be in **stack a**, sorted in ascending order. <br />

## usage

Git clone the project:
```sh
https://github.com/leaozim/42-course--Push_Swap.git
```
To compile, use make
```sh
cd 42-course--Push_Swap && make
```
Run the program
```sh
./push_swap 1 5 8 3 2
```
