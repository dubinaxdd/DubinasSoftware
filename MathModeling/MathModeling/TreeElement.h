#ifndef TREEELEMENT_H
#define TREEELEMENT_H


class TreeElement
{
private:

    bool isX;

    int Coord;
    int Ind;

    int LeftChild;
    int RightChild;

    bool LeftEndTree;
    bool RightEndTree;

public:

    TreeElement();

    void setIsX(bool param){this->isX = param;}
    bool getIsX(){return this->isX;}

    void setLeftEndTree(bool param){this->LeftEndTree = param;}
    bool getLeftEndTree(){return this->LeftEndTree;}

    void setRightEndTree(bool param){this->RightEndTree = param;}
    bool getRightEndTree(){return this->RightEndTree;}

    void setCoord(int coord){this->Coord = coord;}
    int getCoord(){return this->Coord;}

    void setInd(int ind){this->Ind = ind;}
    int getInd(){return this->Ind;}

    void setLeftChild(int LeftChild){this->LeftChild = LeftChild;}
    int getLeftChild(){return this->LeftChild;}

    void setRightChild(int RightChild){this->RightChild = RightChild;}
    int getRightChild(){return this->RightChild;}


};

#endif // TREEELEMENT_H
