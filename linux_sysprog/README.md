# Linux System Programming.

Examples using Linux System Functions.

1. Change Group (change_group) - Change group which file belongs to.
2. Child Process (child_process) - Fork a child and exit.
3. CPU Affinity (affinity) - Show the number of used CPUs.
4. File Operations (file_ops) - Several file operations like open,create,read,sync,truncate,seek.
5. File Statistics (file_stat) - Print statistics of input file.
6. Find File (find_file) - Find a file in a filesystem.
7. Get Allocated Size (get_alloc_size) - Allocate memory and get size of it.
8. Get Directory (get_dir) - Show path to the current directory.
9. Map (map) - Open file and print contents.
10. Multi signal handler (multi_signal) - Handler for various system signals
11. Poll (poll) - Check if stdin and stdout are readable.
12. Print Chars (print_chars) - Print chars from hardcoded string.
13. WriteV (writev) - Create a file and write bytes to it.
14. ReadV (readv) - Read file create by WriteV.
15. R limits (rlimits) - Check R limits.
16. RR Interval (rr_interval) - Get a time quantum 
17. RR Priority (rr_priority) - Schedule a priority range.
18. Select (select) - Read a file using blocking.
## Build and run
```
cd <demo-dir>
make 
./demo-name <args>
```

## Notes
- Demo directory names are in ()
- Poll can be run in format ```./pd < some-file```. Without file stdin will be checked.
- ReadV must be run after WriteV
- Select can be run in format ```./sel < some-file```. Without 5 second block will be made.
