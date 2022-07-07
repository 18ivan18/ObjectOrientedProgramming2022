#ifndef KNYAML_SPEC_H
#define KNYAML_SPEC_H
#include "SimplePair.h"
#include "ResizeableSet.h"
#include <vector>

class KNYAMLSpec : public ResizeableSet<SimplePair *>
{
private:
    void free();
    bool remove(int idx);
    int find(SimplePair *const &elem) override;

public:
    KNYAMLSpec(std::vector<SimplePair *> pairs);
    KNYAMLSpec(const KNYAMLSpec &other);
    KNYAMLSpec &operator=(const KNYAMLSpec &rhs);
    ~KNYAMLSpec();

    void operator[](const std::string &key);
    bool remove(SimplePair *const &el) override;
    bool remove(const std::string &key);
};

#endif