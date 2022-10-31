CMAKE_MINIMUM_REQUIRED(VERSION 3.7)
project(thusql)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
# find_package(antlr4-runtime REQUIRED)


LIST(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# set variable pointing to the antlr tool that supports C++
SET(ANTLR4CPP_JAR_LOCATION ${PROJECT_SOURCE_DIR}/third-party/antlr4/antlr-4.10.1-complete.jar)
# 
set(ANTLR4_INCLUDE_DIR /usr/local/include/antlr4-runtime)
set(ANTLR4_LIB_DIR /usr/local/lib)
message("Antlr Include Dir: " ${ANTLR4_INCLUDE_DIR})
message("Antlr Library Dir: " ${ANTLR4_LIB_DIR})

# add antrl4cpp artifacts to project environment
include(ExternalAntlr4Cpp)



if(EXISTS ${PROJECT_SOURCE_DIR}/build)
    # this is to make many IDE happy about getting the header file. Need to use "build" directory though
    include_directories( ${ANTLR4_INCLUDE_DIR} ${CMAKE_CURRENT_BINARY_DIR} ${PROJECT_SOURCE_DIR}/src ${PROJECT_SOURCE_DIR}/build)
else()
    include_directories( ${ANTLR4_INCLUDE_DIR} ${CMAKE_CURRENT_BINARY_DIR} ${PROJECT_SOURCE_DIR}/src)
endif()

# link
link_directories( ${ANTLR4_LIB_DIR} )


execute_process(COMMAND java -jar ${ANTLR4CPP_JAR_LOCATION} -Dlanguage=Cpp  -visitor src/frontend/parser/SQL.g4
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
        RESULT_VARIABLE antlr4_result
        OUTPUT_VARIABLE antlr4_output)

if (${antlr4_result})
    message(FATAL_ERROR "antlr failed: ${antlr4_result}: ${antlr4_output}, CMake will exit.")
else ()
    message(STATUS "lex/parse file generated successfully.")
endif ()



add_subdirectory(src)
