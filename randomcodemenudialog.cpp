#include "randomcode.h"

#include <cassert>
#include <ctime>
#include <iostream>
#include <iterator>

#include "randomcodemenudialog.h"

int ribi::RandomCodeMenuDialog::ExecuteSpecific(const std::vector<std::string>& /*argv*/) noexcept
{
  #ifndef NDEBUG
  Test();
  #endif
  //From http://www.richelbilderbeek.nl/CppRandomizeTimer.htm
  std::srand(std::time(0));

  //Create the random code
  const std::vector<std::string> v
    = RandomCode::CreateRandomCode();

  //Display the random code
  std::copy(
    v.begin(),
    v.end(),
    std::ostream_iterator<std::string>(std::cout,"\n")
  );

  return 0;
}

ribi::About ribi::RandomCodeMenuDialog::GetAbout() const noexcept
{
  About a(
    "Richel Bilderbeek",
    "RandomCode",
    "tool to generate random C++ code",
    "the 24th of February 2014",
    "2007-2015",
    "http://www.richelbilderbeek.nl/ToolRandomCode.htm",
    GetVersion(),
    GetVersionHistory());
  a.AddLibrary("RandomCode version: " + RandomCode::GetVersion());
  return a;
}

ribi::Help ribi::RandomCodeMenuDialog::GetHelp() const noexcept
{
  return Help(
    this->GetAbout().GetFileTitle(),
    this->GetAbout().GetFileDescription(),
    {

    },
    {

    }
  );
}


std::string ribi::RandomCodeMenuDialog::GetVersion() const noexcept
{
  return "5.0";
}

std::vector<std::string> ribi::RandomCodeMenuDialog::GetVersionHistory() const noexcept
{
  return {
    "2007-xx-xx: version 1.0: initial version in C++ Builder",
    "2010-12-03: version 2.0: port to Qt Creator",
    "2011-01-07: version 3.0: added menu, reworked file architecture",
    "2011-04-24: version 4.0: major architectural change, created web version",
    "2011-08-31: version 4.1: added Welcome picture for web version",
    "2012-12-25: version 4.2: added menu for desktop version",
    "2014-02-24: version 4.3: added command-line version",
    "2015-11-21: version 5.0: moved to own GitHub",
  };
}

#ifndef NDEBUG
void ribi::RandomCodeMenuDialog::Test() noexcept
{
  {
    static bool is_tested{false};
    if (is_tested) return;
    is_tested = true;
  }
  RandomCodeMenuDialog d;
  d.Execute( { "RandomCode" } );
}
#endif
