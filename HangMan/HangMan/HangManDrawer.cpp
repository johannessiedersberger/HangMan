#pragma once
#include <string>
#include <iostream>
#include "HangManGame.hpp"
#include "HangManDrawer.hpp"
using namespace std;


void HangManDrawer::DrawGame(HangManGame game)
{
  PrintCurrentWordState(game);
  PrintLettersPicked(game);
  PrintHangMan(game.GetHangManState());
}

void HangManDrawer::PrintCurrentWordState(HangManGame game)
{
  cout << "Current Word State: ";
  for (size_t i = 0; i < game.GetCurrentWord().length(); i++)
  {
    cout << game.GetCurrentWord()[i] << " ";
  }
  cout << endl;
}

void HangManDrawer::PrintLettersPicked(HangManGame game)
{
  cout << "Letters Picked: ";
  for (size_t i = 0; i < game.GetLettersPicked().length(); i++)
  {
    cout << game.GetLettersPicked()[i] << " ";
  }
  cout << endl;
}

void HangManDrawer::PrintHangMan(int errors)
{
  switch (errors)
  {
  case 0:
    cout << "         " << endl;
    cout << "         " << endl;
    cout << "         " << endl;
    cout << "         " << endl;
    cout << "         " << endl;
    cout << "_____    " << endl;
    cout << endl;
    break;
  case 1:
    cout << "  ____   " << endl;
    cout << " |    |  " << endl;
    cout << " |       " << endl;
    cout << " |       " << endl;
    cout << " |       " << endl;
    cout << "_|___    " << endl;
    cout << endl;
    break;
  case 2:
    cout << "  ____   " << endl;
    cout << " |    |  " << endl;
    cout << " |    O  " << endl;
    cout << " |       " << endl;
    cout << " |       " << endl;
    cout << "_|___    " << endl;
    cout << endl;
    break;
  case 3:
    cout << "  ____   " << endl;
    cout << " |    |  " << endl;
    cout << " |   _O_ " << endl;
    cout << " |       " << endl;
    cout << " |       " << endl;
    cout << "_|___    " << endl;
    cout << endl;
    break;
  case 4:
    cout << "  ____   " << endl;
    cout << " |    |  " << endl;
    cout << " |   _O_ " << endl;
    cout << " |    |  " << endl;
    cout << " |       " << endl;
    cout << "_|___    " << endl;
    cout << endl;
    break;
  case 5:
    cout << "  ____   " << endl;
    cout << " |    |  " << endl;
    cout << " |   _O_ " << endl;
    cout << " |    |  " << endl;
    cout << " |   /   " << endl;
    cout << "_|___    " << endl;
    cout << endl;
    break;
  case 6:
    cout << "  ____   " << endl;
    cout << " |    |  " << endl;
    cout << " |   _O_ " << endl;
    cout << " |    |  " << endl;
    cout << " |   / \\" << endl;
    cout << "_|___    " << endl;
    cout << endl;
    break;
  }
}

std::string HangManDrawer::AskForLetter()
{
  std::string letter;
  bool inputCorrect = false;;
  while (!inputCorrect)
  {
    cout << "Letter: ";
    cin >> letter;
    if (letter.length() == 1)
      inputCorrect = true;
  }
  return letter;

}

std::string HangManDrawer::AskForWord()
{
  std::string word;
  bool inputCorrect = false;;
  while (!inputCorrect)
  {
    cout << "Word To Guess: ";
    cin >> word;
    if (word.length() > 1)
      inputCorrect = true;
  }
  return word;
}
