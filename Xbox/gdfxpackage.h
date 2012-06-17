#ifndef SVODPACKAGE_H
#define SVODPACKAGE_H

#include <string>
#include <vector>
#include "IO/xMultiFileStream.h"
#include "Structures.h"
#include "stfspackage.h"
class GdfxPackage
{
#define BLOCK_SIZE          0x800
// The amount of data between hash tables
#define DATA_BETWEEN_TABLES 0xCC000
// Hash table size
#define HASH_TABLE_SIZE     0x1000
// Maximum size for a Dataxxxx file
#define FILE_MAX_SIZE       0xA290000
public:
    GdfxPackage(std::vector<std::string> FilePath, StfsPackage *package);
    GdfxPackage(Streams::IStream* FileStream, StfsPackage *package);
    void Close( void );

    UINT64 BaseOffset;
    DWORD DataBlockCount; // really an int24
    DWORD DataBlockOffset; // really an int24

    std::string Magic( void );
    DWORD RootBlock( void );
    DWORD RootSize( void );
    std::vector<Dirent> LoadDirents(DWORD Block, DWORD Size);
    Folder* RootDirectory;
    void LoadFolderDirents(Folder* f, bool Recursive=true);

private:
    Streams::IStream* fileStream;
    UINT64 SeekToBlock(UINT32 Block);
    void Initialize( void );
    void CloseFolder( Folder *f );
    StfsPackage *package;
};

#endif // SVODPACKAGE_H
