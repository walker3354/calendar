#include <iostream>
#include<string>
using namespace std;

class weather {
private:
	double humidity;
	double temperature;
	double temperature_scale;
	int feels_like_temperature_value;
	string hint;
public:
	weather() {
		double humidity = 1;
		double temperature = 1;
		double temperature_scale = 1;
		int feels_like_temperature_value = 1;
	}
	void set_temperature_scale(bool main_temperature_scale);
	//void set_humidity(double main_humidity);
	//void set_temperature(double main_temperature);
	void set_All_value(double main_humidity, double main_temperature);
	int feels_like_temperature();
	void C_tranform_F(double& temp);
	void F_tranform_C(double& temp);
	string dectect();
};


void weather::set_temperature_scale(bool main_temperature_scale) {
	temperature_scale = main_temperature_scale;
}
void weather::set_All_value(double main_humidity, double main_temperature) {
	humidity = main_humidity;
	temperature = main_temperature;
}
void weather::C_tranform_F(double& temp) {
	//set_temperature(temperature * 9 / 5 + 32);
	temp = temp * 9 / 5 + 32;
}
void weather::F_tranform_C(double& temp) {
	//set_temperature((temperature - 32) * 5 / 9);
	temp = (temp - 32) * 5 / 9;
}
int weather::feels_like_temperature() {
	if (!temperature_scale) {
		F_tranform_C(temperature);
		feels_like_temperature_value = (int)(1.07 * temperature) +
			(0.2 * ((humidity / 100) * 6.105 * 2.17 * ((17.2 * temperature) / (237.7 + temperature))))
			- (0.65 * 2.5) - 2.7 + 1;
		C_tranform_F(temperature);
		return feels_like_temperature_value * 9 / 5 + 32;
	}
	else feels_like_temperature_value = (int)(1.07 * temperature) +
		(0.2 * ((humidity / 100) * 6.105 * 2.17 * ((17.2 * temperature) / (237.7 + temperature))))
		- (0.65 * 2.5) - 2.7 + 1;
	return feels_like_temperature_value;
}
string weather::dectect() {
	hint = "";
	if (feels_like_temperature_value >= 18 && feels_like_temperature_value <= 25)hint.append("天氣舒適");
	else if (feels_like_temperature_value >= 16 && feels_like_temperature_value <= 17)hint.append("天氣微寒");
	else if (feels_like_temperature_value >= 11 && feels_like_temperature_value <= 15)hint.append("天氣寒冷，建議多家保暖衣物");
	else if (feels_like_temperature_value >= 0 && feels_like_temperature_value <= 10)hint.append("天氣極寒，請注意保暖");
	else if (feels_like_temperature_value < 0)hint.append("這甚麼鬼天氣");
	else if (feels_like_temperature_value >= 26 && feels_like_temperature_value <= 31)hint.append("天氣微熱");
	else if (feels_like_temperature_value >= 32 && feels_like_temperature_value <= 37)hint.append("氣候炎熱，請記得補充水份");
	else hint.append("你怎麼活下來的?");
	return hint;
}