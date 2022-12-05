#include "day5.h"
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
#include <regex>

void part1(std::vector<std::vector<char>> box, std::vector<std::pair<int, std::pair<int, int>>> moves);
int day5c() {
  std::ifstream input("test.txt");
  std::vector<std::string> instr;

  if (input.fail()) std::cout << "failed input" << std::endl;
  else {
	std::string buffer;
	while (std::getline(input, buffer) && buffer[1] != '1') {
	  //std::cout << buffer << std::endl;
	  instr.push_back(buffer);
	}
	/*for (auto &temp : instr) {
	  std::cout << temp << std::endl;
	}*/
	std::vector<std::vector<char>> box(buffer.size() / 4 + 1);
	for (int i = instr.size() - 1; i >= 0; i--) {
	  for (int j = 0; j < box.size(); j++) {
		int temp = j * 4 + 1;
		if (instr[i][temp] == ' ') continue;
		box[j].push_back(instr[i][temp]);
		//std::cout << instr[i][temp] << std::endl;
	  }
	}
	std::getline(input, buffer);
	std::vector<std::pair<int, std::pair<int, int>>> moves;
	while (std::getline(input, buffer)) {
	  int test, test2, test3 = 0;
	  std::pair<int, std::pair<int, int>> temp;
	  sscanf_s(buffer.c_str(), "move %d from %d to %d", &temp.first, &temp.second.first, &temp.second.second);
	  moves.push_back(temp);
	}
	part1(box, moves);
  }
  return 0;
}
void part1(std::vector<std::vector<char>> box, std::vector<std::pair<int, std::pair<int, int>>> moves) {
  for (auto &t : moves) {
	std::cout << t.first << " " << std::endl;

	for (int i = 0; i < t.first; i++) {
	  auto d = box[t.second.first].back();
	  std::cout << d << std::endl;
	  std::cout << box[t.second.first].back() << std::endl;
	  box[t.second.first].pop_back();
	  std::cout << box[t.second.first].back()  << std::endl;
	  std::cout << box[t.second.second].back()<<std::endl;
	  box[t.second.second].push_back(d);
	  std::cout << "test" << std::endl;

	}
  }

  for (const auto t : box) {
	if (!t.empty()) {
	  std::cout << t.front();
	} else {
	  std::cout << ' ';
	}
  }
  std::cout << std::endl;
}
