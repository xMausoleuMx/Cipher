#include <iostream>
#include <string>

using namespace std;

int main()
{
	int letterShift, counter = 0, choice;
	string initialPhrase;
	std::cout << "Enter your phrase\n";
	std::getline(std::cin, initialPhrase);
	std::cout << "Would you like to\n1.Encrypt\n2.Decrypt\n";
	std::cin >> choice;
	switch (choice)
	{
		case 1:
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
					if ((initialPhrase[counter] + letterShift) < 'Z')
						initialPhrase[counter] = (initialPhrase[counter] + letterShift);
					else
						initialPhrase[counter] = (initialPhrase[counter] + letterShift) - 'Z' + 'A';
				}
				counter++;
			}
			std::cout << "\nHere is your encrypted text: " << initialPhrase << endl;
			break;
		case 2:
			std::cout << "What is decryption key?\n";
			std::cin >> letterShift;
			letterShift %= 26;
			while (counter < initialPhrase.length())
			{
				//shifting the letters based on the given shift
				if (initialPhrase[counter] <= 'z' && initialPhrase[counter] >= 'a')
				{
					if ((initialPhrase[counter] - letterShift) > 'a')
						initialPhrase[counter] = (initialPhrase[counter] - letterShift);
					else
						initialPhrase[counter] = (initialPhrase[counter] - letterShift) + 'z'-'a';
				}
				if (initialPhrase[counter] <= 'Z' && initialPhrase[counter] >= 'A')
				{
					if ((initialPhrase[counter] - letterShift) > 'A')
						initialPhrase[counter] = (initialPhrase[counter] - letterShift);
					else
						initialPhrase[counter] = (initialPhrase[counter] - letterShift) + 'Z' - 'A';
				}
				counter++;
			}
			std::cout << "\nHere is your decrypted text: " << initialPhrase << endl;
	}
}
