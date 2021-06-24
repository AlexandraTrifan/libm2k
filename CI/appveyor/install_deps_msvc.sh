#!/bin/bash

set -e
set PATH=%PATH%
TOP_DIR=$(pwd)

# Download SWIG
#cd /c/
#wget https://sourceforge.net/projects/swig/files/swigwin/swigwin-4.0.0/swigwin-4.0.0.zip
#7z x swigwin-4.0.0.zip -oswig
#cd swig/swigwin-4.0.0
#xcopy * .. /s /e /h /Q

# Download glog
#cd /c/
#${TOP_DIR}\CI\appveyor\install_glog.bat "Release" "x64"
#${TOP_DIR}\CI\appveyor\install_glog.bat "Release" "Win32"


MCS_EXECUTABLE_PATH="C:\Windows\Microsoft.NET\Framework\v4.0.30319"
OLD_PATH="$PATH"
DEST_LIBIIO="/c/libiio"

__build_libiio() {
	local PLATFORM="$1"
	local GENERATOR="$2"

	# Create the official build directory for this platform
	mkdir -p "$DEST_LIBIIO/build-$PLATFORM"
	cd "$DEST_LIBIIO/build-$PLATFORM"

	cmake -G "$GENERATOR" -DCMAKE_CONFIGURATION_TYPES=RELEASE ..
	cmake --build . --config Release

}

__mv_to_build_dir() {
	local PLATFORM="$1"

	DST_FOLDER="$DEST_LIBIIO-$PLATFORM/"
	cd "$DEST_LIBIIO/build-$PLATFORM"
	cp *.dll $DST_FOLDER
	cp *.exe $DST_FOLDER
	cp *.lib $DST_FOLDER
	cp *.iss $DST_FOLDER
	cd ..
	cp iio.h $DST_FOLDER
}

git clone https://github.com/analogdevicesinc/libiio $DEST_LIBIIO
cd $DEST_LIBIIO

__build_libiio win32 "Visual Studio 15"
__mv_to_build_dir win32

__build_libiio win64 "Visual Studio 15 Win64"
__mv_to_build_dir win64
