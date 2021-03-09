BEGIN {
	FS=",";

	highestTotal=0;
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

END {
	print "the overall most powerful Pokemon, with a total score of " highestTotal " is " bestPokemon;
	print "averages:"
	print "\ttotal score: " (totalTotal / totalRows)
	print "\tHP: " (totalHP / totalRows)
	print "\tattack: " (totalAtk / totalRows)
	print "\tdefense: " (totalDef / totalRows)
	print "\tspecial attack: " (totalSPAtk / totalRows)
	print "\tspecial defense: " (totalSPDef / totalRows)
	print "\tspeed: " (totalSpeed / totalRows)
}

# vim: syntax=awk
