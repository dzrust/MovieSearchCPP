#include "movieDatabase.h"

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string userInput;
    MovieDatabase movieDatabase;
    cout << "Loading Database" << endl;
    std::ifstream input("title.basics.first1000", std::ios::binary);
    movieDatabase.LoadDatabase(input);
    cout << "Database Loaded" << endl;
    do
    {
        cout << "Please enter in at least three symbols for a movie to search for (/q to quit)" << endl;
        getline(cin, userInput);
        std::for_each(userInput.begin(), userInput.end(), [](char &c) {
            c = ::tolower(c);
        });
        if (userInput == "/q")
            continue;
        if (userInput.length() < 3)
        {
            cout << "You must enter in at least three symbols" << endl;
        }
        else
        {
            // find movie titles and return them in the format {movieTitle} ;; {movieTitle}
            auto movies = movieDatabase.GetMoviesFromInput(userInput);
            if (movies.size() == 0)
            {
                cout << "No results found" << endl;
            }
            for (auto movie : movies)
            {
                cout << movie;
            }
            cout << endl << "Found: " << movies.size() << " results" << endl;
        }
    } while (userInput != "/q");
}