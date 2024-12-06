#!/bin/bash

# Get the directory of the script
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
echo "Current dir: $DIR"

# Get the experiments directory
EXPERIMENTS_DIR=$DIR/Facebook_DLRM
echo "Experiments dir: $EXPERIMENTS_DIR"

# Create a directory for the results called out_HBM_p32
OUT_DIR=$DIR/out
mkdir -p $OUT_DIR
CURRENT_OUT_DIR=$OUT_DIR/out_HBM_p32
mkdir -p $CURRENT_OUT_DIR

# Enter in the experiments folder
cd $EXPERIMENTS_DIR

for ((i=1; i<=3; i++)); do
    for experiment in *; do
        if [ -d "$experiment" ]; then
            echo "Running experiment: ${experiment}_${i}"
            cd $experiment
            ./host xclbin/vadd.hw.xclbin &> $CURRENT_OUT_DIR/${experiment}_iter${i}.txt
            cd ..
        fi
    done
done