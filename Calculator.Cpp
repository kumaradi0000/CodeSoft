#include <iostream>
using namespace std;
int main()
{
  double num1, num2;
  char operation;

  cout << "----------SIMPLE CALCULATOR----------\n";
  cout << "ENTER FIRST NUMBER: ";
  cin >> num1;

  cout << "ENTER SECOND NUMBER: ";
  cin >> num2;

  cout << "SELECT AN OPERATION ( +, -, *, / ): ";
  cin >> operation;

  double result;

  switch (operation)
  {
  case '+':
    result = num1 + num2;
    break;

  case '-':
    result = num1 - num2;
    break;

  case '*':
    result = num1 * num2;
    break;

  case '/':
    if (num2 != 0)
    {
      result = num1 / num2;
    }
    else
    {
      cout << "Error: Division by zero is not allowed." << endl;
      return 1; // RETURNS ERROR!!!
    }
    break;

  default:
    cout << "Error: Invalid operator. please insert valid operation(+, -, *, /)" << endl;
    return 1; // Exit with an error code!!
  }

  cout << "Result: " << result << endl;

  return 0; // Exit with a success code...
}
