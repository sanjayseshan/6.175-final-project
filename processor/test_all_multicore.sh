#!/bin/bash

echo "Testing add"
./testMC.sh add32
timeout 1 ./top_multicore

echo "Testing and"
./testMC.sh and32
timeout 1 ./top_multicore

echo "Testing or"
./testMC.sh or32
timeout 1 ./top_multicore

echo "Testing sub"
./testMC.sh sub32
timeout 1 ./top_multicore

echo "Testing xor" 
./testMC.sh xor32
timeout 1 ./top_multicore

echo "Testing hello"
./testMC.sh hello32
timeout 1 ./top_multicore

echo "Testing mul"
./testMC.sh mul32
timeout 2 ./top_multicore

echo "Testing reverse"
./testMC.sh reverse32
timeout 1 ./top_multicore

echo "Testing thelie"
./testMC.sh thelie32
timeout 1 ./top_multicore

echo "Testing thuemorse"
./testMC.sh thuemorse32
timeout 1 ./top_multicore

echo "Testing matmul"
./testMC.sh matmul32
timeout 60 ./top_multicore

echo "Testing multicore32"
./testMC.sh multicore32
timeout 60 ./top_multicore

