##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=OU5_table
ConfigurationName      :=Debug
WorkspacePath          := "C:\Users\Ny Dator\Documents\codelitews"
ProjectPath            := "C:\Users\Ny Dator\Documents\codelitews\OU5_table"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Ny Dator
Date                   :=13/03/2016
CodeLitePath           :="C:\Program Files\CodeLite"
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="OU5_table.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/dlist.c$(ObjectSuffix) $(IntermediateDirectory)/PDA.c$(ObjectSuffix) $(IntermediateDirectory)/stack_1cell.c$(ObjectSuffix) $(IntermediateDirectory)/table.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c $(IntermediateDirectory)/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Ny Dator/Documents/codelitews/OU5_table/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM "main.c"

$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) "main.c"

$(IntermediateDirectory)/dlist.c$(ObjectSuffix): dlist.c $(IntermediateDirectory)/dlist.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Ny Dator/Documents/codelitews/OU5_table/dlist.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/dlist.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/dlist.c$(DependSuffix): dlist.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/dlist.c$(ObjectSuffix) -MF$(IntermediateDirectory)/dlist.c$(DependSuffix) -MM "dlist.c"

$(IntermediateDirectory)/dlist.c$(PreprocessSuffix): dlist.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/dlist.c$(PreprocessSuffix) "dlist.c"

$(IntermediateDirectory)/PDA.c$(ObjectSuffix): PDA.c $(IntermediateDirectory)/PDA.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Ny Dator/Documents/codelitews/OU5_table/PDA.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PDA.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PDA.c$(DependSuffix): PDA.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/PDA.c$(ObjectSuffix) -MF$(IntermediateDirectory)/PDA.c$(DependSuffix) -MM "PDA.c"

$(IntermediateDirectory)/PDA.c$(PreprocessSuffix): PDA.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PDA.c$(PreprocessSuffix) "PDA.c"

$(IntermediateDirectory)/stack_1cell.c$(ObjectSuffix): stack_1cell.c $(IntermediateDirectory)/stack_1cell.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Ny Dator/Documents/codelitews/OU5_table/stack_1cell.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/stack_1cell.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/stack_1cell.c$(DependSuffix): stack_1cell.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/stack_1cell.c$(ObjectSuffix) -MF$(IntermediateDirectory)/stack_1cell.c$(DependSuffix) -MM "stack_1cell.c"

$(IntermediateDirectory)/stack_1cell.c$(PreprocessSuffix): stack_1cell.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/stack_1cell.c$(PreprocessSuffix) "stack_1cell.c"

$(IntermediateDirectory)/table.c$(ObjectSuffix): table.c $(IntermediateDirectory)/table.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Ny Dator/Documents/codelitews/OU5_table/table.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/table.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/table.c$(DependSuffix): table.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/table.c$(ObjectSuffix) -MF$(IntermediateDirectory)/table.c$(DependSuffix) -MM "table.c"

$(IntermediateDirectory)/table.c$(PreprocessSuffix): table.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/table.c$(PreprocessSuffix) "table.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


