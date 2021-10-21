#pragma once

#include <tuple>
#include <QTimeLine>
#include <QtWidgets/QGraphicsPixmapItem>
#include <QtWidgets/QGraphicsItemAnimation>

class Item : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
        class EventListener;

public:
    explicit Item(EventListener* board, const std::string& path, int row, int column, QGraphicsItem* parent);
    void moveTo(Item& other, bool canRevert);
    void moveTo(int x, int y);
    std::string path() const;
    int row() const;
    int column() const;

    void setRow(int row);
    void setColumn(int column);

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;

private:
    auto moveToInternal(int x, int y)->std::tuple<QTimeLine*, QGraphicsItemAnimation*>;

private:
    EventListener* _listener;
    std::string _path;
    int _row;
    int _column;
    QPointF _pressPos;

public:
    enum class Direction
    {
        Left, Right, Up, Down
    };

    struct Event
    {
        Item* item;
        Direction dir;
    };

    struct EventListener
    {
        virtual void itemDragEvent(const Event* event) = 0;
        virtual void itemMoveFinished(Item* item0, Item* item1, bool canRevert) = 0;
    };
};

