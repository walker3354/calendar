#include <iostream>
#include<string>
#include<ctime>
#include"weather.h"
#include"event.h"
using namespace std;

int main()
{

	//feels_like_temperature
	bool* temperature_scale = new bool;
	double* main_humidity = new double;
	double* main_temperature = new double;
	string temperature_scale℉℃[2] = { "℉" ,"℃" };
	weather test;
	int weather_chose;

	//calender
	int calender_chose;
	time_t variable1 = time(NULL);
	struct tm* calender_day;
	int Event_i[12][32] = { 0 };
	string find_event;
	size_t find_event_temp_i;

	//Event
	event test_1;
	bool* things_to_do_chose = new bool;
	bool* thiings_to_do_a = new bool;
	int* things_to_do_chose_add = new int;

	goto feels_temperature;
feels_temperature:
	{
		cout << "請問要使用什麼溫標？\n\n0)攝氏℉　 1)華氏℃" << endl;
		cin >> *temperature_scale;
		test.set_temperature_scale(*temperature_scale);
		if (*temperature_scale == 0)cout << "已設定為攝氏℉\n" << endl;
		else cout << "已設定為華氏℃\n" << endl;

		cout << "輸入相對濕度(％)和溫度" << temperature_scale℉℃[*temperature_scale] << "\n\n相對濕度(％)：";
		cin >> *main_humidity;
		cout << "溫度" << temperature_scale℉℃[*temperature_scale] << "：";
		cin >> *main_temperature;
	temperature_value:
		{
			test.set_All_value(*main_humidity, *main_temperature);
			cout << "\n體感溫度為" << test.feels_like_temperature() << temperature_scale℉℃[*temperature_scale] << endl;
			cout << "\n小提醒：" << test.dectect() << endl;
		}
		cout << "\n0)將溫標轉換為" << temperature_scale℉℃[!*temperature_scale] << "　1)執行日曆" << "　２)結束程式" << "　3)重新執行" << endl;
		cin >> weather_chose;
		switch (weather_chose)
		{
		case 0:
			if (!*temperature_scale)test.F_tranform_C(*main_temperature);
			else test.C_tranform_F(*main_temperature);
			*temperature_scale = !*temperature_scale;
			test.set_temperature_scale(*temperature_scale);
			goto temperature_value;
			break;
		case 1:
			goto calender;
			break;
		case 2:
			cout << "再會!" << endl;
			return 0;
			break;
		case 3:
			goto feels_temperature;
			break;
		default:
			cout << "錯誤" << endl;
			return 0;
			break;
		}
	}
calender:
	{
		calender_day = localtime(&variable1);
		cout << "\n現在日期" << calender_day->tm_year + 1900 << "年" << calender_day->tm_mon + 1 << "月" <<
			calender_day->tm_mday << "日" << calender_day->tm_hour << "時" << calender_day->tm_min << "分\n" << endl;
		cout << "0)查看今日待辦事項　1)回到體感溫度　2)查看其他日期待辦事項　3)尋找事項　4)結束程式\n\n";
		cin >> calender_chose;

		switch (calender_chose)
		{
		case 0:
			goto things_to_do;
			break;
		case 1:
			goto feels_temperature;
			break;
		case 2:
			goto find_event;
			break;
		case 3:
			//
			cout << "輸入事件關鍵字" << endl;
			find_event_temp_i = 0;
			cin >> find_event;
			cout << "\n" << endl;
			if (!(test_1.find_event(find_event))) cout << "未找到，返回日曆統\n\n" << endl;
			find_event_temp_i = 0;
			goto calender;
			break;
		case 4:
			cout << "再會!" << endl;
			return 0;
			break;
		default:
			cout << "錯誤" << endl;
			return 0;
			break;
		}
	}
things_to_do:
	{
		if (test_1.check_event(calender_day->tm_mon,calender_day->tm_mday)) {
			cout << "本日未偵測到事項，是否要新增？\n\n0)否，回到日曆系統　1)是(最大新增數量10個)\n";
			cin >> *things_to_do_chose;
			if (!*things_to_do_chose) {
				goto calender;
			}
			else {
				goto add_event;
			add_event:
				{
					if (Event_i[calender_day->tm_mon][calender_day->tm_mday] == 10) {
						cout << "事件已達10個，回到日曆系統" << endl;
						goto things_to_do;
					}
					do {
						cout << "\n請輸入事件：" << endl;
						//
						cout << Event_i[calender_day->tm_mon][calender_day->tm_mday] + 1 << ".";
						test_1.add_event(calender_day->tm_mon, calender_day->tm_mday, Event_i[calender_day->tm_mon][calender_day->tm_mday]);
						Event_i[calender_day->tm_mon][calender_day->tm_mday] += 1;
						if (Event_i[calender_day->tm_mon][calender_day->tm_mday] == 10)break;
						cout << "\n\n0)結束新增　1)繼續新增\n";
						cin >> *thiings_to_do_a;
					} while (*thiings_to_do_a);
				}
				goto things_to_do;
			}
		}
		else {
			cout << "\n\n事項共有" << Event_i[calender_day->tm_mon][calender_day->tm_mday] << "項" << endl;
			test_1.printf_event(calender_day->tm_mon, calender_day->tm_mday, Event_i[calender_day->tm_mon][calender_day->tm_mday]);
			cout << "\n\n0)結束程式　1)回到日曆系統　2)查看其他日期待辦事項　3)新增事項\n";
			cin >> *things_to_do_chose_add;
			switch (*things_to_do_chose_add)
			{
			case 0:
				cout << "再會!" << endl;
				break;
			case 1:
				goto calender;
				break;
			case 2:
				goto find_event;
			find_event:
				{
					cout << "請輸入要查看的日期\n\n" << "月：";
					cin >> calender_day->tm_mon;
					calender_day->tm_mon = calender_day->tm_mon - 1;
					cout << "日：";
					cin >> calender_day->tm_mday;
					goto things_to_do;
				}
				break;
			case 3:
				goto add_event;
			default:
				cout << "錯誤" << endl;
				return 0;
				break;
			}
		}
	}
}
