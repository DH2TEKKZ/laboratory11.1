#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct ComaPosition {
	int line;
	int pos;
};

ComaPosition findComa(ifstream& t1)
{
	string line;
	int count = 0;
	int lineN = 0;

	while (getline(t1, line)) {
		lineN++;

		for (int i = 0; i < line.length(); i++) {
			if (line[i] == ',')
			{
				count++;
				if (count == 3) {
					ComaPosition result { lineN, i + 1 };
					return result;
				}
			}
		}
	}
	ComaPosition result = { -1, -1 };
	return result;
}

int main()
{
	ifstream t1("t1.txt");
	string line;
	if (!t1.is_open()) {
		cerr << "Error opening file!" << endl;
		return -1;
	}
	while (getline(t1, line)) {
		cout << line << endl;
	}
	cout << endl << endl;
	t1.clear();
	t1.seekg(0, ios::beg);

	ComaPosition s = findComa(t1);

	cout << "Third coma line: " << s.line << " third coma pos: " << s.pos;

	t1.close();
	return 0;
}
