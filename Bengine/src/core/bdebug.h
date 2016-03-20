#ifndef BDEBUG_H
#define BDEBUG_H

/* ---------------------------------------------------------------------------------- *
 * Credit to Brian C. Milco and his blog post which provided some of this code.       *
 * http://brianmilco.blogspot.com/2011/11/color-debug-output-with-qt-and-qdebug.html  *
 * ---------------------------------------------------------------------------------- */

#include <QDebug>

#define B_DEBUG(message) \
( \
    (qDebug() << Q_FUNC_INFO << ":" << QString(message).toStdString().c_str()), \
    (void)0 \
)

#define B_WARN(message) \
( \
    (qWarning() << Q_FUNC_INFO << ":" << QString(message).toStdString().c_str()), \
    (void)0 \
)

#define B_CRITICAL(message) \
( \
    (qCritical() << Q_FUNC_INFO << ":" << QString(message).toStdString().c_str()), \
    (void)0 \
)

#define B_FATAL(message) \
( \
    (qFatal("%s : %s", Q_FUNC_INFO, QString(message).toStdString().c_str())), \
    (void)0 \
)

#endif // BDEBUG_H
