file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

#include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty")

add_executable(${tabletest} ${srcs} ${hdrs}) #Создаем проект с именем из переменной ${tabletest}, в него добавляются файлы из переменных ${srcs} и ${hdrs}
target_link_libraries(${tabletest} ${tablelib} gtest) #Подключаем к проекту с именем ${table} библиотеки с именами ${tablelib} и gtest
