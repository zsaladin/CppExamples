#include <QtWidgets/QDesktopWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsView>
#include "Board.h"
#include "Score.h"
#include "Values.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene scene;
    scene.setSceneRect(QApplication::desktop()->geometry()); // 좌측 상단을 0, 0으로 지정

    Values values;
    values.score.set(0);

    Board board(&scene, &values);
    Score score(&scene, &values);

    QGraphicsView view(&scene);
    view.showFullScreen();

    return a.exec();
}
