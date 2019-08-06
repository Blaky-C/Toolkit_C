#ifndef UTILS_FILES_H
#define UTILS_FILES_H

#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

ofstream outputFile;
ifstream inputFile;

void openInputFile(string absolutePath) {	
	// open ifstream path
	ifstream inputFile(absolutePath, ios::in);
}

string readLineFromInput() {
	// read every line from the input file

	string line;// 用来存放读取文件的每一行内容
	getline(inputFile, line);

	return line;
}

void closeInputFile() {
	// close ifstream path
	inputFile.close();
}

void openOutputFile(string absolutePath) {
	// open ofstream path
	outputFile = ofstream(absolutePath);
}

void closeOutputFile() {
	// close ofstream path
	outputFile.close();
}

void writeIntoOutput(string m) {
	// write into output file
	outputFile << m;
}

#endif // UTILS_FILES_H
