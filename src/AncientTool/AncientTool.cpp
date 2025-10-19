#include "AncientTool.h"

std::string AncientTool::GetPurpose() const {
    return purpose_;
}
std::string AncientTool::GetMaterial() const {
    return material_;
}

void AncientTool::SetPurpose(std::string purpose) {
    this->purpose_ = purpose;
}
void AncientTool::SetMaterial(std::string material) {
    this->material_ = material;
}
std::string AncientTool::GetExhibitType() const {
    return "AncientTool";
}