FROM debian:jessie

MAINTAINER Potiguar Faga <potz@potz.me>

# Installs requirements for comiling the firmware
RUN apt-get update && \
    apt-get install -y git-core && \ 
    apt-get install -y gcc-avr binutils-avr avr-libc make && \
    rm -rf /var/lib/apt/lists/*

ENV BRANCH master

RUN git clone -q --branch=$BRANCH https://github.com/jackhumbert/qmk_firmware firmware && \
    cd firmware && \ 
    cd /firmware/keyboards/ergodox_ez && make clean

# Map this volume to some folder wher a keymap.c can be found.
# The resulting firmware.hex will also be put in this folder when finished.
VOLUME /keymap

COPY entrypoint.sh /

CMD [ "./entrypoint.sh" ]
