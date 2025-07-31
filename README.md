# CLeetCode
Just a repo, where I practice leetcode tasks in C programming language

## TODO
---
- [x] 1. TwoSum
- [x] 9. Palindrome Number
- [x] 13. Roman to Integer

### TwoSum
---
I am fucking stupid for not reading the task at least once. It's much easier then what I expected and first I was thinking to implement a "greedy" solution (the one I use to convert decimal to binary). But at the end effect I just used brute force. I am not satisfied with this result of course, so I'll try to improove it
Better solution would be to create a hashmap. Intuition goes like that:
- calculate complement of each index value
- store the value from array as a key and the complement as value of this entry
- if found, nice

**Current bruteforce stats:**
- *Runtime*: 99 ms
- *Memory*: 8.67 MB

I did make a hashmap solution, which is twice as inefficient as the bruteforce one... How? No idea yet
Increasing the hashmap size to twice the `numsSize` resulted in 10 ms runtime!!! This is amazing, lol

**Current hashmap stats:**
- *Runtime*: 10 ms
- *Memory*: 11.9 MB

### Palindrome
---
Easy task.
Changing intAsArr from heap allocation to the stack increased speed from 10ms to 2ms lol

**Current stats:**
- *Runtime*: 2 ms
- *Memory*: 9.51 MB

### RomanToInteger
---
Interestin task, used Linked list for that and therefore overengineered it too much.
Don't know if gonna be possible to improove it using this style, but we'll see.
With all of those memory allocations on heap it's definately not gonna be possible to make it very efficient.

Well, all in all, I think that my first solution is really good for languages that may change a lot in its definition.
Meaning, that I didn't think that in roman languages only one character before a bigger one represents a minus action.
For Example: IX - 9, but IIX != 8, because VIII is.

This fact allows me not to fuck around with all of those linked lists and traversals, but it was really fun, so I am leaving this solution in repo.

**Current stats:**
- *Runtime*: 42 ms
- *Memory*: 11.23 MB
