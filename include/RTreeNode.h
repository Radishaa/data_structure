#ifndef RTREENODE_H
#define RTREENODE_H
#include <vector>

class RTreeNode
{
public:
    int val;
    int height;
    bool isBlak;
    RTreeNode *parent;
    RTreeNode *left;
    RTreeNode *right;

    int getheight(RTreeNode *head);
    bool isBlak(RTreeNode *head);
    RTreeNode *insert(RTreeNode *head, int val);
    RTreeNode *remove(RTreeNode *head, int val);
    RTreeNode *serch(int val);

    RTreeNode(/* args */);
    ~RTreeNode();
};

#endif
