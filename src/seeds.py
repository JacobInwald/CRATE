import os

SEED_DIR = "../afl_in"

def write_seed(num, seed):
    filename = f"{num:03d}"
    with open(SEED_DIR+"/"+filename, "w") as f:
        f.write(seed)
    f.close()
    
seeds = [
    "",
    "a",
    "\n",
    " ",
    "\t",
    "\x00",
    "\x90",
    "\xff",
    "0",
    "-1",
    "2147483647",
    "-2147483648",
    "%s",
    "%x",
    "%n",
    "../../path/to/file",
    "{\"key\": \"value\"}",
    "' OR '1'='1",
    "<script>alert('XSS')</script>",
]


for num, seed in zip(range(len(seeds)), seeds):
    write_seed(num, seed)