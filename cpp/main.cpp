#include	<assert.h>
#include	"Game.h"

Game		*g;

void		setup()
{
  g = new Game();
}

void		rollMany(int n, int pins)
{
  for (int i = 0; i < n; i++)
    {
      g->roll(pins);
    }
}

void		testGutterGame()
{
  int		n = 0;
  int		pins = 0;

  setup();
  rollMany(20, 0);
  assert(g->score() == 0);
}

void		testAllOnes()
{
  setup();
  rollMany(20, 1);
  assert(g->score() == 20);
}

void		rollSpare()
{
  g->roll(3);
  g->roll(7);
}

void		testOneSpare()
{
  setup();
  rollSpare();
  g->roll(6);
  rollMany(17, 0);
  assert(g->score() == 22);
}

void		rollStrike()
{
  g->roll(10);
}

void		testOneStrike()
{
  setup();
  rollStrike();
  g->roll(9);
  g->roll(9);
  rollMany(16, 0);
  assert(g->score() == 46);
}

void		testPerfectGame()
{
  setup();
  rollMany(12, 10);
  assert(g->score() == 300);
}

int		main()
{
  testGutterGame();
  testAllOnes();
  testOneSpare();
  testOneStrike();
  testPerfectGame();
  return (0);
}
