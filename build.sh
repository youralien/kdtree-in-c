#! /bin/bash
echo "Rebuilding KDTree"
gcc src/kdt_selftest.c src/kdt_kdtree.c -o src/kdt_selftest -lczmq
src/kdt_selftest
