#ifndef PMERGEME_H
#define PMERGEME_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <sstream>
#include <ctime>

void parseArg(char *argv[]);
void checkArg(char *argv[]);
void printUnsorted();
void printSorted();
void printTimeTaken();
void sortArg(std::string container_type);

#endif