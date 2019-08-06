#ifndef UTILS_STRING_H
#define UTILS_STRING_H

#include "data_geometry.h"

#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

string trim(string s) {
	if (s.empty()) {
		return s;
	}
	s.erase(0, s.find_first_not_of(" "));
	s.erase(s.find_last_not_of(" ") + 1);
	return s;
}

string parseDoubleToString(double d) {
	stringstream ss;
	string result;

	ss << fixed << setprecision(6) << d;
	ss >> result;

	return result;
}

string parseIntegerToString(int i) {
	stringstream ss;
	string result;

	ss << i;
	ss >> result;

	return result;
}

double parseStringToDouble(string s) {
	s = trim(s);
	return atof(s.c_str());
}

int parseStringToInteger(string s) {
	s = trim(s);
	return atoi(s.c_str());
}

Point parseStringToPoint(string s) {

	string data[3];

	int p = s.find(" ");
	data[0] = s.substr(0, p);
	s = s.substr(p + 1);
	p = s.find(" ");
	data[1] = s.substr(0, p);
	data[2] = s.substr(p + 1);

	return Point(atof(data[0].c_str()), atof(data[1].c_str()), atof(data[2].c_str()));
}

// 输入格式为：   1,   x,  y,  z
Point parseStringToPoint2(string s) {
	string data[3];
	s = trim(s);

	// 去除索引号
	s = s.substr(s.find(" "));
	s = trim(s);

	// 取第一位坐标
	data[0] = trim(s.substr(0, s.find(",")));
	s = s.substr(s.find(",") + 1);
	s = trim(s);
	// 取第二位坐标
	data[1] = trim(s.substr(0, s.find(",")));
	s = s.substr(s.find(",") + 1);
	// 取第三位坐标
	data[2] = trim(s);

	return Point(atof(data[0].c_str()), atof(data[1].c_str()), atof(data[2].c_str()));
}

Point parseStringToPoint3(string s) {
	string data[3];
	s = trim(s);

	//    printf("%s", s.c_str());

		// 去除索引号
	s = s.substr(s.find(",") + 1);
	s = trim(s);

	// 取第一位坐标
	data[0] = trim(s.substr(0, s.find(",")));
	//    printf("%s\n", data[0].c_str());
	s = s.substr(s.find(",") + 1);
	s = trim(s);
	// 取第二位坐标
	data[1] = trim(s.substr(0, s.find(",")));
	s = s.substr(s.find(",") + 1);

	// 取第三位坐标
	data[2] = trim(s);

	//    printf("%s, %s, %s\n",data[0].c_str(), data[1].c_str(), data[2].c_str());
	//    printf("%lf, %lf, %lf\n",atof("0.000000"), atof("0.008340"), atof("0.004310"));
	//    printf("%lf, %lf, %lf\n",atof(data[0].c_str()), atof(data[1].c_str()), atof(data[2].c_str()));
	//    printf("%lf, %lf, %lf\n",parseStringToDouble(data[0].c_str()), parseStringToDouble(data[1].c_str()), parseStringToDouble(data[2].c_str()));


	return Point(atof(data[0].c_str()), atof(data[1].c_str()), atof(data[2].c_str()));
}

// 输入格式为：   1,   a, b, c
Facet parseStringToFacet(string s) {
	string data[3];
	s = trim(s);

	// 去除索引号
	s = s.substr(s.find(" "));
	s = trim(s);

	// 取第一位坐标
	data[0] = trim(s.substr(0, s.find(",")));
	s = s.substr(s.find(",") + 1);
	s = trim(s);
	// 取第二位坐标
	data[1] = trim(s.substr(0, s.find(",")));
	s = s.substr(s.find(",") + 1);
	// 取第三位坐标
	data[2] = trim(s);

	return Facet(atoi(data[0].c_str()), atoi(data[1].c_str()), atoi(data[2].c_str()));
}

// 将索引对转换顺序：x, y ---> y, x
string invertOrder(string s) {
	string data[2];
	data[0] = s.substr(0, s.find(","));
	data[1] = s.substr(s.find(",") + 1);

	return trim(data[1]) + ", " + trim(data[0]);
}

// 判断大小，并交换顺序
// 输入x, y：若 x > y，则输出 y, x
string judgeAndInvertOrder(string s) {
	s = trim(s);
	double data[2];
	data[0] = parseStringToDouble(s.substr(0, s.find(",")));
	data[1] = parseStringToDouble(s.substr(s.find(",") + 1));

	if (data[0] > data[1]) {
		return parseDoubleToString(data[1]) + ", " + parseDoubleToString(data[0]);
	}

	return s;
}

string replaceAll(string src, string from, string to) {
	int pos = 0;
	int fromLen = from.size();
	int toLen = to.size();

	while ((pos = src.find(from, pos)) != (int)string::npos) {
		src.replace(pos, fromLen, to);
		pos += toLen;
	}
	return src;
}

#endif // FILEUTILS_H
