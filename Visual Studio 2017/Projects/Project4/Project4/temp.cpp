#include <stdio.h>
#include <fstream>
#include <string>

using namespace std;

fstream in, out;

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	string t = "--------------------------------------------------------------------------------";
	string I;
	int c = 0;
	bool f = false;
	while (in >> I) {
		if (I == "<br>") {
			out << endl;
			c = 0;
			f = true;
		}
		else if (I == "<hr>") {
			if (c == 0) {
				out << t << endl;
			}
			else {
				c = 0;
				f = true;
				out << endl << t << endl;
			}
		}
		else {
			int s = I.size();
			if (c == 0) {
				c = s;
				out << I;
				f = true;
			}
			else if (c + s + 1 <= 80) {
				if (f) {
					out << " ";
					c += 1;
				}
				c += s;
				out << I;
				if (c == 80) {
					out << endl;
					c = 0;
					f = false;
				}
			}
			else {
				c = s;
				f = true;
				out << endl << I;
			}
		}
	}
	return 0;
}