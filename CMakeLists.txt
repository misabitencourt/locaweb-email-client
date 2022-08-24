cmake_minimum_required(VERSION 3.0)
project(locaweb_email_client)
set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES
    "src/*.cpp"
    "src/*.h"    
    "src/lib/*.h"
    "src/lib/*.cpp"
)

include_directories(./)

set(OPENSSL_USE_STATIC_LIBS TRUE)
find_package(OpenSSL REQUIRED)


add_executable(locaweb_email_client ${SOURCES})

target_link_libraries(locaweb_email_client PUBLIC OpenSSL::SSL OpenSSL::Crypto)
