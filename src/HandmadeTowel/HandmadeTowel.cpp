#include "HandmadeTowel.h"

std::string HandmadeTowel::GetFabricType() const {
    return fabricType_;
}
std::string HandmadeTowel::GetEmbroideryStyle() const {
    return embroideryStyle_;
}
std::string HandmadeTowel::GetColorScheme() const {
    return colorScheme_;
}
int HandmadeTowel::GetLength() const {
    return length_;
}
int HandmadeTowel::GetWidth() const {
    return width_;
}
bool HandmadeTowel::GetIsDecorative() const {
    return isDecorative_;
}

void HandmadeTowel::SetFabricType(std::string fabric) {
    this->fabricType_ = fabric;
}
void HandmadeTowel::SetEmbroideryStyle(std::string style) {
    this->embroideryStyle_ = style;
}
void HandmadeTowel::SetColorScheme(std::string colors) {
    this->colorScheme_ = colors;
}
void HandmadeTowel::SetLength(int length) {
    this->length_ = length;
}
void HandmadeTowel::SetWidth(int width) {
    this->width_ = width;
}
void HandmadeTowel::SetIsDecorative(bool isDecorative) {
    this->isDecorative_ = isDecorative;
}

std::string HandmadeTowel::GetExhibitType() const {
    return "Handmade Towel";
}