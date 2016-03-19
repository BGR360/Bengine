//! [0]
#include "subclass.h"
#include <qdebug.h>

int main()
{
     SubClass instance;
     BClass instanceClass = instance.getClass();
     BClass staticClass = SubClass::getStaticClass();

     qDebug() << (instanceClass == staticClass);    // Will print true
     return 0;
}
//! [0]
