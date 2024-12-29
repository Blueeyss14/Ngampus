#include "tree.h"

adrNode newNode(infotype data)
{
    adrNode p = new elmNode;
    Info(p) = data;
    Right(p) = NULL;
    Left(p) = NULL;
    return p;
}

void insertNode(adrNode &root, adrNode p)
{
    if (root == NULL)
    {
        root = p;
    }
    else if (Info(p) < Info(root))
    {
        insertNode(Left(root), p);
    }
    else if (Info(p) > Info(root))
    {
        insertNode(Right(root), p);
    }
}

void printInOrder(adrNode root)
{
    if (root != NULL)
    {
        printInOrder(Left(root));
        cout << Info(root) << " ";
        printInOrder(Right(root));
    }
}

adrNode palingKiri(adrNode root)
{
    if (root != NULL)
    {
        if (Left(root) == NULL)
        {
            return root;
        }
        return palingKiri(Left(root));
    }
    return NULL;
}

adrNode palingKanan(adrNode root)
{
    if (root != NULL)
    {
        if (Right(root) == NULL)
        {
            return root;
        }
        return palingKanan(Right(root));
    }
    return NULL;
}

adrNode findNode(adrNode root)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (Left(root) == NULL && Right(root) == NULL)
    {
        return root;
    }

    adrNode leftResult = findNode(Left(root));
    adrNode rightResult = findNode(Right(root));
    if (leftResult != NULL)
    {
        return leftResult;
    }
    return rightResult;
}

void deleteNode(adrNode &root, adrNode p) {
    if (root != NULL) {
        if (Info(p) < Info(root)) {
            deleteNode(Left(root), p);
        } else if (Info(p) > Info(root)) {
            deleteNode(Right(root), p);
        } else {
            if (Left(root) == NULL && Right(root) == NULL) {
                root = NULL;
            } else if (Left(root) == NULL) {
                root = Right(root);
            } else if (Right(root) == NULL) {
                root = Left(root);
            } else {
                adrNode temp = findNode(root);
                Info(root) = Info(temp);
                deleteNode(root, p);
            }
        }
    } else {
        cout << "Kosong" << endl;
    }
}