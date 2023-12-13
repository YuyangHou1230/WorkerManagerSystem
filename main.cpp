#include "flowcontroler.h"

int main(int argc, char *argv[])
{

    int ret = FlowControler::getInstance().run(argc, argv);

    return ret;
}
