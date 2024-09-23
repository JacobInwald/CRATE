import sys 
import subprocess 
import os 
    

file="data/"

if not os.path.exists('foo'): 
    f = open('foo.c', 'w') 
    f.write(prog) 
    f.close() 
    subprocess.call(["gcc", "foo.c", "-ofoo", "-std=c99", '-w', '-Ofast']) 
subprocess.call(["./foo"], stdin = sys.stdin) 