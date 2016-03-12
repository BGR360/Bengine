#include "bengine.h"

/*!
    \class Bengine
    \brief The Bengine class provides some useful functions related to the Game Engine.
    \inmodule Core
*/

QString Bengine::BENGINE_VERSION = "2.0.0";

/*!
 * \internal
 */
Bengine::Bengine()
{
}

/*!
 * \brief Returns the current version of the engine as a QString.
 */
QString Bengine::getVersion()
{
    return BENGINE_VERSION;
}
