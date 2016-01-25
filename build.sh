#! /bin/bash
echo "Rebuilding KDTree"
gcc src/kdt_selftest.c src/kdt_kdtree.c src/kdt_node.c src/kdt_point.c -o src/kdt_selftest -lczmq -std=c99
src/kdt_selftest

