cmake_minimum_required(VERSION 3.20)

project (ZEngine)

enable_language(C)
enable_language(CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#[[
	库路径
#]]
set (LIBRARY_PATH ${PROJECT_SOURCE_DIR}/../../../Library)
set (SRC_PREFIX ${PROJECT_SOURCE_DIR}/Source)
#[[
	QT
#]]
set (CMAKE_AUTOMOC ON)
set (CMAKE_AUTOUIC ON)
set (CMAKE_AUTORCC ON)

if (USE_QT6)
	#set (CMAKE_PREFIX_PATH G:/Project/BEngine/Library/Windows/GUI/Qt/5.9.2/msvc2017_64/lib/cmake)
	find_package(Qt6 COMPONENTS Widgets Qml Quick QuickControls2 QuickWidgets REQUIRED)
	set (QT_LIBS Qt6::Widgets
				 Qt6::QuickWidgets
				 Qt6::Quick
				 Qt6::Qml
				 Qt6::QuickControls2)
else ()
	#set (CMAKE_PREFIX_PATH G:/Project/BEngine/Library/Windows/GUI/Qt/5.9.2/msvc2017_64/lib/cmake)
	find_package(Qt5 COMPONENTS Widgets Qml Quick QuickControls2 QuickWidgets REQUIRED)
	set (QT_LIBS Qt5::Widgets
				 Qt5::QuickWidgets
				 Qt5::Quick
				 Qt5::Qml
				 Qt5::QuickControls2)
endif ()
#[[
	MultiMedia
#]]
#add_subdirectory (${PROJECT_SOURCE_DIR}/../../Modules/MultiMedia MultiMedia)
#[[
	RHI
#]]
add_subdirectory (${PROJECT_SOURCE_DIR}/../../Modules/RHI/Source/VulkanRHI VulkanRHI)
add_subdirectory (${PROJECT_SOURCE_DIR}/../../Modules/RHI/Source/ES32RHI   ES32RHI)
if (CMAKE_SYSTEM_NAME STREQUAL Windows)
	add_subdirectory (${PROJECT_SOURCE_DIR}/../../Modules/RHI/Source/D3D12RHI  D3D12RHI)
endif ()
#add_subdirectory (${PROJECT_SOURCE_DIR}/../../Modules/RHI/Examples  RHIExamples)

#[[
	源码
#]]
file(GLOB_RECURSE SRC_LIST ${SRC_PREFIX} ${SRC_PREFIX}/*.cpp ${SRC_PREFIX}/*.c ${SRC_PREFIX}/*.h)

if (CMAKE_SYSTEM_NAME STREQUAL Windows)
	source_group (TREE "${SRC_PREFIX}" PREFIX ${PROJECT_NAME} FILES ${SRC_LIST})
endif ()

add_executable (${PROJECT_NAME}  ${SRC_LIST})

list(APPEND INCLUDE_PATH ${SRC_PREFIX})
list(APPEND LIBRARYS ${QT_LIBS}
					 VulkanRHI
					 ES32RHI
					 D3D12RHI)
if (CMAKE_HOST_SYSTEM_NAME MATCHES "Windows")
	list(APPEND INCLUDE_PATH ${LIBRARY_PATH}/Windows/GUI/SDL/3.2.24/msvc_2022/include)
	list(APPEND LINK_PATH    ${LIBRARY_PATH}/Windows/GUI/SDL/3.2.24/msvc_2022/lib)
	list(APPEND LIBRARYS SDL3)	

	list(APPEND INCLUDE_PATH ${LIBRARY_PATH}/Windows/Audio/SFML/3.0.2/vc17_64/include)
	list(APPEND LINK_PATH    ${LIBRARY_PATH}/Windows/Audio/SFML/3.0.2/vc17_64/lib)
	list(APPEND LIBRARYS sfml-main sfml-system sfml-audio sfml-window sfml-graphics)	

	list(APPEND INCLUDE_PATH ${LIBRARY_PATH}/Windows/Audio/irrKlang/include)
	list(APPEND LINK_PATH    ${LIBRARY_PATH}/Windows/Audio/irrKlang/lib)
	list(APPEND LIBRARYS irrKlang)	

	list(APPEND INCLUDE_PATH ${LIBRARY_PATH}/Windows/Audio/SoLoud/20200207/vc43/include)
	list(APPEND LINK_PATH    ${LIBRARY_PATH}/Windows/Audio/SoLoud/20200207/vc43/lib)

	list(APPEND INCLUDE_PATH ${LIBRARY_PATH}/Windows/File\ Format/3D/Assimp/6.0.2/vc143/include)
	list(APPEND LINK_PATH    ${LIBRARY_PATH}/Windows/File\ Format/3D/Assimp/6.0.2/vc143/lib)
	list(APPEND LIBRARYS assimp-vc143-mt)

	list(APPEND INCLUDE_PATH ${LIBRARY_PATH}/Windows/File\ Format/Imath/3.1/msvc_2022/include)
	list(APPEND LINK_PATH    ${LIBRARY_PATH}/Windows/File\ Format/Imath/3.1/msvc_2022/lib)
	list(APPEND LIBRARYS Imath-3_1)

	list(APPEND INCLUDE_PATH ${LIBRARY_PATH}/Windows/File\ Format/OpenEXR/3.2.1/msvc_2022/include)
	list(APPEND LINK_PATH    ${LIBRARY_PATH}/Windows/File\ Format/OpenEXR/3.2.1/msvc_2022/lib)
	list(APPEND LIBRARYS OpenEXR-3_2 OpenEXRCore-3_2 OpenEXRUtil-3_2)

	list(APPEND INCLUDE_PATH ${LIBRARY_PATH}/Windows/File\ Format/webp/1.6.0/msvc_2022/include)
	list(APPEND LINK_PATH    ${LIBRARY_PATH}/Windows/File\ Format/webp/1.6.0/msvc_2022/lib)
	list(APPEND LIBRARYS libwebp libwebpdecoder libwebpdemux libwebpmux libsharpyuv)

	list(APPEND INCLUDE_PATH ${LIBRARY_PATH}/Windows/File\ Format/giflib/5.2.2/msvc2022_64/include)
	list(APPEND LINK_PATH    ${LIBRARY_PATH}/Windows/File\ Format/giflib/5.2.2/msvc2022_64/lib)
	list(APPEND LIBRARYS giflib)

	list(APPEND INCLUDE_PATH ${LIBRARY_PATH}/Windows/Network/Curl/8.11/msvc2022_64/include)
	list(APPEND LINK_PATH    ${LIBRARY_PATH}/Windows/Network/Curl/8.11/msvc2022_64/lib)
	list(APPEND LIBRARYS libcurl_imp)

	list(APPEND INCLUDE_PATH ${LIBRARY_PATH}/Windows/Network/boost/1.84/msvc2022_64/include)
	list(APPEND LINK_PATH    ${LIBRARY_PATH}/Windows/Network/boost/1.84/msvc2022_64/lib)
	list(APPEND LIBRARYS libboost_system-vc143-mt-x64-1_84 libboost_exception-vc143-mt-x64-1_84 libboost_json-vc143-mt-x64-1_84)

	list(APPEND INCLUDE_PATH ${LIBRARY_PATH}/Windows/Codec/STB/2.27/msvc2019_64/include)
	list(APPEND LINK_PATH    ${LIBRARY_PATH}/Windows/Codec/STB/2.27/msvc2019_64/lib)
	list(APPEND LIBRARYS assimp-vc143-mt)

	list (APPEND INCLUDE_PATH   ${LIBRARY_PATH}/Windows/Codec/libmp3lame/3.100.2/vc143/include/)
	list (APPEND LINK_PATH      ${LIBRARY_PATH}/Windows/Codec/libmp3lame/3.100.2/vc143/lib/x64)
	list (APPEND LIBRARYS		libmp3lame mp3lame)

	list (APPEND INCLUDE_PATH   ${LIBRARY_PATH}/Windows/Codec/fdk-acc/2.0.3/vc143/include/)
	list (APPEND LINK_PATH      ${LIBRARY_PATH}/Windows/Codec/fdk-acc/2.0.3/vc143/lib/)
	list (APPEND LIBRARYS		fdk-aac)

	list (APPEND INCLUDE_PATH   ${LIBRARY_PATH}/Windows/Codec/opus/1.5.2/vc143/include/)
	list (APPEND LINK_PATH      ${LIBRARY_PATH}/Windows/Codec/opus/1.5.2/vc143/lib/)
	list (APPEND LIBRARYS		opus)

	list (APPEND INCLUDE_PATH   ${LIBRARY_PATH}/Windows/Codec/libogg/1.3.6/vc143/include/)
	list (APPEND LINK_PATH      ${LIBRARY_PATH}/Windows/Codec/libogg/1.3.6/vc143/lib/)
	list (APPEND LIBRARYS		ogg)

	list (APPEND INCLUDE_PATH   ${LIBRARY_PATH}/Windows/Codec/libtwolame/0.4.0/vc143/include/)
	list (APPEND LINK_PATH      ${LIBRARY_PATH}/Windows/Codec/libtwolame/0.4.0/vc143/lib/)
	list (APPEND LIBRARYS		libtwolame_dll)

	list (APPEND INCLUDE_PATH   ${LIBRARY_PATH}/Windows/Codec/libflac/1.5.0/vc143/include/)
	list (APPEND LINK_PATH      ${LIBRARY_PATH}/Windows/Codec/libflac/1.5.0/vc143/lib/)
	list (APPEND LIBRARYS		FLAC)

	list (APPEND INCLUDE_PATH   ${LIBRARY_PATH}/Windows/Codec/libvorbis/19/vc143/include/)
	list (APPEND LINK_PATH      ${LIBRARY_PATH}/Windows/Codec/libvorbis/19/vc143/lib/)
	list (APPEND LIBRARYS		vorbis	vorbisenc vorbisfile)

	list (APPEND INCLUDE_PATH   ${LIBRARY_PATH}/Windows/GUI/lvgl/9.4.0/msvc2022_64/include/)
	list (APPEND LINK_PATH      ${LIBRARY_PATH}/Windows/GUI/lvgl/9.4.0/msvc2022_64/lib/)
	list (APPEND LIBRARYS		LvglWindows)

	list (APPEND INCLUDE_PATH   ${LIBRARY_PATH}/Windows/HIK/include/)
	list (APPEND LINK_PATH      ${LIBRARY_PATH}/Windows/HIK/lib/)
	list (APPEND LIBRARYS		MvCameraControl)

	list (APPEND INCLUDE_PATH   ${LIBRARY_PATH}/Windows/MindVision/include/)
	list (APPEND LINK_PATH      ${LIBRARY_PATH}/Windows/MindVision/lib/)
	list (APPEND LIBRARYS		MVCAMSDK_X64)

	list (APPEND INCLUDE_PATH   ${LIBRARY_PATH}/Windows/Font/freetype/2.14.1/msvc2022_64/include)
	list (APPEND LINK_PATH      ${LIBRARY_PATH}/Windows/Font/freetype/2.14.1/msvc2022_64/lib/)
	list (APPEND LIBRARYS		freetype)
elseif (CMAKE_HOST_SYSTEM_NAME MATCHES "Linux")
	list(APPEND INCLUDE_PATH ${LIBRARY_PATH}/SFML/3.0.2/include)
	list(APPEND LINK_PATH    ${LIBRARY_PATH}/SFML/3.0.2/lib)
	list(APPEND LIBRARYS sfml-main sfml-system sfml-audio sfml-window sfml-graphics)	
	
	list(APPEND INCLUDE_PATH ${LIBRARY_PATH}/irrKlang/1.6/include)
	list(APPEND LINK_PATH    ${LIBRARY_PATH}/irrKlang/1.6/lib)
	list(APPEND LIBRARYS irrKlang)	
	
	list(APPEND INCLUDE_PATH ${LIBRARY_PATH}/assimp/6.0.2/include)
	list(APPEND LINK_PATH    ${LIBRARY_PATH}/assimp/6.0.2/lib)
	list(APPEND LIBRARYS libassimp)	
	
	list(APPEND INCLUDE_PATH ${LIBRARY_PATH}/libtwolame/0.4.0/include)
	list(APPEND LINK_PATH    ${LIBRARY_PATH}/libtwolame/0.4.0/lib)
	list(APPEND LIBRARYS libtwolame)	
	
	list(APPEND INCLUDE_PATH ${LIBRARY_PATH}/curl/8.11/include)
	list(APPEND LINK_PATH    ${LIBRARY_PATH}/curl/8.11/lib)
	list(APPEND LIBRARYS libcurl)	
	
	list(APPEND INCLUDE_PATH ${LIBRARY_PATH}/FLAC/1.5.0/include)
	list(APPEND LINK_PATH    ${LIBRARY_PATH}/FLAC/1.5.0/lib)
	list(APPEND LIBRARYS libFLAC++)	
	
	list(APPEND INCLUDE_PATH ${LIBRARY_PATH}/giflib/5.2.2/include)
	list(APPEND LINK_PATH    ${LIBRARY_PATH}/giflib/5.2.2/lib)
	list(APPEND LIBRARYS libtwolame)	
	
	list(APPEND INCLUDE_PATH ${LIBRARY_PATH}/ogg/1.3.6/include)
	list(APPEND LINK_PATH    ${LIBRARY_PATH}/ogg/1.3.6/lib)
	list(APPEND LIBRARYS libogg)	
	
	list(APPEND INCLUDE_PATH ${LIBRARY_PATH}/boost/1.84/include)
	list(APPEND LINK_PATH    ${LIBRARY_PATH}/boost/1.84/lib)
	list(APPEND LIBRARYS libboost_json libboost_exception libboost_thread)	
	
	list(APPEND INCLUDE_PATH ${LIBRARY_PATH}/fdk-acc/2.0.3/include)
	list(APPEND LINK_PATH    ${LIBRARY_PATH}/fdk-acc/2.0.3/lib)
	list(APPEND LIBRARYS libfdk-aac)	
	
	list(APPEND INCLUDE_PATH ${LIBRARY_PATH}/freetype/2.14.1/include)
	list(APPEND LINK_PATH    ${LIBRARY_PATH}/freetype/2.14.1/lib)
	list(APPEND LIBRARYS libfreetype)	
	
	list(APPEND INCLUDE_PATH ${LIBRARY_PATH}/Imath/3.2.2/include)
	list(APPEND LINK_PATH    ${LIBRARY_PATH}/Imath/3.2.2/lib)
	list(APPEND LIBRARYS libImath-3_2)	
	
	list(APPEND INCLUDE_PATH ${LIBRARY_PATH}/libmp3lame/3.100/include)
	list(APPEND LINK_PATH    ${LIBRARY_PATH}/libmp3lame/3.100/lib)
	list(APPEND LIBRARYS libmp3lame)	
	
	list(APPEND INCLUDE_PATH ${LIBRARY_PATH}/libvorbis/1.3.7/include)
	list(APPEND LINK_PATH    ${LIBRARY_PATH}/libvorbis/1.3.7/lib)
	list(APPEND LIBRARYS libvorbis libvorbisenc libvorbisfile)	
	
	list(APPEND INCLUDE_PATH ${LIBRARY_PATH}/OpenEXR/3.2.1/include)
	list(APPEND LINK_PATH    ${LIBRARY_PATH}/OpenEXR/3.2.1/lib)
	list(APPEND LIBRARYS libIex-3_2 libImath-3_1 libIlmThread-3_2 libOpenEXRCore-3_2 libOpenEXRUtil-3_2)	
	
	list(APPEND INCLUDE_PATH ${LIBRARY_PATH}/SDL/3.2.24/include)
	list(APPEND LINK_PATH    ${LIBRARY_PATH}/SDL/3.2.24/lib)
	list(APPEND LIBRARYS libSDL3)	

	list(APPEND INCLUDE_PATH ${LIBRARY_PATH}/opus/1.5.2/include)
	list(APPEND LINK_PATH    ${LIBRARY_PATH}/opus/1.5.2/lib)
	list(APPEND LIBRARYS libopus)	
	
	list(APPEND INCLUDE_PATH ${LIBRARY_PATH}/webp/1.6.0/include)
	list(APPEND LINK_PATH    ${LIBRARY_PATH}/webp/1.6.0/lib)
	list(APPEND LIBRARYS libwebp libwebpdecoder libwebpdemux libwebpmux)	
	
	list(APPEND INCLUDE_PATH ${LIBRARY_PATH}/lvgl/9.4.0/include)
	list(APPEND LINK_PATH    ${LIBRARY_PATH}/lvgl/9.4.0/lib)
	list(APPEND LIBRARYS liblvgl)	
	
	list(APPEND INCLUDE_PATH ${LIBRARY_PATH}/glfw/3.3.10/include)
	list(APPEND LINK_PATH    ${LIBRARY_PATH}/glfw/3.3.10/lib)
	list(APPEND LIBRARYS libglfw3)	
	
	list(APPEND INCLUDE_PATH ${LIBRARY_PATH}/stb/include)
	list(APPEND LINK_PATH    ${LIBRARY_PATH}/stb/lib)
	list(APPEND LIBRARYS )	
endif()
target_include_directories (${PROJECT_NAME}	PUBLIC ${INCLUDE_PATH})
target_link_directories (${PROJECT_NAME}	PUBLIC ${LINK_PATH})
target_link_libraries (${PROJECT_NAME} PUBLIC ${LIBRARYS})

if (CMAKE_SYSTEM_NAME STREQUAL Windows)
	target_compile_definitions (${PROJECT_NAME} SYSTEM_IS_WINDOWS)
elif (CMAKE_SYSTEM_NAME STREQUAL Linux)
	target_compile_definitions (${PROJECT_NAME} SYSTEM_IS_LINUX)
elif (CMAKE_SYSTEM_NAME STREQUAL Android)
	target_compile_definitions (${PROJECT_NAME} SYSTEM_IS_ANDROID)
endif ()
