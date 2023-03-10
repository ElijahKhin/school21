cmake_minimum_required(VERSION 3.5)

project(3DViewer_v1 VERSION 0.1)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

#set(CMAKE_C_STANDARD 11)
#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

#include(CPack)
#set(CPACK_SOURCE_GENERATOR "TGZ")


set(PROJECT_SOURCES
        main.cpp
        viewer3d.cpp
        viewer3d.h
        viewer3d.ui
        struct/object3/object3.h
        struct/object3/create.c
        struct/object3/free.c
        parser/core.c
        parser/core.h
        struct/other.h
        MyQOpenGLWidget.cpp
        MyQOpenGLWidget.h
        struct/object3/transformations/move.c
        struct/object3/transformations/rotate.c
        struct/object3/transformations/scale.c
        struct/vector3/add.c
        struct/vector3/rotate.c
        struct/vector3/vector3.h

        QtGifImage-master/src/3rdParty/giflib/dgif_lib.c
        QtGifImage-master/src/3rdParty/giflib/egif_lib.c
        QtGifImage-master/src/3rdParty/giflib/gif_err.c
        QtGifImage-master/src/3rdParty/giflib/gif_lib.h
        QtGifImage-master/src/3rdParty/giflib/gif_hash.c
        QtGifImage-master/src/3rdParty/giflib/gifalloc.c
        QtGifImage-master/src/3rdParty/giflib/quantize.c
        QtGifImage-master/src/gifimage/qgifglobal.h
        QtGifImage-master/src/gifimage/qgifimage.h
        QtGifImage-master/src/gifimage/qgifimage_p.h
        QtGifImage-master/src/gifimage/qgifimage.cpp
        struct/object3/update.c)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets OpenGLWidgets Core OpenGL)


#add_custom_target(dist COMMAND ${CMAKE_MAKE_PROGRAM} package_source)
set(CPACK_SOURCE_IGNORE_FILES
        ./CMakeFiles
        ./3DViewer_v1.app
        ./_CPack_Packages
        )

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(3DViewer_v1
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
endif()

target_link_libraries(3DViewer_v1 PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::OpenGLWidgets
    Qt${QT_VERSION_MAJOR}::Core
    Qt6::OpenGL
)


set_target_properties(3DViewer_v1 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
    C_STANDARD 11
    CXX_STANDARD 11
)

install(TARGETS 3DViewer_v1
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(3DViewer_v1)
endif()

