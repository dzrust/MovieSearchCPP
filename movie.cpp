#include "movie.h"

#include <string>
#include <vector>
#include <algorithm>
#include <ostream>

using namespace std;

/**
 * The movie to be searched for
 */

Movie::Movie()
    : tconst(""), titleType(""), primaryTitle(""),
      originalTitle(""), isAdult(false), startYear(0),
      endYear(0), runtimeMinutes(0), genres(vector<string>())
{
}

Movie::Movie(string tconst,
             string titleType,
             string primaryTitle,
             string originalTitle,
             bool isAdult,
             int startYear,
             int endYear,
             int runtimeMinutes,
             vector<string> genres)
    : tconst(tconst), titleType(titleType), primaryTitle(primaryTitle),
      originalTitle(originalTitle), isAdult(isAdult), startYear(startYear),
      endYear(endYear), runtimeMinutes(runtimeMinutes), genres(genres)
{
}

string Movie::GetPrimaryTitle() const
{
    return primaryTitle;
}

string Movie::GetPrimaryTitleLowercase() const
{
    string lowerCaseTitle = primaryTitle;
    std::for_each(lowerCaseTitle.begin(), lowerCaseTitle.end(), [](char &c) {
        c = ::tolower(c);
    });
    return lowerCaseTitle;
}

ostream &operator<<(std::ostream &out, const Movie &mov)
{
    out << mov.GetPrimaryTitle() << endl;
    return out;
}