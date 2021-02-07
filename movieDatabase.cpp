#include "movieDatabase.h"

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

MovieDatabase::MovieDatabase()
{
}

void MovieDatabase::LoadDatabase(istream &input)
{
    string line;
    getline(input, line);
    while (input)
    {
        vector<string> parts = Split(line, '\t');
        if (parts.size() != 9 || parts[0] == "tconst")
        {
            getline(input, line);
            continue;
        }
        AddMovieToDatabase(Movie(
            parts[0],
            parts[1],
            parts[2],
            parts[3],
            parts[4] == "1",
            ParseInteger(parts[5]),
            ParseInteger(parts[6]),
            ParseInteger(parts[7]),
            Split(parts[8], ',')));
        getline(input, line);
    }
}

void MovieDatabase::AddMovieToDatabase(Movie mov)
{
    movieDatabase.push_back(mov);
}

vector<Movie> MovieDatabase::GetMoviesFromInput(string input) const
{
    vector<Movie> moviesFound;
    for (auto movie : movieDatabase)
    {
        if (movie.GetPrimaryTitleLowercase().find(input) != string::npos)
        {
            moviesFound.push_back(movie);
        }
    }
    return moviesFound;
}

vector<string> MovieDatabase::Split(const string &str, char delimiter)
{
    vector<string> results;
    string::size_type start = 0;
    while (start != string::npos)
    {
        string::size_type splitPos = str.find(delimiter, start);
        if (splitPos == string::npos)
        {
            results.push_back(str.substr(start));
            start = splitPos;
        }
        else
        {
            results.push_back(str.substr(start, splitPos - start));
            start = splitPos + 1;
        }
    }
    return results;
}

int MovieDatabase::ParseInteger(const string &str)
{
    if (str == "\\N") {
        return -1;
    } else {
        return stoi(str);
    }
}