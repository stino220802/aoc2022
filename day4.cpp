#include "day4.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <string_view>
#include <array>
#include <sstream>
#include <cstdio>

#include <cstdlib>

void part1(std::vector<std::pair<int, int>> vector1, std::vector<std::pair<int, int>> vector2);
void part2(std::vector<std::pair<int, int>> vector1, std::vector<std::pair<int, int>> vector2);
int day4c() {
  std::ifstream input("test.txt");
  std::vector<std::pair<int, int>> elf1, elf2;
  if (input.fail()) std::cout << "failed input" << std::endl;

  else {

	while (input.peek() != EOF) {

	  std::pair<int, int> telf1, telf2;
	  std::string buffer;
	  input >> buffer;
	  sscanf(buffer.c_str(), "%d - %d,%d - %d", &telf1.first, &telf1.second, &telf2.first, &telf2.second);
	  elf1.push_back(telf1);
	  elf2.push_back(telf2);

	}
	part1(elf1, elf2);
	part2(elf1, elf2);
  }

  return 0;
}
void part2(std::vector<std::pair<int, int>> vector1, std::vector<std::pair<int, int>> vector2) {
  int contained = 0;
  for (int i = 0; i < vector1.size(); i++) {
	if (vector1[i].first <= vector2[i].first && vector2[i].first <= vector1[i].second
		|| vector2[i].first <= vector1[i].first && vector1[i].first <= vector2[i].second) {
	  contained++;
	}
  }
  std::cout << contained << std::endl;
}
void part1(std::vector<std::pair<int, int>> vector1, std::vector<std::pair<int, int>> vector2) {
  int contained = 0;
  for (int i = 0; i < vector1.size(); i++) {
	if (vector1[i].first <= vector2[i].first && vector1[i].second >= vector2[i].second) {
	  contained++;
	} else if (vector1[i].first >= vector2[i].first && vector1[i].second <= vector2[i].second) {
	  contained++;
	}
  }
  std::cout << contained << std::endl;
}

