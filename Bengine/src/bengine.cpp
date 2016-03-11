#include "bengine.h"

QString Bengine::BENGINE_VERSION = "2.0.0";

Bengine::Bengine()
{
}

QString Bengine::getVersion()
{
    return BENGINE_VERSION;
}
