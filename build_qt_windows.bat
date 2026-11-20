@echo off
setlocal
chcp 65001 >nul
REM Use a MinGW toolchain compatible with your Qt6 installation.
REM Example: set CMAKE_PREFIX_PATH=C:\Qt\6.8.3\mingw_64
set "BUILD_DIR=build_qt_windows"
REM Detect Qt6 installed with MSYS2 MINGW64.
if not defined CMAKE_PREFIX_PATH if exist "C:\msys64\mingw64\lib\cmake\Qt6\Qt6Config.cmake" set "CMAKE_PREFIX_PATH=C:\msys64\mingw64"
cmake -S src -B "%BUILD_DIR%" -G Ninja -DGAME_TYPE=QtGui -DCMAKE_BUILD_TYPE=Release -DCMAKE_PREFIX_PATH="%CMAKE_PREFIX_PATH%"
if errorlevel 1 exit /b %errorlevel%
cmake --build "%BUILD_DIR%" --parallel
if errorlevel 1 exit /b %errorlevel%
echo.
echo Built %BUILD_DIR%\super_mario.exe
REM To share the exe, run windeployqt on it (see QT_WINDOWS_README.md).
endlocal
