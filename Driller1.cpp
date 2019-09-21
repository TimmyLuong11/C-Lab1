#include <iostream>
#include <string> 
#include <vector> 
#include <fstream> 
#include <sstream>
#include <stdio.h>
using namespace std;
/*
int main()
{
	//freopen("7-31-17.csv", "r", stdin);
	//ifstream myFile("mixed_error_practice", ios::binary);
	string lineStr;
	string line1;
	vector<string> passLine1;
	vector<string> strArray;
	vector<string> strArrayDate;
	vector<string> strArrayTime;
	vector<string> strArrayValue;
	vector<int> lineC;
	string date;

	getline(cin, lineStr);

	int i = 0;
	int mul = 0;
	while (getline(cin, lineStr))
	{
		std::string subString;
		std::istringstream issline(lineStr);
		while (getline(issline, subString, ',')) {
			strArray.push_back(subString);

		}

		cout << strArray[i] << endl;
		strArrayDate.push_back(strArray[i]);
		strArrayTime.push_back(strArray[i + 1]);
		date = strArrayDate[0];

		i = i + 18;
	}

	long strArraySize = strArray.size();
	long strArrayDateSize = strArrayDate.size();

	for (int i = 2; i < strArraySize; i = i + 18) {
		int count = 0;
		while (count < 16) {
			strArrayValue.push_back(strArray[count + i]);
			count++;
		}
	}


	//cout << strArrayTime[9] << endl;
	//after this not showing
	//string date = strArrayDate[0];

	for (int i = 0; i < strArrayDateSize; ++i)
	{
		line1 = "";
		if (date == strArrayDate[i]) {
			int count = 0;
			while (count < 18) {

				//cout << strArray[count + mul];
				line1.append(strArray[count + mul]);

				if (count < 17) {
					line1.append(";");
				}
				count++;
			}
			passLine1.push_back(line1);
			mul = mul + 18;
		}

		else {
			//cout << "Non-matching date stamp " << strArrayDate[i] << " at line " << i + 1 << "." << endl;

			passLine1.push_back("Non-matching date stamp " + strArrayDate[i] + " at line " + to_string(i + 1) + ".");

			strArrayTime[i] = to_string(i);

			int ct = 0;
			int lineCT = 16 * i;

			while (ct < 16) {
				strArrayValue[(lineCT + ct)] = to_string(1);
				ct++;
			}
			mul = mul + 18;
		}
	}

	for (int i = 0; i < passLine1.size(); ++i) {
		   cout << passLine1[i] << endl;
	}


	long strArrayTimeSize = strArrayTime.size();

	for (int i = 0; i < strArrayTimeSize; ++i) {

		string test = strArrayTime[i];

		for (int index = 1; index < strArrayTimeSize; ++index)
		{
			if ((i + index) < strArrayTimeSize)
			{
				if (test == strArrayTime[index + i])
				{
					passLine1[i + index] = "Duplicate time stamp " + strArrayTime[i + index] + " at line " + to_string(i + index + 1) + ".";

					int ct = 0;
					int lineCT = 16 * index;

					while (ct < 16)
					{
						strArrayValue[(lineCT + ct)] = to_string(1);
						ct++;
					}
				}
			}
		}
	}

	long strArrayValueSize = strArrayValue.size();

	int lineCounter = 1;
	int test = 0;

	for (int i = 0; i < strArrayValueSize; ++i)
	{
		if ((i - 16) == test)
		{
			++lineCounter;
			test = i;
		}

		float f = stof(strArrayValue[i].c_str());

		if (f <= 0)
		{
			passLine1[lineCounter - 1] = "Invalid floating-point data at line " + to_string(lineCounter) + ".";
		}
	}

	long passLine1Size = passLine1.size();

	for (int i = 0; i < passLine1Size; ++i)
	{
		cout << passLine1[i] << endl;
	}

	//result is not reading file
	//cout << passLine1Size << strArray.size() << strArrayDateSize << strArrayTimeSize;

	/*cout << endl;

	for (int i = 0; i < strArrayTime.size(); ++i)
	{
		   cout << strArrayTime[i] << endl;
	}*/

	//cout << strArrayValue.size();

	/*int index = 1;

	for (int i = 0; i < strArrayValue.size(); ++i)
	{
		cout << strArrayValue[i] << " ";
		if (index % 16 == 0)
		{
			cout << endl;
		}
		   ++index;

	}
	fclose(stdin);

	return 0;
}
*/