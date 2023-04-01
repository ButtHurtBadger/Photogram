# Photogram
A way to organize albums of photos.

to execute:
make a4
./a4

Date.cc Date.h: stores information on dates
Array.h: abstract container for data, in our case, photos and albums
Photo.cc, Photo.h: Stores information on photos
Album.cc, Album.h: Stores information on albums
Criteria.h Criteria.cc: match searches with photos, using categores, dates or both
MediaFactory.cc MediaFactory.h: makes photos, albums, and criteria objects
PhotoGram.cc PhotoGram.h: This class contains the master list of Photos and a collection of Albums. Users can add Photos to the 
	master list, and add or remove Albums. In addition we can search for Photos and these Photos can be added to an Album 
	(we will not worry about removing Photos from an Album in this assignment). In addition, in conjunction with the AlbumCreator 
	and View objects, users can browse Albums and Photos.  
AlbumCreator.cc AlbumCreator.h: Controls the interaction of PhotoGram with the View. Maintains its own list of Photos found during the latest search.
View.cc View.h: Prints menus, Albums, or Photos, and takes input
defs.h: defines max array:
main.cc: creates an albumcreator object. 
