if not exist "%ct_dir%"\lib\mtc2\%NULL% mkdir "%ct_dir%"\lib\mtc2
if exist \djgpp\bin\go32.exe coff2exe -s /djgpp/bin/go32.exe mtc2
copy mtc2.bat "%ct_dir%"\bin\mtc2.bat
copy mtc2.exe "%ct_dir%"\lib\mtc2
copy system_.h "%ct_dir%"\lib\mtc2
copy system_.c "%ct_dir%"\lib\mtc2
copy argument.h "%ct_dir%"\lib\mtc2
copy argument.c "%ct_dir%"\lib\mtc2
