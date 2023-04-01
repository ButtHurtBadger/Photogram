#include "Album.h"

Album::Album(const std::string& title, const std::string& description)
    : m_title(title), m_description(description)
{
}

bool Album::equals(const std::string& title) const
{
    return m_title == title;
}

void Album::addPhoto(Photo* photo)
{
    m_photos.add(photo);
}

Photo* Album::getPhoto(int index) const
{
    return m_photos[index];
}

int Album::size() const
{
    return m_photos.size();
}

void Album::print(std::ostream& os) const
{
    os << m_title << "\n" << m_description << "\nNumber of photos: " << m_photos.size() << std::endl;
}

void Album::display(std::ostream& os) const
{
    print(os);
    for (int i = 0; i < m_photos.size(); i++)
    {
        os << "Photo " << i << ":\n";
        m_photos[i]->display(os);
    }
}

std::ostream& operator<<(std::ostream& os, const Album& album)
{
    album.print(os);
    return os;
}
