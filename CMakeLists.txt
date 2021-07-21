project(usp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/out)

add_executable(manhattan_delivery icc_1/manhattan_delivery/manhattan_delivery.c)
add_executable(automatons icc_1/automatons/automatons.c)
add_executable(playlist_manager icc_1/playlist_manager/main.c)

add_executable(change_coins lab_icc_1/change_coins/change_coins.c)
add_executable(particle_simulation lab_icc_1/particle_simulation/particle_simulation.c)
add_executable(adding_surnames lab_icc_1/adding_surnames/adding_surnames.c)
add_executable(taboo_word lab_icc_1/taboo_word/taboo_word.c)

add_executable(fonte12v3v eletronica_1/fonte.c)

target_link_libraries(manhattan_delivery m)
target_link_libraries(fonte12v3v m)