if [ $# -eq 0 ]
then
  ./bin/ndfs ./input/bintree-cycle.prom op1 1
  ./bin/ndfs ./input/accept-cycle.prom op1 1
else
./bin/ndfs ./input/bintree-cycle.prom op1 $1
./bin/ndfs ./input/accept-cycle.prom op1 $1
fi
