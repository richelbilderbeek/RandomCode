#ifndef QTRANDOMCODEMAINDIALOG_H
#define QTRANDOMCODEMAINDIALOG_H

#include "qthideandshowdialog.h"

namespace Ui {
  class QtRandomCodeMainDialog;
}

namespace ribi {

class QtRandomCodeMainDialog : public QtHideAndShowDialog
{
  Q_OBJECT

public:
  explicit QtRandomCodeMainDialog(QWidget *parent = 0);
  QtRandomCodeMainDialog(const QtRandomCodeMainDialog&) = delete;
  QtRandomCodeMainDialog& operator=(const QtRandomCodeMainDialog&) = delete;
  ~QtRandomCodeMainDialog() noexcept;

protected:
  
  void keyPressEvent(QKeyEvent *);

private:
  Ui::QtRandomCodeMainDialog *ui;

private slots:
  void on_button_about_clicked();
  void on_button_generate_clicked();
};

} //~namespace ribi

#endif // QTRANDOMCODEMAINDIALOG_H
