# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "/Users/pabloruiz/CLionProjects/Validate/cmake-build-debug/_deps/freetype-src")
  file(MAKE_DIRECTORY "/Users/pabloruiz/CLionProjects/Validate/cmake-build-debug/_deps/freetype-src")
endif()
file(MAKE_DIRECTORY
  "/Users/pabloruiz/CLionProjects/Validate/cmake-build-debug/_deps/freetype-build"
  "/Users/pabloruiz/CLionProjects/Validate/cmake-build-debug/_deps/freetype-subbuild/freetype-populate-prefix"
  "/Users/pabloruiz/CLionProjects/Validate/cmake-build-debug/_deps/freetype-subbuild/freetype-populate-prefix/tmp"
  "/Users/pabloruiz/CLionProjects/Validate/cmake-build-debug/_deps/freetype-subbuild/freetype-populate-prefix/src/freetype-populate-stamp"
  "/Users/pabloruiz/CLionProjects/Validate/cmake-build-debug/_deps/freetype-subbuild/freetype-populate-prefix/src"
  "/Users/pabloruiz/CLionProjects/Validate/cmake-build-debug/_deps/freetype-subbuild/freetype-populate-prefix/src/freetype-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/pabloruiz/CLionProjects/Validate/cmake-build-debug/_deps/freetype-subbuild/freetype-populate-prefix/src/freetype-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/pabloruiz/CLionProjects/Validate/cmake-build-debug/_deps/freetype-subbuild/freetype-populate-prefix/src/freetype-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
