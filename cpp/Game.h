#ifndef		__GAME_H__
#define		__GAME_H__

class		Game
{
  int		itsScore;
  int		itsRolls[20];
  int		itsCurrentRoll;

 public:
  Game();
  void		roll(int pins);
  int		score();
  int		sumOfBallsInFrame(int i);
  int		isSpare(int i);
  int		spareBonus(int i);
  int		isStrike(int i);
  int		strikeBonus(int i);
};

#endif		/*__GAME_H__*/
