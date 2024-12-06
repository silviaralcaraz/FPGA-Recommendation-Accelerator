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
CURRENT_EXP_NAME=HBM_p32
CURRENT_OUT_DIR=${OUT_DIR}/${CURRENT_EXP_NAME}
mkdir -p $CURRENT_OUT_DIR

# Array declarations for storing data
declare -a results

# CSV file header
echo "iter,round-number,vector-length,total-time,kernel-time" > ${CURRENT_OUT_DIR}/results_${CURRENT_EXP_NAME}_2.csv

# Enter in the experiments folder
cd $EXPERIMENTS_DIR

# Loop to execute experiments
for ((i=1; i<=3; i++)); do
    for experiment in *; do
        if [ -d "$experiment" ]; then
            echo "Running experiment: $experiment"
            cd "$experiment"
            # Run the experiment command and redirect output
            # ./host xclbin/vadd.hw.xclbin &> $CURRENT_OUT_DIR/${experiment}_iter${i}.txt

            # Extracting needed lines
            kernel_time=$(grep "Kernel execution time:" $CURRENT_OUT_DIR/${experiment}_iter${i}.txt | awk '{print $4}')
            total_time=$(grep "Total time:" $CURRENT_OUT_DIR/${experiment}_iter${i}.txt | awk '{print $3}')

            # Parse experiment name for round-number and vector-length
            round_num=$(echo $experiment | grep -oP 'facebook_dlrm2_\K[0-9]+(?=round)')
            vector_length=$(echo $experiment | grep -oP 'len\K[0-9]+')

            # Store results in array
            results+=("$i,$round_num,$vector_length,$total_time,$kernel_time")

            cd ..
        fi
    done
done

# Sort results by round-number and vector-length
IFS=$'\n' sorted_results=($(sort -t, -k2,2n -k3,3n <<<"${results[*]}"))
unset IFS

# Append sorted results to CSV
for entry in "${sorted_results[@]}"; do
    echo "$entry" >> ${CURRENT_OUT_DIR}/results_${CURRENT_EXP_NAME}_2.csv
done
