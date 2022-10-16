/*
3 difficuties
easy:
    8 lives
Medium:
    6 lives
    "chosen", "fisherman", "attention", "pixel", "zombie", "rhythm", "jumper", "jogger"
Hard:
    4 lives
    "crypt", "embezzle", "voodoo", "oxidize", "wyvern", "sphinx", "hazard", "blizzard"

Input

· Start game
· Letter guesses (i.e., “a”, “b”, “c”)
· Quit game or Restart game

When a user wins/loses, 
the program should ask them if they want to play again. 
There should be an option to quit the program at this point. You should also include a start menu before the user begins the game.

Output
· Welcome to the program
· Word with _ as missing letters
· How many lives does the user have left?
· Would you like to play again?
*/

#include <iostream>
#include <vector>
#include <ctime>

void printStart()
{
    std::cout <<
" _    _                   _   __" << std::endl <<
"| |  | |                 |  \\/  |            " << std::endl <<
"| |__| | __ _ _ __   __ _| \\  / | __ _ _ __  " << std::endl <<
"|  __  |/ _` | '_ \\ / _` | |\\/| |/ _` | '_ \\ " << std::endl <<
"| |  | | (_| | | | | (_| | |  | | (_| | | | |" << std::endl <<
"|_|  |_|\\__,_|_| |_|\\__, |_|  |_|\\__,_|_| |_|" << std::endl <<
"                     __/ |                   " << std::endl <<
"                    |___/                    " << std::endl << std::endl;
    std::cout <<
"______         _ " << std::endl <<          
"| ___ \\       | | " << std::endl <<     
"| |_/ /_   _  | |    _   _  ___ _   _ " << std::endl <<
"| ___ \\ | | | | |   | | | |/ __| | | |" << std::endl <<
"| |_/ / |_| | | |___| |_| | (__| |_| |" << std::endl <<
"\\____/ \\__, | \\_____/\\__,_|\\___|\\__, |" << std::endl <<
"        __/ |                    __/ |" << std::endl <<
"       |___/                    |___/ " << std::endl << std::endl << std::endl;

}

void printMenu()
{
    std::cout << std::endl << "Welcome to Hangman: " << std::endl
        << "Would you like to: " << std::endl
        << "1. Play hangman on easy diffuclt, " << std::endl
        << "2. Play hangman on medium difficulty, " << std::endl
        << "3. Play hangman on hard difficulty. " << std::endl
        << "4. Quit" << std::endl
        << "Choice: ";
}

std::string pickWord(int difficulty)
{
    std::vector<std::string> words;
    switch (difficulty)
    {
        case 1:
        {
            words = {"apple", "car", "cheese", "cold", "wave", "boat", "heal", "four"};
            break;
        }
        case 2:
        {
            words = {"chosen", "fisherman", "attention", "pixel", "zombie", "rhythm", "jumper", "jogger"};
            break;
        }
        case 3:
        {
            words = {"crypt", "embezzle", "voodoo", "oxidize", "wyvern", "sphinx", "hazard", "blizzard"};
            break;
        }
    }
    std::srand(std::time(0));
    int randNum = rand() % words.size();
    return words[randNum];
}

int newGuess()
{
    std::cout << "Nothing for now";
}

void playGame(std::string word_to_guess)
{
    std::cout << "\n" << word_to_guess << "\n";
    std::vector<std::string> gussed_letters;
}

int main()
{
    printStart();
    int option = 0;
    bool play = true;
    std::string word = "";
    while(play == true)
    {
        printMenu();
        std::cin >> option;
        switch(option)
        {
            case 1:
            {
                std::cout << "\nOption 1 chosen\n";
                word = pickWord(option);
                playGame(word);
                break;
            }
            case 2:
            {
                std::cout << "\nOption 2 chosen\n";
                word = pickWord(option);
                playGame(word);
                break;
            }
            case 3:
            {
                std::cout << "\nOption 3 chosen\n";
                word = pickWord(option);
                playGame(word);
                break;
            }
            case 4:
            {
                std::cout << "\nThank you for playing hangman!\n";
                exit(0);
                break;
            }
            default:
            {
                std::cout << "\nSorry that is not a valid response, please retry";
                break;
            }
        }
    }

}
