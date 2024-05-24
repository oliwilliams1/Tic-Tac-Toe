#include <iostream>
using namespace std;

int grid[3][3] = { 0 };
int placementGrid[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

int print_grid(bool init)
{
    cout << (init ? "Placement Grid:\n" : "");
    for (int row = 0; row < 3; row++)
    {
        cout << "-------------\n| ";
        for (int col = 0; col < 3; col++)
        {
            int cellValue = grid[row][col];
            char cell = ' ';
            if (cellValue == 1)
            {
                cell = 'O';
            }
            else if (cellValue == 2)
            {
                cell = 'X';
            }
            if (init)
            {
                cout << placementGrid[row][col] << " | ";
            }
            else
            {
                cout << cell << " | ";
            }
        }
        cout << '\n';
    }
    cout << "-------------\n";
    if (init)
    {
        cout << '\n';
    }
    return 0;
}

int check_for_winner()
{
    for (int row = 0; row < 3; row++)
    {
        int c1 = grid[row][0];
        int c2 = grid[row][1];
        int c3 = grid[row][2];
        if (c1 == c2 && c1 == c3)
        {
            return c1;
        }
    }
    for (int col = 0; col < 3; col++)
    {
        int c1 = grid[0][col];
        int c2 = grid[1][col];
        int c3 = grid[2][col];
        if (c1 == c2 && c1 == c3)
        {
            return c1;
        }
    }
    int c1 = grid[0][0];
    int c2 = grid[1][1];
    int c3 = grid[2][2];
    if (c1 == c2 && c1 == c3)
    {
        return c1;
    }
    c1 = grid[0][2];
    c2 = grid[1][1];
    c3 = grid[2][0];
    if (c1 == c2 && c1 == c3)
    {
        return c1;
    }
    return 0;
}

bool is_input_valid(const std::string& x)
{
    if (x.length() != 1)
    {
        return false;
    }

    int xint = static_cast<int>(x[0]) - '0';
    xint--;
    int row = xint / 3;
    int col = xint % 3;

    if (xint < 0) 
    {
        return false;
    }

    if (grid[row][col] == 0)
    {
        return true;
    }
    else {
        return false;
    }
}

int ask_user_input(char player) {
    cout << player << "'s turn, enter move: ";
    bool valid = false;
    string output;
    while (!valid)
    { 
        cin >> output;
        valid = is_input_valid(output);
        if (!valid)
        {
            cout << "Incorrect input, try again for " << player << ": ";
        }
    }
    int outputInt = static_cast<int>(output[0] - '0');
    outputInt--;
    int row = outputInt / 3;
    int col = outputInt % 3;

    if (player == 'O') {
        grid[row][col] = 1;
    }
    else {
        grid[row][col] = 2;
    }
    return 0;

}

int won_message(int winnerInt) {
    cout << "KA PAI WINNER: " << (winnerInt == 1 ? "O" : "X") << "!!!!";
    return 0;
}

int main()
{
    bool running = true;
    int winner = 0;
    print_grid(true);
    int player = 0;
    char playerChar;
    while (running) {
        print_grid(false);
        playerChar = (player == 0 ? 'X' : 'O');
        ask_user_input(playerChar);
        winner = check_for_winner();
        if (winner != 0)
        {
            running = false;
            print_grid(false);
            won_message(winner);
        }
        player = (player == 0 ? 1 : 0);
    }
}