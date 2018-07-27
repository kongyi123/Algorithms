#include <string>
#include <vector>
#include <conio.h>

using namespace std;

vector<string> sort(vector<string> data) {
	for (int i = 0;i < data.size();i++) {
		for (int j = i + 1;j < data.size();j++) {
			if (data.at(i).compare(data.at(j)) > 0) {
				string temp = data.at(i);
				data.at(i) = data.at(j);
				data.at(j) = temp;
			}
		}
	}

	return data;
}

string time_proc(string st_time, int t) {
	st_time.at(4) += (t % 10);
	if (st_time.at(4) > '9') { //
		st_time.at(3) += 1;
		st_time.at(4) -= 10;
		if (st_time.at(3) > '5') { // 60분이 넘어가면
			st_time.at(1) += 1; // 시간으로 넘겨줌
			st_time.at(3) -= 6;
			if (st_time.at(1) > '9') { // 시간도 두자리수
				st_time.at(0) += 1;
				st_time.at(1) -= 10;
			}
		}
	}

	st_time.at(3) += (t / 10);
	if (st_time.at(3) > '5') { // 60분이 넘어가면
		st_time.at(1) += 1; // 시간으로 넘겨줌
		st_time.at(3) -= 6;
		if (st_time.at(1) > '9') { // 시간도 두자리수
			st_time.at(0) += 1;
			st_time.at(1) -= 10;
		}
	}


	return st_time;
}

string btime_proc(string st_time) {
	st_time.at(4) -= 1;
	if (st_time.at(4) < '0') {
		st_time.at(4) += 10;
		st_time.at(3) -= 1;
		if (st_time.at(3) < '0') {
			st_time.at(3) += 6;
			st_time.at(1) -= 1;
			if (st_time.at(1) < '0') {
				st_time.at(1) += 10;
				st_time.at(0) -= 1;
			}
		}
	}


	return st_time;
}

string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";
	timetable = sort(timetable);
	string st_time = "09:00";
	int cnt = 0;
	int pivot = -1;
	int type = 0;
	n--; // 첫번째 버스
	for (int i = 0;i < timetable.size();i ++) {
		if (st_time.compare(timetable.at(i)) >= 0) { // 시간 안에 들어가면
			if (cnt < m) { // 태울 수 있으면 태운다.
				cnt++;
				continue;
			}
			else if (n > 0) { // 꽉 찼다면, 그리고 버스가 남아 있다면
				// 다음 버스가 있으면 다음 버스로 변경
				cnt = 0; // 버스 인원 비운다.
				st_time = time_proc(st_time, t); // 다음 버스 시간으로 변경
				n--;
				i--;
			}
			else { // 남은 버스가 없다면
				pivot = i;
				type = 1;
				break;
			}
		}
		else if (n > 0) { // 시간안에 들어가는 사람이 없는 경우 다음 버스
			cnt = 0; // 버스 인원 비운다.
			st_time = time_proc(st_time, t); // 다음 버스 시간으로 변경
			n--;
			i--;
		}
	}

	if (type == 1) { // 다음 버스가 없는 경우
		if (cnt < m) {
			answer = st_time;
		}
		else {
			answer = btime_proc(timetable.at(pivot - 1)); // 마지막으로 탄 사람보다 1분 빠른걸로
		}
	}
	else {
		if (cnt < m) {
			answer = st_time;
		}
		else { // 버스 자리가 안남은 경우
			if (pivot == -1) pivot = timetable.size();
			answer = btime_proc(timetable.at(pivot - 1)); // 마지막으로 탄 사람보다 1분 빠른걸로
		}
		
	}
	

	// pivot에 해당하는 사람부터 못태운다.


	return answer;
}

int main(void) {
	vector<string> cities;
	cities.push_back("09:00");
	cities.push_back("09:00");
	cities.push_back("09:00");
	cities.push_back("09:00");

	
	string result = solution(2, 1, 2, cities);
	_getch();
	return 0;
}