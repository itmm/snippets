Cs = $(wildcard *.c)
CXXs = $(wildcard *.cpp)
EXEs = $(Cs:.c=) $(CXXs:.cpp=)

CXXFLAGS += -Wall -std=c++17 -lboost_iostreams

.PHONY: all clean

all: $(EXEs)

log: log.o
	@echo "LD log"
	@$(CC) $^ -lm -o $@

clean:
	@echo "RM"
	@rm -f $(EXEs) *.o
