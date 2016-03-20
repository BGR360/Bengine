#include "bdebugtest.h"

#include <core/bdebug.h>

BDebugTest::BDebugTest()
{

}

void BDebugTest::debug()
{
    B_DEBUG("Debug message");
}

void BDebugTest::info()
{
    B_INFO("Informational message");
}

void BDebugTest::warn()
{
    B_WARN("Recoverable error");
}

void BDebugTest::critical()
{
    B_CRITICAL("Critical error");
}
