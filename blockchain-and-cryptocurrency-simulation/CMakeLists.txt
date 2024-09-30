# CMakeList.txt : CMake project for blockchain-and-cryptocurrency-simulation, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (blockchain-and-cryptocurrency-simulation "main.cpp"  "src/Block.cpp" "src/Blockchain.cpp" "src/NetworkNode.cpp" "src/ProofOfStake.cpp" "src/ProofOfWork.cpp" "src/Transaction.cpp" "includes/Block.h" "includes/Blockchain.h" "includes/NetworkNode.h" "includes/ProofOfStake.h" "includes/ProofOfWork.h" "includes/Transaction.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET blockchain-and-cryptocurrency-simulation PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
if(WIN32)
    # Specify the paths to the libraries and includes for Windows
    set(LIB_PATH_MODIFIED "${CMAKE_SOURCE_DIR}/vcpkg/vcpkg_installed/x64-windows/lib")
    set(LIB_PATH "${CMAKE_SOURCE_DIR}/vcpkg/installed/x64-windows/lib")
    set(INCLUDE_PATH "${CMAKE_SOURCE_DIR}/vcpkg/installed/x64-windows/include")
    set(BIN_PATH "${CMAKE_SOURCE_DIR}/vcpkg/installed/x64-windows/bin")

    # Add include directories
    include_directories(${INCLUDE_PATH})

    # Specify the paths to the libraries
    set(LIBXML2_LIB_PATH "${LIB_PATH}/libxml2.lib")
    set(LIBICONV_LIB_PATH "${LIB_PATH}/iconv.lib")
    set(FMT_LIB_PATH "${LIB_PATH}/fmt.lib")
    set(GTEST_LIB_PATH "${LIB_PATH}/gtest.lib")
    set(ZLIB_LIB_PATH "${LIB_PATH}/zlib.lib")
    set(BOOST_FILESYSTEM_LIB_PATH "${LIB_PATH}/boost_filesystem-vc143-mt-x64-1_85.lib")
    set(BOOST_MOVE_LIB_PATH "${LIB_PATH}/boost_move-vc143-mt-x64-1_85.lib") 
    set(OPENSSL_LIB_PATH "${LIB_PATH_MODIFIED}/libssl.lib;${LIB_PATH_MODIFIED}/libcrypto.lib")
    set(ASIO_LIB_PATH "${LIB_PATH}/asio.lib") # Asio library

    # Link against Windows libraries
    target_link_libraries(blockchain-and-cryptocurrency-simulation PRIVATE 
        ${FMT_LIB_PATH} 
        ${LIBXML2_LIB_PATH} 
        ${LIBICONV_LIB_PATH} 
        ${GTEST_LIB_PATH} 
        ${ZLIB_LIB_PATH} 
        ${BOOST_FILESYSTEM_LIB_PATH} 
        ${BOOST_MOVE_LIB_PATH} 
        ${OPENSSL_LIB_PATH} 
        ${ASIO_LIB_PATH}
    )

    # Copy necessary files to the output directory
    add_custom_command(TARGET blockchain-and-cryptocurrency-simulation POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/blockchain-and-cryptocurrency-simulation/input" 
        $<TARGET_FILE_DIR:blockchain-and-cryptocurrency-simulation>/input
    )

    # Copy DLLs to the output directory
    add_custom_command(TARGET blockchain-and-cryptocurrency-simulation POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${BIN_PATH}/fmt.dll" $<TARGET_FILE_DIR:blockchain-and-cryptocurrency-simulation>
    )
    add_custom_command(TARGET blockchain-and-cryptocurrency-simulation POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${BIN_PATH}/libxml2.dll" $<TARGET_FILE_DIR:blockchain-and-cryptocurrency-simulation>
    )
    add_custom_command(TARGET blockchain-and-cryptocurrency-simulation POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${BIN_PATH}/liblzma.dll" $<TARGET_FILE_DIR:blockchain-and-cryptocurrency-simulation>
    )
    add_custom_command(TARGET blockchain-and-cryptocurrency-simulation POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${BIN_PATH}/iconv-2.dll" $<TARGET_FILE_DIR:blockchain-and-cryptocurrency-simulation>
    )
    add_custom_command(TARGET blockchain-and-cryptocurrency-simulation POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${Boost_LIBRARY_DIRS}/*.dll" $<TARGET_FILE_DIR:blockchain-and-cryptocurrency-simulation>
    )

    # Enable Google Test
    enable_testing()

elseif(UNIX)  # This will match Linux/Unix systems
    # Specify the paths to the libraries and includes for UNIX
    set(LIB_PATH "${CMAKE_SOURCE_DIR}/vcpkg/installed/x64-linux/lib")
    set(INCLUDE_PATH "${CMAKE_SOURCE_DIR}/vcpkg/installed/x64-linux/include")

    # Add include directories
    include_directories(${INCLUDE_PATH})

    # Specify the paths to the libraries
    set(LIBXML2_LIB_PATH "${LIB_PATH}/libxml2.so")
    set(LIBICONV_LIB_PATH "${LIB_PATH}/libiconv.so")
    set(FMT_LIB_PATH "${LIB_PATH}/libfmt.so")
    set(BOOST_FILESYSTEM_LIB_PATH "${LIB_PATH}/libboost_filesystem.so")
    set(OPENSSL_LIB_PATH "${LIB_PATH}/libssl.so;${LIB_PATH}/libcrypto.so")  # OpenSSL libraries
    set(ASIO_LIB_PATH "${LIB_PATH}/libasio.so")  # Asio library

    # Link against UNIX libraries
    target_link_libraries(blockchain-and-cryptocurrency-simulation PRIVATE 
        ${FMT_LIB_PATH} 
        ${LIBXML2_LIB_PATH} 
        ${LIBICONV_LIB_PATH} 
        ${BOOST_FILESYSTEM_LIB_PATH} 
        ${OPENSSL_LIB_PATH} 
        ${ASIO_LIB_PATH}
    )

    # Copy data.xml to the output directory
    add_custom_command(TARGET blockchain-and-cryptocurrency-simulation POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/blockchain-and-cryptocurrency-simulation/input" 
        $<TARGET_FILE_DIR:blockchain-and-cryptocurrency-simulation>/input
    )
endif()
