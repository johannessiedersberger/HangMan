#pragma once
#include<string>
class HangManGame
{
  std::string wordToGuess_;
  int hangManState_;
  std::string lettersPicked_;
  std::string currentWord_;

public:
  HangManGame(const std::string& word);
  HangManGame(const HangManGame&) = delete;
  HangManGame& operator = (const HangManGame&) = delete;

  void AddLetter(std::string letter);
  int GetHangManStateCopy() const;
  std::string GetCurrentWordCopy() const;
  bool CheckIfWon() const;

private:
 
};