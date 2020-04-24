
all:
	+$(MAKE) -C dynamic
	+$(MAKE) -C static

clean:
	$(MAKE) -C dynamic clean
	$(MAKE) -C static clean

remake: clean all

run:
	$(MAKE) -C dynamic run

.PHONY: all clean run $(SUBDIRS)
