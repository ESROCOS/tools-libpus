#!/bin/bash

UPY_TASTE_DIR="/home/esrocos/tool-src/upython-taste"

ACTUAL_DIR="$(dirname $(readlink -f $0))"

declare -a obcpScripts=(
	"code1.py"
	"code2.py"
	"code3.py"
	"ConditionStatement.py"
	"EventsControl.py"
	"ParametersControl.py"
	"WaitStatement.py"
	)

MPY_FILES=()

rm -f $ACTUAL_DIR/code.mpy.h

for i in "${obcpScripts[@]}"
do
   FILE_NAME="${i//".py"/""}"
      
   cat $ACTUAL_DIR/superClass.py $ACTUAL_DIR/$i > $ACTUAL_DIR/${FILE_NAME}p.py
   $UPY_TASTE_DIR/mpy-cross/mpy-cross -v $ACTUAL_DIR/${FILE_NAME}p.py
   
   MPY_FILES+=($ACTUAL_DIR/${FILE_NAME}p.mpy)
done

$UPY_TASTE_DIR/tools/mpytool.py tohdr ${MPY_FILES[@]} > $ACTUAL_DIR/code.mpy.h

echo "" >> $ACTUAL_DIR/code.mpy.h

cont=0
for i in "${obcpScripts[@]}"
do
   FILE_NAME_MAYUS=$(echo ${i//".py"/""} | awk '{print toupper($0)}')
   echo "#define $FILE_NAME_MAYUS $cont" >> $ACTUAL_DIR/defines.h
   cont=$((cont + 1))
   
	FILE_NAME="${i//".py"/""}"
	rm $ACTUAL_DIR/${FILE_NAME}p.py
	rm $ACTUAL_DIR/${FILE_NAME}p.mpy
done

echo "" >> $ACTUAL_DIR/defines.h
cat $ACTUAL_DIR/code.mpy.h >> $ACTUAL_DIR/defines.h
cat $ACTUAL_DIR/defines.h > $ACTUAL_DIR/code.mpy.h

rm -f $ACTUAL_DIR/defines.h

echo "Scripts to bytecode completed!"


