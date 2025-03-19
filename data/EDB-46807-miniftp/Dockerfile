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
RUN apt-get install -y gcc-10
# Add source code 
RUN git clone --single-branch -b master https://github.com/skyqinsc/MiniFtp miniFTP


# Instrument build file to allow for hardening culpable file
ADD Makefile.patch ./
RUN patch -p1 miniFTP/Makefile ./Makefile.patch 

# ------------- ADD EXPLOIT -------------

RUN apt-get install -y curl

# Install python 2.7 support for the exploit
ARG PYPY_VERSION=2.7-v7.3.17
ARG PYPY_ROOT=pypy$PYPY_VERSION-linux64
ARG PYPY_URL=https://downloads.python.org/pypy/$PYPY_ROOT.tar.bz2
# Install pypy itself under /opt and symlink the pypy2 binary into
# /usr/local/bin so that it appears on the PATH.

RUN cd /opt \
    && curl -L "${PYPY_URL}" | tar -xjf - \
    && ln -s "/opt/${PYPY_ROOT}/bin/pypy2" /usr/local/bin/pypy2

ADD exploit.sh ./
RUN chmod +x exploit.sh

# ---------------- ADD DEMO ----------------
ADD demo-exploit.sh ./
RUN chmod +x demo-exploit.sh
ENV HARDEN_FLAGS=""
