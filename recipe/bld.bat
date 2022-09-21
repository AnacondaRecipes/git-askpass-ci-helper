mkdir build
cd build

cmake -G "%CMAKE_GENERATOR%" ^
      -D CMAKE_INSTALL_PREFIX=%LIBRARY_PREFIX% ^
      %SRC_DIR%

:: Build.
cmake --build . --config Release
if errorlevel 1 exit 1

:: Install.
cmake --build . --config Release --target install
if errorlevel 1 exit 1