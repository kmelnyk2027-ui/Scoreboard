#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFont>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Scoreboard");
    window.setFixedSize(480, 350);

    int scoreA = 0;
    int scoreB = 0;

    QFont labelFont("Arial", 28, QFont::Bold);
    QFont buttonFont("Arial", 20, QFont::Bold);

    QLabel *labelA = new QLabel("Player A: 0");
    labelA->setFont(labelFont);
    labelA->setStyleSheet("color: white; background-color: #1E90FF; border-radius: 12px; padding: 12px;");
    labelA->setAlignment(Qt::AlignCenter);

    QLabel *labelB = new QLabel("Player B: 0");
    labelB->setFont(labelFont);
    labelB->setStyleSheet("color: black; background-color: #FFD700; border-radius: 12px; padding: 12px;");
    labelB->setAlignment(Qt::AlignCenter);

    QPushButton *plusA = new QPushButton("+");
    QPushButton *minusA = new QPushButton("-");
    QPushButton *plusB = new QPushButton("+");
    QPushButton *minusB = new QPushButton("-");
    QPushButton *reset = new QPushButton("Reset");

    plusA->setFont(buttonFont);
    minusA->setFont(buttonFont);
    plusB->setFont(buttonFont);
    minusB->setFont(buttonFont);
    reset->setFont(buttonFont);

    plusA->setFixedSize(70,70);
    minusA->setFixedSize(70,70);
    plusB->setFixedSize(70,70);
    minusB->setFixedSize(70,70);
    reset->setFixedSize(150,60);

    plusA->setStyleSheet("QPushButton {background: qlineargradient(x1:0,y1:0,x2:1,y2:1, stop:0 #00BFFF, stop:1 #1E90FF); color: white; border-radius: 12px;}"
                         "QPushButton:pressed {background-color: #009ACD;}");
    minusA->setStyleSheet("QPushButton {background: qlineargradient(x1:0,y1:0,x2:1,y2:1, stop:0 #00BFFF, stop:1 #1E90FF); color: white; border-radius: 12px;}"
                          "QPushButton:pressed {background-color: #009ACD;}");
    plusB->setStyleSheet("QPushButton {background: qlineargradient(x1:0,y1:0,x2:1,y2:1, stop:0 #FFD700, stop:1 #FFA500); color: black; border-radius: 12px;}"
                         "QPushButton:pressed {background-color: #FF8C00;}");
    minusB->setStyleSheet("QPushButton {background: qlineargradient(x1:0,y1:0,x2:1,y2:1, stop:0 #FFD700, stop:1 #FFA500); color: black; border-radius: 12px;}"
                          "QPushButton:pressed {background-color: #FF8C00;}");
    reset->setStyleSheet("QPushButton {background-color: #5555FF; color: white; border-radius: 15px;}"
                         "QPushButton:pressed {background-color: #3333AA;}");

    auto updateUi = [&]() {
        labelA->setText("Player A: " + QString::number(scoreA));
        labelB->setText("Player B: " + QString::number(scoreB));
    };

    QObject::connect(plusA, &QPushButton::clicked, [&]() { scoreA++; updateUi(); });
    QObject::connect(minusA, &QPushButton::clicked, [&]() { scoreA--; updateUi(); });
    QObject::connect(plusB, &QPushButton::clicked, [&]() { scoreB++; updateUi(); });
    QObject::connect(minusB, &QPushButton::clicked, [&]() { scoreB--; updateUi(); });
    QObject::connect(reset, &QPushButton::clicked, [&]() { scoreA = 0; scoreB = 0; updateUi(); });

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setSpacing(20);
    mainLayout->setContentsMargins(30,30,30,30);

    QHBoxLayout *rowA = new QHBoxLayout;
    rowA->addWidget(labelA);
    rowA->addWidget(plusA);
    rowA->addWidget(minusA);

    QHBoxLayout *rowB = new QHBoxLayout;
    rowB->addWidget(labelB);
    rowB->addWidget(plusB);
    rowB->addWidget(minusB);

    mainLayout->addLayout(rowA);
    mainLayout->addLayout(rowB);
    mainLayout->addWidget(reset, 0, Qt::AlignCenter);

    window.setLayout(mainLayout);
    window.show();

    return app.exec();
}
