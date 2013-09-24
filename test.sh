#!/bin/bash

# Traverse input directory
# Run each promela file with sequential algorithm
# check output with parallel

#clean
rm *.out

for file in `ls ./input`
do
  echo "File <$file> : "
  ./bin/ndfs ./input/$file seq 1 > seq.out
  ./bin/ndfs ./input/$file alg2 2 > alg2.out
  ./bin/ndfs ./input/$file alg3 2 > alg3.out
  sed -n '1,1p' seq.out > result_seq.out
  sed -n '1,1p' alg2.out > result_alg2.out
  sed -n '1,1p' alg3.out > result_alg3.out

  DIFF1=`diff result_seq.out result_alg2.out`
  DIFF2=`diff result_alg3.out result_alg2.out`

  if [ -z "$DIFF1" ]; then
    if [ -z "$DIFF2" ]; then
      echo "Output OK"
    fi
  else
    echo "Invalid output"
  fi
done

