SUBDIRS = aarch64 arm clang mingw32 mingw32-w64 mips mips64 ppc ppc64 riscv64 x86 x86_64

define runner =

	+$(MAKE) -C $(dir) $(1)
endef
define cleaner =

	$(MAKE) -C $(dir) $(1)
endef

all: pch
	$(foreach dir,$(SUBDIRS),$(call runner))

clean:
	$(foreach dir,$(SUBDIRS),$(call cleaner,clean))

fullclean:
	$(foreach dir,$(SUBDIRS),$(call cleaner,fullclean))

pch: $(patsubst %, _pchdir_%, $(SUBDIRS))

$(patsubst %, _pchdir_%, $(SUBDIRS)):
	$(MAKE) -C $(patsubst _pchdir_%, %, $@) pch

remake: clean all

run:
	$(MAKE) -C x86_64 run

.PHONY: all clean fullclean $(SUBDIRS)
