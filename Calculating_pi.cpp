/*
Calculating pi.
No description.
*/

#include <iostream>
#include <cmath>   
#include <iomanip>

double calculate_pi(int terms)
{
	double sum = 0.0;
	for (int i = 0; i < terms; i++)
	{
		int sign = pow(-1, i);
		double term = 1.0/(i * 2 + 1);
		sum += sign * term;
	}
	return sum * 4;
}

int main()
{
  //Just for... 1E9, means 1 and 9 zero like: 1000000000.
  //Someone ask me that why you didnt use digit like 1000000000,and...i muted...for whole day.
	std::cout << std::setprecision(15) << calculate_pi(1E9) << std::endl;
	return 0;
}
