// HangMan.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdexcept>
#include "HangManGame.hpp"
#include "HangManDrawer.hpp"

int main(int argc, char* argv[])
{

  auto wordToGuess = HangManDrawer::AskForWord();
  HangManGame game{ wordToGuess, 6 };
  while (game.GetHangManState() < 6)
  {
    try
    {
      auto letter = HangManDrawer::AskForLetter();
      game.AddLetter(letter);
      std::system("cls");
      HangManDrawer::DrawGame(game);
    }
    catch (const std::exception& e)
    {
      std::cout << e.what() << std::endl;
    }
  }

  if (game.CheckIfWon())
    std::cout << "YOU WON :)" << std::endl;
  else
    std::cout << "YOU LOST :(" << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
