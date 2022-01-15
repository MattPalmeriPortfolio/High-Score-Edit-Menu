#include <string>
#include <iostream>
//declare functions
void highScoreAdder(std::string names[], int scores[], const int listSize, std::string newName, int newScore);
//Precondition: names[] and scores[] are arrays of the same size, listSize is equal to the size of names[] and scores[]
//Postcondition: finds the proper location on the list for newScore and places the name and score in the proper position, moving the other scores as necessary.
int nameSearch(std::string list[], const int listSize, std::string name);
//Precondition: listSize is equal to the size of array list[]
//Postcondition: starting from index 0, finds the first entry that corresponds to name, and returns the index - or, if the name was not found, returns listSize
void highScoreRemover(std::string names[], int scores[], const int listSize, std::string playerName);
//Precondition: names[] and scores[] are arrays of the same size, listSize is equal to the size of names[] and scores[]
//Postcondition: finds the highest score attached to playerName and removes it from the list, then re-sorts the list.
//main
int main()
{
	using namespace std;
	//initialize variables
	string names[10]{ "none", "none", "none", "none", "none", "none", "none", "none", "none", "none" }, nameUser;
	int scores[10]{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, scoreUser, menuChoice = 0, index;
	const int SIZE = 10;
	//begin program
	cout << "Welcome to the Chairjumper's High Score List.\n";
	do
	{
		cout << "Choose one of the following options:\n1: Show high score list\n2: Add new high score\n3: Search for high score\n4: Delete high score\n5: Exit\n";
		cin >> menuChoice;
		switch (menuChoice)
		{
		case 1:
			for (int i = 0; i < 10; i++)
				cout << i + 1 << ". " << names[i] << " " << scores[i] << endl;
			break;
		case 2:
			cout << "Enter the player's name, then press ENTER\n";
			cin >> nameUser;
			cout << "Enter the player's score, then press ENTER\n";
			cin >> scoreUser;
			highScoreAdder(names, scores, SIZE, nameUser, scoreUser);
			cout << "Scores added successfully.\n";
			break;
		case 3:
			cout << "Please enter the name of the player you wish to search for.\n";
			cin >> nameUser;
			index = nameSearch(names, SIZE, nameUser);
			if (index < SIZE)
				cout << "The highest score for " << names[index] << " is " << scores[index] << endl;
			else
				cout << "Player not found.\n";
			break;
		case 4:
			cout << "Enter the name of the player whose highest score you wish to remove:\n";
			cin >> nameUser;
			highScoreRemover(names, scores, SIZE, nameUser);
			break;
		default:
			cout << "Goodbye!\n";
			exit(0);
		}
	} while (menuChoice < 5);
	return 0;
}
//define functions
void highScoreAdder(std::string names[], int scores[], const int listSize, std::string newName, int newScore)
{
	using namespace std;
	if (newScore <= scores[listSize - 1])
		return;
	else
	{
		scores[listSize - 1] = newScore; names[listSize - 1] = newName;
		for (int index = listSize - 1; index > 0 && scores[index] > scores[index - 1]; index--)
		{
			int tempScore = scores[index - 1]; string tempName = names[index - 1];
			scores[index - 1] = scores[index]; names[index - 1] = names[index];
			scores[index] = tempScore; names[index] = tempName;
		}
	}
	return;
}
int nameSearch(std::string list[], const int listSize, std::string name)
{
	for (int index = 0; index < listSize; index++)
	{
		if (list[index] == name)
			return index;
	}
	return listSize;
}
//uses iostream
void highScoreRemover(std::string names[], int scores[], const int listSize, std::string playerName)
{
	using namespace std;
	int index = nameSearch(names, listSize, playerName);
	if (!(index < listSize))
	{
		cout << "Name not found.\n";
		return;
	}
	else
	{
		for (index; index < listSize - 1; index++)
		{
			names[index] = names[index + 1];
			scores[index] = scores[index + 1];
		}
		names[listSize - 1] = "none"; scores[listSize - 1] = 0;
		cout << "High score deleted successfully.\n";
	}
	return;
}