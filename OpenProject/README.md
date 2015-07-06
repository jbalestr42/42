TRELLO
======

https://trello.com/b/ND0mwII8/octodev


Makefile usage
==============

To generate dependencies (each time you create a new file and first compilation)
- make dep

To generate data (each time you add a new resource in the Resources directory)
- make data


Log usage
=========
- OctoLogger::log("Bonjour %d", 456);
- OctoLogger::log(std::string);
- OctoLogger::log() << stream;


Issues
======

If you see this message at execution time:
- dyld: Library not loaded: @rpath/libsfml-graphics.2.2.0.dylib

Once you are in the project's directory, execute this line:
- export LD_LIBRARY_PATH=$pwd/Lib/SFML/MacOSX/lib:$pwd/Lib/SFML/extlibs/
