#!/bin/bash

BLACK='\033[0;30m'
RED='\033[0;31m'
GREEN='\033[0;32m'
ORANGE='\033[0;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
LIGHT_GRAY='\033[0;37m'
DARK_GRAY='\033[1;30m'
LIGHT_RED='\033[1;31m'
LIGHT_GREEN='\033[1;32m'
YELLOW='\033[1;33m'
LIGHT_BLUE='\033[1;34m'
LIGHT_PURPLE='\033[1;35m'
LIGHT_CYAN='\033[1;36m'
WHITE='\033[1;37m'
NO_COLOR='\033[0m'

clear
codeFile=$1

fileName=${codeFile%.*}
fileCreated=""

command=""
language=""
flag=""
meta=$3

if [[ $3 == "meta1" ]]
then
    flag="-l"
fi

if [[ $3 == "meta2" ]]
then
    flag="-t"
fi

if [[ $3 == "meta3" ]]
then
    flag="-s"
fi

echo -e "${LIGHT_CYAN}[⏲️ ] ${ORANGE}Compiling $codeFile..."

lex $1.l
yacc -d -v $1.y
cc -o $1 y.tab.c lex.yy.c token_type.c error_handling.c abstract_syntax_tree.c linked_list.c

command="./$1 $flag"

echo -e "${LIGHT_CYAN}[✅] ${LIGHT_GREEN}$codeFile Compiled.${CYAN}"
sleep 1

clear

cat <<"EOF"
       _           _
      | |         | |
      | |_   _  __| | __ _  ___
  _   | | | | |/ _` |/ _` |/ _ \
 | |__| | |_| | (_| | (_| |  __/
  \____/ \__,_|\__,_|\__, |\___|
                      __/ |
                     |___/
                                                (   ) )
                                                 ) ( (
   __          ____                    __      _______)_
  / /  __ __  / __/__ ___ _  __ _____ / /   '-|---------|
 / _ \/ // / _\ \/ _ `/  ' \/ // / -_) /   ( C|/\/\/\/\/|
/_.__/\_, / /___/\_,_/_/_/_/\_,_/\__/_/     '-./\/\/\/\/|
     /___/                                    '_________'
                                               '-------'
EOF

i=0
for file in `ls ./tests/$meta/*.dgo`
do
	i=$((i+1))
	start=`date +%s%N`
	result="${ORANGE}[⊗] Time Limit Exceeded"
	prefix="${LIGHT_CYAN}[${YELLOW}$i${LIGHT_CYAN}] ${NO_COLOR}Running test case: ${ORANGE}${file#./dataset/}\t ${LIGHT_RED}$language ${DARK_GRAY}|"
	timeout $2 $command < $file > sol.out && {
	end=`date +%s%N`
	elapsed=$((end-start))
	conversion=1000000000
	runtime=$(bc <<< "scale=3 ; $elapsed / $conversion")
	second="output"
	outputFile="${file/input/$second}"
	second=".out"
	outputFile="${outputFile/.dgo/$second}"
	result="${LIGHT_GREEN}[✓] Accepted"
	cmp --silent $outputFile sol.out || result="${LIGHT_RED}[✗] Wrong Answer"
	echo -e "$prefix $result ${NO_COLOR}[${runtime}s]"
	cmp --silent $outputFile sol.out
	t=$?
	if [[ $t == 1 ]]
	then
		if [[ $4 == "-debug" ]]
		then
			echo -e "${LIGHT_GRAY}Expected Output:"
			cat $outputFile
			echo -e "${DARK_GRAY}----------------"
			echo -e "${LIGHT_GRAY}Given Output:"
			cat sol.out
		fi
	fi
	} || echo -e "$prefix $result ${NO_COLOR}[$2s]"
done


if [[ $fileCreated != "" ]]
then
	rm $fileCreated
fi

rm sol.out