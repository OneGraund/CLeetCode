# CLeetCode
Just a repo, where I practice leetcode tasks in C programming language

## TODO
---
- [x] 1. TwoSum
- [ ] 9. Palindrome Number
- [ ] 13. Roman to Integer

### TwoSum
---
I am fucking stupid for not reading the task at least once. It's much easier then what I expected and first I was thinking to implement a "greedy" solution (the one I use to convert decimal to binary). But at the end effect I just used brute force. I am not satisfied with this result of course, so I'll try to improove it
Better solution would be to create a hashmap. Intuition goes like that:
- calculate complement of each index value
- store the value from array as a key and the complement as value of this entry
- if found, nice

**Current stats:**
- *Runtime*: 107 ms
- *Memory*: 8.55 MB
