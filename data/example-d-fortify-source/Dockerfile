# syntax=docker/dockerfile:1
FROM pihole/debian-base
WORKDIR /home/

# Install dependencies
RUN apt-get -y update && apt-get install -y --no-install-recommends git \
    cmake \
    build-essential \
    libxml2-dev


# Install software
ADD d-fortify-source.c ./

# Set environment variable for adding hardening flags
ENV HARDEN_FLAGS=""

# Add in demo script
ADD demo-exploit.sh ./
RUN chmod +x demo-exploit.sh
