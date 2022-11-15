/* -------------------------------------------------
 *
 * File Name: main.cpp
 * Author: Afnan Elhamshari
 * Assignment: EECS-269 Lab1
 * Description: run and test the code
 * Date: 01/29/2018
 *
 ------------------------------------------------ */
#include "Executive.h"
#include "Game.h"
#include <iostream>
using namespace std;


int main(int argc,char** argv)
{
  if(argc < 2)
  {
    cout << "Incorrect number of parameters! Please provide the name of the file.\n";
  }
  else
  {
     Executive executive (argv[1]);
     executive.run();
  }

  return(0);
}
