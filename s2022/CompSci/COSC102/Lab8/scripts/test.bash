#!bash

## Colors

hex_to_ansi() {
    HEX_COLOR=$1
    R=0x${HEX_COLOR:1:2}
    G=0x${HEX_COLOR:3:2}
    B=0x${HEX_COLOR:5:2}
    printf "\e[38;2;%d;%d;%dm" $R $G $B
}

RED=$(hex_to_ansi "#e11d48")    # rose 600
GREEN=$(hex_to_ansi "#10b981")  # emerald 500
YELLOW=$(hex_to_ansi "#fde047") # yellow 300
BLUE=$(hex_to_ansi "#3b82f6")   # blue 500
PURPLE=$(hex_to_ansi "#c084fc") # purple 400
ORANGE=$(hex_to_ansi "#ff8200") # UT orange

BOLD='\e[1m'
ITALIC='\e[3m'
RESET_STYLE='\e[0m'

print_styled() {
    STYLE=$1
    MESSAGE="${@:2}"
    printf "$STYLE$MESSAGE$RESET_STYLE\n"
}

print_bold() {
    MESSAGE="$@"
    print_styled "$BOLD" "$MESSAGE"
}

print_success() {
    MESSAGE="$@"
    print_styled "$BOLD$GREEN" "$MESSAGE"
}

print_warning() {
    MESSAGE="$@"
    print_styled "$BOLD$YELLOW" "$MESSAGE"
}

print_error() {
    MESSAGE="$@"
    print_styled "$BOLD$RED" "$MESSAGE"
}

print_blue() {
    MESSAGE="$@"
    print_styled "$BOLD$BLUE" "$MESSAGE"
}

print_purple() {
    MESSAGE="$@"
    print_styled "$BOLD$PURPLE" "$MESSAGE"
}

## Colors

## Check for Updates

ZIP_FILENAME=bitset-tests.zip
ZIP_FILE_URL=https://raw.githubusercontent.com/seeker-3/cs102-resources/main/tests/$ZIP_FILENAME

if
    [[ "${@}" != *--no-update* ]] &&
        curl --silent $ZIP_FILE_URL -o check.zip &&
        ! cmp --silent check.zip $ZIP_FILENAME
then
    mv check.zip $ZIP_FILENAME
    unzip -qq -o $ZIP_FILENAME
    print_success "Tests were updated, please re-run the script"
    exit
else
    rm -f check.zip
fi

## Check for Updates

SRC_FILE=$1
BIN_FILE=lab.bin

TEST_INPUT_DIR=tests/input
TEST_OUTPUT_DIR=tests/output

# Usage
if [[ -z $SRC_FILE ]]; then
    print_error "Error: no source file specified"
    echo -e "Usage: bash $0 ${BOLD}source-file${RESET_STYLE} diff-flags"
    echo
    echo "Example: bash $0 lab.cpp -yiw"
    exit 1
fi

if ! [[ -f $SRC_FILE ]]; then
    print_error "Error: file '$SRC_FILE' not found."
    exit 1
fi

if ! [[ -d $TEST_INPUT_DIR ]]; then
    print_error "Error: input directory '$TEST_INPUT_DIR' not found."
    exit 1
fi

if ! [[ -d $TEST_OUTPUT_DIR ]]; then
    print_error "Error: output directory '$TEST_OUTPUT_DIR' not found."
    exit 1
fi

# Build
if ! g++ -std=c++11 -Wall -o $BIN_FILE $SRC_FILE; then
    echo
    print_error Build failed
    exit 1
fi

# Test
for TEST_NAME in $(ls $TEST_INPUT_DIR); do
    INPUT_TEST="$TEST_INPUT_DIR/$TEST_NAME"
    OUTPUT_TEST="$TEST_OUTPUT_DIR/$TEST_NAME"

    printf "${BLUE}%-32s${RESET_STYLE}" "$TEST_NAME:"
    if ! diff -y <(./$BIN_FILE <$INPUT_TEST 2>&1) $OUTPUT_TEST &>/dev/null; then
        print_error "FAILED"
        echo
        print_blue "$(printf '%-64s%s' YOURS EXPECTED)"
        echo
        diff -y --color <(./$BIN_FILE <$INPUT_TEST 2>&1 | sed 's/ >/\n>/g') <(cat $OUTPUT_TEST | sed 's/ >/\n>/g')
        echo
        echo

        printf "Run the test by itself with: ${PURPLE}./$BIN_FILE <$INPUT_TEST${RESET_STYLE}\n"
        printf "You can view the input with:  ${PURPLE}cat $INPUT_TEST${RESET_STYLE}\n"
        printf "You can view the output with: ${PURPLE}cat $OUTPUT_TEST${RESET_STYLE}\n"
        exit

    else
        print_success "PASSED"
    fi
done
