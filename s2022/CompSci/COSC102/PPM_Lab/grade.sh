#!/usr/bin/env bash

gdir="$(pwd)/gs"
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

rm -f out.ppm sol.ppm
no_fail=0
exe=lab11

# search args for --no-fail flag
for arg in "$@"; do
    if [ "$arg" = "--no-fail" ]; then
        no_fail=1
    elif [[ "$arg" == *.cpp ]]; then
        g++ -Wall -O0 -g -std=c++11 -o lab11 "$arg"
    fi
done

# grade bee.ppm to out.ppm
for i in {I,X,Y}; do
    rm out.ppm 2>/dev/null && rm sol.ppm 2>/dev/null
    echo "./lab11 $gdir/bee.ppm $gdir/out$i.ppm $i"
    ./$exe $gdir/bee.ppm $gdir/out$i.ppm $i
    diff -q $gdir/out$i.ppm $gdir/sol$i.ppm

    if [ $? == 0 ]; then
        echo -e "${GREEN}passed command: $i - bee.ppm to out.ppm${NC}\n"
    else
        cp $gdir/out$i.ppm out.ppm 2>/dev/null && cp $gdir/sol$i.ppm sol.ppm 2>/dev/null
        echo -e "${RED}failed command: $i - bee.ppm to out.ppm${NC}"
        echo -e "${YELLOW}Run ${NC}${GREEN}make test${NC}${YELLOW} to see the difference${NC}\n"
        if [ $no_fail -ne 1 ]; then
            exit 1
        fi
    fi
    rm -f out.ppm sol.ppm

done

# grade bee.ppm to stdout
for i in {I,X,Y}; do
    rm out.ppm 2>/dev/null && rm sol.ppm 2>/dev/null
    echo -e "./lab11 $gdir/bee.ppm - $i > out$i.ppm"
    ./$exe $gdir/bee.ppm - $i >$gdir/out$i.ppm
    diff -q $gdir/out$i.ppm $gdir/sol$i.ppm

    if [ $? == 0 ]; then
        echo -e "${GREEN}passed command: $i - bee.ppm to stdout${NC}\n"
    else
        cp $gdir/out$i.ppm out.ppm 2>/dev/null && cp $gdir/sol$i.ppm sol.ppm 2>/dev/null
        echo -e "${RED}failed command: $i - bee.ppm to stdout${NC}"
        echo -e "${YELLOW}Run ${NC}${GREEN}make test${NC}${YELLOW} to see the difference${NC}\n"
        if [ $no_fail -ne 1 ]; then
            exit 1
        fi
    fi
    rm -f out.ppm sol.ppm

done

# grade stdin to out.ppm
for i in {I,X,Y}; do
    rm out.ppm 2>/dev/null && rm sol.ppm 2>/dev/null
    echo -e "./lab11 - $gdir/out$i.ppm $i < $gdir/bee.ppm"
    ./$exe - $gdir/out$i.ppm $i <$gdir/bee.ppm
    diff -q $gdir/out$i.ppm $gdir/sol$i.ppm

    if [ $? == 0 ]; then
        echo -e "${GREEN}passed command: $i - stdin to out.ppm${NC}\n"
    else
        cp $gdir/out$i.ppm out.ppm 2>/dev/null && cp $gdir/sol$i.ppm sol.ppm 2>/dev/null
        echo -e "${RED}failed command: $i - stdin to out.ppm${NC}"
        echo -e "${YELLOW}Run ${NC}${GREEN}make test${NC}${YELLOW} to see the difference${NC}\n"
        if [ $no_fail -ne 1 ]; then
            exit 1
        fi
    fi
    rm -f out.ppm sol.ppm

done

# grade stdin to stdout
for i in {I,X,Y}; do
    rm out.ppm 2>/dev/null && rm sol.ppm 2>/dev/null
    echo -e "./lab11 - - $i < $gdir/bee.ppm > out$i.ppm"
    ./$exe - - $i <$gdir/bee.ppm >$gdir/out$i.ppm
    diff -q $gdir/out$i.ppm $gdir/sol$i.ppm

    if [ $? == 0 ]; then
        echo -e "${GREEN}passed command: $i - stdin to stdout${NC}\n"
    else
        cp $gdir/out$i.ppm out.ppm 2>/dev/null && cp $gdir/sol$i.ppm sol.ppm 2>/dev/null
        echo -e "${RED}failed command: $i - stdin to stdout${NC}"
        echo -e "${YELLOW}Run ${NC}${GREEN}make test${NC}${YELLOW} to see the difference${NC}\n"
        if [ $no_fail -ne 1 ]; then
            exit 1
        fi
    fi
    rm -f out.ppm sol.ppm

done

# grade no manipulation arg
rm out.ppm 2>/dev/null && rm sol.ppm 2>/dev/null
echo -e "./lab11 - - < $gdir/bee.ppm > out.ppm"
./$exe - - <$gdir/bee.ppm >$gdir/out.ppm
diff -q $gdir/out.ppm $gdir/bee.ppm

if [ $? == 0 ]; then
    echo -e "${GREEN}passed command: no change${NC}\n"
else
    cp $gdir/out.ppm out.ppm 2>/dev/null && cp $gdir/bee.ppm sol.ppm 2>/dev/null
    echo -e "${RED}failed command: $i - no change${NC}"
    echo -e "${YELLOW}Run ${NC}${GREEN}make test${NC}${YELLOW} to see the difference${NC}\n"
    exit
fi

echo "Done"
