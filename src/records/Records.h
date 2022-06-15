#ifndef GUESSTHEPATH_RECORDS_H
#define GUESSTHEPATH_RECORDS_H


#include <vector>
#include "Record.h"

class Records {
public:
    Records(std::string dataFilename);

    virtual ~Records();

    void readFromFile();
    void writeToFile();

    const std::vector<Record *> &getValues() const;

    bool addValue(Record *rec);

    std::string username = "Player";
protected:
    int maxValues = 10;
    std::string filename = "";
    std::vector<Record*> values;
    void sort();
};


#endif //GUESSTHEPATH_RECORDS_H
