//
// Created by 12001732 on 2/12/2022.
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

int part2(std::vector<std::pair<char, char>> vector_1);
int day2c() {
  std::vector<std::pair<char, char>> instructions;
  std::ifstream input("test.txt");
  if (input.fail()) std::cout << "Failed to open file";
  else {

	while (input.peek() != EOF) {
	  std::pair<char, char> instruction;
	  input >> instruction.first >> instruction.second;
	  instructions.push_back(instruction);
	}
	int zero = part1(instructions);
	zero = part2(instructions);

  }

  return 0;

}
int part2(std::vector<std::pair<char, char>> instructions) {
  int score = 0;

  for (auto &instruction : instructions) {
	if (instruction.second == 'Y') {
	  score = score + 3;
	  if (instruction.first == 'A') score = score + 1;
	  else if (instruction.first == 'B') score = score + 2;
	  else if (instruction.first == 'C') score = score + 3;
	} else if (instruction.second == 'Z') {
	  score = score + 6;
	  if (instruction.first == 'A') score = score + 2;
	  else if (instruction.first == 'B') score = score + 3;
	  else if (instruction.first == 'C') score = score + 1;
	} else if (instruction.second == 'X') {
	  if (instruction.first == 'A') score = score + 3;
	  else if (instruction.first == 'B') score = score + 1;
	  else if (instruction.first == 'C') score = score + 2;
	}
  }
  std::cout << score << std::endl;

  return 0;
}

int part1(std::vector<std::pair<char, char>> instructions) {
  int score = 0;
  for (auto &instruction : instructions) {
	if (instruction.second == 'Y') {
	  score = score + 2;
	} else if (instruction.second == 'X') {
	  score = score + 1;
	} else if (instruction.second == 'Z') {
	  score = score + 3;
	}
	if (instruction.first == instruction.second) score = score + 3;
	else if (instruction.first == 'A' && instruction.second == 'Y'
		|| instruction.first == 'C' && instruction.second == 'X'
		|| instruction.first == 'B' && instruction.second == 'Z')
	  score = score + 6;
	else if (instruction.first == 'C' && instruction.second == 'Z'
		|| instruction.first == 'B' && instruction.second == 'Y'
		|| instruction.first == 'A' && instruction.second == 'X')
	  score = score + 3;
  }
  std::cout << score << std::endl;

  return 0;
}