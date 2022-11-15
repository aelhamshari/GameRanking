/* -------------------------------------------------
 *
 * File Name: Game.h
 * Author: Afnan Elhamshari
 * Assignment: EECS-269 Lab1
 * Description: Declaration of the Game class
 * Date: 01/29/2018
 *
 ------------------------------------------------ */
#ifndef GAME_H
#define GAME_H
#include <string>
using namespace std;

class Game
{
  private:
    int m_rank;
    string m_name;
    int m_year;
    double m_grating; //geek rating
    double m_avgrating; //average rating
    int m_voters;

  public:
    /*
     * @pre None
     * @post creates a Game object
    */
    Game();
    /*
     * @pre None
     * @post None
     * @return Returns the Rank of the game
    */
    int getRank();
    /*
     * @pre None
     * @post None
     * @return Returns the Name of the game
    */
    string getGameName();
    /*
     * @pre None
     * @post None
     * @return Returns the year the game was created in
    */
    int getYear();
    /*
     * @pre None
     * @post None
     * @return Returns the geek rating of the game
    */
    double getGeekRating();
    /*
     * @pre None
     * @post None
     * @return Returns the Average Rating of the game
    */
    double getAvgRating();
    /*
     * @pre None
     * @post None
     * @return Returns the number of voters
    */
    int getVoters();
    /*
     * @pre rank is a valid
     * @param rank is between 0 and Size
     * @post sets the member variable m_rank
    */
    void setRank(int rank);
    /*
     * @pre name is a valid
     * @param takes in a name from a file
     * @post sets the member variable m_name
    */
    void setGameName(string name);
    /*
     * @pre year is a valid
     * @param year is read from a file
     * @post sets the member variable m_year
    */
    void setYear(int year);
    /*
     * @pre grating is a valid
     * @param grating is the geek rating read from a file
     * @post sets the member variable m_grating
    */
    void setGeekRating(double grating);
    /*
     * @pre avgrating is a valid
     * @param avgrating is the average rating read from a file
     * @post sets the member variable m_avgrating
    */
    void setAvgRating(double avgrating);
    /*
     * @pre voters is a valid
     * @param voters is the number of voters read from a file
     * @post sets the member variable m_voters
    */
    void setVoters(int voters);
};
#endif
