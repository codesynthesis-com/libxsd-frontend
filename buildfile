# file      : buildfile
# license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

./: {*/ -build/} doc{INSTALL NEWS README} legal{GPLv2 LICENSE} manifest

# Don't install tests or the INSTALL file.
#
tests/:          install = false
doc{INSTALL}@./: install = false
