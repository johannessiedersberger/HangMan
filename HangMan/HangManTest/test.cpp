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
  EXPECT_EQ(game.GetLettersPicked(), "t");
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
  EXPECT_EQ(game.GetLettersPicked(), "q");
}

TEST(GameTest, WinGame)
{
  // Given
  HangManGame game{ "Test", 10 };
  // When 
  game.AddLetter("t");
  game.AddLetter("e");
  game.AddLetter("s");
  // Then
  EXPECT_EQ(game.GetCurrentWord(), "test");
  EXPECT_EQ(game.GetHangManState(), 0);
  EXPECT_EQ(game.GetLettersPicked(), "tes");
  EXPECT_EQ(game.CheckIfWon(), true);
}

TEST(GameTest, LoseGame)
{
  // Given
  HangManGame game{ "Test", 10 };
  // When 
  game.AddLetter("x");
  game.AddLetter("y");
  game.AddLetter("z");
  game.AddLetter("a");
  game.AddLetter("b");
  game.AddLetter("c");
  game.AddLetter("d");
  game.AddLetter("f");
  game.AddLetter("g");
  game.AddLetter("h");

  // Then
  EXPECT_EQ(game.GetCurrentWord(), "____");
  EXPECT_EQ(game.GetHangManState(), 10);
  EXPECT_EQ(game.GetLettersPicked(), "xyzabcdfgh");
  EXPECT_EQ(game.CheckIfWon(), false);
}


