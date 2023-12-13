#ifndef SINGLETON_H
#define SINGLETON_H

#include <QMutex>

template<class T>
class Singleton
{
public:
    static T &getInstance()
    {
        if(!instance){
            QMutexLocker locker(&mutex);
            if(!instance)
            {
                instance = new T();
            }
        }

        return *instance;
    }

private:
    Singleton();


    static QMutex mutex;
    static T* instance;
};

template<class T>
QMutex   Singleton<T>::mutex;

template<class T>
T*   Singleton<T>::instance = nullptr;

#endif // SINGLETON_H
