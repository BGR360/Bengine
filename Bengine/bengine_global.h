#ifndef BENGINE_GLOBAL_H
#define BENGINE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(BENGINE_LIBRARY)
#  define BENGINESHARED_EXPORT Q_DECL_EXPORT
#else
#  define BENGINESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // BENGINE_GLOBAL_H
