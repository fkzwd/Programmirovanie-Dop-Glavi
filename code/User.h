#pragma once
#include <iostream>
#include <string>
#include <vector>

namespace User {

	bool isNumber(std::string);

	int getInt() {
		std::string s;
		std::cin >> s;
		if (!isNumber(s)) return 0;
		return std::stoi(s);
	}

	int* getInts(int size) {
		std::string s;
		std::vector<std::string> strings;
		for (int i = 0; i < size; i++) {
			std::cin >> s;
			if (!isNumber(s)) strings.push_back("0");
			else strings.push_back(s);
		}
		int* numbers = new int[size];
		for (int i = 0; i < size; i++) {
			numbers[i] = stoi(strings[i]);
		}
		return numbers;
	}

	bool isNumber(std::string s) {
		unsigned int i = 0;
		while (i < s.size()) {
			if (!isdigit(s[i])) return false;
			i++;
		}
		return true;
	}
}
