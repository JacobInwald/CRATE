# Purpose: Makefile for docker image
IMAGE_NAME=dirtypipe
EXITED:=$(shell sudo docker ps -a -q -f status=exited)


clean: 
	sudo docker rm -v $(EXITED)

build:
	sudo docker build -t $(IMAGE_NAME) . 

run/zsh:
	sudo docker run -it --entrypoint /bin/zsh $(IMAGE_NAME)

run/bash:
	sudo docker run -it --entrypoint /bin/sh $(IMAGE_NAME)

run/demo:
	sudo docker run -it -e HARDEN_FLAGS=$(HARDEN_FLAGS) --entrypoint ./demo-exploit.sh $(IMAGE_NAME)
