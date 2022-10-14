#include "interface.h"
#include "gif/gifimage/qgifimage.h"
#include "ui_interface.h"
#include <unistd.h>

s21::Interface::Interface(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Interface)
    , controller_(new s21::Controller) {
    clicks["pushButton_plus_move_x"] = new Move_x_plus(controller_);
    clicks["pushButton_plus_move_y"] = new Move_y_plus(controller_);
    clicks["pushButton_plus_move_z"] = new Move_z_plus(controller_);
    clicks["pushButton_minus_move_x"] = new Move_x_minus(controller_);
    clicks["pushButton_minus_move_y"] = new Move_y_minus(controller_);
    clicks["pushButton_minus_move_z"] = new Move_z_minus(controller_);
    clicks["pushButton_plus_turn_x"] = new Turn_x_plus(controller_);
    clicks["pushButton_plus_turn_y"] = new Turn_y_plus(controller_);
    clicks["pushButton_plus_turn_z"] = new Turn_z_plus(controller_);
    clicks["pushButton_minus_turn_x"] = new Turn_x_minus(controller_);
    clicks["pushButton_minus_turn_y"] = new Turn_y_minus(controller_);
    clicks["pushButton_minus_turn_z"] = new Turn_z_minus(controller_);
    clicks["pushButton_minus_scale"] = new Scale_minus(controller_);
    clicks["pushButton_plus_scale"] = new Scale_plus(controller_);
    clicks["pushButton_plus_size_dots"] = new Size_dots_plus(controller_);
    clicks["pushButton_minus_size_dots"] = new Size_dots_minus(controller_);
    clicks["pushButton_plus_size_edge"] = new Size_edges_plus(controller_);
    clicks["pushButton_minus_size_edge"] = new Size_edges_minus(controller_);
    clicks["pushButton_centering"] = new CenteringPicture(controller_);
    ui->setupUi(this);
    gifCreate_ = new gifCreate;
    ui->pushButtonStopMakeGif->setHidden(true);
    for (QPushButton*button : findChildren<QPushButton*>()) {
        if (button->objectName().contains("plus_") || button->objectName().contains("minus")) {
            connect(button, SIGNAL(clicked()), this, SLOT(plus_minus_slot()));
        }
    }
    connect(ui->pushButton_centering, SIGNAL(clicked()), this, SLOT(plus_minus_slot()));
    if (s21::Settings::Instance().ProectionType()) {
         ui->radioButton_central->setChecked(true);
    } else {
         ui->radioButton_parall->setChecked(true);
    }
    modelRender = new ModelRender(this, controller_);
    modelRender->setGeometry(ui->frameForRender->pos().x(), ui->frameForRender->pos().y(),
                 ui->frameForRender->width(), ui->frameForRender->height());
}

s21::Interface::~Interface() {
    delete modelRender;
    for (auto it = clicks.begin(); it != clicks.end(); it++) {
        delete it->second;
    }
    delete gifCreate_;
    delete controller_;
    delete ui;
}

void s21::Interface::on_pushButtonOpenFile_clicked() {
    QString file_name;
    file_name = QFileDialog::getOpenFileName(this, "Open File", "examples", "OBJECT (*.obj)");
    if (file_name != nullptr) {
        ui->label_info->setText(QString::fromStdString(controller_->viewNewPicture(file_name.toStdString())));
        draw();
    }
    ui->comboBox_typ_dots->setCurrentIndex(s21::Settings::Instance().DotType());
    ui->comboBox_typ_edge->setCurrentIndex(s21::Settings::Instance().FacetType());
}

void s21::Interface::on_pushButton_color_dots_clicked() {
    QColor color = QColorDialog::getColor();
    s21::Settings::Instance().DotColor()[0] = color.redF();
    s21::Settings::Instance().DotColor()[1] = color.greenF();
    s21::Settings::Instance().DotColor()[2] = color.blueF();
    draw();
}

void s21::Interface::on_pushButton_back_color_clicked() {
    QColor color = QColorDialog::getColor();
    s21::Settings::Instance().BackgroundColor()[0] = color.redF();
    s21::Settings::Instance().BackgroundColor()[1] = color.greenF();
    s21::Settings::Instance().BackgroundColor()[2] = color.blueF();
    draw();
}

void s21::Interface::on_pushButton_color_edge_clicked() {
    QColor color = QColorDialog::getColor();
    s21::Settings::Instance().FacetColor()[0] = color.redF();
    s21::Settings::Instance().FacetColor()[1] = color.greenF();
    s21::Settings::Instance().FacetColor()[2] = color.blueF();
    draw();
}

void s21::Interface::on_pushButton_move_clicked() {
    controller_->move(ui->doubleSpinBox_move_x->value(),
                      ui->doubleSpinBox_move_y->value(),
                      ui->doubleSpinBox_move_z->value());
    draw();
}

void s21::Interface::plus_minus_slot() {
    QPushButton * button = (QPushButton*)sender();
    clicks[button->objectName()]->add_date_in_controller();
    draw();
}

void s21::Interface::on_pushButton_turn_clicked() {
    controller_->rotate(ui->doubleSpinBox_turn_x->value(),
                        ui->doubleSpinBox_turn_y->value(),
                        ui->doubleSpinBox_turn_z->value());
    draw();
}

void s21::Interface::on_radioButton_central_clicked() {
    s21::Settings::Instance().ProectionType() = 1;
    draw();
}

void s21::Interface::on_radioButton_parall_clicked() {
    s21::Settings::Instance().ProectionType() = 0;
    draw();
}

void s21::Interface::on_comboBox_typ_dots_currentIndexChanged(int index) {
    s21::Settings::Instance().DotType() = index;
    draw();
}

void s21::Interface::on_comboBox_typ_edge_currentIndexChanged(int index) {
    s21::Settings::Instance().FacetType() = index;
    draw();
}

void s21::Interface::on_pushButtonMakeScreenshot_clicked() {
    QImage screenshot = modelRender->grabFramebuffer();
    const QString format = "jpeg";
    QString default_path = "screenshots/";
    QFileDialog save_dialog(this, tr("Сохранить как"), default_path);
    save_dialog.setAcceptMode(QFileDialog::AcceptSave);
    save_dialog.setDirectory(default_path);
    save_dialog.setDefaultSuffix(format);
    QStringList mime_types({"image/jpeg", "image/png", "image/bmp"});
    save_dialog.setMimeTypeFilters(mime_types);
    if (save_dialog.exec() == QDialog::Accepted) {
        const QString fname = save_dialog.selectedFiles().constFirst();
        if (!screenshot.save(fname)) {
            QMessageBox::warning(this, tr("Ошибка"),
            tr("Невозможно сохранить изображение в \"%1\".")
            .arg(QDir::toNativeSeparators(fname)));
         }
    }
}

void s21::Interface::on_pushButtonMakeGif_clicked() {
    gifCreate_->writeGif() = true;
    ui->pushButtonStopMakeGif->setHidden(false);
    gifCreate_->addImage(modelRender->grabFramebuffer());
}

void s21::Interface::draw() {
    modelRender->initGeo();
    gifCreate_->addImage(modelRender->grabFramebuffer());
}

void s21::Interface::on_pushButtonStopMakeGif_clicked() {
    gifCreate_->createGif();
    ui->pushButtonStopMakeGif->setHidden(true);
}

