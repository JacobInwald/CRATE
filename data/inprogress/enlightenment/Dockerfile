#syntax=docker/dockerfile:1
# FROM debian:bullseye-slim
FROM ubuntu:focal
WORKDIR /home/

ARG DEBIAN_FRONTEND=noninteractive
RUN ln -snf /usr/share/zoneinfo/$CONTAINER_TIMEZONE /etc/localtime && echo $CONTAINER_TIMEZONE > /etc/timezone
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

# Add source code dependencies

RUN apt-get install -y \
    meson ninja-build check libpam0g-dev \
    libfreetype6-dev libfribidi-dev libfontconfig1-dev libpng-dev \
    libjpeg-dev zlib1g-dev libdbus-1-dev libluajit-5.1-dev \
    libx11-dev libxcursor-dev libxrender-dev libxrandr-dev \
    libxfixes-dev libxdamage-dev libxcomposite-dev libxss-dev \
    libxext-dev libxinerama-dev libxkbfile-dev \
    libxtst-dev libxcb1-dev libxcb-shape0-dev libxcb-keysyms1-dev \
    libpulse-dev libsndfile1-dev libudev-dev systemd libblkid-dev \
    libmount-dev libgstreamer1.0-dev libtiff5-dev libgif-dev \
    curl libssl-dev libgl1-mesa-dev libspectre-dev \
    libpoppler-cpp-dev librsvg2-dev libraw-dev \
    libbullet-dev util-linux libpam0g libpam0g-dev \
    libexif12 libexif-dev pkg-config systemd gettext \
    bluez libbluetooth-dev libmount-dev libefl-all-dev \ 
    liblua5.1-0-dev liblua5.2-dev libwebp-dev libopenjp2-7-dev \
    scim-dev

# Build EFL as a required library
RUN git clone http://git.enlightenment.org/enlightenment/efl.git
RUN cd efl && \
    meson setup build && \
    ninja -C build && \
    sudo ninja -C build install && \
    sudo ldconfig


# Add source code
RUN git clone https://github.com/Enlightenment/enlightenment --branch=v0.23.0

# Build source code
RUN cd enlightenment && \
  meson build && \
  ninja -C build && \
  sudo ninja -C build install && \
  sudo ldconfig

# ------------- ADD EXPLOIT -------------

ADD exploit.sh ./
RUN chmod +x exploit.sh


# ---------------- ADD DEMO ----------------
ADD demo-exploit.sh ./
RUN chmod +x demo-exploit.sh
ENV HARDEN_FLAGS=""

