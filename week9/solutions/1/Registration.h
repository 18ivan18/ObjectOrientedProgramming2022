#ifndef REGISTRATION_H
#define REGISTRATION_H

class Registration
{
private:
    char reg[9];

    void validateBegininigOfReg(const char *);
    void validate(const char *);
    bool isUppercaseChar(char);
    bool isDigit(char);

public:
    Registration() = delete;
    Registration(const char *str);

    Registration &operator=(const char *str);
    bool operator==(const Registration &rhs) const;
    const char *toString() const;
};

#endif