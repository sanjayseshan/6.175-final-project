#!/bin/bash

echo "Testing add"
./testMC.sh add32
timeout 1 ./top_pipelined

echo "Testing and"
./testMC.sh and32
timeout 1 ./top_pipelined

echo "Testing or"
./testMC.sh or32
timeout 1 ./top_pipelined

echo "Testing sub"
./testMC.sh sub32
timeout 1 ./top_pipelined

echo "Testing xor" 
./testMC.sh xor32
timeout 1 ./top_pipelined

echo "Testing hello"
./testMC.sh hello32
timeout 1 ./top_pipelined

echo "Testing mul"
./testMC.sh mul32
timeout 2 ./top_pipelined

echo "Testing reverse"
./testMC.sh reverse32
timeout 1 ./top_pipelined

echo "Testing thelie"
./testMC.sh thelie32
timeout 1 ./top_pipelined

echo "Testing thuemorse"
./testMC.sh thuemorse32
timeout 1 ./top_pipelined

echo "Testing matmul"
./testMC.sh matmul32
timeout 60 ./top_pipelined

