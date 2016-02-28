#!/bin/bash


# Check param's...
if ! [[ "$1" =~ ^[0-9]+$ ]]
then
	echo "Error: parameter 1 must be an integer! Aborting..."
	exit
fi

if [[ -z "$2" ]]
then
	echo "Error: parameter 2 must be set (to a problem name in caps-lead camel-case). Aborting..."
	exit
fi


# Extract param's...
NUM=` expr $1 - 0 `
NS_NEW=$2
NS_NEW_UC=`echo ${NS_NEW} | tr [a-z] [A-Z]`

# Set filenames...
PAD=`printf %04d $NUM`
TITLE="EP${PAD}_${NS_NEW}"
CPP_NEW="${TITLE}.cpp"
HPP_NEW="${TITLE}.hpp"


# Create files...
cp EPxxxx_EulerTemplate.cpp ${CPP_NEW}
cp EPxxxx_EulerTemplate.hpp ${HPP_NEW}


# Replace strings
CPP_TMP="EPxxxx_EulerTemplate.cpp"
HPP_TMP="EPxxxx_EulerTemplate.hpp"
HEAD_TMP="EPXXXX_EULERTEMPLATE_HPP_"
HEAD_NEW="EP${PAD}_${NS_NEW_UC}_HPP_"
NS_TMP="EulerTemplate"
DATE_TMP="Created on: DATE"
DATE=`date +"%d/%m/%Y"`
#echo $DATE
DATE_NEW="Created on: ${DATE}"

# .cpp first...
sed -i 's,'"${DATE_TMP}"','"${DATE_NEW}"',g' "$CPP_NEW"
sed -i "s/${HPP_TMP}/${HPP_NEW}/g" "$CPP_NEW"
sed -i "s/${CPP_TMP}/${CPP_NEW}/g" "$CPP_NEW"
sed -i "s/${NS_TMP}/${NS_NEW}/g" "$CPP_NEW"

# Now .hpp...
sed -i 's,'"${DATE_TMP}"','"${DATE_NEW}"',g' "$HPP_NEW"
sed -i "s/${HPP_TMP}/${HPP_NEW}/g" "$HPP_NEW"
sed -i "s/${NS_TMP}/${NS_NEW}/g" "$HPP_NEW"
sed -i "s/${HEAD_TMP}/${HEAD_NEW}/g" "$HPP_NEW"

exit

