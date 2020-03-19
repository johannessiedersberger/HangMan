#include <string>
#include <stdexcept>

#include "HangManGame.hpp"


HangManGame::HangManGame(const std::string& word, int maxErrors)
{
  if (word.length() == 0 || word.empty())
    throw std::invalid_argument{ "The word is to short" };

  wordToGuess_ = LowerString(word);
  currentWord_ = CreateUnderscores(word.length());
  hangManState_ = 0;
  maxErrors_ = 10;
}

std::string HangManGame::LowerString(std::string word)
{
  for (size_t i = 0; i < word.length(); i++)
  {
    word[i] = std::tolower(word[i]);
  }
  return word;
}

std::string HangManGame::CreateUnderscores(int length)
{
  std::string underscores = "";
  underscores.resize(length, '_');
  return underscores;
}

void HangManGame::AddLetter(const std::string& letter)
{
  if (letter.length() != 1)
    throw std::invalid_argument{ "Pass just One Letter!" };
  
  std::string lowerLetter = LowerString(letter);

  if (lettersPicked_.find(lowerLetter) != std::string::npos)
  {
    throw std::invalid_argument{ "You already used this letter!" };
  }
  else
  {
    lettersPicked_.append(lowerLetter);
  }

  if (wordToGuess_.find(lowerLetter) != std::string::npos)
  {
    SetLetter(lowerLetter[0]);
  }
  else
  {
    hangManState_++;
    if (maxErrors_ < hangManState_)
    {
      throw std::exception{ "You already lost! " };
    }
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

bool HangManGame::CheckIfWon() const
{
  if (currentWord_.find('_') != std::string::npos)
  {
    return false;
  }
  else
  {
    return true;
  }
}

int HangManGame::GetHangManState() const
{
  return hangManState_;
}

std::string HangManGame::GetCurrentWord() const
{
  return currentWord_;
}

std::string HangManGame::GetLettersPicked() const
{
  return lettersPicked_;
}
