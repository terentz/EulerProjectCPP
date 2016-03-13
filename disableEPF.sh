#!/bin/bash


# Check param's...
if ! [[ "$1" =~ ^[0-9]+$ ]]; then
	echo "Error: parameter 1 must be an integer! Aborting..."
	exit
fi


# Extract param's...
let NUM=` expr $1 - 0 `
FILE="EulerProject.cpp"

## Now update EulerProject.cpp...

NL=$'\n'
TAB=$'\t'
TABS=${TAB}${TAB}${TAB}${TAB}


# 1. Get the location of the #include line and comment it out...
let LN_NUM=0
while read line
do
	let LN_NUM=$LN_NUM+1
	#echo "line ${LN_NUM}"
#	echo -e "$line "
	args=( $line )
	if [[ ${args[0]} == "#include" ]]; then
		# If args[1] has an EPxxxx code...
		if [[ "${args[1]}" =~ ^\"EP[0-9]{4}_[A-Za-z0-9]+\.hpp\"$ ]]; then
			CURRENT_HEADER=${args[1]}
			CURRENT_NUMSTR=${CURRENT_HEADER:3:4}
			CURRENT_NUMSTR=`echo $CURRENT_NUMSTR | awk '{sub(/^0*/,"");}1'`
			let CURRENT_NUMBER=$((CURRENT_NUMSTR))
			if [[ $((CURRENT_NUMBER)) -eq $((NUM)) ]]; then
                NL="//${line}"
                sed -i 's,'"${line}"','"${NL}"',g' "$FILE"
				break
			fi
		fi
	fi
done < EulerProject.cpp

echo "A1. done "

# 2. Now the menu_item line (ignore #defines)
let LN_NUM=0
while read line
do
	let LN_NUM=$LN_NUM+1
	args=( $line )
    if [[ "${args[0]}" =~ ^menu_items\[EP[0-9]{4}_[A-Z0-9]+\]$ ]]; then
		CURRENT_HEADER=${args[0]}
		CURRENT_NUMSTR=${CURRENT_HEADER:13:4}
		CURRENT_NUMSTR=`echo $CURRENT_NUMSTR | awk '{sub(/^0*/,"");}1'`
		let CURRENT_NUMBER=$((CURRENT_NUMSTR))
		if [[ $((CURRENT_NUMBER)) -eq $((NUM)) ]]; then
			NL="//${line}"
			echo "old line : ${line}"
			echo "new line : ${NL}"
            sed -i 's,'"${line}"','"${NL}"',g' "$FILE"
			break
		fi
    fi
done < EulerProject.cpp
exit
echo "A2. done "

# 3. Now the code...
let LN_NUM=0
let BLOCK_LN=0
while read line
do
	let LN_NUM=$LN_NUM+1
	args=( $line )
	if [[ "${args[0]}" =~ ^//$ ]] && [[ "${args[1]}" == "case" ]] && [[ $BLOCK_LN -eq 0 ]]; then
		CURRENT_HEADER=${args[2]}
		CURRENT_NUMSTR=${CURRENT_HEADER:2:4}
		CURRENT_NUMSTR=`echo $CURRENT_NUMSTR | awk '{sub(/^0*/,"");}1'`
		let CURRENT_NUMBER=$((CURRENT_NUMSTR))
		if [[ $((CURRENT_NUMBER)) -eq $((NUM)) ]]; then
			NL="//${line}"
            sed -i 's,'"${line}"','"${NL}"',g' "$FILE"
			let BLOCK_LN=1
		fi
	fi
	if [[ $BLOCK_LN -gt 0 ]]; then
        let BLOCK_LN=1+$BLOCK_LN
        NL="//${line}"
        sed -i 's,'"${line}"','"${NL}"',g' "$FILE"
    fi
    if [[ $BLOCK_LN -gt 3 ]]; then
        break
    fi
done < EulerProject.cpp

echo "A3. done"
exit
