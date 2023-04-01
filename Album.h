#ifndef ALBUM_H
#define ALBUM_H

#include "Array.h"
#include "Photo.h"
#include <string>
#include <iostream>

class Album {
public:
    Album(const std::string& title, const std::string& description);
		
    bool equals(const std::string& title) const;
    void addPhoto(Photo* photo);
    Photo* getPhoto(int index) const;
    int size() const;
    void print(std::ostream& os) const;
    void display(std::ostream& os) const;

private:
    std::string m_title;
    std::string m_description;
    Array<Photo*> m_photos;
};

std::ostream& operator<<(std::ostream& os, const Album& album);

#endif // ALBUM_H
