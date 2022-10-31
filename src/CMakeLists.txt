cmake_minimum_required(VERSION 3.14)

# add_subdirectory(backend)/
# add_subdirectory(frontend)

# can be moved to backend/
set(SOURCE
    ${SOURCE}
    backend/BuffManagement/BufPageManager.cpp
    backend/BuffManagement/FindReplace.cpp 
    backend/FileManagement/FileManager.cpp 
    backend/FileManagement/FileTable.cpp 
    backend/PageManager/PageFile.cpp 
    backend/Utils/MyBitMap.cpp 
    backend/Utils/MyHashMap.cpp 
    backend/Utils/MyLinkList.cpp
    backend/defs.cpp
    backend/main.cpp
)

set(HEADERS 
    ${HEADERS}
    backend/BuffManagement/BufPageManager.h
    backend/BuffManagement/FindReplace.h 
    backend/FileManagement/FileManager.h
    backend/FileManagement/FileTable.h
    backend/PageManager/PageFile.h
    backend/Utils/Compare.h
    backend/Utils/MyBitMap.h
    backend/Utils/MyHashMap.h
    backend/Utils/MyLinkList.h
    backend/defs.h
)

# can be moved to frontend/
set(parser
    ${parser}
    frontend/parser/SQLBaseListener.cpp 
    frontend/parser/SQLBaseListener.h 
    frontend/parser/SQLBaseVisitor.cpp 
    frontend/parser/SQLBaseVisitor.h 
    frontend/parser/SQLLexer.cpp 
    frontend/parser/SQLLexer.h 
    frontend/parser/SQLListener.cpp 
    frontend/parser/SQLListener.h 
    frontend/parser/SQLParser.cpp 
    frontend/parser/SQLParser.h 
    frontend/parser/SQLVisitor.cpp 
    frontend/parser/SQLVisitor.h
    frontend/parser/MySQLListener.h 
    frontend/parser/MySQLVisitor.h
    frontend/database/dbms.h
    frontend/database/dbms.cpp
    frontend/database/database.h 
    frontend/database/database.cpp
    frontend/database/table.h 
    frontend/database/table.cpp 
)

# make root executable
add_executable(${CMAKE_PROJECT_NAME} main.cpp)

# add libraries
add_library(${CMAKE_PROJECT_NAME}_lib ${SOURCE} ${HEADERS} ${parser})
# add_dependencies(${CMAKE_PROJECT_NAME} ${CMAKE_PROJECT_NAME}_lib)

# link libraries
target_link_libraries(${CMAKE_PROJECT_NAME} 
    ${CMAKE_PROJECT_NAME}_lib             # backend
    ${ANTLR4_LIB_DIR}/libantlr4-runtime.a # antlr4
    
)

# fix https://github.com/antlr/antlr4/issues/3418
target_link_libraries(${CMAKE_PROJECT_NAME} Threads::Threads)


message("ANTLR4_LIBS: " ${ANTLR4_LIB_DIR})
message("CURRENT_BIN_DIR:" ${CMAKE_CURRENT_BINARY_DIR})
