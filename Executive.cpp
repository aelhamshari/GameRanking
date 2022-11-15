/* -------------------------------------------------
 *
 * File Name: Executive.cpp
 * Author: Afnan Elhamshari
 * Assignment: EECS-269 Lab1
 * Description: Implementing the Executive class
 * Date: 01/29/2018
 *
 ------------------------------------------------ */
#include "Executive.h"
#include "Game.h"
#include <fstream>
#include <iostream>
#include <string>
#include <exception>
#include <cmath>
#include <limits>
using namespace std;

Executive::Executive(string filename)
{
  string read;
  string FileName = filename;
  ifstream inFile;
  inFile.open(FileName);
  inFile >> Size;
  cout << read << endl;
  games = new Game*[Size];
  for (int i=0;i<Size;i++)
  {
      games[i] = new Game();

      //Reading and setting the rank
      getline(inFile, read, ',');
      games[i]-> setRank(stoi (read));

      //Reading and setting the game name
      getline(inFile, read, '(');
      games[i]-> setGameName(read.substr(0,read.find('(')));

      //Reading and setting the game release year
      getline(inFile, read, ',');
      games[i] -> setYear(stoi (read.substr(read.find('(')+1, read.find(')'))));

      //Reading and setting the game Geek rating
      getline(inFile, read, ',');
      games[i] -> setGeekRating(stod (read.substr(read.find(',')+1, read.find(','))));
      
      //Reading nad setting average rating
      getline(inFile, read, ',');
      games[i] -> setAvgRating(stod (read.substr(read.find(',')+1, read.find(','))));

      //Reading and setting the number of votes
      getline(inFile, read);
      games[i] -> setVoters(stoi (read.substr(read.find(',')+1, read.find(' '))));
  }
}

Executive::~Executive()
{
  for (int i = 0; i < Size; i++)
  {
    delete games[i];
  }
  delete [] games;
}

void Executive::printGame(int j)
{
  cout << endl << games[j]-> getRank();
  cout << ")\t" << games[j]-> getGameName() << endl;
  cout << "\tGeek Rating: "<< games[j]-> getGeekRating() << endl;
  cout << "\tAverage Rating: " << games[j]-> getAvgRating() << endl;
  cout << "\tNum Ratings: " << games[j]-> getVoters() << endl;
  cout << "\tYear: " << games[j]-> getYear() << endl;
}

void Executive::print()
{
  cout << "\nHere is a list of all the games:\n";
  cout << "----------------------------------\n";
  for (int i=0; i < Size; i++)
  {
    printGame(i);
  }
}

void Executive::MinRating()
{
  int NumVoters = 0;
  cout << "What is the minimum number of voters do you want? ";
  cin >> NumVoters;
  while (cin.fail() || NumVoters < 0)
  {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Please Enter a valid number of voters: ";
    cin >> NumVoters;
  }
  int largest = 0;
  for (int i=0; i<Size; i++)
  {
    if (games[i]->getVoters() > largest)
    {
      largest = games[i]->getVoters();
    }
  }
  if (NumVoters > largest)
  {
    cout << "\nThe maximum number of voters is " << largest << " there are no games";
    cout << " with a minumum number of voters " << NumVoters << " in this list.\n";
  }
  else
  {
    cout << "\nHere is a list of all the games with at least " << NumVoters << " voters:\n";
    cout << "----------------------------------\n\n";
    for (int i=0; i<Size; i++)
    {
      if (games[i]->getVoters()>= NumVoters)
      {
        printGame(i);
      }
    }
  }
}

void Executive::GameYear()
{
  int year = 0;
  cout << "What is year of production? ";
  cin >> year;
  while (cin.fail() || year < 0)
  {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Please Enter a valid year of production: ";
    cin >> year;
  }
  int count = 0;
  for (int i=0; i<Size; i++)
  {
    if (games[i]->getYear() == year)
    {
      count = 1;
      break;
    }
  }
  if (count != 0)
  {
    cout << "\nHere is a list of all the games from the year " << year << ":\n";
    cout << "----------------------------------\n\n";
    for (int i=0; i<Size; i++)
    {
      if (games[i]->getYear() == year)
      {
        printGame(i);
      }
    }
  }
  else
  {
    cout << "\nThere are no games on this list built in this year.\n";
  }
}

void Executive::LargestGap()
{
  double max = 0;
  int largest = 0;
  for (int i=0; i<Size; i++)
  {
    if (abs((games[i]->getGeekRating())-(games[i]->getAvgRating())) > max)
    {
      max = abs((games[i]->getGeekRating())-(games[i]->getAvgRating()));
      largest = i;
    }
  }
  printGame(largest);
  cout << "\tRatings Difference: " << max << endl;
}


void Executive::menu(int &choice)
{
    cout << "\nWhat do you want to do?\n";
    cout << "\t1. Print all games from rank 1 to 100\n\t2. Print all games with a minimum amount of ratings\n";
    cout << "\t3. Print all games from a specific year\n\t4. Print the game with largest gap between the geek rating and the average rating\n";
    cout << "\t5. Exit\n";
    do{
      cout << "Your choice: ";
      cin >> choice;
      while (cin.fail() || choice <1 || choice > 5)
      {
        cin.clear();
	      cin.ignore(numeric_limits<streamsize>::max(),'\n');
	      cout << "Please Enter a valid choice.\n";
        cout << "Your choice: ";
        cin >> choice;
      }
    }while (choice <1 || choice > 5);
}

void Executive::run()
{
  int choice = 0;
  bool again = true;
  cout << "Welcome to BBG.com Top 100 games rankings!";
  do{
    menu(choice);
    switch (choice)
    {
      case 1:
      {
        print();
        break;
      }

      case 2:
      {
        MinRating();
        break;
      }

      case 3:
      {
        GameYear();
        break;
      }

      case 4:
      {
        LargestGap();
        break;
      }

      case 5:
      {
        cout << "Exiting the Program. Have a good day!\n";
        again = false;
      }
    }
  }while (again);
}
