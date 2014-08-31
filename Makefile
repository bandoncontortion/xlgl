VERSION := 0.0.1
NAME    := xlgl
MAINSRC := \
		XLGL/xlglcontext.c \
		XLGL/xlglevents.c  \
		XLGL/xlglinit.c    \
		XLGL/xlgllogging.c \
		XLGL/xlglwindow.c  \
		XLGL/xlglandroid.c

BASEDIR := $(shell pwd;)

# Add new Makefiles and supported make commands here
MAKES   := \
		build/Makefile.android     \
		build/Makefile.linux_x11   \
		build/Makefile.win32-cross \
		build/Makefile.win64-cross
SUPPORT := \
		all                    \
		static                 \
		shared                 \
		copy                   \
		android                \
		linux_x11              \
		linux_x11-static       \
		linux_x11-shared       \
		windows32-cross        \
		windows32-static-cross \
		windows32-shared-cross \
		windows64-cross        \
		windows64-static-cross \
		windows64-shared-cross

export VERSION
export NAME
export MAINSRC
export BASEDIR

all:
	@$(foreach MAKEFILE, $(MAKES), $(MAKE) -f $(MAKEFILE) all;)

list:
	@echo "Choose one: "
	@$(foreach SUP, $(SUPPORT), echo "    $(SUP)";)

static:
	@$(foreach MAKEFILE, $(MAKES), $(MAKE) -f $(MAKEFILE) static;)

shared:
	@$(foreach MAKEFILE, $(MAKES), $(MAKE) -f $(MAKEFILE) shared;)

copy: tools/ tools/XLGL/
	@$(foreach MAKEFILE, $(MAKES), $(MAKE) -f $(MAKEFILE) copy;)
	cp -f XLGL/*.h tools/XLGL/
	cp -f XLGL/*.hpp tools/XLGL/

tools/:
	mkdir tools/

tools/XLGL/:
	mkdir tools/XLGL/

install:
	@$(foreach MAKEFILE, $(MAKES), $(MAKE) -f $(MAKEFILE) install;)

uninstall:
	@$(foreach MAKEFILE, $(MAKES), $(MAKE) -f $(MAKEFILE) uninstall;)

android:
	@$(MAKE) -f build/Makefile.android all

linux_x11:
	@$(MAKE) -f build/Makefile.linux_x11 all

linux_x11-static:
	@$(MAKE) -f build/Makefile.linux_x11 static

linux_x11-shared:
	@$(MAKE) -f build/Makefile.linux_x11 shared

windows32-cross:
	@$(MAKE) -f build/Makefile.win32-cross all

windows32-static-cross:
	@$(MAKE) -f build/Makefile.win32-cross static

windows32-shared-cross:
	@$(MAKE) -f build/Makefile.win32-cross shared

windows64-cross:
	@$(MAKE) -f build/Makefile.win64-cross all

windows64-static-cross:
	@$(MAKE) -f build/Makefile.win64-cross static

windows64-shared-cross:
	@$(MAKE) -f build/Makefile.win64-cross shared

clean:
	@$(foreach MAKEFILE, $(MAKES), $(MAKE) -f $(MAKEFILE) clean;)
	rm -rf tools/
