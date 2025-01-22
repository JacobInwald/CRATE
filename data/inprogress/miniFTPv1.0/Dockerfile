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
    zsh \ 
    python3

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

# Install GDB
RUN apt-get install -y --no-install-recommends gdb

# Install Software
RUN git clone -c http.sslverify=false --single-branch -b master https://github.com/skyqinsc/MiniFtp miniFTP

ADD Makefile.patch ./
RUN patch -p1 miniFTP/Makefile ./Makefile.patch 

# Install Exploit
ADD setup-exploit.sh ./
RUN chmod +x setup-exploit.sh
RUN ./setup-exploit.sh

ADD demo-exploit.sh ./
RUN chmod +x demo-exploit.sh
