#ifndef PHOTOGRAM_H
#define PHOTOGRAM_H

#include "Array.h"
#include "MediaFactory.h"
#include "Criteria.h"
#include "View.h"

class PhotoGram {
public:
    PhotoGram();
    ~PhotoGram();

    bool addAlbum(const string& title, const string& description);
    bool addToAlbum(int index, Array<Photo*>& photos);
    bool uploadPhoto(const string& title);
    bool deleteAlbum(int index);

    void getPhotos(const Criteria& criteria, Array<Photo*>& result);

    void displayAlbum(int index, View& view);
    int printAlbums(View& view);
    void displayPhoto(int index, View& view);
    int printPhotos(View& view);

private:
    Array<Album*> albums;
    Array<Photo*> photos;
    MediaFactory mediaFactory;
};

#endif
