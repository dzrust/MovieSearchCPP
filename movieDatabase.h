#ifndef MOVIE_DATABASE_H
#define MOVIE_DATABASE_H

#include "movie.h"

#include <vector>
#include <string>

using namespace std;

/**
 * The master list of all research topics, organized
 * by their research plans.
 */
class MovieDatabase
{
public:
    MovieDatabase();
    void LoadDatabase(istream &input);
    vector<Movie> GetMoviesFromInput(string input) const;
    void AddMovieToDatabase(Movie mov);

private:
    vector<Movie> movieDatabase;
    static std::vector<std::string> Split(const std::string &str, char delimiter);
    static int ParseInteger(const std::string &str);
};

#endif