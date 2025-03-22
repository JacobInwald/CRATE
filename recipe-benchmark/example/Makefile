
all: main

main: main.c
	gcc -Wno-incompatible-pointer-types -g -w -D_FORTIFY_SOURCE=0 -no-pie -z execstack -z norelro -fno-stack-protector -fcf-protection=${TYPE} -o main main.c homebrew.c
	~/.local/bin/ROPgadget --binary main > gadget

clean:
	rm main gadget
