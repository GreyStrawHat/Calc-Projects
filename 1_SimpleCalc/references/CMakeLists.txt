project(SimpleCalcDocs NONE)
cmake_minimum_required(VERSION 3.10)

find_package(LATEX REQUIRED)
find_package(LATEX COMPONENTS PDFLATEX REQUIRED)

SET(CALCFOLDER "1_SimpleCalc" )
SET ( JOB_NAME "simplecalc" )

SET( MAIN_TEX_BASE_FILENAME "${JOB_NAME}")
SET( MAIN_TEX "${CMAKE_CURRENT_SOURCE_DIR}/${MAIN_TEX_BASE_FILENAME}.tex")
SET ( OUTPUT_DIR "${CMAKE_BINARY_DIR}/${CALCFOLDER}/" )
SET ( PRODUCT_PATH "${OUTPUT_DIR}${JOB_NAME}.pdf")
# First pass.
add_custom_target( simplecalc-latex-prebuild
COMMAND ${PDFLATEX_COMPILER} -jobname ${JOB_NAME} -output-directory ${OUTPUT_DIR} -draftmode -interaction=nonstopmode ${MAIN_TEX}
COMMENT "Starting Prebuild."
WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/"
DEPENDS ${MAIN_TEX})

# Second pass - Resolve references.
add_custom_target( simplecalc-latex-pdf-one	
    COMMAND ${PDFLATEX_COMPILER} -jobname ${JOB_NAME} -output-directory ${OUTPUT_DIR} ${MAIN_TEX}
    WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/"
    COMMENT "Reloving references for the final pdf file."
    DEPENDS  ${MAIN_TEX})

# Second pass - Resolve table of contents/generate final pdf.
add_custom_target( simplecalc-latex-pdf-two
    COMMAND ${PDFLATEX_COMPILER} -jobname ${JOB_NAME} -output-directory ${OUTPUT_DIR} ${MAIN_TEX}
    WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/"
    COMMENT "Assembling the final pdf file."
    DEPENDS  ${MAIN_TEX})

add_custom_target(simplecalc-all-formats ALL) # Entry point of execution.
add_dependencies( simplecalc-all-formats simplecalc-latex-pdf-two )
add_dependencies( simplecalc-latex-pdf-two simplecalc-latex-pdf-one)
add_dependencies( simplecalc-latex-pdf-one simplecalc-latex-prebuild)

install(FILES ${PRODUCT_PATH} DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})