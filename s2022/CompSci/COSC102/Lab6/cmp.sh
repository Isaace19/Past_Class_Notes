#!/usr/bin/env sh

# check if platform is linux or macos
if [ "$(uname)" = "Linux" ]; then
    # linux
    linux/bowling-sol <test.txt | sed 's/: /:\n/g' >sol.txt
    ./$1 <test.txt | sed 's/: /:\n/g' >out.txt
    diff -y --suppress-common-lines sol.txt out.txt || echo -e "Test failed. Input used is is in test.txt"
elif [ "$(uname)" = "Darwin" ]; then
    # macos
    macos/bowling-sol <test.txt | sed 's/: /:\n/g' >sol.txt
    ./$1 <test.txt | sed 's/: /:\n/g' >out.txt
    diff -y --suppress-common-lines sol.txt out.txt || echo -e "Test failed. Input used is is in test.txt"
else
    echo "Unsupported platform"
    exit 1
fi

exit 0
