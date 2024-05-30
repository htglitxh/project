//tic tac toe game with markers O and X
#include <iostream>
using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char current_marker;
int current_player;

void drawBoard() {
    cout << "-------------\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "|";
        for (int j = 0; j < SIZE; j++) {
            cout << " " << board[i][j] << " |";
        }
        cout << "\n-------------\n";
    }
}

bool placeMarker(int slot) {
    int row = (slot - 1) / SIZE;
    int col = (slot - 1) % SIZE;
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = current_marker;
        return true;
    }
    return false;
}

int winner() {
    // Rows
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return current_player;
    }
    // Columns
    for (int i = 0; i < SIZE; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return current_player;
    }
    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return current_player;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return current_player;
    return 0;
}

void swapPlayerAndMarker() {
    if (current_marker == 'X')
        current_marker = 'O';
    else
        current_marker = 'X';
    
    if (current_player == 1)
        current_player = 2;
    else
        current_player = 1;
}

void game() {
    cout << "Player 1, choose your marker: ";
    char marker_p1;
    cin >> marker_p1;
    
    current_player = 1;
    current_marker = marker_p1;
    
    drawBoard();
    
    int player_won;
    
    for (int i = 0; i < SIZE * SIZE; i++) {
        cout << "It's player " << current_player << "'s turn. Enter your slot: ";
        int slot;
        cin >> slot;
        
        if (slot < 1 || slot > 9) {
            cout << "Invalid slot! Try again.\n";
            i--;
            continue;
        }
        
        if (!placeMarker(slot)) {
            cout << "That slot is occupied! Try another slot!\n";
            i--;
            continue;
        }
        
        drawBoard();
        
        player_won = winner();
        
        if (player_won == 1) {
            cout << "Player 1 won! Congratulations!\n";
            break;
        }
        if (player_won == 2) {
            cout << "Player 2 won! Congratulations!\n";
            break;
        }
        
        swapPlayerAndMarker();
    }
    
    if (player_won == 0)
        cout << "It's a tie game!\n";
}

int main() {
    game();
    return 0;
}
