import sys 
import subprocess 
import os 
    
# example compilation:
# * gcc data/test/fuzz-harness.c -o tmp/basic
# * AFL_SKIP_CPU_FREQ=1 afl-fuzz -Q -i data/afl_in -o out -m none -- tmp/basic
