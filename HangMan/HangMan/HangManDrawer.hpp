#pragma once
#include "HangManGame.hpp"
#include <string>

class HangManDrawer
{
public:
  static void DrawGame(HangManGame game);
  static std::string AskForLetter();
  static std::string AskForWord();

private:
  static void PrintCurrentWordState(HangManGame game);
  static void PrintLettersPicked(HangManGame game);
  static void PrintHangMan(int errors);
};

