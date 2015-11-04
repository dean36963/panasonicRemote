#!/bin/bash
if [[ "X$MXE" == "$MXE" ]] ; then
	MXE=mxe
fi
if [[ -d $MXE ]] ; then
	git clone https://github.com/mxe/mxe.git $MXE
	cd $MXE
	make qtbase
	cd -
fi
export PATH="$MXE/usr/bin:$MXE/usr/i686-w64-mingw32.static/qt5/bin:$MXE/usr/i686-w64-mingw32.static/bin:$PATH"
echo $PATH
which qmake
qmake
make
mv release/panasonicRemote.exe .
zip -r panasonicRemote_win32.zip panasonicRemote.exe res
