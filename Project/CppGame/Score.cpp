#include "Score.h"
#include "Consts.h"
#include "Values.h"

#include <QtWidgets/QGraphicsScene>


void scoreChanged(Score* score, int value)
{
    score->setText(("Score : " + std::to_string(value)).c_str());
}

Score::Score(QGraphicsScene* scene, Values* values)
    : _scene(scene)
    , _values(values)
{
    _scene->addItem(this);
    setX(_scene->sceneRect().width() / 2 - Consts::BOARD_ITEM_SIZE * Consts::BOARD_SIZE / 2);
    setY(_scene->sceneRect().height() / 2 + Consts::BOARD_ITEM_SIZE * Consts::BOARD_SIZE / 2);

    _values->score.observe([this](int value) {
        scoreChanged(this, value);
        });

    std::string msg = "Score : " + std::to_string(values->score.get());
    setText(msg.c_str());
    setScale(2.5);
}



