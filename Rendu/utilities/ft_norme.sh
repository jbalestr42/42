#!/bin/sh

tab=("if(" "while(" "break;" "continue;" "return;" "return(" "//"
	 "if\t" "while\t" "break\t" "return\t" "libc.h" "stdio.h" "printf" "switch")
dir=""

if [ "$1" = "" ]; then # Si il n'y a pas d'argument on utilise le dossier courant
	dir="."
else
	if [ -d "$1" ]; then # Sinon on verfie si le dossier existe
		dir=$1
	else
		echo "Dossier inexistant."
		exit
	fi
fi

for file in $dir/*.c # On parcours tous les fichiers .c pour verifier la norme
do
	echo $file
	for i in ${tab[*]}
	do
		grep -n $i $file
	done
done
