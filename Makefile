SUBDIRS = aarch64 arm mingw32 mingw32-w64 mips mips64 ppc ppc64 x86 x86_64

all: $(patsubst %, _dir_%, $(SUBDIRS))

$(patsubst %, _dir_%, $(SUBDIRS)):
	@$(MAKE) -r -C $(patsubst _dir_%, %, $@)

clean: $(patsubst %, _cleandir_%, $(SUBDIRS))

$(patsubst %, _cleandir_%, $(SUBDIRS)):
	$(MAKE) -C $(patsubst _cleandir_%, %, $@) clean

remake: clean all

run:
	$(MAKE) -C x86_64 run
	
