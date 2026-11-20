#!/usr/bin/env bash
set -euo pipefail
cmake -S src -B build_qt_linux -G Ninja -DGAME_TYPE=QtGui -DCMAKE_BUILD_TYPE=Release
cmake --build build_qt_linux --parallel
