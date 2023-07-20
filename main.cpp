//#include <iostream>
//#include <string>

#include "rps.h"

int main(int argc, char** argv) {
  std::string RPS = " ";
  int player = -1;
  int AI = -1;
  std::string will =" ";
  //parse argument to seed
  int seed;
  std::string YON = " ";

  if (argc == 1) {
    seed = time(nullptr);
  } else if (argc == 2) {
    seed = std::stoi(argv[1]);
  } else {
    std::cout << "Invalid Arguments" << std::endl;
    return 1;
  }

  std::minstd_rand generator(seed);
  do{
    do {
      std::string playerInput = fRPS(RPS);
      //std::cout << std::endl;
      player = changePlayerInput2Num(playerInput);
      AI = minstd_get_random_int(0, 2, generator);
      if (playerWin(player, AI)) {
        std::cout << "The ai played " << aiInput(AI) << "." << std::endl;
        std::cout << "You win!" << std::endl;
        break;
      } else if (!playerWin(player, AI) && player != AI) {
        std::cout << "The ai played " << aiInput(AI) << "." << std::endl;
        std::cout << "The AI wins :(" << std::endl;
        break;
      } else {
        std::cout << "The ai played " << aiInput(AI) << "." << std::endl;
        std::cout << "You and the AI both played " << aiInput(AI) << "." << std::endl;
        std::cout << "Keep playing until someone wins." << std::endl;
      }
    }while (true);
    will = fYON(YON);    //get the user input
    //std::cout << std::endl;
  }while(will == "y" or will == "yes" or will == "(y)es");

  return 0;
}
