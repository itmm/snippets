Cs = $(wildcard *.c)
EXEs = $(Cs:.c=)

.PHONY: all clean

all: $(EXEs)

log: log.o
	@echo "LD log"
	@$(CC) $^ -lm -o $@

clean:
	@echo "RM"
	@rm -f $(EXEs) *.o
