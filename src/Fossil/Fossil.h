//
// Created by user on 17.10.2025.
//

#ifndef LABWORK2_FOSSIL_H
#define LABWORK2_FOSSIL_H
#include "../Exhibit/Exhibit.h"
#include <string>

class Fossil : public Exhibit {
    public:
    Fossil() = default;

    std::string GetSpecies() const;
    std::string GetFoundationPlace() const;
    int GetBoneAmount() const;
    double GetWeight() const;
    int GetLength() const;
    int GetWidth() const;
    int GetHeight() const;

    void SetSpecies(std::string species);
    void SetFoundationPlace(std::string place);
    void SetBoneAmount(int bone);
    void SetWeight(double weight);
    void SetLength(int length);
    void SetWidth(int width);
    void SetHeight(int height);

    std::string GetExhibitType() const override;

private:
    std::string species_;
    std::string foundationPlace_;
    int boneAmount_ = 0;
    double weight_ = 0.0;
    int length_ = 0;
    int width_ = 0;
    int height_ = 0;
};

#endif //LABWORK2_FOSSIL_H