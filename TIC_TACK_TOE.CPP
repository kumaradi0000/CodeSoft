#include <iostream>
#include <ctime>
#include <random>

using namespace std;

char table[9] = {
    ' ',
    ' ',
    ' ',
    ' ',
    ' ',
    ' ',
    ' ',
    ' ',
    ' ',
};
void show_table();
void get_X_player_choice();
void get_O_player_choice();
void get_computer_choice();
int count_table(char symbol);
char check_winner();
void computer_vs_player();
void player_vs_player();

int main()
{
  cout << "---------TIC TAC TOE GAME--------- ";
  cout << endl;
  int mode;
  cout << "1. Computer Vs Player." << endl;
  cout << "2. Player Vs Player." << endl;
  cout << "Select Game Mode." << endl;
  cin >> mode;
  switch (mode)
  {
  case 1:
    computer_vs_player();
    break;
  case 2:
    player_vs_player();
    break;

  default:
    cout << "Please Select Valid Game Mode." << endl;
    break;
  }
  return 0;
}
void computer_vs_player()
{
  string player_name;
  cout << "Enter Your Name: ";
  cin >> player_name;
  while (true)
  {
    system("cls");
    show_table();
    if (count_table('X') == count_table('O'))
    {
      cout << player_name << "'s Turn." << endl;
      get_X_player_choice();
    }
    else
    {
      get_computer_choice();
    }
    char winner = check_winner();
    if (winner == 'X')
    {
      system("cls");
      show_table();
      cout << player_name << " Won the Game." << endl;
      break;
    }
    else if (winner == 'O')
    {
      system("cls");
      show_table();
      cout << "Computer Won The Game." << endl;
      break;
    }
    else if (winner == 'D')
    {
      cout << "Game is Draw." << endl;
      break;
    }
  }
}
void get_computer_choice()
{
  srand(time(0));
  int choice;
  do
  {
    choice = rand() % 10;
  } while (table[choice] != ' ');
  table[choice] = 'O';
}
void get_X_player_choice()
{
  while (true)
  {
    cout << "Select Your Position (1-9): ";
    int choice;
    cin >> choice;
    choice--;
    if (choice < 0 || choice > 8)
    {
      cout << "Invalid Choice. Try Again!" << endl;
    }
    else if (table[choice] != ' ')
    {
      cout << "Please Select An Empty Position." << endl;
    }
    else
    {
      table[choice] = 'X';
      break;
    }
  }
}

void get_O_player_choice()
{
  while (true)
  {
    cout << "Select Your Position (1-9): ";
    int choice;
    cin >> choice;
    choice--;
    if (choice < 0 || choice > 8)
    {
      cout << "Invalid Choice. Try Again!" << endl;
    }
    else if (table[choice] != ' ')
    {
      cout << "Please Select An Empty Position." << endl;
    }
    else
    {
      table[choice] = 'O';
      break;
    }
  }
}

void player_vs_player()
{
  string X_player_name, O_Player_name;
  cout << "Enter X Player Name: ";
  cin >> X_player_name;
  cout << "Enter O Player Name: ";
  cin >> O_Player_name;
  while (true)
  {
    system("cls");
    show_table();
    if (count_table('X') == count_table('O'))
    {
      cout << X_player_name << "'s Turn." << endl;
      get_X_player_choice();
    }
    else
    {
      cout << O_Player_name << "'s Turn." << endl;
      get_O_player_choice();
    }
    char winner = check_winner();
    if (winner == 'X')
    {
      system("cls");
      show_table();
      cout << X_player_name << " Won the Game." << endl;
      break;
    }
    else if (winner == 'O')
    {
      system("cls");
      show_table();
      cout << O_Player_name << " Won the Game." << endl;
      break;
    }
    else if (winner == 'D')
    {
      cout << "Game is Draw." << endl;
      break;
    }
  }
}
int count_table(char symbol)
{
  int total = 0;
  for (int i = 0; i < 9; i++)
  {
    if (table[i] == symbol)
      total += 1;
  }
  return total;
}

char check_winner()
{
  // checking winner in horizontal.
  if (table[0] == table[1] && table[1] == table[2] && table[0] != ' ')
    return table[0];
  if (table[3] == table[4] && table[4] == table[5] && table[3] != ' ')
    return table[3];
  if (table[6] == table[7] && table[7] == table[8] && table[6] != ' ')
    return table[6];
  // checking winner in vertical column.
  if (table[0] == table[3] && table[3] == table[6] && table[0] != ' ')
    return table[0];
  if (table[1] == table[4] && table[4] == table[7] && table[1] != ' ')
    return table[1];
  if (table[2] == table[5] && table[5] == table[8] && table[2] != ' ')
    return table[2];
  // checking winner in diagonal.
  if (table[0] == table[4] && table[4] == table[8] && table[0] != ' ')
    return table[0];
  if (table[2] == table[4] && table[4] == table[6] && table[2] != ' ')
    return table[2];
  if (count_table('X') + count_table('O') < 9)
    return 'C';
  else
    return 'D';
}

void show_table()
{
  cout << "   "
       << "    |   "
       << "    |   " << endl;
  cout << "   " << table[0] << "   |   " << table[1] << "   |   " << table[2] << endl;
  cout << "   "
       << "    |   "
       << "    |   " << endl;
  cout << "  --------------------" << endl;

  cout << "   "
       << "    |   "
       << "    |   " << endl;
  cout << "   " << table[3] << "   |   " << table[4] << "   |   " << table[5] << endl;
  cout << "   "
       << "    |   "
       << "    |   " << endl;
  cout << "  --------------------" << endl;
  cout << "   "
       << "    |   "
       << "    |   " << endl;
  cout << "   " << table[6] << "   |   " << table[7] << "   |   " << table[8] << endl;
  cout << "   "
       << "    |   "
       << "    |   " << endl;
}
