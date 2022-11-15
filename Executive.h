/* -------------------------------------------------
 *
 * File Name: Executive.h
 * Author: Afnan Elhamshari
 * Assignment: EECS-269 Lab1
 * Description: Declaration of the Executive class
 * Date: 01/29/2018
 *
 ------------------------------------------------ */
#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "Game.h"
#include <string>

class Executive
{
  private:
    int Size;
    Game** games = nullptr;

  public:
    /*
    *  @pre arg is valid
    *  @param arg must be > 1
    *  @post Reads in data from a file into a pointer to an array of pointers of objects
    */
    Executive(string filename);
    /*
	   *  @pre None.
	   *  @post The array created by this object is deleted
	  */
    ~Executive();
    /*
     * @pre An Executive Object is created.
     * @post Interacts with the user and runs the Program
    */
    void run();
    /*
     * @pre None
     * @post all the games in the file are printed on the screen.
    */
    void print();
    /*
     * @pre j is valid
     * @param j is between 0 and Size
     * @post a specific game with index j is printed
    */
    void printGame(int j);
    /*
     * @pre min is a vaild input
     * @param min is bigger than 0
     * @post prints games with minimum number of voters = min
    */
    void MinRating();
    /*
     * @pre year is a valid input
     * @param year is bigger than 0
     * @post prints all games created in this year
    */
    void GameYear();
    /*
     * @pre None
     * @post prints the game with the largest absolute gap between the two Ratings
    */
    void LargestGap();

    void menu(int& choice);
};
#endif
