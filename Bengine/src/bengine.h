#ifndef BENGINE_H
#define BENGINE_H

#include <QString>

#include "bengine_global.h"

class BENGINESHARED_EXPORT Bengine
{

public:
    Bengine();

    static QString getVersion();

private:
    static QString BENGINE_VERSION;
};

#endif // BENGINE_H
