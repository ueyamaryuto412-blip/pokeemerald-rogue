#!/bin/sh

echo "Gathering dependencies:"

echo "Poryscript.."
if [ -d "tools/poryscript" ] 
then
  echo "Skipping (Already exists)"
else
  mkdir -p tools/poryscript
  wget -O tools/poryscript/poryscript-linux.zip https://github.com/huderlem/poryscript/releases/download/3.0.2/poryscript-linux.zip
  wget -O tools/poryscript/poryscript-windows.zip https://github.com/huderlem/poryscript/releases/download/3.0.2/poryscript-windows.zip
  unzip tools/poryscript/poryscript-linux.zip -d tools/poryscript
  unzip tools/poryscript/poryscript-windows.zip -d tools/poryscript
  echo "Done."
fi

echo "UPS Patcher.."
if [ -d "tools/ups" ] 
then
  echo "Skipping (Already exists)"
else
  mkdir -p tools/ups
  wget -O tools/ups/windows-arm.zip https://github.com/rameshvarun/ups/releases/download/v0.2.1/windows-arm.zip
  wget -O tools/ups/linux-arm.zip https://github.com/rameshvarun/ups/releases/download/v0.2.1/linux-arm.zip
  unzip tools/ups/windows-arm.zip -d tools/ups/windows-arm
  unzip tools/ups/linux-arm.zip -d tools/ups/linux-arm
  echo "Done."
fi

echo "Include stubs for scaninc.."
# scaninc looks in tools/agbcc/include for quoted system headers (string.h etc).
# The modern (arm-none-eabi) build does not use agbcc, so that directory does not
# exist and scaninc reports src/string.h as a missing dependency, which stops make.
# Empty stubs are enough: only the dependency scanner reads them, never the compiler.
if [ -f "tools/agbcc/include/string.h" ]
then
  echo "Skipping (Already exists)"
else
  mkdir -p tools/agbcc/include
  touch tools/agbcc/include/string.h tools/agbcc/include/stdio.h \
        tools/agbcc/include/stdlib.h tools/agbcc/include/math.h
  echo "Done."
fi

echo "Gathering dependencies finished."