#!/bin/bash
if [ -d "/opt/gbdk/bin" ]; then
  PATH=/opt/gbdk/bin:$PATH
fi
lcc -o main.gb main.c
