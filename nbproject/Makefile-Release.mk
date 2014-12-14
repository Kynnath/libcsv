#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/CSV/CsvError.o \
	${OBJECTDIR}/src/CSV/Record.o \
	${OBJECTDIR}/src/CSV/Table.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-m64 -Wfatal-errors -Wall -Wextra -pedantic -Winit-self -Wmissing-include-dirs -Wswitch-default -Wswitch-enum -Wswitch-default -Wfloat-equal -Wshadow -Wcast-qual -Wcast-align -Wwrite-strings -Wconversion -Wsign-conversion -Wlogical-op -Wmissing-declarations -Wmissing-noreturn -Wmissing-format-attribute -Wpacked -Wredundant-decls -Wunreachable-code -Winvalid-pch -Wvolatile-register-var -Wdisabled-optimization -Wstack-protector -std=c++1y
CXXFLAGS=-m64 -Wfatal-errors -Wall -Wextra -pedantic -Winit-self -Wmissing-include-dirs -Wswitch-default -Wswitch-enum -Wswitch-default -Wfloat-equal -Wshadow -Wcast-qual -Wcast-align -Wwrite-strings -Wconversion -Wsign-conversion -Wlogical-op -Wmissing-declarations -Wmissing-noreturn -Wmissing-format-attribute -Wpacked -Wredundant-decls -Wunreachable-code -Winvalid-pch -Wvolatile-register-var -Wdisabled-optimization -Wstack-protector -std=c++1y

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblibcsv.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblibcsv.a: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblibcsv.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblibcsv.a ${OBJECTFILES} 
	$(RANLIB) ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblibcsv.a

${OBJECTDIR}/src/CSV/CsvError.o: src/CSV/CsvError.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/CSV
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Wall -s -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CSV/CsvError.o src/CSV/CsvError.cpp

${OBJECTDIR}/src/CSV/Record.o: src/CSV/Record.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/CSV
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Wall -s -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CSV/Record.o src/CSV/Record.cpp

${OBJECTDIR}/src/CSV/Table.o: src/CSV/Table.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/CSV
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Wall -s -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CSV/Table.o src/CSV/Table.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblibcsv.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
