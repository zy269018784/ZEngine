#!/bin/bash
cmake -S . -B ../ZEngine_build -DCMAKE_BUILD_TYPE=Release  -DUSE_QT6=true  -DCMAKE_PREFIX_PATH="/opt/Qt/6.10.0/gcc_64/lib/cmake/"
cmake --build  ../ZEngine_build



