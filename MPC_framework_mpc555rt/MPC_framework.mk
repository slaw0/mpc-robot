# Copyright 2001-2005 The MathWorks, Inc.
#
# File    : MPC_framework.mk   $Revision: 1.23.4.18 $
# $Date: 2005/12/15 21:14:46 $
# Abstract:
#	Real-Time Workshop template makefile for building
#	stand-alone embedded real-time version of Simulink model using
#	generated C code and Diab Data Power PC Compiler 4.3g

MAKECMD         = "C:/MATLAB/R2006a\toolbox\rtw\targets\mpc555dk\bin\win32\make.exe"
HOST            = PC
BUILD           = yes
SYS_TARGET_FILE = mpc555rt.tlc
BUILD_SUCCESS   = Completed MPC555 make phase
MAKEFILE_FILESEP= /			


MODEL                   = MPC_framework
MODULES                 = MPC_framework_data.c can_frame_ground.c rt_nonfinite.c 
MAKEFILE                = MPC_framework.mk
MATLAB_ROOT             = $(subst \,/,C:/MATLAB/R2006a)
ALT_MATLAB_ROOT         = $(subst \,/,C:/MATLAB/R2006a)
S_FUNCTIONS             = 
S_FUNCTIONS_LIB         = 
NUMST                   = 2
NCSTATES                = 0
COMPUTER                = PCWIN
BUILDARGS               =  MPC555_OPTIMIZATION_SWITCH="speed" EXECUTION_PROFILING_NUM_SAMPLES=500 RELATIVE_PATH_TO_ANCHOR=..
MULTITASKING            = 1
INTEGER_CODE            = 0
MAT_FILE                = 0
ONESTEPFCN              = 1
TERMFCN                 = 1
B_ERTSFCN               = 0
MEXEXT                  = mexw32
EXT_MODE                = 0
EXTMODE_TRANSPORT       = 0
EXTMODE_STATIC          = 0
EXTMODE_STATIC_SIZE     = 1000000
MULTI_INSTANCE_CODE     = 0
ADD_MDL_NAME_TO_GLOBALS = 1
STATIC_RTWLIB           = 1
BASE_RATE_MAX_OVERRUNS  = 5
SUB_RATE_MAX_OVERRUNS   = 0

MODELREFS               = 
MODELLIB                = MPC_frameworklib.a
MODELREF_LINK_LIBS      = 
MODELREF_INC_PATH       = 
MODELREF_TARGET_TYPE    = NONE

SHARED_BIN_DIR          = $(subst \,/,)
SHARED_LIB              = $(subst \,/,)
SHARED_SRC              = $(subst \,/,)
SHARED_SRC_DIR          = $(subst \,/,)

ifneq ("$(MATLAB_ROOT)","$(ALT_MATLAB_ROOT)")
MATLAB_ROOT = $(ALT_MATLAB_ROOT)
endif
ifneq ("$(MATLAB_BIN)","$(ALT_MATLAB_BIN)")
MATLAB_BIN = $(ALT_MATLAB_BIN)
endif

#-----------------------------------------------------
# Include the make variables defined from TLC file
#-----------------------------------------------------
include $(MODEL)_makevars.mk

include $(MATLAB_ROOT)/toolbox/rtw/targets/mpc555dk/rt_makevars.mk

#-------------------------------- C Flags --------------------------------------
PROFILE_SRCS = profile.c
ifeq ($(EXECUTION_PROFILING_ENABLED),1)
   PROFILING_OPTS = -DPROFILING_ENABLED  -DPROFILING_NUM_SAMPLES=$(EXECUTION_PROFILING_NUM_SAMPLES)
endif
#----------------------------- External mode -----------------------------------
# Uncomment -DVERBOSE to have information printed to stdout (or specify
# OPTS=-DVERBOSE).
ifeq ($(EXT_MODE),1)
   $(error Simulink external mode is not supported by Embedded Target for Motorola MPC555)
endif

# Determine if we are generating an s-function
SFCN = 0
ifeq ($(GEN_MDLREF_SFCN),1)
  SFCN = 1
endif
ifeq ($(B_ERTSFCN),1)
  SFCN = 1
endif
#------------------------------ Include Path -----------------------------------

MATLAB_INCLUDES = \
	-I$(MATLAB_ROOT)/rtw/c/ert \
	-I$(MATLAB_ROOT)/extern/include \
	-I$(MATLAB_ROOT)/simulink/include \
	-I$(MATLAB_ROOT)/rtw/c/src \
	-I$(MATLAB_ROOT)/toolbox/rtw/targets/common/profile/execution

# Additional includes 
ADD_INCLUDES = \
	-I"C:/Users/Opra/MPC-555 Robot/mpc-robot/MPC_framework_mpc555rt" \
	-I"C:/Users/Opra/MPC-555 Robot/mpc-robot" \
	-IC:/Users/Opra/MPC-55~1/MPC-RO~1 \
	-IC:/Users/Opra/MPC-55~1/MPC-RO~1/MPC_FR~1 \
	-I$(MATLAB_ROOT)/rtw/c/libsrc \
	-I$(MATLAB_ROOT)/toolbox/rtw/targets/common/can/datatypes \
	-I$(MATLAB_ROOT)/toolbox/rtw/targets/common/can/blocks/tlc_c \
	-I$(MATLAB_ROOT)/toolbox/rtw/targets/mpc555dk/drivers/src/libsrc/standard/include \
	-I$(MATLAB_ROOT)/toolbox/rtw/targets/mpc555dk/rt/blockset/tlc_c \


SHARED_INCLUDES = 
ifneq ($(SHARED_SRC_DIR),)
SHARED_INCLUDES = -I$(SHARED_SRC_DIR)
endif

INCLUDES += -I. -I.. $(MATLAB_INCLUDES) $(ADD_INCLUDES) $(USER_INCLUDES) \
	$(INSTRUMENT_INCLUDES) $(SHARED_INCLUDES) $(MODELREF_INC_PATH) \
        -I$(RELATIVE_PATH_TO_ANCHOR)


#-------------------------------- C Flags --------------------------------------

#####################################################################
# Select between RAM and FLASH targets
#####################################################################

# Optimization Options
MPC555_OPTIMIZATION_FLAGS := $(OPT_OPTS)
MPC555_DEBUG_FLAGS := $(DEBUG_OPTS)

ifeq ($(MODELREF_TARGET_TYPE), NONE)
 # Top-level model for RTW
	ifeq (FLASH,RAM)
   COMPONENT=external_ram
   PRODUCT_SUFFIX=_ram.s19
 else
   COMPONENT=internal_flash
   PRODUCT_SUFFIX=_flash.s19
 endif
else
 # sub-model for RTW
 # no target memory model
 COMPONENT=mpc555_build_rules
endif

.PHONY : default
default : all 

include $(MPC555DK_ROOT)/drivers/make_plugins/component_manager.mk

# General User Options
OPTS =

# Compiler options, etc: 
CC_OPTS = $(OPTS) $(ANSI_OPTS) $(PROFILING_OPTS)

CPP_REQ_DEFINES = -DMODEL=$(MODEL) -DNUMST=$(NUMST) \
		  -DUNIX -DMT=$(MULTITASKING) -DNCSTATES=$(NCSTATES) \
		  -DMAT_FILE=$(MAT_FILE) -DINTEGER_CODE=$(INTEGER_CODE) \
		  -DONESTEPFCN=$(ONESTEPFCN) -DTERMFCN=$(TERMFCN) \
		  -DMULTI_INSTANCE_CODE=$(MULTI_INSTANCE_CODE)\
		  -DADD_MDL_NAME_TO_GLOBALS=$(ADD_MDL_NAME_TO_GLOBALS)\
		  -DBASE_RATE_MAX_OVERRUNS=$(BASE_RATE_MAX_OVERRUNS)\
		  -DSUB_RATE_MAX_OVERRUNS=$(SUB_RATE_MAX_OVERRUNS)

# The MPC555 does not require STDIO
# CPP_REQ_DEFINES += -DHAVESTDIO 

CFLAGS += $(CC_OPTS) $(CPP_REQ_DEFINES) 

LDFLAGS +=

#-------------------------- Additional Libraries ------------------------------
# Expand any possibly precompiled libraries - eg. RTW, DSP
#
# We handle precompiled libraries specially depending on the
# static rtwlib option in the rtwoptions gui. 

ifeq ($(STATIC_RTWLIB),0)
  # Build a dynamic library
  LIBS += rtwlib.a
else
  # Use the static library
  LIBS += $(MATLAB_ROOT)/toolbox/rtw/targets/mpc555dk/drivers/lib/CODE_WARRIOR/rtwlib.a
endif


# These libraries will be built in the build directory. There
# are no precompiled sources. These library types can be 
# triggered by setting the 
# 	Precompile flag = 0
# in the rtwmakecfg.m files 

LIBS += $(S_FUNCTIONS_LIB) $(INSTRUMENT_LIBS) $(SHARED_LIB_TARGET)

#----------------------------- Source Files ------------------------------------

SRCS  = $(MODULES) $(S_FUNCTIONS) 

ifeq ($(MODELREF_TARGET_TYPE), NONE)
   # Top-level model for RTW
   PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/$(MODEL)$(PRODUCT_SUFFIX)
   define BIN_SETTING
      $(build-srec-file)
   endef
   BUILD_PRODUCT_TYPE = "executable"
   SRCS += $(MODEL).c mpc555dk_main.c $(EXT_SRC) $(PROFILE_SRCS)
else
   # sub-model for RTW
   PRODUCT = $(MODELLIB)
   BUILD_PRODUCT_TYPE = "library"
endif

# wildcard expand shared src files
SHARED_SRC := $(wildcard $(SHARED_SRC))
# derive object names
SHARED_OBJECTS = $(addsuffix .o, $(basename $(notdir $(SHARED_SRC))))

USER_OBJECTS       = $(addsuffix .o, $(basename $(USER_SRCS)))
LOCAL_USER_OBJECTS = $(notdir $(USER_OBJECTS))

OBJECTS      += $(addsuffix .o, $(basename $(SRCS))) $(LOCAL_USER_OBJECTS)

#--------------------------------- Rules ---------------------------------------

.PHONY : all
all : setup $(PRODUCT)

ifeq ($(MODELREF_TARGET_TYPE),NONE)
# Top-level model for RTW
LIBS += $(MODELREF_LINK_LIBS)
$(PRODUCT) : $(OBJECT_TARGETS) $(LIBS) $(LINKER_COMMAND_FILE)
	@echo "-------------------------------------"
	@echo "LIBS = $(LIBS)"
	@echo "SHARED_LIB = $(SHARED_LIB)"
	@echo "SHARED_LIB_TARGET = $(SHARED_LIB_TARGET)"
	@echo "-------------------------------------"
	$(BIN_SETTING)
	@echo \#\#\# $(BUILD_SUCCESS)
else
# sub-model for RTW
$(PRODUCT) : $(OBJECT_TARGETS) $(SHARED_OBJECT_TARGETS)
	@echo "-------------------------------------"
	@echo "OBJECT_TARGETS = $(OBJECT_TARGETS)"
	@echo "SHARED_OBJECT_TARGETS = $(SHARED_OBJECT_TARGETS)"
	@echo "-------------------------------------"
	$(RM) $(MODELLIB)
	$(LIBCMD) $(MODELLIB) $(OBJECT_TARGETS)
	@echo "### $(MODELLIB) Created"
	@echo "### Created $(BUILD_PRODUCT_TYPE): $@"
	@echo "### $(BUILD_SUCCESS)"
endif

#################################################
# Shared Utilities Library                      #
#                                               #
# SHARED_LIB_TARGET is a modified version of    #
# SHARED_LIB that adds in toolchain and variant	#
# dirs to the library path                      #
#                                               #
#################################################
$(SHARED_LIB_TARGET) : $(SHARED_OBJECT_TARGETS)
	@echo
	@echo --------------------------------------
	@echo "### Creating $@ from $(SHARED_OBJECT_TARGETS)"
	$(LIBCMD) $@ $(SHARED_OBJECT_TARGETS)
	@echo "### Created $@"
	@echo --------------------------------------
	@echo

vpath %.c  .. \
           $(MATLAB_ROOT)/rtw/c/ert \
           $(MATLAB_ROOT)/rtw/c/src \
           $(MATLAB_ROOT)/simulink/src \
           $(MPC555DK_ROOT)/mpc555dk \
           $(MPC555DK_ROOT)/../common/profile/execution \
           $(SHARED_SRC_DIR) \
	$(MATLAB_ROOT)/rtw/c/src \
	$(MATLAB_ROOT)/toolbox/rtw/targets/common/configuration/resource \
	$(MATLAB_ROOT)/toolbox/rtw/targets/common/can/blocks/tlc_c \
	$(MATLAB_ROOT)/toolbox/rtw/targets/mpc555dk/rt/blockset/tlc_c \
	$(MATLAB_ROOT)/rtw/c/libsrc \


#------------------------------- Libraries -------------------------------------



#------------------------------- PRECOMP Libraries -------------------------------------

MODULES_rtwlib = \
    $(OBJDIR)/rt_atan2.o \
    $(OBJDIR)/rt_atan232.o \
    $(OBJDIR)/rt_backsubcc_dbl.o \
    $(OBJDIR)/rt_backsubcc_sgl.o \
    $(OBJDIR)/rt_backsubrc_dbl.o \
    $(OBJDIR)/rt_backsubrc_sgl.o \
    $(OBJDIR)/rt_backsubrr_dbl.o \
    $(OBJDIR)/rt_backsubrr_sgl.o \
    $(OBJDIR)/rt_enab.o \
    $(OBJDIR)/rt_forwardsubcc_dbl.o \
    $(OBJDIR)/rt_forwardsubcc_sgl.o \
    $(OBJDIR)/rt_forwardsubcr_dbl.o \
    $(OBJDIR)/rt_forwardsubcr_sgl.o \
    $(OBJDIR)/rt_forwardsubrc_dbl.o \
    $(OBJDIR)/rt_forwardsubrc_sgl.o \
    $(OBJDIR)/rt_forwardsubrr_dbl.o \
    $(OBJDIR)/rt_forwardsubrr_sgl.o \
    $(OBJDIR)/rt_hypot.o \
    $(OBJDIR)/rt_hypot32.o \
    $(OBJDIR)/rt_i32zcfcn.o \
    $(OBJDIR)/rt_interpolate.o \
    $(OBJDIR)/rt_intrp1flatcd.o \
    $(OBJDIR)/rt_intrp1flatcf.o \
    $(OBJDIR)/rt_intrp1flatd.o \
    $(OBJDIR)/rt_intrp1flatf.o \
    $(OBJDIR)/rt_intrp1lincd.o \
    $(OBJDIR)/rt_intrp1lincf.o \
    $(OBJDIR)/rt_intrp1linxd.o \
    $(OBJDIR)/rt_intrp1linxf.o \
    $(OBJDIR)/rt_intrp2flatcd.o \
    $(OBJDIR)/rt_intrp2flatcf.o \
    $(OBJDIR)/rt_intrp2flatd.o \
    $(OBJDIR)/rt_intrp2flatf.o \
    $(OBJDIR)/rt_intrp2lincd.o \
    $(OBJDIR)/rt_intrp2lincf.o \
    $(OBJDIR)/rt_intrp2lind.o \
    $(OBJDIR)/rt_intrp2linf.o \
    $(OBJDIR)/rt_intrp2linxd.o \
    $(OBJDIR)/rt_intrp2linxf.o \
    $(OBJDIR)/rt_intrp3lind.o \
    $(OBJDIR)/rt_intrp3linf.o \
    $(OBJDIR)/rt_intrp4lind.o \
    $(OBJDIR)/rt_intrp4linf.o \
    $(OBJDIR)/rt_intrp5lind.o \
    $(OBJDIR)/rt_intrp5linf.o \
    $(OBJDIR)/rt_intrpnflatcd.o \
    $(OBJDIR)/rt_intrpnflatcf.o \
    $(OBJDIR)/rt_intrpnflatd.o \
    $(OBJDIR)/rt_intrpnflatf.o \
    $(OBJDIR)/rt_intrpnlincd.o \
    $(OBJDIR)/rt_intrpnlincf.o \
    $(OBJDIR)/rt_intrpnlind.o \
    $(OBJDIR)/rt_intrpnlinf.o \
    $(OBJDIR)/rt_intrpnlinxd.o \
    $(OBJDIR)/rt_intrpnlinxf.o \
    $(OBJDIR)/rt_intrpnspld.o \
    $(OBJDIR)/rt_intrpnsplf.o \
    $(OBJDIR)/rt_logging.o \
    $(OBJDIR)/rt_look.o \
    $(OBJDIR)/rt_look1d.o \
    $(OBJDIR)/rt_look1d32.o \
    $(OBJDIR)/rt_look2d32_general.o \
    $(OBJDIR)/rt_look2d32_normal.o \
    $(OBJDIR)/rt_look2d_general.o \
    $(OBJDIR)/rt_look2d_normal.o \
    $(OBJDIR)/rt_look32.o \
    $(OBJDIR)/rt_lookflat1bincsd.o \
    $(OBJDIR)/rt_lookflat1bincsf.o \
    $(OBJDIR)/rt_lookflat1binczd.o \
    $(OBJDIR)/rt_lookflat1binczf.o \
    $(OBJDIR)/rt_lookflat1evncsd.o \
    $(OBJDIR)/rt_lookflat1evncsf.o \
    $(OBJDIR)/rt_lookflat1evnczd.o \
    $(OBJDIR)/rt_lookflat1evnczf.o \
    $(OBJDIR)/rt_lookflat1lincsd.o \
    $(OBJDIR)/rt_lookflat1lincsf.o \
    $(OBJDIR)/rt_lookflat1linczd.o \
    $(OBJDIR)/rt_lookflat1linczf.o \
    $(OBJDIR)/rt_lookflat2bincsd.o \
    $(OBJDIR)/rt_lookflat2bincsf.o \
    $(OBJDIR)/rt_lookflat2binczd.o \
    $(OBJDIR)/rt_lookflat2binczf.o \
    $(OBJDIR)/rt_lookflat2evncsd.o \
    $(OBJDIR)/rt_lookflat2evncsf.o \
    $(OBJDIR)/rt_lookflat2evnczd.o \
    $(OBJDIR)/rt_lookflat2evnczf.o \
    $(OBJDIR)/rt_lookflat2lincsd.o \
    $(OBJDIR)/rt_lookflat2lincsf.o \
    $(OBJDIR)/rt_lookflat2linczd.o \
    $(OBJDIR)/rt_lookflat2linczf.o \
    $(OBJDIR)/rt_lookflatnbincsd.o \
    $(OBJDIR)/rt_lookflatnbincsf.o \
    $(OBJDIR)/rt_lookflatnbinczd.o \
    $(OBJDIR)/rt_lookflatnbinczf.o \
    $(OBJDIR)/rt_lookflatnevncsd.o \
    $(OBJDIR)/rt_lookflatnevncsf.o \
    $(OBJDIR)/rt_lookflatnevnczd.o \
    $(OBJDIR)/rt_lookflatnevnczf.o \
    $(OBJDIR)/rt_lookflatnlincsd.o \
    $(OBJDIR)/rt_lookflatnlincsf.o \
    $(OBJDIR)/rt_lookflatnlinczd.o \
    $(OBJDIR)/rt_lookflatnlinczf.o \
    $(OBJDIR)/rt_looklin1bincsd.o \
    $(OBJDIR)/rt_looklin1bincsf.o \
    $(OBJDIR)/rt_looklin1binczd.o \
    $(OBJDIR)/rt_looklin1binczf.o \
    $(OBJDIR)/rt_looklin1binxsd.o \
    $(OBJDIR)/rt_looklin1binxsf.o \
    $(OBJDIR)/rt_looklin1binxzd.o \
    $(OBJDIR)/rt_looklin1binxzf.o \
    $(OBJDIR)/rt_looklin1evncsd.o \
    $(OBJDIR)/rt_looklin1evncsf.o \
    $(OBJDIR)/rt_looklin1evnczd.o \
    $(OBJDIR)/rt_looklin1evnczf.o \
    $(OBJDIR)/rt_looklin1evnxsd.o \
    $(OBJDIR)/rt_looklin1evnxsf.o \
    $(OBJDIR)/rt_looklin1evnxzd.o \
    $(OBJDIR)/rt_looklin1evnxzf.o \
    $(OBJDIR)/rt_looklin1lincsd.o \
    $(OBJDIR)/rt_looklin1lincsf.o \
    $(OBJDIR)/rt_looklin1linczd.o \
    $(OBJDIR)/rt_looklin1linczf.o \
    $(OBJDIR)/rt_looklin1linxsd.o \
    $(OBJDIR)/rt_looklin1linxsf.o \
    $(OBJDIR)/rt_looklin1linxzd.o \
    $(OBJDIR)/rt_looklin1linxzf.o \
    $(OBJDIR)/rt_looklin2bincsd.o \
    $(OBJDIR)/rt_looklin2bincsf.o \
    $(OBJDIR)/rt_looklin2binczd.o \
    $(OBJDIR)/rt_looklin2binczf.o \
    $(OBJDIR)/rt_looklin2binxsd.o \
    $(OBJDIR)/rt_looklin2binxsf.o \
    $(OBJDIR)/rt_looklin2binxzd.o \
    $(OBJDIR)/rt_looklin2binxzf.o \
    $(OBJDIR)/rt_looklin2evncsd.o \
    $(OBJDIR)/rt_looklin2evncsf.o \
    $(OBJDIR)/rt_looklin2evnczd.o \
    $(OBJDIR)/rt_looklin2evnczf.o \
    $(OBJDIR)/rt_looklin2evnxsd.o \
    $(OBJDIR)/rt_looklin2evnxsf.o \
    $(OBJDIR)/rt_looklin2evnxzd.o \
    $(OBJDIR)/rt_looklin2evnxzf.o \
    $(OBJDIR)/rt_looklin2lincsd.o \
    $(OBJDIR)/rt_looklin2lincsf.o \
    $(OBJDIR)/rt_looklin2linczd.o \
    $(OBJDIR)/rt_looklin2linczf.o \
    $(OBJDIR)/rt_looklin2linxsd.o \
    $(OBJDIR)/rt_looklin2linxsf.o \
    $(OBJDIR)/rt_looklin2linxzd.o \
    $(OBJDIR)/rt_looklin2linxzf.o \
    $(OBJDIR)/rt_looklinnbincsd.o \
    $(OBJDIR)/rt_looklinnbincsf.o \
    $(OBJDIR)/rt_looklinnbinczd.o \
    $(OBJDIR)/rt_looklinnbinczf.o \
    $(OBJDIR)/rt_looklinnbinxsd.o \
    $(OBJDIR)/rt_looklinnbinxsf.o \
    $(OBJDIR)/rt_looklinnbinxzd.o \
    $(OBJDIR)/rt_looklinnbinxzf.o \
    $(OBJDIR)/rt_looklinnevncsd.o \
    $(OBJDIR)/rt_looklinnevncsf.o \
    $(OBJDIR)/rt_looklinnevnczd.o \
    $(OBJDIR)/rt_looklinnevnczf.o \
    $(OBJDIR)/rt_looklinnevnxsd.o \
    $(OBJDIR)/rt_looklinnevnxsf.o \
    $(OBJDIR)/rt_looklinnevnxzd.o \
    $(OBJDIR)/rt_looklinnevnxzf.o \
    $(OBJDIR)/rt_looklinnlincsd.o \
    $(OBJDIR)/rt_looklinnlincsf.o \
    $(OBJDIR)/rt_looklinnlinczd.o \
    $(OBJDIR)/rt_looklinnlinczf.o \
    $(OBJDIR)/rt_looklinnlinxsd.o \
    $(OBJDIR)/rt_looklinnlinxsf.o \
    $(OBJDIR)/rt_looklinnlinxzd.o \
    $(OBJDIR)/rt_looklinnlinxzf.o \
    $(OBJDIR)/rt_looksplnbincsd.o \
    $(OBJDIR)/rt_looksplnbincsf.o \
    $(OBJDIR)/rt_looksplnbinczd.o \
    $(OBJDIR)/rt_looksplnbinczf.o \
    $(OBJDIR)/rt_looksplnbinssd.o \
    $(OBJDIR)/rt_looksplnbinssf.o \
    $(OBJDIR)/rt_looksplnbinszd.o \
    $(OBJDIR)/rt_looksplnbinszf.o \
    $(OBJDIR)/rt_looksplnbinxsd.o \
    $(OBJDIR)/rt_looksplnbinxsf.o \
    $(OBJDIR)/rt_looksplnbinxzd.o \
    $(OBJDIR)/rt_looksplnbinxzf.o \
    $(OBJDIR)/rt_looksplnevncsd.o \
    $(OBJDIR)/rt_looksplnevncsf.o \
    $(OBJDIR)/rt_looksplnevnczd.o \
    $(OBJDIR)/rt_looksplnevnczf.o \
    $(OBJDIR)/rt_looksplnevnssd.o \
    $(OBJDIR)/rt_looksplnevnssf.o \
    $(OBJDIR)/rt_looksplnevnszd.o \
    $(OBJDIR)/rt_looksplnevnszf.o \
    $(OBJDIR)/rt_looksplnevnxsd.o \
    $(OBJDIR)/rt_looksplnevnxsf.o \
    $(OBJDIR)/rt_looksplnevnxzd.o \
    $(OBJDIR)/rt_looksplnevnxzf.o \
    $(OBJDIR)/rt_looksplnlincsd.o \
    $(OBJDIR)/rt_looksplnlincsf.o \
    $(OBJDIR)/rt_looksplnlinczd.o \
    $(OBJDIR)/rt_looksplnlinczf.o \
    $(OBJDIR)/rt_looksplnlinssd.o \
    $(OBJDIR)/rt_looksplnlinssf.o \
    $(OBJDIR)/rt_looksplnlinszd.o \
    $(OBJDIR)/rt_looksplnlinszf.o \
    $(OBJDIR)/rt_looksplnlinxsd.o \
    $(OBJDIR)/rt_looksplnlinxsf.o \
    $(OBJDIR)/rt_looksplnlinxzd.o \
    $(OBJDIR)/rt_looksplnlinxzf.o \
    $(OBJDIR)/rt_lu_cplx.o \
    $(OBJDIR)/rt_lu_cplx_sgl.o \
    $(OBJDIR)/rt_lu_real.o \
    $(OBJDIR)/rt_lu_real_sgl.o \
    $(OBJDIR)/rt_matdivcc_dbl.o \
    $(OBJDIR)/rt_matdivcc_sgl.o \
    $(OBJDIR)/rt_matdivcr_dbl.o \
    $(OBJDIR)/rt_matdivcr_sgl.o \
    $(OBJDIR)/rt_matdivrc_dbl.o \
    $(OBJDIR)/rt_matdivrc_sgl.o \
    $(OBJDIR)/rt_matdivrr_dbl.o \
    $(OBJDIR)/rt_matdivrr_sgl.o \
    $(OBJDIR)/rt_matmultandinccc_dbl.o \
    $(OBJDIR)/rt_matmultandinccc_sgl.o \
    $(OBJDIR)/rt_matmultandinccr_dbl.o \
    $(OBJDIR)/rt_matmultandinccr_sgl.o \
    $(OBJDIR)/rt_matmultandincrc_dbl.o \
    $(OBJDIR)/rt_matmultandincrc_sgl.o \
    $(OBJDIR)/rt_matmultandincrr_dbl.o \
    $(OBJDIR)/rt_matmultandincrr_sgl.o \
    $(OBJDIR)/rt_matmultcc_dbl.o \
    $(OBJDIR)/rt_matmultcc_sgl.o \
    $(OBJDIR)/rt_matmultcr_dbl.o \
    $(OBJDIR)/rt_matmultcr_sgl.o \
    $(OBJDIR)/rt_matmultrc_dbl.o \
    $(OBJDIR)/rt_matmultrc_sgl.o \
    $(OBJDIR)/rt_matmultrr_dbl.o \
    $(OBJDIR)/rt_matmultrr_sgl.o \
    $(OBJDIR)/rt_matrx.o \
    $(OBJDIR)/rt_nrand.o \
    $(OBJDIR)/rt_plookbincd.o \
    $(OBJDIR)/rt_plookbincf.o \
    $(OBJDIR)/rt_plookbinkcd.o \
    $(OBJDIR)/rt_plookbinkcf.o \
    $(OBJDIR)/rt_plookbinxd.o \
    $(OBJDIR)/rt_plookbinxf.o \
    $(OBJDIR)/rt_plookevncd.o \
    $(OBJDIR)/rt_plookevncf.o \
    $(OBJDIR)/rt_plookevnkcd.o \
    $(OBJDIR)/rt_plookevnkcf.o \
    $(OBJDIR)/rt_plookevnxd.o \
    $(OBJDIR)/rt_plookevnxf.o \
    $(OBJDIR)/rt_plooklincd.o \
    $(OBJDIR)/rt_plooklincf.o \
    $(OBJDIR)/rt_plooklinkcd.o \
    $(OBJDIR)/rt_plooklinkcf.o \
    $(OBJDIR)/rt_plooklinxd.o \
    $(OBJDIR)/rt_plooklinxf.o \
    $(OBJDIR)/rt_printf.o \
    $(OBJDIR)/rt_sat_div_int16.o \
    $(OBJDIR)/rt_sat_div_int32.o \
    $(OBJDIR)/rt_sat_div_int8.o \
    $(OBJDIR)/rt_sat_div_uint16.o \
    $(OBJDIR)/rt_sat_div_uint32.o \
    $(OBJDIR)/rt_sat_div_uint8.o \
    $(OBJDIR)/rt_sat_prod_int16.o \
    $(OBJDIR)/rt_sat_prod_int32.o \
    $(OBJDIR)/rt_sat_prod_int8.o \
    $(OBJDIR)/rt_sat_prod_uint16.o \
    $(OBJDIR)/rt_sat_prod_uint32.o \
    $(OBJDIR)/rt_sat_prod_uint8.o \
    $(OBJDIR)/rt_tdelay.o \
    $(OBJDIR)/rt_urand.o \
    $(OBJDIR)/rt_zcfcn.o \


$(MODULES_rtwlib) : $(MAKEFILE) rtw_proj.tmw

rtwlib.a : setup $(filter-out $(OBJDIR)/rt_logging.o, $(MODULES_rtwlib) )
	@echo "### Creating $@ "
	$(LIBCMD) $@  $(filter-out $(OBJDIR)/rt_logging.o, $(MODULES_rtwlib) )
	@echo "### Created $@"



#----------------------------- Dependencies ------------------------------------

$(OBJECT_TARGETS) $(LINKER_COMMAND_FILE) : $(MAKEFILE) rtw_proj.tmw

#--------- Miscellaneous rules to purge, clean and lint (sol2 only) ------------

purge : clean
	@echo "### Deleting the generated source code for $(MODEL)"
	@$(RM) -f $(MODEL).c $(MODEL).h $(MODEL)_types.h $(MODEL)_data.c \
		$(MODEL)_private.h $(MODEL).rtw $(MODULES) rtw_proj.tmw $(MAKEFILE)

clean :
	@echo "### Deleting the $(PRODUCT)"
	@$(RM) $(PRODUCT)



