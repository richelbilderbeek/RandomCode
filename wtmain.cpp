#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-but-set-parameter"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#include <Wt/WApplication>
#include <Wt/WContainerWidget>

#include "wtautoconfig.h"
#include "wtrandomcodemenudialog.h"
#pragma GCC diagnostic pop

struct WtRandomCodeApplication : public Wt::WApplication
{
  WtRandomCodeApplication(const Wt::WEnvironment& env)
  : Wt::WApplication(env)
  {
    this->setTitle("RandomCode");
    this->useStyleSheet("wt.css");
    root()->addWidget(new ribi::WtRandomCodeMenuDialog);
  }
};

Wt::WApplication * createApplication(const Wt::WEnvironment& env)
{
  return new WtRandomCodeApplication(env);
}

int main(int argc, char **argv)
{
  ribi::WtAutoConfig a(argc,argv,createApplication);
  ribi::WtAutoConfig::SaveDefaultStylesheet();
  return a.Run();
}


