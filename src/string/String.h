
#ifndef _STRING_H_
#define _STRING_H_

#include <string>

class String 
{
public:
    String();
    virtual ~String();

    static int levenshtein_distance(const std::string &source, 
                                    const std::string &target);

};

#endif
