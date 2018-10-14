#include <iostream>

using namespace std;

class Queens {
private:
	int conf[4][4];
public:
	int queens[4];
	Queens() {
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				conf[i][j] = 0;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			queens[i] = -1;
		}
	}
	void print() {
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				cout << conf[i][j] << " ";
			}
			cout << endl;
		}
	}
	bool unguards(int x, int y) {
		for (int i = 0; i < 4; i++)
		{
			if (queens[i] > -1)
			{
				if ((i != x) && (queens[i] != y) && (i - x != queens[i] - y) && (x - i != queens[i] - y))
					;
				else
					return false;
			}
		}
		return true;
	}
	void insert(int x, int y) {
		conf[x][y] = 1;
		queens[x] = y;
	}
	void remove(int x, int y)
	{
		conf[x][y] = 0;
		queens[x] = -1;
	}
};

void solution(Queens confi,int counts) {
	if (counts == 4)
	{
		confi.print();
		cout << endl;
	}
	else
	{
		for (int k = 0; k < 4; k++)
		{
			if (confi.unguards(counts, k))
			{
				confi.insert(counts, k);
				solution(confi, counts+1);
				confi.remove(counts, k);
			}
		}
	}
}
int main()
{
	Queens configuration;
	solution(configuration, 0);
	return 0;
}