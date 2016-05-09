#!/bin/bash

rootfs="/home/twoflower/GBS-ROOT-3.0TM1/local/BUILD-ROOTS/scratch.armv7l.0/"
rootfsd="/home/twoflower/GBS-ROOT-3.0TM1/local/BUILD-ROOTS/scratch.armv7l.0/"
buildArgs="CPLUS_INCLUDE_PATH=$rootfs/usr/lib/gcc/armv7l-tizen-linux-gnueabi/4.9.2/include/c++/:$rootfs/usr/lib/gcc/armv7l-tizen-linux-gnueabi/4.9.2/include/c++/armv7l-tizen-linux-gnueabi/:$rootfs/usr/include/llvm/:$rootfs/usr/include/llvm-c/:$rootfs/usr/local/include:$rootfs/usr/include CXXFLAGS=-Wno-deprecated-declarations"
arch="arm-softfp"
sudo ROOTFS_DIR=$rootfsd $buildArgs ./build.sh $arch debug verbose clean cross clang3.6

