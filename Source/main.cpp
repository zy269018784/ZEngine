﻿#include "ZEngine.h"
int http_main(int argc, char* argv[]);
int ProgressDownloadermain(int argc, char* argv[]);
void LVGLDemos();
int main(int argc, char* argv[])
{
    //return ProgressDownloadermain(argc, argv);
    //return http_main(argc, argv);
    LVGLDemos();
    return 0;
    ZEngine app;
    app.Run(argc, argv);
    return 0;
}