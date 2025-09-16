message(STATUS "Launching EXE: ${EXE} | Output to: ${OUT}")  # Для отладки: покажет в логе сборки

execute_process(COMMAND "${EXE}" OUTPUT_FILE "${OUT}" ERROR_FILE "${OUT}" RESULT_VARIABLE rv)
if(NOT rv EQUAL 0)
   message(WARNING "Program exit code: ${rv} (output saved to ${OUT})")
endif()