#include "String.h"
#include <string>

int 
String::levenshtein_distance(const std::string &source, 
                             const std::string &target)
{
    // Levenshtein distance is a string metric for 
    // measuring the difference between two sequences. 
    // Informally, the Levenshtein distance between two words 
    // is the minimum number of single-character 
    // edits (insertion, deletion, substitution) required 
    // to change one word into the other
    //
    // This is a dynamic programming version with one array to memory the answer of sub-problem 
    if( source.empty()) 
        return target.length();
    if( target.empty() )
        return source.length();

    int *costs = new int[target.length() + 1];

    for( size_t k=0; k <= target.length(); k++ ) 
        costs[k] = k;

    int i = 0;
    for ( std::string::const_iterator it1 = source.begin(); it1 != source.end(); ++it1, ++i )
    {
        costs[0] = i+1;
        int corner = i;

        int j = 0;
        for ( std::string::const_iterator it2 = target.begin(); it2 != target.end(); ++it2, ++j )
        {
            int upper = costs[j+1];
            if( *it1 == *it2 )
            {
                costs[j+1] = corner;
            }
            else
            {
                int t = upper<corner ? upper : corner;
                costs[j+1] = (costs[j] < t ? costs[j] : t) + 1;
            }

            corner = upper;
        }
    }

    int result = costs[target.length()];
    delete [] costs;

    return result;
}

