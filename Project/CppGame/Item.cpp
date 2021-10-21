#include "Item.h"
#include "Consts.h"
#include "Board.h"

#include <QtWidgets/QGraphicsSceneEvent>

Item::Item(EventListener* listener, const std::string& path, int row, int column, QGraphicsItem* parent)
    : QGraphicsPixmapItem(QPixmap(path.c_str()).scaled(Consts::BOARD_ITEM_SIZE, Consts::BOARD_ITEM_SIZE), parent)
    , _listener(listener)
    , _path(path)
    , _row(row)
    , _column(column)
{
}


void Item::moveTo(Item& other, bool canRevert)
{
    auto tuple = moveToInternal(other.x(), other.y());
    auto timer = std::get<0>(tuple);
    auto animation = std::get<1>(tuple);

    connect(timer, &QTimeLine::finished, [this, timer, animation, canRevert, other = &other]() {
        delete timer;
        delete animation;
        _listener->itemMoveFinished(this, other, canRevert);
        });
}

void Item::moveTo(int toX, int toY)
{
    auto tuple = moveToInternal(toX, toY);
    auto timer = std::get<0>(tuple);
    auto animation = std::get<1>(tuple);

    connect(timer, &QTimeLine::finished, [this, timer, animation]() {
        delete timer;
        delete animation;
        _listener->itemMoveFinished(this, nullptr, false);
        });
}

auto Item::moveToInternal(int toX, int toY) -> std::tuple<QTimeLine*, QGraphicsItemAnimation*>
{
    double diffX = toX - x();
    double diffY = toY - y();

    double time = 0;
    time += qAbs(diffX) * 200 / 60;
    time += qAbs(diffY) * 200 / 60;

    // 애니메이션 설명 해야 함
    QTimeLine* timer = new QTimeLine(time);
    timer->setFrameRange(0, 100);

    QGraphicsItemAnimation* animation = new QGraphicsItemAnimation;
    animation->setItem(this);
    animation->setTimeLine(timer);

    for (int i = 0; i < 200; ++i)
    {
        double currX = x() + diffX * (i / 200.0);
        double currY = y() + diffY * (i / 200.0);
        animation->setPosAt(i / 200.0, QPointF(currX, currY));
    }
    timer->start();
    return { timer, animation };
}


std::string Item::path() const
{
    return _path;
}

int Item::row() const
{
    return _row;
}


int Item::column() const
{
    return _column;
}

void Item::setRow(int row)
{
    _row = row;
}

void Item::setColumn(int column)
{
    _column = column;
}

void Item::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    _pressPos = event->pos();
}


void Item::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
    Event newEvent;
    newEvent.item = this;

    QPointF diff = event->pos() - _pressPos;
    if (qAbs(diff.x()) > qAbs(diff.y()))
    {
        if (diff.x() > 0)
        {
            newEvent.dir = Direction::Right;
        }
        else
        {
            newEvent.dir = Direction::Left;
        }
    }
    else
    {
        if (diff.y() > 0)
        {
            newEvent.dir = Direction::Up;
        }
        else
        {
            newEvent.dir = Direction::Down;
        }
    }

    _listener->itemDragEvent(&newEvent);
}

