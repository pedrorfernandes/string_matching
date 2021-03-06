//
//  stringAlgorithms.cpp
//  Strings
//
//  Created by pedro on 5/19/13.
//  Copyright (c) 2013 feup. All rights reserved.
//

#include "stringAlgorithms.h"

vector<int> StringAlgorithms::KMP(string S, string K)
{
    vector<int> T(K.size() + 1, -1);
    vector<int> matches;

    if(K.size() == 0)
    {
        matches.push_back(0);
        return matches;
    }
    for(unsigned int i = 1; i <= K.size(); i++)
    {
        int pos = T[i - 1];
        while(pos != -1 && K[pos] != K[i - 1]) pos = T[pos];
        T[i] = pos + 1;
    }

    int sp = 0;
    int kp = 0;
    while(sp < (int)S.size())
    {
        while(kp != -1 && (kp == (int)K.size() || K[kp] != S[sp])) kp = T[kp];
        kp++;
        sp++;
        if(kp == (int)K.size()) matches.push_back(sp - (int)K.size());
    }

    return matches;
}

// Boyer moore implementation in 
// http://www-igm.univ-mlv.fr/~lecroq/string/node14.html#SECTION0014

// Very interesting matching algorithm and analysis
// http://volnitsky.com/project/str_search/
