#include "Board.h"

Board::Board()
{
	srand(time(NULL));
	addRandomValuesInit();
	updateScore();
	drawFrame();
}	

Board::~Board()
{
}

void Board::update(char key)
{
	switch (key)
	{
	case 'w':
		//go top
		for (int k = 0; k < 4; ++k)
		{
			for (int i = 3; i > 0; --i)
			{
				for (int j = 0; j < 4; ++j)
				{
					if (m_values[i][j] == 0)
					{
						continue;
					}
					if (m_values[i - 1][j] == m_values[i][j])
					{
						m_values[i - 1][j] *= 2;
						m_values[i][j] = 0;
					}
					if (m_values[i - 1][j] == 0 && m_values[i][j] != 0)
					{
						m_values[i - 1][j] = m_values[i][j];
						m_values[i][j] = 0;
					}



				}
			}
		}
		break;
	case 'a':
		//go left
		for (int i = 0; i < 4; ++i)
		{
			for (int k = 0; k < 4; ++k)
			{
				for (int j = 3; j > 0; --j)
				{
					if (m_values[i][j] == 0)
					{
						continue;
					}
					if (m_values[i][j - 1] == m_values[i][j])
					{
						m_values[i][j - 1] *= 2;
						m_values[i][j] = 0;
					}
					if (m_values[i][j - 1] == 0 && m_values[i][j] != 0)
					{
						m_values[i][j - 1] = m_values[i][j];
						m_values[i][j] = 0;
					}



				}
			}
		}
		break;
	case 's':
		//go bottom
		for (int k = 0; k < 4; ++k)
		{
			for (int i = 0; i < 3; ++i)
			{

				for (int j = 0; j < 4; ++j)
				{
					if (m_values[i][j] == 0)
					{
						continue;
					}
					if (m_values[i + 1][j] == m_values[i][j])
					{
						m_values[i + 1][j] *= 2;
						m_values[i][j] = 0;
					}
					if (m_values[i + 1][j] == 0 && m_values[i][j] != 0)
					{
						m_values[i + 1][j] = m_values[i][j];
						m_values[i][j] = 0;
					}
				}
			}
		}
		break;
	case 'd':
		//go right
		for (int i = 0; i < 4; ++i)
		{
			for (int k = 0; k < 4; ++k)
			{

				for (int j = 0; j < 3; ++j)
				{
					if (m_values[i][j] == 0)
					{
						continue;
					}
					if (m_values[i][j + 1] == m_values[i][j])
					{
						m_values[i][j + 1] *= 2;
						m_values[i][j] = 0;
					}
					if (m_values[i][j + 1] == 0 && m_values[i][j] != 0)
					{
						m_values[i][j + 1] = m_values[i][j];
						m_values[i][j] = 0;
					}
				}
			}
		}
		break;
	case 'q':
		break;
	default:
		break;
	}
	addRandomValues();
	updateScore();

}

void Board::drawFrame()
{
	for (int i = 0; i < 4; ++i)
	{
		drawPrimitive("+", "-----");

		drawPrimitive("|", "     ");
		
		drawPrimitiveWithNumber("|", " ", &m_values[i][0]);
		
		drawPrimitive("|", "     ");
		
	}
	drawPrimitive("+", "-----");
	std::cout << "score: " << score << "\n";
	std::cout << "Enter move : (WASD or Q to quit)" << "\n";
	


}

void Board::addRandomValues()
{
	//dice for value
	int tmp = rand() % 5;
	if (tmp < 4)
	{
		inputDiceValue(2);
	}
	tmp = rand() % 5;
	if (tmp == 4)
	{
		inputDiceValue(4);
	}
	

}

void Board::addRandomValuesInit()
{
	inputDiceValue(2);
	inputDiceValue(4);
}

void Board::drawPrimitive(std::string p1, std::string p2)
{
	for (int i = 0; i < 4; ++i)
	{
		std::cout << p1 << p2;
	}
	std::cout << p1;
	std::cout << "\n";
}

void Board::drawPrimitiveWithNumber(std::string p1, std::string p2, int* value)
{
	for (int i = 0; i < 4; ++i)
	{
		if (value[i] != 0)
		{
			std::cout << p1;
			std::cout << std::setfill(p2[0]) << std::setw(5) << value[i];
		}
		else
		{
			std::cout << p1 << std::setfill(p2[0]) << std::setw(5) << p2;
		}
		
	}
	std::cout << p1;
	std::cout << "\n";
}

void Board::inputDiceValue(int diceValue)
{

	int emptyCounter = 0;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (m_values[i][j] == 0)
			{
				emptyCounter++;
			}


		}
	}

	//dice for cell
	int cellN = rand() % emptyCounter;

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{

			if (m_values[i][j] == 0)
			{
				cellN--;
				if (cellN == 0)
				{
					m_values[i][j] = diceValue;
				}
			}
			


		}
	}
}

void Board::updateScore()
{
	score = 0;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			score += m_values[i][j];
		}
	}
}
