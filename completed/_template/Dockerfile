#syntax=docker/dockerfile:1
FROM ubuntu:noble 
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
RUN apt-get -y install ... 

# Add source code 
RUN ...

# Instrument build file to allow for hardening culpable file
RUN ...

# ------------- ADD EXPLOIT -------------

RUN ...

# ---------------- ADD DEMO ----------------
ADD demo-exploit.sh ./
RUN chmod +x demo-exploit.sh
ENV HARDEN_FLAGS=""
