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
        << "1. Play hangman on easy diffuclty, " << std::endl
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

std::string convertString(std::string word, std::vector<std::string> &guessed_letters)
{
    std::string output = "";
    bool found_letter = false;
    for(int i = 0; i < word.length(); i++)
    {
        found_letter = false;
        if (guessed_letters.size() == 0)
        {
            output += "_";
        }
        else
        {
            for(int j = 0; j < guessed_letters.size(); j++)
            {
                if (guessed_letters[j][0] == word[i])
                {
                    found_letter = true;
                    break;
                }                
            }
            if(found_letter == false)
            {
                output += "_";
            }
            else
            {
                output += word[i];
            }
        }
    }
    return output;
}

bool letterInWord(std::string letter, std::string word)
{
    bool found = false;
    for (int i = 0; i < word.length(); i++)
    {
        if (letter[0] == word[i])
        {
            found = true;
        }
    }
    return found;
}

void playGame(std::string word_to_guess, int lives)
{
    std::vector<std::string> guessed_letters;
    std::string letter_guess = "";
    bool already_guessed = false;
    bool dead = false;
    bool word_found = false;
    
    while (true)
    {
        if (lives == 0)
        {
            dead = true;
            std::cout << "\nSorry you lost the word was: " << word_to_guess << "\n";
            break;
        }
        already_guessed = false;
        std::cout << "Word so far: ";
        std::cout << convertString(word_to_guess, guessed_letters) << "\n";
        std::cout << "Lives Left: " << lives << "\n";
        std::cout << "Letters Guessed so far: ";
        for(auto letter : guessed_letters)
        {
            std::cout << letter << ", ";
        }
        std::cout << "\n\n" << "What letter would you like to guess: ";
        std::cin >> letter_guess;
        for(auto letter: guessed_letters)
        {
            if (letter_guess == letter)
            {
                std::cout << "\nYou have already selected this letter please try again\n";
                already_guessed = true;
            }
        }
        if(!already_guessed)
        {
            guessed_letters.push_back(letter_guess);
            if(letterInWord(letter_guess, word_to_guess) == true)
            {
                std::cout << "\nThat letter is in the word, well done\n\n";
                std::string current_string = convertString(word_to_guess, guessed_letters);
                std::string place_holder = "_";
                word_found = true;
                for (int i = 0; i < current_string.length(); i++)
                {
                    if(current_string[i] == place_holder[0])
                    {
                        word_found = false;
                    }
                }
                if (word_found == true)
                {
                    std::cout << "Well done, you got the word: " << word_to_guess
                              << " you won with " << lives << ": lives left\n";
                    break;
                }
            }
            else
            {
                std::cout << "\nThat letter is not in the word \n\n";
                lives--;
            }
        }
    }
}

int main()
{
    printStart();
    int option = 0;
    bool play = true;
    std::string play_again;
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
                playGame(word, 8);
                break;
            }
            case 2:
            {
                std::cout << "\nOption 2 chosen\n";
                word = pickWord(option);
                playGame(word, 6);
                break;
            }
            case 3:
            {
                std::cout << "\nOption 3 chosen\n";
                word = pickWord(option);
                playGame(word, 4);
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
        std::cout << "Would you like to play again (y/n): ";
        std::cin >> play_again;
        if (play_again == "y" || play_again == "yes")
        {
            std::cout << "\n";
        }
        else
        {
            std::cout << "\nThank you for playing hangman :)\n";
            play = false;
        }
    }

}
