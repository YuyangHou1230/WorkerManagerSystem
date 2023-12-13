#ifndef FLOWCONTROLER_H
#define FLOWCONTROLER_H

#include <QObject>

class FlowControler
{
public:
    static FlowControler &getInstance()
    {
        static FlowControler flow;
        return flow;
    }

    int run(int argc, char *argv[]);

private:
    FlowControler();
};

#endif   // FLOWCONTROLER_H
