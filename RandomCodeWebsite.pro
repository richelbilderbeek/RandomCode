include(../RibiLibraries/WebApplication.pri)
include(../RibiLibraries/BoostAll.pri)
include(../RibiLibraries/Wt.pri)
include(../RibiLibraries/GeneralConsole.pri)
include(../RibiLibraries/GeneralWeb.pri)

#Specific, console
include(../RibiClasses/CppRandomCode/CppRandomCode.pri)

#Specific, website
include(RandomCodeWebsite.pri)

SOURCES += wtmain.cpp
