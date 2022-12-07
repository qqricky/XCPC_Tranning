#include <bits/stdc++.h>
using namespace std;
struct BiTree
{
    BiTree *lchild, rchild;
};

int Height(BiTree bt)∥求二叉树bt的深度
{
    int hl，hr;
    if (bt == NULL)
        return (0); else
        {
            hi = Height(bt ->lchild) ：
                hr = Height(bt - ＞rchild) ; if (hl＞hr) return (hl + 1) ： else return (hr + 1) ;
        }
}
void Balance(BiTree bt)∥计算二叉树bt各结点的平衡因子
{
    if (bt)
    {
        Balance(bt - ＞lchild) ;∥后序遍历左子树
            Balance(bt - ＞rchild) ;∥后序遍历右子树
                hl = Height(bt - ＞lchild) ：
                    hr = Height(bt - ＞rchild) ;∥求左右子树的高度
                             bt -
                         ＞bf = hl - hr;∥结点的平衡因子bf
    }
}
int Height(BiTree bt)∥求二叉树bt的深度
{
    int hl，hr; if (bt == null) return (0); else
    {
        hi = Height(bt - ＞lchild) ：
            hr = Height(bt - ＞rchild) ; if (hl＞hr) return (hl + 1) ： else return (hr + 1) ;
    }
}
void Balance(BiTree bt)∥计算二叉树bt各结点的平衡因子
{
    if (bt)
    {
        Balance(bt - ＞lchild) ;∥后序遍历左子树
            Balance(bt - ＞rchild) ;∥后序遍历右子树
                hl = Height(bt - ＞lchild) ：
                    hr = Height(bt - ＞rchild) ;∥求左右子树的高度
                             bt -
                         ＞bf = hl - hr;∥结点的平衡因子bf
    }
}