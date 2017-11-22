## introduction 
A mechanics framework/game engine mashup for the hypothetical game Preppers.

## Dependencies
* SFML 2.4
* Lua 5.2
* Selene (C++ binder for C++)
* Google Testing Framework


## How to build
### Setting up Google Testing Framework
1. cd into folder in git bash
2. mkdir externals
3. cd into externals
4. git clone https://github.com/google/googletest.git
5. Should be O.K!

### Setting up Lua 5.2
1. Download dynamic libraries for Lua 5.2 from https://sourceforge.net/projects/luabinaries/files/5.2/Windows%20Libraries/Dynamic/
2. Extract to somewhere and add it to PATH.

### Setting up SFML 2.4
1. Download SFML
2. Extract to somewhere
3. Add SFML_ROOT to environment variables with the root dir of SFML

### Build VS olution
1. cd into project root dir
2. mkdir build
3. cd build
4. cmake ..
5. Now a Visual Studio solution should be in the build folder
6. Compile and run!