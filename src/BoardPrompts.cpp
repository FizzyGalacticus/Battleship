#ifndef __BATTLESHIP__BOARD__PROMPTS__CPP
#define __BATTLESHIP__BOARD__PROMPTS__CPP

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

const string Board::initialShipCoordinatePrompt(const string & shipName, const int & shipHitpoints)
{
	string input;
	
	cout << "Please type desired coordinates for front of " << shipName
		<< endl << '(' << shipHitpoints << " total spaces needed) " << "(example: 'I4'): ";
	cin >> input;
	cin.ignore(1000, '\n');
	
	return input;
}

const char Board::shipDirectionalPrompt(const vector<vector<pair<int, int> > > & possibleShipDirections)
{
	const vector<string> availableShipDirectionStrings = parsePossibleShipDirections(possibleShipDirections);
	
	cout << "Please enter a direction (UDLR) you would like to face your ship." << endl;
	cout << "Your options are: " << endl;
	for(int j = 0; j < availableShipDirectionStrings.size(); j++)
		cout << availableShipDirectionStrings[j] << endl;
	
	return getchar();
}

const string Board::attackCoordinatePrompt()
{
	string input;
	
	cout << "Please enter coordinates that you wish to attack: ";
	cin >> input;
	cin.ignore(1000, '\n');
	
	return input;
}


#endif