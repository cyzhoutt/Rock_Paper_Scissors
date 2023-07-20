#include <iostream>
#include <sstream>
#include <string>
#include <random>

std::string get_valid_string(const std::string& prompt) {
  std::string line;
  while (true) {
    std::cout << prompt;
    std::getline(std::cin, line); //grabs the entire line
    std::stringstream line2parse(line);
    std::string word;
    line2parse >> word;
    if (line2parse) { //if I was able to read the number
      std::string what_is_left;
      line2parse >> what_is_left;
      if (not line2parse) { //if there is nothing left we will fail to read it
        return word;
      }
    }
  }
}

std::string fRPS(std::string RPS){
  do{
    RPS = get_valid_string("Enter (R)ock, (P)aper, or (S)cissors for your move: ");
    for (char& RPSC:RPS){
      if (isalpha(RPSC)){
        RPSC = tolower(RPSC);
      }
    }
  }while(!(RPS == "r" or RPS=="(r)ock" or RPS == "rock" or RPS == "p" or RPS =="(p)aper" or RPS == "paper" or RPS == "s" or RPS == "(s)cissors" or RPS == "scissors"));
  return RPS;
}

bool playerWin(int player, int AI) {
  if (abs(player - AI) == 1){
    return player > AI;
  }
  else if (abs(player - AI) == 2){
    return player < AI;
  }else{ //==
    return false;
  }
}


std::string fYON(std::string YON){
  do{
    YON = get_valid_string("Would you like to replay the game?\nEnter (Y)es or (N)o: ");
    for (char& RPSC:YON){
      if (isalpha(RPSC)){
        RPSC = tolower(RPSC);
      }
    }
  }while(!(YON == "y" or YON == "(y)es" or YON == "yes" or YON == "n" or YON == "(n)o" or YON == "no"));
  return YON;
}

/*
for (char& RPSC:RPS){
  if (isalpha(RPSC)){
    RPSC = tolower(RPSC);
  }
}
*/

//int seed = std::stoi(argv[1]);

int minstd_get_random_int(int min, int max, std::minstd_rand& generator) {
  std::uniform_int_distribution<int> dist(min, max);
  int random_num = dist(generator);
  return random_num;
}

//int generateRandomAI(int seed) {
//  std::minstd_rand generator(seed);
//  int AI;
//  AI = minstd_get_random_int(0, 2, generator);
//  return AI;
//}

int changePlayerInput2Num(std::string playerInput){
  if (playerInput == "r" or playerInput=="(r)ock" or playerInput == "rock") {
    return 0;
  } else if (playerInput == "p" or playerInput=="(p)aper" or playerInput == "paper") {
    return 1;
  } else {
    return 2;
  }
}

std::string aiInput(int AI){
  if (AI == 0) {
    return "rock";
  } else if (AI == 1) {
    return "paper";
  } else {
    return "scissors";
  }
}


