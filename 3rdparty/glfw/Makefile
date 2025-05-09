ifeq ($(strip $(PREFIX)),)
override PREFIX = $(abspath $(CURDIR)/../build)
endif

VERSION = 3.3.3
GLFW_EXTRA_CMAKE_FLAGS ?=
ifeq ($(shell uname),Darwin)
 GLFW_EXTRA_CMAKE_FLAGS += -DCMAKE_OSX_DEPLOYMENT_TARGET=10.15
endif

ifeq ($(DOWNLOAD_CMD),)
ifneq ($(shell curl --version 2>/dev/null),)
DOWNLOAD_CMD := curl -k -OL
endif
endif
ifeq ($(DOWNLOAD_CMD),)
ifneq ($(shell wget --version 2>/dev/null),)
DOWNLOAD_CMD := wget --no-check-certificate
endif
endif
ifeq ($(DOWNLOAD_CMD),)
DOWNLOAD_CMD := echo "Error: Unable to find curl or wget."; exit 1; \#
endif

ifeq ($(CMAKE_CMD),)
ifneq ($(shell cmake --version 2>/dev/null),)
CMAKE_CMD := cmake
CMAKE_DEP :=
endif
endif
ifeq ($(CMAKE_CMD),)
CMAKE_CMD := $(PREFIX)/bin/cmake
CMAKE_DEP := $(CMAKE_CMD)
endif

default: install

$(PREFIX)/src/glfw-$(VERSION).tar.gz:
	mkdir -p $(PREFIX)/src
	cd $(PREFIX)/src/ && $(DOWNLOAD_CMD) https://gr-framework.org/downloads/3rdparty/glfw-$(VERSION).tar.gz

$(PREFIX)/src/glfw-$(VERSION)/CMakeLists.txt: $(PREFIX)/src/glfw-$(VERSION).tar.gz
	cd $(PREFIX)/src/ && tar -xf glfw-$(VERSION).tar.gz
	cd $(PREFIX)/src/glfw-$(VERSION) && \
	( \
	echo '--- a/CMakeLists.txt'; \
	echo '+++ b/CMakeLists.txt'; \
	echo '@@ -1,4 +1,4 @@'; \
	echo '-cmake_minimum_required(VERSION 3.0)'; \
	echo '+cmake_minimum_required(VERSION 3.5)'; \
	echo; \
	echo ' project(GLFW VERSION 3.3.3 LANGUAGES C)'; \
	echo; \
	) | patch -Np1

$(PREFIX)/build/glfw-$(VERSION)/Makefile: $(PREFIX)/src/glfw-$(VERSION)/CMakeLists.txt $(CMAKE_DEP)
	mkdir -p $(PREFIX)/build/glfw-$(VERSION)
	cd $(PREFIX)/build/glfw-$(VERSION) && \
	$(CMAKE_CMD) \
		-DCMAKE_INSTALL_PREFIX:PATH=${PREFIX} \
		-DCMAKE_INSTALL_LIBDIR=lib \
		-DGLFW_USE_RETINA=OFF \
		-DGLFW_BUILD_EXAMPLES=OFF \
		-DGLFW_BUILD_DOCS=OFF \
		-DGLFW_BUILD_TESTS=OFF \
		$(GLFW_EXTRA_CMAKE_FLAGS) \
		$(PREFIX)/src/glfw-$(VERSION)/

$(PREFIX)/lib/libglfw3.a: $(PREFIX)/build/glfw-$(VERSION)/Makefile
	$(MAKE) -C $(PREFIX)/build/glfw-$(VERSION) -j4
	$(MAKE) -C $(PREFIX)/build/glfw-$(VERSION) install

install: $(PREFIX)/lib/libglfw3.a

.PHONY: default install
