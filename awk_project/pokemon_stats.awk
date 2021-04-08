BEGIN {
	FS=",";

	highestTotal=0;
	bestPokemon="";

	lowestTotal=-1;
	bestPokemon="";

	totalRows=0;
	totalTotal=0;
	totalHP=0;
	totalAtk=0;
	totalDef=0;
	totalSPAtk=0;
	totalSPDef=0;
	totalSpeed=0;
}

# find best Pokemon
/^[0-9]/ {
	if ($5 > highestTotal) {
		highestTotal=$5;
		bestPokemon=$2;
	} else if ($5 == highestTotal) {
		bestPokemon=bestPokemon "\n\t" $2
	}
}

# find all averages
/^[0-9]/ {
	totalRows+=1
	totalTotal+=$5
	totalHP+=$6
	totalAtk+=$7
	totalDef+=$8
	totalSPAtk+=$9
	totalSPDef+=$10
	totalSpeed+=$11
}

# find best pokemon of each primary type
/^[0-9]/ {
	if (pokemonTypes[$3] == "") {
		pokemonTypes[$3]=$2","$5
	} else {
		split(pokemonTypes[$3], splitArr, ",")
		if ($5 > splitArr[2]) {
			pokemonTypes[$3]=$2","$5
		}
	}
}

# find average stats of each type
/^[0-9]/ {
	if (averageForType[$3] == "") {
		averageForType[$3] = $5",1"
	} else {
		split(averageForType[$3], splitArr, ",")
		averageForType[$3] = splitArr[1] + $5 "," splitArr[2] + 1
	}
}

# find worst pokemon overall
/^[0-9]/ {
	if (lowestTotal == -1) {
		lowestTotal=$5
		worstPokemon=$2
	}
	if ($5 < lowestTotal) {
		lowestTotal=$5;
		worstPokemon=$2;
	} else if ($5 == highestTotal) {
		worstPokemon=worstPokemon "\n\t" $2
	}
}

function getLongestKeyLen(arr) {
	longest=0
	for (i in arr) {
		if (length(i) > longest)
			longest=length(i)
	}
	return longest
}

function normalizeSpaces(curVal, longestVal) {
	spaces=""
	for (i=length(curVal); i<longestVal; ++i) {
		spaces=spaces" "
	}
	return spaces
}

END {
	# most powerful overall
	print "the overall most powerful Pokemon, with a total score of " highestTotal " is/are:\n\t" bestPokemon;

	# least powerful overall
	print "the overall least powerful pokemon, with a total score of " lowestTotal " is/are:\n\t" worstPokemon;

	# overall averages
	print "overall averages:  "
	printf "\ttotal:           %.2f\n", (totalTotal / totalRows)
	printf "\tHP:              %.2f\n", (totalHP / totalRows)
	printf "\tattack:          %.2f\n", (totalAtk / totalRows)
	printf "\tdefense:         %.2f\n", (totalDef / totalRows)
	printf "\tspecial attack:  %.2f\n", (totalSPAtk / totalRows)
	printf "\tspecial defense: %.2f\n", (totalSPDef / totalRows)
	printf "\tspeed:           %.2f\n", (totalSpeed / totalRows)

	# best pokemon of each type
	longestKeyLen=getLongestKeyLen(pokemonTypes)
	print "best pokemon by type: "
	for (i in pokemonTypes) {
		split(pokemonTypes[i], splitArr, ",")
		printf "\t" i ":%s %s (%s)\n", normalizeSpaces(i, longestKeyLen), splitArr[1], splitArr[2]
	}

	# average stats of each type
	longestKeyLen=getLongestKeyLen(averageForType)
	print "average stats of each type:"
	for (i in averageForType) {
		split(averageForType[i], splitArr, ",")
		printf "\t" i ":%s %.2f\n", normalizeSpaces(i, longestKeyLen), splitArr[1] / splitArr[2]
	}
}

# vim: syntax=awk
