#pragma once

#include <QtWidgets/QGraphicsTextItem>

class QGraphicsScene;
class Values;
class Score : public QGraphicsSimpleTextItem
{
private:
    QGraphicsScene* _scene;
    Values* _values;

public:
    Score(QGraphicsScene* scene, Values* values);
};

