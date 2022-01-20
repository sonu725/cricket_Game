#include<iostream>
#include<cstdlib>
#include<ctime>
#include<limits>
#include"team.h" // player.h string and vector
class Game{

	public:
	Game();
	int PlayersPerTeam;
	int maxballs;
	int totalPlayers;
	std :: string players[11];
	bool isFirstInnings;
	Team teamA,teamB;
	Team *battingTeam,*bowlingTeam;
	Player *batsman,*bowler;

	void welcome();
	void showAllplayers();
	int takeIntegerInput();
	void selectPlayer();
	bool validateSelectedPlayer(int);
	void showTeamPlayers();
    void toss();
    void tossChoice(Team);
    void startFirstInnings();
    void initializePlayers();
    void playInnings();
    void  bat();
    bool validateInningsScore();
    void showGameScorecard();
    void startSecondInnings();
    void showMatchSummary();
};
