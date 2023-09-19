Cs = $(wildcard *.c)
CXXs = $(wildcard *.cpp)
EXEs = $(Cs:.c=) $(CXXs:.cpp=)


# CXXFLAGS += -Wall -std=c++17 -lboost_iostreams
CXXFLAGS += -Wall -std=c++17

.PHONY: all clean

all: $(EXEs)

log: log.o
	@echo "LD log"
	@$(CC) $^ -lm -o $@

sha1:
	@echo ignore sha1

zinflate:
	@echo ignore zinflate

clean:
	@echo "RM"
	@rm -f $(EXEs) *.o
