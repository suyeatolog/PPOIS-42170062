#include "CeramicVase.h"

std::string CeramicVase::GetPattern() const {
    return pattern_;
}
bool CeramicVase::GetFragile() const {
    return isFragile_;
}
int CeramicVase::GetLength() const {
    return length_;
}
int CeramicVase::GetWidth() const {
    return width_;
}
int CeramicVase::GetHeight() const {
    return height_;
}

void CeramicVase::SetPattern(std::string pattern) {
    this->pattern_ = pattern;
}
void CeramicVase::SetFragile(bool fragile) {
    this->isFragile_ = fragile;
}
void CeramicVase::SetLength(int length) {
    this->length_ = length;
}
void CeramicVase::SetWidth(int width) {
    this->width_ = width;
}
void CeramicVase::SetHeight(int height) {
    this->height_ = height;
}
std::string CeramicVase::GetExhibitType() const {
    return "Ceramic Vase";
}
