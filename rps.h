#ifndef RPS_H
#define RPS_H
  #include <iostream>
  #include <sstream>
  #include <string>
  #include <random>

std::string get_valid_string(const std::string& prompt);
std::string fRPS(std::string RPS);
bool playerWin(int player, int AI);
std::string fYON(std::string YON);
int minstd_get_random_int(int min, int max, std::minstd_rand& generator);
int generateRandomAI(int seed);
//void runRandomExamples(int seed);
int changePlayerInput2Num(std::string playerInput);
std::string aiInput(int AI);

#endif