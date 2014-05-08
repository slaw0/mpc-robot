# ------------------- Required for MSVC nmake ---------------------------------
# This file should be included at the top of a MAKEFILE as follows:


!include <ntwin32.mak>

MACHINE     = MPC_framework
TARGET      = sfun
CHART_SRCS 	= \
		c1_MPC_framework.c\
		c2_MPC_framework.c\
		c3_MPC_framework.c\
		c4_MPC_framework.c\
		c7_MPC_framework.c\
		c8_MPC_framework.c
MACHINE_SRC	= MPC_framework_sfun.c
MACHINE_REG = MPC_framework_sfun_registry.c
MEX_WRAPPER =
MAKEFILE    = MPC_framework_sfun.mak
MATLAB_ROOT	= c:\matlab\r2006a
BUILDARGS   =

#--------------------------- Tool Specifications ------------------------------
#
#
MSVC_ROOT1 = $(MSDEVDIR:SharedIDE=vc)
MSVC_ROOT2 = $(MSVC_ROOT1:SHAREDIDE=vc)
MSVC_ROOT  = $(MSVC_ROOT2:sharedide=vc)

# Compiler tool locations, CC, LD, LIBCMD:
CC     = cl.exe
LD     = link.exe
LIBCMD = lib.exe
#------------------------------ Include/Lib Path ------------------------------

USER_INCLUDES   =  /I "c:\users\opra\mpc-555 robot\mpc-robot\sfprj\build\mpc_framework\sfun\src" /I "c:\users\opra\mpc-555 robot\mpc-robot"
ML_INCLUDES     = /I "$(MATLAB_ROOT)\extern\include"
SL_INCLUDES     = /I "$(MATLAB_ROOT)\simulink\include"
SF_INCLUDES     = /I "c:\matlab\r2006a\stateflow\c\mex\include" /I "c:\matlab\r2006a\stateflow\c\debugger\include"

DSP_INCLUDES    = /I "c:\matlab\r2006a\toolbox\eml\lib\dsp"

COMPILER_INCLUDES = /I "$(MSVC_ROOT)\include"

INCLUDE_PATH = $(USER_INCLUDES) $(ML_INCLUDES) $(SL_INCLUDES) $(SF_INCLUDES) $(DSP_INCLUDES)
LIB_PATH     = "$(MSVC_ROOT)\lib"

CFLAGS = $(COMPFLAGS) /MD
LDFLAGS = /nologo /dll /OPT:NOREF /export:mexFunction

#----------------------------- Source Files -----------------------------------

REQ_SRCS  = $(MACHINE_SRC) $(MACHINE_REG) $(MEX_WRAPPER) $(CHART_SRCS)

USER_ABS_OBJS =

REQ_OBJS = $(REQ_SRCS:.cpp=.obj)
REQ_OBJS2 = $(REQ_OBJS:.c=.obj)
OBJS = $(REQ_OBJS2) $(USER_ABS_OBJS)
OBJLIST_FILE = MPC_framework_sfun.mol
SFCLIB = "c:\matlab\r2006a\stateflow\c\mex\lib\win32\sfc_mexmsvc71.lib" "c:\matlab\r2006a\stateflow\c\debugger\lib\win32\sfc_debugmsvc71.lib"
USER_LIBS =
LINK_MACHINE_LIBS =

DSP_LIBS    = "c:\matlab\r2006a\toolbox\dspblks\lib\win32\dsp_dyn_rt_vc.lib"

#--------------------------------- Rules --------------------------------------

MEX_FILE_NAME_WO_EXT = $(MACHINE)_$(TARGET)
MEX_FILE_NAME = $(MEX_FILE_NAME_WO_EXT).mexw32
MEX_FILE_CSF =
all : $(MEX_FILE_NAME) $(MEX_FILE_CSF)

MEXLIB = "C:\MATLAB\R2006a\extern\lib\win32\microsoft\libmx.lib" "C:\MATLAB\R2006a\extern\lib\win32\microsoft\libmex.lib" "C:\MATLAB\R2006a\extern\lib\win32\microsoft\libmat.lib" "C:\MATLAB\R2006a\extern\lib\win32\microsoft\libfixedpoint.lib" "C:\MATLAB\R2006a\extern\lib\win32\microsoft\libut.lib"

$(MEX_FILE_NAME) : $(MAKEFILE) $(OBJS) $(SFCLIB) $(USER_LIBS)
	@echo ### Linking ...
	$(LD) $(LDFLAGS) /OUT:$(MEX_FILE_NAME) /map:"$(MEX_FILE_NAME_WO_EXT).map" $(USER_LIBS) $(SFCLIB) $(MEXLIB) $(LINK_MACHINE_LIBS) $(DSP_LIBS) @$(OBJLIST_FILE)
	@echo ### Created $@

.c.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"

.cpp.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"

