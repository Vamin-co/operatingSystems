#!/bin/bash
# make  main dir with current date and time
main_dir=$(date +"%Y-%m-%d_%H-%M-%S")
mkdir "$main_dir"

# array for languages 
langugages=(Python Java C JavaScript C# R Go Ruby Swift Perl)

# for loop for making sub dirs, txt files, and writting to the txt files
for i in {101..110}; do 
    sub_dir="$main_dir/file$i"
    mkdir "$sub_dir"

    # use i counter for naming if tuser text files
    txt_file="$sub_dir/tuser$((i+400)).txt"
    echo "${langugages[$((i-101))]}" > "$txt_file"
done

