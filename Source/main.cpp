#include "ZEngine.h"
int ModuleTest(int argc, char** argv);
int main(int argc, char** argv)
{
    return ModuleTest(argc, argv);
    ZEngine app;
    app.Run(argc, argv);
    return 0;
}