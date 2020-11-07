$(PROG): mkbindir
	gcc -o bin/$(PROG) $(PROG).c

mkbindir:
	@mkdir -p bin

clean:
	@rm -f bin/*