#include "ArtHall.h"
std::string ArtHall::GetArtPeriod() const {
    return artPeriod_;
}
void ArtHall::SetArtPeriod(std::string artPeriod) {
    this->artPeriod_ = artPeriod;
}
std::string ArtHall::GetHallType() const {
    return "ArtHall";
}