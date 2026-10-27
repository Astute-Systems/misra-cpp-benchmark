cmake_minimum_required(VERSION 3.14)
project(misra_cpp_benchmark LANGUAGES CXX)

# Optional alternative to tools/gen_compile_commands.py:
#
#   cmake -S . -B build
#   # compile_commands.json is written to build/
#
# Nothing is linked. Every example becomes an OBJECT library so that the files
# of one example form one target; checkers that group translation units by
# target (for the one-definition rules 6.2.x) then see them together.

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CASES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/cases")

file(GLOB case_dirs LIST_DIRECTORIES true RELATIVE "${CASES_DIR}" "${CASES_DIR}/*")
list(SORT case_dirs)

foreach(case IN LISTS case_dirs)
  if(NOT IS_DIRECTORY "${CASES_DIR}/${case}")
    continue()
  endif()

  file(GLOB_RECURSE sources "${CASES_DIR}/${case}/*.cpp")
  list(SORT sources)

  set(example_numbers "")
  foreach(source IN LISTS sources)
    get_filename_component(name "${source}" NAME)
    string(REGEX MATCH "^example([0-9]+)" matched "${name}")
    if(NOT matched)
      message(FATAL_ERROR "${source}: file name must start with exampleN")
    endif()
    set(number "${CMAKE_MATCH_1}")

    # Examples that cannot compile by nature carry a NO-COMPILE: tag.
    file(READ "${source}" content)
    string(FIND "${content}" "NO-COMPILE:" tag_position)
    if(NOT tag_position EQUAL -1)
      continue()
    endif()

    list(APPEND example_numbers "${number}")
    list(APPEND files_${number} "${source}")
  endforeach()

  list(REMOVE_DUPLICATES example_numbers)
  foreach(number IN LISTS example_numbers)
    set(target "${case}-example${number}")
    add_library(${target} OBJECT ${files_${number}})
    target_include_directories(${target} PRIVATE "${CASES_DIR}/${case}")
    unset(files_${number})
  endforeach()
endforeach()
