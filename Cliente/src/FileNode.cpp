//
// Created by julian_camacho on 13/8/20.
//

#include "FileNode.h"

FileNode::FileNode(string pName){
    name = pName;
    toCommit = false;
}
const string& FileNode::getName() const {
    return name;
}

void FileNode::setName(const string &name) {
    FileNode::name = name;
}

bool FileNode::isToCommit() const {
    return toCommit;
}

void FileNode::setToCommit(bool toCommit) {
    FileNode::toCommit = toCommit;
}

