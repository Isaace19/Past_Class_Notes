CCFLAGS = -g
BINARY = bowling
SOURCES = $(BINARY).cpp
ZIP = tests.zip
LAB = lab7

all: $(BINARY)

$(BINARY): $(SOURCES)
	g++ -o $(BINARY) $(SOURCES) $(CCFLAGS)

input1.txt:
	curl https://pastebin.com/raw/7f2wVQ1a --output input1.txt

input2.txt:
	curl https://pastebin.com/raw/wfVRnrvj --output input2.txt

clean:
	rm -rf $(BINARY) input1.txt input2.txt $(ZIP) out.txt sol.txt test.txt cmp.sh generate_tests.py macos linux

.PHONY: help random test1 test2
FORCE:

test1: $(BINARY) input1.txt
	./$(BINARY) < input1.txt | sed 's/: /:\n/g'

test2: $(BINARY) input2.txt
	./$(BINARY) < input2.txt | sed 's/: /:\n/g'

random: $(ZIP) $(BINARY)
	@python3 generate_tests.py
	@echo "Running $(BINARY) with random test cases..."
	@echo "Left is the expected output, right is your output - empty means passed"
	@bash cmp.sh $(BINARY)

help:
	@echo
	@echo "Available commands"
	@echo
	@echo "make:          Compiles '$(SOURCES)' to binary file named '$(BINARY)'"
	@echo "make test1:    Run '$(BINARY)' with input1.txt"
	@echo "make test2:    Run '$(BINARY)' with input2.txt"
	@echo "make random:   Generate random test cases and compare your output to the expected output"

Makefile: FORCE
	@echo "Checking for updates to Makefile..."
	@curl --silent https://raw.githubusercontent.com/Ethan0429/cs102-writeups/main/$(LAB)/Makefile -o Makefile.tmp
	@cmp -s Makefile.tmp Makefile && rm Makefile.tmp || (mv -f Makefile.tmp Makefile && echo "Updated Makefile - Restarting...")

$(ZIP): FORCE
	@echo "Checking for updates to $(ZIP)..."
	@curl --silent -L https://raw.githubusercontent.com/Ethan0429/cs102-writeups/main/$(LAB)/$(ZIP) -o $(ZIP).tmp
	@cmp -s $(ZIP).tmp $(ZIP) && rm $(ZIP).tmp || (mv -f $(ZIP).tmp $(ZIP) && echo "Updated $(ZIP)")
	@unzip -o -q $(ZIP) || @echo "Unable to unzip $(ZIP). Check that you have unzip installed."