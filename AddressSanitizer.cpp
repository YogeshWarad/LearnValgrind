#include<array>
#include<iostream>

int main()
{
	std::array<int, 4>myArray = { 1,3,4,6 };
	
	for (int i = 0; i <= myArray.size(); i++)
	{
		std::cout << myArray[i] << std::endl;
	}
}