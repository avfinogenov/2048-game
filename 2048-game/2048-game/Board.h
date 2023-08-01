#pragma once
#include <iostream>
#include <random>
#include <string>
#include <iomanip>
class Board
{
public:
	Board();
	~Board();
	void update(char key);
	void drawFrame();




private:
	//size of board 4x4
	int m_values[4][4]{ 0 };
	int score = 0;
	void addRandomValues();
	void addRandomValuesInit();
	void drawPrimitive(std::string p1, std::string p2);
	void drawPrimitiveWithNumber(std::string p1, std::string p2, int* value);
	void inputDiceValue(int diceValue);
	void updateScore();

};

