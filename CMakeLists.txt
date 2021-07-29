project(usp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/out)

add_executable(manhattan_delivery icc_1/manhattan_delivery/manhattan_delivery.c)
add_executable(automatons icc_1/automatons/automatons.c)
add_executable(playlist_manager icc_1/playlist_manager/main.c)
add_executable(redrum icc_1/redrum/main.c)
add_executable(ascii_drawer icc_1/ascii_drawer/main.c)

add_executable(change_coins lab_icc_1/change_coins/change_coins.c)
add_executable(particle_simulation lab_icc_1/particle_simulation/particle_simulation.c)
add_executable(adding_surnames lab_icc_1/adding_surnames/adding_surnames.c)
add_executable(taboo_word lab_icc_1/taboo_word/main.c)
add_executable(polonese_notation lab_icc_1/polonese_notation/main.c)
add_executable(image_padding lab_icc_1/image_padding/main.c)
add_executable(attack_and_types lab_icc_1/attack_and_types/main.c)
add_executable(student_manager lab_icc_1/student_manager/main.c)
add_executable(pokedex lab_icc_1/pokedex/main.c)
add_executable(jit_compiler lab_icc_1/jit_compiler/main.c)

add_executable(fonte12v3v eletronica_1/fonte.c)

target_link_libraries(manhattan_delivery m)
target_link_libraries(fonte12v3v m)