#syntax=docker/dockerfile:1
FROM debian:buster-slim 
WORKDIR /home/


# Install dependencies
RUN apt-get -y update && apt-get -y install --no-install-recommends \ 
    git \
    cmake \
    build-essential \
    libxml2-dev \
    sudo \ 
    zsh \
    meson \
    ninja-build 

ENV HARDEN_FLAGS=""

# Add in demo script
ADD demo-exploit.sh ./
RUN chmod +x demo-exploit.sh


# Add source code

RUN git clone -c http.sslVerify=false https://github.com/Enlightenment/enlightenment && \
  cd enlightenment && \
  git fetch && \
  git checkout 49c95a3567d96986f1de3bd4a7c4e08c4c0ca4db

# Dependencies
RUN apt-get -y install \
  libpam0g libpam0g-dev \
  libexif12 libexif-dev \
  pkg-config \
  systemd \
  gettext \
  bluez libbluetooth-dev\ 
  libmount-dev \
  libeeze1 libeeze-bin libecore1 libeeze-dev
