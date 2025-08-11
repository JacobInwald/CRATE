#syntax=docker/dockerfile:1
FROM ubuntu:noble
WORKDIR /home/
ENV DEBIAN_FRONTEND='noninteractive'

RUN apt-get -y update
RUN apt-get -y upgrade

# Install core dependencies
RUN apt-get -y install --no-install-recommends \ 
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

# Intel SDE for unsupported CPUs
ENV SDE_VERSION="9.48.0-2024-11-25-lin"
RUN wget https://downloadmirror.intel.com/843185/sde-external-${SDE_VERSION}.tar.xz && \
    tar -xvf sde-external-${SDE_VERSION}.tar.xz && \
    rm -rf sde-external-${SDE_VERSION}.tar.xz && \
    mv sde-external-${SDE_VERSION} sde


# ----------------- SETUP SOURCE ---------------

# Add source code 
RUN git clone --single-branch -b 1.6 https://git.code.sf.net/p/ftnapps/crashmail/code crashmail

# Patch an error that happens when compiling with modern gcc
ADD pkt.patch ./
RUN patch crashmail/src/crashmail/pkt.c pkt.patch


# ------------- ADD EXPLOIT -------------

RUN apt-get -y install curl gdb gcc-multilib

# Install python 2.7 support for the exploit
ARG PYPY_VERSION=2.7-v7.3.17
ARG PYPY_ROOT=pypy$PYPY_VERSION-linux64
ARG PYPY_URL=https://downloads.python.org/pypy/$PYPY_ROOT.tar.bz2

# Install pypy itself under /opt and symlink the pypy2 binary into
# /usr/local/bin so that it appears on the PATH.
RUN cd /opt \
    && curl -L "${PYPY_URL}" | tar -xjf - \
    && ln -s "/opt/${PYPY_ROOT}/bin/pypy2" /usr/local/bin/pypy2

RUN useradd user
ADD exploit.py ./
RUN chmod +x exploit.py
RUN chown user exploit.py

# ---------------- ADD DEMO ----------------
ADD demo-exploit.sh ./
RUN chmod +x demo-exploit.sh
ENV HARDEN_FLAGS=""
