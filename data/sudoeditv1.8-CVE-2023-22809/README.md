# Exploit Title: Crashmail 

I'm not sure if this exploit is working correctly, output is different from benign input or badly formed exploits. 
However, it doesn't spawn a shell which I believe is the intention. 
This may be due to new versions of gcc applying -PIE automatically, and causing the ROP chain to break. 

## Disclaimer

This is a containerized version of an *exploit* for research and testing purposes. This was created as part of my final year project in security research. While running this should be safe, there is no guarantee of safety on your machine. I hold no responsibility for any damages caused to others machines as a result of running any of the exploits in this dataset.

## Instructions 

Use the associated `make` commands to run the example exploit.

```
    make build # Builds the container, needs to be run once before all other commands 

    make clean # Removes unused docker containers, NOTE: can remove unrelated docker containers that are not in use!

    make run/demo # Runs an encapsulated demo of the exploit, to test against different hardening combinations set the HARDEN_FLAGS environment variable before running this 

    make run/bash # Opens a shell inside the build container for debugging and exploration. 
```

