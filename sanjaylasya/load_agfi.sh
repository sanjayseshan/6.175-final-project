#!/bin/sh

sudo modprobe -r pcieportal
sudo modprobe -r portalmem
sudo fpga-load-local-image -S 0 -I $1
sudo modprobe pcieportal
sudo modprobe portalmem
