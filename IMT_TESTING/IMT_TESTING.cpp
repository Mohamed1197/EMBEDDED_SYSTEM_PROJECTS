//- Copyright (c) 2008-2013 James Grenning --- All rights reserved
//- For exclusive use by participants in Renaissance Software Consulting training courses.
//- Cannot be used by attendees to train others without written permission.
//- www.renaissancesoftware.net james@renaissancesoftware.net
#include <stdio.h>
#include <stdlib.h>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTestExt/MockSupport.h"

extern "C"
{
#include "Example.h"
}

TEST_GROUP(Example)
{
    void setup()
    {
    }

    void teardown()
    {
    }
};

TEST(Example, returns_1)
{
    LONGS_EQUAL(5,Add(3 + 2));
}



int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}

