CONNECTALDIR?=/mnt/efs/fs1/connectal
S2H_INTERFACES = TopRequest:ProcTop.topRequest
H2S_INTERFACES = ProcTop:TopIndication

BSVFILES= \
    Axi4New.bsv\
    DdrAws.bsv\
	ProcTop.bsv

CPPFILES= testProc.cpp elf2hex/ElfLoader.cpp


PIN_TYPE = Axi4
PIN_TYPE_INCLUDE = Axi4New
AUTOTOP = --interface pins:ProcTop.ddr3

CONNECTALFLAGS += -D AWSF1_DDR_A

include $(CONNECTALDIR)/Makefile.connectal
