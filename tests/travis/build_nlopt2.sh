#! /bin/bash
set -ex
cd lib
[[ -e nlopt-2.4.2.tar.gz ]] || wget http://ab-initio.mit.edu/nlopt/nlopt-2.4.2.tar.gz
[[ -e nlopt2             ]] || (tar xzf nlopt-2.4.2.tar.gz && \
                                mv nlopt-2.4.2 nlopt2)
cd nlopt2
[[ -e Makefile           ]] || ./configure --disable-shared
make
cp .libs/libnlopt.a ../../bin/linux/libnlopt2.a
