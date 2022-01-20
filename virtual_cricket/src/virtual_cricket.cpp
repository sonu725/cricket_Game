#include "game.h"
using namespace std;
int main(){
	Game game;
	game.welcome();
	cout<<"Press Enter to continue"<<endl;
	getchar();
	game.showAllplayers();

	cout<<"Press Enter to continue"<<endl;
	getchar();

	game.selectPlayer();
	game.showTeamPlayers();

	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	cout<<"\nPress Enter to toss";
	getchar();

	game.toss();

	game.startFirstInnings();

    game.startSecondInnings();

    game.showMatchSummary();
	return 0;
}
