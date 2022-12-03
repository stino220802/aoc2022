#include "day3.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <string_view>
#include <array>

void part1(std::vector<std::pair<std::string, std::string>> vector_1);
void part2(std::vector<std::pair<std::string, std::string>> vector_1);
int day3c() {

  std::vector<std::pair<std::string, std::string>> rucksack;
  std::vector<std::pair<std::string, std::string>> rucksack2;
  std::ifstream input("test.txt");
  if (input.fail()) std::cout << "Failed to open file";
  else {
	while (input.peek() != EOF) {
	  std::pair<std::string, std::string> split;
	  std::string instruction;
	  input >> instruction;
	  split.first = instruction.substr(0, instruction.length() / 2);
	  split.second = instruction.substr(instruction.length() / 2);
	  rucksack.emplace_back(split);
	  rucksack2.emplace_back(instruction, "0");
	}

  }
  part1(rucksack);
  part2(rucksack2);
}

void part2(std::vector<std::pair<std::string, std::string>> vector_1) {

  char te;
  auto sum = std::vector<char>{};
  for (int j = 0; j < vector_1.size(); j += 3) {

	for (int i = 0; i < vector_1[j].first.size(); i++) {
	  for (int x = 0; x < vector_1[j + 1].first.size(); x++) {
		for (int y = 0; y < vector_1[j + 2].first.size(); y++) {
		  if (j != vector_1.size()) {
			if (vector_1[j].first[i] == vector_1[j + 1].first[x] && vector_1[j].first[i] == vector_1[j + 2].first[y]
				&& vector_1[j + 1].first[x] == vector_1[j + 2].first[y]) {
			  te = vector_1[j].first[i];
			}
		  }
		}
	  }
	}
	sum.emplace_back(te);
  }
  int c = 0;
  char letters[27] = "abcdefghijklmnopqrstuvwxyz";
  char uletters[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for (auto &t : sum) {
	for (int count = 0; count <= 27; ++count) {
	  if (t == letters[count]) {
		c += count + 1;
	  } else if (t == uletters[count]) {
		c += count + 1 + 26;
	  }
	}
  }
  std::cout << c << std::endl;
}

void part1(std::vector<std::pair<std::string, std::string>> vector_1) {
  auto sum = std::vector<char>{};
  for (auto &rucksack : vector_1) {
	char temp;
	for (int i = 0; i < rucksack.first.size(); i++) {
	  for (int j = 0; j < rucksack.first.size(); j++) {
		if (rucksack.first[i] == rucksack.second[j]) {
		  temp = rucksack.first[i];
		}
	  }
	}
	sum.emplace_back(temp);
  }
  int c = 0;
  char letters[27] = "abcdefghijklmnopqrstuvwxyz";
  char uletters[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for (auto &t : sum) {
	for (int count = 0; count <= 27; ++count) {
	  if (t == letters[count]) {
		c += count + 1;
	  } else if (t == uletters[count]) {
		c += count + 1 + 26;
	  }
	}
  }
  auto sum2 = sum;
  std::cout << c << std::endl;
}


