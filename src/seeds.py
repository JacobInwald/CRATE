import os
import sys
from pathlib import Path

# Absolute path for the seed directory
SEED_DIR = Path(os.getcwd() + "/" + sys.argv[0]).parent.parent /  "afl_in"


def write_seed(num, seed):
    filename = f"{num:03d}"
    with open(SEED_DIR+"/"+filename, "w") as f:
        f.write(seed)
    f.close()


def gen_seeds():
    
    if not os.path.isdir(SEED_DIR):
        os.makedirs(SEED_DIR)
    else:
        pass   
     
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
        
        