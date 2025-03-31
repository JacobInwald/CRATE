# Is more better? Evaluating security hardening options in GCC
This is my 4th year honours project from the University of Edinburgh. 
This project investigates whether combinations of hardening measures create new unintended side effects, such as one causing failure of another, or introducing new vulnerabilities.
This projects key contributions and findings include:
  - **A repeatable framework for reproducing crowd-sourced exploits**. To curate the dataset of exploits, I formulate a framework to ensure that any results are repeatable, and usable for research outside the scope of this project.  
  - **A curated dataset of exploit-code pairings.** I use the framework to create a small dataset of exploit-code pairings, that can be used to test the hypothesis of this project. Moreover, these exploits are robust, meaning that they can be run on a variety of x86-64 machines to achieve similar results.
  - **Systemic evaluation of combinations of hardening flags.** Two separate approaches are used to evaluate the effectiveness of combinations. Namely, these approaches are benchmarking and case study analysis. Overall, more is better, excepting one possible interaction. 
  - **Correction of misinformation regarding certain exploits.** This project finds inconsistencies in a variety of exploits tested, including errors in the National Vulnerability Database.


## Overview

This repository contains the information used for my dissertation, alongside some forks of benchmarks used.
The structure is:
- `attempted`: Attempted case studies, but not reproduced.
- `data`: Reproduced case studies from this project.
- `examples`: Examples of hardening flags, in the same format as the others.
- `exploit-db`: The results from the ExploitDB filtering.
- `recipe-benchmark`: The forked RecIPE repository.
- `RIPE64`: The forked RIPE64 repository.
- `writeup`: My writeup in Latex


## Usage

Exploring the test cases is quite simple. 
All of them have the exact same following commands:
```bash
    make build      # Builds the docker image
    make run/zsh    # Opens a zsh prompt in the image
    make run/bash   # Opens a bash prompt in the image
    make clean      # Remove unused images
    make run/demo   # Runs the demo script for each case study
```
These should be run withing the containing folder of the exploit. 

## Contributions

As this is university work, I cannot acccept contributions until this course is over.
If this project sounds interesting to you, check back next year when I can (maybe) open-source this properly.
To add another exploit, simply copy the template found in `data/_template` and get cracking!
