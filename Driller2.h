#include <iostream>
#include <string> 
#include <vector> 
#include <sstream>
#include <fstream> 
using namespace std;

int main()
{
	//initiated start values
	int i = 0;
	int second = 0;

	//organization for reading lines
	string firstLine;
	string line;
	string date;

	vector<string> skipLine;
	vector<string> stringVector;
	vector<string> dateVector;
	vector<string> timeVector;
	vector<string> valueVector;
	vector<int> hereLine;

	getline(cin, firstLine);

	//while-while loop for date outputs
	while (getline(cin, firstLine))
	{
		string newString;
		istringstream inside(firstLine);
		while (getline(inside, newString, ',')) {
			stringVector.push_back(newString);
		}

		dateVector.push_back(stringVector[i]);
		timeVector.push_back(stringVector[i + 1]);
		date = dateVector[0];
		i += 18;
	}

	long arraySize = stringVector.size();
	long dateSize = dateVector.size();

	for (int sizeCounter = 2; sizeCounter < arraySize; sizeCounter++) {

		for (int cont = 0; cont < 16; ++cont) {
			valueVector.push_back(stringVector[cont + sizeCounter]);
		}
		sizeCounter += 17;
	}

	int dateCounter = 0;
	while (dateCounter < dateSize) {
		line = "";
		if (date == dateVector[dateCounter]) {
			int counter = 0;
			while (counter <= 17) {
				line.append(stringVector[counter + second]);
				if (counter < 17) {
					line.append(";");
				}
				counter++;
			}
			skipLine.push_back(line);
			second += 18;
			dateCounter++;
		}

		//else to track different dates to have output
		else {
			int lineCounter = 16 * i;
			skipLine.push_back("Dates are not matching " + dateVector[i] + " at line " + to_string(i + 1) + ".");
			timeVector[i] = to_string(i);

			for (int count = 0; count < 16; count++) {
				valueVector[(lineCounter + count)] = to_string(1);
			}
			second += 18;
		}
	}
	//matching times for for loop
	long timeSize = timeVector.size();

	for (int i = 0; i < timeSize; ++i) {

		string test = timeVector[i];
		for (int perCol = 1; perCol < timeSize; ++perCol) {

			if ((i + perCol) < timeSize) {

				if (test == timeVector[perCol + i]) {

					skipLine[i + perCol] = "Duplicate time stamp " + timeVector[i + perCol] + " at line " + to_string(i + perCol + 1) + ".";
					int lineCounter = 16 * perCol;

					for (int count = 0; count < 16; ++count) {
						valueVector[(lineCounter + count)] = to_string(1);
					}
				}
			}
		}
	}

	//loops for error on floating points
	long valSize = valueVector.size();
	long skiplineSize = skipLine.size();
	int hereVal = 0;
	int lineCounter = 1;

	for (int i = 0; i < valSize; ++i) {
		if ((i - 16) == hereVal) {
			++lineCounter;
			hereVal = i;
		}

		float first = stof(valueVector[i].c_str());
		if (first <= 0) {
			skipLine[lineCounter - 1] = "Invalid floating-point data at line " + to_string(lineCounter) + ".";
		}

	}
	int final = 0;
	while (final < skiplineSize) {

		cout << skipLine[final] << endl;
		final++;
	}
}