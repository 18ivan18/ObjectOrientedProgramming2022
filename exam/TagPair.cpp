#include "TagPair.h"

TagPair::TagPair(const std::string &key, const std::string &value) : SimplePair(key, value)
{
    validate();
}

void TagPair::validate()
{
    if (value.front() != '"' || value.back() != '"')
    {
        // value must start and end with ""
        throw std::exception();
    }
    if (key.substr(key.length() - 5, 5) != "_html")
    {
        // key must end with _html
        throw std::exception();
    }
}
std::string TagPair::replaceTags(const std::string &value)
{
    std::string output;
    const int dashSize = 20;
    const std::string br = "<br/>", hr = "<hr/>", b = "<b>", bClosing = "</b>";
    std::vector<TextProcessor::Tag> tags = TextProcessor(b, bClosing).getAllTags(value);
    int tagsIndex = 0;
    for (size_t i = 0; i < value.size(); i++)
    {
        if (i < value.size() - br.size() && value.substr(i, br.size()) == br)
        {
            output += '\n';
            i += br.size() - 1;
            continue;
        }
        if (i < value.size() - hr.size() && value.substr(i, hr.size()) == hr)
        {
            for (size_t i = 0; i < dashSize; i++)
            {
                output += '-';
            }

            i += hr.size() - 1;
            continue;
        }
        if (tagsIndex < tags.size() && i == tags[tagsIndex].startIndex)
        {
            i += b.size();
            while (i != tags[tagsIndex].endIndex)
            {
                output += TextProcessor::toupper(value[i++]);
            }
            i += bClosing.size() - 1;
            tagsIndex++;
            continue;
        }
        output += value[i];
    }
    return output;
}

void TagPair::printValue()
{
    std::cout << replaceTags(value) << '\n';
}

SimplePair *TagPair::clone()
{
    return new TagPair(*this);
}
