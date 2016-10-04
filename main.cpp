#include <iostream>
#include <cmath>
using namespace std;

//Prototypes
void Help();
bool InputData(char& operation, double& operand);
double calculate(double total, char operation, double operand);
bool calculate(double total, char operation, double operand, int i);


int main()
{
	//declare and initialize variables
	char operation;
	double operand, total = 0.000;
	bool quit = false, valid = false;

	//Show menu
	Help();

	//Magic formula to display with 3 digits after decimal
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(3);

	//Loop until quit is true
	do
	{
		//Display the current total
		cout << "Total: " << total << endl;

		//Check if the charachter entered returns a valid result
		valid = InputData(operation, operand);

		//If char is either q or Q then the program will end
		if (operation == 'q' || operation == 'Q')
		{
			//Display message for good bye
			cout << "Good bye. Have a nice day!";

			//Change quit to true to end program
			quit = true;
		}

		//If the result from the function is valid
		else if (valid)
		{
			//function returns a double that is assigned to total
			total = calculate(total, operation, operand);
		}

	} while (quit == false);
	return 0;
}

/*******************************************************
Name            :   Help()
Arguments       :   None
Returns         :   None
Precondition    :   None
Postcondition   :   Display the calculator menu
*******************************************************/
void Help()
{
	cout << "Welcome to the Super Dooper Calculator(SDC).\n"
		<< "Usage:\n"
		<< "Enter the operator followed by the operand and the\n"
		<< "SDC will show you the accumulated total.\n"
		<< "Enter C to clear the contents.\n"
		<< "Enter Q to quit.\n"
		<< "You can use the following operators :\n"
		<< "+		add\n"
		<< "-		subtract\n"
		<< "*		multiply\n"
		<< "/		divide\n"
		<< "^		power\n"
		<< "t or T		Taxes\n"
		<< "c or C		clear total\n"
		<< "h or H		show help\n"
		<< "q or Q		quit\n\n";
}


/*******************************************************
Name            :   InputData(char& operation, double& operand)
Arguments       :   operation, operand
Returns         :   bool
Precondition    :   operation and operand must be declared
Postcondition   :   Pass by reference operand and operation 
*******************************************************/
bool InputData(char& operation, double& operand)
{
	//User inputs operation
	cin >> operation;
	
	//Switch case to check for valid char
	switch (operation)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
		case '>':
		case '<':
		case 't':
		case 'T':
			//Enter operand when valid operator is entered
			cin >> operand;
			return true;
			break;
		case 'c':
		case 'C':
		case 'h':
		case 'H':
		case 'q':
		case 'Q':
			operand = 0;
			return true;
			break;
		default:
			cout << "\aBad input: '" << operation << "' " << "is not a valid operator\n";
			cin.clear();
			cin.ignore(100, '\n');
			return false;
	}
}

/*******************************************************
Name            :   calculate(double total, char operation, double operand)
Arguments       :   total, operation, operand
Returns         :   double
Precondition    :   total, operation and operand passed by value
Postcondition   :   Returns the total double
*******************************************************/
double calculate(double total, char operation, double operand)
{
	//Switch to pass by value the operation and perform case function
	switch (operation)
	{
		case '+':
			total += operand;
			break;
		case '-':
			total -= operand;
			break;
		case '*':
			total *= operand;
			break;
		case '/':
			total /= operand;
			break;
		case '^':
			total = pow(total, operand);
			break;
		case '>':
			cout << boolalpha << calculate(total, operation, operand, 0) << endl;
			break;
		case '<':
			cout << boolalpha << calculate(total, operation, operand, 0) << endl;
			break;
		case 't':
		case 'T':
			total += ((operand / 100) * total);
			break;
		case 'c':
		case 'C':
			total = 0.000;
			break;
		case 'h':
		case 'H':
			Help();
			break;
		case 'q':
		case 'Q':
			cout << "Good bye. Have a nice day!";
			break;
		default:
			return false;
	}
	return total;
}

/*******************************************************
Name            :   calculate(double total, char operation, double operand, int i)
Arguments       :   total, operation, operand, i
Returns         :   bool
Precondition    :   total, operation and operand passed by value
Postcondition   :   Returns bool
*******************************************************/
bool calculate(double total, char operation, double operand, int i)
{
	//Test both '>' and '<' and respond with a boolean
	if (operation == '>')
	{
		if (total > operand)
		{
			return true;
		}
		else
			return false;
	}
	else if (operation == '<')
	{
		if (total < operand)
			return true;

		else
			return false;
	}
}
