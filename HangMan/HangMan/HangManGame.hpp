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

  void AddLetter(const std::string& letter);
  int GetHangManState() const;
  std::string GetCurrentWord() const;
  bool CheckIfWon() const;

private:
  void SetLetter(char letter);
  std::string CreateUnderscores(int length);
  std::string LowerString(std::string word);
};