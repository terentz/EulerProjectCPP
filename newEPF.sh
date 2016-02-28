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

if [[ -z "$2" ]]
then
	echo "Error: parameter 3 must be set (to a short quoted description of the problem). Aborting..."
fi


# Extract param's...
NUM=` expr $1 - 0 `
NS_NEW=$2
NS_NEW_UC=`echo ${NS_NEW} | tr [a-z] [A-Z]`
DESC=$2

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


## Now update EulerProject.cpp...

NL=$'\n'
TAB=$'\t'
TABS=${TAB}${TAB}${TAB}${TAB}


# 1. Get the location of the next #include line...
let LN_NUM=0
while read line
do
	let LN_NUM=$LN_NUM+1
	#echo "line ${LN_NUM}"
#	echo -e "$line "
	args=( $line )
	if [[ ${args[0]} == "#include" ]] || [[ ${args[0]} == "//#include" ]]
	then
		# If args[1] has an EPxxxx code...
		if [[ "${args[1]}" =~ ^\"EP[0-9]{4}_[A-Za-z0-9]+\.hpp\"$ ]];
		then
			CURRENT_HEADER=${args[1]}
			CURRENT_NUMSTR=${CURRENT_HEADER:3:4}
			CURRENT_NUMSTR=`echo $CURRENT_NUMSTR | awk '{sub(/^0*/,"");}1'`
			CURRENT_NUMBER=$((CURRENT_NUMSTR))
			if [[ $((CURRENT_NUMBER)) -gt $((NUM)) ]];
			then
				let INCLUDE_START=$LN_NUM
				break
			fi
		fi
	fi
done < EulerProject.cpp

echo "A1. done "

# 2. And the trailing #define line
let LN_NUM=0
while read line
do
	let LN_NUM=$LN_NUM+1
	args=( $line )
	if [[ ${args[0]} == "#define" ]];
	then
		if [[ "${args[1]}" =~ ^EP[0-9]{4}_[A-Z0-9]+$ ]];
		then
			CURRENT_HEADER=${args[1]}
			CURRENT_NUMSTR=${CURRENT_HEADER:2:4}
			CURRENT_NUMSTR=`echo $CURRENT_NUMSTR | awk '{sub(/^0*/,"");}1'`
			CURRENT_NUMBER=$((CURRENT_NUMSTR))
			if [[ $((CURRENT_NUMBER)) -gt $((NUM)) ]];
			then
				let DEFINE_START=$((LN_NUM))+1
				break
			fi
		fi
	fi
done < EulerProject.cpp		

#echo "old define line $OLD_DEFINE_LINE"

echo "A2. done "

# 3. Now the menu_item line...
let LN_NUM=0
while read line
do
	let LN_NUM=$LN_NUM+1
	args=( $line )
	if [[ "${args[0]}" =~ ^menu_items\[EP[0-9]{4}_[A-Z0-9]+\]$ ]];
	then
		CURRENT_HEADER=${args[0]}
		CURRENT_NUMSTR=${CURRENT_HEADER:13:4}
		CURRENT_NUMSTR=`echo $CURRENT_NUMSTR | awk '{sub(/^0*/,"");}1'`
		CURRENT_NUMBER=$((CURRENT_NUMSTR))
		if [[ $((CURRENT_NUMBER)) -gt $((NUM)) ]];
		then
			let MENU_LINE_START=$LN_NUM+2
			break
		fi
	elif [[ "${args[1]}" =~ ^menu_items\[EP[0-9]{4}_[A-Z0-9]+\]$ ]];
	then	
		CURRENT_HEADER=${args[1]}
		CURRENT_NUMSTR=${CURRENT_HEADER:13:4}
		CURRENT_NUMSTR=`echo $CURRENT_NUMSTR | awk '{sub(/^0*/,"");}1'`
		CURRENT_NUMBER=$((CURRENT_NUMSTR))
		if [[ $((CURRENT_NUMBER)) -gt $((NUM)) ]];
		then
			let MENU_LINE_START=$LN_NUM+2
			break
		fi
	fi
done < EulerProject.cpp		

#echo "old menu line $OLD_MENU_LINE"

echo "A3. done "

# 4. Now the code...
let LN_NUM=0
while read line
do
	let LN_NUM=$LN_NUM+1
	args=( $line )
	if [[ "${args[0]}" =~ ^//$ ]] && [[ "${args[1]}" == "case" ]];
	then
		CURRENT_HEADER=${args[2]}
		CURRENT_NUMSTR=${CURRENT_HEADER:2:4}
		CURRENT_NUMSTR=`echo $CURRENT_NUMSTR | awk '{sub(/^0*/,"");}1'`
		CURRENT_NUMBER=$((CURRENT_NUMSTR))
		if [[ $((CURRENT_NUMBER)) -gt $((NUM)) ]];
		then
			let MENU_CODE_START=$LN_NUM+3
			break
		fi
	elif [[ "${args[0]}" == "case" ]];
	then
		CURRENT_HEADER=${args[1]}
		CURRENT_NUMSTR=${CURRENT_HEADER:2:4}
		CURRENT_NUMSTR=`echo $CURRENT_NUMSTR | awk '{sub(/^0*/,"");}1'`
		CURRENT_NUMBER=$((CURRENT_NUMSTR))
		if [[ $((CURRENT_NUMBER)) -gt $((NUM)) ]];
		then
			let MENU_CODE_START=$LN_NUM+3
			break
		fi
	fi
done < EulerProject.cpp		

echo "A4. done"

# Now to update the file..


# B1. Build new #include line
NEW_INCLUDE_LINE="#include \"EP${PAD}_${NS_NEW}.hpp\"${NL}"

# B2. Build new #define line
DEF_COL_OFFSET=48
NEW_DEFINE_HEAD="#define EP${PAD}_${NS_NEW_UC}"
DEF_LEN=${#NEW_DEFINE_HEAD}
let res=$((DEF_COL_OFFSET))-$((DEF_LEN))
SPCS=`printf "%${res}s"`
NEW_DEFINE_LINE="${NEW_DEFINE_HEAD}${SPCS}${NUM}${NL}"

# B3. Build new menu item
NML_COL_OFFSET=53
NEW_MENU_LINE_HEAD="${TAB}"'menu_items[EP'"${PAD}_${NS_NEW_UC}"']'
NML_LEN=${#NEW_MENU_LINE_HEAD}
let res=$((NML_COL_OFFSET))-$((NML_LEN))
SPCS=`printf "%${res}s"`
NEW_MENU_LINE="${TAB}${NEW_MENU_LINE_HEAD}${SPCS}= \"${DESC}\";${NL}"

# B4. Build new menu code
NEW_MENU_CODE_LN1="${TAB}${TAB}${TAB}case EP${PAD}_${NS_NEW_UC}:${NL}"
NEW_MENU_CODE_LN2="${TABS}using ${NS_NEW}::run;${NL}"
NEW_MENU_CODE_LN3="${TABS}${NS_NEW}::run();${NL}"
NEW_MENU_CODE_LN4="${TABS}break;${NL}"
NEW_MENU_CODE_LN5="${NL}"

# C. Update EulerProject.cpp...
FILE='EulerProject.cpp'

sed -i "${INCLUDE_START}i ${NEW_INCLUDE_LINE}" "$FILE"
sed -i "${DEFINE_START}i ${NEW_DEFINE_LINE}" "$FILE"
sed -i "${MENU_LINE_START}i ${NEW_MENU_LINE}" "$FILE"
sed -i "${MENU_CODE_START}i ${NEW_MENU_CODE_LN1}" "$FILE"
let MENU_CODE_START=$MENU_CODE_START+1
sed -i "${MENU_CODE_START}i ${NEW_MENU_CODE_LN2}" "$FILE"
let MENU_CODE_START=$MENU_CODE_START+1
sed -i "${MENU_CODE_START}i ${NEW_MENU_CODE_LN3}" "$FILE"
let MENU_CODE_START=$MENU_CODE_START+1
sed -i "${MENU_CODE_START}i ${NEW_MENU_CODE_LN4}" "$FILE"
let MENU_CODE_START=$MENU_CODE_START+1
sed -i "${MENU_CODE_START}i ${NEW_MENU_CODE_LN5}" "$FILE"

exit



