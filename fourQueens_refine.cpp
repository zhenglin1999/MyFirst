#include <iostream>
#define size 4
using namespace std;

class Queens {
private:
	bool col_unguard[size];
	bool ltr[2 * size - 1];
	bool rtl[2 * size - 1];
	int cols_rows[size];
public:
	Queens() {
		for (int i = 0; i < size; i++)
		{
			col_unguard[i] = true;
		}
		for (int i = 0; i < 2 * size - 1; i++)
		{
			ltr[i] = true;
			rtl[i] = true;
		}
	}
	void print() {
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (j == cols_rows[i])
					cout << "1" << " ";
				else
					cout << "0" << " ";
			}
			cout << endl;
		}
	}
	bool unguards(int rows,int cols) {
		return col_unguard[cols] && rtl[rows - cols + size - 1] && ltr[rows + cols];
	}
	void insert(int rows, int cols) {
		col_unguard[cols] = false;
		rtl[rows - cols + size - 1] = false;
		ltr[rows + cols] = false;
		cols_rows[rows] = cols;
	}
	void remove(int rows, int cols)
	{
		col_unguard[cols] = true;
		rtl[rows - cols + size - 1] = true;
		ltr[rows + cols] = true;
		cols_rows[rows] = -1;
	}
};

void solution(Queens confi, int counts) {
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
				solution(confi, counts + 1);
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