#include "clicks.h"

void s21::Move_x_plus::add_date_in_controller() {
    get_controller()->move(0.5, 0, 0);
}

void s21::Move_y_plus::add_date_in_controller() {
    get_controller()->move(0, 0.5, 0);
}

void s21::Move_z_plus::add_date_in_controller() {
    get_controller()->move(0, 0, 0.5);
}

void s21::Move_x_minus::add_date_in_controller() {
    get_controller()->move(-0.5, 0, 0);
}

void s21::Move_y_minus::add_date_in_controller() {
    get_controller()->move(0, -0.5, 0);
}

void s21::Move_z_minus::add_date_in_controller() {
    get_controller()->move(0, 0, -0.5);
}

void s21::Turn_x_plus::add_date_in_controller() {
    get_controller()->rotate(5, 0, 0);
}

void s21::Turn_y_plus::add_date_in_controller() {
    get_controller()->rotate(0, 5, 0);
}

void s21::Turn_z_plus::add_date_in_controller() {
    get_controller()->rotate(0, 0, 5);
}

void s21::Turn_x_minus::add_date_in_controller() {
    get_controller()->rotate(-5, 0, 0);
}

void s21::Turn_y_minus::add_date_in_controller() {
    get_controller()->rotate(0, -5, 0);
}

void s21::Turn_z_minus::add_date_in_controller() {
    get_controller()->rotate(0, 0, -5);
}

void s21::Scale_minus::add_date_in_controller() {
    get_controller()->scale(0.9);
}

void s21::Scale_plus::add_date_in_controller() {
    get_controller()->scale(1.1);
}

void s21::Size_dots_plus::add_date_in_controller() {
    if (Settings::Instance().DotSize() < 50)
        Settings::Instance().DotSize()++;
}

void s21::Size_dots_minus::add_date_in_controller() {
    if (Settings::Instance().DotSize() > 1)
        Settings::Instance().DotSize()--;
}

void s21::Size_edges_plus::add_date_in_controller() {
    if (Settings::Instance().FacetSize() < 50)
        Settings::Instance().FacetSize()++;
}

void s21::Size_edges_minus::add_date_in_controller() {
    if (Settings::Instance().FacetSize() > 1)
    Settings::Instance().FacetSize()--;
}

void s21::CenteringPicture::add_date_in_controller() {
    get_controller()->centeringPicture();
}

