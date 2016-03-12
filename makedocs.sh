#!/bin/sh

# Build the documentation
cd Bengine/doc
~/Qt/5.5/clang_64/bin/qdoc Bengine.qdocconfig
cd ../..
