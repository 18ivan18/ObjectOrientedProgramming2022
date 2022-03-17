#ifndef TASK_1_RECORD
#define TASK_1_RECORD

class Record
{
private:
    char *word;
    char *meaning;

public:
    void init(const char *word, const char *meaning);
    Record copy() const;
    void print() const;
    char *getWord() const;
    char *getMeaning() const;
    void deleteDynamic();
};

#endif