# swg_tpy

## introduction
python compiler written in c++. i saw many transpilers of python but all they are written in python and i dont like this fact. they are too slow. this attempt tries to increase speed of python. theoretically if it is possible to transpile every function of the standard python library it is possible to transpile to c++ every module. (correct me if i am wrong and explain why please)

## developement
### easy way
u need to have make and run this command to compile and run
```
mkdir build
make && make run
```
### not easy way
```
mkdir build
g++ src/main.cpp src/parsing.cpp src/utils.cpp -o build/tpy -std=c++17
```

### ideas to implement 
- convert directly custom classes from python to c++ classes. attributes with an underscore before the attribute (self._attribute) should be transpiled to private.

## contribution
contribution are welcomed and every pull request will be reviewed and if it is in the spirit of the project, useful and well written it will be merged. try to use code that is as cross platform as possible (if it does not work on windows i dont care). if u have an idea make a pull request and we ll evaluate it.

