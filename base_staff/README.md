# Basics

Basics of C programming language. 

1. Basics (basics) - very basic C stuff.

   Below goes the list of sub-demos with arguments in ().
   1. Hello World (hw) - Basic hello world.
   2. Farenheit to celsius (fc) - Dummy function converting temperature.
   3. Bit count (bc some-number) - Count number of 1-bits in input number.
   4. Day of Year (dy year month day) - Calculate number of day in year.
   5. Month (mn month-number) - Convert month number to name.
   6. Factorial (fac) - Calc factorials of numbers in range.

2. Bit Operations (bit_ops) - Several bit operations with strings.
   
   Below goes the list of sub-demos with arguments in ().
   1. Get bit (bg) - Get bit value of position at string.
   2. Set bit (bs) - Set bit at position at string.
   3. Bit XOR (bx) - XOR two strings.
   4. Bit rotate (br) - Rotate bits in string to the left.
   
3. Concat Files (concat_files)  - Input several files,read them ,concat their contents and print it.
   Arguments: list of files. If no files provided input will be open for entering a message.
4. Input counter (input_counter) - Print some lines in console and get some calculations about the input.
5. Keywords (keywords) - Count how many special words are in input lines.
6. Line Sort (line_sort) - Input several lines and sort them.
7. Long line (long_line) - Print the longest line from input.

## Build and run
```
cd <demo-dir>
make 
./demo-name <args>
```

# Notes
- Demo directory names are in ()
- Arguments for demos will be listed if needed.
- Input Counter and Keywords print count results after closing input via CTRL-D.
- Line Sort and Long Line print results after closing input via CTRL-D.