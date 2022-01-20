#include "game.h"
using namespace std;
Game :: Game(){

	 PlayersPerTeam=4;
	 maxballs=6;
	 totalPlayers=11;

		players[0] = "Virat";
		players[1] = "Rohit";
		players[2] = "S Dhawan";
		players[3] = "Pant";
		players[4] = "MS Dhoni";
		players[5] = "KL Rahul";
		players[6] = "R Jadeja";
		players[7] = "Hardik";
		players[8] = "Bumrah";
		players[9] = "B Kumar";
		players[10] = "MD Shami";

	 this->isFirstInnings=false;
	 teamA.name="Team-A";
	 teamB.name="Team-B";
}

void Game::welcome(){

	cout<< "------------------------------------------------"<<"\n";
	cout<< "|=================CRIC--IN=====================|"<<"\n";
	cout<< "|                                              |"<<"\n";
	cout<< "|        Welcome to Virtual Cricket Game       |"<<"\n";
	cout<< "----------------------------------------------- "<<"\n";
	cout<<"\n"<<"\n";
	cout<< "------------------------------------------------------------"<<"\n";
	cout<< "|======================Instructions========================="<<"\n";
	cout<< "------------------------------------------------------------"<<"\n";
	cout<< "|                                                          |"<<"\n";
	cout<< "| 1. Create 2 teams (Team-A and Team-B with 4              |"<<"\n";
	cout<< "|    players each) from a give pool of 11 players.         |"<<"\n";
	cout<< "| 2. Lead the toss and decide the choice of play.          |"<<"\n";
	cout<< "| 3. Each innings will be of 6 balls.                      |"<<"\n";
	cout<< "------------------------------------------------------------"<<"\n";
}

void Game::showAllplayers() {

	cout<<"\n";
	cout<< "-----------------------------------------------------------"<<"\n";
	cout<< "|=====================Pool of Players=====================|"<<"\n";
	cout<< "-----------------------------------------------------------"<<"\n";
	cout<<"\n";
	for( int i=0;i< totalPlayers;i++) {
		cout<<"\t\t["<< i <<"] "<<players[i]<<"\n";
	}
}

int Game::takeIntegerInput(){

	int n;
	while(!(cin>>n)){

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout<<"Invalid input! Please try again with valid input: ";
	}
	return n;
}

bool Game::validateSelectedPlayer(int index) {
	int n;
	vector<Player> players;
	players=teamA.players;
	n=players.size();
	for(int i=0;i<n;i++)
	{
		if(players[i].id==index)
			return false;
	}

	players=teamB.players;
	n=players.size();
	for(int i=0;i<n;i++){
		if(players[i].id==index)
			return false;
	}
	return true;
}

void Game :: selectPlayer(){
	cout<<endl;
	cout<< "-------------------------------------------------------------"<<"\n";
	cout<< "|================Create Team--A and Team--B=================|"<<"\n";
	cout<< "-------------------------------------------------------------"<<"\n";

	for(int i=0;i<PlayersPerTeam;i++){

		// Selection of Team A Player
		cout<<"\n"<< "Select player " <<i + 1<<" of Team A -";
		teamASelection:
		int playerIndexTeamA=takeIntegerInput();
		if(playerIndexTeamA < 0 || playerIndexTeamA > 10) {
			cout<<"\n"<<"Please select from the given players"<<endl;
			goto teamASelection;
		}
		else if(!validateSelectedPlayer(playerIndexTeamA)){
			cout<<"\n"<<"Player has been already selected. Please select other players"<<"\n";
			goto teamASelection;
		}else{

			 Player teamAplayer;
			 teamAplayer.id = playerIndexTeamA;
			 teamAplayer.name = players[playerIndexTeamA];
			 teamA.players.push_back(teamAplayer);
		}


		// Selection Of Team B Player

	    teamBSelection:
		cout<<"\n"<< "Select player " <<i + 1<<" of Team B -";
		int playerIndexTeamB=takeIntegerInput();

		if(playerIndexTeamB < 0 || playerIndexTeamB > 10) {
			cout<<"\n"<<"Please select from the given players"<<endl;
			goto teamBSelection;
		}
		else if(!validateSelectedPlayer(playerIndexTeamB)){
			cout<<"\n"<<"Player has been already selected. Please select other players"<<"\n";
			goto teamBSelection;
		}else{

			 Player teamBplayer;
			 teamBplayer.id = playerIndexTeamB;
			 teamBplayer.name = players[playerIndexTeamB];
			 teamB.players.push_back(teamBplayer);
		}
	}
}

void Game::showTeamPlayers(){

	vector<Player> teamAPlayers = teamA.players;
	vector<Player> teamBPlayers = teamB.players;

	cout<<"\n"<<"\n";
	cout<<"------------------------\t\t-----------------------"<<"\n";
	cout<<"|======= Team--A ======\t\t\t=====  Team--B ======="<<"\n";
	cout<<"------------------------\t\t-----------------------"<<"\n";

	for(int i=0;i<PlayersPerTeam;i++) {

		cout<<"|\t"<<"["<<i<<"] "<<teamAPlayers[i].name<<"\t |"
				<<"\t\t"
				<<"|\t"<<"["<<i<<"] "<< teamBPlayers[i].name<<"\t |"<<"\n";
	}
	cout<<"-------------------------\t\t-------------------------"<<"\n"<<"\n";
}

void Game::toss() {
	cout<<"\n";
	cout<<"------------------------------------------------------"<<"\n";
	cout<<"=====================Let's Todd======================="<<"\n";
	cout<<"------------------------------------------------------"<<"\n";
	cout<<"\n";

	cout<<"Tossing the coin....."<<endl<<endl;

	srand(time(NULL));
	int randomValue = rand()%2;
	switch (randomValue) {
	case 0:
		cout<< "Team--A won the toss"<<"\n"<<"\n";
		tossChoice(teamA);
		break;
	case 1:
		cout<< "Team--B won the toss"<<"\n"<<"\n";
		tossChoice(teamB);
		break;
	}
}

void Game::tossChoice(Team tossWinnerTeam)
{
	cout<< "Enter 1 to bat or 2 to bowl first. "<<"\n";
	cout<<"1. Bat"<<endl;
	cout<<"2. Bowl"<<endl;

	int tossInput = takeIntegerInput();

	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	 switch(tossInput){
	 case 1:
		 cout<<"\n"<<tossWinnerTeam.name<<"won the toss and elected to bat first"<<endl<<endl;

		 if(tossWinnerTeam.name.compare("Team-A")==0)  // if team--A is the toss winner
		 {
			 battingTeam = &teamA;
			 bowlingTeam = &teamB;
		 }else{                                       // else Team--B is the toss winner
			 battingTeam=&teamB;
			 bowlingTeam=&teamA;
		 }
		 break;
	 case 2:
		 cout<<endl<<tossWinnerTeam.name<<"won the toss and choose to bowl first"<<"\n"<<"\n";

		 if(tossWinnerTeam.name.compare("Team-A")==0) // if Team--A is the toss winner
		 {
			 bowlingTeam=&teamA;
			 battingTeam=&teamB;
		 }else{                                      // else Team--B is the toss winner
			 bowlingTeam=&teamB;
			 battingTeam=&teamA;
		 }

		 break;
	 default:
		 cout<<endl<<"Invalid input.Please try again:"<<"\n"<<"\n";
		 tossChoice(tossWinnerTeam);
		 break;
	 }
}

void Game::startFirstInnings(){

	cout<<"\t\t  ||| FIRST INNINGS STARTS ||| "<<endl<<endl;

	isFirstInnings = true;

	initializePlayers();
	playInnings();
}

void Game :: startSecondInnings(){

	cout << "\t\t ||| SECOND INNINGS STARTS ||| " << "\n" << "\n";

	isFirstInnings=false;

	// Swap Batting Team and Bowling Team

    Team tempTeam = *battingTeam;
    *battingTeam = *bowlingTeam;
    *bowlingTeam = tempTeam;

   //  Select the batsman and bowler for second innings

    initializePlayers();
    playInnings();
}

void Game::initializePlayers(){

	// choose batsman and bowler : Initialize *batsman and *bowler
	 batsman = &battingTeam->players[0];
	 bowler = &bowlingTeam->players[0];

	 cout<<battingTeam->name<<" -  " << batsman->name << "is batting "<<endl;
	 cout<<bowlingTeam->name<<" - "<<bowler->name<< "is bowling"<<endl<<endl;

}

void Game::playInnings(){

	for(int i=0;i<maxballs;i++)
	{
		cout<< "Press Enter to bowl";
		getchar();
		cout<<"Bowling...."<<endl;
		bat();

		if(!validateInningsScore())
			break;
	}
}

void Game::bat()
{
	srand(time(NULL));
	int runScored = rand()%7;

	// Update batting team and batsman score
	batsman->runsScored+=runScored;
	battingTeam->totalRunsScored+=runScored;
	batsman->ballsPlayed+=1;

	// Update bowling team and bowler
	bowler->ballsBowled+=1;
	bowlingTeam->totalBallsBowled+=1;
	bowler->runsGiven+=runScored;

	if(runScored!=0){ // if runscored = 1,2,3,4,5,6
		cout<<"\n"<<bowler->name<<" to "<<batsman->name<<" "<<runScored<<" runs! "<<endl<<endl;
		showGameScorecard();
	}else{
		cout<<endl<<bowler->name<<" to "<<batsman->name<<" OUT! "<<endl<<endl;

		battingTeam->wicketsLost+=1;
  		bowler->wicketsTaken+=1;

		showGameScorecard();

		int nextPlayerIndex=battingTeam->wicketsLost;
		batsman=&battingTeam->players[nextPlayerIndex];

	}

}

bool Game::validateInningsScore(){

	if(isFirstInnings) {
		if(battingTeam->wicketsLost==PlayersPerTeam ||  bowlingTeam->totalBallsBowled==maxballs){

			cout<<"\t\t ||| FIRST INNINGS ENDS " <<"\n"<<endl;

			cout <<battingTeam->name<<" "<<battingTeam->totalRunsScored<<" - "
					<<battingTeam->wicketsLost << " ("<< bowlingTeam->totalBallsBowled<<")"<<endl;
			cout<< bowlingTeam->name<< " needs "<<battingTeam->totalRunsScored+1
					<<" runs to win the match"<<endl<<endl;
			return false;
		}
	} else{
		            //2nd Innings
		//Case1: If batting team score > bowling team score
    	if (battingTeam->totalRunsScored > bowlingTeam->totalRunsScored) {
        	cout << battingTeam->name << " WON THE MATCH" << endl << endl;
        	return false;

        	//Case2: Batting team is all OUT OR Bowling team is done bowling

        } else if (battingTeam->wicketsLost == PlayersPerTeam || bowlingTeam->totalBallsBowled == maxballs) {
            if (battingTeam->totalRunsScored < bowlingTeam->totalRunsScored) {
            	cout << bowlingTeam->name << " WON THE MATCH" << endl << endl;
            } else {
            	cout << "MATCH DRAW" << endl << endl;
            }
            return false;
        }
	}
	return true;
}

void Game::showGameScorecard(){

	cout<<"----------------------------------------------------"<<endl;

	cout<<"\t"<<battingTeam->name<<" "<<battingTeam->totalRunsScored<<"-"
		<< battingTeam->wicketsLost <<" ("<<bowlingTeam->totalBallsBowled<<") | "<<batsman->name
		<<" "<<batsman->runsScored<<" ("<< batsman->ballsPlayed <<") \t"
		<< bowler->name<<" "<<bowler->ballsBowled << " - "<<bowler->runsGiven <<" - "
		<< bowler->wicketsTaken <<"\t" <<endl;

	cout<< "----------------------------------------------------"<<endl<<endl;
}

void Game::showMatchSummary() {

cout << "\t\t ||| MATCH ENDS ||| " << endl << endl;

cout << battingTeam->name << " " << battingTeam->totalRunsScored << "-" << battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled << ")" << endl;

cout << "==========================================" << endl;
cout << "| PLAYER \t BATTING \t BOWLING |" << endl;

for (int j = 0; j < PlayersPerTeam; j++) {
	Player player = battingTeam->players[j];
	cout << "|----------------------------------------|" << endl;
	cout << "| " << "[" << j << "] " << player.name << "  \t "
    	<< player.runsScored << "(" << player.ballsPlayed << ") \t\t "
		<< player.ballsBowled << "-" << player.runsGiven << "-"
		<< player.wicketsTaken << "\t |" << endl;
}
cout << "==========================================" << endl << endl;

cout << bowlingTeam->name << " " << bowlingTeam->totalRunsScored << "-" << bowlingTeam->wicketsLost << " (" << battingTeam->totalBallsBowled << ")" << endl;

cout << "==========================================" << endl;
cout << "| PLAYER \t BATTING \t BOWLING |" << endl;

for (int i = 0; i < PlayersPerTeam; i++) {
	Player player = bowlingTeam->players[i];
    cout << "|----------------------------------------|" << endl;
    cout << "| " << "[" << i << "] " << player.name << "  \t "
        << player.runsScored << "(" << player.ballsPlayed << ") \t\t "
        << player.ballsBowled << "-" << player.runsGiven << "-"
		<< player.wicketsTaken << "\t |" << endl;
}
cout << "==========================================" << endl << endl;
}
