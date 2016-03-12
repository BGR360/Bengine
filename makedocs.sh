#!/bin/sh

# Build the documentation
cd Bengine/doc
~/Qt/5.5/clang_64/bin/qdoc Bengine.qdocconfig

# Copy all the HTML files to my github.io directory
cp -R html/. /Users/Ben/Documents/Coding\ Projects/BGR360.github.io/benginedoc/

cd ../..
