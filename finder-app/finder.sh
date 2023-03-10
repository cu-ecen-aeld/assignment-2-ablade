#!/bin/bash

if [ $# -lt 2 ]
then
	echo -e "You need to provied 2 arguments\nFirst arg: directory path\nSecond arg: text string to search\n"
	exit 1
else
	#echo "Thank you for providing 2 arguments"
	filesdir=$1
	searchstr=$2

fi

if [[ -d $filesdir ]]
then
	#echo "This is a good directory"
	#files=`find $filesdir -type f -print`
	#_files=`find $filesdir type -f`
	#for i in $VAR
	cnt=0
	X=`find $filesdir -type f | wc -l`
	Y=`grep -r $searchstr $filesdir | wc -l`

	echo "The number of files are $X and the number of matching lines are $Y"
	# for i in `find $filesdir -type f -print`
	# do
	# 	gl=`grep $searchstr $i | wc -l`
	# 	echo $i
	# 	(( cnt+=gl ))
	# done
	# echo $cnt

else
	echo "This is not a directory"
	exit 1

fi

#  corn
#  corn
#  corn
#  corn
#  corn
#  
#9) Write a shell script finder-app/finder.sh as described below:
#
#Accepts the following runtime arguments: the first argument is a path to a directory on the filesystem, referred to below as filesdir; the second argument is a text string which will be searched within these files, referred to below as searchstr
#
#Exits with return value 1 error and print statements if any of the parameters above were not specified
#
#Exits with return value 1 error and print statements if filesdir does not represent a directory on the filesystem
#
#Prints a message "The number of files are X and the number of matching lines are Y" where X is the number of files in the directory and all subdirectories and Y is the number of matching lines found in respective files, where a matching line refers to a line which contains searchstr (and may also contain additional content).
