#include "randomcodemenudialog.h"

int main(int argc, char *argv[])
{
  const std::vector<std::string> args {
    ribi::RandomCodeMenuDialog::ConvertArguments(argc,argv)
  };
  ribi::RandomCodeMenuDialog d;
  return d.Execute(args);
}
