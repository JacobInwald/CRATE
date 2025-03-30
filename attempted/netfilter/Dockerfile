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
    wget \
    ca-certificates


# ----------------- SETUP SOURCE ---------------

# Install source code dependencies
RUN apt-get -y install \
  libncurses-dev \
  flex \ 
  bison \
  libssl-dev \
  bc \
  libelf-dev 

# Add source code and build kernel
ENV COMMIT="bcf876870b95592b52519ed4aafcf9d95999bc9c"
RUN wget https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/snapshot/linux-${COMMIT}.tar.gz && \
  tar -xvf linux-${COMMIT}.tar.gz && \ 
  rm linux-${COMMIT}.tar.gz && \
  mv linux-${COMMIT} linux

ADD linux.config linux/.config

RUN cd linux && \
  make bzImage -j 8

# Instrument build file to allow for hardening culpable file
ADD Makefile.patch ./
RUN patch linux/net/netfilter/Makefile Makefile.patch


# ------------- SETUP EMULATION -------------
# Install dependencies
RUN apt-get -y install \
  qemu-utils \
  qemu-system-x86 \
  qemu-system-gui \
  qemu-user \
  cpio \
  libc6-dev-i386 

# Use buzybox to build a minimal initramfs, ad  d the exploit and then package it up.
ENV BUSYVER="1.34.1"
RUN wget https://busybox.net/downloads/busybox-${BUSYVER}.tar.bz2 && \
  tar xf busybox-${BUSYVER}.tar.bz2 && \
  rm -f busybox-${BUSYVER}.tar.bz2 && \
  mv busybox-${BUSYVER} busybox

# Add in busy box config (builds as static)
ADD busybox.config busybox/.config

# Build busybox
RUN cd busybox && \
  make -j 8 && \
  make install 

# --------------- SETUP INITRAMFS -----------
# Add init script
ADD init ./busybox/_install/init
ADD vm-demo-exploit.sh ./busybox/_install/exploit


# Add and build exploit
ADD exploit.c ./
RUN gcc -m32 -static -o exploit exploit.c
ADD exploit.c /home/busybox/_install/exploit.c

# Organise root file strcuture
RUN cd busybox/_install && \
  mkdir -p proc sys dev etc etc/init.d usr/local && \
  chmod +x init && \
  mkdir home && \ 
  mv /home/exploit home/exploit



# Package up the initramfs
RUN cd busybox/_install && \
  find . -print0 | cpio --null -ov --format=newc > /home/initramfs

# ---------------- ADD DEMO ----------------
ADD find_kernel_offsets.sh ./
RUN apt-get -y install python python3-pip && \
  pip3 install ropper && \
  chmod +x find_kernel_offsets.sh

ADD initramfs.cpio.gz ./


ADD demo-exploit.sh ./
RUN chmod +x demo-exploit.sh
ENV HARDEN_FLAGS=""
