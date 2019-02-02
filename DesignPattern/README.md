`Design Patterns`

## .clang-format
`clang-format --style=llvm -dump-config > .clang-format`
`find . -iname *.h -o -iname *.c -o -iname *.cpp -o -iname *.hpp | xargs clang-format -style=file -i -fallback-style=none`

## git commands
`git remote add upstream https://github.com/elinus/Code.git`
`git fetch upstream`
`git merge upstream/master master`
`git push origin master`

## Ubuntu build installs
`sudo apt install gcc g++ clang clang-tidy clang-tools clang-format cmake cppcheck doxygen graphviz`

## cmake
`cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ...`

## Valgrind
`valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./a.out`

