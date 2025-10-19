#ifndef LABWORK2_ANCIENTTOOL_H
#define LABWORK2_ANCIENTTOOL_H
#include "../Exhibit/Exhibit.h"
#include <string>
class AncientTool : public Exhibit {
    public:
    AncientTool() = default;

    std::string GetPurpose() const;
    std::string GetMaterial() const;

    void SetPurpose(std::string purpose);
    void SetMaterial(std::string material);

    std::string GetExhibitType() const override;
private:
    std::string purpose_;
    std::string material_;
};

#endif //LABWORK2_ANCIENTTOOL_H