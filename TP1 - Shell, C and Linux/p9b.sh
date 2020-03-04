#!/bin/zsh

#To create directories
counter=1

echo "Creating directories for $1 classes"

while [ $counter -le $1 ]
do
	mkdir "aula $counter"
	((counter++))
done

echo "All directories created!\n"

ls

#################################################

#To remove directories created above (Uncomment to do that)
#counter=1

#echo "Removing directories for $1 classes"

#while [ $counter -le $1 ]
#do
#	rm -rf "aula $counter"
#	((counter++))
#done

#echo "All directories removed!\n"

#ls