SUBDIRS = aarch64 arm clang mingw32 mingw32-w64 mips mips64 ppc ppc64 riscv64 x86 x86_64

define runner =

	+$(MAKE) -C $(dir)
endef
define cleaner =

	$(MAKE) -C $(dir) clean
endef

all:
	$(foreach dir,$(SUBDIRS),$(call runner))

clean:
	$(foreach dir,$(SUBDIRS),$(call cleaner))

remake: clean all

run:
	$(MAKE) -C x86_64 run

.PHONY: all clean $(SUBDIRS)
