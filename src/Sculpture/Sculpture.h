//
// Created by user on 16.10.2025.
//

#ifndef LABWORK2_SCULPTURE_H
#define LABWORK2_SCULPTURE_H
#include "../Exhibit/Exhibit.h"
#include <string>

class Sculpture : public Exhibit {
    public:
    Sculpture() = default;

    std::string GetSculpturist() const;
    std::string GetMaterial() const;
    double GetWeight() const;
    bool IsFragile() const;

    int GetLength() const;
    int GetWidth() const;
    int GetHeight() const;

    void SetSculpturist(std::string sculpturist);
    void SetMaterial(std::string material);
    void SetWeight(double weight);
    void SetFragile(bool isFragile);
    void SetLength(int length);
    void SetWidth(int width);
    void SetHeight(int height);

    std::string GetExhibitType() const override;

private:
    std::string sculpturist_;
    std::string material_;
    double weight_ = 0.0;
    bool isFragile_ = false;
    int length_ = 0;
    int width_ = 0;
    int height_ = 0;
};

#endif //LABWORK2_SCULPTURE_H