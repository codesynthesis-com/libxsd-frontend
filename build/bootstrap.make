# file      : build/bootstrap.make
# author    : Boris Kolpackov <boris@codesynthesis.com>
# copyright : Copyright (c) 2005-2009 Code Synthesis Tools CC
# license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

project_name := libxsd-frontend

include build-0.3/bootstrap.make

# Aliases
#
ifdef %interactive%

.PHONY: test $(out_base)/.test \
        clean $(out_base)/.clean

test: $(out_base)/.test
clean: $(out_base)/.clean

ifeq ($(.DEFAULT_GOAL),test)
.DEFAULT_GOAL :=
endif

ifeq ($(.DEFAULT_GOAL),clean)
.DEFAULT_GOAL :=
endif

endif

# Don't include dependency info if we are cleaning.
#
define include-dep
endef

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(MAKECMDGOALS),disfigure)
define include-dep
$(call -include,$1)
endef
endif
endif
