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
		if (st_time.at(3) > '5') { // 60���� �Ѿ��
			st_time.at(1) += 1; // �ð����� �Ѱ���
			st_time.at(3) -= 6;
			if (st_time.at(1) > '9') { // �ð��� ���ڸ���
				st_time.at(0) += 1;
				st_time.at(1) -= 10;
			}
		}
	}

	st_time.at(3) += (t / 10);
	if (st_time.at(3) > '5') { // 60���� �Ѿ��
		st_time.at(1) += 1; // �ð����� �Ѱ���
		st_time.at(3) -= 6;
		if (st_time.at(1) > '9') { // �ð��� ���ڸ���
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
	n--; // ù��° ����
	for (int i = 0;i < timetable.size();i ++) {
		if (st_time.compare(timetable.at(i)) >= 0) { // �ð� �ȿ� ����
			if (cnt < m) { // �¿� �� ������ �¿��.
				cnt++;
				continue;
			}
			else if (n > 0) { // �� á�ٸ�, �׸��� ������ ���� �ִٸ�
				// ���� ������ ������ ���� ������ ����
				cnt = 0; // ���� �ο� ����.
				st_time = time_proc(st_time, t); // ���� ���� �ð����� ����
				n--;
				i--;
			}
			else { // ���� ������ ���ٸ�
				pivot = i;
				type = 1;
				break;
			}
		}
		else if (n > 0) { // �ð��ȿ� ���� ����� ���� ��� ���� ����
			cnt = 0; // ���� �ο� ����.
			st_time = time_proc(st_time, t); // ���� ���� �ð����� ����
			n--;
			i--;
		}
	}

	if (type == 1) { // ���� ������ ���� ���
		if (cnt < m) {
			answer = st_time;
		}
		else {
			answer = btime_proc(timetable.at(pivot - 1)); // ���������� ź ������� 1�� �����ɷ�
		}
	}
	else {
		if (cnt < m) {
			answer = st_time;
		}
		else { // ���� �ڸ��� �ȳ��� ���
			if (pivot == -1) pivot = timetable.size();
			answer = btime_proc(timetable.at(pivot - 1)); // ���������� ź ������� 1�� �����ɷ�
		}
		
	}
	

	// pivot�� �ش��ϴ� ������� ���¿��.


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