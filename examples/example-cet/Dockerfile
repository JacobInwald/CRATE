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


ENV SDE_VERSION="9.48.0-2024-11-25-lin"
RUN wget https://downloadmirror.intel.com/843185/sde-external-${SDE_VERSION}.tar.xz && \
    tar -xvf sde-external-${SDE_VERSION}.tar.xz && \
    rm -rf sde-external-${SDE_VERSION}.tar.xz && \
    mv sde-external-${SDE_VERSION} sde

# ----------------- SETUP SOURCE ---------------

# Add source code 
ADD example.c ./

# ---------------- ADD DEMO ----------------
ADD demo-exploit.sh ./
RUN chmod +x demo-exploit.sh
ENV HARDEN_FLAGS=""
