#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=cof
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=${DISTDIR}/EM_System.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=${DISTDIR}/EM_System.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=Drivers/p18f4620_tim.c Drivers/p18f4620_interrupt.c Drivers/p18f4620_gpio.c Drivers/p18f4620_lcd.c Drivers/p18f4620_uart.c Drivers/p18f4620_adc.c Drivers/p18f4620_pwm.c Software/timer_software.c Software/menu.c Software/sensor.c main.c Software/uart.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/Drivers/p18f4620_tim.o ${OBJECTDIR}/Drivers/p18f4620_interrupt.o ${OBJECTDIR}/Drivers/p18f4620_gpio.o ${OBJECTDIR}/Drivers/p18f4620_lcd.o ${OBJECTDIR}/Drivers/p18f4620_uart.o ${OBJECTDIR}/Drivers/p18f4620_adc.o ${OBJECTDIR}/Drivers/p18f4620_pwm.o ${OBJECTDIR}/Software/timer_software.o ${OBJECTDIR}/Software/menu.o ${OBJECTDIR}/Software/sensor.o ${OBJECTDIR}/main.o ${OBJECTDIR}/Software/uart.o
POSSIBLE_DEPFILES=${OBJECTDIR}/Drivers/p18f4620_tim.o.d ${OBJECTDIR}/Drivers/p18f4620_interrupt.o.d ${OBJECTDIR}/Drivers/p18f4620_gpio.o.d ${OBJECTDIR}/Drivers/p18f4620_lcd.o.d ${OBJECTDIR}/Drivers/p18f4620_uart.o.d ${OBJECTDIR}/Drivers/p18f4620_adc.o.d ${OBJECTDIR}/Drivers/p18f4620_pwm.o.d ${OBJECTDIR}/Software/timer_software.o.d ${OBJECTDIR}/Software/menu.o.d ${OBJECTDIR}/Software/sensor.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/Software/uart.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/Drivers/p18f4620_tim.o ${OBJECTDIR}/Drivers/p18f4620_interrupt.o ${OBJECTDIR}/Drivers/p18f4620_gpio.o ${OBJECTDIR}/Drivers/p18f4620_lcd.o ${OBJECTDIR}/Drivers/p18f4620_uart.o ${OBJECTDIR}/Drivers/p18f4620_adc.o ${OBJECTDIR}/Drivers/p18f4620_pwm.o ${OBJECTDIR}/Software/timer_software.o ${OBJECTDIR}/Software/menu.o ${OBJECTDIR}/Software/sensor.o ${OBJECTDIR}/main.o ${OBJECTDIR}/Software/uart.o

# Source Files
SOURCEFILES=Drivers/p18f4620_tim.c Drivers/p18f4620_interrupt.c Drivers/p18f4620_gpio.c Drivers/p18f4620_lcd.c Drivers/p18f4620_uart.c Drivers/p18f4620_adc.c Drivers/p18f4620_pwm.c Software/timer_software.c Software/menu.c Software/sensor.c main.c Software/uart.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/EM_System.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4620
MP_PROCESSOR_OPTION_LD=18f4620
MP_LINKER_DEBUG_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/Drivers/p18f4620_tim.o: Drivers/p18f4620_tim.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Drivers" 
	@${RM} ${OBJECTDIR}/Drivers/p18f4620_tim.o.d 
	@${RM} ${OBJECTDIR}/Drivers/p18f4620_tim.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -I"Drivers" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Drivers/p18f4620_tim.o   Drivers/p18f4620_tim.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Drivers/p18f4620_tim.o 
	@${FIXDEPS} "${OBJECTDIR}/Drivers/p18f4620_tim.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/Drivers/p18f4620_interrupt.o: Drivers/p18f4620_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Drivers" 
	@${RM} ${OBJECTDIR}/Drivers/p18f4620_interrupt.o.d 
	@${RM} ${OBJECTDIR}/Drivers/p18f4620_interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -I"Drivers" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Drivers/p18f4620_interrupt.o   Drivers/p18f4620_interrupt.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Drivers/p18f4620_interrupt.o 
	@${FIXDEPS} "${OBJECTDIR}/Drivers/p18f4620_interrupt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/Drivers/p18f4620_gpio.o: Drivers/p18f4620_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Drivers" 
	@${RM} ${OBJECTDIR}/Drivers/p18f4620_gpio.o.d 
	@${RM} ${OBJECTDIR}/Drivers/p18f4620_gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -I"Drivers" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Drivers/p18f4620_gpio.o   Drivers/p18f4620_gpio.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Drivers/p18f4620_gpio.o 
	@${FIXDEPS} "${OBJECTDIR}/Drivers/p18f4620_gpio.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/Drivers/p18f4620_lcd.o: Drivers/p18f4620_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Drivers" 
	@${RM} ${OBJECTDIR}/Drivers/p18f4620_lcd.o.d 
	@${RM} ${OBJECTDIR}/Drivers/p18f4620_lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -I"Drivers" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Drivers/p18f4620_lcd.o   Drivers/p18f4620_lcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Drivers/p18f4620_lcd.o 
	@${FIXDEPS} "${OBJECTDIR}/Drivers/p18f4620_lcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/Drivers/p18f4620_uart.o: Drivers/p18f4620_uart.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Drivers" 
	@${RM} ${OBJECTDIR}/Drivers/p18f4620_uart.o.d 
	@${RM} ${OBJECTDIR}/Drivers/p18f4620_uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -I"Drivers" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Drivers/p18f4620_uart.o   Drivers/p18f4620_uart.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Drivers/p18f4620_uart.o 
	@${FIXDEPS} "${OBJECTDIR}/Drivers/p18f4620_uart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/Drivers/p18f4620_adc.o: Drivers/p18f4620_adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Drivers" 
	@${RM} ${OBJECTDIR}/Drivers/p18f4620_adc.o.d 
	@${RM} ${OBJECTDIR}/Drivers/p18f4620_adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -I"Drivers" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Drivers/p18f4620_adc.o   Drivers/p18f4620_adc.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Drivers/p18f4620_adc.o 
	@${FIXDEPS} "${OBJECTDIR}/Drivers/p18f4620_adc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/Drivers/p18f4620_pwm.o: Drivers/p18f4620_pwm.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Drivers" 
	@${RM} ${OBJECTDIR}/Drivers/p18f4620_pwm.o.d 
	@${RM} ${OBJECTDIR}/Drivers/p18f4620_pwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -I"Drivers" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Drivers/p18f4620_pwm.o   Drivers/p18f4620_pwm.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Drivers/p18f4620_pwm.o 
	@${FIXDEPS} "${OBJECTDIR}/Drivers/p18f4620_pwm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/Software/timer_software.o: Software/timer_software.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Software" 
	@${RM} ${OBJECTDIR}/Software/timer_software.o.d 
	@${RM} ${OBJECTDIR}/Software/timer_software.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -I"Drivers" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Software/timer_software.o   Software/timer_software.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Software/timer_software.o 
	@${FIXDEPS} "${OBJECTDIR}/Software/timer_software.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/Software/menu.o: Software/menu.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Software" 
	@${RM} ${OBJECTDIR}/Software/menu.o.d 
	@${RM} ${OBJECTDIR}/Software/menu.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -I"Drivers" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Software/menu.o   Software/menu.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Software/menu.o 
	@${FIXDEPS} "${OBJECTDIR}/Software/menu.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/Software/sensor.o: Software/sensor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Software" 
	@${RM} ${OBJECTDIR}/Software/sensor.o.d 
	@${RM} ${OBJECTDIR}/Software/sensor.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -I"Drivers" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Software/sensor.o   Software/sensor.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Software/sensor.o 
	@${FIXDEPS} "${OBJECTDIR}/Software/sensor.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -I"Drivers" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/main.o   main.c 
	@${DEP_GEN} -d ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/Software/uart.o: Software/uart.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Software" 
	@${RM} ${OBJECTDIR}/Software/uart.o.d 
	@${RM} ${OBJECTDIR}/Software/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -I"Drivers" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Software/uart.o   Software/uart.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Software/uart.o 
	@${FIXDEPS} "${OBJECTDIR}/Software/uart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
else
${OBJECTDIR}/Drivers/p18f4620_tim.o: Drivers/p18f4620_tim.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Drivers" 
	@${RM} ${OBJECTDIR}/Drivers/p18f4620_tim.o.d 
	@${RM} ${OBJECTDIR}/Drivers/p18f4620_tim.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"Drivers" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Drivers/p18f4620_tim.o   Drivers/p18f4620_tim.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Drivers/p18f4620_tim.o 
	@${FIXDEPS} "${OBJECTDIR}/Drivers/p18f4620_tim.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/Drivers/p18f4620_interrupt.o: Drivers/p18f4620_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Drivers" 
	@${RM} ${OBJECTDIR}/Drivers/p18f4620_interrupt.o.d 
	@${RM} ${OBJECTDIR}/Drivers/p18f4620_interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"Drivers" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Drivers/p18f4620_interrupt.o   Drivers/p18f4620_interrupt.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Drivers/p18f4620_interrupt.o 
	@${FIXDEPS} "${OBJECTDIR}/Drivers/p18f4620_interrupt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/Drivers/p18f4620_gpio.o: Drivers/p18f4620_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Drivers" 
	@${RM} ${OBJECTDIR}/Drivers/p18f4620_gpio.o.d 
	@${RM} ${OBJECTDIR}/Drivers/p18f4620_gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"Drivers" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Drivers/p18f4620_gpio.o   Drivers/p18f4620_gpio.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Drivers/p18f4620_gpio.o 
	@${FIXDEPS} "${OBJECTDIR}/Drivers/p18f4620_gpio.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/Drivers/p18f4620_lcd.o: Drivers/p18f4620_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Drivers" 
	@${RM} ${OBJECTDIR}/Drivers/p18f4620_lcd.o.d 
	@${RM} ${OBJECTDIR}/Drivers/p18f4620_lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"Drivers" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Drivers/p18f4620_lcd.o   Drivers/p18f4620_lcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Drivers/p18f4620_lcd.o 
	@${FIXDEPS} "${OBJECTDIR}/Drivers/p18f4620_lcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/Drivers/p18f4620_uart.o: Drivers/p18f4620_uart.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Drivers" 
	@${RM} ${OBJECTDIR}/Drivers/p18f4620_uart.o.d 
	@${RM} ${OBJECTDIR}/Drivers/p18f4620_uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"Drivers" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Drivers/p18f4620_uart.o   Drivers/p18f4620_uart.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Drivers/p18f4620_uart.o 
	@${FIXDEPS} "${OBJECTDIR}/Drivers/p18f4620_uart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/Drivers/p18f4620_adc.o: Drivers/p18f4620_adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Drivers" 
	@${RM} ${OBJECTDIR}/Drivers/p18f4620_adc.o.d 
	@${RM} ${OBJECTDIR}/Drivers/p18f4620_adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"Drivers" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Drivers/p18f4620_adc.o   Drivers/p18f4620_adc.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Drivers/p18f4620_adc.o 
	@${FIXDEPS} "${OBJECTDIR}/Drivers/p18f4620_adc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/Drivers/p18f4620_pwm.o: Drivers/p18f4620_pwm.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Drivers" 
	@${RM} ${OBJECTDIR}/Drivers/p18f4620_pwm.o.d 
	@${RM} ${OBJECTDIR}/Drivers/p18f4620_pwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"Drivers" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Drivers/p18f4620_pwm.o   Drivers/p18f4620_pwm.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Drivers/p18f4620_pwm.o 
	@${FIXDEPS} "${OBJECTDIR}/Drivers/p18f4620_pwm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/Software/timer_software.o: Software/timer_software.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Software" 
	@${RM} ${OBJECTDIR}/Software/timer_software.o.d 
	@${RM} ${OBJECTDIR}/Software/timer_software.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"Drivers" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Software/timer_software.o   Software/timer_software.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Software/timer_software.o 
	@${FIXDEPS} "${OBJECTDIR}/Software/timer_software.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/Software/menu.o: Software/menu.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Software" 
	@${RM} ${OBJECTDIR}/Software/menu.o.d 
	@${RM} ${OBJECTDIR}/Software/menu.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"Drivers" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Software/menu.o   Software/menu.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Software/menu.o 
	@${FIXDEPS} "${OBJECTDIR}/Software/menu.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/Software/sensor.o: Software/sensor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Software" 
	@${RM} ${OBJECTDIR}/Software/sensor.o.d 
	@${RM} ${OBJECTDIR}/Software/sensor.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"Drivers" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Software/sensor.o   Software/sensor.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Software/sensor.o 
	@${FIXDEPS} "${OBJECTDIR}/Software/sensor.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"Drivers" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/main.o   main.c 
	@${DEP_GEN} -d ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/Software/uart.o: Software/uart.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Software" 
	@${RM} ${OBJECTDIR}/Software/uart.o.d 
	@${RM} ${OBJECTDIR}/Software/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"Drivers" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Software/uart.o   Software/uart.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Software/uart.o 
	@${FIXDEPS} "${OBJECTDIR}/Software/uart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/EM_System.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_LD} $(MP_EXTRA_LD_PRE)   -p$(MP_PROCESSOR_OPTION_LD)  -w -x -u_DEBUG -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -z__MPLAB_DEBUG=1 $(MP_LINKER_DEBUG_OPTION) -l ${MP_CC_DIR}\\..\\lib  -o ${DISTDIR}/EM_System.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
else
${DISTDIR}/EM_System.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_LD} $(MP_EXTRA_LD_PRE)   -p$(MP_PROCESSOR_OPTION_LD)  -w  -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -l ${MP_CC_DIR}\\..\\lib  -o ${DISTDIR}/EM_System.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
