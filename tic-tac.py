#!/usr/bin/env python3

import random
import os

# GLOBALS
board = [1, 2, 3, 4, 5, 6, 7, 8, 9]
slots_filled = 0
players = ["A", "B"]
player_input = None
current_player = random.choice(players)

# displays
def display_board():
    """
        Function that displays the board in..., 
        
        1 2 3
        4 5 6
        7 8 9

        ^ that format
    """

    for i in range(9):

        if i == 2 or i == 5:
            end_ = "\n\n--------------------------\n\n"

        elif i == 8:
            end_ = "\n"

        else:
            end_ = "     |     "

        print(f"{board[i]}", end=end_)

    print()

def display_current_player():
    """
        function that displays current player
    """

    print()

    if current_player == players[0]:
        print(f">>>>>>> PLAYER {current_player}'s TURN <<<<<<<")
    else:
        print(f"<<<<<<< PLAYER {current_player}'s TURN >>>>>>>")

def clear_screen():
    """
        the system() is a posix system call function 
        that handles creating a new process and running the
        command passed to it like we are running it on the command
        line directly and here we pass in the "clear" command
        if the OS is windows or "cls" command if it is linux or 
        other OS

        The "cls" or "clear" command clears the screen
    """

    os.system("cls" if os.name == "nt" else "clear")

# Take player's input and...,
# first, check if input is valid
def input_validator_and_board_updator(inp):
    """
        This validates user's or players' input to make 
        sure that they have entered the correct inputs
        and also check if player decides to quit or end the game

        If the input is correct, then it is used to update the board
        by calling the update_board() function
    """

    global player_input

    if not inp or inp.lower() == 'q':
        exit(0)

    player_input = int(inp) - 1
    if player_input < 0 or player_input > 8:
        clear_screen()
        print("PLESE SELECT THE RIGHT OPTION!\n")
        display_board()
        display_current_player()
        player_input = input("Make your move[0 - 9] (Q to quit game) => ")
        input_validator_and_board_updator(player_input)
    else:
        update_board()

# second, check if play slot is still availabale
def update_board():
    """
        This fucntion first check if the slot player had
        selected is not occupied yet, if it hasn't, then 
        it update the slot with the current player symbol
    """

    global player_input
    global slots_filled

    slot = player_input
    if board[slot] != slot + 1:
        clear_screen()
        print(f"Slot {slot + 1} is already occupied by {'YOU' if board[slot] == current_player else 'your OPPONENT'}, verify your move\n")
        display_board()
        display_current_player()
        player_input = input("Make your move[0 - 9] (Q to quit game) => ")
        input_validator_and_board_updator(player_input)

    else:
        board[slot] = current_player
        slots_filled += 1


# third, check for win cases
def check_tie_win_case():
    """
     Checks Horizontal win case
            --->
           1 2 3
           4 5 6
           7 8 9
    """
    pl = current_player
    if board[0] == pl and board[1] == pl and board[2] == pl or\
            board[3] == pl and board[4] == pl and board[5] == pl or\
            board[3] == pl and board[4] == pl and board[5] == pl:
        return True

    """
     Checks Vertical
        |   1 2 3
        |   4 5 6
        V   7 8 9
    """
    if board[0] == pl and board[3] == pl and board[6] == pl or\
            board[1] == pl and board[4] == pl and board[7] == pl or\
            board[2] == pl and board[5] == pl and board[8] == pl:
        return True

    """
     Checks Diagonal
     '\' and '/'
        1 2 3   
        4 5 6
        7 8 9
    """
    if board[0] == pl and board[4] == pl and board[8] == pl or\
            board[2] == pl and board[4] == pl and board[6] == pl:
        return True

    """
        checks Tie  
    """
    if slots_filled == 9:
        return "Tied"

    return False


# if third is false, switch player
def switch_player():
    """
        Handles the switch of players after each turn
        or round
    """

    global current_player

    if current_player == players[0]:
        current_player = players[1]
    else:
        current_player = players[0]


def game_control(check):
    """
        This function handles players' decision whether
        to continue playing or quit after a Tie or Win
    """

    if check == "Tied":

        clear_screen()
        print("GAME TIED")
        decision = None
        while decision == None:
            decision = input("Press [r] to restart and [q] to quit => ")
            if decision.lower() == 'q':
                exit(0)
            elif decision.lower() == 'r':
                game_reset()
            else:
                decision = None

    elif check == True:

        clear_screen()
        print(f"PLAYER {current_player} WON")
        decision = None
        while decision == None:
            decision = input("Press [r] to restart and [q] to quit => ")
            if decision.lower() == 'q':
                exit(0)
            elif decision.lower() == 'r':
                game_reset()
            else:
                decision = None


def game_reset():
    """
        This resets the game to give a clean
        game board
    """

    global board, slots_filled, current_player

    board = [1, 2, 3, 4, 5, 6, 7, 8, 9]
    slots_filled = 0
    current_player = random.choice(players)


def game_engine():
    """
        The game's engine because it handles the game loop
        until a player decides to stop playing
    """

    global player_input

    while True:
        clear_screen()

        display_board()
        display_current_player()

        player_input = input("Make your move[0 - 9] (Q to quit game) => ")
        input_validator_and_board_updator(player_input)

        check = check_tie_win_case()
        if check == False:
            switch_player()
        else:
            game_control(check)


welcome_note = """
\t =============================
\t| ARE YOU READY TO TIC & TAC? |
\t =============================

GAME RULES:

1. A player wins if they have three of their symbols in a row (horizontally, vertically, or diagonally)

2. If all cells are filled and no player has three symbols in a row, the game is a Tie.

STRATEGY:

When playing, try to block your opponent from creating a winning line while also working on your own winning moves.

"""


def welcome():
    """
        Handles the opening details of the game and a brief
        introduction to the game    
    """

    print(welcome_note)

    play = input("Press 'S' to start game or 'Q' to quit => ")

    while play.lower() != 's' and play.lower() != 'q':
        print("\nEnter the right input")
        play = input("Press 'S' to start game or 'Q' to quit => ")

    if play.lower() == 's':
        game_engine()

    if play.lower() == 'q':
        exit(0)


welcome()
