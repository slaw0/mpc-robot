			# Automatically Generated File
			# Do not edit

			# Compiler Location
CWROOT= $(subst \,/,C:\CodeWarrior)
MPC555_TOOL_CHAIN=CODE_WARRIOR

ifeq ($(MODELREF_TARGET_TYPE), NONE)
   # Top-level model for RTW is assumed to include a resource configuration 
   # block that generates this file containing information about the selected 
   # processor type
   include mpc5xxvariant.mk
else
   MPC5XX_VARIANT = 5XX
endif


OVERRIDE_DEFAULT_OPT_OPTS = 1
OVERRIDE_DEFAULT_DEBUG_OPTS = 1
OPT_OPTS:= -opt speed 
DEBUG_OPTS:=
