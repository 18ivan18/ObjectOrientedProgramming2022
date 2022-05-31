#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../../../../utils/doctest.h"
#include "SimpleEvent.h"
#include "EventWithFixedIntermission.h"
#include "EventWithIntermission.h"
#include "EventManager.h"

TEST_SUITE("Time")
{
    TEST_CASE("correctly validates time")
    {
        CHECK_THROWS(Time(-5));
        CHECK_THROWS(Time(25));
        CHECK_THROWS(Time(1, 67));
        CHECK_THROWS(Time(0, 0, 108));
    }

    TEST_CASE("correctly compares time")
    {
        CHECK(Time(1) < Time(2));
    }

    TEST_CASE("correctly adds time")
    {
        CHECK(Time(1) + Time(2) == Time(3));
        CHECK(Time(1, 15) + Time(2, 30) == Time(3, 45));
        CHECK(Time(1, 50) + Time(2, 30) == Time(4, 20));
    }

    TEST_CASE("correctly subtracts time")
    {
        CHECK_THROWS(Time(1) - Time(2));
        CHECK(Time(2) - Time(1, 30) == Time(0, 30));
        CHECK(Time(4, 10) - Time(2, 30) == Time(1, 40));
    }
}

TEST_SUITE("Event")
{
    TEST_CASE("can validate correctly when start time is after end time")
    {
        Event e(Time(12), Time(11));
        CHECK(e.getStart() == Time());
        CHECK(e.getEnd() == Time());
    }

    TEST_CASE("can validate correctly when start time is after end time")
    {
        Event e(Time(12), Time(13));
        CHECK(e.getStart() == Time(12));
        CHECK(e.getEnd() == Time(13));
    }
}

TEST_SUITE("Simple Event")
{
    TEST_CASE("can validate when start and end time are further than 2 hours apart")
    {
        SimpleEvent se(Time(11), Time(15));
        CHECK(se.getStart() == Time());
        CHECK(se.getEnd() == Time());
    }
}

TEST_SUITE("Event With Fixed Intermission")
{
    TEST_CASE("can validate when start is after intermission start")
    {
        EventWithFixedIntermission ewfi(Time(11), Time(10), Time(15));
        CHECK(ewfi.getStart() == Time());
        CHECK(ewfi.getEnd() == Time());
        CHECK(ewfi.getIntermissionStart() == Time());
    }

    TEST_CASE("can validate when intermission start +20mins is after end")
    {
        EventWithFixedIntermission ewfi(Time(11), Time(10), Time(15));
        CHECK(ewfi.getStart() == Time());
        CHECK(ewfi.getEnd() == Time());
        CHECK(ewfi.getIntermissionStart() == Time());
    }
}

TEST_SUITE("Event With Intermission")
{
    TEST_CASE("can validate when the event is longer than 6 hours")
    {
        EventWithIntermission ewi(Time(1), Time(2), Time(3), Time(10));
        CHECK(ewi.getStart() == Time());
    }

    TEST_CASE("can instantiate a valid event")
    {
        EventWithIntermission ewi(Time(20, 30), Time(21, 30), Time(22, 10), Time(23, 30));
        CHECK(ewi.getStart() == Time(20, 30));
    }

    TEST_CASE("can validate when intermission is longer than 1h or shorter than 30min")
    {
        EventWithIntermission ewi(Time(1), Time(2), Time(5), Time(6));
        CHECK(ewi.getStart() == Time());
        EventWithIntermission ewi30(Time(22, 15), Time(22, 45), Time(23), Time(23, 30));
        CHECK(ewi30.getStart() == Time());
    }
}

TEST_SUITE("Event Manager")
{
    TEST_CASE("can add events")
    {
        EventManager em(2);
        CHECK(em.addEvent(new Event(Time(22, 30), Time(23, 30))));
        CHECK(em.addEvent(new SimpleEvent(Time(22, 30), Time(23, 30))));
        CHECK(!em.addEvent(new EventWithFixedIntermission(Time(22, 30), Time(23, 15), Time(23, 30))));
    }

    TEST_CASE("can find number of ongoing events")
    {
        EventManager em(3);
        em.addEvent(new Event(Time(22, 30), Time(23, 10)));
        em.addEvent(new SimpleEvent(Time(21, 30), Time(23, 30)));
        em.addEvent(new EventWithFixedIntermission(Time(22, 30), Time(23, 15), Time(23, 50)));
        CHECK(em.ongoingEvents(Time(23, 15)) == 1);
    }
}