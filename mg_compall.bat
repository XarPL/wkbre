@windres wkbre.rc res.o
@call mg_compile.bat %* *.c *.cpp gameset/*.cpp play/*.cpp script/*.cpp imgui/*.cpp
@call mg_linkall.bat %*