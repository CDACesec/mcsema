# Copyright (c) 2017 Trail of Bits, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
set(CMAKE_BC_COMPILER /usr/bin/clang++-4.0)
enable_language(ASM)

if (NOT TARGET remill)
  message(FATAL_ERROR "The remill target does not exists!")
endif ()

# Create the runtimes
set(mips_clang /usr/bin/clang++-4.0)
set(MCSEMA_RT32 lib_mipsel.a)
set(install_folder "${CMAKE_INSTALL_PREFIX}")
  

# Linux and friends
add_compile_options(-Wno-invalid-offsetof)
# generates the binary ,which writes the assembly file
add_executable(create_assembly_file
print_elf_mips_floatsupport.cpp
)

# this is going to import the public include headers of remill
#no longer problematic
target_link_libraries(create_assembly_file PRIVATE remill)
target_include_directories(create_assembly_file PRIVATE
"${REMILL_SOURCE_DIR}" "${MCSEMA_SOURCE_DIR}")

# create the archive file
add_custom_target(phony_custom_target ALL
    DEPENDS lib_mipsel.a)



add_custom_command(
    OUTPUT asm.o
    # check if we need the -fPIC[for linker too] or not
    # looks like we do
    COMMAND ${CMAKE_BC_COMPILER} -mfp32 -g -shared -fpic -fPIC -Wno-invalid-offsetof -o asm.o --target="mipsel-unknown-linux-gnu" -c mipsel_assembly.S
    DEPENDS mipsel_assembly.S
    COMMENT "assembling the assembly file"
    )

add_custom_command(
    OUTPUT mipsel_assembly.S
    COMMAND create_assembly_file
    DEPENDS create_assembly_file
    COMMENT "Generating runtime assembly file"
    )

set(incl /usr/mipsel-linux-gnu)

add_custom_command(
  OUTPUT runtime_mipsel.o
  # check if we need the -fPIC[for linker too] or not
  COMMAND "${mips_clang}" --target="mipsel-unknown-linux-gnu" -std=gnu++11 -isystem "${REMILL_SOURCE_DIR}" -isystem "${MCSEMA_SOURCE_DIR}" -fPIC -c "${CMAKE_CURRENT_SOURCE_DIR}/Runtime.cpp" -o runtime_mipsel.o
  DEPENDS Runtime.cpp
  COMMENT "Building mipsel runtime"
)

set_source_files_properties(
  runtime_mipsel.o
  PROPERTIES
  EXTERNAL_OBJECT True
  GENERATED True
)


add_custom_command(
    OUTPUT lib_mipsel.a
    COMMAND ar -crs lib_mipsel.a asm.o  && ranlib lib_mipsel.a
    #do we need to run ranlib or not?
    DEPENDS asm.o 
    COMMENT "creating library archive"
    )

# install our custom target in the destination location
install(
	FILES ${CMAKE_CURRENT_BINARY_DIR}/${MCSEMA_RT32}
	DESTINATION "${install_folder}/lib"
)  