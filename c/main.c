#include	<assert.h>
#include	<stdio.h>

int		itsRolls[20];
int		itsCurrentRoll = 0;

void		setup()
{
  itsCurrentRoll = 0;
}

void		gameRoll(int pins)
{
  itsRolls[itsCurrentRoll++] = pins;
}

int		isSpare(int i)
{
  return (itsRolls[i] + itsRolls[i + 1] == 10);
}

int		spareScore(int i)
{
  return (10 + itsRolls[i + 2]);
}

int		sumOfBallsInFrame(int i)
{
  return (itsRolls[i] + itsRolls[i + 1]);
}

int		addScoreFromFrame(int *score, int *i)
{
  if (itsRolls[*i] == 10)
    {
      *score = 10 + itsRolls[*i + 1] + itsRolls[*i + 2];
      (*i)++;
    }
  else if (isSpare(*i))
    {
      (*score) += spareScore(*i);
      *i += 2;
    }
  else
    {
      (*score) += sumOfBallsInFrame(*i);
      *i += 2;
    }
}

int		gameScore()
{
  int		frame;
  int		score = 0;
  int		i = 0;

  for (frame = 0; frame < 10; frame++)
    {
      addScoreFromFrame(&score, &i);
    }
  return (score);
}

void		rollMany(int n, int pins)
{
  int		i;

  for (i = 0; i < n; i++)
    {
      gameRoll(pins);
    }
}

void		testGutterGame()
{
  setup();
  rollMany(20, 0);
  assert(gameScore() == 0);
}

void		testAllOnes()
{
  setup();
  rollMany(20, 1);
  assert(gameScore() == 20);
}

void		rollSpare()
{
  gameRoll(5);
  gameRoll(5);
}

void		testOneSpare()
{
  setup();
  rollSpare();
  gameRoll(3);
  rollMany(17, 0);
  assert(gameScore() == 16);
}

void		testOneStrike()
{
  setup();
  gameRoll(10);
  gameRoll(3);
  gameRoll(4);
  rollMany(16, 0);
  assert(gameScore() == 24);
}

int		main()
{
  testGutterGame();
  testAllOnes();
  testOneSpare();
  testOneStrike();
  return (0);
}
