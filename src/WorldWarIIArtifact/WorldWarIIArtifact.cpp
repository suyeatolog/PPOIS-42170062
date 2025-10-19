#include "WorldWarIIArtifact.h"

std::string WorldWarIIArtifact::GetArtifactType() const {
    return artifactType_;
}
std::string WorldWarIIArtifact::GetCondition() const {
    return condition_;
}
bool WorldWarIIArtifact::GetHasCombatHistory() const {
    return hasCombatHistory_;
}
std::string WorldWarIIArtifact::GetOriginCountry() const {
    return originCountry_;
}

void WorldWarIIArtifact::SetArtifactType(std::string artifactType) {
    this->artifactType_ = artifactType;
}
void WorldWarIIArtifact::SetCondition(std::string condition) {
    this->condition_ = condition;
}
void WorldWarIIArtifact::SetHasCombatHistory(bool hasCombatHistory) {
    this->hasCombatHistory_ = hasCombatHistory;
}
void WorldWarIIArtifact::SetOriginCountry(std::string originCountry) {
    this->originCountry_ = originCountry;
}

std::string WorldWarIIArtifact::GetExhibitType() const {
    return "World War II Artifact";
}