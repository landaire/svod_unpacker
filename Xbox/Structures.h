#ifndef STRUCTURES_H
#define STRUCTURES_H
#include "typedefs.h"
#include <string>
#include <vector>
struct Dirent
{
    DWORD Offset;
    DWORD Length;
    BYTE Flag;
    BYTE FileNameLength;
    std::string FileName;
};

struct Folder
{
    Dirent Entry;
    bool DirentsRead;
    std::string FullPath;
    std::vector <Dirent> Files;
    std::vector <Folder*> Folders;
};

struct Attributes
{
    static const int READONLY     = 0x00000001;
    static const int HIDDEN       = 0x00000002;
    static const int SYSTEM       = 0x00000004;
    static const int DIRECTORY    = 0x00000010;
    static const int ARCHIVE      = 0x00000020;
    static const int DEVICE       = 0x00000040;
    static const int NORMAL       = 0x00000080;
    static const int TEMPORARY    = 0x00000100;
};

#endif // STRUCTURES_H
