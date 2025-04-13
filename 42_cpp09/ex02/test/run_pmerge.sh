#!/bin/bash
args=""
for i in $(seq 1 3000)
do
    args="$args $i"
done
./PmergeMe $args
