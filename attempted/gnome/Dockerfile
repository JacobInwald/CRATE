#syntax=docker/dockerfile:1
FROM debian:bullseye-slim
WORKDIR /home/
ENV DEBIAN_FRONTEND=noninteractive

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
RUN apt-get -y update && apt-get -y install \
  ninja-build meson automake pkg-config \
  glib2.0 gtk+-3.0 libgnome-desktop-3-dev \
  gnome 

# Add source code 
RUN wget http://ftp.gnome.org/pub/gnome/sources/gnome-font-viewer/3.34/gnome-font-viewer-3.34.0.tar.xz && \
  tar -xvf gnome-font-viewer-3.34.0.tar.xz && \
  rm 
# Instrument build file to allow for hardening culpable file
# RUN ...

# ------------- ADD EXPLOIT -------------

RUN useradd -m user 
USER user
ADD exploit.py /home/user/ 
# RUN chmod +x /home/user/exploit.py
USER root


# ---------------- ADD DEMO ----------------
ADD demo-exploit.sh ./
RUN chmod +x demo-exploit.sh
ENV HARDEN_FLAGS=""
