/********************************************************************************
** Form generated from reading UI file 'viewer3d.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWER3D_H
#define UI_VIEWER3D_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "MyQOpenGLWidget.h"

QT_BEGIN_NAMESPACE

class Ui_Viewer3D
{
public:
    QAction *load_file_2;
    QAction *action_exit;
    QAction *action_jpg;
    QAction *action_bmp;
    QAction *action_gif;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *top_info_panel;
    QLabel *save_lavel;
    QPushButton *jpeg_button;
    QPushButton *bmp_button;
    QPushButton *gif_button;
    QLabel *gif_label;
    QSpacerItem *horizontalSpacer_2;
    MyQOpenGLWidget *openGLWidget;
    QHBoxLayout *bottom_info_panel;
    QLabel *file_info;
    QSpacerItem *horizontalSpacer;
    QLabel *vertical_info;
    QScrollArea *panel;
    QWidget *panel_items;
    QVBoxLayout *verticalLayout;
    QPushButton *load_file;
    QVBoxLayout *move_layout;
    QLabel *move_label;
    QGridLayout *move_grid;
    QLabel *move_x_label;
    QDoubleSpinBox *move_y_spin;
    QLabel *move_z_label;
    QDoubleSpinBox *move_z_spin;
    QLabel *move_y_label;
    QDoubleSpinBox *move_x_spin;
    QVBoxLayout *rotate_layout;
    QLabel *rotate_label;
    QGridLayout *rotate_grid;
    QLabel *rotate_x_label;
    QDoubleSpinBox *rotate_x_spin;
    QDoubleSpinBox *rotate_y_spin;
    QLabel *rotate_z_label;
    QDoubleSpinBox *rotate_z_spin;
    QLabel *rotate_y_label;
    QVBoxLayout *scale_layout;
    QLabel *scale_label;
    QGridLayout *scale_grid;
    QLabel *scale_x_label;
    QDoubleSpinBox *scale_x_spin;
    QDoubleSpinBox *scale_y_spin;
    QLabel *scale_z_label;
    QLabel *scale_y_label;
    QDoubleSpinBox *scale_z_spin;
    QVBoxLayout *color_layout;
    QLabel *color_label;
    QGridLayout *color_grid;
    QLabel *color_red_label;
    QSpinBox *color_green_spin;
    QSpinBox *color_red_spin;
    QLabel *color_green_label;
    QSlider *color_blue_slider;
    QLabel *color_blue_label;
    QSpinBox *color_blue_spin;
    QSlider *color_green_slider;
    QSlider *color_red_slider;
    QVBoxLayout *projection_layout;
    QLabel *projection_label;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *orthographic;
    QRadioButton *perspective;
    QVBoxLayout *edges_layout;
    QLabel *edges_label;
    QHBoxLayout *edges_type_layout;
    QLabel *edges_type_label;
    QComboBox *edges_type_combo;
    QHBoxLayout *edges_size_layout;
    QLabel *edhes_size_label;
    QSlider *edges_size_slider;
    QSpinBox *edges_size_spin;
    QGroupBox *edges_group;
    QGridLayout *gridLayout;
    QSlider *edges_red_slider;
    QSpinBox *edges_green_spin;
    QSpinBox *edges_red_spin;
    QSpinBox *edges_blue_spin;
    QSlider *edges_green_slider;
    QSlider *edges_blue_slider;
    QLabel *edges_green_label;
    QLabel *edges_blue_label;
    QLabel *edges_red_label;
    QVBoxLayout *vertex_layout;
    QLabel *vertex_label;
    QHBoxLayout *vertex_type_layout;
    QLabel *vertex_type_label;
    QComboBox *vertex_type_combo;
    QHBoxLayout *vertex_size_layout;
    QLabel *vertex_size_label;
    QSlider *vertex_size_slide;
    QSpinBox *vertex_size_spin;
    QGroupBox *vertex_color_group;
    QGridLayout *gridLayout_2;
    QLabel *vertex_blue_label;
    QSlider *vertex_blue_slide;
    QLabel *vertex_red_label;
    QSlider *vertex_red_slide;
    QLabel *vertex_green_label;
    QSlider *vertex_green_slide;
    QSpinBox *vertex_red_spin;
    QSpinBox *vertex_green_spin;
    QSpinBox *vertex_blue_spin;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Viewer3D)
    {
        if (Viewer3D->objectName().isEmpty())
            Viewer3D->setObjectName("Viewer3D");
        Viewer3D->resize(1200, 1000);
        load_file_2 = new QAction(Viewer3D);
        load_file_2->setObjectName("load_file_2");
        action_exit = new QAction(Viewer3D);
        action_exit->setObjectName("action_exit");
        action_jpg = new QAction(Viewer3D);
        action_jpg->setObjectName("action_jpg");
        action_bmp = new QAction(Viewer3D);
        action_bmp->setObjectName("action_bmp");
        action_gif = new QAction(Viewer3D);
        action_gif->setObjectName("action_gif");
        centralwidget = new QWidget(Viewer3D);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(-1, -1, -1, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(9, 9, 9, 9);
        top_info_panel = new QHBoxLayout();
        top_info_panel->setObjectName("top_info_panel");
        save_lavel = new QLabel(centralwidget);
        save_lavel->setObjectName("save_lavel");

        top_info_panel->addWidget(save_lavel);

        jpeg_button = new QPushButton(centralwidget);
        jpeg_button->setObjectName("jpeg_button");
        jpeg_button->setCursor(QCursor(Qt::PointingHandCursor));

        top_info_panel->addWidget(jpeg_button);

        bmp_button = new QPushButton(centralwidget);
        bmp_button->setObjectName("bmp_button");
        bmp_button->setCursor(QCursor(Qt::PointingHandCursor));

        top_info_panel->addWidget(bmp_button);

        gif_button = new QPushButton(centralwidget);
        gif_button->setObjectName("gif_button");
        gif_button->setCursor(QCursor(Qt::PointingHandCursor));

        top_info_panel->addWidget(gif_button);

        gif_label = new QLabel(centralwidget);
        gif_label->setObjectName("gif_label");

        top_info_panel->addWidget(gif_label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        top_info_panel->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(top_info_panel);

        openGLWidget = new MyQOpenGLWidget(centralwidget);
        openGLWidget->setObjectName("openGLWidget");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(openGLWidget->sizePolicy().hasHeightForWidth());
        openGLWidget->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(openGLWidget);

        bottom_info_panel = new QHBoxLayout();
        bottom_info_panel->setObjectName("bottom_info_panel");
        file_info = new QLabel(centralwidget);
        file_info->setObjectName("file_info");

        bottom_info_panel->addWidget(file_info);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        bottom_info_panel->addItem(horizontalSpacer);

        vertical_info = new QLabel(centralwidget);
        vertical_info->setObjectName("vertical_info");

        bottom_info_panel->addWidget(vertical_info);


        verticalLayout_2->addLayout(bottom_info_panel);

        verticalLayout_2->setStretch(0, 5);
        verticalLayout_2->setStretch(1, 90);
        verticalLayout_2->setStretch(2, 5);

        horizontalLayout->addLayout(verticalLayout_2);

        panel = new QScrollArea(centralwidget);
        panel->setObjectName("panel");
        panel->setWidgetResizable(true);
        panel_items = new QWidget();
        panel_items->setObjectName("panel_items");
        panel_items->setGeometry(QRect(0, 0, 312, 941));
        verticalLayout = new QVBoxLayout(panel_items);
        verticalLayout->setObjectName("verticalLayout");
        load_file = new QPushButton(panel_items);
        load_file->setObjectName("load_file");
        load_file->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout->addWidget(load_file);

        move_layout = new QVBoxLayout();
        move_layout->setObjectName("move_layout");
        move_label = new QLabel(panel_items);
        move_label->setObjectName("move_label");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(move_label->sizePolicy().hasHeightForWidth());
        move_label->setSizePolicy(sizePolicy1);
        move_label->setAlignment(Qt::AlignCenter);

        move_layout->addWidget(move_label);

        move_grid = new QGridLayout();
        move_grid->setObjectName("move_grid");
        move_x_label = new QLabel(panel_items);
        move_x_label->setObjectName("move_x_label");
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(move_x_label->sizePolicy().hasHeightForWidth());
        move_x_label->setSizePolicy(sizePolicy2);
        move_x_label->setAlignment(Qt::AlignCenter);

        move_grid->addWidget(move_x_label, 0, 1, 1, 1);

        move_y_spin = new QDoubleSpinBox(panel_items);
        move_y_spin->setObjectName("move_y_spin");
        move_y_spin->setMinimum(-999.000000000000000);
        move_y_spin->setMaximum(999.000000000000000);
        move_y_spin->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        move_grid->addWidget(move_y_spin, 0, 4, 1, 1);

        move_z_label = new QLabel(panel_items);
        move_z_label->setObjectName("move_z_label");
        sizePolicy2.setHeightForWidth(move_z_label->sizePolicy().hasHeightForWidth());
        move_z_label->setSizePolicy(sizePolicy2);
        move_z_label->setAlignment(Qt::AlignCenter);

        move_grid->addWidget(move_z_label, 0, 5, 1, 1);

        move_z_spin = new QDoubleSpinBox(panel_items);
        move_z_spin->setObjectName("move_z_spin");
        move_z_spin->setMinimum(-999.000000000000000);
        move_z_spin->setMaximum(999.000000000000000);
        move_z_spin->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        move_grid->addWidget(move_z_spin, 0, 6, 1, 1);

        move_y_label = new QLabel(panel_items);
        move_y_label->setObjectName("move_y_label");
        sizePolicy2.setHeightForWidth(move_y_label->sizePolicy().hasHeightForWidth());
        move_y_label->setSizePolicy(sizePolicy2);
        move_y_label->setAlignment(Qt::AlignCenter);

        move_grid->addWidget(move_y_label, 0, 3, 1, 1);

        move_x_spin = new QDoubleSpinBox(panel_items);
        move_x_spin->setObjectName("move_x_spin");
        move_x_spin->setMinimum(-999.000000000000000);
        move_x_spin->setMaximum(999.000000000000000);
        move_x_spin->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        move_grid->addWidget(move_x_spin, 0, 2, 1, 1);


        move_layout->addLayout(move_grid);


        verticalLayout->addLayout(move_layout);

        rotate_layout = new QVBoxLayout();
        rotate_layout->setObjectName("rotate_layout");
        rotate_label = new QLabel(panel_items);
        rotate_label->setObjectName("rotate_label");
        sizePolicy1.setHeightForWidth(rotate_label->sizePolicy().hasHeightForWidth());
        rotate_label->setSizePolicy(sizePolicy1);
        rotate_label->setAlignment(Qt::AlignCenter);

        rotate_layout->addWidget(rotate_label);

        rotate_grid = new QGridLayout();
        rotate_grid->setObjectName("rotate_grid");
        rotate_x_label = new QLabel(panel_items);
        rotate_x_label->setObjectName("rotate_x_label");
        sizePolicy2.setHeightForWidth(rotate_x_label->sizePolicy().hasHeightForWidth());
        rotate_x_label->setSizePolicy(sizePolicy2);
        rotate_x_label->setAlignment(Qt::AlignCenter);

        rotate_grid->addWidget(rotate_x_label, 0, 0, 1, 1);

        rotate_x_spin = new QDoubleSpinBox(panel_items);
        rotate_x_spin->setObjectName("rotate_x_spin");
        rotate_x_spin->setMinimum(-360.000000000000000);
        rotate_x_spin->setMaximum(360.000000000000000);

        rotate_grid->addWidget(rotate_x_spin, 0, 1, 1, 1);

        rotate_y_spin = new QDoubleSpinBox(panel_items);
        rotate_y_spin->setObjectName("rotate_y_spin");
        rotate_y_spin->setMinimum(-360.000000000000000);
        rotate_y_spin->setMaximum(360.000000000000000);

        rotate_grid->addWidget(rotate_y_spin, 0, 3, 1, 1);

        rotate_z_label = new QLabel(panel_items);
        rotate_z_label->setObjectName("rotate_z_label");
        sizePolicy2.setHeightForWidth(rotate_z_label->sizePolicy().hasHeightForWidth());
        rotate_z_label->setSizePolicy(sizePolicy2);
        rotate_z_label->setAlignment(Qt::AlignCenter);

        rotate_grid->addWidget(rotate_z_label, 0, 4, 1, 1);

        rotate_z_spin = new QDoubleSpinBox(panel_items);
        rotate_z_spin->setObjectName("rotate_z_spin");
        rotate_z_spin->setMinimum(-360.000000000000000);
        rotate_z_spin->setMaximum(360.000000000000000);

        rotate_grid->addWidget(rotate_z_spin, 0, 5, 1, 1);

        rotate_y_label = new QLabel(panel_items);
        rotate_y_label->setObjectName("rotate_y_label");
        sizePolicy2.setHeightForWidth(rotate_y_label->sizePolicy().hasHeightForWidth());
        rotate_y_label->setSizePolicy(sizePolicy2);
        rotate_y_label->setAlignment(Qt::AlignCenter);

        rotate_grid->addWidget(rotate_y_label, 0, 2, 1, 1);


        rotate_layout->addLayout(rotate_grid);


        verticalLayout->addLayout(rotate_layout);

        scale_layout = new QVBoxLayout();
        scale_layout->setObjectName("scale_layout");
        scale_label = new QLabel(panel_items);
        scale_label->setObjectName("scale_label");
        sizePolicy1.setHeightForWidth(scale_label->sizePolicy().hasHeightForWidth());
        scale_label->setSizePolicy(sizePolicy1);
        scale_label->setAlignment(Qt::AlignCenter);

        scale_layout->addWidget(scale_label);

        scale_grid = new QGridLayout();
        scale_grid->setObjectName("scale_grid");
        scale_x_label = new QLabel(panel_items);
        scale_x_label->setObjectName("scale_x_label");
        sizePolicy2.setHeightForWidth(scale_x_label->sizePolicy().hasHeightForWidth());
        scale_x_label->setSizePolicy(sizePolicy2);
        scale_x_label->setAlignment(Qt::AlignCenter);

        scale_grid->addWidget(scale_x_label, 0, 0, 1, 1);

        scale_x_spin = new QDoubleSpinBox(panel_items);
        scale_x_spin->setObjectName("scale_x_spin");
        scale_x_spin->setMinimum(0.010000000000000);
        scale_x_spin->setMaximum(999.000000000000000);
        scale_x_spin->setValue(1.000000000000000);

        scale_grid->addWidget(scale_x_spin, 0, 1, 1, 1);

        scale_y_spin = new QDoubleSpinBox(panel_items);
        scale_y_spin->setObjectName("scale_y_spin");
        scale_y_spin->setMinimum(0.010000000000000);
        scale_y_spin->setMaximum(999.000000000000000);
        scale_y_spin->setValue(1.000000000000000);

        scale_grid->addWidget(scale_y_spin, 0, 3, 1, 1);

        scale_z_label = new QLabel(panel_items);
        scale_z_label->setObjectName("scale_z_label");
        sizePolicy2.setHeightForWidth(scale_z_label->sizePolicy().hasHeightForWidth());
        scale_z_label->setSizePolicy(sizePolicy2);
        scale_z_label->setAlignment(Qt::AlignCenter);

        scale_grid->addWidget(scale_z_label, 0, 4, 1, 1);

        scale_y_label = new QLabel(panel_items);
        scale_y_label->setObjectName("scale_y_label");
        sizePolicy2.setHeightForWidth(scale_y_label->sizePolicy().hasHeightForWidth());
        scale_y_label->setSizePolicy(sizePolicy2);
        scale_y_label->setAlignment(Qt::AlignCenter);

        scale_grid->addWidget(scale_y_label, 0, 2, 1, 1);

        scale_z_spin = new QDoubleSpinBox(panel_items);
        scale_z_spin->setObjectName("scale_z_spin");
        scale_z_spin->setMinimum(0.010000000000000);
        scale_z_spin->setMaximum(999.000000000000000);
        scale_z_spin->setValue(1.000000000000000);

        scale_grid->addWidget(scale_z_spin, 0, 5, 1, 1);


        scale_layout->addLayout(scale_grid);


        verticalLayout->addLayout(scale_layout);

        color_layout = new QVBoxLayout();
        color_layout->setObjectName("color_layout");
        color_label = new QLabel(panel_items);
        color_label->setObjectName("color_label");
        sizePolicy1.setHeightForWidth(color_label->sizePolicy().hasHeightForWidth());
        color_label->setSizePolicy(sizePolicy1);
        color_label->setAlignment(Qt::AlignCenter);

        color_layout->addWidget(color_label);

        color_grid = new QGridLayout();
        color_grid->setObjectName("color_grid");
        color_red_label = new QLabel(panel_items);
        color_red_label->setObjectName("color_red_label");
        sizePolicy2.setHeightForWidth(color_red_label->sizePolicy().hasHeightForWidth());
        color_red_label->setSizePolicy(sizePolicy2);
        color_red_label->setAlignment(Qt::AlignCenter);

        color_grid->addWidget(color_red_label, 0, 0, 1, 1);

        color_green_spin = new QSpinBox(panel_items);
        color_green_spin->setObjectName("color_green_spin");
        color_green_spin->setMaximum(255);

        color_grid->addWidget(color_green_spin, 1, 2, 1, 1);

        color_red_spin = new QSpinBox(panel_items);
        color_red_spin->setObjectName("color_red_spin");
        color_red_spin->setMaximum(255);

        color_grid->addWidget(color_red_spin, 0, 2, 1, 1);

        color_green_label = new QLabel(panel_items);
        color_green_label->setObjectName("color_green_label");
        sizePolicy2.setHeightForWidth(color_green_label->sizePolicy().hasHeightForWidth());
        color_green_label->setSizePolicy(sizePolicy2);
        color_green_label->setAlignment(Qt::AlignCenter);

        color_grid->addWidget(color_green_label, 1, 0, 1, 1);

        color_blue_slider = new QSlider(panel_items);
        color_blue_slider->setObjectName("color_blue_slider");
        color_blue_slider->setMaximum(255);
        color_blue_slider->setOrientation(Qt::Horizontal);

        color_grid->addWidget(color_blue_slider, 2, 1, 1, 1);

        color_blue_label = new QLabel(panel_items);
        color_blue_label->setObjectName("color_blue_label");
        sizePolicy2.setHeightForWidth(color_blue_label->sizePolicy().hasHeightForWidth());
        color_blue_label->setSizePolicy(sizePolicy2);
        color_blue_label->setAlignment(Qt::AlignCenter);

        color_grid->addWidget(color_blue_label, 2, 0, 1, 1);

        color_blue_spin = new QSpinBox(panel_items);
        color_blue_spin->setObjectName("color_blue_spin");
        color_blue_spin->setMaximum(255);

        color_grid->addWidget(color_blue_spin, 2, 2, 1, 1);

        color_green_slider = new QSlider(panel_items);
        color_green_slider->setObjectName("color_green_slider");
        color_green_slider->setMaximum(255);
        color_green_slider->setOrientation(Qt::Horizontal);

        color_grid->addWidget(color_green_slider, 1, 1, 1, 1);

        color_red_slider = new QSlider(panel_items);
        color_red_slider->setObjectName("color_red_slider");
        color_red_slider->setMaximum(255);
        color_red_slider->setOrientation(Qt::Horizontal);

        color_grid->addWidget(color_red_slider, 0, 1, 1, 1);


        color_layout->addLayout(color_grid);


        verticalLayout->addLayout(color_layout);

        projection_layout = new QVBoxLayout();
        projection_layout->setObjectName("projection_layout");
        projection_label = new QLabel(panel_items);
        projection_label->setObjectName("projection_label");
        sizePolicy1.setHeightForWidth(projection_label->sizePolicy().hasHeightForWidth());
        projection_label->setSizePolicy(sizePolicy1);
        projection_label->setAlignment(Qt::AlignCenter);

        projection_layout->addWidget(projection_label);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        orthographic = new QRadioButton(panel_items);
        orthographic->setObjectName("orthographic");
        orthographic->setCursor(QCursor(Qt::PointingHandCursor));
        orthographic->setChecked(true);

        verticalLayout_3->addWidget(orthographic);

        perspective = new QRadioButton(panel_items);
        perspective->setObjectName("perspective");
        perspective->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_3->addWidget(perspective);


        projection_layout->addLayout(verticalLayout_3);


        verticalLayout->addLayout(projection_layout);

        edges_layout = new QVBoxLayout();
        edges_layout->setObjectName("edges_layout");
        edges_label = new QLabel(panel_items);
        edges_label->setObjectName("edges_label");
        sizePolicy1.setHeightForWidth(edges_label->sizePolicy().hasHeightForWidth());
        edges_label->setSizePolicy(sizePolicy1);
        edges_label->setAlignment(Qt::AlignCenter);

        edges_layout->addWidget(edges_label);

        edges_type_layout = new QHBoxLayout();
        edges_type_layout->setObjectName("edges_type_layout");
        edges_type_label = new QLabel(panel_items);
        edges_type_label->setObjectName("edges_type_label");

        edges_type_layout->addWidget(edges_type_label);

        edges_type_combo = new QComboBox(panel_items);
        edges_type_combo->addItem(QString());
        edges_type_combo->addItem(QString());
        edges_type_combo->addItem(QString());
        edges_type_combo->setObjectName("edges_type_combo");
        edges_type_combo->setCursor(QCursor(Qt::PointingHandCursor));

        edges_type_layout->addWidget(edges_type_combo);


        edges_layout->addLayout(edges_type_layout);

        edges_size_layout = new QHBoxLayout();
        edges_size_layout->setObjectName("edges_size_layout");
        edhes_size_label = new QLabel(panel_items);
        edhes_size_label->setObjectName("edhes_size_label");

        edges_size_layout->addWidget(edhes_size_label);

        edges_size_slider = new QSlider(panel_items);
        edges_size_slider->setObjectName("edges_size_slider");
        edges_size_slider->setMinimum(1);
        edges_size_slider->setMaximum(99);
        edges_size_slider->setOrientation(Qt::Horizontal);

        edges_size_layout->addWidget(edges_size_slider);

        edges_size_spin = new QSpinBox(panel_items);
        edges_size_spin->setObjectName("edges_size_spin");
        edges_size_spin->setMinimum(1);

        edges_size_layout->addWidget(edges_size_spin);


        edges_layout->addLayout(edges_size_layout);

        edges_group = new QGroupBox(panel_items);
        edges_group->setObjectName("edges_group");
        gridLayout = new QGridLayout(edges_group);
        gridLayout->setObjectName("gridLayout");
        edges_red_slider = new QSlider(edges_group);
        edges_red_slider->setObjectName("edges_red_slider");
        edges_red_slider->setMaximum(255);
        edges_red_slider->setValue(255);
        edges_red_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(edges_red_slider, 0, 1, 1, 1);

        edges_green_spin = new QSpinBox(edges_group);
        edges_green_spin->setObjectName("edges_green_spin");
        edges_green_spin->setMaximum(255);
        edges_green_spin->setValue(255);

        gridLayout->addWidget(edges_green_spin, 1, 2, 1, 1);

        edges_red_spin = new QSpinBox(edges_group);
        edges_red_spin->setObjectName("edges_red_spin");
        edges_red_spin->setMaximum(255);
        edges_red_spin->setValue(255);

        gridLayout->addWidget(edges_red_spin, 0, 2, 1, 1);

        edges_blue_spin = new QSpinBox(edges_group);
        edges_blue_spin->setObjectName("edges_blue_spin");
        edges_blue_spin->setMaximum(255);
        edges_blue_spin->setValue(255);

        gridLayout->addWidget(edges_blue_spin, 2, 2, 1, 1);

        edges_green_slider = new QSlider(edges_group);
        edges_green_slider->setObjectName("edges_green_slider");
        edges_green_slider->setMaximum(255);
        edges_green_slider->setValue(255);
        edges_green_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(edges_green_slider, 1, 1, 1, 1);

        edges_blue_slider = new QSlider(edges_group);
        edges_blue_slider->setObjectName("edges_blue_slider");
        edges_blue_slider->setMaximum(255);
        edges_blue_slider->setValue(255);
        edges_blue_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(edges_blue_slider, 2, 1, 1, 1);

        edges_green_label = new QLabel(edges_group);
        edges_green_label->setObjectName("edges_green_label");

        gridLayout->addWidget(edges_green_label, 1, 0, 1, 1);

        edges_blue_label = new QLabel(edges_group);
        edges_blue_label->setObjectName("edges_blue_label");

        gridLayout->addWidget(edges_blue_label, 2, 0, 1, 1);

        edges_red_label = new QLabel(edges_group);
        edges_red_label->setObjectName("edges_red_label");

        gridLayout->addWidget(edges_red_label, 0, 0, 1, 1);


        edges_layout->addWidget(edges_group);


        verticalLayout->addLayout(edges_layout);

        vertex_layout = new QVBoxLayout();
        vertex_layout->setObjectName("vertex_layout");
        vertex_label = new QLabel(panel_items);
        vertex_label->setObjectName("vertex_label");
        sizePolicy1.setHeightForWidth(vertex_label->sizePolicy().hasHeightForWidth());
        vertex_label->setSizePolicy(sizePolicy1);
        vertex_label->setAlignment(Qt::AlignCenter);

        vertex_layout->addWidget(vertex_label);

        vertex_type_layout = new QHBoxLayout();
        vertex_type_layout->setObjectName("vertex_type_layout");
        vertex_type_label = new QLabel(panel_items);
        vertex_type_label->setObjectName("vertex_type_label");

        vertex_type_layout->addWidget(vertex_type_label);

        vertex_type_combo = new QComboBox(panel_items);
        vertex_type_combo->addItem(QString());
        vertex_type_combo->addItem(QString());
        vertex_type_combo->addItem(QString());
        vertex_type_combo->setObjectName("vertex_type_combo");
        vertex_type_combo->setCursor(QCursor(Qt::PointingHandCursor));

        vertex_type_layout->addWidget(vertex_type_combo);


        vertex_layout->addLayout(vertex_type_layout);

        vertex_size_layout = new QHBoxLayout();
        vertex_size_layout->setObjectName("vertex_size_layout");
        vertex_size_label = new QLabel(panel_items);
        vertex_size_label->setObjectName("vertex_size_label");

        vertex_size_layout->addWidget(vertex_size_label);

        vertex_size_slide = new QSlider(panel_items);
        vertex_size_slide->setObjectName("vertex_size_slide");
        vertex_size_slide->setMinimum(1);
        vertex_size_slide->setOrientation(Qt::Horizontal);

        vertex_size_layout->addWidget(vertex_size_slide);

        vertex_size_spin = new QSpinBox(panel_items);
        vertex_size_spin->setObjectName("vertex_size_spin");
        vertex_size_spin->setMinimum(1);

        vertex_size_layout->addWidget(vertex_size_spin);


        vertex_layout->addLayout(vertex_size_layout);

        vertex_color_group = new QGroupBox(panel_items);
        vertex_color_group->setObjectName("vertex_color_group");
        gridLayout_2 = new QGridLayout(vertex_color_group);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(-1, 4, -1, 4);
        vertex_blue_label = new QLabel(vertex_color_group);
        vertex_blue_label->setObjectName("vertex_blue_label");

        gridLayout_2->addWidget(vertex_blue_label, 2, 0, 1, 1);

        vertex_blue_slide = new QSlider(vertex_color_group);
        vertex_blue_slide->setObjectName("vertex_blue_slide");
        vertex_blue_slide->setMaximum(255);
        vertex_blue_slide->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(vertex_blue_slide, 2, 1, 1, 1);

        vertex_red_label = new QLabel(vertex_color_group);
        vertex_red_label->setObjectName("vertex_red_label");

        gridLayout_2->addWidget(vertex_red_label, 0, 0, 1, 1);

        vertex_red_slide = new QSlider(vertex_color_group);
        vertex_red_slide->setObjectName("vertex_red_slide");
        vertex_red_slide->setMaximum(255);
        vertex_red_slide->setValue(255);
        vertex_red_slide->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(vertex_red_slide, 0, 1, 1, 1);

        vertex_green_label = new QLabel(vertex_color_group);
        vertex_green_label->setObjectName("vertex_green_label");

        gridLayout_2->addWidget(vertex_green_label, 1, 0, 1, 1);

        vertex_green_slide = new QSlider(vertex_color_group);
        vertex_green_slide->setObjectName("vertex_green_slide");
        vertex_green_slide->setMaximum(255);
        vertex_green_slide->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(vertex_green_slide, 1, 1, 1, 1);

        vertex_red_spin = new QSpinBox(vertex_color_group);
        vertex_red_spin->setObjectName("vertex_red_spin");
        vertex_red_spin->setMaximum(255);
        vertex_red_spin->setValue(255);

        gridLayout_2->addWidget(vertex_red_spin, 0, 2, 1, 1);

        vertex_green_spin = new QSpinBox(vertex_color_group);
        vertex_green_spin->setObjectName("vertex_green_spin");
        vertex_green_spin->setMaximum(255);

        gridLayout_2->addWidget(vertex_green_spin, 1, 2, 1, 1);

        vertex_blue_spin = new QSpinBox(vertex_color_group);
        vertex_blue_spin->setObjectName("vertex_blue_spin");
        vertex_blue_spin->setMaximum(255);

        gridLayout_2->addWidget(vertex_blue_spin, 2, 2, 1, 1);


        vertex_layout->addWidget(vertex_color_group);


        verticalLayout->addLayout(vertex_layout);

        panel->setWidget(panel_items);

        horizontalLayout->addWidget(panel);

        horizontalLayout->setStretch(0, 85);
        Viewer3D->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Viewer3D);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1173, 24));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menu);
        menu_2->setObjectName("menu_2");
        Viewer3D->setMenuBar(menubar);
        statusbar = new QStatusBar(Viewer3D);
        statusbar->setObjectName("statusbar");
        Viewer3D->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(load_file_2);
        menu->addAction(menu_2->menuAction());
        menu->addAction(action_exit);
        menu_2->addAction(action_jpg);
        menu_2->addAction(action_bmp);
        menu_2->addAction(action_gif);

        retranslateUi(Viewer3D);
        QObject::connect(color_red_slider, &QSlider::valueChanged, color_red_spin, &QSpinBox::setValue);
        QObject::connect(color_red_spin, &QSpinBox::valueChanged, color_red_slider, &QSlider::setValue);
        QObject::connect(color_green_slider, &QSlider::valueChanged, color_green_spin, &QSpinBox::setValue);
        QObject::connect(color_green_spin, &QSpinBox::valueChanged, color_green_slider, &QSlider::setValue);
        QObject::connect(color_blue_spin, &QSpinBox::valueChanged, color_blue_slider, &QSlider::setValue);
        QObject::connect(color_blue_slider, &QSlider::valueChanged, color_blue_spin, &QSpinBox::setValue);
        QObject::connect(edges_size_slider, &QSlider::valueChanged, edges_size_spin, &QSpinBox::setValue);
        QObject::connect(edges_red_slider, &QSlider::valueChanged, edges_red_spin, &QSpinBox::setValue);
        QObject::connect(edges_red_spin, &QSpinBox::valueChanged, edges_red_slider, &QSlider::setValue);
        QObject::connect(edges_blue_slider, &QSlider::valueChanged, edges_blue_spin, &QSpinBox::setValue);
        QObject::connect(edges_blue_spin, &QSpinBox::valueChanged, edges_blue_slider, &QSlider::setValue);
        QObject::connect(edges_green_slider, &QSlider::valueChanged, edges_green_spin, &QSpinBox::setValue);
        QObject::connect(edges_green_spin, &QSpinBox::valueChanged, edges_green_slider, &QSlider::setValue);
        QObject::connect(edges_size_spin, &QSpinBox::valueChanged, edges_size_slider, &QSlider::setValue);
        QObject::connect(vertex_red_slide, &QSlider::valueChanged, vertex_red_spin, &QSpinBox::setValue);
        QObject::connect(vertex_red_spin, &QSpinBox::valueChanged, vertex_red_slide, &QSlider::setValue);
        QObject::connect(vertex_green_slide, &QSlider::valueChanged, vertex_green_spin, &QSpinBox::setValue);
        QObject::connect(vertex_green_spin, &QSpinBox::valueChanged, vertex_green_slide, &QSlider::setValue);
        QObject::connect(vertex_blue_slide, &QSlider::valueChanged, vertex_blue_spin, &QSpinBox::setValue);
        QObject::connect(vertex_blue_spin, &QSpinBox::valueChanged, vertex_blue_slide, &QSlider::setValue);
        QObject::connect(vertex_size_slide, &QSlider::valueChanged, vertex_size_spin, &QSpinBox::setValue);
        QObject::connect(vertex_size_spin, &QSpinBox::valueChanged, vertex_size_slide, &QSlider::setValue);

        QMetaObject::connectSlotsByName(Viewer3D);
    } // setupUi

    void retranslateUi(QMainWindow *Viewer3D)
    {
        Viewer3D->setWindowTitle(QCoreApplication::translate("Viewer3D", "3DViewer v1.0 | lcardiga X fhiedi ", nullptr));
        load_file_2->setText(QCoreApplication::translate("Viewer3D", "Upload file", nullptr));
        action_exit->setText(QCoreApplication::translate("Viewer3D", "Exit", nullptr));
        action_jpg->setText(QCoreApplication::translate("Viewer3D", "*.jpg", nullptr));
        action_bmp->setText(QCoreApplication::translate("Viewer3D", "*.bmp", nullptr));
        action_gif->setText(QCoreApplication::translate("Viewer3D", "*.gif", nullptr));
        save_lavel->setText(QCoreApplication::translate("Viewer3D", "Save as", nullptr));
        jpeg_button->setText(QCoreApplication::translate("Viewer3D", "jpeg", nullptr));
        bmp_button->setText(QCoreApplication::translate("Viewer3D", "bmp", nullptr));
        gif_button->setText(QCoreApplication::translate("Viewer3D", "gif", nullptr));
        gif_label->setText(QString());
        file_info->setText(QString());
        vertical_info->setText(QString());
        load_file->setText(QCoreApplication::translate("Viewer3D", "Upload file", nullptr));
        move_label->setText(QCoreApplication::translate("Viewer3D", "Shift", nullptr));
        move_x_label->setText(QCoreApplication::translate("Viewer3D", "X", nullptr));
        move_z_label->setText(QCoreApplication::translate("Viewer3D", "Z", nullptr));
        move_y_label->setText(QCoreApplication::translate("Viewer3D", "Y", nullptr));
        rotate_label->setText(QCoreApplication::translate("Viewer3D", "Rotation", nullptr));
        rotate_x_label->setText(QCoreApplication::translate("Viewer3D", "X", nullptr));
        rotate_z_label->setText(QCoreApplication::translate("Viewer3D", "Z", nullptr));
        rotate_y_label->setText(QCoreApplication::translate("Viewer3D", "Y", nullptr));
        scale_label->setText(QCoreApplication::translate("Viewer3D", "Scope", nullptr));
        scale_x_label->setText(QCoreApplication::translate("Viewer3D", "X", nullptr));
        scale_z_label->setText(QCoreApplication::translate("Viewer3D", "Z", nullptr));
        scale_y_label->setText(QCoreApplication::translate("Viewer3D", "Y", nullptr));
        color_label->setText(QCoreApplication::translate("Viewer3D", "Background color", nullptr));
        color_red_label->setText(QCoreApplication::translate("Viewer3D", "R", nullptr));
        color_green_label->setText(QCoreApplication::translate("Viewer3D", "G", nullptr));
        color_blue_label->setText(QCoreApplication::translate("Viewer3D", "B", nullptr));
        projection_label->setText(QCoreApplication::translate("Viewer3D", "Projection", nullptr));
        orthographic->setText(QCoreApplication::translate("Viewer3D", "Parallel", nullptr));
        perspective->setText(QCoreApplication::translate("Viewer3D", "Central", nullptr));
        edges_label->setText(QCoreApplication::translate("Viewer3D", "Settings of edges", nullptr));
        edges_type_label->setText(QCoreApplication::translate("Viewer3D", "Type:", nullptr));
        edges_type_combo->setItemText(0, QCoreApplication::translate("Viewer3D", "No", nullptr));
        edges_type_combo->setItemText(1, QCoreApplication::translate("Viewer3D", "Solid", nullptr));
        edges_type_combo->setItemText(2, QCoreApplication::translate("Viewer3D", "Dotted", nullptr));

        edhes_size_label->setText(QCoreApplication::translate("Viewer3D", "Size:", nullptr));
        edges_group->setTitle(QCoreApplication::translate("Viewer3D", "Color of edges", nullptr));
        edges_green_label->setText(QCoreApplication::translate("Viewer3D", "G", nullptr));
        edges_blue_label->setText(QCoreApplication::translate("Viewer3D", "B", nullptr));
        edges_red_label->setText(QCoreApplication::translate("Viewer3D", "R", nullptr));
        vertex_label->setText(QCoreApplication::translate("Viewer3D", "Vertexes settings", nullptr));
        vertex_type_label->setText(QCoreApplication::translate("Viewer3D", "Shape", nullptr));
        vertex_type_combo->setItemText(0, QCoreApplication::translate("Viewer3D", "No", nullptr));
        vertex_type_combo->setItemText(1, QCoreApplication::translate("Viewer3D", "Square", nullptr));
        vertex_type_combo->setItemText(2, QCoreApplication::translate("Viewer3D", "Circle", nullptr));

        vertex_size_label->setText(QCoreApplication::translate("Viewer3D", "Size", nullptr));
        vertex_blue_label->setText(QCoreApplication::translate("Viewer3D", "B", nullptr));
        vertex_red_label->setText(QCoreApplication::translate("Viewer3D", "R", nullptr));
        vertex_green_label->setText(QCoreApplication::translate("Viewer3D", "G", nullptr));
        menu->setTitle(QCoreApplication::translate("Viewer3D", "\320\244\320\260\320\271\320\273", nullptr));
        menu_2->setTitle(QCoreApplication::translate("Viewer3D", "Save as...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Viewer3D: public Ui_Viewer3D {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWER3D_H
