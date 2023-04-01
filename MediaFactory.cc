#include "MediaFactory.h"
#include <fstream>
#include <sstream>
#include <limits>

// Converts a string in the format "YYYY MM DD" to a Date object.
Date MediaFactory::toDate(const string& d){
    stringstream ss(d);
    int year, month, day;
    ss >> year >> month >> day;
    return Date(year, month, day);
}

// Searches for a photo with the given title in the file "media/photos.txt".
// If found, returns a Photo object with the photo's details.
// Otherwise, returns nullptr.
Photo* MediaFactory::uploadPhoto(const string& title){
    ifstream mediaFile("media/photos.txt");
    string temp, photoTitle, date, description, category;
    stringstream content;

    cout << "Searching for photo title: " << title << endl;

    while (getline(mediaFile, photoTitle)) {
        if (title == photoTitle) {
            getline(mediaFile, category);
            getline(mediaFile, date);
            getline(mediaFile, temp);

            while (temp != "!!endrecord!!") {
                content << temp << endl;
                getline(mediaFile, temp);
            }

            mediaFile.close();
            return new Photo(photoTitle, category, toDate(date), content.str());
        }

        // Advance to next photo
        while (temp != "!!endrecord!!") {
            getline(mediaFile, temp);
        }
    }

    mediaFile.close();
    return nullptr;
}

// Creates an Album object with the given title and description.
Album* MediaFactory::createAlbum(const string& title, const string& description){
    return new Album(title, description);
}

// Creates a Criteria object based on date range.
Criteria* MediaFactory::dateCriteria(const Date& start, const Date& end){
    return new Date_Criteria(start, end);
}

// Creates a Criteria object based on category.
Criteria* MediaFactory::categoryCriteria(const string& category){
    return new Cat_Criteria(category);
}

// Creates a Criteria object based on date range and category.
Criteria* MediaFactory::dateAndCatCriteria(const Date& start, const Date& end, const string& category){
    return new CandD_Criteria(start, end, category);
}
