# syntax=docker/dockerfile:1
FROM debian:trixie
WORKDIR /home/

# Install dependencies
RUN apt-get -y update && \ 
    apt-get install -y --no-install-recommends git \
    cmake \
    build-essential \
    libxml2-dev \
    curl \
    ca-certificates \
    zsh

# Install python 2.7 support for the exploit
ARG PYPY_VERSION=2.7-v7.3.17
ARG PYPY_ROOT=pypy$PYPY_VERSION-linux64
ARG PYPY_URL=https://downloads.python.org/pypy/$PYPY_ROOT.tar.bz2
# Install pypy itself under /opt and symlink the pypy2 binary into
# /usr/local/bin so that it appears on the PATH.
RUN \
    cd /opt \
    && curl -L "${PYPY_URL}" | tar -xjf - \
    && ln -s "/opt/${PYPY_ROOT}/bin/pypy2" /usr/local/bin/pypy2


# Install Software
RUN git clone -c http.sslverify=false --single-branch -b 1.6 https://git.code.sf.net/p/ftnapps/crashmail/code crashmailv1.6


# Patch an error that happens when compiling with modern gcc
ADD pkt.patch ./
RUN patch crashmailv1.6/src/crashmail/pkt.c pkt.patch


# Install Exploit
ADD demo-exploit.sh ./
RUN chmod +x demo-exploit.sh
ADD exploit.py ./
RUN chmod +x exploit.py
