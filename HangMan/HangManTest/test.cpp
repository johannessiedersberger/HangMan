#include <string>
#include <stdexcept>
#include "pch.h"
#include "HangManGame.cpp"

TEST(GameTest, TestConstruction)
{
  // Given
  HangManGame game{ "Test", 10 };
  // When / Then
  EXPECT_EQ(game.GetCurrentWord(), "____");
  EXPECT_EQ(game.GetHangManState(), 0);
}

TEST(GameTest, TestAddCorrectLetter)
{
  // Given
  HangManGame game{ "Test", 10 };
  // When 
  game.AddLetter("t");
  // Then
  EXPECT_EQ(game.GetCurrentWord(), "t__t");
  EXPECT_EQ(game.GetHangManState(), 0);
}

TEST(GameTest, TestAddWrongLetter)
{
  // Given
  HangManGame game{ "Test", 10 };
  // When 
  game.AddLetter("q");
  // Then
  EXPECT_EQ(game.GetCurrentWord(), "____");
  EXPECT_EQ(game.GetHangManState(), 1);
}

