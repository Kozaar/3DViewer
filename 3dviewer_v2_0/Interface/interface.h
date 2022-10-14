#ifndef SRC_3DVIEWER_V2_0_INTERFACE_INTERFACE_H_
#define SRC_3DVIEWER_V2_0_INTERFACE_INTERFACE_H_

#include <QMainWindow>
#include <QFileDialog>
#include <QColorDialog>
#include <QSurfaceFormat>
#include <QString>
#include <QImage>
#include <QMessageBox>
#include <map>

#include "../Settings/settings.h"
#include "modelrender.h"
#include "clicks.h"
#include "../Controller/controller.h"
#include "gifCreate.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Interface; }
QT_END_NAMESPACE
namespace s21 {
class Interface : public QMainWindow {
    Q_OBJECT

 public:
    explicit Interface(QWidget *parent = nullptr);
    ~Interface();
    std::map<QString, s21::Clicks_plus_or_minus*> clicks;

 private slots:
    void on_pushButtonOpenFile_clicked();
    void on_pushButton_color_dots_clicked();
    void on_pushButton_back_color_clicked();
    void on_pushButton_move_clicked();
    void on_pushButton_turn_clicked();
    void plus_minus_slot();
    void on_pushButton_color_edge_clicked();
    void on_radioButton_central_clicked();
    void on_radioButton_parall_clicked();
    void on_comboBox_typ_dots_currentIndexChanged(int index);
    void on_comboBox_typ_edge_currentIndexChanged(int index);
    void on_pushButtonMakeScreenshot_clicked();
    void draw();
    void on_pushButtonMakeGif_clicked();

    void on_pushButtonStopMakeGif_clicked();

 private:
    Ui::Interface *ui;
    ModelRender *modelRender;
    Controller *controller_;
    gifCreate *gifCreate_;
};
}  // namespace s21
#endif  // SRC_3DVIEWER_V2_0_INTERFACE_INTERFACE_H_
