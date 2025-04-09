import random

# Initialize the board
board = [" " for _ in range(9)]

def print_board():
    print("\n")
    for i in range(3):
        print(" | ".join(board[i*3:(i+1)*3]))
        if i < 2:
            print("--+---+--")
    print("\n")

def player_move():
    while True:
        try:
            move = int(input("Choose your move (1-9): ")) - 1
            if board[move] == " ":
                board[move] = "X"
                break
            else:
                print("Oops! That spot is already taken 🪑")
        except (ValueError, IndexError):
            print("That’s not a valid move, friend 😅 Try a number between 1 and 9!")

def computer_move():
    print("Computer is thinking... 🤔")
    move = random.choice([i for i in range(9) if board[i] == " "])
    board[move] = "O"
    print("Computer chose position", move + 1)

def check_winner(symbol):
    win_positions = [
        (0, 1, 2), (3, 4, 5), (6, 7, 8),  # Rows
        (0, 3, 6), (1, 4, 7), (2, 5, 8),  # Columns
        (0, 4, 8), (2, 4, 6)              # Diagonals
    ]
    return any(all(board[i] == symbol for i in pos) for pos in win_positions)

def is_draw():
    return " " not in board

# Game loop
print("Welcome to Tic Tac Toe! 🎉 You are 'X', computer is 'O'")
print_board()

while True:
    player_move()
    print_board()
    if check_winner("X"):
        print("You win! 🏆 Are you a genius or just lucky?")
        break
    if is_draw():
        print("It's a draw! Great minds think alike 🤝")
        break

    computer_move()
    print_board()
    if check_winner("O"):
        print("Computer wins! 😢 But hey, rematch?")
        break
    if is_draw():
        print("It's a draw! Great minds think alike 🤝")
        break

