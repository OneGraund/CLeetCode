# CLeetCode
Just a repo, where I practice leetcode tasks in C programming language

## TODO
---
- [x] 1. TwoSum
- [x] 9. Palindrome Number
- [ ] 13. Roman to Integer

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

