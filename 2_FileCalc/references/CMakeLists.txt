project(SimpleCalcDocs NONE)
cmake_minimum_required(VERSION 3.10)

find_package(LATEX REQUIRED)
find_package(LATEX COMPONENTS PDFLATEX REQUIRED)

SET(CALCFOLDER "2_FileCalc" )
SET (JOB_NAME "filecalc" )
SET (JOB_NAME_TWO "FileSpec" )

SET( MAIN_TEX_BASE_FILENAME "${JOB_NAME}")
SET( MAIN_TEX_BASE_FILENAME_TWO "${JOB_NAME_TWO}")
SET( MAIN_TEX "${CMAKE_CURRENT_SOURCE_DIR}/${MAIN_TEX_BASE_FILENAME}.tex")
SET( MAIN_TEX_TWO "${CMAKE_CURRENT_SOURCE_DIR}/${MAIN_TEX_BASE_FILENAME_TWO}.tex")
SET ( OUTPUT_DIR "${CMAKE_BINARY_DIR}/${CALCFOLDER}/" )
SET ( PRODUCT_PATH "${OUTPUT_DIR}${JOB_NAME}.pdf")
SET ( PRODUCT_PATH_TWO "${OUTPUT_DIR}${JOB_NAME_TWO}.pdf")

# First pass.
add_custom_target( filecalc-latex-prebuild
COMMAND ${PDFLATEX_COMPILER} -jobname ${JOB_NAME} -output-directory ${OUTPUT_DIR} -draftmode -interaction=nonstopmode ${MAIN_TEX}
COMMENT "Starting Prebuild."
WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/"
DEPENDS ${MAIN_TEX})

# Second pass - Resolve references.
add_custom_target( filecalc-latex-pdf-one	
    COMMAND ${PDFLATEX_COMPILER} -jobname ${JOB_NAME} -output-directory ${OUTPUT_DIR} ${MAIN_TEX}
    WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/"
    COMMENT "Reloving references for the final pdf file."
    DEPENDS  ${MAIN_TEX})

# Second pass - Resolve table of contents/generate final pdf.
add_custom_target( filecalc-latex-pdf-two
    COMMAND ${PDFLATEX_COMPILER} -jobname ${JOB_NAME} -output-directory ${OUTPUT_DIR} ${MAIN_TEX}
    WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/"
    COMMENT "Assembling the final pdf file."
    DEPENDS  ${MAIN_TEX})

    # First pass.
add_custom_target( filespec-latex-prebuild
COMMAND ${PDFLATEX_COMPILER} -jobname ${JOB_NAME_TWO} -output-directory ${OUTPUT_DIR} -draftmode -interaction=nonstopmode ${MAIN_TEX_TWO}
COMMENT "Starting Prebuild."
WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/"
DEPENDS ${MAIN_TEX})

# Second pass - Resolve references.
add_custom_target( filespec-latex-pdf-one	
    COMMAND ${PDFLATEX_COMPILER} -jobname ${JOB_NAME_TWO} -output-directory ${OUTPUT_DIR} ${MAIN_TEX_TWO}
    WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/"
    COMMENT "Reloving references for the final pdf file."
    DEPENDS  ${MAIN_TEX})

# Second pass - Resolve table of contents/generate final pdf.
add_custom_target( filespec-latex-pdf-two
    COMMAND ${PDFLATEX_COMPILER} -jobname ${JOB_NAME_TWO} -output-directory ${OUTPUT_DIR} ${MAIN_TEX_TWO}
    WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/"
    COMMENT "Assembling the final pdf file."
    DEPENDS  ${MAIN_TEX})

add_custom_target(filecalc-all-formats ALL) # Entry point of execution.
add_dependencies( filecalc-all-formats filecalc-latex-pdf-two )
add_dependencies( filecalc-latex-pdf-two filecalc-latex-pdf-one)
add_dependencies( filecalc-latex-pdf-one filecalc-latex-prebuild)

add_custom_target(filespec-all-formats ALL) # Entry point of execution.
add_dependencies( filespec-all-formats filespec-latex-pdf-two )
add_dependencies( filespec-latex-pdf-two filespec-latex-pdf-one)
add_dependencies( filespec-latex-pdf-one filespec-latex-prebuild)

install(FILES ${PRODUCT_PATH} DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})
install(FILES ${PRODUCT_PATH_TWO} DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})