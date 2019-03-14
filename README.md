[![Build Status](https://travis-ci.com/elinus/Code.svg?branch=master)](https://travis-ci.com/elinus/Code) 
[![CodeFactor](https://www.codefactor.io/repository/github/elinus/Code/badge)](https://www.codefactor.io/repository/github/elinus/Code) 
![repo-size](https://img.shields.io/github/repo-size/elinus/Code.svg) 
![code-size](https://img.shields.io/github/languages/code-size/elinus/Code.svg)	
![Pull requests](https://img.shields.io/github/issues-pr/elinus/Code.svg) 
![Closed pull requests](https://img.shields.io/github/issues-pr-closed-raw/elinus/Code.svg) 
![Tweet](https://img.shields.io/twitter/url/https/elinus/Code.svg?style=social)
![Follow Me](https://img.shields.io/twitter/follow/ayruomlinus.svg?style=social)

# Idea is to code on daily basis. 

## some useful commands 
- .clang-format
    - clang-format --style=llvm -dump-config > .clang-format
    - find . -iname *.h -o -iname *.c -o -iname *.cpp -o -iname *.hpp | xargs clang-format -style=file -i -fallback-style=none

- git commands for sync with latest remote repo
    - git remote add upstream https://github.com/elinus/Code.git
    - git fetch upstream
    - git merge upstream/master master
    - git push origin master

- Ubuntu build installs
    - sudo apt install gcc g++ clang clang-tidy clang-tools clang-format cmake cppcheck doxygen graphviz

- cmake
    - cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ...

- Valgrind
    valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./a.out

## Important links
https://hackernoon.com/50-data-structure-and-algorithms-interview-questions-for-programmers-b4b1ac61f5b0
