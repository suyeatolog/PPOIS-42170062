//
// Created by user on 16.10.2025.
//

#include "Painting.h"

std::string Painting::GetArtist() const {
    return artist_;
}
std::string Painting::GetStyle() const {
    return style_;
}
std::string Painting::GetMaterial() const {
    return material_;
}
int Painting::GetLength() const {
    return length_;
}
int Painting::GetWidth() const {
    return width_;
}

void Painting::SetArtist(std::string artist) {
    this->artist_ = artist;
}
void Painting::SetStyle(std::string style) {
    this->style_ = style;
}
void Painting::SetMaterial(std::string material) {
    this->material_ = material;
}
void Painting::SetLength(int length) {
    this->length_ = length;
}
void Painting::SetWidth(int width) {
    this->width_ = width;
}
std::string Painting::GetExhibitType() const {
    return "Painting";
}