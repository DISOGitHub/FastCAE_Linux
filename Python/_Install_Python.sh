#!/bin/bash
sudo apt-get update
sudo apt-get upgrade
sudo apt-get dist-upgrade
sudo apt-get install  zlib*
sudo apt-get install build-essential python-dev python-setuptools python3-pip python-smbus
sudo apt-get install libreadline-dev libdb-dev libpcap-dev libexpat1-dev
sudo apt-get install libbz2-dev  libncurses5-dev xz-utils liblzma-dev 
sudo apt-get install libncursesw5-dev libgdbm-dev libc6-dev
sudo apt-get install libsqlite3-dev tk-dev
sudo apt-get install libssl-dev openssl
sudo apt-get install libffi-dev

tar -zxvf Python-3.7.0.tgz
cd Python-3.7.0/
./configure --enable-optimizations
make
sudo make install

sudo mv /usr/bin/python /usr/bin/python.bak
sudo ln -s /usr/local/bin/python3 /usr/bin/python
sudo mv /usr/bin/pip /usr/bin/pip.bak
sudo ln -s /usr/local/bin/pip3 /usr/bin/pip
