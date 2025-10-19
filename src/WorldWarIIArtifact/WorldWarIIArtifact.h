#ifndef LABWORK2_WORLDWARIIARTIFACT_H
#define LABWORK2_WORLDWARIIARTIFACT_H
#include "../Exhibit/Exhibit.h"
#include <string>

class WorldWarIIArtifact : public Exhibit {
public:
    WorldWarIIArtifact() = default;

    std::string GetArtifactType() const;
    std::string GetCondition() const;
    bool GetHasCombatHistory() const;
    std::string GetOriginCountry() const;

    void SetArtifactType(std::string artifactType);
    void SetCondition(std::string condition);
    void SetHasCombatHistory(bool hasCombatHistory);
    void SetOriginCountry(std::string originuntry);

    std::string GetExhibitType() const override;
private:
    std::string artifactType_;
    std::string condition_;
    bool hasCombatHistory_ = false;
    std::string originCountry_;
};

#endif //LABWORK2_WORLDWARIIARTIFACT_H