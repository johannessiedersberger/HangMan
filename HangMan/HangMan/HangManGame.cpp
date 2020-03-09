#include <string>
#include <stdexcept>

#include "HangManGame.hpp"

static std::string LowerString(std::string word)
{
  // convert string to back to lower case
  std::string newString = "";
  for (size_t i = 0; i < word.length(); i++)
  {
    word[i] = std::tolower(word[i]);
  }
  return word;
}

static std::string CheckWord(const std::string& word)
{
  if (word.length() == 0 || word.empty())
    throw std::invalid_argument{ "The word is to short" };
  return LowerString(word);
}

HangManGame::HangManGame(const std::string& word)
  : wordToGuess_(CheckWord(word))
{
}

void HangManGame::AddLetter(const std::string& letter)
{
  if (letter.length() != 1)
    throw std::invalid_argument{ "Pass just One Letter!" };

  if (lettersPicked_.find(letter) != std::string::npos)
  {
    throw std::invalid_argument{ "You already used this letter!" };
  }
  else
  {
    lettersPicked_.append(letter);
  }

  if (wordToGuess_.find(letter))
  {
    SetLetter(letter[0]);
  }
  else
  {
    hangManState_++;
  }
}

void HangManGame::SetLetter(char letter)
{
  for (size_t i = 0; i < wordToGuess_.length(); i++)
  {
    if (wordToGuess_[i] == letter)
    {
      currentWord_[i] = letter;
    }
  }
}