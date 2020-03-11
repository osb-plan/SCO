#!/bin/bash

echo "Add libsco to PATH"
STR=$(echo $LD_LIBRARY_PATH)

if [ -z "$STR" ] 
then
	export LD_LIBRARY_PATH=$(pwd)
else
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd)
fi

echo $STR
 
