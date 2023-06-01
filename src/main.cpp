#include <iostream>
#include <vector>
#include <random>
#include "popl.hpp"

// this and randInt() are shamelessly taken from StackOverflow
std::random_device rd;     // Only used once to initialise (seed) engine
// returns a random integer between min (inclusive) and max (exclusive)
int randInt(int min, int max) {
  std::mt19937 rng(rd());    // Random-number engine used (Mersenne-Twister in this case)
  std::uniform_int_distribution<int> uni(min,max-1); // Guaranteed unbiased
  return uni(rng);
}

// generates a set containing each number from 0 to (n - 1), in a randomized order
std::vector<int> generateRandomData(int n) {
  std::vector<int> orderedSet{};
  for (int i{0}; i < n; ++i) {
    orderedSet.push_back(i);
  }

  std::vector<int> randomSet{};
  while (orderedSet.size() > 0) {
    size_t index = randInt(0, static_cast<int>(orderedSet.size()));
    randomSet.push_back(orderedSet[index]);
    orderedSet.erase(orderedSet.begin() + index);
  }
  return randomSet;
}

int main(int argc, char **argv) {
  bool printHelp, printVersion, verbose, timer;
  int dataSize;

  // parse command-line args with popl
  popl::OptionParser op("Allowed Options");
  op.add<popl::Switch>("h", "help", "produce help message", &printHelp);
  op.add<popl::Switch>("", "version", "prints the version number", &printVersion);
  op.add<popl::Switch>("v", "verbose", "prints extra information while sorting", &verbose);
  op.add<popl::Value<int> >("s", "size", "sets the number of items in the dataset", 10, &dataSize);

  op.parse(argc, argv);

  if (printHelp) {
    std::cout << op << '\n';
    return 0;
  }
  if (printVersion) {
    std::cout << "Bad Sorts v0.0.1\nCopyright (c) 2023 Joe Williams\nMIT License\nThis is free software: you are free to change and redistribute it.\nThere is NO WARRANTY, to the extent permitted by law.\n";
    return 0;
  }

  std::vector<int> dataset = generateRandomData(dataSize);
}