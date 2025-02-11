#syntax=docker/dockerfile:1
FROM debian:bullseye-slim
WORKDIR /home/


# Install core dependencies
RUN apt-get -y update && apt-get -y install --no-install-recommends \ 
    git \
    cmake \
    build-essential \
    libxml2-dev \
    sudo \ 
    zsh \
    meson \
    ninja-build \
    wget
RUN apt-get -y install ca-certificates
ENV HARDEN_FLAGS=""

# Install source code dependencies
RUN apt-get -y install \
  libncurses-dev \
  flex \ 
  bison \
  libssl-dev \
  bc \
  libelf-dev 

# Add source code
RUN wget https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/snapshot/linux-f6dd975583bd8ce088400648fd9819e4691c8958.tar.gz && \
  tar -xvf linux-f6dd975583bd8ce088400648fd9819e4691c8958.tar.gz && \ 
  rm linux-f6dd975583bd8ce088400648fd9819e4691c8958.tar.gz && \
  mv linux-f6dd975583bd8ce088400648fd9819e4691c8958 linux && \
  cd linux && \
  make defconfig

# Install emulation dependencies
RUN apt-get -y install \
  qemu-utils \
  qemu-system-x86 \
  qemu-system-gui \
  qemu-user 

ADD exploit.c ./
RUN gcc -static -o write_anything exploit.c

# Add in demo script
ADD demo-exploit.sh ./
RUN chmod +x demo-exploit.sh

# Use buzybox to build a minimal initramfs, ad  d the exploit and then package it up. 
RUN wget https://busybox.net/downloads/busybox-1.34.1.tar.bz2 && \
  tar xf busybox-1.34.1.tar.bz2 && \
  rm -f busybox-1.34.1.tar.bz2

# Add in busy box config (builds as static)
ADD .config busybox-1.34.1/.config

# Build busybox
RUN cd busybox-1.34.1 && \
  # make defconfig && \
  make -j 8 && \
  make install 

# Create initramfs and add exploit
ADD init ./busybox-1.34.1/_install/init
RUN cd busybox-1.34.1/_install && \
  mkdir -p proc sys dev etc etc/init.d && \
  chmod +x init && \
  mkdir home && \ 
  cp /home/write_anything home/write_anything 


RUN apt install -y cpio

# Package up the initramfs
RUN cd busybox-1.34.1/_install && \
  find . -print0 | cpio --null -ov --format=newc > /home/initramfs


