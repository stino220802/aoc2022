//
// Created by 12001732 on 1/12/2022.
//
#include "day1.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <string_view>
#include <array>

int day1c() {
  std::string input = "test.txt";
  std::string line;
  std::fstream file(input);
  std::getline(file, line);
  int cur = std::stoi(line);
  int prev = cur;
  int highest = 0;
  auto CC = std::vector<int>{};
  while (std::getline(file, line)) {
	std::cout << line << std::endl;
	if (!line.empty()) {
	  prev = prev + std::stoi(line);
	  if (highest < prev) {
		highest = prev;
	  }
	  CC.emplace_back(prev);
	} else {
	  prev = 0;
	}
  }
  std::sort(CC.begin(), CC.end());
  auto sum = CC[CC.size() - 1] + CC[CC.size() - 2] + CC[CC.size() - 3];
  std::cout << highest << std::endl;
  std::cout << sum << std::endl;

  return 0;

}

