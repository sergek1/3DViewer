/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

#include "glwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow {
 public:
  QWidget *centralwidget;
  QHBoxLayout *horizontalLayout;
  QVBoxLayout *verticalLayout;
  QLabel *file_name;
  QLabel *vertexes_edges;
  QHBoxLayout *horizontalLayout_3;
  QLabel *label;
  QLabel *label_14;
  QDoubleSpinBox *x;
  QLabel *label_13;
  QDoubleSpinBox *y;
  QLabel *label_12;
  QDoubleSpinBox *z;
  QHBoxLayout *horizontalLayout_4;
  QLabel *label_7;
  QLabel *label_16;
  QSpinBox *angle_x;
  QLabel *label_15;
  QSpinBox *angle_y;
  QLabel *label_3;
  QSpinBox *angle_z;
  QHBoxLayout *horizontalLayout_6;
  QLabel *label_2;
  QDoubleSpinBox *scale;
  QLabel *label_4;
  QLabel *label_6;
  QHBoxLayout *horizontalLayout_7;
  QLabel *label_23;
  QComboBox *projection_type;
  QLabel *label_5;
  QLabel *label_9;
  QLabel *label_19;
  QHBoxLayout *horizontalLayout_12;
  QLabel *label_18;
  QComboBox *line_type;
  QLabel *label_17;
  QDoubleSpinBox *line_thickness;
  QLabel *label_24;
  QHBoxLayout *horizontalLayout_13;
  QLabel *label_25;
  QComboBox *vertex_type;
  QLabel *label_26;
  QDoubleSpinBox *vertex_size;
  QLabel *label_8;
  QLabel *label_31;
  QHBoxLayout *horizontalLayout_15;
  QPushButton *color_back;
  QPushButton *color_line;
  QPushButton *color_vertex;
  QCheckBox *default_2;
  QSpacerItem *verticalSpacer;
  QHBoxLayout *horizontalLayout_8;
  QPushButton *save_image;
  QPushButton *screencast;
  QPushButton *open_file;
  s21::GLWidget *GLwidget;
  QStatusBar *statusbar;

  void setupUi(QMainWindow *MainWindow) {
    if (MainWindow->objectName().isEmpty())
      MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->setWindowModality(Qt::NonModal);
    MainWindow->resize(1000, 627);
    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
    MainWindow->setSizePolicy(sizePolicy);
    MainWindow->setMinimumSize(QSize(1000, 600));
    MainWindow->setMaximumSize(QSize(1000, 627));
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    centralwidget->setMinimumSize(QSize(200, 600));
    centralwidget->setMaximumSize(QSize(1000, 600));
    horizontalLayout = new QHBoxLayout(centralwidget);
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    verticalLayout = new QVBoxLayout();
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
    file_name = new QLabel(centralwidget);
    file_name->setObjectName(QString::fromUtf8("file_name"));
    sizePolicy.setHeightForWidth(file_name->sizePolicy().hasHeightForWidth());
    file_name->setSizePolicy(sizePolicy);
    file_name->setMaximumSize(QSize(350, 20));
    file_name->setStyleSheet(QString::fromUtf8("font-weight: bold;"));
    file_name->setAlignment(Qt::AlignCenter);

    verticalLayout->addWidget(file_name);

    vertexes_edges = new QLabel(centralwidget);
    vertexes_edges->setObjectName(QString::fromUtf8("vertexes_edges"));
    vertexes_edges->setMaximumSize(QSize(350, 20));
    vertexes_edges->setStyleSheet(QString::fromUtf8("font-weight: bold;"));
    vertexes_edges->setAlignment(Qt::AlignCenter);

    verticalLayout->addWidget(vertexes_edges);

    horizontalLayout_3 = new QHBoxLayout();
    horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
    label = new QLabel(centralwidget);
    label->setObjectName(QString::fromUtf8("label"));
    sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
    label->setSizePolicy(sizePolicy);
    label->setMaximumSize(QSize(65, 20));
    QFont font;
    font.setBold(true);
    label->setFont(font);
    label->setAlignment(Qt::AlignCenter);

    horizontalLayout_3->addWidget(label);

    label_14 = new QLabel(centralwidget);
    label_14->setObjectName(QString::fromUtf8("label_14"));
    sizePolicy.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
    label_14->setSizePolicy(sizePolicy);
    label_14->setMaximumSize(QSize(15, 20));
    label_14->setAlignment(Qt::AlignRight | Qt::AlignTrailing |
                           Qt::AlignVCenter);

    horizontalLayout_3->addWidget(label_14);

    x = new QDoubleSpinBox(centralwidget);
    x->setObjectName(QString::fromUtf8("x"));
    sizePolicy.setHeightForWidth(x->sizePolicy().hasHeightForWidth());
    x->setSizePolicy(sizePolicy);
    x->setMinimumSize(QSize(50, 20));
    x->setMaximumSize(QSize(70, 20));
    x->setMinimum(-200.000000000000000);
    x->setMaximum(200.000000000000000);
    x->setSingleStep(10.000000000000000);

    horizontalLayout_3->addWidget(x);

    label_13 = new QLabel(centralwidget);
    label_13->setObjectName(QString::fromUtf8("label_13"));
    sizePolicy.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
    label_13->setSizePolicy(sizePolicy);
    label_13->setMaximumSize(QSize(15, 20));
    label_13->setAlignment(Qt::AlignRight | Qt::AlignTrailing |
                           Qt::AlignVCenter);

    horizontalLayout_3->addWidget(label_13);

    y = new QDoubleSpinBox(centralwidget);
    y->setObjectName(QString::fromUtf8("y"));
    sizePolicy.setHeightForWidth(y->sizePolicy().hasHeightForWidth());
    y->setSizePolicy(sizePolicy);
    y->setMinimumSize(QSize(50, 20));
    y->setMaximumSize(QSize(70, 20));
    y->setMinimum(-200.000000000000000);
    y->setMaximum(200.000000000000000);
    y->setSingleStep(10.000000000000000);
    y->setValue(0.000000000000000);

    horizontalLayout_3->addWidget(y);

    label_12 = new QLabel(centralwidget);
    label_12->setObjectName(QString::fromUtf8("label_12"));
    sizePolicy.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
    label_12->setSizePolicy(sizePolicy);
    label_12->setMaximumSize(QSize(15, 20));
    label_12->setAlignment(Qt::AlignRight | Qt::AlignTrailing |
                           Qt::AlignVCenter);

    horizontalLayout_3->addWidget(label_12);

    z = new QDoubleSpinBox(centralwidget);
    z->setObjectName(QString::fromUtf8("z"));
    sizePolicy.setHeightForWidth(z->sizePolicy().hasHeightForWidth());
    z->setSizePolicy(sizePolicy);
    z->setMinimumSize(QSize(50, 10));
    z->setMaximumSize(QSize(70, 20));
    z->setMinimum(-1000.000000000000000);
    z->setMaximum(1000.000000000000000);
    z->setSingleStep(5.000000000000000);
    z->setStepType(QAbstractSpinBox::DefaultStepType);
    z->setValue(0.000000000000000);

    horizontalLayout_3->addWidget(z);

    verticalLayout->addLayout(horizontalLayout_3);

    horizontalLayout_4 = new QHBoxLayout();
    horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
    label_7 = new QLabel(centralwidget);
    label_7->setObjectName(QString::fromUtf8("label_7"));
    sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
    label_7->setSizePolicy(sizePolicy);
    label_7->setMaximumSize(QSize(65, 20));
    label_7->setFont(font);
    label_7->setAlignment(Qt::AlignCenter);

    horizontalLayout_4->addWidget(label_7);

    label_16 = new QLabel(centralwidget);
    label_16->setObjectName(QString::fromUtf8("label_16"));
    sizePolicy.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
    label_16->setSizePolicy(sizePolicy);
    label_16->setMaximumSize(QSize(23, 20));
    label_16->setAlignment(Qt::AlignRight | Qt::AlignTrailing |
                           Qt::AlignVCenter);

    horizontalLayout_4->addWidget(label_16);

    angle_x = new QSpinBox(centralwidget);
    angle_x->setObjectName(QString::fromUtf8("angle_x"));
    sizePolicy.setHeightForWidth(angle_x->sizePolicy().hasHeightForWidth());
    angle_x->setSizePolicy(sizePolicy);
    angle_x->setMinimumSize(QSize(20, 0));
    angle_x->setMaximumSize(QSize(70, 20));
    angle_x->setMinimum(-360);
    angle_x->setMaximum(360);
    angle_x->setSingleStep(10);

    horizontalLayout_4->addWidget(angle_x);

    label_15 = new QLabel(centralwidget);
    label_15->setObjectName(QString::fromUtf8("label_15"));
    label_15->setMaximumSize(QSize(23, 20));
    label_15->setCursor(QCursor(Qt::ArrowCursor));
    label_15->setLayoutDirection(Qt::RightToLeft);
    label_15->setAlignment(Qt::AlignRight | Qt::AlignTrailing |
                           Qt::AlignVCenter);

    horizontalLayout_4->addWidget(label_15);

    angle_y = new QSpinBox(centralwidget);
    angle_y->setObjectName(QString::fromUtf8("angle_y"));
    angle_y->setMaximumSize(QSize(70, 20));
    angle_y->setMinimum(-360);
    angle_y->setMaximum(360);
    angle_y->setSingleStep(10);

    horizontalLayout_4->addWidget(angle_y);

    label_3 = new QLabel(centralwidget);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setMaximumSize(QSize(23, 20));
    label_3->setAlignment(Qt::AlignRight | Qt::AlignTrailing |
                          Qt::AlignVCenter);

    horizontalLayout_4->addWidget(label_3);

    angle_z = new QSpinBox(centralwidget);
    angle_z->setObjectName(QString::fromUtf8("angle_z"));
    sizePolicy.setHeightForWidth(angle_z->sizePolicy().hasHeightForWidth());
    angle_z->setSizePolicy(sizePolicy);
    angle_z->setMinimumSize(QSize(70, 20));
    angle_z->setMaximumSize(QSize(70, 20));
    angle_z->setMinimum(-360);
    angle_z->setMaximum(360);
    angle_z->setSingleStep(10);

    horizontalLayout_4->addWidget(angle_z);

    verticalLayout->addLayout(horizontalLayout_4);

    horizontalLayout_6 = new QHBoxLayout();
    horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
    horizontalLayout_6->setSizeConstraint(QLayout::SetMinAndMaxSize);
    label_2 = new QLabel(centralwidget);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setMaximumSize(QSize(65, 20));
    label_2->setFont(font);
    label_2->setAlignment(Qt::AlignRight | Qt::AlignTrailing |
                          Qt::AlignVCenter);

    horizontalLayout_6->addWidget(label_2);

    scale = new QDoubleSpinBox(centralwidget);
    scale->setObjectName(QString::fromUtf8("scale"));
    scale->setMinimumSize(QSize(50, 10));
    scale->setMaximumSize(QSize(60, 20));
    scale->setDecimals(2);
    scale->setMaximum(100.000000000000000);
    scale->setSingleStep(1.000000000000000);
    scale->setStepType(QAbstractSpinBox::DefaultStepType);
    scale->setValue(1.000000000000000);

    horizontalLayout_6->addWidget(scale);

    label_4 = new QLabel(centralwidget);
    label_4->setObjectName(QString::fromUtf8("label_4"));
    label_4->setMaximumSize(QSize(200, 20));

    horizontalLayout_6->addWidget(label_4);

    verticalLayout->addLayout(horizontalLayout_6);

    label_6 = new QLabel(centralwidget);
    label_6->setObjectName(QString::fromUtf8("label_6"));

    verticalLayout->addWidget(label_6);

    horizontalLayout_7 = new QHBoxLayout();
    horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
    horizontalLayout_7->setSizeConstraint(QLayout::SetNoConstraint);
    label_23 = new QLabel(centralwidget);
    label_23->setObjectName(QString::fromUtf8("label_23"));
    label_23->setMaximumSize(QSize(122, 20));
    label_23->setFont(font);
    label_23->setAlignment(Qt::AlignRight | Qt::AlignTrailing |
                           Qt::AlignVCenter);

    horizontalLayout_7->addWidget(label_23);

    projection_type = new QComboBox(centralwidget);
    projection_type->addItem(QString());
    projection_type->addItem(QString());
    projection_type->setObjectName(QString::fromUtf8("projection_type"));
    projection_type->setMaximumSize(QSize(100, 20));

    horizontalLayout_7->addWidget(projection_type);

    label_5 = new QLabel(centralwidget);
    label_5->setObjectName(QString::fromUtf8("label_5"));
    label_5->setMaximumSize(QSize(100, 20));

    horizontalLayout_7->addWidget(label_5);

    verticalLayout->addLayout(horizontalLayout_7);

    label_9 = new QLabel(centralwidget);
    label_9->setObjectName(QString::fromUtf8("label_9"));
    label_9->setMaximumSize(QSize(16777215, 10));

    verticalLayout->addWidget(label_9);

    label_19 = new QLabel(centralwidget);
    label_19->setObjectName(QString::fromUtf8("label_19"));
    label_19->setMaximumSize(QSize(350, 20));
    label_19->setFont(font);
    label_19->setAlignment(Qt::AlignCenter);

    verticalLayout->addWidget(label_19);

    horizontalLayout_12 = new QHBoxLayout();
    horizontalLayout_12->setObjectName(
        QString::fromUtf8("horizontalLayout_12"));
    label_18 = new QLabel(centralwidget);
    label_18->setObjectName(QString::fromUtf8("label_18"));
    label_18->setMaximumSize(QSize(40, 20));
    label_18->setAlignment(Qt::AlignRight | Qt::AlignTrailing |
                           Qt::AlignVCenter);

    horizontalLayout_12->addWidget(label_18);

    line_type = new QComboBox(centralwidget);
    line_type->addItem(QString());
    line_type->addItem(QString());
    line_type->setObjectName(QString::fromUtf8("line_type"));
    line_type->setMaximumSize(QSize(100, 20));

    horizontalLayout_12->addWidget(line_type);

    label_17 = new QLabel(centralwidget);
    label_17->setObjectName(QString::fromUtf8("label_17"));
    label_17->setMaximumSize(QSize(70, 20));
    label_17->setAlignment(Qt::AlignRight | Qt::AlignTrailing |
                           Qt::AlignVCenter);

    horizontalLayout_12->addWidget(label_17);

    line_thickness = new QDoubleSpinBox(centralwidget);
    line_thickness->setObjectName(QString::fromUtf8("line_thickness"));
    line_thickness->setMaximumSize(QSize(60, 20));
    line_thickness->setMaximum(30.000000000000000);
    line_thickness->setValue(1.000000000000000);

    horizontalLayout_12->addWidget(line_thickness);

    verticalLayout->addLayout(horizontalLayout_12);

    label_24 = new QLabel(centralwidget);
    label_24->setObjectName(QString::fromUtf8("label_24"));
    label_24->setMaximumSize(QSize(350, 20));
    label_24->setFont(font);
    label_24->setAlignment(Qt::AlignCenter);

    verticalLayout->addWidget(label_24);

    horizontalLayout_13 = new QHBoxLayout();
    horizontalLayout_13->setObjectName(
        QString::fromUtf8("horizontalLayout_13"));
    label_25 = new QLabel(centralwidget);
    label_25->setObjectName(QString::fromUtf8("label_25"));
    label_25->setMaximumSize(QSize(40, 20));
    label_25->setAlignment(Qt::AlignRight | Qt::AlignTrailing |
                           Qt::AlignVCenter);

    horizontalLayout_13->addWidget(label_25);

    vertex_type = new QComboBox(centralwidget);
    vertex_type->addItem(QString());
    vertex_type->addItem(QString());
    vertex_type->addItem(QString());
    vertex_type->setObjectName(QString::fromUtf8("vertex_type"));
    vertex_type->setMaximumSize(QSize(100, 20));

    horizontalLayout_13->addWidget(vertex_type);

    label_26 = new QLabel(centralwidget);
    label_26->setObjectName(QString::fromUtf8("label_26"));
    label_26->setMaximumSize(QSize(40, 20));
    label_26->setAlignment(Qt::AlignRight | Qt::AlignTrailing |
                           Qt::AlignVCenter);

    horizontalLayout_13->addWidget(label_26);

    vertex_size = new QDoubleSpinBox(centralwidget);
    vertex_size->setObjectName(QString::fromUtf8("vertex_size"));
    vertex_size->setMaximumSize(QSize(50, 20));
    vertex_size->setMaximum(30.000000000000000);
    vertex_size->setValue(1.000000000000000);

    horizontalLayout_13->addWidget(vertex_size);

    verticalLayout->addLayout(horizontalLayout_13);

    label_8 = new QLabel(centralwidget);
    label_8->setObjectName(QString::fromUtf8("label_8"));
    label_8->setMaximumSize(QSize(16777215, 10));

    verticalLayout->addWidget(label_8);

    label_31 = new QLabel(centralwidget);
    label_31->setObjectName(QString::fromUtf8("label_31"));
    QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(label_31->sizePolicy().hasHeightForWidth());
    label_31->setSizePolicy(sizePolicy1);
    label_31->setMaximumSize(QSize(350, 20));
    label_31->setFont(font);

    verticalLayout->addWidget(label_31);

    horizontalLayout_15 = new QHBoxLayout();
    horizontalLayout_15->setObjectName(
        QString::fromUtf8("horizontalLayout_15"));
    color_back = new QPushButton(centralwidget);
    color_back->setObjectName(QString::fromUtf8("color_back"));

    horizontalLayout_15->addWidget(color_back);

    color_line = new QPushButton(centralwidget);
    color_line->setObjectName(QString::fromUtf8("color_line"));

    horizontalLayout_15->addWidget(color_line);

    color_vertex = new QPushButton(centralwidget);
    color_vertex->setObjectName(QString::fromUtf8("color_vertex"));

    horizontalLayout_15->addWidget(color_vertex);

    verticalLayout->addLayout(horizontalLayout_15);

    default_2 = new QCheckBox(centralwidget);
    default_2->setObjectName(QString::fromUtf8("default_2"));
    default_2->setMaximumSize(QSize(200, 20));

    verticalLayout->addWidget(default_2);

    verticalSpacer =
        new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    verticalLayout->addItem(verticalSpacer);

    horizontalLayout_8 = new QHBoxLayout();
    horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
    save_image = new QPushButton(centralwidget);
    save_image->setObjectName(QString::fromUtf8("save_image"));

    horizontalLayout_8->addWidget(save_image);

    screencast = new QPushButton(centralwidget);
    screencast->setObjectName(QString::fromUtf8("screencast"));

    horizontalLayout_8->addWidget(screencast);

    verticalLayout->addLayout(horizontalLayout_8);

    open_file = new QPushButton(centralwidget);
    open_file->setObjectName(QString::fromUtf8("open_file"));
    sizePolicy.setHeightForWidth(open_file->sizePolicy().hasHeightForWidth());
    open_file->setSizePolicy(sizePolicy);
    open_file->setMaximumSize(QSize(350, 16777215));

    verticalLayout->addWidget(open_file);

    horizontalLayout->addLayout(verticalLayout);

    GLwidget = new s21::GLWidget(centralwidget);
    GLwidget->setObjectName(QString::fromUtf8("GLwidget"));
    QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy2.setHorizontalStretch(0);
    sizePolicy2.setVerticalStretch(0);
    sizePolicy2.setHeightForWidth(GLwidget->sizePolicy().hasHeightForWidth());
    GLwidget->setSizePolicy(sizePolicy2);
    GLwidget->setMinimumSize(QSize(540, 540));
    GLwidget->setMaximumSize(QSize(700, 600));

    horizontalLayout->addWidget(GLwidget);

    MainWindow->setCentralWidget(centralwidget);
    statusbar = new QStatusBar(MainWindow);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    MainWindow->setStatusBar(statusbar);

    retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(MainWindow);
  }  // setupUi

  void retranslateUi(QMainWindow *MainWindow) {
    MainWindow->setWindowTitle(
        QCoreApplication::translate("MainWindow", "3DViewer v1.0", nullptr));
    file_name->setText(QString());
    vertexes_edges->setText(QString());
    label->setText(
        QCoreApplication::translate("MainWindow", "Position", nullptr));
    label_14->setText(QCoreApplication::translate("MainWindow", "X:", nullptr));
    label_13->setText(QCoreApplication::translate("MainWindow", "Y:", nullptr));
    label_12->setText(QCoreApplication::translate("MainWindow", "Z:", nullptr));
    label_7->setText(
        QCoreApplication::translate("MainWindow", "Rotation", nullptr));
    label_16->setText(
        QCoreApplication::translate("MainWindow", "OX:", nullptr));
    label_15->setText(
        QCoreApplication::translate("MainWindow", "OY:", nullptr));
    label_3->setText(QCoreApplication::translate("MainWindow", "OZ:", nullptr));
    label_2->setText(
        QCoreApplication::translate("MainWindow", "Scale", nullptr));
    label_4->setText(QString());
    label_6->setText(QString());
    label_23->setText(
        QCoreApplication::translate("MainWindow", "Projection type", nullptr));
    projection_type->setItemText(
        0, QCoreApplication::translate("MainWindow", "parallel", nullptr));
    projection_type->setItemText(
        1, QCoreApplication::translate("MainWindow", "central", nullptr));

    label_5->setText(QString());
    label_9->setText(QString());
    label_19->setText(QCoreApplication::translate(
        "MainWindow",
        "-----------------------------------------------LINE "
        "SETTINGS:-----------------------------------------------",
        nullptr));
    label_18->setText(
        QCoreApplication::translate("MainWindow", "type:", nullptr));
    line_type->setItemText(
        0, QCoreApplication::translate("MainWindow", "solid", nullptr));
    line_type->setItemText(
        1, QCoreApplication::translate("MainWindow", "dashed", nullptr));

    label_17->setText(
        QCoreApplication::translate("MainWindow", "thickness:", nullptr));
    label_24->setText(QCoreApplication::translate(
        "MainWindow",
        "---------------------------------------------VERTEX "
        "SETTINGS:---------------------------------------------",
        nullptr));
    label_25->setText(
        QCoreApplication::translate("MainWindow", "type:", nullptr));
    vertex_type->setItemText(
        0, QCoreApplication::translate("MainWindow", "none", nullptr));
    vertex_type->setItemText(
        1, QCoreApplication::translate("MainWindow", "circle", nullptr));
    vertex_type->setItemText(
        2, QCoreApplication::translate("MainWindow", "square", nullptr));

    label_26->setText(
        QCoreApplication::translate("MainWindow", "size:", nullptr));
    label_8->setText(QString());
    label_31->setText(QCoreApplication::translate(
        "MainWindow",
        "-------------------------COLORS:-------------------------", nullptr));
    color_back->setText(
        QCoreApplication::translate("MainWindow", "Background", nullptr));
    color_line->setText(
        QCoreApplication::translate("MainWindow", "Line", nullptr));
    color_vertex->setText(
        QCoreApplication::translate("MainWindow", "Vertex", nullptr));
    default_2->setText(
        QCoreApplication::translate("MainWindow", "default settings", nullptr));
    save_image->setText(
        QCoreApplication::translate("MainWindow", "SAVE IMAGE", nullptr));
    screencast->setText(
        QCoreApplication::translate("MainWindow", "SCREENCAST", nullptr));
    open_file->setText(
        QCoreApplication::translate("MainWindow", "OPEN .obj file", nullptr));
  }  // retranslateUi
};

namespace Ui {
class MainWindow : public Ui_MainWindow {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_MAINWINDOW_H
