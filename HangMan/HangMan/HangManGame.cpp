#include <string>
#include <stdexcept>

#include "HangManGame.hpp"

static std::string CheckWord(const std::string& word)
{
  if (word.length <= 0)
    throw std::invalid_argument{ "The word is to short" };
  return word;
}

HangManGame::HangManGame(const std::string& word)
  : wordToGuess_(CheckWord(word))
{
}

void HangManGame::AddLetter(std::string letter)
{

}