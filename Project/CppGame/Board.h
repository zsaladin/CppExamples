#pragma once

#include <string>
#include <vector>
#include <set>
#include <random>
#include <QtWidgets/QGraphicsRectItem>
#include <QtWidgets/QGraphicsScene>

#include "Item.h"

class Values;
class Board : public Item::EventListener
{
private:
    QGraphicsScene* _scene;
    Values* _values;

    QGraphicsRectItem _root;
    std::vector<std::vector<Item*>> _items;
    int _animatingCount;
    std::random_device _rd;
    std::mt19937 _gen;

public:
    explicit Board(QGraphicsScene* scene, Values* values);
    ~Board();
    virtual void itemDragEvent(const Item::Event* event) override;
    virtual void itemMoveFinished(Item* item0, Item* item1, bool canRevert) override;

private:
    bool refresh();
    bool refresh(const std::set<std::pair<int, int>>& matched);
    void addItem(int row, int column);
    void removeItem(int row, int column);
    void moveItem(int row, int column, int toRow, int toColumn);
    void exchangeItems(int row0, int column0, int row1, int column1, bool canRevert);
    std::set<std::pair<int, int>> matchedItems() const;
    std::set<std::pair<int, int>> matchedItems(int row, int column) const;
    std::set<std::pair<int, int>> matchedItemsHorizontal(int row, int column) const;
    std::set<std::pair<int, int>> matchedItemsVertical(int row, int column) const;

};

