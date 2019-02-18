#!/bin/sh
cd "$(dirname "$0")"
cd ..
make
cd scripts

mkdir ../../tmp
cd ../../tmp
rm -rf *
cp -R ../ofMIDI2DMX ofMIDI2DMX
zip -r ofMIDI2DMX_osx_version.zip ofMIDI2DMX
openssl dgst -sha256 ofMIDI2DMX_osx_version.zip