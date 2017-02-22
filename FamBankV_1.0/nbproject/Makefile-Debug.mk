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
CC=arm-brcm-linux-gnueabi-gcc
CCC=arm-brcm-linux-gnueabi-g++
CXX=arm-brcm-linux-gnueabi-g++
FC=gfortran.exe
AS=as

# Macros
CND_PLATFORM=Gnueabi-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include NbMakefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/wub_lib.o \
	${OBJECTDIR}/gsm.o \
	${OBJECTDIR}/start.o \
	${OBJECTDIR}/Setting.o \
	${OBJECTDIR}/moremenu.o \
	${OBJECTDIR}/debug2.o \
	${OBJECTDIR}/Transaction.o \
	${OBJECTDIR}/mainmenu.o


# C Compiler Flags
CFLAGS="-I${SDKV3INC}" -fsigned-char -Wundef -Wstrict-prototypes -Wno-trigraphs -Wimplicit -Wformat 

# CC Compiler Flags
CCFLAGS="-I${SDKV3INC}" -fsigned-char -Wundef -Wno-trigraphs -Wimplicit -Wformat 
CXXFLAGS="-I${SDKV3INC}" -fsigned-char -Wundef -Wno-trigraphs -Wimplicit -Wformat 

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lcaethernet -lcafont -lcafs -lcakms -lcalcd -lcamodem -lcapmodem -lcaprt -lcartc -lcauart -lcauldpm -lcausbh -lcagsm -lcabarcode -lpthread -ldl -lcaclvw -lcatls -lctosapi -lcrypto -lcurl -lssl -lz -lfreetype

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk dist/V3/Debug/FamBankV_1.0.exe

dist/V3/Debug/FamBankV_1.0.exe: ${OBJECTFILES}
	${MKDIR} -p dist/V3/Debug
	arm-brcm-linux-gnueabi-g++ -L . "-L${SDKV3LIB}" "-L${SDKV3LIBN}" -o dist/V3/Debug/FamBankV_1.0  ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/wub_lib.o: wub_lib.c 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.c) -g -I/cygdrive/C/Program\ Files/Castles/VEGA3000/include -I/cygdrive/C/Program\ Files\ \(x86\)/Castles/VEGA3000/include -o ${OBJECTDIR}/wub_lib.o wub_lib.c

${OBJECTDIR}/gsm.o: gsm.c 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.c) -g -I/cygdrive/C/Program\ Files/Castles/VEGA3000/include -I/cygdrive/C/Program\ Files\ \(x86\)/Castles/VEGA3000/include -o ${OBJECTDIR}/gsm.o gsm.c

${OBJECTDIR}/start.o: start.c 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.c) -g -I/cygdrive/C/Program\ Files/Castles/VEGA3000/include -I/cygdrive/C/Program\ Files\ \(x86\)/Castles/VEGA3000/include -o ${OBJECTDIR}/start.o start.c

${OBJECTDIR}/Setting.o: Setting.c 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.c) -g -I/cygdrive/C/Program\ Files/Castles/VEGA3000/include -I/cygdrive/C/Program\ Files\ \(x86\)/Castles/VEGA3000/include -o ${OBJECTDIR}/Setting.o Setting.c

${OBJECTDIR}/moremenu.o: moremenu.c 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.c) -g -I/cygdrive/C/Program\ Files/Castles/VEGA3000/include -I/cygdrive/C/Program\ Files\ \(x86\)/Castles/VEGA3000/include -o ${OBJECTDIR}/moremenu.o moremenu.c

${OBJECTDIR}/debug2.o: debug2.c 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.c) -g -I/cygdrive/C/Program\ Files/Castles/VEGA3000/include -I/cygdrive/C/Program\ Files\ \(x86\)/Castles/VEGA3000/include -o ${OBJECTDIR}/debug2.o debug2.c

${OBJECTDIR}/Transaction.o: Transaction.c 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.c) -g -I/cygdrive/C/Program\ Files/Castles/VEGA3000/include -I/cygdrive/C/Program\ Files\ \(x86\)/Castles/VEGA3000/include -o ${OBJECTDIR}/Transaction.o Transaction.c

${OBJECTDIR}/mainmenu.o: mainmenu.c 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.c) -g -I/cygdrive/C/Program\ Files/Castles/VEGA3000/include -I/cygdrive/C/Program\ Files\ \(x86\)/Castles/VEGA3000/include -o ${OBJECTDIR}/mainmenu.o mainmenu.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} dist/V3/Debug/FamBankV_1.0.exe

# Subprojects
.clean-subprojects:
