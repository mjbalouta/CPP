#!/bin/bash

# Usage: ./GenerateNumbers.sh [amount] [max_range]
# Example: ./GenerateNumbers.sh 100 1000
# Generates 100 unique numbers between 1 and 1000

shuf -i 1-$2 -n $1 | tr '\n' ' '
echo ""