#include "bclock.h"

/*!
 * \class BClock
 * \brief The BClock class is a high-precision timer used to calculate delta times
 * between frames.
 * \inmodule Core
 *
 * The BClock class can be used to query the current time since the last update
 * (see \l getDelta) or since the clock started (see getTime).
 */


/*!
 * \brief Constructs a new BClock
 */
BClock::BClock()
{

}

/*!
 * \brief Destroys a BClock
 */
BClock::~BClock()
{

}

/*!
 * \brief Returns the time, in seconds, since start() was last called.
 */
double BClock::getTime() const
{
    return 0.0;
}

/*!
 * \brief Returns the time, in seconds, since newFrame() was last called.
 */
float BClock::getDelta() const
{
    return 0.0f;
}

/*!
 * \brief Begins a new frame for the clock.
 *
 * Calling this function will reset deltaTime to 0 seconds.
 */
void BClock::newFrame()
{

}

/*!
 * \brief Resets the current time to 0 seconds.
 *
 * This function can be called while the clock is running or stopped and
 * can be called multiple times.
 */
void BClock::reset()
{

}

/*!
 * \brief Starts the clock running.
 *
 * If stop() was previously called without a call to reset(), the clock
 * will continue counting from where it left off.
 */
void BClock::start()
{

}

/*!
 * \brief Stops the clock running.
 *
 * After stop() is called, if start() is called before reset() is called,
 * the clock will continue counting from where it left off.
 */
void BClock::stop()
{

}
