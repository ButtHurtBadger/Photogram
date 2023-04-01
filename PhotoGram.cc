#include "PhotoGram.h"

PhotoGram::PhotoGram() {}
PhotoGram::~PhotoGram() {
    for (int i = 0; i < albums.size(); i++) {
        delete albums[i];
    }
    for (int i = 0; i < photos.size(); i++) {
        delete photos[i];
    }
}

bool PhotoGram::addAlbum(const string& title, const string& description) {
    Album* album = mediaFactory.createAlbum(title, description);
    if (album) {
        albums.add(album);
        return true;
    }
    return false;
}

bool PhotoGram::addToAlbum(int index, Array<Photo*>& photos) {
    if (index >= 0 && index < albums.size()) {
        Album* album = albums[index];
        for (int i = 0; i < photos.size(); i++) {
            album->addPhoto(photos[i]);
        }
        return true;
    }
    return false;
}

bool PhotoGram::uploadPhoto(const string& title) {
    Photo* photo = mediaFactory.uploadPhoto(title);
    if (photo) {
        photos.add(photo);
        return true;
    }
    return false;
}

bool PhotoGram::deleteAlbum(int index) {
    if (index >= 0 && index < albums.size()) {
        Album* album = albums[index];
        albums.remove(album);
        delete album;
        return true;
    }
    return false;
}

void PhotoGram::getPhotos(const Criteria& criteria, Array<Photo*>& result) {
    for (int i = 0; i < photos.size(); i++) {
        if (criteria.matches(*photos[i])) {
            result.add(photos[i]);
        }
    }
}

void PhotoGram::displayAlbum(int index, View& view) {
    if (index >= 0 && index < albums.size()) {
        view.displayAlbum(*albums[index]);
    }
}

int PhotoGram::printAlbums(View& view) {
    view.printAlbums(albums);
    return albums.size();
}

void PhotoGram::displayPhoto(int index, View& view) {
    if (index >= 0 && index < photos.size()) {
        view.displayPhoto(*photos[index]);
    }
}

int PhotoGram::printPhotos(View& view) {
    view.printPhotos(photos);
    return photos.size();
}
