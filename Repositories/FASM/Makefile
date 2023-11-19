CC = fasm
LIBS = asmlib/fmt.o asmlib/str.o asmlib/sys.o asmlib/mth.o
.PHONY: default compile build once dump hex run
default: build run
compile: $(LIBS)
	$(CC) asmlib/fmt.asm && $(CC) asmlib/str.asm && $(CC) asmlib/sys.asm && $(CC) asmlib/mth.asm
build: $(fn).asm
	$(CC) $(fn).asm
	ld $(fn).o $(LIBS) -o $(fn)
once: $(fn).asm
	$(CC) $(fn).asm
	ld $(fn).o -o $(fn)
dump: $(fn)
	objdump -S -M intel -d $(fn) > obj.dump
	cat obj.dump
hex: $(fn)
	hexeditor $(fn)
run: $(fn)
	./$(fn)
clear:
	rm $(fn) $(fn).o
