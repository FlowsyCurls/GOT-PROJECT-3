//
// Created by julian_camacho on 13/8/20.
//

#ifndef GOT_FILENODE_H
#define GOT_FILENODE_H
#include <iostream>
using namespace std;

class FileNode {
    string name;
    bool toCommit;
    string huffmanCode;

public:
    FileNode();

    FileNode(string pName);

    const string &getName() const;

    void setName(const string &name);

    bool isToCommit() const;

    void setToCommit(bool toCommit);

    const string &getHuffmanCode() const;

    void setHuffmanCode(const string &huffmanCode);
};


#endif //GOT_FILENODE_H
