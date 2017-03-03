#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#include "qtrandomcodemenudialog.h"

#include <QDesktopWidget>
#include <QKeyEvent>

#include "randomcodemenudialog.h"
#include "qtaboutdialog.h"
#include "qtrandomcodemaindialog.h"
#include "qthideandshowdialog.h"
#include "ui_qtrandomcodemenudialog.h"
#pragma GCC diagnostic pop

ribi::QtRandomCodeMenuDialog::QtRandomCodeMenuDialog(QWidget *parent) :
    QtHideAndShowDialog(parent),
    ui(new Ui::QtRandomCodeMenuDialog)
{
  ui->setupUi(this);
}

ribi::QtRandomCodeMenuDialog::~QtRandomCodeMenuDialog() noexcept
{
  delete ui;
}

void ribi::QtRandomCodeMenuDialog::keyPressEvent(QKeyEvent * event)
{
  if (event->key() == Qt::Key_Escape) { close(); return; }
}

void ribi::QtRandomCodeMenuDialog::on_button_about_clicked()
{
  About a = RandomCodeMenuDialog().GetAbout();
  a.AddLibrary("QtHideAndShowDialog version: " + QtHideAndShowDialog::GetVersion());
  QtAboutDialog d(a);
  d.setWindowIcon(this->windowIcon());
  d.setStyleSheet(this->styleSheet());
  this->ShowChild(&d);
}

void ribi::QtRandomCodeMenuDialog::on_button_quit_clicked()
{
  close();
}

void ribi::QtRandomCodeMenuDialog::on_button_start_clicked()
{
  QtRandomCodeMainDialog d;
  ShowChild(&d);
}


