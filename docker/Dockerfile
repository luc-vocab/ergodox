FROM debian:jessie

MAINTAINER Potiguar Faga <potz@potz.me>

# Installs requirements for comiling the firmware
RUN apt-get update && \
    apt-get install -y git-core && \ 
    apt-get install -y gcc-avr binutils-avr avr-libc make && \
    rm -rf /var/lib/apt/lists/*

# Specify which SHA and branch from jack humbert's 
# firmware repository we want to fetch
ENV SHA ec4428b1c670756625b773716d9912a69a1dab84
ENV BRANCH master

RUN git clone -q --branch=$BRANCH https://github.com/jackhumbert/qmk_firmware firmware && \
    cd firmware && git checkout -f $SHA && \ 
    cd /firmware/keyboard/ergodox_ez && make clean

# Map this volume to some folder wher a keymap.c can be found.
# The resulting firmware.hex will also be put in this folder when finished.
VOLUME /keymap

COPY entrypoint.sh /

CMD [ "./entrypoint.sh" ]
