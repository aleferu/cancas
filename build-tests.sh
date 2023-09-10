#!/usr/bin/env bash

set -xe

gcc -Wall -Wextra -Wconversion -pedantic -g test.c -o run-tests
