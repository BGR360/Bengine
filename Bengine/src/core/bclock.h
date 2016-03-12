#ifndef BCLOCK_H
#define BCLOCK_H

#include <bengine_global.h>

class BENGINESHARED_EXPORT BClock
{
public:
    BClock();
    virtual ~BClock();

    virtual double getTime() const;
    virtual float getDelta() const;
    virtual void newFrame();
    virtual void reset();
    virtual void start();
    virtual void stop();
};

#endif // BCLOCK_H