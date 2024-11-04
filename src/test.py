import sys 
import subprocess 
import os 
    
# example compilation:
# * gcc data/test/fuzz-harness.c -o tmp/basic
# * AFL_SKIP_CPU_FREQ=1 afl-fuzz -Q -i data/afl_in -o out -m none -- tmp/basic

# Fuzzing Harness Location
HARNESS_LOC = "test/fuzz-harness.c"
# File format of test cases
test_format = lambda n : f"test-{n:03d}.c"


def rewrite_fuzz_harness(case_no):
    """
    Rewrite the fuzz harness to include the test case specified by case_no
    """
    with open(HARNESS_LOC, 'r') as f:
        lines = f.readlines()
        
    with open(HARNESS_LOC, 'w') as f:
        for line in lines:
            if '/* REPLACE */' in line:
                f.write(f'#include "{test_format(case_no)}" /* REPLACE */\n')
            else:
                f.write(line)
                

def compile_fuzz_harness(case_no, flags=""):
    rewrite_fuzz_harness(case_no)
    subprocess.run(f"gcc {HARNESS_LOC} -o tmp/{test_format(case_no)[:-2]} {flags}", shell=True, check=True)
    
    
def fuzz_test(case_no):
    subprocess.run(f"AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1 AFL_SKIP_CPUFREQ=1 afl-fuzz -Q -i afl_in -o afl_out/out_{case_no:03d} -m none -- tmp/{test_format(case_no)[:-2]}", shell=True, check=True)
    
compile_fuzz_harness(1)
fuzz_test(1)