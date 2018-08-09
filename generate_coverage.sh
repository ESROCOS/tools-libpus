#!/bin/bash
geninfo --base-directory /home/esrocos/esrocos_workspace/tools/libpus --gcov-tool /usr/bin/gcov-6 --output-filename /home/esrocos/esrocos_workspace/tools/libpus/build/coverage.info --no-external `find . -name *.gcda`
genhtml /home/esrocos/esrocos_workspace/tools/libpus/build/coverage.info -o /home/esrocos/esrocos_workspace/tools/libpus/build/coverage
