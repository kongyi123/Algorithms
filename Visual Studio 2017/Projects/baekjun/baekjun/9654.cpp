#include <stdio.h>

int main(void) {
	fprintf(stdout, "SHIP NAME      CLASS          DEPLOYMENT IN SERVICE\n");
	fprintf(stdout, "N2 Bomber      Heavy Fighter  Limited    21        \n");
	fprintf(stdout, "J-Type 327     Light Combat   Unlimited  1         \n");
	fprintf(stdout, "NX Cruiser     Medium Fighter Limited    18        \n");
	fprintf(stdout, "N1 Starfighter Medium Fighter Unlimited  25        \n");
	fprintf(stdout, "Royal Cruiser  Light Combat   Limited    4         \n");

	return 0;
}