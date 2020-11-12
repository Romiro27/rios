#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/ri.kernel isodir/boot/ri.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "RI 1.0" {
	multiboot /boot/ri.kernel
}
EOF
grub-mkrescue -o ri-1.0-i686.iso isodir
