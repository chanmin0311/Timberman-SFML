cmake_minimum_required(VERSION 3.10)
project(Timber)

set(CMAKE_CXX_STANDARD 17)
set(SFML_DIR "~/")
# 소스 디렉토리 설정
set(SRC_DIR src)

# 소스 파일 목록
file(GLOB SOURCES "${SRC_DIR}/*.cpp")

# SMFL 라이브러리 설정
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

# 실행 파일 생성
add_executable(${PROJECT_NAME} ${SOURCES})

# SFML 라이브러리 링크
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics)

# 빌드 출력 디렉토리 설정 (프로젝트 루트의 bin 폴더에 생성)
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)
