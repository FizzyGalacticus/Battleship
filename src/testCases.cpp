//Dustin Dodson & Bucky Frost
//Main test file to test all the codes!
//CS372 Project 1

#define CATCH_CONFIG_MAIN	//Define the main function to be used by CATCH
#include "catch.hpp"		//Include CATCH testing framework

#include "Board.h"

TEST_CASE("Testing values for Board class", "[Board]")
{
	SECTION("Testing FizzBuzz Code")
	{
		Board myBoard;
		REQUIRE(myBoard.isOccupied(0,0) == false);
		REQUIRE(myBoard.isOccupied(5,0) == false);
		REQUIRE(myBoard.isOccupied(0,9) == false);
		REQUIRE(myBoard.isOccupied(4,6) == false);
	}
}