cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME FGPA_interface)

project(${PROJECT_NAME} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

#set (CMAKE_PREFIX_PATH "D:\\Development\\Qt_5.14.2\\5.14.2\\msvc2017_64")

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt5 COMPONENTS PrintSupport Widgets Network REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS PrintSupport Widgets Network REQUIRED)

set(PROJECT_SOURCES
    main.cpp
    udpconnection.cpp       udpconnection.hpp
    operator.cpp            operator.hpp
    basedevice.cpp          basedevice.hpp
)

set(CLIENT_SOURCES
    client/client.cpp           client/client.hpp
    client/main_client.cpp
)

set(SERVER_SOURCES
    server/server.cpp           server/server.hpp
    server/main_server.cpp
)

set(MESSENGER_SOURCES
    messenger/messenger.cpp     messenger/messenger.hpp
    messenger/main_messenger.cpp
)

#add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
add_executable(Client ${CLIENT_SOURCES})
add_executable(Server ${SERVER_SOURCES})
#add_executable(Messenger ${MESSENGER_SOURCES})
#[[
target_link_libraries(${PROJECT_NAME} PRIVATE 
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::PrintSupport
    Qt${QT_VERSION_MAJOR}::Network
)
]]#

target_link_libraries(Client PRIVATE 
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::PrintSupport
    Qt${QT_VERSION_MAJOR}::Network
)

target_link_libraries(Server PRIVATE 
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::PrintSupport
    Qt${QT_VERSION_MAJOR}::Network
)

#[[
target_link_libraries(Messenger PRIVATE 
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::PrintSupport
    Qt${QT_VERSION_MAJOR}::Network
)
]]#