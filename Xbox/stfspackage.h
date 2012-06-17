#ifndef STFSPACKAGE_H
#define STFSPACKAGE_H
#include "typedefs.h"
#include "IO/IStream.h"
#include <QString>
#include <../QtGui/QImage>

#define STFS_PACKAGE_LIVE               0x4C495645
#define STFS_PACKAGE_PIRS               0x50495253
#define STFS_PACKAGE_CON                0x434F4E20

#define STFS_CONTENT_TYPE_ARCADE_TITLE      0xD0000
#define STFS_CONTENT_TYPE_AVATAR_ITEM       0x9000
#define STFS_CONTENT_TYPE_CACHE_FILE        0x40000
#define STFS_CONTENT_TYPE_COMMUNITY_GAME    0x2000000
#define STFS_CONTENT_TYPE_GAME_DEMO         0x80000
#define STFS_CONTENT_TYPE_GAMER_PICTURE     0x20000
#define STFS_CONTENT_TYPE_GAME_TITLE        0xA0000
#define STFS_CONTENT_TYPE_GAME_TRAILER      0xC0000
#define STFS_CONTENT_TYPE_GAME_VIDEO        0x400000
#define STFS_CONTENT_TYPE_INSTALLED_GAME    0x4000
#define STFS_CONTENT_TYPE_INSTALLER         0xB0000
#define STFS_CONTENT_TYPE_IPTV_PAUSE_BUFFER 0x2000
#define STFS_CONTENT_TYPE_LICENSE_STORE     0xF0000
#define STFS_CONTENT_TYPE_MARKETPLACE_CONTENT 0x2
#define STFS_CONTENT_TYPE_MOVIE             0x100000
#define STFS_CONTENT_TYPE_MUSIC_VIDEO       0x300000
#define STFS_CONTENT_TYPE_PODCAST_VIDEO     0x500000
#define STFS_CONTENT_TYPE_PROFILE           0x10000
#define STFS_CONTENT_TYPE_PUBLISHER         0x3
#define STFS_CONTENT_TYPE_SAVED_GAME        0x1
#define STFS_CONTENT_TYPE_STORAGE_DOWNLOAD  0x50000
#define STFS_CONTENT_TYPE_THEME             0x30000
#define STFS_CONTENT_TYPE_TV                0x200000
#define STFS_CONTENT_TYPE_VIDEO             0x90000
#define STFS_CONTENT_TYPE_VIRAL_VIDEO       0x600000
#define STFS_CONTENT_TYPE_XBOX_DOWNLOAD     0x70000
#define STFS_CONTENT_TYPE_XBOX_ORIGINAL_GAME 0x5000
#define STFS_CONTENT_TYPE_XBOX_SAVED_GAME   0x60000
#define STFS_CONTENT_TYPE_XBOX_360_TITLE    0x1000
#define STFS_CONTENT_TYPE_XNA               0xE0000

class StfsPackage
{
private:
    Streams::IStream *Stream;
public:
    StfsPackage( Streams::IStream *Stream );
    ~StfsPackage( void );
    bool IsStfsPackage( void );
    DWORD Magic( void );
    DWORD ContentType( void );
    DWORD TitleId( void );
    UINT64 ConsoleId( void );
    UINT64 ProfileId( void );
    QString DisplayName( int Locale = 0 );
    QString Description( int Locale = 0 );
    QString TitleName( int Locale = 0 );
    QImage ThumbnailImage( void );
    QImage TitleImage( void );

    QString ContentType_s( void );

    // SVOD stuff
    DWORD DataBlockCount( void ); // really an int24
    DWORD DataBlockOffset( void ); // really an int24
};

#endif // STFSPACKAGE_H
