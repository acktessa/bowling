#include	<iostream>
#include	"Game.h"

Game::Game()
{
  itsScore = 0;
  itsCurrentRoll = 0;
}

void		Game::roll(int pins)
{
  itsScore += pins;
  itsRolls[itsCurrentRoll++] = pins;
}

int		Game::sumOfBallsInFrame(int i)
{
  return (itsRolls[i] + itsRolls[i + 1]);
}

int		Game::spareBonus(int i)
{
  return (itsRolls[i + 2]);
}

int		Game::isSpare(int i)
{
  return (sumOfBallsInFrame(i) == 10);
}

int		Game::isStrike(int i)
{
  return (itsRolls[i] == 10);
}

int		Game::strikeBonus(int i)
{
  return (itsRolls[i + 1] + itsRolls[i + 2]);
}

int		Game::score()
{
  int		score = 0;
  int		i = 0;
  int		frame;

  for (frame = 0; frame < 10; frame++)
    {
      if (isStrike(i))
	{
	  score += 10 + strikeBonus(i);
	  i++;
	}
      else if (isSpare(i))
	{
	  score += 10 + spareBonus(i);
	  i += 2;
	}
      else
	{
	  score += sumOfBallsInFrame(i);
	  i += 2;
	}
    }
  return (score);
}
