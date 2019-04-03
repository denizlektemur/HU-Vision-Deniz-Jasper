#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : RGBImage() {
	//int throwError = 0, e = 1 / throwError; //Throws error without the need to include a header
	//TODO: Nothing
	this->pixelStorage = nullptr;
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(), other.getHeight()) {
	//int throwError = 0, e = 1 / throwError;
	//TODO: Create a copy from the other object
	delete[] this->pixelStorage;
	this->pixelStorage = new RGB[other.getWidth() * other.getHeight()];
	this->pixelStorage = other.pixelStorage;
}


RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height) {
	//int throwError = 0, e = 1 / throwError;
	//TODO: Initialize pixel storage
	delete[] this->pixelStorage;
	this->pixelStorage = new RGB[width * height];
}

RGBImageStudent::~RGBImageStudent() {
	//int throwError = 0, e = 1 / throwError;
	//TODO: delete allocated objects
	delete[] this->pixelStorage;
	this->pixelStorage = nullptr;
}

void RGBImageStudent::set(const int width, const int height) {
	RGBImage::set(width, height);
	//int throwError = 0, e = 1 / throwError;
	//TODO: resize or create a new pixel storage (Don't forget to delete the old storage)
	delete[] this->pixelStorage;
	this->pixelStorage = new RGB[width * height];
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	RGBImage::set(other.getWidth(), other.getHeight());
	//int throwError = 0, e = 1 / throwError;
	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
	delete[] this->pixelStorage;
	this->pixelStorage = new RGB[other.getWidth() * other.getHeight()];
	this->pixelStorage = other.pixelStorage;
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	//int throwError = 0, e = 1 / throwError;
	//TODO: no comment needed :)
	*(this->pixelStorage + (y * RGBImage::getWidth() + x)) = pixel;
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	//int throwError = 0, e = 1 / throwError;
	/*
	* TODO: set pixel i in "Row-Major Order"
	*
	*
	* Original 2d image (values):
	* 9 1 2
	* 4 3 5
	* 8 7 8
	*
	* 1d representation (i, value):
	* i		value
	* 0		9
	* 1		1
	* 2		2
	* 3		4
	* 4		3
	* 5		5
	* 6		8
	* 7		7
	* 8		8
	*/
	*(this->pixelStorage + i) = pixel;
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	//int throwError = 0, e = 1 / throwError;
	//TODO: no comment needed :)
	return *(this->pixelStorage + (y * RGBImage::getWidth() + x));
}

RGB RGBImageStudent::getPixel(int i) const {
	//int throwError = 0, e = 1 / throwError;
	//TODO: see setPixel(int i, RGB pixel)
	return *(this->pixelStorage + i);
}