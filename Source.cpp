#include <iostream>
#include <string>

using namespace std;

int main()
{
	int letterShift;
	string initialPhrase;
	int counter = 0;
	std::cout << "Enter the phrase you wish to encrypt\n";
	std::getline(std::cin, initialPhrase);
	std::cout << "What is the shift amount desired?\n";
	std::cin >> letterShift;
	//making sure the shift stays within the alphabet
	letterShift %= 26;
	while (counter < initialPhrase.length())
	{
		//shifting the letters based on the given shift
		if (initialPhrase[counter] <= 'z' && initialPhrase[counter] >= 'a')
		{
			if ((initialPhrase[counter] + letterShift) < 'z')
				initialPhrase[counter] = (initialPhrase[counter] + letterShift);
			else
				initialPhrase[counter] = (initialPhrase[counter] + letterShift) - 'z' + 'a';
		}
		if (initialPhrase[counter] <= 'Z' && initialPhrase[counter] >= 'A')
		{
			if ((initialPhrase[counter] + letterShift)< 'Z')
				initialPhrase[counter] = (initialPhrase[counter] + letterShift);
			else
				initialPhrase[counter] = (initialPhrase[counter] + letterShift) - 'Z' + 'A';
		}
		counter++;
	}
	std::cout << "\nHere is your encrypted text: " << initialPhrase << endl;
}
