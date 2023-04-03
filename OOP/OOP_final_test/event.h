#include <iostream>
#include<string>
#include<ctime>
using namespace std;

class event {
private:
	string Event[12][32][10];
public:

	void add_event(time_t mon,time_t day,int i);
	bool check_event(time_t mon, time_t day);
	void printf_event(time_t mon, time_t day, int i);
	bool find_event(string key_word);
};

void event::add_event(time_t mon, time_t day,int i) {
	cin >> Event[mon][day][i];
}
bool event::check_event(time_t mon, time_t day) {
	if (Event[mon][day][0] == "")return 1;
	else return 0;
}
void event::printf_event(time_t mon, time_t day, int i) {
	for (size_t i_1 = 0; i_1 < i; i_1++)cout << i_1 + 1 << "." << Event[mon][day][i_1] << endl;
}
bool event::find_event(string key_word) {
	int flag = 0;
	for (size_t i0 = 0; i0 < 12; i0++) {
		for (size_t i1 = 0; i1 < 32; i1++) {
			for (size_t i2 = 0; i2 < 10; i2++) {
				if (Event[i0][i1][i2].find(key_word) == string::npos);
				else {
					cout << i0 + 1 << "ค๋" << i1 << "ค้" << Event[i0][i1][i2] << endl;
					flag = 1;
				}
			}
		}
	}
	cout << "\n\n";
	return flag;
}
