#include "leafNode.h"

LeafNode::LeafNode(int _value) : value(_value) {}

double LeafNode::result()
{
  return (double)value;
}

QString LeafNode::print()
{
  return QString::number(value);
}
