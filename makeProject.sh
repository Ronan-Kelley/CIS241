#!/bin/env bash

[ -z "$1" ] && exit 1

mkdir -p $1 && cd $1
git init
mkdir -p bin include lib share man info
echo "$1" > README.md
touch .gitignore
git add bin include lib share man info .gitignore README.md
git commit -m "Create initial structure"

# vim: syntax=sh
