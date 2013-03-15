RM:=rm -rfv

vpath %.c ../src
vpath %.h ../hdr
vpath %.o ../objs
vpath %.d ../deps

%.d: %.c
	@set -e;rm -f $@; \
	$(CC) -MM $(CFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@: ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

