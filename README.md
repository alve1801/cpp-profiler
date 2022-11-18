# cpp-profiler
Tiny CPP profiler

Once again, in the form of a single header file that you include in your project and use. Originally developed for SpaceCore.

Usage:
Call `timer.reset()` before the first block of code you want to profile, and `timer["<block_nickname>"]` after every block.
`timer.disp()` will show an overview of time spent on each block (in milliseconds and as a percentage of the whole)
