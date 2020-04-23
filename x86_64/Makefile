
all:
	+$(MAKE) -C dynamic
	+$(MAKE) -C static

clean:
	$(MAKE) -C dynamic clean
	$(MAKE) -C static clean

remake: clean all

.PHONY: all clean $(SUBDIRS)
