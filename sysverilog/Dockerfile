FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        verilator \
        make \
        g++ \
        git \
        ca-certificates \
        pkg-config \
        perl \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /work

