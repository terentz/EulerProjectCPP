#!/bin/bash


SPC=" "
SPCS=""
for n in {5..9}
do 
	SPCS=`echo "${SPC}${SPCS}"`
done
echo "${SPCS}hi"
exit

SZ=20
CMND="printf '%${SZ}s' ' '"
#v=`printf ${CMND}`
v=`exec ${CMND}`
echo "${v} hi there"

