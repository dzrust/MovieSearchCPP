#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <vector>

using namespace std;

/**
 * The movie to be searched for
 */
class Movie
{
public:
    Movie();
    Movie(string tconst,
          string titleType,
          string primaryTitle,
          string originalTitle,
          bool isAdult,
          int startYear,
          int endYear,
          int runtimeMinutes,
          vector<string> genres);

    string GetPrimaryTitle() const;
    string GetPrimaryTitleLowercase() const;

private:
    string tconst;
    string titleType;
    string primaryTitle;
    string originalTitle;
    bool isAdult;
    int startYear;
    int endYear;
    int runtimeMinutes;
    vector<string> genres;
};

ostream &operator<<(std::ostream &out, const Movie &mov);

#endif