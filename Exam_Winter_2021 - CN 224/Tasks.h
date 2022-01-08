#pragma once
#include "PhoneBook.h"

#pragma region Identifiers
void menu();
void menuText(int select, string selecIcon);
void christmasThemedMenu(int select, string selecIcon, bool& animationSkip);
void themeColor1(int size);
void themeColor2(int size);
void themeColor3(int size);

void task1();

void task2();
void addPerson(int select, string selecIcon);
void searchPerson();

void task3();
void boardSetup(vector<vector<char>>& board, vector<vector<char>>& player, int row, int column, bool& startup);
void boardPrint(vector<vector<char>> board, vector<vector<char>> player, int row, int column, char playerIcon, string& typing, int summer, bool& eIsPressed);
void moveDirection(vector<vector<char>> board, vector<vector<char>>& player, int& movementX, int& movementY, bool& game, int row, int column, string& typing, int& summer, bool& eIsPressed);
int calculator(string& typing);
#pragma endregion

//Menu (Mandatory)
void menu() {

	bool animationSkip{ false };
	bool menu{ true };

	int select{ 0 };
	string selecIcon{ "->" };

	while (menu)
	{
		system("cls"); //Update menu

		christmasThemedMenu(select, selecIcon, animationSkip);

		char menuSelect = tolower(_getch());
		switch (menuSelect)
		{
		case 'w':
			select -= 1;
			break;
		case 's':
			select += 1;
			break;
		case 13:
			system("cls");
			if (select == 0)
				task1();
			else if (select == 1)
				task2();
			else if (select == 2)
				task3();
			else if (select == 3)
				exit(0); //When select == 2, exit program
			break;
		case 8:
			exit(0); //Exit the program
			break;
		default:
			break;
		}

		if (select < 0)
			select = 3;
		if (select > 3)
			select = 0;
	}
}
void menuText(int select, string selecIcon) {

	cout << endl << endl;

	if (select == 0)
		cout << selecIcon << " | Task 1" << endl;
	else
		cout << " | Task 1" << endl;

	if (select == 1)
		cout << selecIcon << " | Task 2" << endl;
	else
		cout << " | Task 2" << endl;

	if (select == 2)
		cout << selecIcon << " | Task 3" << endl;
	else
		cout << " | Task 3" << endl;

	if (select == 3)
		cout << selecIcon << " | Exit" << endl;
	else
		cout << " | Exit" << endl;

	cout << endl << endl;
}
void christmasThemedMenu(int select, string selecIcon, bool& animationSkip) {

	int timesRepeated{ 0 }; //Intro animation repeat cycle
	int size{ 2 }; //Size of the Intro line
	int sleepTime{ 300 }; //Amount of time between the animation shift

	if (animationSkip == false)
	{
		animationSkip = true;

		for (size_t i = 0; i < timesRepeated; i++)
		{
			//Menu Repeat 1 ----------------------------------------------------------
			themeColor1(size);
			menuText(select, selecIcon);
			themeColor1(size);

			Sleep(sleepTime);
			system("cls");

			//Menu Repeat 2 ----------------------------------------------------------
			themeColor2(size);
			menuText(select, selecIcon);
			themeColor2(size);

			Sleep(sleepTime);
			system("cls");

			//Menu Repeat 3 ----------------------------------------------------------
			themeColor3(size);
			menuText(select, selecIcon);
			themeColor3(size);

			Sleep(sleepTime);
			system("cls");
		}

		themeColor1(size);
		menuText(select, selecIcon);
		themeColor1(size);
	}
	else
	{
		themeColor1(size);
		menuText(select, selecIcon);
		themeColor1(size);
	}
}
void themeColor1(int size) {
	for (size_t i = 0; i < size; i++)
	{
		cout << termcolor::red << "*" << termcolor::reset;
		cout << termcolor::green << "-" << termcolor::reset;
		cout << termcolor::blue << "*" << termcolor::reset;
		cout << termcolor::green << "-" << termcolor::reset;
		cout << termcolor::yellow << "*" << termcolor::reset;
		cout << termcolor::green << "-" << termcolor::reset;
	}
	cout << termcolor::red << "*" << termcolor::reset;
}
void themeColor2(int size) {
	for (size_t i = 0; i < size; i++)
	{
		cout << termcolor::yellow << "*" << termcolor::reset;
		cout << termcolor::green << "-" << termcolor::reset;
		cout << termcolor::red << "*" << termcolor::reset;
		cout << termcolor::green << "-" << termcolor::reset;
		cout << termcolor::blue << "*" << termcolor::reset;
		cout << termcolor::green << "-" << termcolor::reset;
	}
	cout << termcolor::yellow << "*" << termcolor::reset;
}
void themeColor3(int size) {
	for (size_t i = 0; i < size; i++)
	{
		cout << termcolor::blue << "*" << termcolor::reset;
		cout << termcolor::green << "-" << termcolor::reset;
		cout << termcolor::yellow << "*" << termcolor::reset;
		cout << termcolor::green << "-" << termcolor::reset;
		cout << termcolor::red << "*" << termcolor::reset;
		cout << termcolor::green << "-" << termcolor::reset;
	}
	cout << termcolor::blue << "*" << termcolor::reset;
}

//task 1 (20 points)
void task1() {

	vector<string> setOne = {"Jack", "Sara", "Sina", "Rose"};
	vector<string> setTwo = {"Sara", "John", "Hana", "Sina"};

	vector<string> result{};

	int countSimilar{};

	//----------------------------------------------------------------------

	//Printing out "vector<string> setOne"
	cout << "Vector 1:" << endl;
	for (size_t i = 0; i < setOne.size(); i++)
		cout << setOne[i] << ", ";

	cout << endl << endl;

	//Printing out "vector<string> setTwo"
	cout << "Vector 2:" << endl;
	for (size_t i = 0; i < setTwo.size(); i++)
		cout << setTwo[i] << ", ";

	//----------------------------------------------------------------------

	//Checking the first vector
	for (size_t i = 0; i < setOne.size(); i++)
	{
		countSimilar = 0;

		for (size_t j = 0; j < setTwo.size(); j++)
		{
			if (setOne[i] == setTwo[j])
				countSimilar++;
		}

		if (countSimilar <= 0)
			result.push_back(setOne[i]);
		else
			result.push_back(setOne[i]);
	}

	//Checking the second vector
	for (size_t i = 0; i < setTwo.size(); i++)
	{
		countSimilar = 0;

		for (size_t j = 0; j < setOne.size(); j++)
		{
			if (setTwo[i] == setOne[j])
				countSimilar++;
		}

		if (countSimilar <= 0)
			result.push_back(setTwo[i]);
	}

	//Printing out the result
	cout << endl << endl;
	cout << "Result" << endl;
	cout << "------" << endl;
	for (size_t i = 0; i < result.size(); i++)
		cout << result[i] << ", ";
	
	system("pause > 0");
}

//Task 2 (30 points)
void task2() {

	int select{ 0 };
	string selecIcon{ "->" };
	bool run{ true };
	
	while (run)
	{
		system("cls"); //Update menu
		bool phoneMenu{ true };

		if (select == 0)
			cout << selecIcon << " | Add to Phonebook" << endl;
		else
			cout << " | Add to Phonebook" << endl;

		if (select == 1)
			cout << selecIcon << " | Search in Phonebook" << endl;
		else
			cout << " | Search in Phonebook" << endl;

		if (select == 2)
			cout << selecIcon << " | Go back to main menu" << endl;
		else
			cout << " | Go back to main menu" << endl;

		while (phoneMenu)
		{
			char menuSelect = tolower(_getch());
			switch (menuSelect)
			{
			case 'w':
				select -= 1;
				phoneMenu = false;
				break;
			case 's':
				select += 1;
				phoneMenu = false;
				break;
			case 13:
				system("cls");
				if (select == 0)
					addPerson(select, selecIcon);
				else if (select == 1)
					searchPerson();
				else if (select == 2)
					run = false;
					phoneMenu = false;
				break;
			case 8:
				run = false;
				phoneMenu = false;
				break;
			default:
				break;
			}

			if (select < 0)
				select = 2;
			if (select > 2)
				select = 0;
		}
	}
}
void addPerson(int select, string selecIcon) {

	Person person{};
	vector<Person> persons{};
	bool phoneBookRun{ true };

	while (phoneBookRun)
	{
		bool addMore{ true };

		//Add information to "vector<Person> persons"
		cout << "Add a name: \t\t";
		cin >> person.name;

		cout << "Add a 8-digit number: ";
		cin >> person.phoneNumber;
		
		persons.clear();
		persons.push_back(person);

		//Save "vector<Person> persons" to file
		ofstream phoneBook("PhoneBook.txt", ios::in | ios::app | ios::out);
		for (size_t i = 0; i < persons.size(); i++)
		{
			phoneBook << persons[i].name << endl;
			phoneBook << persons[i].phoneNumber << endl;
			cout << endl;
		}

		//Asked to add another person to the phonebook
		while (addMore)
		{
			system("cls"); //Update menu
			bool phoneMenu{ true };

			cout << "Do you want to add another person?" << endl;

			if (select == 0)
				cout << selecIcon << " | Yes" << endl;
			else
				cout << " | Yes" << endl;

			if (select == 1)
				cout << selecIcon << " | No" << endl;
			else
				cout << " | No" << endl;

			while (phoneMenu)
			{
				char menuSelect = tolower(_getch());
				switch (menuSelect)
				{
				case 'w':
					select -= 1;
					phoneMenu = false;
					break;
				case 's':
					select += 1;
					phoneMenu = false;
					break;
				case 13:
					system("cls");
					if (select == 0)
					{
						addMore = false;
						phoneMenu = false;
					}
					else if (select == 1)
					{
						phoneMenu = false;
						addMore = false;
						phoneBookRun = false;
					}
					break;
				case 8:
					phoneMenu = false;
					addMore = false;
					phoneBookRun = false;
					break;
				default:
					break;
				}

				if (select < 0)
					select = 1;
				if (select > 1)
					select = 0;
			}
		}
	}
}
void searchPerson() {

	string keyWord{};
	vector<string> phoneBookNames{};

	//Input search
	cout << "Search: ";
	cout << termcolor::bright_green;
	cin >> keyWord;
	cout << termcolor::reset;
	system("cls");

	//find name in file
	ifstream phoneBook("PhoneBook.txt", ios::in);
	if (phoneBook.is_open())
	{
		string buff{};
		int gotANameCount{};

		phoneBookNames.clear();
		while ((getline(phoneBook, buff)))
			phoneBookNames.push_back(buff);

		for (size_t i = 0; i < phoneBookNames.size(); i++)
		{
			if (keyWord == phoneBookNames[i])
			{
				cout << "Name: " << phoneBookNames[i] << endl;
				cout << "Phone number: " << phoneBookNames[i + 1] << endl;
				gotANameCount++;
			}
		}

		//If there is no name, named "Keyword" in the Phonebook
		if (gotANameCount <= 0)
			cout << "This name is not included in the Phonebook" << endl;

		system("pause > 0");

		phoneBook.close();
	}
}

//Task 3 (50 points)
void task3() {

	int row{ 5 };
	int column{ 4 };

	char playerIcon{'>'};
	string typing{};

	int summer{};
	bool eIsPressed{};

	vector<vector<char>> board(column, vector<char>(row));
	vector<vector<char>> player(column, vector<char>(row));

	int movementX{};
	int movementY{};

	bool game{ true };
	bool startup{ false };

	while (game)
	{
		if (startup == false)
			boardSetup(board, player, row, column, startup);

		boardPrint(board, player, row, column, playerIcon, typing, summer, eIsPressed);
		moveDirection(board, player, movementX, movementY, game, row, column, typing, summer, eIsPressed);
	}
}
void boardSetup(vector<vector<char>>& board, vector<vector<char>>& player, int row, int column, bool& startup) {

	startup = true;

	board[0][0] = ' ';
	board[1][0] = ' ';
	board[2][0] = ' ';
	board[3][0] = '/';

	board[0][1] = '7';
	board[1][1] = '8';
	board[2][1] = '9';
	board[3][1] = '*';

	board[0][2] = '4';
	board[1][2] = '5';
	board[2][2] = '6';
	board[3][2] = '-';

	board[0][3] = '1';
	board[1][3] = '2';
	board[2][3] = '3';
	board[3][3] = '+';

	board[0][4] = 'C';
	board[1][4] = '0';
	board[2][4] = '.';
	board[3][4] = 'E';
	
	for (size_t x = 0; x < row; x++)
	{
		for (size_t y = 0; y < column; y++)
			player[y][x] = ' ';
	}

	player[0][4] = '>';
}
void boardPrint(vector<vector<char>> board, vector<vector<char>> player, int row, int column, char playerIcon, string& typing, int summer, bool& eIsPressed) {

	system("cls");

	cout << "---------------------" << endl;
	if (eIsPressed)
		cout << summer << endl;
	else
		cout << typing << endl;
	
	cout << "---------------------" << endl;

	for (size_t x = 0; x < row; x++)
	{
		for (size_t y = 0; y < column; y++)
			cout << setw(2) << "| " << player[y][x] << board[y][x] << " ";

		cout << "|" << endl;
		cout << "---------------------" << endl;
	}

	//Info with colors
	cout << endl;
	cout << "Move " << termcolor::cyan << "up" << termcolor::reset << ":    " << termcolor::cyan << "W" << termcolor::reset << endl;
	cout << "Move " << termcolor::cyan << "down" << termcolor::reset << ":  " << termcolor::cyan << "S" << termcolor::reset << endl;
	cout << "Move " << termcolor::cyan << "right" << termcolor::reset << ": " << termcolor::cyan << "D" << termcolor::reset << endl;
	cout << "Move " << termcolor::cyan << "left" << termcolor::reset << ":  " << termcolor::cyan << "A" << termcolor::reset << endl;
	cout << endl;
}
void moveDirection(vector<vector<char>> board, vector<vector<char>>& player, int& movementX, int& movementY, bool& game, int row, int column, string& typing, int& summer, bool& eIsPressed) {

	movementX = 0;
	movementY = 0;
	bool enterIsPressed{ true };

	char menuSelect = tolower(_getch());
	switch (menuSelect)
	{
	case 'w':
		movementY -= 1;
		enterIsPressed = false;
		break;
	case 's':
		movementY += 1;
		enterIsPressed = false;
		break;
	case 'a':
		movementX -= 1;
		enterIsPressed = false;
		break;
	case 'd':
		movementX += 1;
		enterIsPressed = false;
		break;
	case 13:
		enterIsPressed = true;

		for (size_t y = 0; y < row; y++)
		{
			for (size_t x = 0; x < column; x++)
			{
				if (player[0][0] == '>')
				{
					typing += ' ';
					y = row;
					x = column;
				}
				else if (player[1][0] == '>')
				{
					typing += ' ';
					y = row;
					x = column;
				}
				else if (player[2][0] == '>')
				{
					typing += ' ';
					y = row;
					x = column;
				}
				else if (player[3][0] == '>')
				{
					typing += '/';
					y = row;
					x = column;
				}

				else if (player[0][1] == '>')
				{
					typing += '7';
					y = row;
					x = column;
				}
				else if (player[1][1] == '>')
				{
					typing += '8';
					y = row;
					x = column;
				}
				else if (player[2][1] == '>')
				{
					typing += '9';
					y = row;
					x = column;
				}
				else if (player[3][1] == '>')
				{
					typing += '*';
					y = row;
					x = column;
				}
					
				
				else if (player[0][2] == '>')
				{
					typing += '4';
					y = row;
					x = column;
				}
				else if (player[1][2] == '>')
				{
					typing += '5';
					y = row;
					x = column;
				}
				else if (player[2][2] == '>')
				{
					typing += '6';
					y = row;
					x = column;
				}
				else if (player[3][2] == '>')
				{
					typing += '-';
					y = row;
					x = column;
				}
					
				else if (player[0][3] == '>')
				{
					typing += '1';
					y = row;
					x = column;
				}
				else if (player[1][3] == '>')
				{
					typing += '2';
					y = row;
					x = column;
				}
				else if (player[2][3] == '>')
				{
					typing += '3';
					y = row;
					x = column;
				}
				else if (player[3][3] == '>')
				{
					typing += '+';
					y = row;
					x = column;
				}

				else if (player[0][4] == '>')
				{
					typing += 'C';
					typing = "";
					y = row;
					x = column;

					eIsPressed = false;
				}
				else if (player[1][4] == '>')
				{
					typing += '0';
					y = row;
					x = column;
				}
				else if (player[2][4] == '>')
				{
					typing += '.';
					y = row;
					x = column;
				}
				else if (player[3][4] == '>')
				{
					typing += 'E';
					y = row;
					x = column;
					summer = calculator(typing);
					eIsPressed = true;
				}
			}
		}
		break;
	case 8:
		game = false;
		enterIsPressed = false;
		break;
	default:
		break;
	}

	//Change the player icon's position
	for (size_t y = 0; y < row; y++)
	{
		for (size_t x = 0; x < column; x++)
		{
			if (player[x][y] == '>')
			{
				player[x + movementX][y + movementY] = '#';
				if (enterIsPressed == false)
					player[x][y] = ' ';
			}
		}
	}

	for (size_t y = 0; y < row; y++)
	{
		for (size_t x = 0; x < column; x++)
		{
			if (player[x][y] == '#')
				player[x][y] = '>';
		}
	}
}
int calculator(string& typing) {

	vector<int> number{};
	vector<char> parameters{};
	vector<int> numberTemp{};
	int sum{};
	int sumTemp{};
	int numberPosition{};

	string stringSum{};

	typing.push_back('.');

	//Reset all vectors and total score variable
	number.clear();
	parameters.clear();
	sum = 0;
	sumTemp = 0;

	//Sorting the string into vector<int> and vector<char>
	for (size_t k = 0; k < typing.size(); k++)
	{
		if (typing[k] != '1' && typing[k] != '2' && typing[k] != '3' && typing[k] != '4' && typing[k] != '5' && typing[k] != '6' && typing[k] != '7' && typing[k] != '8' && typing[k] != '9' && typing[k] != '0')
		{
			if (typing[k] == '.') {}
			else
				parameters.push_back(typing[k]);

			for (size_t i = 0; i < numberTemp.size(); i++)
			{
				if (i >= numberTemp.size() - 1)
					sumTemp += numberTemp[i];
				else
				{
					numberTemp[i] *= pow(10, numberTemp.size() - i - 1);
					sumTemp += numberTemp[i];
				}
			}

			number.push_back(sumTemp);

			sumTemp = 0;
			numberTemp.clear();
		}
		else
			numberTemp.push_back(typing[k] - 48);
	}

	sum = number[0];

	for (size_t i = 0; i < parameters.size(); i++)
	{
		if (parameters[i] == '+')
			sum += number[i + 1];
		else if (parameters[i] == '-')
			sum -= number[i + 1];
		else if (parameters[i] == '*')
			sum *= number[i + 1];
		else if (parameters[i] == '/')
			sum /= number[i + 1];
	}

	sum;

	return sum;
}