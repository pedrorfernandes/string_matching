//  result.h
//
//  Projeto 2 CAL
//
//  Turma 1 Grupo D
//
//  ei11089 - Diogo Santos
//  ei11122 - Pedro Fernandes
//  ei11132 - Daniel Pereira
//

#ifndef _result_h
#define _result_h

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "match.h"
#include "parser.h"
#include "stringAlgorithms.h"

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
		( std::ostringstream() << std::dec << x ) ).str()

#define SAME_LINE_BONUS 20

#define MATCH_DISPLAY_FORMAT "%-14s | %-6s | %-6s\n"
#define MATCH_DISPLAY_FORMAT_RESULT "%-14s | %-6d | %-6s\n"

using namespace std;

/**
 * A result holds all the matches found for a given query with keywords.
 */
class Result {
private:
	string query; /**< Keywords of the query */
	vector<Match> matches; /**< Matches found for all the keywords */

public:
	/**
	 * Constructor for result.
	 * @param query The keywords of the query.
	 */
	Result(string query);

	/**
	 * @return Returns the query (keywords of the search).
	 */
	string getQuery() const;

	/**
	 * @return Returns the exact keyword matches found for the given query.
	 */
	int getExactMatches() const;

	/**
	 * @return Returns the partial keyword matches found for the given query.
	 */
	int getPartialMatches() const;

	/**
	 * @return The score total of all the keyword matches found.
	 */
	int getMatchScore() const;

	/**
	 * Adds a new matching found word to this result.
	 * @param newMatch The new match.
	 */
	void addMatch(Match newMatch);

	/**
	 * @return All the found matching words.
	 */
	vector<Match> getMatches();

	/**
	 * Checks if the given word exists in the ignore list and is to be ignored.
	 * @param word The word to search for in the ignore list.
	 * @return True if the word is in the ignore list, false if not.
	 */
	bool isIgnoredWord(string word);

	/**
	 * This function will analyze all the matches found and check which are the ones that are located in the same line and are different. For example, if we have keywords "traffic systems" and we find the match "traffic" and "system" in the same line, this is a good line match.
	 * @return A vector for each line containing vectors with each keyword found.
	 */
	vector<vector<Match> > getSameLineMatches() const;

	/**
	 * Prints the result's matches information in an easily readable way.
	 */
	void printMatches();

};

#endif
