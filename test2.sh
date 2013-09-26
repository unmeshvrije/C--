#!/bin/bash

# Traverse input directory
# Run each promela file with sequential algorithm
# check output with parallel

#clean
rm *.out

if [ "$1" = "all" ]
then
  for file in `ls ./input`
  do
    echo "File <$file> : "
    ./bin/ndfs ./input/$file seq 1 > seq.out
    ./bin/ndfs ./input/$file alg2 2 > alg2.out
    ./bin/ndfs ./input/$file alg3 2 > alg3.out

    SEQ_RESULT= grep "Found a Cycle" seq.out
    ALG2_RESULT= grep "Found a Cycle" alg2.out
    ALG3_RESULT= grep "Found a Cycle" alg3.out

    if [ "$SEQ_RESULT" -eq "$ALG2_RESULT" ]; then
      if [ "$ALG2_RESULT" -eq "$ALG3_RESULT" ]; then
        echo "Output OK"
      fi
    else
      echo "Invalid output"
    fi
  done

else
  file=$1
  for i in  `seq 1 $2`
  do
    echo "File <$file> : "
    ./bin/ndfs $file seq 1 > seq.out
    ./bin/ndfs $file alg2 3 > alg2.out
    ./bin/ndfs $file alg3 3 > alg3.out

    SEQ_RESULT= grep "Found a Cycle" seq.out
    ALG2_RESULT= grep "Found a Cycle" alg2.out
    ALG3_RESULT= grep "Found a Cycle" alg3.out

    if [ $SEQ_RESULT -eq $ALG2_RESULT ]; then
      if [ $ALG2_RESULT -eq $ALG3_RESULT ]; then
        echo "Output OK"
      fi
    else
      echo "Invalid output"
    fi
  done
  

fi
