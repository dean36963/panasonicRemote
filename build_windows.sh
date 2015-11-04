#!/bin/bash
git clone https://github.com/mxe/mxe.git
cd mxe
make qtbase
export PATH="$(pwd)/usr/bin:$(pwd)/usr/i686-w64-mingw32.static/{,qt5}/bin:$PATH"
cd ..
qmake
make
mv release/panasonicRemote.exe .
zip -r panasonicRemote_win32.zip panasonicRemote.exe res
