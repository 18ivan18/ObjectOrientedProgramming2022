#include <cassert>
#include "InterpolationPair.h"
#include "TagPair.h"
#include "ComplexPair.h"
#include "KNYAML.h"
#include <iostream>

void testSimplePair()
{
    try
    {
        SimplePair sp("Key", "Value");
        assert(("Key cannot start contain capital letters", false));
    }
    catch (const std::exception &e)
    {
        // std::cerr << e.what() << '\n';
        assert(true);
    }

    try
    {
        SimplePair sp("asd_basd", "Value");
        assert(true);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        assert(false);
    }
}

void testInterpolationPair()
{
    try
    {
        InterpolationPair ip("asd_basd", "My name is %{username}");
        ip.printValue();
        assert(true);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        assert(false);
    }

    try
    {
        InterpolationPair ip("asd_basd", "My name is ");
        assert(("Value must contain interpolation string", false));
    }
    catch (const std::exception &e)
    {
        assert(true);
    }

    try
    {
        InterpolationPair ip("asd_basd", "My name is %{first} %{second}");
        ip.printValue();
    }
    catch (const std::exception &e)
    {
        assert(("Can contain more than one interpolation strings", false));
    }

    try
    {
        InterpolationPair ip("asd_basd", "My name is %{name} %{name}");
        assert(("Interpolations must be unique", false));
    }
    catch (const std::exception &e)
    {
        assert(true);
    }

    try
    {
        InterpolationPair ip("asd_basd", "My name is %{}");
        assert(("Value must contain interpolation string", false));
    }
    catch (const std::exception &e)
    {
        assert(true);
    }

    try
    {
        InterpolationPair ip("asd_basd", "My name is %{USERNAME}");
        assert(("Interpolation string must be lower cased", false));
    }
    catch (const std::exception &e)
    {
        assert(true);
    }
}

void testTagPair()
{
    try
    {
        TagPair tp("greeting_html", "\"How are <b>you?</b> <br/> <hr/>\"");
        tp.printValue();
    }
    catch (const std::exception &e)
    {
        assert(("Tag Pair is valid", false));
    }

    try
    {
        TagPair tp("ml", "\"How are <b>you?</b> <br/> <hr/>\"");
    }
    catch (const std::exception &e)
    {
        assert(true);
    }

    try
    {
        TagPair tp("greeting_html", "How are <b>you?</b> <br/> <hr/>\"");
    }
    catch (const std::exception &e)
    {
        assert(true);
    }
}

void testComplexPair()
{
    try
    {
        ComplexPair cp("sth_html", "\"How are <b>you?</b>, %{name} <br/> <hr/>\"");
        cp.printValue();
    }
    catch (const std::exception &e)
    {
        assert(false);
    }

    try
    {
        ComplexPair cp("sth_html", "\"How are <b>you?</b>, %{name1} <br/> <hr/>\"");
    }
    catch (const std::exception &e)
    {
        assert(true);
    }
}

void testKNYAML()
{
    try
    {
        KNYAML knyaml({new TagPair("greeting_html", "\"How <b>you</b> doin' </br><br/> <hr/>\"")});
        knyaml["greeting_html"];
    }
    catch (const std::exception &e)
    {
        assert(false);
    }
}

void runAllTests()
{
    testSimplePair();
    testInterpolationPair();
    testTagPair();
    testComplexPair();
    testKNYAML();
}