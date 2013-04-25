#include "String.h"
#include <string>
#include <iostream>

using namespace std;


int main(int argc, const char *argv[])
{
    string source = "rosettacode";
    string target = "raisethysword";

    if ( argc > 2 )
        source = argv[1], target = argv[2];

    int distance = String::levenshtein_distance(source,target);
    cout << "distance between " << source << " and " << target << " : " 
        << distance  << std::endl;
    double percent = 1.0 - double(distance)/target.length();
    cout << "similary percent = " << percent * 100 << "%\n";

    return 0;
}

