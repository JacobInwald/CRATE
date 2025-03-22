# Exploit Title: Dirty Pipe 

- Exploit Author: Max Kellerman 
- Vendor Homepage: https://git.kernel.org/
- Software Link: https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/commit/?id=bbf5c979011a099af5dc76498918ed7df445635b
- Version: 5.8<5.10.102,5.15.25,5.16.11
- CVE: CVE-2022-0847 

## Disclaimer

This is a containerized version of CVE-2022-0847 for research and testing purposes. This was created as part of my final year project in security research. While running this should be safe, there is no guarantee of safety on your machine. I hold no responsibility for any damages caused to others machines as a result of running any of the exploits in this dataset.

## Instructions 

Use the associated `make` commands to run the example exploit.

```
    make build # Builds the container, needs to be run once before all other commands 

    make clean # Removes unused docker containers, NOTE: can remove unrelated docker containers that are not in use!

    make run/demo # Runs an encapsulated demo of the exploit, to test against different hardening combinations set the HARDEN_FLAGS environment variable before running this 

    make run/zsh # Opens a shell inside the build container for debugging and exploration. 
```

## References
- https://www.exploit-db.com/exploits/50808
- https://securitylabs.datadoghq.com/articles/dirty-pipe-vulnerability-overview-and-remediation/
