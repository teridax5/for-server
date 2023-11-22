CC = fasm
INCLUDE = asmlib
.PHONY: build once dump hex run clear
once: main.asm
	@$(CC) main.asm
	@ld main.o -o main
dump:
	@objdump -S -M intel -d main > obj.dump
	@cat obj.dump
hex:
	@hexeditor main
run:
	@./main
clear:
	@rm main
compile:
	$(eval ALIBS = $(shell ls $(INCLUDE)/*.asm))
	@for file in $(ALIBS) ; do \
		$(CC) $$file; \
	done
build:
	$(eval OBJFILES = $(shell ls $(INCLUDE)/*.o))
	@$(CC) main.asm
	@ld main.o $(OBJFILES) -o main
	@rm $(OBJFILES) main.o
