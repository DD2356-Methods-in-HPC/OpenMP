#!/bin/bash


if [ "$#" -lt 2 ]; then
    echo "binary path, target output needed"
    exit 1
    threads=1
fi

executable="$1"
output="$2"

if [ "$#" -gt 2 ]; then
    threads="$3"
fi

runs=10
#Run program "runs" times and save output in $output using array notation

#Empty file and add opening bracket
echo [ > "$output"

# Loop 100 times
for ((i = 0; i < runs-1; i++)); do
    # Run your program and redirect the output to a file
    ./"$executable" "$threads" | awk '{print $0","}' >> "$output"
done
#run last iteration specially to not include ending comma
./"$executable" "$threads" >> "$output"

#add ending bracket
echo ] >> "$output"