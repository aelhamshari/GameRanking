/* -------------------------------------------------
 *
 * File Name: Game.cpp
 * Author: Afnan Elhamshari
 * Assignment: EECS-269 Lab1
 * Description: Implementing the Game class
 * Date: 01/29/2018
 *
 ------------------------------------------------ */
 #include "Game.h"

Game::Game()
{

}

void Game::setRank(int rank)
{
  m_rank=rank;
}

void Game::setGameName(string name)
{
  m_name = name;
}

void Game::setYear(int year)
{
  m_year = year;
}

void Game::setGeekRating(double grating)
{
  m_grating=grating;
}

void Game::setAvgRating(double avgrating)
{
  m_avgrating=avgrating;
}

void Game::setVoters(int voters)
{
  m_voters=voters;
}

int Game::getRank()
{
  return(m_rank);
}

string Game::getGameName()
{
  return(m_name);
}

int Game::getYear()
{
  return(m_year);
}

double Game::getGeekRating()
{
  return(m_grating);
}

double Game::getAvgRating()
{
  return(m_avgrating);
}

int Game::getVoters()
{
  return(m_voters);
}
