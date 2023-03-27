#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void punch(vector<int> a_y, vector<int> a_x, vector<int> b_y, vector<int> b_x)
{
	vector<int> punch_x;
	vector<int> punch_y;
	int check_x;
	int check_y;
	for (int i = 0; i < a_y.size(); i++)
	{
		for (int j = 0; j < b_y.size(); j++)
		{
			if ((abs(a_y[i] - b_y[j]) == 1) && (abs(a_x[i] - b_x[j]) == 1))
			{
				if (a_y[i] < b_y[j])
				{
					if (a_x[i] < b_x[j])
					{
						check_x = a_x[i] + 2;
						check_y = a_y[i] + 2;
						if (check_x < 8 && check_x > -1 && check_y < 8 && check_y > -1)
						{
							int k = 0;
								while (check_x != b_x[k] && check_y != b_y[k] && k < (b_x.size() - 1))
								{
									k += 1;
								}
								if (k == b_x.size() - 1 && check_x != b_x[k] && check_y != b_y[k])
								{
									punch_x.push_back(b_x[j]);
									punch_y.push_back(b_y[j]);
								}
						}
					}
					else
					{
						check_x = a_x[i] - 2;
						check_y = a_y[i] + 2;
						if (check_x < 8 && check_x > -1 && check_y < 8 && check_y > -1)
						{
							int k = 0;
							while (check_x != b_x[k] && check_y != b_y[k] && k < (b_x.size() - 1))
							{
								k += 1;
							}
							if (k == b_x.size() - 1 && check_x != b_x[k] && check_y != b_y[k])
							{
								punch_x.push_back(b_x[j]);
								punch_y.push_back(b_y[j]);
							}
						}
					}
				}
				else
				{
					if (a_x[i] < b_x[j])
					{
						check_x = a_x[i] + 2;
						check_y = a_y[i] - 2;
						if (check_x < 8 && check_x > -1 && check_y < 8 && check_y > -1)
						{
							int k = 0;
							while (check_x != b_x[k] && check_y != b_y[k] && k < (b_x.size() - 1))
							{
								k += 1;
							}
							if (k == b_x.size() - 1 && check_x != b_x[k] && check_y != b_y[k])
							{
								punch_x.push_back(b_x[j]);
								punch_y.push_back(b_y[j]);
							}
						}
					}
					else
					{
						check_x = a_x[i] - 2;
						check_y = a_y[i] - 2;
						if (check_x < 8 && check_x > -1 && check_y < 8 && check_y > -1)
						{
							int k = 0;
							while (check_x != b_x[k] && check_y != b_y[k] && k < (b_x.size() - 1))
							{
								k += 1;
							}
							if (k == b_x.size() - 1 && check_x != b_x[k] && check_y != b_y[k])
							{
								punch_x.push_back(b_x[j]);
								punch_y.push_back(b_y[j]);
							}
						}
					}
				}
			}
		}
	}
	ofstream out("result.txt", ofstream::app);
	for (int i = 0; i < punch_x.size(); i++)
	{
		out << punch_x[i] << ' ' << punch_y[i] << endl;
	}
}


int main()
{
	vector<vector<char>> board(8, vector<char>(8));
	vector<int> white_x;
	vector<int> white_y;
	vector<int> black_x;
	vector<int> black_y;
	ifstream inp("board.txt");
	ofstream out("result.txt");
	//ofstream out("result.txt");
	char c;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
		writ:
			c = inp.get();
			if (c != 'w' && c != 'b' && c != '.')
				goto writ;
			board[i][j] = c;
			if (board[i][j] == 'w')
			{
				white_y.push_back(i);
				white_x.push_back(j);
				cout << "W: " << j << ' ' << i << endl;
			}
			if (board[i][j] == 'b')
			{
				black_y.push_back(i);
				black_x.push_back(j);
				cout << "B: " << j << ' ' << i << endl;
			}
		}
	}
	punch(white_y, white_x, black_y, black_x);
	//punch(black_y, black_x, white_y, white_x);
	inp.close();
	vector<int> punch_x;
	vector<int> punch_y;
	int check_x;
	int check_y;
	for (int i = 0; i < white_y.size(); i++)
	{
		for (int j = 0; j < black_y.size(); j++)
		{
			if ((abs(white_y[i] - black_y[j]) == 1) && (abs(white_x[i] - black_x[j]) == 1))
			{
				if (white_y[i] < black_y[j])
				{
					if (white_x[i] < black_x[j])
					{
						check_x = white_x[i] + 2;
						check_y = white_y[i] + 2;
						if (check_x < 8 && check_x > -1 && check_y < 8 && check_y > -1)
						{
							if (check_x != black_x[j] && check_y != black_y[j])
							{
								punch_x.push_back(black_x[j]);
								punch_y.push_back(black_y[j]);
							}
						}
					}
					else
					{
						check_x = white_x[i] - 2;
						check_y = white_y[i] + 2;
						if (check_x < 8 && check_x > -1 && check_y < 8 && check_y > -1)
						{
							if (check_x != black_x[j] && check_y != black_y[j])
							{
								punch_x.push_back(black_x[j]);
								punch_y.push_back(black_x[j]);
							}
						}
					}
				}
				else
				{
					if (white_x[i] < black_x[j])
					{
						check_x = white_x[i] + 2;
						check_y = white_y[i] - 2;
						if (check_x < 8 && check_x > -1 && check_y < 8 && check_y > -1)
						{
							if (check_x != black_x[j] && check_y != black_y[j])
							{
								punch_x.push_back(black_x[j]);
								punch_y.push_back(black_x[j]);
							}
						}
					}
					else
					{
						check_x = white_x[i] - 2;
						check_y = white_y[i] - 2;
						if (check_x < 8 && check_x > -1 && check_y < 8 && check_y > -1)
						{
							if (check_x != black_x[j] && check_y != black_y[j])
							{
								punch_x.push_back(black_x[j]);
								punch_y.push_back(black_x[j]);
							}
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < black_x.size(); i++)
	{
		out << punch_x[i] << ' ' << punch_y[i] << endl;
	}
}