#syntax=docker/dockerfile:1
FROM debian:trixie
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

ENV HARDEN_FLAGS=""

# Add in demo script
ADD demo-exploit.sh ./
RUN chmod +x demo-exploit.sh

# Add source code
RUN git clone -c http.sslVerify=false  https://github.com/<project> code && \
  cd code && \
  git fetch && \
  git checkout  

# Install source code dependencies
# RUN apt-get -y install 
