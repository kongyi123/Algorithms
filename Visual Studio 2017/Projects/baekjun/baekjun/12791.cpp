#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

char data[2020][60];
int y[2020];
int cnt;

int main(void) {
	y[++cnt] = 1967; strcpy(data[cnt], "DavidBowie");
	y[++cnt] = 1969; strcpy(data[cnt], "SpaceOddity");
	y[++cnt] = 1970; strcpy(data[cnt], "TheManWhoSoldTheWorld");
	y[++cnt] = 1971; strcpy(data[cnt], "HunkyDory");
	y[++cnt] = 1972; strcpy(data[cnt], "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars");
	y[++cnt] = 1973; strcpy(data[cnt], "AladdinSane");
	y[++cnt] = 1973; strcpy(data[cnt], "PinUps");
	y[++cnt] = 1974; strcpy(data[cnt], "DiamondDogs");
	y[++cnt] = 1975; strcpy(data[cnt], "YoungAmericans");
	y[++cnt] = 1976; strcpy(data[cnt], "StationToStation");
	y[++cnt] = 1977; strcpy(data[cnt], "Low");
	y[++cnt] = 1977; strcpy(data[cnt], "Heroes");
	y[++cnt] = 1979; strcpy(data[cnt], "Lodger");
	y[++cnt] = 1980; strcpy(data[cnt], "ScaryMonstersAndSuperCreeps");
	y[++cnt] = 1983; strcpy(data[cnt], "LetsDance");
	y[++cnt] = 1984; strcpy(data[cnt], "Tonight");
	y[++cnt] = 1987; strcpy(data[cnt], "NeverLetMeDown");
	y[++cnt] = 1993; strcpy(data[cnt], "BlackTieWhiteNoise");
	y[++cnt] = 1995; strcpy(data[cnt], "1.Outside");
	y[++cnt] = 1997; strcpy(data[cnt], "Earthling");
	y[++cnt] = 1999; strcpy(data[cnt], "Hours");
	y[++cnt] = 2002; strcpy(data[cnt], "Heathen");
	y[++cnt] = 2003; strcpy(data[cnt], "Reality");
	y[++cnt] = 2013; strcpy(data[cnt], "TheNextDay");
	y[++cnt] = 2016; strcpy(data[cnt], "BlackStar");


	int n;
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		int a, b;
		fscanf(stdin, "%d %d", &a, &b);
		int dcnt = 0;
		for (int j = 1;j <= cnt;j++) {
			if (y[j] >= a && y[j] <= b) dcnt++;
		}
		fprintf(stdout, "%d\n", dcnt);
		for (int j = 1;j <= cnt;j++) {
			if (y[j] >= a && y[j] <= b) {
				fprintf(stdout, "%d %s\n", y[j], data[j]);
			}
		}
	}
	return 0;
}