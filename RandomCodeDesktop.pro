include(../RibiLibraries/DesktopApplicationNoWeffcpp.pri)
include(../RibiLibraries/BoostAll.pri)
include(../RibiLibraries/GeneralConsole.pri)
include(../RibiLibraries/GeneralDesktop.pri)


#Specific, console
include(../RibiClasses/CppRandomCode/CppRandomCode.pri)

#Specific
include(RandomCodeDesktop.pri)
SOURCES += qtmain.cpp
