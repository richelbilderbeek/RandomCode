#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#include "qtrandomcodemaindialog.h"

#include <string>
#include <vector>

#include <QDesktopWidget>
#include <QKeyEvent>

#include "about.h"
#include "qtaboutdialog.h"
#include "ui_qtrandomcodemaindialog.h"
#include "randomcode.h"
#include "randomcodemenudialog.h"
#pragma GCC diagnostic pop

ribi::QtRandomCodeMainDialog::QtRandomCodeMainDialog(QWidget *parent) :
    QtHideAndShowDialog(parent),
    ui(new Ui::QtRandomCodeMainDialog)
{
  ui->setupUi(this);

  //Put the dialog in the screen center
  const QRect screen = QApplication::desktop()->screenGeometry();
  this->setGeometry( screen.adjusted(64,64,-64,-64));
  this->move( screen.center() - this->rect().center() );

  ui->button_generate->click();
}

ribi::QtRandomCodeMainDialog::~QtRandomCodeMainDialog() noexcept
{
  delete ui;
}

void ribi::QtRandomCodeMainDialog::keyPressEvent(QKeyEvent * event)
{
  if (event->key() == Qt::Key_Escape) { close(); return; }
}

void ribi::QtRandomCodeMainDialog::on_button_generate_clicked()
{
  const std::vector<std::string> v = RandomCode::CreateRandomCode();
  ui->textEdit->clear();
  for(const std::string& s: v)
  {
    ui->textEdit->append(s.c_str());
  }
}

void ribi::QtRandomCodeMainDialog::on_button_about_clicked()
{
  About about = RandomCodeMenuDialog().GetAbout();
  //about.AddLibrary("QtConnectThreeWidget version: " + QtConnectThreeWidget::GetVersion());
  QtAboutDialog d(about);
  this->ShowChild(&d);
}
