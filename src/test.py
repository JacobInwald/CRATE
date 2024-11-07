import sys 
import subprocess 
import os 
from options import OptionEnum
    
# * Constants
DATA_PATH = "test"


# *  Fuzz Testing Command
fuzz_env_opts = "AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1 AFL_SKIP_CPUFREQ=1 "

# Black Box Fuzzing
bb_fuzz = lambda num, name, options : fuzz_env_opts + f"afl-fuzz -Q -i afl_in -o afl_out/out_{num:03d}/opts{"-".join(options.split(" -"))} -- {DATA_PATH}/{num:03d}-{name}/build/bb_{name}{"-".join(options.split(" -"))}"

# White box fuzzing
fuzz = lambda num, name, options : fuzz_env_opts + f"afl-fuzz -i afl_in -o afl_out/out_{num:03d}/opts{"-".join(options.split(" -"))} -- {DATA_PATH}/{num:03d}-{name}/build/{name}{"-".join(options.split(" -"))}"

# * Build Command 

build_env_opts = " "

build = lambda num, name, options, bb: build_env_opts + f"./{DATA_PATH}/{num:03d}-{name}/build.sh {"bb_" if bb else ""}build {options}" 


def run(cmd):
    subprocess.run(cmd, shell=True, check=True)
    

tests = {
    1: "strcpy",
    2: "viewnior",
    3: "winbagility",
    4: "peervpn",
    5: "rustlua",
    6: "terminology",
    7: "ticketd",
    8: "twemproxy",
    9: "warfacebot",
}

opt = str(OptionEnum.HARDENED.value) + ""
opt = ""

test_no = 1

if len(sys.argv) >= 2:
    assert sys.argv[1].isdigit(), "Test Case Index is not a number"
    assert 0 <= int(sys.argv[1]) < len(tests), "Test Case Index out of bounds"
    test_no = int(sys.argv[1])
    
if len(sys.argv) >= 3:
    assert sys.argv[2] == "-bb" or sys.argv[2] == "-wb" , "Select white or black box testing with -bb or -wb"
    bb = sys.argv[2] == "-bb"

if len(sys.argv) >= 4:
    opts = ""
    for opt in sys.argv[3:]:
        opts += opt + " "
        
    opt = OptionEnum.find(opts)
    
    
run(build(test_no, tests[test_no], str(opt), False))
run(fuzz(test_no, tests[test_no], str(opt)))

