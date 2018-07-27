#include <string>
#include <vector>
#include <conio.h>

using namespace std;

typedef struct node {
	int year;
	int month;
	int day;
	int hour;
	int min;
	int sec;	// ms
	int during; // ms
} node;


int solution(vector<string> lines) {
	int answer = 0;
	node data[2100];

	for (int i = 0;i < lines.size();i++) {
		data[i].year = atoi(lines.at(i).substr(0, 4).c_str());
		data[i].month = atoi(lines.at(i).substr(5, 7).c_str());
		data[i].day = atoi(lines.at(i).substr(8, 10).c_str());
		data[i].hour = atoi(lines.at(i).substr(11, 13).c_str());
		data[i].min = atoi(lines.at(i).substr(14, 16).c_str());
		data[i].sec = (int)(atof(lines.at(i).substr(17, 23).c_str()) * 1000);
		data[i].during = (int)(atof(lines.at(i).substr(24, lines.at(i).size()).c_str()) * 1000);
	}

	for (int i = 0;i < lines.size();i++) {
		int cnt = 1;
		for (int j = 0;j < lines.size();j++) {
			if (i == j) continue;
			node temp2;

			temp2.hour = data[i].hour;
			temp2.min = data[i].min;
			temp2.sec = data[i].sec;
			
			temp2.sec += data[i].during;
			if (temp2.sec > 60000) {
				temp2.sec -= 60000;
				temp2.min += 1;
				if (temp2.min > 60) {
					temp2.min -= 60;
					temp2.hour += 1;
				}
			}

			node temp;

			temp.hour = temp2.hour;
			temp.min = temp2.min;
			temp.sec = temp2.sec;

			temp.sec += 1000;
			if (temp.sec > 60000) {
				temp.sec -= 60000;
				temp.min += 1;
				if (temp.min > 60) {
					temp.min -= 60;
					temp.hour += 1;
				}
			}

			int er = 0;
			if (temp2.hour > data[j].hour) er = 1;
			else if (temp2.min > data[j].min) er = 1;
			else if (temp2.sec > data[j].sec) er = 1;

			if (data[j].hour > temp.hour) er = 1;
			else if (data[j].min > temp.min) er = 1;
			else if (data[j].sec > temp.sec) er = 1;

			if (er == 0) cnt++;
		}

		if (answer < cnt) answer = cnt;
	}

	return answer;
}


int main(void) {
	vector<string> board;
	board.push_back("2016-09-15 01:00:04.002 2.0s");
	board.push_back("2016-09-15 01:00:07.000 2s");	

	fprintf(stdout, "%d", solution(board));
	_getch();
	return 0;
}